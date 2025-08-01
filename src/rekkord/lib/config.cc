// Copyright (C) 2025  Niels Martignène <niels.martignene@protonmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "src/core/base/base.hh"
#include "config.hh"
#include "vendor/lz4/lib/lz4hc.h"

namespace RG {

bool rk_Config::Complete(bool require_auth)
{
    if (!url) {
        url = GetEnv("REKKORD_REPOSITORY");
        if (!url) {
            LogError("Missing repository location");
            return false;
        }
    }

    if (!rk_DecodeURL(url, this))
        return false;

    if (require_auth) {
        if (!key_filename) {
            key_filename = GetEnv("REKKORD_KEYFILE");
        }

        if (!key_filename) {
            if (!username) {
                username = GetEnv("REKKORD_USER");
                if (!username && FileIsVt100(STDERR_FILENO)) {
                    username = Prompt("Repository user: ", &str_alloc);
                }
                if (!username)
                    return false;
            }

            if (!password) {
                password = GetEnv("REKKORD_PASSWORD");
                if (!password && FileIsVt100(STDERR_FILENO)) {
                    password = Prompt("Repository password: ", nullptr, "*", &str_alloc);
                }
                if (!password)
                    return false;
            }
        }
    }

    switch (type) {
        case rk_DiskType::Local: return true;
        case rk_DiskType::S3: return s3.remote.Complete();
        case rk_DiskType::SFTP: return ssh.Complete();
    }

    RG_UNREACHABLE();
}

bool rk_Config::Validate(bool require_auth) const
{
    bool valid = true;

    if (!url) {
        LogError("Missing repository location");
        valid = false;
    }

    if (require_auth && !key_filename) {
        if (!username) {
            LogError("Missing repository username");
            valid = false;
        }
        if (!password) {
            LogError("Missing repository password");
            valid = false;
        }
    }

    if (retain) {
        if (safety) {
            if (retain < rk_MinimalRetention) {
                LogError("Retain duration is too low, disable DurationSafety to override");
                valid = false;
            } else if (retain > rk_MaximalRetention) {
                LogError("Retain duration is too high, disable DurationSafety to override");
                valid = false;
            }
        }

        if (type != rk_DiskType::S3) {
            LogError("Retain locks are only supported with S3 providers");
            valid = false;
        }
    }

    switch (type) {
        case rk_DiskType::Local: {} break;
        case rk_DiskType::S3: { valid &= s3.remote.Validate(); } break;
        case rk_DiskType::SFTP: {
            valid &= ssh.Validate();

            if (!ssh.path) {
                LogError("Missing SFTP remote path");
                valid = false;
            }
        } break;
    }

    return valid;
}

static bool LooksLikeS3(Span<const char> str)
{
    if (StartsWith(str, "s3:")) {
        str = str.Take(3, str.len - 3);
    }

    bool ret = StartsWith(str, "http://") || StartsWith(str, "https://");
    return ret;
}

static bool LooksLikeUserName(Span<const char> str)
{
    const auto test_char = [](char c) { return IsAsciiAlphaOrDigit(c) || c == '_' || c == '.' || c == '-'; };

    if (!str.len)
        return false;
    if (!std::all_of(str.begin(), str.end(), test_char))
        return false;

    return true;
}

static bool LooksLikeHost(Span<const char> str)
{
    if (!str.len)
        return false;
    if (memchr(str.ptr, '/', (size_t)str.len))
        return false;

    return true;
}

static bool LooksLikeSSH(Span<const char> str)
{
    if (StartsWith(str, "ssh://") || StartsWith(str, "sftp://"))
        return true;

    // Test for user@host pattern
    {
        Span<const char> remain = str;

        Span<const char> username = SplitStr(remain, '@', &remain);
        Span<const char> host = SplitStr(remain, ':', &remain);
        Span<const char> path = remain;

        if (host.ptr > username.end() && path.ptr > host.end() &&
                LooksLikeUserName(username) && LooksLikeHost(host))
            return true;
    }

    return false;
}

bool rk_DecodeURL(Span<const char> url, rk_Config *out_config)
{
    if (url == "S3") {
        out_config->url = "S3";
        out_config->type = rk_DiskType::S3;

        return true;
    } else if (LooksLikeS3(url)) {
        out_config->url = DuplicateString(url, &out_config->str_alloc).ptr;
        out_config->type = rk_DiskType::S3;

        return s3_DecodeURL(url, &out_config->s3.remote);
    } else if (url == "SFTP") {
        out_config->url = "SFTP";
        out_config->type = rk_DiskType::SFTP;

        return true;
    } else if (LooksLikeSSH(url)) {
        out_config->url = DuplicateString(url, &out_config->str_alloc).ptr;
        out_config->type = rk_DiskType::SFTP;

        return ssh_DecodeURL(url, &out_config->ssh);
    } else {
        out_config->url = DuplicateString(url, &out_config->str_alloc).ptr;
        out_config->type = rk_DiskType::Local;

        return true;
    }
}

bool rk_LoadConfig(StreamReader *st, rk_Config *out_config)
{
    rk_Config config;

    Span<const char> root_directory = GetPathDirectory(st->GetFileName());
    root_directory = NormalizePath(root_directory, GetWorkingDirectory(), &config.str_alloc);

    IniParser ini(st);
    ini.PushLogFilter();
    RG_DEFER { PopLogFilter(); };

    bool valid = true;
    {
        IniProperty prop;
        while (ini.Next(&prop)) {
            if (prop.section == "Repository") {
                do {
                    if (prop.key == "URL") {
                        valid &= rk_DecodeURL(prop.value, &config);
                    } else if (prop.key == "KeyFile") {
                        config.key_filename = NormalizePath(prop.value, root_directory, &config.str_alloc).ptr;
                    } else if (prop.key == "User") {
                        config.username = DuplicateString(prop.value, &config.str_alloc).ptr;
                    } else if (prop.key == "Password") {
                        config.password = DuplicateString(prop.value, &config.str_alloc).ptr;
                        ZeroSafe((void *)prop.value.ptr, prop.value.len);
                    } else {
                        LogError("Unknown attribute '%1'", prop.key);
                        valid = false;
                    }
                } while (ini.NextInSection(&prop));
            } else if (prop.section == "Settings") {
                do {
                    if (prop.key == "Threads") {
                        if (ParseInt(prop.value, &config.threads)) {
                            if (config.threads < 1) {
                                LogError("Threads count cannot be < 1");
                                valid = false;
                            }
                        } else {
                            valid = false;
                        }
                    } else if (prop.key == "CompressionLevel") {
                        valid &= ParseInt(prop.value, &config.compression_level);
                    } else {
                        LogError("Unknown attribute '%1'", prop.key);
                        valid = false;
                    }
                } while (ini.NextInSection(&prop));
            } else if (prop.section == "Protection") {
                do {
                    if (prop.key == "RetainDuration") {
                        if (prop.value == "Disabled") {
                            config.retain = 0;
                        } else if (ParseDuration(prop.value, &config.retain)) {
                            if (config.retain < 0) {
                                LogError("Retain duration cannot be negative");
                                valid = false;
                            }
                        } else {
                            valid = false;
                        }
                    } else if (prop.key == "DurationSafety") {
                        valid &= ParseBool(prop.value, &config.safety);
                    } else {
                        LogError("Unknown attribute '%1'", prop.key);
                        valid = false;
                    }
                } while (ini.NextInSection(&prop));
            } else if (prop.section == "S3") {
                do {
                    if (prop.key == "ConditionalWrites") {
                        valid &= ParseBool(prop.value, &config.s3.conditional);
                    } else if (prop.key == "LockMode") {
                        if (!OptionToEnumI(s3_LockModeNames, prop.value, &config.s3.lock)) {
                            LogError("Invalid lock mode '%1'", prop.value);
                            valid = false;
                        }
                    } else {
                        valid &= config.s3.remote.SetProperty(prop.key, prop.value, root_directory);
                    }
                } while (ini.NextInSection(&prop));
            } else if (prop.section == "SSH" || prop.section == "SFTP") {
                do {
                    valid &= config.ssh.SetProperty(prop.key, prop.value, root_directory);
                } while (ini.NextInSection(&prop));
            } else {
                LogError("Unknown section '%1'", prop.section);
                while (ini.NextInSection(&prop));
                valid = false;
            }
        }
    }
    if (!ini.IsValid() || !valid)
        return false;

    std::swap(*out_config, config);
    return true;
}

bool rk_LoadConfig(const char *filename, rk_Config *out_config)
{
    StreamReader st(filename);
    return rk_LoadConfig(&st, out_config);
}

}
