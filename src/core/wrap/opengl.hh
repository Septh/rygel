// Copyright (C) 2025  Niels Martignène <niels.martignene@protonmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the “Software”), to deal in
// the Software without restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#pragma once

#include <stdint.h>

#if defined(__EMSCRIPTEN__)
    #include <GLES3/gl3.h>

    #define GL_API GL_APICALL
    #define OGL_FUNCTION_PTR(Ret, Name, ...) \
        Ret (GL_API *Name)(__VA_ARGS__)

    #if !defined(OGL_NO_COMPAT)
        #define OGL_NO_COMPAT
    #endif
#else
    #if defined(_WIN32)
        #define GL_API __stdcall
    #else
        #define GL_API
    #endif
    #define OGL_FUNCTION_PTR(Ret, Name, ...) \
        Ret (GL_API *Name)(__VA_ARGS__)

    // ------------------------------------------------------------------------
    // OpenGL types
    // ------------------------------------------------------------------------

    typedef unsigned int GLenum;
    typedef unsigned char GLboolean;
    typedef unsigned int GLbitfield;
    typedef void GLvoid;
    typedef signed char GLbyte;
    typedef short GLshort;
    typedef int GLint;
    typedef unsigned char GLubyte;
    typedef unsigned short GLushort;
    typedef unsigned int GLuint;
    typedef int GLsizei;
    typedef float GLfloat;
    typedef float GLclampf;
    typedef double GLdouble;
    typedef double GLclampd;
    typedef char GLchar;
    typedef unsigned short GLhalf;
    typedef ptrdiff_t GLintptr;
    typedef ptrdiff_t GLsizeiptr;
    typedef int64_t GLint64;
    typedef uint64_t GLuint64;
    typedef struct __GLsync *GLsync;
    typedef void (GL_API *GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity,
                                       GLsizei length, const GLchar *message, const void *userParam);

    // ------------------------------------------------------------------------
    // OpenGL defines
    // ------------------------------------------------------------------------

    // OpenGL 1.0

    #define GL_DEPTH_BUFFER_BIT 0x00000100
    #define GL_STENCIL_BUFFER_BIT 0x00000400
    #define GL_COLOR_BUFFER_BIT 0x00004000
    #define GL_FALSE 0
    #define GL_TRUE 1
    #define GL_POINTS 0x0000
    #define GL_LINES 0x0001
    #define GL_LINE_LOOP 0x0002
    #define GL_LINE_STRIP 0x0003
    #define GL_TRIANGLES 0x0004
    #define GL_TRIANGLE_STRIP 0x0005
    #define GL_TRIANGLE_FAN 0x0006
    #if !defined(OGL_NO_COMPAT)
        #define GL_QUADS 0x0007
    #endif
    #define GL_NEVER 0x0200
    #define GL_LESS 0x0201
    #define GL_EQUAL 0x0202
    #define GL_LEQUAL 0x0203
    #define GL_GREATER 0x0204
    #define GL_NOTEQUAL 0x0205
    #define GL_GEQUAL 0x0206
    #define GL_ALWAYS 0x0207
    #define GL_ZERO 0
    #define GL_ONE 1
    #define GL_SRC_COLOR 0x0300
    #define GL_ONE_MINUS_SRC_COLOR 0x0301
    #define GL_SRC_ALPHA 0x0302
    #define GL_ONE_MINUS_SRC_ALPHA 0x0303
    #define GL_DST_ALPHA 0x0304
    #define GL_ONE_MINUS_DST_ALPHA 0x0305
    #define GL_DST_COLOR 0x0306
    #define GL_ONE_MINUS_DST_COLOR 0x0307
    #define GL_SRC_ALPHA_SATURATE 0x0308
    #define GL_NONE 0
    #define GL_FRONT_LEFT 0x0400
    #define GL_FRONT_RIGHT 0x0401
    #define GL_BACK_LEFT 0x0402
    #define GL_BACK_RIGHT 0x0403
    #define GL_FRONT 0x0404
    #define GL_BACK 0x0405
    #define GL_LEFT 0x0406
    #define GL_RIGHT 0x0407
    #define GL_FRONT_AND_BACK 0x0408
    #define GL_NO_ERROR 0
    #define GL_INVALID_ENUM 0x0500
    #define GL_INVALID_VALUE 0x0501
    #define GL_INVALID_OPERATION 0x0502
    #define GL_OUT_OF_MEMORY 0x0505
    #define GL_CW 0x0900
    #define GL_CCW 0x0901
    #define GL_POINT_SIZE 0x0B11
    #define GL_POINT_SIZE_RANGE 0x0B12
    #define GL_POINT_SIZE_GRANULARITY 0x0B13
    #define GL_LINE_SMOOTH 0x0B20
    #define GL_LINE_WIDTH 0x0B21
    #define GL_LINE_WIDTH_RANGE 0x0B22
    #define GL_LINE_WIDTH_GRANULARITY 0x0B23
    #define GL_POLYGON_MODE 0x0B40
    #define GL_POLYGON_SMOOTH 0x0B41
    #define GL_CULL_FACE 0x0B44
    #define GL_CULL_FACE_MODE 0x0B45
    #define GL_FRONT_FACE 0x0B46
    #define GL_DEPTH_RANGE 0x0B70
    #define GL_DEPTH_TEST 0x0B71
    #define GL_DEPTH_WRITEMASK 0x0B72
    #define GL_DEPTH_CLEAR_VALUE 0x0B73
    #define GL_DEPTH_FUNC 0x0B74
    #define GL_STENCIL_TEST 0x0B90
    #define GL_STENCIL_CLEAR_VALUE 0x0B91
    #define GL_STENCIL_FUNC 0x0B92
    #define GL_STENCIL_VALUE_MASK 0x0B93
    #define GL_STENCIL_FAIL 0x0B94
    #define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
    #define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
    #define GL_STENCIL_REF 0x0B97
    #define GL_STENCIL_WRITEMASK 0x0B98
    #define GL_VIEWPORT 0x0BA2
    #define GL_DITHER 0x0BD0
    #define GL_BLEND_DST 0x0BE0
    #define GL_BLEND_SRC 0x0BE1
    #define GL_BLEND 0x0BE2
    #define GL_LOGIC_OP_MODE 0x0BF0
    #define GL_DRAW_BUFFER 0x0C01
    #define GL_READ_BUFFER 0x0C02
    #define GL_SCISSOR_BOX 0x0C10
    #define GL_SCISSOR_TEST 0x0C11
    #define GL_COLOR_CLEAR_VALUE 0x0C22
    #define GL_COLOR_WRITEMASK 0x0C23
    #define GL_DOUBLEBUFFER 0x0C32
    #define GL_STEREO 0x0C33
    #define GL_LINE_SMOOTH_HINT 0x0C52
    #define GL_POLYGON_SMOOTH_HINT 0x0C53
    #define GL_UNPACK_SWAP_BYTES 0x0CF0
    #if !defined(OGL_NO_COMPAT) // Deprecated in 4.3
        #define GL_UNPACK_LSB_FIRST 0x0CF1
    #endif
    #define GL_UNPACK_ROW_LENGTH 0x0CF2
    #define GL_UNPACK_SKIP_ROWS 0x0CF3
    #define GL_UNPACK_SKIP_PIXELS 0x0CF4
    #define GL_UNPACK_ALIGNMENT 0x0CF5
    #define GL_PACK_SWAP_BYTES 0x0D00
    #if !defined(OGL_NO_COMPAT) // Deprecated in 4.3
        #define GL_PACK_LSB_FIRST 0x0D01
    #endif
    #define GL_PACK_ROW_LENGTH 0x0D02
    #define GL_PACK_SKIP_ROWS 0x0D03
    #define GL_PACK_SKIP_PIXELS 0x0D04
    #define GL_PACK_ALIGNMENT 0x0D05
    #define GL_MAX_TEXTURE_SIZE 0x0D33
    #define GL_MAX_VIEWPORT_DIMS 0x0D3A
    #define GL_SUBPIXEL_BITS 0x0D50
    #define GL_TEXTURE_1D 0x0DE0
    #define GL_TEXTURE_2D 0x0DE1
    #define GL_TEXTURE_WIDTH 0x1000
    #define GL_TEXTURE_HEIGHT 0x1001
    #define GL_TEXTURE_BORDER_COLOR 0x1004
    #define GL_DONT_CARE 0x1100
    #define GL_FASTEST 0x1101
    #define GL_NICEST 0x1102
    #define GL_BYTE 0x1400
    #define GL_UNSIGNED_BYTE 0x1401
    #define GL_SHORT 0x1402
    #define GL_UNSIGNED_SHORT 0x1403
    #define GL_INT 0x1404
    #define GL_UNSIGNED_INT 0x1405
    #define GL_FLOAT 0x1406
    #if !defined(OGL_NO_COMPAT) // Deprecated in 4.3
        #define GL_STACK_OVERFLOW 0x0503
        #define GL_STACK_UNDERFLOW 0x0504
    #endif
    #define GL_CLEAR 0x1500
    #define GL_AND 0x1501
    #define GL_AND_REVERSE 0x1502
    #define GL_COPY 0x1503
    #define GL_AND_INVERTED 0x1504
    #define GL_NOOP 0x1505
    #define GL_XOR 0x1506
    #define GL_OR 0x1507
    #define GL_NOR 0x1508
    #define GL_EQUIV 0x1509
    #define GL_INVERT 0x150A
    #define GL_OR_REVERSE 0x150B
    #define GL_COPY_INVERTED 0x150C
    #define GL_OR_INVERTED 0x150D
    #define GL_NAND 0x150E
    #define GL_SET 0x150F
    #define GL_TEXTURE 0x1702
    #define GL_COLOR 0x1800
    #define GL_DEPTH 0x1801
    #define GL_STENCIL 0x1802
    #define GL_STENCIL_INDEX 0x1901
    #define GL_DEPTH_COMPONENT 0x1902
    #define GL_RED 0x1903
    #define GL_GREEN 0x1904
    #define GL_BLUE 0x1905
    #define GL_ALPHA 0x1906
    #define GL_RGB 0x1907
    #define GL_RGBA 0x1908
    #define GL_POINT 0x1B00
    #define GL_LINE 0x1B01
    #define GL_FILL 0x1B02
    #define GL_KEEP 0x1E00
    #define GL_REPLACE 0x1E01
    #define GL_INCR 0x1E02
    #define GL_DECR 0x1E03
    #define GL_VENDOR 0x1F00
    #define GL_RENDERER 0x1F01
    #define GL_VERSION 0x1F02
    #define GL_EXTENSIONS 0x1F03
    #define GL_NEAREST 0x2600
    #define GL_LINEAR 0x2601
    #define GL_NEAREST_MIPMAP_NEAREST 0x2700
    #define GL_LINEAR_MIPMAP_NEAREST 0x2701
    #define GL_NEAREST_MIPMAP_LINEAR 0x2702
    #define GL_LINEAR_MIPMAP_LINEAR 0x2703
    #define GL_TEXTURE_MAG_FILTER 0x2800
    #define GL_TEXTURE_MIN_FILTER 0x2801
    #define GL_TEXTURE_WRAP_S 0x2802
    #define GL_TEXTURE_WRAP_T 0x2803
    #define GL_REPEAT 0x2901
    #if !defined(OGL_NO_COMPAT)
        #define GL_CURRENT_BIT 0x00000001
        #define GL_POINT_BIT 0x00000002
        #define GL_LINE_BIT 0x00000004
        #define GL_POLYGON_BIT 0x00000008
        #define GL_POLYGON_STIPPLE_BIT 0x00000010
        #define GL_PIXEL_MODE_BIT 0x00000020
        #define GL_LIGHTING_BIT 0x00000040
        #define GL_FOG_BIT 0x00000080
        #define GL_ACCUM_BUFFER_BIT 0x00000200
        #define GL_VIEWPORT_BIT 0x00000800
        #define GL_TRANSFORM_BIT 0x00001000
        #define GL_ENABLE_BIT 0x00002000
        #define GL_HINT_BIT 0x00008000
        #define GL_EVAL_BIT 0x00010000
        #define GL_LIST_BIT 0x00020000
        #define GL_TEXTURE_BIT 0x00040000
        #define GL_SCISSOR_BIT 0x00080000
        #define GL_ALL_ATTRIB_BITS 0xFFFFFFFF
        #define GL_QUAD_STRIP 0x0008
        #define GL_POLYGON 0x0009
        #define GL_ACCUM 0x0100
        #define GL_LOAD 0x0101
        #define GL_RETURN 0x0102
        #define GL_MULT 0x0103
        #define GL_ADD 0x0104
        #define GL_AUX0 0x0409
        #define GL_AUX1 0x040A
        #define GL_AUX2 0x040B
        #define GL_AUX3 0x040C
        #define GL_2D 0x0600
        #define GL_3D 0x0601
        #define GL_3D_COLOR 0x0602
        #define GL_3D_COLOR_TEXTURE 0x0603
        #define GL_4D_COLOR_TEXTURE 0x0604
        #define GL_PASS_THROUGH_TOKEN 0x0700
        #define GL_POINT_TOKEN 0x0701
        #define GL_LINE_TOKEN 0x0702
        #define GL_POLYGON_TOKEN 0x0703
        #define GL_BITMAP_TOKEN 0x0704
        #define GL_DRAW_PIXEL_TOKEN 0x0705
        #define GL_COPY_PIXEL_TOKEN 0x0706
        #define GL_LINE_RESET_TOKEN 0x0707
        #define GL_EXP 0x0800
        #define GL_EXP2 0x0801
        #define GL_COEFF 0x0A00
        #define GL_ORDER 0x0A01
        #define GL_DOMAIN 0x0A02
        #define GL_PIXEL_MAP_I_TO_I 0x0C70
        #define GL_PIXEL_MAP_S_TO_S 0x0C71
        #define GL_PIXEL_MAP_I_TO_R 0x0C72
        #define GL_PIXEL_MAP_I_TO_G 0x0C73
        #define GL_PIXEL_MAP_I_TO_B 0x0C74
        #define GL_PIXEL_MAP_I_TO_A 0x0C75
        #define GL_PIXEL_MAP_R_TO_R 0x0C76
        #define GL_PIXEL_MAP_G_TO_G 0x0C77
        #define GL_PIXEL_MAP_B_TO_B 0x0C78
        #define GL_PIXEL_MAP_A_TO_A 0x0C79
        #define GL_CURRENT_COLOR 0x0B00
        #define GL_CURRENT_INDEX 0x0B01
        #define GL_CURRENT_NORMAL 0x0B02
        #define GL_CURRENT_TEXTURE_COORDS 0x0B03
        #define GL_CURRENT_RASTER_COLOR 0x0B04
        #define GL_CURRENT_RASTER_INDEX 0x0B05
        #define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
        #define GL_CURRENT_RASTER_POSITION 0x0B07
        #define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
        #define GL_CURRENT_RASTER_DISTANCE 0x0B09
        #define GL_POINT_SMOOTH 0x0B10
        #define GL_LINE_STIPPLE 0x0B24
        #define GL_LINE_STIPPLE_PATTERN 0x0B25
        #define GL_LINE_STIPPLE_REPEAT 0x0B26
        #define GL_LIST_MODE 0x0B30
        #define GL_MAX_LIST_NESTING 0x0B31
        #define GL_LIST_BASE 0x0B32
        #define GL_LIST_INDEX 0x0B33
        #define GL_POLYGON_STIPPLE 0x0B42
        #define GL_EDGE_FLAG 0x0B43
        #define GL_LIGHTING 0x0B50
        #define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
        #define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
        #define GL_LIGHT_MODEL_AMBIENT 0x0B53
        #define GL_SHADE_MODEL 0x0B54
        #define GL_COLOR_MATERIAL_FACE 0x0B55
        #define GL_COLOR_MATERIAL_PARAMETER 0x0B56
        #define GL_COLOR_MATERIAL 0x0B57
        #define GL_FOG 0x0B60
        #define GL_FOG_INDEX 0x0B61
        #define GL_FOG_DENSITY 0x0B62
        #define GL_FOG_START 0x0B63
        #define GL_FOG_END 0x0B64
        #define GL_FOG_MODE 0x0B65
        #define GL_FOG_COLOR 0x0B66
        #define GL_ACCUM_CLEAR_VALUE 0x0B80
        #define GL_MATRIX_MODE 0x0BA0
        #define GL_NORMALIZE 0x0BA1
        #define GL_MODELVIEW_STACK_DEPTH 0x0BA3
        #define GL_PROJECTION_STACK_DEPTH 0x0BA4
        #define GL_TEXTURE_STACK_DEPTH 0x0BA5
        #define GL_MODELVIEW_MATRIX 0x0BA6
        #define GL_PROJECTION_MATRIX 0x0BA7
        #define GL_TEXTURE_MATRIX 0x0BA8
        #define GL_ATTRIB_STACK_DEPTH 0x0BB0
        #define GL_ALPHA_TEST 0x0BC0
        #define GL_ALPHA_TEST_FUNC 0x0BC1
        #define GL_ALPHA_TEST_REF 0x0BC2
        #define GL_LOGIC_OP 0x0BF1
        #define GL_AUX_BUFFERS 0x0C00
        #define GL_INDEX_CLEAR_VALUE 0x0C20
        #define GL_INDEX_WRITEMASK 0x0C21
        #define GL_INDEX_MODE 0x0C30
        #define GL_RGBA_MODE 0x0C31
        #define GL_RENDER_MODE 0x0C40
        #define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
        #define GL_POINT_SMOOTH_HINT 0x0C51
        #define GL_FOG_HINT 0x0C54
        #define GL_TEXTURE_GEN_S 0x0C60
        #define GL_TEXTURE_GEN_T 0x0C61
        #define GL_TEXTURE_GEN_R 0x0C62
        #define GL_TEXTURE_GEN_Q 0x0C63
        #define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
        #define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
        #define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
        #define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
        #define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
        #define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
        #define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
        #define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
        #define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
        #define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
        #define GL_MAP_COLOR 0x0D10
        #define GL_MAP_STENCIL 0x0D11
        #define GL_INDEX_SHIFT 0x0D12
        #define GL_INDEX_OFFSET 0x0D13
        #define GL_RED_SCALE 0x0D14
        #define GL_RED_BIAS 0x0D15
        #define GL_ZOOM_X 0x0D16
        #define GL_ZOOM_Y 0x0D17
        #define GL_GREEN_SCALE 0x0D18
        #define GL_GREEN_BIAS 0x0D19
        #define GL_BLUE_SCALE 0x0D1A
        #define GL_BLUE_BIAS 0x0D1B
        #define GL_ALPHA_SCALE 0x0D1C
        #define GL_ALPHA_BIAS 0x0D1D
        #define GL_DEPTH_SCALE 0x0D1E
        #define GL_DEPTH_BIAS 0x0D1F
        #define GL_MAX_EVAL_ORDER 0x0D30
        #define GL_MAX_LIGHTS 0x0D31
        #define GL_MAX_CLIP_PLANES 0x0D32
        #define GL_MAX_PIXEL_MAP_TABLE 0x0D34
        #define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
        #define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
        #define GL_MAX_NAME_STACK_DEPTH 0x0D37
        #define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
        #define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
        #define GL_INDEX_BITS 0x0D51
        #define GL_RED_BITS 0x0D52
        #define GL_GREEN_BITS 0x0D53
        #define GL_BLUE_BITS 0x0D54
        #define GL_ALPHA_BITS 0x0D55
        #define GL_DEPTH_BITS 0x0D56
        #define GL_STENCIL_BITS 0x0D57
        #define GL_ACCUM_RED_BITS 0x0D58
        #define GL_ACCUM_GREEN_BITS 0x0D59
        #define GL_ACCUM_BLUE_BITS 0x0D5A
        #define GL_ACCUM_ALPHA_BITS 0x0D5B
        #define GL_NAME_STACK_DEPTH 0x0D70
        #define GL_AUTO_NORMAL 0x0D80
        #define GL_MAP1_COLOR_4 0x0D90
        #define GL_MAP1_INDEX 0x0D91
        #define GL_MAP1_NORMAL 0x0D92
        #define GL_MAP1_TEXTURE_COORD_1 0x0D93
        #define GL_MAP1_TEXTURE_COORD_2 0x0D94
        #define GL_MAP1_TEXTURE_COORD_3 0x0D95
        #define GL_MAP1_TEXTURE_COORD_4 0x0D96
        #define GL_MAP1_VERTEX_3 0x0D97
        #define GL_MAP1_VERTEX_4 0x0D98
        #define GL_MAP2_COLOR_4 0x0DB0
        #define GL_MAP2_INDEX 0x0DB1
        #define GL_MAP2_NORMAL 0x0DB2
        #define GL_MAP2_TEXTURE_COORD_1 0x0DB3
        #define GL_MAP2_TEXTURE_COORD_2 0x0DB4
        #define GL_MAP2_TEXTURE_COORD_3 0x0DB5
        #define GL_MAP2_TEXTURE_COORD_4 0x0DB6
        #define GL_MAP2_VERTEX_3 0x0DB7
        #define GL_MAP2_VERTEX_4 0x0DB8
        #define GL_MAP1_GRID_DOMAIN 0x0DD0
        #define GL_MAP1_GRID_SEGMENTS 0x0DD1
        #define GL_MAP2_GRID_DOMAIN 0x0DD2
        #define GL_MAP2_GRID_SEGMENTS 0x0DD3
        #define GL_TEXTURE_COMPONENTS 0x1003
        #define GL_TEXTURE_BORDER 0x1005
        #define GL_AMBIENT 0x1200
        #define GL_DIFFUSE 0x1201
        #define GL_SPECULAR 0x1202
        #define GL_POSITION 0x1203
        #define GL_SPOT_DIRECTION 0x1204
        #define GL_SPOT_EXPONENT 0x1205
        #define GL_SPOT_CUTOFF 0x1206
        #define GL_CONSTANT_ATTENUATION 0x1207
        #define GL_LINEAR_ATTENUATION 0x1208
        #define GL_QUADRATIC_ATTENUATION 0x1209
        #define GL_COMPILE 0x1300
        #define GL_COMPILE_AND_EXECUTE 0x1301
        #define GL_2_BYTES 0x1407
        #define GL_3_BYTES 0x1408
        #define GL_4_BYTES 0x1409
        #define GL_EMISSION 0x1600
        #define GL_SHININESS 0x1601
        #define GL_AMBIENT_AND_DIFFUSE 0x1602
        #define GL_COLOR_INDEXES 0x1603
        #define GL_MODELVIEW 0x1700
        #define GL_PROJECTION 0x1701
        #define GL_COLOR_INDEX 0x1900
        #define GL_LUMINANCE 0x1909
        #define GL_LUMINANCE_ALPHA 0x190A
        #define GL_BITMAP 0x1A00
        #define GL_RENDER 0x1C00
        #define GL_FEEDBACK 0x1C01
        #define GL_SELECT 0x1C02
        #define GL_FLAT 0x1D00
        #define GL_SMOOTH 0x1D01
        #define GL_S 0x2000
        #define GL_T 0x2001
        #define GL_R 0x2002
        #define GL_Q 0x2003
        #define GL_MODULATE 0x2100
        #define GL_DECAL 0x2101
        #define GL_TEXTURE_ENV_MODE 0x2200
        #define GL_TEXTURE_ENV_COLOR 0x2201
        #define GL_TEXTURE_ENV 0x2300
        #define GL_EYE_LINEAR 0x2400
        #define GL_OBJECT_LINEAR 0x2401
        #define GL_SPHERE_MAP 0x2402
        #define GL_TEXTURE_GEN_MODE 0x2500
        #define GL_OBJECT_PLANE 0x2501
        #define GL_EYE_PLANE 0x2502
        #define GL_CLAMP 0x2900
        #define GL_CLIP_PLANE0 0x3000
        #define GL_CLIP_PLANE1 0x3001
        #define GL_CLIP_PLANE2 0x3002
        #define GL_CLIP_PLANE3 0x3003
        #define GL_CLIP_PLANE4 0x3004
        #define GL_CLIP_PLANE5 0x3005
        #define GL_LIGHT0 0x4000
        #define GL_LIGHT1 0x4001
        #define GL_LIGHT2 0x4002
        #define GL_LIGHT3 0x4003
        #define GL_LIGHT4 0x4004
        #define GL_LIGHT5 0x4005
        #define GL_LIGHT6 0x4006
        #define GL_LIGHT7 0x4007
    #endif

    // OpenGL 1.1

    #define GL_COLOR_LOGIC_OP 0x0BF2
    #define GL_POLYGON_OFFSET_UNITS 0x2A00
    #define GL_POLYGON_OFFSET_POINT 0x2A01
    #define GL_POLYGON_OFFSET_LINE 0x2A02
    #define GL_POLYGON_OFFSET_FILL 0x8037
    #define GL_POLYGON_OFFSET_FACTOR 0x8038
    #define GL_TEXTURE_BINDING_1D 0x8068
    #define GL_TEXTURE_BINDING_2D 0x8069
    #define GL_TEXTURE_INTERNAL_FORMAT 0x1003
    #define GL_TEXTURE_RED_SIZE 0x805C
    #define GL_TEXTURE_GREEN_SIZE 0x805D
    #define GL_TEXTURE_BLUE_SIZE 0x805E
    #define GL_TEXTURE_ALPHA_SIZE 0x805F
    #define GL_DOUBLE 0x140A
    #define GL_PROXY_TEXTURE_1D 0x8063
    #define GL_PROXY_TEXTURE_2D 0x8064
    #define GL_R3_G3_B2 0x2A10
    #define GL_RGB4 0x804F
    #define GL_RGB5 0x8050
    #define GL_RGB8 0x8051
    #define GL_RGB10 0x8052
    #define GL_RGB12 0x8053
    #define GL_RGB16 0x8054
    #define GL_RGBA2 0x8055
    #define GL_RGBA4 0x8056
    #define GL_RGB5_A1 0x8057
    #define GL_RGBA8 0x8058
    #define GL_RGB10_A2 0x8059
    #define GL_RGBA12 0x805A
    #define GL_RGBA16 0x805B
    #if !defined(OGL_NO_COMPAT)
        #define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
        #define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
        #define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
        #define GL_VERTEX_ARRAY_POINTER 0x808E
        #define GL_NORMAL_ARRAY_POINTER 0x808F
        #define GL_COLOR_ARRAY_POINTER 0x8090
        #define GL_INDEX_ARRAY_POINTER 0x8091
        #define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
        #define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
        #define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
        #define GL_SELECTION_BUFFER_POINTER 0x0DF3
        #define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
        #define GL_INDEX_LOGIC_OP 0x0BF1
        #define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
        #define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
        #define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
        #define GL_SELECTION_BUFFER_SIZE 0x0DF4
        #define GL_VERTEX_ARRAY 0x8074
        #define GL_NORMAL_ARRAY 0x8075
        #define GL_COLOR_ARRAY 0x8076
        #define GL_INDEX_ARRAY 0x8077
        #define GL_TEXTURE_COORD_ARRAY 0x8078
        #define GL_EDGE_FLAG_ARRAY 0x8079
        #define GL_VERTEX_ARRAY_SIZE 0x807A
        #define GL_VERTEX_ARRAY_TYPE 0x807B
        #define GL_VERTEX_ARRAY_STRIDE 0x807C
        #define GL_NORMAL_ARRAY_TYPE 0x807E
        #define GL_NORMAL_ARRAY_STRIDE 0x807F
        #define GL_COLOR_ARRAY_SIZE 0x8081
        #define GL_COLOR_ARRAY_TYPE 0x8082
        #define GL_COLOR_ARRAY_STRIDE 0x8083
        #define GL_INDEX_ARRAY_TYPE 0x8085
        #define GL_INDEX_ARRAY_STRIDE 0x8086
        #define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
        #define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
        #define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
        #define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
        #define GL_TEXTURE_LUMINANCE_SIZE 0x8060
        #define GL_TEXTURE_INTENSITY_SIZE 0x8061
        #define GL_TEXTURE_PRIORITY 0x8066
        #define GL_TEXTURE_RESIDENT 0x8067
        #define GL_ALPHA4 0x803B
        #define GL_ALPHA8 0x803C
        #define GL_ALPHA12 0x803D
        #define GL_ALPHA16 0x803E
        #define GL_LUMINANCE4 0x803F
        #define GL_LUMINANCE8 0x8040
        #define GL_LUMINANCE12 0x8041
        #define GL_LUMINANCE16 0x8042
        #define GL_LUMINANCE4_ALPHA4 0x8043
        #define GL_LUMINANCE6_ALPHA2 0x8044
        #define GL_LUMINANCE8_ALPHA8 0x8045
        #define GL_LUMINANCE12_ALPHA4 0x8046
        #define GL_LUMINANCE12_ALPHA12 0x8047
        #define GL_LUMINANCE16_ALPHA16 0x8048
        #define GL_INTENSITY 0x8049
        #define GL_INTENSITY4 0x804A
        #define GL_INTENSITY8 0x804B
        #define GL_INTENSITY12 0x804C
        #define GL_INTENSITY16 0x804D
        #define GL_V2F 0x2A20
        #define GL_V3F 0x2A21
        #define GL_C4UB_V2F 0x2A22
        #define GL_C4UB_V3F 0x2A23
        #define GL_C3F_V3F 0x2A24
        #define GL_N3F_V3F 0x2A25
        #define GL_C4F_N3F_V3F 0x2A26
        #define GL_T2F_V3F 0x2A27
        #define GL_T4F_V4F 0x2A28
        #define GL_T2F_C4UB_V3F 0x2A29
        #define GL_T2F_C3F_V3F 0x2A2A
        #define GL_T2F_N3F_V3F 0x2A2B
        #define GL_T2F_C4F_N3F_V3F 0x2A2C
        #define GL_T4F_C4F_N3F_V4F 0x2A2D
    #endif

    // OpenGL 1.2

    #define GL_UNSIGNED_BYTE_3_3_2 0x8032
    #define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
    #define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
    #define GL_UNSIGNED_INT_8_8_8_8 0x8035
    #define GL_UNSIGNED_INT_10_10_10_2 0x8036
    #define GL_TEXTURE_BINDING_3D 0x806A
    #define GL_PACK_SKIP_IMAGES 0x806B
    #define GL_PACK_IMAGE_HEIGHT 0x806C
    #define GL_UNPACK_SKIP_IMAGES 0x806D
    #define GL_UNPACK_IMAGE_HEIGHT 0x806E
    #define GL_TEXTURE_3D 0x806F
    #define GL_PROXY_TEXTURE_3D 0x8070
    #define GL_TEXTURE_DEPTH 0x8071
    #define GL_TEXTURE_WRAP_R 0x8072
    #define GL_MAX_3D_TEXTURE_SIZE 0x8073
    #define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
    #define GL_UNSIGNED_SHORT_5_6_5 0x8363
    #define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
    #define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
    #define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
    #define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
    #define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
    #define GL_BGR 0x80E0
    #define GL_BGRA 0x80E1
    #define GL_MAX_ELEMENTS_VERTICES 0x80E8
    #define GL_MAX_ELEMENTS_INDICES 0x80E9
    #define GL_CLAMP_TO_EDGE 0x812F
    #define GL_TEXTURE_MIN_LOD 0x813A
    #define GL_TEXTURE_MAX_LOD 0x813B
    #define GL_TEXTURE_BASE_LEVEL 0x813C
    #define GL_TEXTURE_MAX_LEVEL 0x813D
    #define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
    #define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
    #define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
    #define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
    #define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
    #if !defined(OGL_NO_COMPAT)
        #define GL_RESCALE_NORMAL 0x803A
        #define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
        #define GL_SINGLE_COLOR 0x81F9
        #define GL_SEPARATE_SPECULAR_COLOR 0x81FA
        #define GL_ALIASED_POINT_SIZE_RANGE 0x846D
    #endif

    // OpenGL 1.3

    #define GL_TEXTURE0 0x84C0
    #define GL_TEXTURE1 0x84C1
    #define GL_TEXTURE2 0x84C2
    #define GL_TEXTURE3 0x84C3
    #define GL_TEXTURE4 0x84C4
    #define GL_TEXTURE5 0x84C5
    #define GL_TEXTURE6 0x84C6
    #define GL_TEXTURE7 0x84C7
    #define GL_TEXTURE8 0x84C8
    #define GL_TEXTURE9 0x84C9
    #define GL_TEXTURE10 0x84CA
    #define GL_TEXTURE11 0x84CB
    #define GL_TEXTURE12 0x84CC
    #define GL_TEXTURE13 0x84CD
    #define GL_TEXTURE14 0x84CE
    #define GL_TEXTURE15 0x84CF
    #define GL_TEXTURE16 0x84D0
    #define GL_TEXTURE17 0x84D1
    #define GL_TEXTURE18 0x84D2
    #define GL_TEXTURE19 0x84D3
    #define GL_TEXTURE20 0x84D4
    #define GL_TEXTURE21 0x84D5
    #define GL_TEXTURE22 0x84D6
    #define GL_TEXTURE23 0x84D7
    #define GL_TEXTURE24 0x84D8
    #define GL_TEXTURE25 0x84D9
    #define GL_TEXTURE26 0x84DA
    #define GL_TEXTURE27 0x84DB
    #define GL_TEXTURE28 0x84DC
    #define GL_TEXTURE29 0x84DD
    #define GL_TEXTURE30 0x84DE
    #define GL_TEXTURE31 0x84DF
    #define GL_ACTIVE_TEXTURE 0x84E0
    #define GL_MULTISAMPLE 0x809D
    #define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
    #define GL_SAMPLE_ALPHA_TO_ONE 0x809F
    #define GL_SAMPLE_COVERAGE 0x80A0
    #define GL_SAMPLE_BUFFERS 0x80A8
    #define GL_SAMPLES 0x80A9
    #define GL_SAMPLE_COVERAGE_VALUE 0x80AA
    #define GL_SAMPLE_COVERAGE_INVERT 0x80AB
    #define GL_TEXTURE_CUBE_MAP 0x8513
    #define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
    #define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
    #define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
    #define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
    #define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
    #define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
    #define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
    #define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
    #define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
    #define GL_COMPRESSED_RGB 0x84ED
    #define GL_COMPRESSED_RGBA 0x84EE
    #define GL_TEXTURE_COMPRESSION_HINT 0x84EF
    #define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
    #define GL_TEXTURE_COMPRESSED 0x86A1
    #if !defined(OGL_NO_COMPAT) // 4.2
        #define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
        #define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
    #endif
    #define GL_CLAMP_TO_BORDER 0x812D
    #if !defined(OGL_NO_COMPAT)
        #define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
        #define GL_MAX_TEXTURE_UNITS 0x84E2
        #define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
        #define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
        #define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
        #define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
        #define GL_MULTISAMPLE_BIT 0x20000000
        #define GL_NORMAL_MAP 0x8511
        #define GL_REFLECTION_MAP 0x8512
        #define GL_COMPRESSED_ALPHA 0x84E9
        #define GL_COMPRESSED_LUMINANCE 0x84EA
        #define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
        #define GL_COMPRESSED_INTENSITY 0x84EC
        #define GL_COMBINE 0x8570
        #define GL_COMBINE_RGB 0x8571
        #define GL_COMBINE_ALPHA 0x8572
        #define GL_SOURCE0_RGB 0x8580
        #define GL_SOURCE1_RGB 0x8581
        #define GL_SOURCE2_RGB 0x8582
        #define GL_SOURCE0_ALPHA 0x8588
        #define GL_SOURCE1_ALPHA 0x8589
        #define GL_SOURCE2_ALPHA 0x858A
        #define GL_OPERAND0_RGB 0x8590
        #define GL_OPERAND1_RGB 0x8591
        #define GL_OPERAND2_RGB 0x8592
        #define GL_OPERAND0_ALPHA 0x8598
        #define GL_OPERAND1_ALPHA 0x8599
        #define GL_OPERAND2_ALPHA 0x859A
        #define GL_RGB_SCALE 0x8573
        #define GL_ADD_SIGNED 0x8574
        #define GL_INTERPOLATE 0x8575
        #define GL_SUBTRACT 0x84E7
        #define GL_CONSTANT 0x8576
        #define GL_PRIMARY_COLOR 0x8577
        #define GL_PREVIOUS 0x8578
        #define GL_DOT3_RGB 0x86AE
        #define GL_DOT3_RGBA 0x86AF
    #endif

    // OpenGL 1.4

    #define GL_BLEND_DST_RGB 0x80C8
    #define GL_BLEND_SRC_RGB 0x80C9
    #define GL_BLEND_DST_ALPHA 0x80CA
    #define GL_BLEND_SRC_ALPHA 0x80CB
    #define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
    #define GL_DEPTH_COMPONENT16 0x81A5
    #define GL_DEPTH_COMPONENT24 0x81A6
    #define GL_DEPTH_COMPONENT32 0x81A7
    #define GL_MIRRORED_REPEAT 0x8370
    #define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
    #define GL_TEXTURE_LOD_BIAS 0x8501
    #define GL_INCR_WRAP 0x8507
    #define GL_DECR_WRAP 0x8508
    #define GL_TEXTURE_DEPTH_SIZE 0x884A
    #define GL_TEXTURE_COMPARE_MODE 0x884C
    #define GL_TEXTURE_COMPARE_FUNC 0x884D
    #if !defined(OGL_NO_COMPAT)
        #define GL_POINT_SIZE_MIN 0x8126
        #define GL_POINT_SIZE_MAX 0x8127
        #define GL_POINT_DISTANCE_ATTENUATION 0x8129
        #define GL_GENERATE_MIPMAP 0x8191
        #define GL_GENERATE_MIPMAP_HINT 0x8192
        #define GL_FOG_COORDINATE_SOURCE 0x8450
        #define GL_FOG_COORDINATE 0x8451
        #define GL_FRAGMENT_DEPTH 0x8452
        #define GL_CURRENT_FOG_COORDINATE 0x8453
        #define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
        #define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
        #define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
        #define GL_FOG_COORDINATE_ARRAY 0x8457
        #define GL_COLOR_SUM 0x8458
        #define GL_CURRENT_SECONDARY_COLOR 0x8459
        #define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
        #define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
        #define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
        #define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
        #define GL_SECONDARY_COLOR_ARRAY 0x845E
        #define GL_TEXTURE_FILTER_CONTROL 0x8500
        #define GL_DEPTH_TEXTURE_MODE 0x884B
        #define GL_COMPARE_R_TO_TEXTURE 0x884E
    #endif
    #define GL_FUNC_ADD 0x8006
    #define GL_FUNC_SUBTRACT 0x800A
    #define GL_FUNC_REVERSE_SUBTRACT 0x800B
    #define GL_MIN 0x8007
    #define GL_MAX 0x8008
    #define GL_CONSTANT_COLOR 0x8001
    #define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
    #define GL_CONSTANT_ALPHA 0x8003
    #define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004

    // OpenGL 1.5

    #define GL_BUFFER_SIZE 0x8764
    #define GL_BUFFER_USAGE 0x8765
    #define GL_QUERY_COUNTER_BITS 0x8864
    #define GL_CURRENT_QUERY 0x8865
    #define GL_QUERY_RESULT 0x8866
    #define GL_QUERY_RESULT_AVAILABLE 0x8867
    #define GL_ARRAY_BUFFER 0x8892
    #define GL_ELEMENT_ARRAY_BUFFER 0x8893
    #define GL_ARRAY_BUFFER_BINDING 0x8894
    #define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
    #define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
    #define GL_READ_ONLY 0x88B8
    #define GL_WRITE_ONLY 0x88B9
    #define GL_READ_WRITE 0x88BA
    #define GL_BUFFER_ACCESS 0x88BB
    #define GL_BUFFER_MAPPED 0x88BC
    #define GL_BUFFER_MAP_POINTER 0x88BD
    #define GL_STREAM_DRAW 0x88E0
    #define GL_STREAM_READ 0x88E1
    #define GL_STREAM_COPY 0x88E2
    #define GL_STATIC_DRAW 0x88E4
    #define GL_STATIC_READ 0x88E5
    #define GL_STATIC_COPY 0x88E6
    #define GL_DYNAMIC_DRAW 0x88E8
    #define GL_DYNAMIC_READ 0x88E9
    #define GL_DYNAMIC_COPY 0x88EA
    #define GL_SAMPLES_PASSED 0x8914
    #define GL_SRC1_ALPHA 0x8589
    #define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
    #if !defined(OGL_NO_COMPAT)
        #define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
        #define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
        #define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
        #define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
        #define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
        #define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
        #define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
        #define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
        #define GL_FOG_COORD_SRC 0x8450
        #define GL_FOG_COORD 0x8451
        #define GL_CURRENT_FOG_COORD 0x8453
        #define GL_FOG_COORD_ARRAY_TYPE 0x8454
        #define GL_FOG_COORD_ARRAY_STRIDE 0x8455
        #define GL_FOG_COORD_ARRAY_POINTER 0x8456
        #define GL_FOG_COORD_ARRAY 0x8457
        #define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
        #define GL_SRC0_RGB 0x8580
        #define GL_SRC1_RGB 0x8581
        #define GL_SRC2_RGB 0x8582
        #define GL_SRC0_ALPHA 0x8588
        #define GL_SRC2_ALPHA 0x858A
    #endif

    // OpenGL 2.0

    #define GL_BLEND_EQUATION_RGB 0x8009
    #define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
    #define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
    #define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
    #define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
    #define GL_CURRENT_VERTEX_ATTRIB 0x8626
    #define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
    #define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
    #define GL_STENCIL_BACK_FUNC 0x8800
    #define GL_STENCIL_BACK_FAIL 0x8801
    #define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
    #define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
    #define GL_MAX_DRAW_BUFFERS 0x8824
    #define GL_DRAW_BUFFER0 0x8825
    #define GL_DRAW_BUFFER1 0x8826
    #define GL_DRAW_BUFFER2 0x8827
    #define GL_DRAW_BUFFER3 0x8828
    #define GL_DRAW_BUFFER4 0x8829
    #define GL_DRAW_BUFFER5 0x882A
    #define GL_DRAW_BUFFER6 0x882B
    #define GL_DRAW_BUFFER7 0x882C
    #define GL_DRAW_BUFFER8 0x882D
    #define GL_DRAW_BUFFER9 0x882E
    #define GL_DRAW_BUFFER10 0x882F
    #define GL_DRAW_BUFFER11 0x8830
    #define GL_DRAW_BUFFER12 0x8831
    #define GL_DRAW_BUFFER13 0x8832
    #define GL_DRAW_BUFFER14 0x8833
    #define GL_DRAW_BUFFER15 0x8834
    #define GL_BLEND_EQUATION_ALPHA 0x883D
    #define GL_MAX_VERTEX_ATTRIBS 0x8869
    #define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
    #define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
    #define GL_FRAGMENT_SHADER 0x8B30
    #define GL_VERTEX_SHADER 0x8B31
    #define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
    #define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
    #define GL_MAX_VARYING_FLOATS 0x8B4B
    #define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
    #define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
    #define GL_SHADER_TYPE 0x8B4F
    #define GL_FLOAT_VEC2 0x8B50
    #define GL_FLOAT_VEC3 0x8B51
    #define GL_FLOAT_VEC4 0x8B52
    #define GL_INT_VEC2 0x8B53
    #define GL_INT_VEC3 0x8B54
    #define GL_INT_VEC4 0x8B55
    #define GL_BOOL 0x8B56
    #define GL_BOOL_VEC2 0x8B57
    #define GL_BOOL_VEC3 0x8B58
    #define GL_BOOL_VEC4 0x8B59
    #define GL_FLOAT_MAT2 0x8B5A
    #define GL_FLOAT_MAT3 0x8B5B
    #define GL_FLOAT_MAT4 0x8B5C
    #define GL_SAMPLER_1D 0x8B5D
    #define GL_SAMPLER_2D 0x8B5E
    #define GL_SAMPLER_3D 0x8B5F
    #define GL_SAMPLER_CUBE 0x8B60
    #define GL_SAMPLER_1D_SHADOW 0x8B61
    #define GL_SAMPLER_2D_SHADOW 0x8B62
    #define GL_DELETE_STATUS 0x8B80
    #define GL_COMPILE_STATUS 0x8B81
    #define GL_LINK_STATUS 0x8B82
    #define GL_VALIDATE_STATUS 0x8B83
    #define GL_INFO_LOG_LENGTH 0x8B84
    #define GL_ATTACHED_SHADERS 0x8B85
    #define GL_ACTIVE_UNIFORMS 0x8B86
    #define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
    #define GL_SHADER_SOURCE_LENGTH 0x8B88
    #define GL_ACTIVE_ATTRIBUTES 0x8B89
    #define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
    #define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
    #define GL_SHADING_LANGUAGE_VERSION 0x8B8C
    #define GL_CURRENT_PROGRAM 0x8B8D
    #define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
    #define GL_LOWER_LEFT 0x8CA1
    #define GL_UPPER_LEFT 0x8CA2
    #define GL_STENCIL_BACK_REF 0x8CA3
    #define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
    #define GL_STENCIL_BACK_WRITEMASK 0x8CA5
    #if !defined(OGL_NO_COMPAT)
        #define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
        #define GL_POINT_SPRITE 0x8861
        #define GL_COORD_REPLACE 0x8862
        #define GL_MAX_TEXTURE_COORDS 0x8871
    #endif

    // OpenGL 2.1

    #define GL_PIXEL_PACK_BUFFER 0x88EB
    #define GL_PIXEL_UNPACK_BUFFER 0x88EC
    #define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
    #define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
    #define GL_FLOAT_MAT2x3 0x8B65
    #define GL_FLOAT_MAT2x4 0x8B66
    #define GL_FLOAT_MAT3x2 0x8B67
    #define GL_FLOAT_MAT3x4 0x8B68
    #define GL_FLOAT_MAT4x2 0x8B69
    #define GL_FLOAT_MAT4x3 0x8B6A
    #define GL_SRGB 0x8C40
    #define GL_SRGB8 0x8C41
    #define GL_SRGB_ALPHA 0x8C42
    #define GL_SRGB8_ALPHA8 0x8C43
    #define GL_COMPRESSED_SRGB 0x8C48
    #define GL_COMPRESSED_SRGB_ALPHA 0x8C49
    #if !defined(OGL_NO_COMPAT)
        #define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
        #define GL_SLUMINANCE_ALPHA 0x8C44
        #define GL_SLUMINANCE8_ALPHA8 0x8C45
        #define GL_SLUMINANCE 0x8C46
        #define GL_SLUMINANCE8 0x8C47
        #define GL_COMPRESSED_SLUMINANCE 0x8C4A
        #define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
    #endif

    // OpenGL 3.0

    #define GL_COMPARE_REF_TO_TEXTURE 0x884E
    #define GL_CLIP_DISTANCE0 0x3000
    #define GL_CLIP_DISTANCE1 0x3001
    #define GL_CLIP_DISTANCE2 0x3002
    #define GL_CLIP_DISTANCE3 0x3003
    #define GL_CLIP_DISTANCE4 0x3004
    #define GL_CLIP_DISTANCE5 0x3005
    #define GL_CLIP_DISTANCE6 0x3006
    #define GL_CLIP_DISTANCE7 0x3007
    #define GL_MAX_CLIP_DISTANCES 0x0D32
    #define GL_MAJOR_VERSION 0x821B
    #define GL_MINOR_VERSION 0x821C
    #define GL_NUM_EXTENSIONS 0x821D
    #define GL_CONTEXT_FLAGS 0x821E
    #define GL_COMPRESSED_RED 0x8225
    #define GL_COMPRESSED_RG 0x8226
    #define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
    #define GL_RGBA32F 0x8814
    #define GL_RGB32F 0x8815
    #define GL_RGBA16F 0x881A
    #define GL_RGB16F 0x881B
    #define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
    #define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
    #define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
    #define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
    #define GL_CLAMP_READ_COLOR 0x891C
    #define GL_FIXED_ONLY 0x891D
    #define GL_MAX_VARYING_COMPONENTS 0x8B4B
    #define GL_TEXTURE_1D_ARRAY 0x8C18
    #define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
    #define GL_TEXTURE_2D_ARRAY 0x8C1A
    #define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
    #define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
    #define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
    #define GL_R11F_G11F_B10F 0x8C3A
    #define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
    #define GL_RGB9_E5 0x8C3D
    #define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
    #define GL_TEXTURE_SHARED_SIZE 0x8C3F
    #define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
    #define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
    #define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
    #define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
    #define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
    #define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
    #define GL_PRIMITIVES_GENERATED 0x8C87
    #define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
    #define GL_RASTERIZER_DISCARD 0x8C89
    #define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
    #define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
    #define GL_INTERLEAVED_ATTRIBS 0x8C8C
    #define GL_SEPARATE_ATTRIBS 0x8C8D
    #define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
    #define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
    #define GL_RGBA32UI 0x8D70
    #define GL_RGB32UI 0x8D71
    #define GL_RGBA16UI 0x8D76
    #define GL_RGB16UI 0x8D77
    #define GL_RGBA8UI 0x8D7C
    #define GL_RGB8UI 0x8D7D
    #define GL_RGBA32I 0x8D82
    #define GL_RGB32I 0x8D83
    #define GL_RGBA16I 0x8D88
    #define GL_RGB16I 0x8D89
    #define GL_RGBA8I 0x8D8E
    #define GL_RGB8I 0x8D8F
    #define GL_RED_INTEGER 0x8D94
    #define GL_GREEN_INTEGER 0x8D95
    #define GL_BLUE_INTEGER 0x8D96
    #define GL_RGB_INTEGER 0x8D98
    #define GL_RGBA_INTEGER 0x8D99
    #define GL_BGR_INTEGER 0x8D9A
    #define GL_BGRA_INTEGER 0x8D9B
    #define GL_SAMPLER_1D_ARRAY 0x8DC0
    #define GL_SAMPLER_2D_ARRAY 0x8DC1
    #define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
    #define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
    #define GL_SAMPLER_CUBE_SHADOW 0x8DC5
    #define GL_UNSIGNED_INT_VEC2 0x8DC6
    #define GL_UNSIGNED_INT_VEC3 0x8DC7
    #define GL_UNSIGNED_INT_VEC4 0x8DC8
    #define GL_INT_SAMPLER_1D 0x8DC9
    #define GL_INT_SAMPLER_2D 0x8DCA
    #define GL_INT_SAMPLER_3D 0x8DCB
    #define GL_INT_SAMPLER_CUBE 0x8DCC
    #define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
    #define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
    #define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
    #define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
    #define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
    #define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
    #define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
    #define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
    #define GL_QUERY_WAIT 0x8E13
    #define GL_QUERY_NO_WAIT 0x8E14
    #define GL_QUERY_BY_REGION_WAIT 0x8E15
    #define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
    #define GL_BUFFER_ACCESS_FLAGS 0x911F
    #define GL_BUFFER_MAP_LENGTH 0x9120
    #define GL_BUFFER_MAP_OFFSET 0x9121
    #define GL_DEPTH_COMPONENT32F 0x8CAC
    #define GL_DEPTH32F_STENCIL8 0x8CAD
    #define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
    #define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
    #define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
    #define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
    #define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
    #define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
    #define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
    #define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
    #define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
    #define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
    #define GL_FRAMEBUFFER_DEFAULT 0x8218
    #define GL_FRAMEBUFFER_UNDEFINED 0x8219
    #define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
    #define GL_MAX_RENDERBUFFER_SIZE 0x84E8
    #define GL_DEPTH_STENCIL 0x84F9
    #define GL_UNSIGNED_INT_24_8 0x84FA
    #define GL_DEPTH24_STENCIL8 0x88F0
    #define GL_TEXTURE_STENCIL_SIZE 0x88F1
    #define GL_TEXTURE_RED_TYPE 0x8C10
    #define GL_TEXTURE_GREEN_TYPE 0x8C11
    #define GL_TEXTURE_BLUE_TYPE 0x8C12
    #define GL_TEXTURE_ALPHA_TYPE 0x8C13
    #define GL_TEXTURE_DEPTH_TYPE 0x8C16
    #define GL_UNSIGNED_NORMALIZED 0x8C17
    #define GL_FRAMEBUFFER_BINDING 0x8CA6
    #define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
    #define GL_RENDERBUFFER_BINDING 0x8CA7
    #define GL_READ_FRAMEBUFFER 0x8CA8
    #define GL_DRAW_FRAMEBUFFER 0x8CA9
    #define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
    #define GL_RENDERBUFFER_SAMPLES 0x8CAB
    #define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
    #define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
    #define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
    #define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
    #define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
    #define GL_FRAMEBUFFER_COMPLETE 0x8CD5
    #define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
    #define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
    #define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
    #define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
    #define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
    #define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
    #define GL_COLOR_ATTACHMENT0 0x8CE0
    #define GL_COLOR_ATTACHMENT1 0x8CE1
    #define GL_COLOR_ATTACHMENT2 0x8CE2
    #define GL_COLOR_ATTACHMENT3 0x8CE3
    #define GL_COLOR_ATTACHMENT4 0x8CE4
    #define GL_COLOR_ATTACHMENT5 0x8CE5
    #define GL_COLOR_ATTACHMENT6 0x8CE6
    #define GL_COLOR_ATTACHMENT7 0x8CE7
    #define GL_COLOR_ATTACHMENT8 0x8CE8
    #define GL_COLOR_ATTACHMENT9 0x8CE9
    #define GL_COLOR_ATTACHMENT10 0x8CEA
    #define GL_COLOR_ATTACHMENT11 0x8CEB
    #define GL_COLOR_ATTACHMENT12 0x8CEC
    #define GL_COLOR_ATTACHMENT13 0x8CED
    #define GL_COLOR_ATTACHMENT14 0x8CEE
    #define GL_COLOR_ATTACHMENT15 0x8CEF
    #define GL_COLOR_ATTACHMENT16 0x8CF0
    #define GL_COLOR_ATTACHMENT17 0x8CF1
    #define GL_COLOR_ATTACHMENT18 0x8CF2
    #define GL_COLOR_ATTACHMENT19 0x8CF3
    #define GL_COLOR_ATTACHMENT20 0x8CF4
    #define GL_COLOR_ATTACHMENT21 0x8CF5
    #define GL_COLOR_ATTACHMENT22 0x8CF6
    #define GL_COLOR_ATTACHMENT23 0x8CF7
    #define GL_COLOR_ATTACHMENT24 0x8CF8
    #define GL_COLOR_ATTACHMENT25 0x8CF9
    #define GL_COLOR_ATTACHMENT26 0x8CFA
    #define GL_COLOR_ATTACHMENT27 0x8CFB
    #define GL_COLOR_ATTACHMENT28 0x8CFC
    #define GL_COLOR_ATTACHMENT29 0x8CFD
    #define GL_COLOR_ATTACHMENT30 0x8CFE
    #define GL_COLOR_ATTACHMENT31 0x8CFF
    #define GL_DEPTH_ATTACHMENT 0x8D00
    #define GL_STENCIL_ATTACHMENT 0x8D20
    #define GL_FRAMEBUFFER 0x8D40
    #define GL_RENDERBUFFER 0x8D41
    #define GL_RENDERBUFFER_WIDTH 0x8D42
    #define GL_RENDERBUFFER_HEIGHT 0x8D43
    #define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
    #define GL_STENCIL_INDEX1 0x8D46
    #define GL_STENCIL_INDEX4 0x8D47
    #define GL_STENCIL_INDEX8 0x8D48
    #define GL_STENCIL_INDEX16 0x8D49
    #define GL_RENDERBUFFER_RED_SIZE 0x8D50
    #define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
    #define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
    #define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
    #define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
    #define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
    #define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
    #define GL_MAX_SAMPLES 0x8D57
    #if !defined(OGL_NO_COMPAT)
        #define GL_INDEX 0x8222
        #define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
        #define GL_TEXTURE_INTENSITY_TYPE 0x8C15
    #endif
    #define GL_FRAMEBUFFER_SRGB 0x8DB9
    #define GL_HALF_FLOAT 0x140B
    #define GL_MAP_READ_BIT 0x0001
    #define GL_MAP_WRITE_BIT 0x0002
    #define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
    #define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
    #define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
    #define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
    #define GL_COMPRESSED_RED_RGTC1 0x8DBB
    #define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
    #define GL_COMPRESSED_RG_RGTC2 0x8DBD
    #define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
    #define GL_RG 0x8227
    #define GL_RG_INTEGER 0x8228
    #define GL_R8 0x8229
    #define GL_R16 0x822A
    #define GL_RG8 0x822B
    #define GL_RG16 0x822C
    #define GL_R16F 0x822D
    #define GL_R32F 0x822E
    #define GL_RG16F 0x822F
    #define GL_RG32F 0x8230
    #define GL_R8I 0x8231
    #define GL_R8UI 0x8232
    #define GL_R16I 0x8233
    #define GL_R16UI 0x8234
    #define GL_R32I 0x8235
    #define GL_R32UI 0x8236
    #define GL_RG8I 0x8237
    #define GL_RG8UI 0x8238
    #define GL_RG16I 0x8239
    #define GL_RG16UI 0x823A
    #define GL_RG32I 0x823B
    #define GL_RG32UI 0x823C
    #define GL_VERTEX_ARRAY_BINDING 0x85B5
    #if !defined(OGL_NO_COMPAT)
        #define GL_CLAMP_VERTEX_COLOR 0x891A
        #define GL_CLAMP_FRAGMENT_COLOR 0x891B
        #define GL_ALPHA_INTEGER 0x8D97
    #endif

    // OpenGL 3.1

    #define GL_SAMPLER_2D_RECT 0x8B63
    #define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
    #define GL_SAMPLER_BUFFER 0x8DC2
    #define GL_INT_SAMPLER_2D_RECT 0x8DCD
    #define GL_INT_SAMPLER_BUFFER 0x8DD0
    #define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
    #define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
    #define GL_TEXTURE_BUFFER 0x8C2A
    #define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
    #define GL_TEXTURE_BINDING_BUFFER 0x8C2C
    #define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
    #define GL_TEXTURE_RECTANGLE 0x84F5
    #define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
    #define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
    #define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
    #define GL_R8_SNORM 0x8F94
    #define GL_RG8_SNORM 0x8F95
    #define GL_RGB8_SNORM 0x8F96
    #define GL_RGBA8_SNORM 0x8F97
    #define GL_R16_SNORM 0x8F98
    #define GL_RG16_SNORM 0x8F99
    #define GL_RGB16_SNORM 0x8F9A
    #define GL_RGBA16_SNORM 0x8F9B
    #define GL_SIGNED_NORMALIZED 0x8F9C
    #define GL_PRIMITIVE_RESTART 0x8F9D
    #define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
    #define GL_COPY_READ_BUFFER 0x8F36
    #define GL_COPY_WRITE_BUFFER 0x8F37
    #define GL_UNIFORM_BUFFER 0x8A11
    #define GL_UNIFORM_BUFFER_BINDING 0x8A28
    #define GL_UNIFORM_BUFFER_START 0x8A29
    #define GL_UNIFORM_BUFFER_SIZE 0x8A2A
    #define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
    #define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
    #define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
    #define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
    #define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
    #define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
    #define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
    #define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
    #define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
    #define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
    #define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
    #define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
    #define GL_UNIFORM_TYPE 0x8A37
    #define GL_UNIFORM_SIZE 0x8A38
    #define GL_UNIFORM_NAME_LENGTH 0x8A39
    #define GL_UNIFORM_BLOCK_INDEX 0x8A3A
    #define GL_UNIFORM_OFFSET 0x8A3B
    #define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
    #define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
    #define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
    #define GL_UNIFORM_BLOCK_BINDING 0x8A3F
    #define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
    #define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
    #define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
    #define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
    #define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
    #define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
    #define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
    #define GL_INVALID_INDEX 0xFFFFFFFFu

    // OpenGL 3.2

    #define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
    #define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
    #define GL_LINES_ADJACENCY 0x000A
    #define GL_LINE_STRIP_ADJACENCY 0x000B
    #define GL_TRIANGLES_ADJACENCY 0x000C
    #define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
    #define GL_PROGRAM_POINT_SIZE 0x8642
    #define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
    #define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
    #define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
    #define GL_GEOMETRY_SHADER 0x8DD9
    #define GL_GEOMETRY_VERTICES_OUT 0x8916
    #define GL_GEOMETRY_INPUT_TYPE 0x8917
    #define GL_GEOMETRY_OUTPUT_TYPE 0x8918
    #define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
    #define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
    #define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
    #define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
    #define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
    #define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
    #define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
    #define GL_CONTEXT_PROFILE_MASK 0x9126
    #define GL_DEPTH_CLAMP 0x864F
    #define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
    #define GL_FIRST_VERTEX_CONVENTION 0x8E4D
    #define GL_LAST_VERTEX_CONVENTION 0x8E4E
    #define GL_PROVOKING_VERTEX 0x8E4F
    #define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
    #define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
    #define GL_OBJECT_TYPE 0x9112
    #define GL_SYNC_CONDITION 0x9113
    #define GL_SYNC_STATUS 0x9114
    #define GL_SYNC_FLAGS 0x9115
    #define GL_SYNC_FENCE 0x9116
    #define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
    #define GL_UNSIGNALED 0x9118
    #define GL_SIGNALED 0x9119
    #define GL_ALREADY_SIGNALED 0x911A
    #define GL_TIMEOUT_EXPIRED 0x911B
    #define GL_CONDITION_SATISFIED 0x911C
    #define GL_WAIT_FAILED 0x911D
    #define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFFull
    #define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
    #define GL_SAMPLE_POSITION 0x8E50
    #define GL_SAMPLE_MASK 0x8E51
    #define GL_SAMPLE_MASK_VALUE 0x8E52
    #define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
    #define GL_TEXTURE_2D_MULTISAMPLE 0x9100
    #define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
    #define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
    #define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
    #define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
    #define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
    #define GL_TEXTURE_SAMPLES 0x9106
    #define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
    #define GL_SAMPLER_2D_MULTISAMPLE 0x9108
    #define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
    #define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
    #define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
    #define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
    #define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
    #define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
    #define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
    #define GL_MAX_INTEGER_SAMPLES 0x9110

    // OpenGL 3.3

    #define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
    #define GL_SRC1_COLOR 0x88F9
    #define GL_ONE_MINUS_SRC1_COLOR 0x88FA
    #define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
    #define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
    #define GL_ANY_SAMPLES_PASSED 0x8C2F
    #define GL_SAMPLER_BINDING 0x8919
    #define GL_RGB10_A2UI 0x906F
    #define GL_TEXTURE_SWIZZLE_R 0x8E42
    #define GL_TEXTURE_SWIZZLE_G 0x8E43
    #define GL_TEXTURE_SWIZZLE_B 0x8E44
    #define GL_TEXTURE_SWIZZLE_A 0x8E45
    #define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
    #define GL_TIME_ELAPSED 0x88BF
    #define GL_TIMESTAMP 0x8E28
    #define GL_INT_2_10_10_10_REV 0x8D9F

    // OpenGL 4.0

    #define GL_SAMPLE_SHADING 0x8C36
    #define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
    #define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
    #define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
    #define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
    #define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
    #define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
    #define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
    #define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
    #define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
    #define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
    #define GL_DRAW_INDIRECT_BUFFER 0x8F3F
    #define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
    #define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
    #define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
    #define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
    #define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
    #define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
    #define GL_MAX_VERTEX_STREAMS 0x8E71
    #define GL_DOUBLE_VEC2 0x8FFC
    #define GL_DOUBLE_VEC3 0x8FFD
    #define GL_DOUBLE_VEC4 0x8FFE
    #define GL_DOUBLE_MAT2 0x8F46
    #define GL_DOUBLE_MAT3 0x8F47
    #define GL_DOUBLE_MAT4 0x8F48
    #define GL_DOUBLE_MAT2x3 0x8F49
    #define GL_DOUBLE_MAT2x4 0x8F4A
    #define GL_DOUBLE_MAT3x2 0x8F4B
    #define GL_DOUBLE_MAT3x4 0x8F4C
    #define GL_DOUBLE_MAT4x2 0x8F4D
    #define GL_DOUBLE_MAT4x3 0x8F4E
    #define GL_ACTIVE_SUBROUTINES 0x8DE5
    #define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
    #define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
    #define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
    #define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
    #define GL_MAX_SUBROUTINES 0x8DE7
    #define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
    #define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
    #define GL_COMPATIBLE_SUBROUTINES 0x8E4B
    #define GL_PATCHES 0x000E
    #define GL_PATCH_VERTICES 0x8E72
    #define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
    #define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
    #define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
    #define GL_TESS_GEN_MODE 0x8E76
    #define GL_TESS_GEN_SPACING 0x8E77
    #define GL_TESS_GEN_VERTEX_ORDER 0x8E78
    #define GL_TESS_GEN_POINT_MODE 0x8E79
    #define GL_ISOLINES 0x8E7A
    #define GL_QUADS 0x0007
    #define GL_FRACTIONAL_ODD 0x8E7B
    #define GL_FRACTIONAL_EVEN 0x8E7C
    #define GL_MAX_PATCH_VERTICES 0x8E7D
    #define GL_MAX_TESS_GEN_LEVEL 0x8E7E
    #define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
    #define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
    #define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
    #define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
    #define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
    #define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
    #define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
    #define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
    #define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
    #define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
    #define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
    #define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
    #define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
    #define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
    #define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
    #define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
    #define GL_TESS_EVALUATION_SHADER 0x8E87
    #define GL_TESS_CONTROL_SHADER 0x8E88
    #define GL_TRANSFORM_FEEDBACK 0x8E22
    #define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
    #define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
    #define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
    #define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
    #define GL_MAX_VERTEX_STREAMS 0x8E71

    // OpenGL 4.1

    #define GL_FIXED 0x140C
    #define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
    #define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
    #define GL_LOW_FLOAT 0x8DF0
    #define GL_MEDIUM_FLOAT 0x8DF1
    #define GL_HIGH_FLOAT 0x8DF2
    #define GL_LOW_INT 0x8DF3
    #define GL_MEDIUM_INT 0x8DF4
    #define GL_HIGH_INT 0x8DF5
    #define GL_SHADER_COMPILER 0x8DFA
    #define GL_SHADER_BINARY_FORMATS 0x8DF8
    #define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
    #define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
    #define GL_MAX_VARYING_VECTORS 0x8DFC
    #define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
    #define GL_RGB565 0x8D62
    #define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
    #define GL_PROGRAM_BINARY_LENGTH 0x8741
    #define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
    #define GL_PROGRAM_BINARY_FORMATS 0x87FF
    #define GL_VERTEX_SHADER_BIT 0x00000001
    #define GL_FRAGMENT_SHADER_BIT 0x00000002
    #define GL_GEOMETRY_SHADER_BIT 0x00000004
    #define GL_TESS_CONTROL_SHADER_BIT 0x00000008
    #define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
    #define GL_ALL_SHADER_BITS 0xFFFFFFFF
    #define GL_PROGRAM_SEPARABLE 0x8258
    #define GL_ACTIVE_PROGRAM 0x8259
    #define GL_PROGRAM_PIPELINE_BINDING 0x825A
    #define GL_MAX_VIEWPORTS 0x825B
    #define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
    #define GL_VIEWPORT_BOUNDS_RANGE 0x825D
    #define GL_LAYER_PROVOKING_VERTEX 0x825E
    #define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
    #define GL_UNDEFINED_VERTEX 0x8260

    // OpenGL 4.2

    #define GL_COPY_READ_BUFFER_BINDING 0x8F36
    #define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
    #define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
    #define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
    #define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
    #define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
    #define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
    #define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
    #define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
    #define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
    #define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
    #define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
    #define GL_NUM_SAMPLE_COUNTS 0x9380
    #define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC
    #define GL_ATOMIC_COUNTER_BUFFER 0x92C0
    #define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
    #define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
    #define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
    #define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
    #define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
    #define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
    #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
    #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
    #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
    #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
    #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
    #define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
    #define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
    #define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
    #define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
    #define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
    #define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
    #define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
    #define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
    #define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
    #define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
    #define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
    #define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
    #define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
    #define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
    #define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
    #define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
    #define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
    #define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
    #define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
    #define GL_UNIFORM_BARRIER_BIT 0x00000004
    #define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
    #define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
    #define GL_COMMAND_BARRIER_BIT 0x00000040
    #define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
    #define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
    #define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
    #define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
    #define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
    #define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
    #define GL_ALL_BARRIER_BITS 0xFFFFFFFF
    #define GL_MAX_IMAGE_UNITS 0x8F38
    #define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
    #define GL_IMAGE_BINDING_NAME 0x8F3A
    #define GL_IMAGE_BINDING_LEVEL 0x8F3B
    #define GL_IMAGE_BINDING_LAYERED 0x8F3C
    #define GL_IMAGE_BINDING_LAYER 0x8F3D
    #define GL_IMAGE_BINDING_ACCESS 0x8F3E
    #define GL_IMAGE_1D 0x904C
    #define GL_IMAGE_2D 0x904D
    #define GL_IMAGE_3D 0x904E
    #define GL_IMAGE_2D_RECT 0x904F
    #define GL_IMAGE_CUBE 0x9050
    #define GL_IMAGE_BUFFER 0x9051
    #define GL_IMAGE_1D_ARRAY 0x9052
    #define GL_IMAGE_2D_ARRAY 0x9053
    #define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
    #define GL_IMAGE_2D_MULTISAMPLE 0x9055
    #define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
    #define GL_INT_IMAGE_1D 0x9057
    #define GL_INT_IMAGE_2D 0x9058
    #define GL_INT_IMAGE_3D 0x9059
    #define GL_INT_IMAGE_2D_RECT 0x905A
    #define GL_INT_IMAGE_CUBE 0x905B
    #define GL_INT_IMAGE_BUFFER 0x905C
    #define GL_INT_IMAGE_1D_ARRAY 0x905D
    #define GL_INT_IMAGE_2D_ARRAY 0x905E
    #define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
    #define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
    #define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
    #define GL_UNSIGNED_INT_IMAGE_1D 0x9062
    #define GL_UNSIGNED_INT_IMAGE_2D 0x9063
    #define GL_UNSIGNED_INT_IMAGE_3D 0x9064
    #define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
    #define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
    #define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
    #define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
    #define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
    #define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
    #define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
    #define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
    #define GL_MAX_IMAGE_SAMPLES 0x906D
    #define GL_IMAGE_BINDING_FORMAT 0x906E
    #define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
    #define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
    #define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
    #define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
    #define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
    #define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
    #define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
    #define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
    #define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
    #define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
    #define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
    #define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
    #define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
    #define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F

    // OpenGL 4.3

    #define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
    #define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E
    #define GL_COMPRESSED_RGB8_ETC2 0x9274
    #define GL_COMPRESSED_SRGB8_ETC2 0x9275
    #define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
    #define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
    #define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
    #define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
    #define GL_COMPRESSED_R11_EAC 0x9270
    #define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
    #define GL_COMPRESSED_RG11_EAC 0x9272
    #define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
    #define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
    #define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
    #define GL_MAX_ELEMENT_INDEX 0x8D6B
    #define GL_COMPUTE_SHADER 0x91B9
    #define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
    #define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
    #define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
    #define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
    #define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
    #define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
    #define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
    #define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
    #define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
    #define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
    #define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
    #define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
    #define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
    #define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
    #define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
    #define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
    #define GL_COMPUTE_SHADER_BIT 0x00000020
    #define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
    #define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
    #define GL_DEBUG_CALLBACK_FUNCTION 0x8244
    #define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
    #define GL_DEBUG_SOURCE_API 0x8246
    #define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
    #define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
    #define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
    #define GL_DEBUG_SOURCE_APPLICATION 0x824A
    #define GL_DEBUG_SOURCE_OTHER 0x824B
    #define GL_DEBUG_TYPE_ERROR 0x824C
    #define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
    #define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
    #define GL_DEBUG_TYPE_PORTABILITY 0x824F
    #define GL_DEBUG_TYPE_PERFORMANCE 0x8250
    #define GL_DEBUG_TYPE_OTHER 0x8251
    #define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
    #define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
    #define GL_DEBUG_LOGGED_MESSAGES 0x9145
    #define GL_DEBUG_SEVERITY_HIGH 0x9146
    #define GL_DEBUG_SEVERITY_MEDIUM 0x9147
    #define GL_DEBUG_SEVERITY_LOW 0x9148
    #define GL_DEBUG_TYPE_MARKER 0x8268
    #define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
    #define GL_DEBUG_TYPE_POP_GROUP 0x826A
    #define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
    #define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
    #define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
    #define GL_BUFFER 0x82E0
    #define GL_SHADER 0x82E1
    #define GL_PROGRAM 0x82E2
    #define GL_VERTEX_ARRAY 0x8074
    #define GL_QUERY 0x82E3
    #define GL_PROGRAM_PIPELINE 0x82E4
    #define GL_SAMPLER 0x82E6
    #define GL_MAX_LABEL_LENGTH 0x82E8
    #define GL_DEBUG_OUTPUT 0x92E0
    #define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
    #define GL_MAX_UNIFORM_LOCATIONS 0x826E
    #define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
    #define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
    #define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
    #define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
    #define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
    #define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
    #define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
    #define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
    #define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
    #define GL_INTERNALFORMAT_SUPPORTED 0x826F
    #define GL_INTERNALFORMAT_PREFERRED 0x8270
    #define GL_INTERNALFORMAT_RED_SIZE 0x8271
    #define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
    #define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
    #define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
    #define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
    #define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
    #define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
    #define GL_INTERNALFORMAT_RED_TYPE 0x8278
    #define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
    #define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
    #define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
    #define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
    #define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
    #define GL_MAX_WIDTH 0x827E
    #define GL_MAX_HEIGHT 0x827F
    #define GL_MAX_DEPTH 0x8280
    #define GL_MAX_LAYERS 0x8281
    #define GL_MAX_COMBINED_DIMENSIONS 0x8282
    #define GL_COLOR_COMPONENTS 0x8283
    #define GL_DEPTH_COMPONENTS 0x8284
    #define GL_STENCIL_COMPONENTS 0x8285
    #define GL_COLOR_RENDERABLE 0x8286
    #define GL_DEPTH_RENDERABLE 0x8287
    #define GL_STENCIL_RENDERABLE 0x8288
    #define GL_FRAMEBUFFER_RENDERABLE 0x8289
    #define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
    #define GL_FRAMEBUFFER_BLEND 0x828B
    #define GL_READ_PIXELS 0x828C
    #define GL_READ_PIXELS_FORMAT 0x828D
    #define GL_READ_PIXELS_TYPE 0x828E
    #define GL_TEXTURE_IMAGE_FORMAT 0x828F
    #define GL_TEXTURE_IMAGE_TYPE 0x8290
    #define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
    #define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
    #define GL_MIPMAP 0x8293
    #define GL_MANUAL_GENERATE_MIPMAP 0x8294
    #define GL_AUTO_GENERATE_MIPMAP 0x8295
    #define GL_COLOR_ENCODING 0x8296
    #define GL_SRGB_READ 0x8297
    #define GL_SRGB_WRITE 0x8298
    #define GL_FILTER 0x829A
    #define GL_VERTEX_TEXTURE 0x829B
    #define GL_TESS_CONTROL_TEXTURE 0x829C
    #define GL_TESS_EVALUATION_TEXTURE 0x829D
    #define GL_GEOMETRY_TEXTURE 0x829E
    #define GL_FRAGMENT_TEXTURE 0x829F
    #define GL_COMPUTE_TEXTURE 0x82A0
    #define GL_TEXTURE_SHADOW 0x82A1
    #define GL_TEXTURE_GATHER 0x82A2
    #define GL_TEXTURE_GATHER_SHADOW 0x82A3
    #define GL_SHADER_IMAGE_LOAD 0x82A4
    #define GL_SHADER_IMAGE_STORE 0x82A5
    #define GL_SHADER_IMAGE_ATOMIC 0x82A6
    #define GL_IMAGE_TEXEL_SIZE 0x82A7
    #define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
    #define GL_IMAGE_PIXEL_FORMAT 0x82A9
    #define GL_IMAGE_PIXEL_TYPE 0x82AA
    #define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
    #define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
    #define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
    #define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
    #define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
    #define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
    #define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
    #define GL_CLEAR_BUFFER 0x82B4
    #define GL_TEXTURE_VIEW 0x82B5
    #define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
    #define GL_FULL_SUPPORT 0x82B7
    #define GL_CAVEAT_SUPPORT 0x82B8
    #define GL_IMAGE_CLASS_4_X_32 0x82B9
    #define GL_IMAGE_CLASS_2_X_32 0x82BA
    #define GL_IMAGE_CLASS_1_X_32 0x82BB
    #define GL_IMAGE_CLASS_4_X_16 0x82BC
    #define GL_IMAGE_CLASS_2_X_16 0x82BD
    #define GL_IMAGE_CLASS_1_X_16 0x82BE
    #define GL_IMAGE_CLASS_4_X_8 0x82BF
    #define GL_IMAGE_CLASS_2_X_8 0x82C0
    #define GL_IMAGE_CLASS_1_X_8 0x82C1
    #define GL_IMAGE_CLASS_11_11_10 0x82C2
    #define GL_IMAGE_CLASS_10_10_10_2 0x82C3
    #define GL_VIEW_CLASS_128_BITS 0x82C4
    #define GL_VIEW_CLASS_96_BITS 0x82C5
    #define GL_VIEW_CLASS_64_BITS 0x82C6
    #define GL_VIEW_CLASS_48_BITS 0x82C7
    #define GL_VIEW_CLASS_32_BITS 0x82C8
    #define GL_VIEW_CLASS_24_BITS 0x82C9
    #define GL_VIEW_CLASS_16_BITS 0x82CA
    #define GL_VIEW_CLASS_8_BITS 0x82CB
    #define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
    #define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
    #define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
    #define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
    #define GL_VIEW_CLASS_RGTC1_RED 0x82D0
    #define GL_VIEW_CLASS_RGTC2_RG 0x82D1
    #define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
    #define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
    #define GL_UNIFORM 0x92E1
    #define GL_UNIFORM_BLOCK 0x92E2
    #define GL_PROGRAM_INPUT 0x92E3
    #define GL_PROGRAM_OUTPUT 0x92E4
    #define GL_BUFFER_VARIABLE 0x92E5
    #define GL_SHADER_STORAGE_BLOCK 0x92E6
    #define GL_VERTEX_SUBROUTINE 0x92E8
    #define GL_TESS_CONTROL_SUBROUTINE 0x92E9
    #define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
    #define GL_GEOMETRY_SUBROUTINE 0x92EB
    #define GL_FRAGMENT_SUBROUTINE 0x92EC
    #define GL_COMPUTE_SUBROUTINE 0x92ED
    #define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
    #define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
    #define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
    #define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
    #define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
    #define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
    #define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
    #define GL_ACTIVE_RESOURCES 0x92F5
    #define GL_MAX_NAME_LENGTH 0x92F6
    #define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
    #define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
    #define GL_NAME_LENGTH 0x92F9
    #define GL_TYPE 0x92FA
    #define GL_ARRAY_SIZE 0x92FB
    #define GL_OFFSET 0x92FC
    #define GL_BLOCK_INDEX 0x92FD
    #define GL_ARRAY_STRIDE 0x92FE
    #define GL_MATRIX_STRIDE 0x92FF
    #define GL_IS_ROW_MAJOR 0x9300
    #define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
    #define GL_BUFFER_BINDING 0x9302
    #define GL_BUFFER_DATA_SIZE 0x9303
    #define GL_NUM_ACTIVE_VARIABLES 0x9304
    #define GL_ACTIVE_VARIABLES 0x9305
    #define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
    #define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
    #define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
    #define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
    #define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
    #define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
    #define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
    #define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
    #define GL_LOCATION 0x930E
    #define GL_LOCATION_INDEX 0x930F
    #define GL_IS_PER_PATCH 0x92E7
    #define GL_SHADER_STORAGE_BUFFER 0x90D2
    #define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
    #define GL_SHADER_STORAGE_BUFFER_START 0x90D4
    #define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
    #define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
    #define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
    #define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
    #define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
    #define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
    #define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
    #define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
    #define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
    #define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
    #define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
    #define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
    #define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
    #define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA
    #define GL_TEXTURE_BUFFER_OFFSET 0x919D
    #define GL_TEXTURE_BUFFER_SIZE 0x919E
    #define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
    #define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
    #define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
    #define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
    #define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
    #define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
    #define GL_VERTEX_ATTRIB_BINDING 0x82D4
    #define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
    #define GL_VERTEX_BINDING_DIVISOR 0x82D6
    #define GL_VERTEX_BINDING_OFFSET 0x82D7
    #define GL_VERTEX_BINDING_STRIDE 0x82D8
    #define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
    #define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
    #define GL_VERTEX_BINDING_BUFFER 0x8F4F
    #define GL_STACK_UNDERFLOW 0x0504
    #define GL_STACK_OVERFLOW 0x0503

    // OpenGL 4.4

    #define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
    #define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
    #define GL_TEXTURE_BUFFER_BINDING 0x8C2A
    #define GL_MAP_READ_BIT 0x0001
    #define GL_MAP_WRITE_BIT 0x0002
    #define GL_MAP_PERSISTENT_BIT 0x0040
    #define GL_MAP_COHERENT_BIT 0x0080
    #define GL_DYNAMIC_STORAGE_BIT 0x0100
    #define GL_CLIENT_STORAGE_BIT 0x0200
    #define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
    #define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
    #define GL_BUFFER_STORAGE_FLAGS 0x8220
    #define GL_CLEAR_TEXTURE 0x9365
    #define GL_LOCATION_COMPONENT 0x934A
    #define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
    #define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
    #define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
    #define GL_QUERY_BUFFER 0x9192
    #define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
    #define GL_QUERY_BUFFER_BINDING 0x9193
    #define GL_QUERY_RESULT_NO_WAIT 0x9194
    #define GL_MIRROR_CLAMP_TO_EDGE 0x8743
    #define GL_STENCIL_INDEX 0x1901
    #define GL_STENCIL_INDEX8 0x8D48
    #define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B

    // OpenGL 4.5

    #define GL_CONTEXT_LOST 0x0507
    #define GL_LOWER_LEFT 0x8CA1
    #define GL_UPPER_LEFT 0x8CA2
    #define GL_NEGATIVE_ONE_TO_ONE 0x935E
    #define GL_ZERO_TO_ONE 0x935F
    #define GL_CLIP_ORIGIN 0x935C
    #define GL_CLIP_DEPTH_MODE 0x935D
    #define GL_QUERY_WAIT_INVERTED 0x8E17
    #define GL_QUERY_NO_WAIT_INVERTED 0x8E18
    #define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19
    #define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
    #define GL_MAX_CULL_DISTANCES 0x82F9
    #define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
    #define GL_TEXTURE_TARGET 0x1006
    #define GL_QUERY_TARGET 0x82EA
    #define GL_TEXTURE_BINDING_1D 0x8068
    #define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
    #define GL_TEXTURE_BINDING_2D 0x8069
    #define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
    #define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
    #define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
    #define GL_TEXTURE_BINDING_3D 0x806A
    #define GL_TEXTURE_BINDING_BUFFER 0x8C2C
    #define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
    #define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
    #define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
    #define GL_BACK 0x0405
    #define GL_NO_ERROR 0
    #define GL_GUILTY_CONTEXT_RESET 0x8253
    #define GL_INNOCENT_CONTEXT_RESET 0x8254
    #define GL_UNKNOWN_CONTEXT_RESET 0x8255
    #define GL_RESET_NOTIFICATION_STRATEGY 0x8256
    #define GL_LOSE_CONTEXT_ON_RESET 0x8252
    #define GL_NO_RESET_NOTIFICATION 0x8261
    #define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
    #define GL_CONTEXT_LOST 0x0507
    #define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
    #define GL_NONE 0
    #define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC

    // ------------------------------------------------------------------------
    // OpenGL functions
    // ------------------------------------------------------------------------

    // OpenGL 1.0

    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glAccum(GLenum op, GLfloat value);
    extern "C" void GL_API glAlphaFunc(GLenum func, GLfloat ref);
    extern "C" void GL_API glBegin(GLenum mode);
    extern "C" void GL_API glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig,
                                      GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
    #endif
    extern "C" void GL_API glBlendFunc(GLenum sfactor, GLenum dfactor);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glCallList(GLuint list);
    extern "C" void GL_API glCallLists(GLsizei n, GLenum type, const void *lists);
    #endif
    extern "C" void GL_API glClear(GLbitfield mask);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    #endif
    extern "C" void GL_API glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    extern "C" void GL_API glClearDepth(GLdouble depth);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glClearIndex(GLfloat c);
    #endif
    extern "C" void GL_API glClearStencil(GLint s);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glClipPlane(GLenum plane, const GLdouble *equation);
    extern "C" void GL_API glColor3b(GLbyte red, GLbyte green, GLbyte blue);
    extern "C" void GL_API glColor3bv(const GLbyte *v);
    extern "C" void GL_API glColor3d(GLdouble red, GLdouble green, GLdouble blue);
    extern "C" void GL_API glColor3dv(const GLdouble *v);
    extern "C" void GL_API glColor3f(GLfloat red, GLfloat green, GLfloat blue);
    extern "C" void GL_API glColor3fv(const GLfloat *v);
    extern "C" void GL_API glColor3i(GLint red, GLint green, GLint blue);
    extern "C" void GL_API glColor3iv(const GLint *v);
    extern "C" void GL_API glColor3s(GLshort red, GLshort green, GLshort blue);
    extern "C" void GL_API glColor3sv(const GLshort *v);
    extern "C" void GL_API glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
    extern "C" void GL_API glColor3ubv(const GLubyte *v);
    extern "C" void GL_API glColor3ui(GLuint red, GLuint green, GLuint blue);
    extern "C" void GL_API glColor3uiv(const GLuint *v);
    extern "C" void GL_API glColor3us(GLushort red, GLushort green, GLushort blue);
    extern "C" void GL_API glColor3usv(const GLushort *v);
    extern "C" void GL_API glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
    extern "C" void GL_API glColor4bv(const GLbyte *v);
    extern "C" void GL_API glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
    extern "C" void GL_API glColor4dv(const GLdouble *v);
    extern "C" void GL_API glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    extern "C" void GL_API glColor4fv(const GLfloat *v);
    extern "C" void GL_API glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
    extern "C" void GL_API glColor4iv(const GLint *v);
    extern "C" void GL_API glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
    extern "C" void GL_API glColor4sv(const GLshort *v);
    extern "C" void GL_API glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
    extern "C" void GL_API glColor4ubv(const GLubyte *v);
    extern "C" void GL_API glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
    extern "C" void GL_API glColor4uiv(const GLuint *v);
    extern "C" void GL_API glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
    extern "C" void GL_API glColor4usv(const GLushort *v);
    #endif
    extern "C" void GL_API glColorMask(GLboolean red, GLboolean green, GLboolean blue,
                                       GLboolean alpha);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glColorMaterial(GLenum face, GLenum mode);
    extern "C" void GL_API glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
    #endif
    extern "C" void GL_API glCullFace(GLenum mode);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glDeleteLists(GLuint list, GLsizei range);
    #endif
    extern "C" void GL_API glDepthFunc(GLenum func);
    extern "C" void GL_API glDepthMask(GLboolean flag);
    extern "C" void GL_API glDepthRange(GLdouble near, GLdouble far);
    extern "C" void GL_API glDisable(GLenum cap);
    extern "C" void GL_API glDrawBuffer(GLenum buf);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type,
                                        const void *pixels);
    extern "C" void GL_API glEdgeFlag(GLboolean flag);
    extern "C" void GL_API glEdgeFlagv(const GLboolean *flag);
    #endif
    extern "C" void GL_API glEnable(GLenum cap);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glEnd(void);
    extern "C" void GL_API glEndList(void);
    extern "C" void GL_API glEvalCoord1d(GLdouble u);
    extern "C" void GL_API glEvalCoord1dv(const GLdouble *u);
    extern "C" void GL_API glEvalCoord1f(GLfloat u);
    extern "C" void GL_API glEvalCoord1fv(const GLfloat *u);
    extern "C" void GL_API glEvalCoord2d(GLdouble u, GLdouble v);
    extern "C" void GL_API glEvalCoord2dv(const GLdouble *u);
    extern "C" void GL_API glEvalCoord2f(GLfloat u, GLfloat v);
    extern "C" void GL_API glEvalCoord2fv(const GLfloat *u);
    extern "C" void GL_API glEvalMesh1(GLenum mode, GLint i1, GLint i2);
    extern "C" void GL_API glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
    extern "C" void GL_API glEvalPoint1(GLint i);
    extern "C" void GL_API glEvalPoint2(GLint i, GLint j);
    extern "C" void GL_API glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer);
    #endif
    extern "C" void GL_API glFinish();
    extern "C" void GL_API glFlush();
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glFogf(GLenum pname, GLfloat param);
    extern "C" void GL_API glFogfv(GLenum pname, const GLfloat *params);
    extern "C" void GL_API glFogi(GLenum pname, GLint param);
    extern "C" void GL_API glFogiv(GLenum pname, const GLint *params);
    #endif
    extern "C" void GL_API glFrontFace(GLenum mode);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top,
                                     GLdouble zNear, GLdouble zFar);
    extern "C" GLuint GL_API glGenLists(GLsizei range);
    #endif
    extern "C" void GL_API glGetBooleanv(GLenum pname, GLboolean *data);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glGetClipPlane(GLenum plane, GLdouble *equation);
    #endif
    extern "C" void GL_API glGetDoublev(GLenum pname, GLdouble *data);
    extern "C" GLenum GL_API glGetError();
    extern "C" void GL_API glGetFloatv(GLenum pname, GLfloat *data);
    extern "C" void GL_API glGetIntegerv(GLenum pname, GLint *data);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glGetLightfv(GLenum light, GLenum pname, GLfloat *params);
    extern "C" void GL_API glGetLightiv(GLenum light, GLenum pname, GLint *params);
    extern "C" void GL_API glGetMapdv(GLenum target, GLenum query, GLdouble *v);
    extern "C" void GL_API glGetMapfv(GLenum target, GLenum query, GLfloat *v);
    extern "C" void GL_API glGetMapiv(GLenum target, GLenum query, GLint *v);
    extern "C" void GL_API glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params);
    extern "C" void GL_API glGetMaterialiv(GLenum face, GLenum pname, GLint *params);
    extern "C" void GL_API glGetPixelMapfv(GLenum map, GLfloat *values);
    extern "C" void GL_API glGetPixelMapuiv(GLenum map, GLuint *values);
    extern "C" void GL_API glGetPixelMapusv(GLenum map, GLushort *values);
    extern "C" void GL_API glGetPolygonStipple(GLubyte *mask);
    #endif
    extern "C" const GLubyte * GL_API glGetString(GLenum name);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params);
    extern "C" void GL_API glGetTexEnviv(GLenum target, GLenum pname, GLint *params);
    extern "C" void GL_API glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params);
    extern "C" void GL_API glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
    extern "C" void GL_API glGetTexGeniv(GLenum coord, GLenum pname, GLint *params);
    #endif
    extern "C" void GL_API glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type,
                                         void *pixels);
    extern "C" void GL_API glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname,
                                                    GLfloat *params);
    extern "C" void GL_API glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname,
                                                    GLint *params);
    extern "C" void GL_API glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
    extern "C" void GL_API glGetTexParameteriv(GLenum target, GLenum pname, GLint *params);
    extern "C" void GL_API glHint(GLenum target, GLenum mode);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glIndexMask(GLuint mask);
    extern "C" void GL_API glIndexd(GLdouble c);
    extern "C" void GL_API glIndexdv(const GLdouble *c);
    extern "C" void GL_API glIndexf(GLfloat c);
    extern "C" void GL_API glIndexfv(const GLfloat *c);
    extern "C" void GL_API glIndexi(GLint c);
    extern "C" void GL_API glIndexiv(const GLint *c);
    extern "C" void GL_API glIndexs(GLshort c);
    extern "C" void GL_API glIndexsv(const GLshort *c);
    extern "C" void GL_API glInitNames(void);
    #endif
    extern "C" GLboolean GL_API glIsEnabled(GLenum cap);
    #if !defined(OGL_NO_COMPAT)
    extern "C" GLboolean GL_API glIsList(GLuint list);
    extern "C" void GL_API glLightModelf(GLenum pname, GLfloat param);
    extern "C" void GL_API glLightModelfv(GLenum pname, const GLfloat *params);
    extern "C" void GL_API glLightModeli(GLenum pname, GLint param);
    extern "C" void GL_API glLightModeliv(GLenum pname, const GLint *params);
    extern "C" void GL_API glLightf(GLenum light, GLenum pname, GLfloat param);
    extern "C" void GL_API glLightfv(GLenum light, GLenum pname, const GLfloat *params);
    extern "C" void GL_API glLighti(GLenum light, GLenum pname, GLint param);
    extern "C" void GL_API glLightiv(GLenum light, GLenum pname, const GLint *params);
    extern "C" void GL_API glLineStipple(GLint factor, GLushort pattern);
    #endif
    extern "C" void GL_API glLineWidth(GLfloat width);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glListBase(GLuint base);
    extern "C" void GL_API glLoadIdentity(void);
    extern "C" void GL_API glLoadMatrixd(const GLdouble *m);
    extern "C" void GL_API glLoadMatrixf(const GLfloat *m);
    extern "C" void GL_API glLoadName(GLuint name);
    #endif
    extern "C" void GL_API glLogicOp(GLenum opcode);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order,
                                   const GLdouble *points);
    extern "C" void GL_API glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order,
                                   const GLfloat *points);
    extern "C" void GL_API glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride,
                                   GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder,
                                   const GLdouble *points);
    extern "C" void GL_API glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder,
                                   GLfloat v1, GLfloat v2, GLint vstride, GLint vorder,
                                   const GLfloat *points);
    extern "C" void GL_API glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
    extern "C" void GL_API glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
    extern "C" void GL_API glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1,
                                       GLdouble v2);
    extern "C" void GL_API glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1,
                                       GLfloat v2);
    extern "C" void GL_API glMaterialf(GLenum face, GLenum pname, GLfloat param);
    extern "C" void GL_API glMaterialfv(GLenum face, GLenum pname, const GLfloat *params);
    extern "C" void GL_API glMateriali(GLenum face, GLenum pname, GLint param);
    extern "C" void GL_API glMaterialiv(GLenum face, GLenum pname, const GLint *params);
    extern "C" void GL_API glMatrixMode(GLenum mode);
    extern "C" void GL_API glMultMatrixd(const GLdouble *m);
    extern "C" void GL_API glMultMatrixf(const GLfloat *m);
    extern "C" void GL_API glNewList(GLuint list, GLenum mode);
    extern "C" void GL_API glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
    extern "C" void GL_API glNormal3bv(const GLbyte *v);
    extern "C" void GL_API glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
    extern "C" void GL_API glNormal3dv(const GLdouble *v);
    extern "C" void GL_API glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
    extern "C" void GL_API glNormal3fv(const GLfloat *v);
    extern "C" void GL_API glNormal3i(GLint nx, GLint ny, GLint nz);
    extern "C" void GL_API glNormal3iv(const GLint *v);
    extern "C" void GL_API glNormal3s(GLshort nx, GLshort ny, GLshort nz);
    extern "C" void GL_API glNormal3sv(const GLshort *v);
    extern "C" void GL_API glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top,
                                   GLdouble zNear, GLdouble zFar);
    extern "C" void GL_API glPassThrough(GLfloat token);
    extern "C" void GL_API glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values);
    extern "C" void GL_API glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values);
    extern "C" void GL_API glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values);
    #endif
    extern "C" void GL_API glPixelStoref(GLenum pname, GLfloat param);
    extern "C" void GL_API glPixelStorei(GLenum pname, GLint param);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glPixelTransferf(GLenum pname, GLfloat param);
    extern "C" void GL_API glPixelTransferi(GLenum pname, GLint param);
    extern "C" void GL_API glPixelZoom(GLfloat xfactor, GLfloat yfactor);
    #endif
    extern "C" void GL_API glPointSize(GLfloat size);
    extern "C" void GL_API glPolygonMode(GLenum face, GLenum mode);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glPolygonStipple(const GLubyte *mask);
    extern "C" void GL_API glPopAttrib(void);
    extern "C" void GL_API glPopMatrix(void);
    extern "C" void GL_API glPopName(void);
    extern "C" void GL_API glPushAttrib(GLbitfield mask);
    extern "C" void GL_API glPushMatrix(void);
    extern "C" void GL_API glPushName(GLuint name);
    extern "C" void GL_API glRasterPos2d(GLdouble x, GLdouble y);
    extern "C" void GL_API glRasterPos2dv(const GLdouble *v);
    extern "C" void GL_API glRasterPos2f(GLfloat x, GLfloat y);
    extern "C" void GL_API glRasterPos2fv(const GLfloat *v);
    extern "C" void GL_API glRasterPos2i(GLint x, GLint y);
    extern "C" void GL_API glRasterPos2iv(const GLint *v);
    extern "C" void GL_API glRasterPos2s(GLshort x, GLshort y);
    extern "C" void GL_API glRasterPos2sv(const GLshort *v);
    extern "C" void GL_API glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
    extern "C" void GL_API glRasterPos3dv(const GLdouble *v);
    extern "C" void GL_API glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
    extern "C" void GL_API glRasterPos3fv(const GLfloat *v);
    extern "C" void GL_API glRasterPos3i(GLint x, GLint y, GLint z);
    extern "C" void GL_API glRasterPos3iv(const GLint *v);
    extern "C" void GL_API glRasterPos3s(GLshort x, GLshort y, GLshort z);
    extern "C" void GL_API glRasterPos3sv(const GLshort *v);
    extern "C" void GL_API glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    extern "C" void GL_API glRasterPos4dv(const GLdouble *v);
    extern "C" void GL_API glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    extern "C" void GL_API glRasterPos4fv(const GLfloat *v);
    extern "C" void GL_API glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
    extern "C" void GL_API glRasterPos4iv(const GLint *v);
    extern "C" void GL_API glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
    extern "C" void GL_API glRasterPos4sv(const GLshort *v);
    #endif
    extern "C" void GL_API glReadBuffer(GLenum src);
    extern "C" void GL_API glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format,
                                        GLenum type, void *pixels);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
    extern "C" void GL_API glRectdv(const GLdouble *v1, const GLdouble *v2);
    extern "C" void GL_API glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
    extern "C" void GL_API glRectfv(const GLfloat *v1, const GLfloat *v2);
    extern "C" void GL_API glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
    extern "C" void GL_API glRectiv(const GLint *v1, const GLint *v2);
    extern "C" void GL_API glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
    extern "C" void GL_API glRectsv(const GLshort *v1, const GLshort *v2);
    extern "C" GLint GL_API glRenderMode(GLenum mode);
    extern "C" void GL_API glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
    extern "C" void GL_API glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
    extern "C" void GL_API glScaled(GLdouble x, GLdouble y, GLdouble z);
    extern "C" void GL_API glScalef(GLfloat x, GLfloat y, GLfloat z);
    #endif
    extern "C" void GL_API glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glSelectBuffer(GLsizei size, GLuint *buffer);
    extern "C" void GL_API glShadeModel(GLenum mode);
    #endif
    extern "C" void GL_API glStencilFunc(GLenum func, GLint ref, GLuint mask);
    extern "C" void GL_API glStencilMask(GLuint mask);
    extern "C" void GL_API glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glTexCoord1d(GLdouble s);
    extern "C" void GL_API glTexCoord1dv(const GLdouble *v);
    extern "C" void GL_API glTexCoord1f(GLfloat s);
    extern "C" void GL_API glTexCoord1fv(const GLfloat *v);
    extern "C" void GL_API glTexCoord1i(GLint s);
    extern "C" void GL_API glTexCoord1iv(const GLint *v);
    extern "C" void GL_API glTexCoord1s(GLshort s);
    extern "C" void GL_API glTexCoord1sv(const GLshort *v);
    extern "C" void GL_API glTexCoord2d(GLdouble s, GLdouble t);
    extern "C" void GL_API glTexCoord2dv(const GLdouble *v);
    extern "C" void GL_API glTexCoord2f(GLfloat s, GLfloat t);
    extern "C" void GL_API glTexCoord2fv(const GLfloat *v);
    extern "C" void GL_API glTexCoord2i(GLint s, GLint t);
    extern "C" void GL_API glTexCoord2iv(const GLint *v);
    extern "C" void GL_API glTexCoord2s(GLshort s, GLshort t);
    extern "C" void GL_API glTexCoord2sv(const GLshort *v);
    extern "C" void GL_API glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
    extern "C" void GL_API glTexCoord3dv(const GLdouble *v);
    extern "C" void GL_API glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
    extern "C" void GL_API glTexCoord3fv(const GLfloat *v);
    extern "C" void GL_API glTexCoord3i(GLint s, GLint t, GLint r);
    extern "C" void GL_API glTexCoord3iv(const GLint *v);
    extern "C" void GL_API glTexCoord3s(GLshort s, GLshort t, GLshort r);
    extern "C" void GL_API glTexCoord3sv(const GLshort *v);
    extern "C" void GL_API glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
    extern "C" void GL_API glTexCoord4dv(const GLdouble *v);
    extern "C" void GL_API glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
    extern "C" void GL_API glTexCoord4fv(const GLfloat *v);
    extern "C" void GL_API glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
    extern "C" void GL_API glTexCoord4iv(const GLint *v);
    extern "C" void GL_API glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
    extern "C" void GL_API glTexCoord4sv(const GLshort *v);
    extern "C" void GL_API glTexEnvf(GLenum target, GLenum pname, GLfloat param);
    extern "C" void GL_API glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params);
    extern "C" void GL_API glTexEnvi(GLenum target, GLenum pname, GLint param);
    extern "C" void GL_API glTexEnviv(GLenum target, GLenum pname, const GLint *params);
    extern "C" void GL_API glTexGend(GLenum coord, GLenum pname, GLdouble param);
    extern "C" void GL_API glTexGendv(GLenum coord, GLenum pname, const GLdouble *params);
    extern "C" void GL_API glTexGenf(GLenum coord, GLenum pname, GLfloat param);
    extern "C" void GL_API glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
    extern "C" void GL_API glTexGeni(GLenum coord, GLenum pname, GLint param);
    extern "C" void GL_API glTexGeniv(GLenum coord, GLenum pname, const GLint *params);
    #endif
    extern "C" void GL_API glTexImage1D(GLenum target, GLint level, GLint internalformat,
                                        GLsizei width, GLint border, GLenum format, GLenum type,
                                        const void *pixels);
    extern "C" void GL_API glTexImage2D(GLenum target, GLint level, GLint internalformat,
                                        GLsizei width, GLsizei height, GLint border, GLenum format,
                                        GLenum type, const void *pixels);
    extern "C" void GL_API glTexParameterf(GLenum target, GLenum pname, GLfloat param);
    extern "C" void GL_API glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params);
    extern "C" void GL_API glTexParameteri(GLenum target, GLenum pname, GLint param);
    extern "C" void GL_API glTexParameteriv(GLenum target, GLenum pname, const GLint *params);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glTranslated(GLdouble x, GLdouble y, GLdouble z);
    extern "C" void GL_API glTranslatef(GLfloat x, GLfloat y, GLfloat z);
    extern "C" void GL_API glVertex2d(GLdouble x, GLdouble y);
    extern "C" void GL_API glVertex2dv(const GLdouble *v);
    extern "C" void GL_API glVertex2f(GLfloat x, GLfloat y);
    extern "C" void GL_API glVertex2fv(const GLfloat *v);
    extern "C" void GL_API glVertex2i(GLint x, GLint y);
    extern "C" void GL_API glVertex2iv(const GLint *v);
    extern "C" void GL_API glVertex2s(GLshort x, GLshort y);
    extern "C" void GL_API glVertex2sv(const GLshort *v);
    extern "C" void GL_API glVertex3d(GLdouble x, GLdouble y, GLdouble z);
    extern "C" void GL_API glVertex3dv(const GLdouble *v);
    extern "C" void GL_API glVertex3f(GLfloat x, GLfloat y, GLfloat z);
    extern "C" void GL_API glVertex3fv(const GLfloat *v);
    extern "C" void GL_API glVertex3i(GLint x, GLint y, GLint z);
    extern "C" void GL_API glVertex3iv(const GLint *v);
    extern "C" void GL_API glVertex3s(GLshort x, GLshort y, GLshort z);
    extern "C" void GL_API glVertex3sv(const GLshort *v);
    extern "C" void GL_API glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    extern "C" void GL_API glVertex4dv(const GLdouble *v);
    extern "C" void GL_API glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    extern "C" void GL_API glVertex4fv(const GLfloat *v);
    extern "C" void GL_API glVertex4i(GLint x, GLint y, GLint z, GLint w);
    extern "C" void GL_API glVertex4iv(const GLint *v);
    extern "C" void GL_API glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
    extern "C" void GL_API glVertex4sv(const GLshort *v);
    #endif
    extern "C" void GL_API glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

    // OpenGL 1.1

    #if !defined(OGL_NO_COMPAT)
    extern "C" GLboolean GL_API glAreTexturesResident(GLsizei n, const GLuint *textures,
                                                      GLboolean *residences);
    extern "C" void GL_API glArrayElement(GLint i);
    #endif
    extern "C" void GL_API glBindTexture(GLenum target, GLuint texture);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glColorPointer(GLint size, GLenum type, GLsizei stride,
                                          const void *pointer);
    #endif
    extern "C" void GL_API glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat,
                                            GLint x, GLint y, GLsizei width, GLint border);
    extern "C" void GL_API glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat,
                                            GLint x, GLint y, GLsizei width, GLsizei height,
                                            GLint border);
    extern "C" void GL_API glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset,
                                               GLint x, GLint y, GLsizei width);
    extern "C" void GL_API glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset,
                                               GLint yoffset, GLint x, GLint y, GLsizei width,
                                               GLsizei height);
    extern "C" void GL_API glDeleteTextures(GLsizei n, const GLuint *textures);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glDisableClientState(GLenum array);
    #endif
    extern "C" void GL_API glDrawArrays(GLenum mode, GLint first, GLsizei count);
    extern "C" void GL_API glDrawElements(GLenum mode, GLsizei count, GLenum type,
                                          const void *indices);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glEdgeFlagPointer(GLsizei stride, const void *pointer);
    extern "C" void GL_API glEnableClientState(GLenum array);
    #endif
    extern "C" void GL_API glGenTextures(GLsizei n, GLuint *textures);
    extern "C" void GL_API glGetPointerv(GLenum pname, void **params); // Undeprecated in 4.3
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glIndexPointer(GLenum type, GLsizei stride, const void *pointer);
    extern "C" void GL_API glIndexub(GLubyte c);
    extern "C" void GL_API glIndexubv(const GLubyte *c);
    extern "C" void GL_API glInterleavedArrays(GLenum format, GLsizei stride, const void *pointer);
    #endif
    extern "C" GLboolean GL_API glIsTexture(GLuint texture);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glNormalPointer(GLenum type, GLsizei stride, const void *pointer);
    #endif
    extern "C" void GL_API glPolygonOffset(GLfloat factor, GLfloat units);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glPopClientAttrib(void);
    extern "C" void GL_API glPrioritizeTextures(GLsizei n, const GLuint *textures,
                                                const GLfloat *priorities);
    extern "C" void GL_API glPushClientAttrib(GLbitfield mask);
    extern "C" void GL_API glTexCoordPointer(GLint size, GLenum type, GLsizei stride,
                                             const void *pointer);
    #endif
    extern "C" void GL_API glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width,
                                           GLenum format, GLenum type, const void *pixels);
    extern "C" void GL_API glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                           GLsizei width, GLsizei height, GLenum format, GLenum type,
                                           const void *pixels);
    #if !defined(OGL_NO_COMPAT)
    extern "C" void GL_API glVertexPointer(GLint size, GLenum type, GLsizei stride,
                                           const void *pointer);
    #endif
#endif

// ------------------------------------------------------------------------
// Custom helpers
// ------------------------------------------------------------------------

namespace RG {

// Generic
bool ogl_InitFunctions(void *(*get_proc_address)(const char *name));
GLuint ogl_BuildShader(const char *name, const char *vertex_src, const char *fragment_src);

}

// ------------------------------------------------------------------------
// Function pointers
// ------------------------------------------------------------------------

#define OGL_FUNCTION(Cond, ...) \
    extern RG_FORCE_EXPAND(OGL_FUNCTION_PTR(__VA_ARGS__))
#include "opengl_func.inc"
