// Copyright (C) 2025  Niels Martignène <niels.martignene@protonmail.com>

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the “Software”), to deal in
// the Software without restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#include "src/core/base/base.hh"

#define MINIZ_NO_ZLIB_COMPATIBLE_NAMES
#include "vendor/miniz/miniz.h"

namespace RG {

class MinizDecompressor: public StreamDecoder {
    tinfl_decompressor inflator;
    bool done = false;

    // This decompressor supports Zlib and Gzip
    bool is_gzip = false;
    bool process_gzip_header = false;

    uint8_t in_buf[256 * 1024];
    uint8_t *in_ptr = nullptr;
    Size in_len = 0;

    uint8_t out_buf[256 * 1024];
    uint8_t *out_ptr = nullptr;
    Size out_len = 0;

    // For gzip support
    uint32_t crc32 = MZ_CRC32_INIT;
    Size uncompressed_size = 0;

public:
    MinizDecompressor(StreamReader *reader, CompressionType type);
    ~MinizDecompressor() {}

    Size Read(Size max_len, void *out_buf) override;
};

MinizDecompressor::MinizDecompressor(StreamReader *reader, CompressionType type)
    : StreamDecoder(reader), is_gzip(type == CompressionType::Gzip), process_gzip_header(is_gzip)
{
    static_assert(RG_SIZE(out_buf) >= TINFL_LZ_DICT_SIZE);
    tinfl_init(&inflator);
}

Size MinizDecompressor::Read(Size max_len, void *user_buf)
{
    // Gzip header is not directly supported by miniz. Currently this
    // will fail if the header is longer than 8192 bytes, which is
    // probably quite rare.
    if (process_gzip_header) {
        const Size header_max = 8192;
        static_assert(header_max < RG_SIZE(in_buf) / 4);

        in_len = ReadRaw(header_max, in_buf);

        if (in_len < 0)
            return -1;

        Size header_len = 10;

        if (in_len < header_len || in_buf[0] != 0x1F || in_buf[1] != 0x8B) {
            LogError("File '%1' does not look like a Gzip stream", GetFileName());
            return -1;
        }
        if (in_buf[3] & ~0x1F) {
            LogError("Unsupported flags in Gzip header");
            return -1;
        }

        if (in_buf[3] & 0x4) { // FEXTRA
            if (in_len - header_len < 2)
                goto truncated_error;
            uint16_t extra_len = (uint16_t)((in_buf[11] << 8) | in_buf[10]);
            if (extra_len > in_len - header_len)
                goto truncated_error;
            header_len += extra_len;
        }
        if (in_buf[3] & 0x8) { // FNAME
            uint8_t *end_ptr = (uint8_t *)memchr(in_buf + header_len, '\0',
                                                 (size_t)(in_len - header_len));
            if (!end_ptr)
                goto truncated_error;
            header_len = end_ptr - in_buf + 1;
        }
        if (in_buf[3] & 0x10) { // FCOMMENT
            uint8_t *end_ptr = (uint8_t *)memchr(in_buf + header_len, '\0',
                                                 (size_t)(in_len - header_len));
            if (!end_ptr)
                goto truncated_error;
            header_len = end_ptr - in_buf + 1;
        }
        if (in_buf[3] & 0x2) { // FHCRC
            if (in_len - header_len < 2)
                goto truncated_error;

            uint16_t crc16 = (uint16_t)mz_crc32(MZ_CRC32_INIT, in_buf, (size_t)header_len);
            uint16_t expected = ((uint16_t)in_buf[header_len + 1] << 8) | in_buf[header_len];

            if (crc16 != expected) {
                LogError("Failed header CRC16 check in '%1'", GetFileName());
                return -1;
            }

            header_len += 2;
        }

        in_ptr = in_buf + header_len;
        in_len -= header_len;

        process_gzip_header = false;
    }

    // Inflate (with miniz)
    {
        Size read_len = 0;
        for (;;) {
            if (max_len < out_len) {
                MemCpy(user_buf, out_ptr, max_len);
                read_len += max_len;
                out_ptr += max_len;
                out_len -= max_len;

                return read_len;
            } else {
                MemCpy(user_buf, out_ptr, out_len);
                read_len += out_len;
                user_buf = (uint8_t *)user_buf + out_len;
                max_len -= out_len;
                out_ptr = out_buf;
                out_len = 0;

                if (done) {
                    SetEOF(true);
                    return read_len;
                }
            }

            while (out_len < RG_SIZE(out_buf)) {
                if (!in_len) {
                    in_ptr = in_buf;
                    in_len = ReadRaw(RG_SIZE(in_buf), in_buf);
                    if (in_len < 0)
                        return read_len ? read_len : in_len;
                }

                size_t in_arg = (size_t)in_len;
                size_t out_arg = (size_t)(RG_SIZE(out_buf) - out_len);
                uint32_t flags = (uint32_t)
                    ((is_gzip ? 0 : TINFL_FLAG_PARSE_ZLIB_HEADER) |
                     (IsSourceEOF() ? 0 : TINFL_FLAG_HAS_MORE_INPUT));

                tinfl_status status = tinfl_decompress(&inflator, in_ptr, &in_arg,
                                                       out_buf, out_buf + out_len,
                                                       &out_arg, flags);

                if (is_gzip) {
                    crc32 = (uint32_t)mz_crc32(crc32, out_buf + out_len, out_arg);
                    uncompressed_size += (Size)out_arg;
                }

                in_ptr += (Size)in_arg;
                in_len -= (Size)in_arg;
                out_len += (Size)out_arg;

                if (status == TINFL_STATUS_DONE) {
                    // Gzip footer (CRC and size check)
                    if (is_gzip) {
                        uint32_t footer[2];
                        static_assert(RG_SIZE(footer) == 8);

                        if (in_len < RG_SIZE(footer)) {
                            MemCpy(footer, in_ptr, in_len);

                            uint8_t *ptr = (uint8_t *)footer + in_len;
                            Size missing_len = RG_SIZE(footer) - in_len;

                            if (ReadRaw(missing_len, ptr) < missing_len) {
                                if (IsValid()) {
                                    goto truncated_error;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            MemCpy(footer, in_ptr, RG_SIZE(footer));
                        }
                        footer[0] = LittleEndian(footer[0]);
                        footer[1] = LittleEndian(footer[1]);

                        if (crc32 != footer[0] || (uint32_t)uncompressed_size != footer[1]) {
                            LogError("Failed CRC32 or size check in GZip stream '%1'", GetFileName());
                            return -1;
                        }
                    }

                    done = true;
                    break;
                } else if (status < TINFL_STATUS_DONE) {
                    LogError("Failed to decompress '%1' (Deflate)", GetFileName());
                    return -1;
                }
            }
        }
    }

truncated_error:
    LogError("Truncated Gzip header in '%1'", GetFileName());
    return -1;
}

class MinizCompressor: public StreamEncoder {
    tdefl_compressor deflator;

    // Gzip support
    bool is_gzip = false;
    uint32_t crc32 = MZ_CRC32_INIT;
    Size uncompressed_size = 0;

    // Used to buffer small writes
    LocalArray<uint8_t, 1024> small_buf;

public:
    MinizCompressor(StreamWriter *writer, CompressionType type, CompressionSpeed speed);
    ~MinizCompressor() {}

    bool Write(Span<const uint8_t> buf) override;
    bool Finalize() override;

private:
    bool WriteDeflate(Span<const uint8_t> buf);
};

MinizCompressor::MinizCompressor(StreamWriter *writer, CompressionType type, CompressionSpeed speed)
    : StreamEncoder(writer)
{
    is_gzip = (type == CompressionType::Gzip);

    int flags = 0;
    switch (speed) {
        case CompressionSpeed::Default: { flags = 32 | TDEFL_GREEDY_PARSING_FLAG; } break;
        case CompressionSpeed::Slow: { flags = 512; } break;
        case CompressionSpeed::Fast: { flags = 1 | TDEFL_GREEDY_PARSING_FLAG; } break;
    }
    flags |= (is_gzip ? 0 : TDEFL_WRITE_ZLIB_HEADER);

    tdefl_status status = tdefl_init(&deflator, [](const void *buf, int len, void *udata) {
        MinizCompressor *compressor = (MinizCompressor *)udata;
        return (int)compressor->WriteRaw(MakeSpan((uint8_t *)buf, len));
    }, this, flags);
    RG_ASSERT(status == TDEFL_STATUS_OKAY);

    if (is_gzip) {
        static uint8_t gzip_header[] = {
            0x1F, 0x8B, // Fixed bytes
            8,          // Deflate
            0x2,        // FLG (FHCRC)
            0, 0, 0, 0, // MTIME
            0,          // XFL
            255,        // OS
            0x90, 0xC9  // CRC16 for header
        };

        WriteRaw(gzip_header);
    }
}

bool MinizCompressor::Write(Span<const uint8_t> buf)
{
    if (small_buf.len) {
        Size copy_len = std::min(buf.len, small_buf.Available());

        MemCpy(small_buf.end(), buf.ptr, copy_len);
        small_buf.len += copy_len;
        buf.ptr += copy_len;
        buf.len -= copy_len;
    }

    if (buf.len) {
        if (small_buf.len && !WriteDeflate(small_buf))
            return false;
        small_buf.Clear();

        if (buf.len >= RG_SIZE(small_buf.data) / 2) {
            if (!WriteDeflate(buf))
                return false;
        } else {
            MemCpy(small_buf.data, buf.ptr, buf.len);
            small_buf.len = buf.len;
        }
    }

    return true;
}

bool MinizCompressor::WriteDeflate(Span<const uint8_t> buf)
{
    if (is_gzip) {
        crc32 = (uint32_t)mz_crc32(crc32, buf.ptr, (size_t)buf.len);
        uncompressed_size += buf.len;
    }

    tdefl_status status = tdefl_compress_buffer(&deflator, buf.ptr, (size_t)buf.len, TDEFL_NO_FLUSH);
    if (status < TDEFL_STATUS_OKAY) {
        if (status != TDEFL_STATUS_PUT_BUF_FAILED) {
            LogError("Failed to deflate stream to '%1'", GetFileName());
        }

        return false;
    }

    return true;
}

bool MinizCompressor::Finalize()
{
    if (small_buf.len && !WriteDeflate(small_buf))
        return false;

    uint8_t dummy; // Avoid UB in miniz
    tdefl_status status = tdefl_compress_buffer(&deflator, &dummy, 0, TDEFL_FINISH);
    if (status != TDEFL_STATUS_DONE) {
        if (status != TDEFL_STATUS_PUT_BUF_FAILED) {
            LogError("Failed to end Deflate stream for '%1", GetFileName());
        }

        return false;
    }

    if (is_gzip) {
        uint32_t gzip_footer[] = {
            LittleEndian(crc32),
            LittleEndian((uint32_t)uncompressed_size)
        };

        if (!WriteRaw(MakeSpan((uint8_t *)gzip_footer, RG_SIZE(gzip_footer))))
            return false;
    }

    return true;
}

RG_REGISTER_DECOMPRESSOR(CompressionType::Zlib, MinizDecompressor);
RG_REGISTER_DECOMPRESSOR(CompressionType::Gzip, MinizDecompressor);
RG_REGISTER_COMPRESSOR(CompressionType::Zlib, MinizCompressor);
RG_REGISTER_COMPRESSOR(CompressionType::Gzip, MinizCompressor);

}
