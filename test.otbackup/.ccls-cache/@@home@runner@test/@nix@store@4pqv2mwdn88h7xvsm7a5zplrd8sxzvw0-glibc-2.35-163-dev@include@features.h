[{"ops":[{"insert":"/* Copyright (C) 1991-2022 Free Software Foundation, Inc.\n   This file is part of the GNU C Library.\n\n   The GNU C Library is free software; you can redistribute it and/or\n   modify it under the terms of the GNU Lesser General Public\n   License as published by the Free Software Foundation; either\n   version 2.1 of the License, or (at your option) any later version.\n\n   The GNU C Library is distributed in the hope that it will be useful,\n   but WITHOUT ANY WARRANTY; without even the implied warranty of\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n   Lesser General Public License for more details.\n\n   You should have received a copy of the GNU Lesser General Public\n   License along with the GNU C Library; if not, see\n   <https://www.gnu.org/licenses/>.  */\n\n#ifndef\t_FEATURES_H\n#define\t_FEATURES_H\t1\n\n/* These are defined by the user (or the compiler)\n   to specify the desired environment:\n\n   __STRICT_ANSI__\tISO Standard C.\n   _ISOC99_SOURCE\tExtensions to ISO C89 from ISO C99.\n   _ISOC11_SOURCE\tExtensions to ISO C99 from ISO C11.\n   _ISOC2X_SOURCE\tExtensions to ISO C99 from ISO C2X.\n   __STDC_WANT_LIB_EXT2__\n\t\t\tExtensions to ISO C99 from TR 27431-2:2010.\n   __STDC_WANT_IEC_60559_BFP_EXT__\n\t\t\tExtensions to ISO C11 from TS 18661-1:2014.\n   __STDC_WANT_IEC_60559_FUNCS_EXT__\n\t\t\tExtensions to ISO C11 from TS 18661-4:2015.\n   __STDC_WANT_IEC_60559_TYPES_EXT__\n\t\t\tExtensions to ISO C11 from TS 18661-3:2015.\n   __STDC_WANT_IEC_60559_EXT__\n\t\t\tISO C2X interfaces defined only in Annex F.\n\n   _POSIX_SOURCE\tIEEE Std 1003.1.\n   _POSIX_C_SOURCE\tIf ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;\n\t\t\tif >=199309L, add IEEE Std 1003.1b-1993;\n\t\t\tif >=199506L, add IEEE Std 1003.1c-1995;\n\t\t\tif >=200112L, all of IEEE 1003.1-2004\n\t\t\tif >=200809L, all of IEEE 1003.1-2008\n   _XOPEN_SOURCE\tIncludes POSIX and XPG things.  Set to 500 if\n\t\t\tSingle Unix conformance is wanted, to 600 for the\n\t\t\tsixth revision, to 700 for the seventh revision.\n   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.\n   _LARGEFILE_SOURCE\tSome more functions for correct standard I/O.\n   _LARGEFILE64_SOURCE\tAdditional functionality from LFS for large files.\n   _FILE_OFFSET_BITS=N\tSelect default filesystem interface.\n   _ATFILE_SOURCE\tAdditional *at interfaces.\n   _DYNAMIC_STACK_SIZE_SOURCE Select correct (but non compile-time constant)\n\t\t\tMINSIGSTKSZ, SIGSTKSZ and PTHREAD_STACK_MIN.\n   _GNU_SOURCE\t\tAll of the above, plus GNU extensions.\n   _DEFAULT_SOURCE\tThe default set of features (taking precedence over\n\t\t\t__STRICT_ANSI__).\n\n   _FORTIFY_SOURCE\tAdd security hardening to many library functions.\n\t\t\tSet to 1 or 2; 2 performs stricter checks than 1.\n\n   _REENTRANT, _THREAD_SAFE\n\t\t\tObsolete; equivalent to _POSIX_C_SOURCE=199506L.\n\n   The `-ansi' switch to the GNU C compiler, and standards conformance\n   options such as `-std=c99', define __STRICT_ANSI__.  If none of\n   these are defined, or if _DEFAULT_SOURCE is defined, the default is\n   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to\n   200809L, as well as enabling miscellaneous functions from BSD and\n   SVID.  If more than one of these are defined, they accumulate.  For\n   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together\n   give you ISO C, 1003.1, and 1003.2, but nothing else.\n\n   These are defined by this file and are used by the\n   header files to decide what to declare or define:\n\n   __GLIBC_USE (F)\tDefine things from feature set F.  This is defined\n\t\t\tto 1 or 0; the subsequent macros are either defined\n\t\t\tor undefined, and those tests should be moved to\n\t\t\t__GLIBC_USE.\n   __USE_ISOC11\t\tDefine ISO C11 things.\n   __USE_ISOC99\t\tDefine ISO C99 things.\n   __USE_ISOC95\t\tDefine ISO C90 AMD1 (C95) things.\n   __USE_ISOCXX11\tDefine ISO C++11 things.\n   __USE_POSIX\t\tDefine IEEE Std 1003.1 things.\n   __USE_POSIX2\t\tDefine IEEE Std 1003.2 things.\n   __USE_POSIX199309\tDefine IEEE Std 1003.1, and .1b things.\n   __USE_POSIX199506\tDefine IEEE Std 1003.1, .1b, .1c and .1i things.\n   __USE_XOPEN\t\tDefine XPG things.\n   __USE_XOPEN_EXTENDED\tDefine X/Open Unix things.\n   __USE_UNIX98\t\tDefine Single Unix V2 things.\n   __USE_XOPEN2K        Define XPG6 things.\n   __USE_XOPEN2KXSI     Define XPG6 XSI things.\n   __USE_XOPEN2K8       Define XPG7 things.\n   __USE_XOPEN2K8XSI    Define XPG7 XSI things.\n   __USE_LARGEFILE\tDefine correct standard I/O things.\n   __USE_LARGEFILE64\tDefine LFS things with separate names.\n   __USE_FILE_OFFSET64\tDefine 64bit interface as default.\n   __USE_MISC\t\tDefine things from 4.3BSD or System V Unix.\n   __USE_ATFILE\t\tDefine *at interfaces and AT_* constants for them.\n   __USE_DYNAMIC_STACK_SIZE Define correct (but non compile-time constant)\n\t\t\tMINSIGSTKSZ, SIGSTKSZ and PTHREAD_STACK_MIN.\n   __USE_GNU\t\tDefine GNU extensions.\n   __USE_FORTIFY_LEVEL\tAdditional security measures used, according to level.\n\n   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are\n   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided\n   only for compatibility.  All new code should use the other symbols\n   to test for features.\n\n   All macros listed above as possibly being defined by this file are\n   explicitly undefined if they are not explicitly defined.\n   Feature-test macros that are not defined by the user or compiler\n   but are implied by the other feature-test macros defined (or by the\n   lack of any definitions) are defined by the file.\n\n   ISO C feature test macros depend on the definition of the macro\n   when an affected header is included, not when the first system\n   header is included, and so they are handled in\n   <bits/libc-header-start.h>, which does not have a multiple include\n   guard.  Feature test macros that can be handled from the first\n   system header included are handled here.  */\n\n\n/* Undefine everything, so we get a clean slate.  */\n#undef\t__USE_ISOC11\n#undef\t__USE_ISOC99\n#undef\t__USE_ISOC95\n#undef\t__USE_ISOCXX11\n#undef\t__USE_POSIX\n#undef\t__USE_POSIX2\n#undef\t__USE_POSIX199309\n#undef\t__USE_POSIX199506\n#undef\t__USE_XOPEN\n#undef\t__USE_XOPEN_EXTENDED\n#undef\t__USE_UNIX98\n#undef\t__USE_XOPEN2K\n#undef\t__USE_XOPEN2KXSI\n#undef\t__USE_XOPEN2K8\n#undef\t__USE_XOPEN2K8XSI\n#undef\t__USE_LARGEFILE\n#undef\t__USE_LARGEFILE64\n#undef\t__USE_FILE_OFFSET64\n#undef\t__USE_MISC\n#undef\t__USE_ATFILE\n#undef\t__USE_DYNAMIC_STACK_SIZE\n#undef\t__USE_GNU\n#undef\t__USE_FORTIFY_LEVEL\n#undef\t__KERNEL_STRICT_NAMES\n#undef\t__GLIBC_USE_ISOC2X\n#undef\t__GLIBC_USE_DEPRECATED_GETS\n#undef\t__GLIBC_USE_DEPRECATED_SCANF\n\n/* Suppress kernel-name space pollution unless user expressedly asks\n   for it.  */\n#ifndef _LOOSE_KERNEL_NAMES\n# define __KERNEL_STRICT_NAMES\n#endif\n\n/* Convenience macro to test the version of gcc.\n   Use like this:\n   #if __GNUC_PREREQ (2,8)\n   ... code requiring gcc 2.8 or later ...\n   #endif\n   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was\n   added in 2.0.  */\n#if defined __GNUC__ && defined __GNUC_MINOR__\n# define __GNUC_PREREQ(maj, min) \\\n\t((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))\n#else\n# define __GNUC_PREREQ(maj, min) 0\n#endif\n\n/* Similarly for clang.  Features added to GCC after version 4.2 may\n   or may not also be available in clang, and clang's definitions of\n   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such\n   features can be queried via __has_extension/__has_feature.  */\n#if defined __clang_major__ && defined __clang_minor__\n# define __glibc_clang_prereq(maj, min) \\\n  ((__clang_major__ << 16) + __clang_minor__ >= ((maj) << 16) + (min))\n#else\n# define __glibc_clang_prereq(maj, min) 0\n#endif\n\n/* Whether to use feature set F.  */\n#define __GLIBC_USE(F)\t__GLIBC_USE_ ## F\n\n/* _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for\n   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not\n   issue a warning; the expectation is that the source is being\n   transitioned to use the new macro.  */\n#if (defined _BSD_SOURCE || defined _SVID_SOURCE) \\\n    && !defined _DEFAULT_SOURCE\n# warning \"_BSD_SOURCE and _SVID_SOURCE are deprecated, use _DEFAULT_SOURCE\"\n# undef  _DEFAULT_SOURCE\n# define _DEFAULT_SOURCE\t1\n#endif\n\n/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */\n#ifdef _GNU_SOURCE\n# undef  _ISOC95_SOURCE\n# define _ISOC95_SOURCE\t1\n# undef  _ISOC99_SOURCE\n# define _ISOC99_SOURCE\t1\n# undef  _ISOC11_SOURCE\n# define _ISOC11_SOURCE\t1\n# undef  _ISOC2X_SOURCE\n# define _ISOC2X_SOURCE\t1\n# undef  _POSIX_SOURCE\n# define _POSIX_SOURCE\t1\n# undef  _POSIX_C_SOURCE\n# define _POSIX_C_SOURCE\t200809L\n# undef  _XOPEN_SOURCE\n# define _XOPEN_SOURCE\t700\n# undef  _XOPEN_SOURCE_EXTENDED\n# define _XOPEN_SOURCE_EXTENDED\t1\n# undef\t _LARGEFILE64_SOURCE\n# define _LARGEFILE64_SOURCE\t1\n# undef  _DEFAULT_SOURCE\n# define _DEFAULT_SOURCE\t1\n# undef  _ATFILE_SOURCE\n# define _ATFILE_SOURCE\t1\n# undef  _DYNAMIC_STACK_SIZE_SOURCE\n# define _DYNAMIC_STACK_SIZE_SOURCE 1\n#endif\n\n/* If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,\n   define _DEFAULT_SOURCE.  */\n#if (defined _DEFAULT_SOURCE\t\t\t\t\t\\\n     || (!defined __STRICT_ANSI__\t\t\t\t\\\n\t && !defined _ISOC99_SOURCE && !defined _ISOC11_SOURCE\t\\\n\t && !defined _ISOC2X_SOURCE\t\t\t\t\\\n\t && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE\t\\\n\t && !defined _XOPEN_SOURCE))\n# undef  _DEFAULT_SOURCE\n# define _DEFAULT_SOURCE\t1\n#endif\n\n/* This is to enable the ISO C2X extension.  */\n#if (defined _ISOC2X_SOURCE \\\n     || (defined __STDC_VERSION__ && __STDC_VERSION__ > 201710L))\n# define __GLIBC_USE_ISOC2X\t1\n#else\n# define __GLIBC_USE_ISOC2X\t0\n#endif\n\n/* This is to enable the ISO C11 extension.  */\n#if (defined _ISOC11_SOURCE || defined _ISOC2X_SOURCE \\\n     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L))\n# define __USE_ISOC11\t1\n#endif\n\n/* This is to enable the ISO C99 extension.  */\n#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE\t\t\t\\\n     || defined _ISOC2X_SOURCE\t\t\t\t\t\t\\\n     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))\n# define __USE_ISOC99\t1\n#endif\n\n/* This is to enable the ISO C90 Amendment 1:1995 extension.  */\n#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE\t\t\t\\\n     || defined _ISOC2X_SOURCE\t\t\t\t\t\t\\\n     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199409L))\n# define __USE_ISOC95\t1\n#endif\n\n#ifdef __cplusplus\n/* This is to enable compatibility for ISO C++17.  */\n# if __cplusplus >= 201703L\n#  define __USE_ISOC11\t1\n# endif\n/* This is to enable compatibility for ISO C++11.\n   Check the temporary macro for now, too.  */\n# if __cplusplus >= 201103L || defined __GXX_EXPERIMENTAL_CXX0X__\n#  define __USE_ISOCXX11\t1\n#  define __USE_ISOC99\t1\n# endif\n#endif\n\n/* If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE\n   is defined, use POSIX.1-2008 (or another version depending on\n   _XOPEN_SOURCE).  */\n#ifdef _DEFAULT_SOURCE\n# if !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE\n#  define __USE_POSIX_IMPLICITLY\t1\n# endif\n# undef  _POSIX_SOURCE\n# define _POSIX_SOURCE\t1\n# undef  _POSIX_C_SOURCE\n# define _POSIX_C_SOURCE\t200809L\n#endif\n\n#if ((!defined __STRICT_ANSI__\t\t\t\t\t\\\n      || (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500))\t\\\n     && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE)\n# define _POSIX_SOURCE\t1\n# if defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 500\n#  define _POSIX_C_SOURCE\t2\n# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 600\n#  define _POSIX_C_SOURCE\t199506L\n# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 700\n#  define _POSIX_C_SOURCE\t200112L\n# else\n#  define _POSIX_C_SOURCE\t200809L\n# endif\n# define __USE_POSIX_IMPLICITLY\t1\n#endif\n\n/* Some C libraries once required _REENTRANT and/or _THREAD_SAFE to be\n   defined in all multithreaded code.  GNU libc has not required this\n   for many years.  We now treat them as compatibility synonyms for\n   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with\n   comprehensive support for multithreaded code.  Using them never\n   lowers the selected level of POSIX conformance, only raises it.  */\n#if ((!defined _POSIX_C_SOURCE || (_POSIX_C_SOURCE - 0) < 199506L) \\\n     && (defined _REENTRANT || defined _THREAD_SAFE))\n# define _POSIX_SOURCE   1\n# undef  _POSIX_C_SOURCE\n# define _POSIX_C_SOURCE 199506L\n#endif\n\n#if (defined _POSIX_SOURCE\t\t\t\t\t\\\n     || (defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 1)\t\\\n     || defined _XOPEN_SOURCE)\n# define __USE_POSIX\t1\n#endif\n\n#if defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 2 || defined _XOPEN_SOURCE\n# define __USE_POSIX2\t1\n#endif\n\n#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199309L\n# define __USE_POSIX199309\t1\n#endif\n\n#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199506L\n# define __USE_POSIX199506\t1\n#endif\n\n#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200112L\n# define __USE_XOPEN2K\t\t1\n# undef __USE_ISOC95\n# define __USE_ISOC95\t\t1\n# undef __USE_ISOC99\n# define __USE_ISOC99\t\t1\n#endif\n\n#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200809L\n# define __USE_XOPEN2K8\t\t1\n# undef  _ATFILE_SOURCE\n# define _ATFILE_SOURCE\t1\n#endif\n\n#ifdef\t_XOPEN_SOURCE\n# define __USE_XOPEN\t1\n# if (_XOPEN_SOURCE - 0) >= 500\n#  define __USE_XOPEN_EXTENDED\t1\n#  define __USE_UNIX98\t1\n#  undef _LARGEFILE_SOURCE\n#  define _LARGEFILE_SOURCE\t1\n#  if (_XOPEN_SOURCE - 0) >= 600\n#   if (_XOPEN_SOURCE - 0) >= 700\n#    define __USE_XOPEN2K8\t1\n#    define __USE_XOPEN2K8XSI\t1\n#   endif\n#   define __USE_XOPEN2K\t1\n#   define __USE_XOPEN2KXSI\t1\n#   undef __USE_ISOC95\n#   define __USE_ISOC95\t\t1\n#   undef __USE_ISOC99\n#   define __USE_ISOC99\t\t1\n#  endif\n# else\n#  ifdef _XOPEN_SOURCE_EXTENDED\n#   define __USE_XOPEN_EXTENDED\t1\n#  endif\n# endif\n#endif\n\n#ifdef _LARGEFILE_SOURCE\n# define __USE_LARGEFILE\t1\n#endif\n\n#ifdef _LARGEFILE64_SOURCE\n# define __USE_LARGEFILE64\t1\n#endif\n\n#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64\n# define __USE_FILE_OFFSET64\t1\n#endif\n\n#include <features-time64.h>\n\n#if defined _DEFAULT_SOURCE\n# define __USE_MISC\t1\n#endif\n\n#ifdef\t_ATFILE_SOURCE\n# define __USE_ATFILE\t1\n#endif\n\n#ifdef\t_DYNAMIC_STACK_SIZE_SOURCE\n# define __USE_DYNAMIC_STACK_SIZE\t1\n#endif\n\n#ifdef\t_GNU_SOURCE\n# define __USE_GNU\t1\n#endif\n\n#if defined _FORTIFY_SOURCE && _FORTIFY_SOURCE > 0\n# if !defined __OPTIMIZE__ || __OPTIMIZE__ <= 0\n#  warning _FORTIFY_SOURCE requires compiling with optimization (-O)\n# elif !__GNUC_PREREQ (4, 1)\n#  warning _FORTIFY_SOURCE requires GCC 4.1 or later\n# elif _FORTIFY_SOURCE > 2 && (__glibc_clang_prereq (9, 0)\t\t      \\\n\t\t\t       || __GNUC_PREREQ (12, 0))\n\n#  if _FORTIFY_SOURCE > 3\n#   warning _FORTIFY_SOURCE > 3 is treated like 3 on this platform\n#  endif\n#  define __USE_FORTIFY_LEVEL 3\n# elif _FORTIFY_SOURCE > 1\n#  if _FORTIFY_SOURCE > 2\n#   warning _FORTIFY_SOURCE > 2 is treated like 2 on this platform\n#  endif\n#  define __USE_FORTIFY_LEVEL 2\n# else\n#  define __USE_FORTIFY_LEVEL 1\n# endif\n#endif\n#ifndef __USE_FORTIFY_LEVEL\n# define __USE_FORTIFY_LEVEL 0\n#endif\n\n/* The function 'gets' existed in C89, but is impossible to use\n   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for\n   compatibility with various implementations of <cstdio>, this test\n   must consider only the value of __cplusplus when compiling C++.  */\n#if defined __cplusplus ? __cplusplus >= 201402L : defined __USE_ISOC11\n# define __GLIBC_USE_DEPRECATED_GETS 0\n#else\n# define __GLIBC_USE_DEPRECATED_GETS 1\n#endif\n\n/* GNU formerly extended the scanf functions with modified format\n   specifiers %as, %aS, and %a[...] that allocate a buffer for the\n   input using malloc.  This extension conflicts with ISO C99, which\n   defines %a as a standalone format specifier that reads a floating-\n   point number; moreover, POSIX.1-2008 provides the same feature\n   using the modifier letter 'm' instead (%ms, %mS, %m[...]).\n\n   We now follow C99 unless GNU extensions are active and the compiler\n   is specifically in C89 or C++98 mode (strict or not).  For\n   instance, with GCC, -std=gnu11 will have C99-compliant scanf with\n   or without -D_GNU_SOURCE, but -std=c89 -D_GNU_SOURCE will have the\n   old extension.  */\n#if (defined __USE_GNU\t\t\t\t\t\t\t\\\n     && (defined __cplusplus\t\t\t\t\t\t\\\n\t ? (__cplusplus < 201103L && !defined __GXX_EXPERIMENTAL_CXX0X__) \\\n\t : (!defined __STDC_VERSION__ || __STDC_VERSION__ < 199901L)))\n# define __GLIBC_USE_DEPRECATED_SCANF 1\n#else\n# define __GLIBC_USE_DEPRECATED_SCANF 0\n#endif\n\n/* Get definitions of __STDC_* predefined macros, if the compiler has\n   not preincluded this header automatically.  */\n#include <stdc-predef.h>\n\n/* This macro indicates that the installed library is the GNU C Library.\n   For historic reasons the value now is 6 and this will stay from now\n   on.  The use of this variable is deprecated.  Use __GLIBC__ and\n   __GLIBC_MINOR__ now (see below) when you want to test for a specific\n   GNU C library version and use the values in <gnu/lib-names.h> to get\n   the sonames of the shared libraries.  */\n#undef  __GNU_LIBRARY__\n#define __GNU_LIBRARY__ 6\n\n/* Major and minor version number of the GNU C library package.  Use\n   these macros to test for features in specific releases.  */\n#define\t__GLIBC__\t2\n#define\t__GLIBC_MINOR__\t35\n\n#define __GLIBC_PREREQ(maj, min) \\\n\t((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))\n\n/* This is here only because every header file already includes this one.  */\n#ifndef __ASSEMBLER__\n# ifndef _SYS_CDEFS_H\n#  include <sys/cdefs.h>\n# endif\n\n/* If we don't have __REDIRECT, prototypes will be missing if\n   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */\n# if defined __USE_FILE_OFFSET64 && !defined __REDIRECT\n#  define __USE_LARGEFILE\t1\n#  define __USE_LARGEFILE64\t1\n# endif\n\n#endif\t/* !ASSEMBLER */\n\n/* Decide whether we can define 'extern inline' functions in headers.  */\n#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \\\n    && !defined __OPTIMIZE_SIZE__ && !defined __NO_INLINE__ \\\n    && defined __extern_inline\n# define __USE_EXTERN_INLINES\t1\n#endif\n\n\n/* This is here only because every header file already includes this one.\n   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.\n   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub\n   that will always return failure (and set errno to ENOSYS).  */\n#include <gnu/stubs.h>\n\n\n#endif\t/* features.h  */\n"}],"crc32":785012759,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]