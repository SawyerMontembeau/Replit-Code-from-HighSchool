[{"ops":[{"insert":"/*===---- __stddef_max_align_t.h - Definition of max_align_t for modules ---===\n *\n * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.\n * See https://llvm.org/LICENSE.txt for license information.\n * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception\n *\n *===-----------------------------------------------------------------------===\n */\n\n#ifndef __CLANG_MAX_ALIGN_T_DEFINED\n#define __CLANG_MAX_ALIGN_T_DEFINED\n\n#if defined(_MSC_VER)\ntypedef double max_align_t;\n#elif defined(__APPLE__)\ntypedef long double max_align_t;\n#else\n// Define 'max_align_t' to match the GCC definition.\ntypedef struct {\n  long long __clang_max_align_nonce1\n      __attribute__((__aligned__(__alignof__(long long))));\n  long double __clang_max_align_nonce2\n      __attribute__((__aligned__(__alignof__(long double))));\n} max_align_t;\n#endif\n\n#endif\n"}],"crc32":1163796406,"timestamp":1704214356,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]