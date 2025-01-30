[{"ops":[{"insert":"/* Handle feature test macros at the start of a header.\n   Copyright (C) 2016-2022 Free Software Foundation, Inc.\n   This file is part of the GNU C Library.\n\n   The GNU C Library is free software; you can redistribute it and/or\n   modify it under the terms of the GNU Lesser General Public\n   License as published by the Free Software Foundation; either\n   version 2.1 of the License, or (at your option) any later version.\n\n   The GNU C Library is distributed in the hope that it will be useful,\n   but WITHOUT ANY WARRANTY; without even the implied warranty of\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n   Lesser General Public License for more details.\n\n   You should have received a copy of the GNU Lesser General Public\n   License along with the GNU C Library; if not, see\n   <https://www.gnu.org/licenses/>.  */\n\n/* This header is internal to glibc and should not be included outside\n   of glibc headers.  Headers including it must define\n   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header\n   cannot have multiple include guards because ISO C feature test\n   macros depend on the definition of the macro when an affected\n   header is included, not when the first system header is\n   included.  */\n\n#ifndef __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION\n# error \"Never include <bits/libc-header-start.h> directly.\"\n#endif\n\n#undef __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION\n\n#include <features.h>\n\n/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__\n   macro.  */\n#undef __GLIBC_USE_LIB_EXT2\n#if (defined __USE_GNU\t\t\t\t\t\t\t\\\n     || (defined __STDC_WANT_LIB_EXT2__ && __STDC_WANT_LIB_EXT2__ > 0))\n# define __GLIBC_USE_LIB_EXT2 1\n#else\n# define __GLIBC_USE_LIB_EXT2 0\n#endif\n\n/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__\n   macro.  Most but not all symbols enabled by that macro in TS\n   18661-1 are enabled unconditionally in C2X.  In C2X, the symbols in\n   Annex F still require a new feature test macro\n   __STDC_WANT_IEC_60559_EXT__ instead (C2X does not define\n   __STDC_WANT_IEC_60559_BFP_EXT__), while a few features from TS\n   18661-1 are not included in C2X (and thus should depend on\n   __STDC_WANT_IEC_60559_BFP_EXT__ even when C2X features are\n   enabled).\n\n   __GLIBC_USE (IEC_60559_BFP_EXT) controls those features from TS\n   18661-1 not included in C2X.\n\n   __GLIBC_USE (IEC_60559_BFP_EXT_C2X) controls those features from TS\n   18661-1 that are also included in C2X (with no feature test macro\n   required in C2X).\n\n   __GLIBC_USE (IEC_60559_EXT) controls those features from TS 18661-1\n   that are included in C2X but conditional on\n   __STDC_WANT_IEC_60559_EXT__.  (There are currently no features\n   conditional on __STDC_WANT_IEC_60559_EXT__ that are not in TS\n   18661-1.)  */\n#undef __GLIBC_USE_IEC_60559_BFP_EXT\n#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_BFP_EXT__\n# define __GLIBC_USE_IEC_60559_BFP_EXT 1\n#else\n# define __GLIBC_USE_IEC_60559_BFP_EXT 0\n#endif\n#undef __GLIBC_USE_IEC_60559_BFP_EXT_C2X\n#if __GLIBC_USE (IEC_60559_BFP_EXT) || __GLIBC_USE (ISOC2X)\n# define __GLIBC_USE_IEC_60559_BFP_EXT_C2X 1\n#else\n# define __GLIBC_USE_IEC_60559_BFP_EXT_C2X 0\n#endif\n#undef __GLIBC_USE_IEC_60559_EXT\n#if __GLIBC_USE (IEC_60559_BFP_EXT) || defined __STDC_WANT_IEC_60559_EXT__\n# define __GLIBC_USE_IEC_60559_EXT 1\n#else\n# define __GLIBC_USE_IEC_60559_EXT 0\n#endif\n\n/* ISO/IEC TS 18661-4:2015 defines the\n   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  Other than the reduction\n   functions, the symbols from this TS are enabled unconditionally in\n   C2X.  */\n#undef __GLIBC_USE_IEC_60559_FUNCS_EXT\n#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_FUNCS_EXT__\n# define __GLIBC_USE_IEC_60559_FUNCS_EXT 1\n#else\n# define __GLIBC_USE_IEC_60559_FUNCS_EXT 0\n#endif\n#undef __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X\n#if __GLIBC_USE (IEC_60559_FUNCS_EXT) || __GLIBC_USE (ISOC2X)\n# define __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X 1\n#else\n# define __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X 0\n#endif\n\n/* ISO/IEC TS 18661-3:2015 defines the\n   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */\n#undef __GLIBC_USE_IEC_60559_TYPES_EXT\n#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_TYPES_EXT__\n# define __GLIBC_USE_IEC_60559_TYPES_EXT 1\n#else\n# define __GLIBC_USE_IEC_60559_TYPES_EXT 0\n#endif\n"}],"crc32":4268201685,"timestamp":1704214356,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]