[{"ops":[{"insert":"/* Copyright (C) 1995-2022 Free Software Foundation, Inc.\n   This file is part of the GNU C Library.\n\n   The GNU C Library is free software; you can redistribute it and/or\n   modify it under the terms of the GNU Lesser General Public\n   License as published by the Free Software Foundation; either\n   version 2.1 of the License, or (at your option) any later version.\n\n   The GNU C Library is distributed in the hope that it will be useful,\n   but WITHOUT ANY WARRANTY; without even the implied warranty of\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n   Lesser General Public License for more details.\n\n   You should have received a copy of the GNU Lesser General Public\n   License along with the GNU C Library; if not, see\n   <https://www.gnu.org/licenses/>.  */\n\n/*\n *      ISO C99 Standard: 7.24\n *\tExtended multibyte and wide character utilities\t<wchar.h>\n */\n\n#ifndef _WCHAR_H\n#define _WCHAR_H 1\n\n#define __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION\n#include <bits/libc-header-start.h>\n\n/* Gather machine dependent type support.  */\n#include <bits/floatn.h>\n\n#define __need_size_t\n#define __need_wchar_t\n#define __need_NULL\n#include <stddef.h>\n\n#define __need___va_list\n#include <stdarg.h>\n\n#include <bits/wchar.h>\n#include <bits/types/wint_t.h>\n#include <bits/types/mbstate_t.h>\n#include <bits/types/__FILE.h>\n\n#if defined __USE_UNIX98 || defined __USE_XOPEN2K\n# include <bits/types/FILE.h>\n#endif\n#ifdef __USE_XOPEN2K8\n# include <bits/types/locale_t.h>\n#endif\n\n/* Tell the caller that we provide correct C++ prototypes.  */\n#if defined __cplusplus && __GNUC_PREREQ (4, 4)\n# define __CORRECT_ISO_CPP_WCHAR_H_PROTO\n#endif\n\n#ifndef WCHAR_MIN\n/* These constants might also be defined in <inttypes.h>.  */\n# define WCHAR_MIN __WCHAR_MIN\n# define WCHAR_MAX __WCHAR_MAX\n#endif\n\n#ifndef WEOF\n# define WEOF (0xffffffffu)\n#endif\n\n/* All versions of XPG prior to the publication of ISO C99 required\n   the bulk of <wctype.h>'s declarations to appear in this header\n   (because <wctype.h> did not exist prior to C99).  In POSIX.1-2001\n   those declarations were marked as XSI extensions; in -2008 they\n   were additionally marked as obsolescent.  _GNU_SOURCE mode\n   anticipates the removal of these declarations in the next revision\n   of POSIX.  */\n#if (defined __USE_XOPEN && !defined __USE_GNU \\\n     && !(defined __USE_XOPEN2K && !defined __USE_XOPEN2KXSI))\n# include <bits/wctype-wchar.h>\n#endif\n\n__BEGIN_DECLS\n\n/* This incomplete type is defined in <time.h> but needed here because\n   of `wcsftime'.  */\nstruct tm;\n\n\n/* Copy SRC to DEST.  */\nextern wchar_t *wcscpy (wchar_t *__restrict __dest,\n\t\t\tconst wchar_t *__restrict __src)\n     __THROW __nonnull ((1, 2));\n\n/* Copy no more than N wide-characters of SRC to DEST.  */\nextern wchar_t *wcsncpy (wchar_t *__restrict __dest,\n\t\t\t const wchar_t *__restrict __src, size_t __n)\n     __THROW __nonnull ((1, 2));\n\n/* Append SRC onto DEST.  */\nextern wchar_t *wcscat (wchar_t *__restrict __dest,\n\t\t\tconst wchar_t *__restrict __src)\n     __THROW __nonnull ((1, 2));\n/* Append no more than N wide-characters of SRC onto DEST.  */\nextern wchar_t *wcsncat (wchar_t *__restrict __dest,\n\t\t\t const wchar_t *__restrict __src, size_t __n)\n     __THROW __nonnull ((1, 2));\n\n/* Compare S1 and S2.  */\nextern int wcscmp (const wchar_t *__s1, const wchar_t *__s2)\n     __THROW __attribute_pure__ __nonnull ((1, 2));\n/* Compare N wide-characters of S1 and S2.  */\nextern int wcsncmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)\n     __THROW __attribute_pure__ __nonnull ((1, 2));\n\n#ifdef __USE_XOPEN2K8\n/* Compare S1 and S2, ignoring case.  */\nextern int wcscasecmp (const wchar_t *__s1, const wchar_t *__s2) __THROW;\n\n/* Compare no more than N chars of S1 and S2, ignoring case.  */\nextern int wcsncasecmp (const wchar_t *__s1, const wchar_t *__s2,\n\t\t\tsize_t __n) __THROW;\n\n/* Similar to the two functions above but take the information from\n   the provided locale and not the global locale.  */\nextern int wcscasecmp_l (const wchar_t *__s1, const wchar_t *__s2,\n\t\t\t locale_t __loc) __THROW;\n\nextern int wcsncasecmp_l (const wchar_t *__s1, const wchar_t *__s2,\n\t\t\t  size_t __n, locale_t __loc) __THROW;\n#endif\n\n/* Compare S1 and S2, both interpreted as appropriate to the\n   LC_COLLATE category of the current locale.  */\nextern int wcscoll (const wchar_t *__s1, const wchar_t *__s2) __THROW;\n/* Transform S2 into array pointed to by S1 such that if wcscmp is\n   applied to two transformed strings the result is the as applying\n   `wcscoll' to the original strings.  */\nextern size_t wcsxfrm (wchar_t *__restrict __s1,\n\t\t       const wchar_t *__restrict __s2, size_t __n) __THROW;\n\n#ifdef __USE_XOPEN2K8\n/* Similar to the two functions above but take the information from\n   the provided locale and not the global locale.  */\n\n/* Compare S1 and S2, both interpreted as appropriate to the\n   LC_COLLATE category of the given locale.  */\nextern int wcscoll_l (const wchar_t *__s1, const wchar_t *__s2,\n\t\t      locale_t __loc) __THROW;\n\n/* Transform S2 into array pointed to by S1 such that if wcscmp is\n   applied to two transformed strings the result is the as applying\n   `wcscoll' to the original strings.  */\nextern size_t wcsxfrm_l (wchar_t *__s1, const wchar_t *__s2,\n\t\t\t size_t __n, locale_t __loc) __THROW;\n\n/* Duplicate S, returning an identical malloc'd string.  */\nextern wchar_t *wcsdup (const wchar_t *__s) __THROW\n  __attribute_malloc__ __attr_dealloc_free;\n#endif\n\n/* Find the first occurrence of WC in WCS.  */\n#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO\nextern \"C++\" wchar_t *wcschr (wchar_t *__wcs, wchar_t __wc)\n     __THROW __asm (\"wcschr\") __attribute_pure__;\nextern \"C++\" const wchar_t *wcschr (const wchar_t *__wcs, wchar_t __wc)\n     __THROW __asm (\"wcschr\") __attribute_pure__;\n#else\nextern wchar_t *wcschr (const wchar_t *__wcs, wchar_t __wc)\n     __THROW __attribute_pure__;\n#endif\n/* Find the last occurrence of WC in WCS.  */\n#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO\nextern \"C++\" wchar_t *wcsrchr (wchar_t *__wcs, wchar_t __wc)\n     __THROW __asm (\"wcsrchr\") __attribute_pure__;\nextern \"C++\" const wchar_t *wcsrchr (const wchar_t *__wcs, wchar_t __wc)\n     __THROW __asm (\"wcsrchr\") __attribute_pure__;\n#else\nextern wchar_t *wcsrchr (const wchar_t *__wcs, wchar_t __wc)\n     __THROW __attribute_pure__;\n#endif\n\n#ifdef __USE_GNU\n/* This function is similar to `wcschr'.  But it returns a pointer to\n   the closing NUL wide character in case C is not found in S.  */\nextern wchar_t *wcschrnul (const wchar_t *__s, wchar_t __wc)\n     __THROW __attribute_pure__;\n#endif\n\n/* Return the length of the initial segmet of WCS which\n   consists entirely of wide characters not in REJECT.  */\nextern size_t wcscspn (const wchar_t *__wcs, const wchar_t *__reject)\n     __THROW __attribute_pure__;\n/* Return the length of the initial segmet of WCS which\n   consists entirely of wide characters in  ACCEPT.  */\nextern size_t wcsspn (const wchar_t *__wcs, const wchar_t *__accept)\n     __THROW __attribute_pure__;\n/* Find the first occurrence in WCS of any character in ACCEPT.  */\n#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO\nextern \"C++\" wchar_t *wcspbrk (wchar_t *__wcs, const wchar_t *__accept)\n     __THROW __asm (\"wcspbrk\") __attribute_pure__;\nextern \"C++\" const wchar_t *wcspbrk (const wchar_t *__wcs,\n\t\t\t\t     const wchar_t *__accept)\n     __THROW __asm (\"wcspbrk\") __attribute_pure__;\n#else\nextern wchar_t *wcspbrk (const wchar_t *__wcs, const wchar_t *__accept)\n     __THROW __attribute_pure__;\n#endif\n/* Find the first occurrence of NEEDLE in HAYSTACK.  */\n#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO\nextern \"C++\" wchar_t *wcsstr (wchar_t *__haystack, const wchar_t *__needle)\n     __THROW __asm (\"wcsstr\") __attribute_pure__;\nextern \"C++\" const wchar_t *wcsstr (const wchar_t *__haystack,\n\t\t\t\t    const wchar_t *__needle)\n     __THROW __asm (\"wcsstr\") __attribute_pure__;\n#else\nextern wchar_t *wcsstr (const wchar_t *__haystack, const wchar_t *__needle)\n     __THROW __attribute_pure__;\n#endif\n\n/* Divide WCS into tokens separated by characters in DELIM.  */\nextern wchar_t *wcstok (wchar_t *__restrict __s,\n\t\t\tconst wchar_t *__restrict __delim,\n\t\t\twchar_t **__restrict __ptr) __THROW;\n\n/* Return the number of wide characters in S.  */\nextern size_t wcslen (const wchar_t *__s) __THROW __attribute_pure__;\n\n#ifdef __USE_XOPEN\n/* Another name for `wcsstr' from XPG4.  */\n# ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO\nextern \"C++\" wchar_t *wcswcs (wchar_t *__haystack, const wchar_t *__needle)\n     __THROW __asm (\"wcswcs\") __attribute_pure__;\nextern \"C++\" const wchar_t *wcswcs (const wchar_t *__haystack,\n\t\t\t\t    const wchar_t *__needle)\n     __THROW __asm (\"wcswcs\") __attribute_pure__;\n# else\nextern wchar_t *wcswcs (const wchar_t *__haystack, const wchar_t *__needle)\n     __THROW __attribute_pure__;\n# endif\n#endif\n\n#ifdef __USE_XOPEN2K8\n/* Return the number of wide characters in S, but at most MAXLEN.  */\nextern size_t wcsnlen (const wchar_t *__s, size_t __maxlen)\n     __THROW __attribute_pure__;\n#endif\n\n\n/* Search N wide characters of S for C.  */\n#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO\nextern \"C++\" wchar_t *wmemchr (wchar_t *__s, wchar_t __c, size_t __n)\n     __THROW __asm (\"wmemchr\") __attribute_pure__;\nextern \"C++\" const wchar_t *wmemchr (const wchar_t *__s, wchar_t __c,\n\t\t\t\t     size_t __n)\n     __THROW __asm (\"wmemchr\") __attribute_pure__;\n#else\nextern wchar_t *wmemchr (const wchar_t *__s, wchar_t __c, size_t __n)\n     __THROW __attribute_pure__;\n#endif\n\n/* Compare N wide characters of S1 and S2.  */\nextern int wmemcmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)\n     __THROW __attribute_pure__;\n\n/* Copy N wide characters of SRC to DEST.  */\nextern wchar_t *wmemcpy (wchar_t *__restrict __s1,\n\t\t\t const wchar_t *__restrict __s2, size_t __n) __THROW;\n\n/* Copy N wide characters of SRC to DEST, guaranteeing\n   correct behavior for overlapping strings.  */\nextern wchar_t *wmemmove (wchar_t *__s1, const wchar_t *__s2, size_t __n)\n     __THROW;\n\n/* Set N wide characters of S to C.  */\nextern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) __THROW;\n\n#ifdef __USE_GNU\n/* Copy N wide characters of SRC to DEST and return pointer to following\n   wide character.  */\nextern wchar_t *wmempcpy (wchar_t *__restrict __s1,\n\t\t\t  const wchar_t *__restrict __s2, size_t __n)\n     __THROW;\n#endif\n\n\n/* Determine whether C constitutes a valid (one-byte) multibyte\n   character.  */\nextern wint_t btowc (int __c) __THROW;\n\n/* Determine whether C corresponds to a member of the extended\n   character set whose multibyte representation is a single byte.  */\nextern int wctob (wint_t __c) __THROW;\n\n/* Determine whether PS points to an object representing the initial\n   state.  */\nextern int mbsinit (const mbstate_t *__ps) __THROW __attribute_pure__;\n\n/* Write wide character representation of multibyte character pointed\n   to by S to PWC.  */\nextern size_t mbrtowc (wchar_t *__restrict __pwc,\n\t\t       const char *__restrict __s, size_t __n,\n\t\t       mbstate_t *__restrict __p) __THROW;\n\n/* Write multibyte representation of wide character WC to S.  */\nextern size_t wcrtomb (char *__restrict __s, wchar_t __wc,\n\t\t       mbstate_t *__restrict __ps) __THROW;\n\n/* Return number of bytes in multibyte character pointed to by S.  */\nextern size_t __mbrlen (const char *__restrict __s, size_t __n,\n\t\t\tmbstate_t *__restrict __ps) __THROW;\nextern size_t mbrlen (const char *__restrict __s, size_t __n,\n\t\t      mbstate_t *__restrict __ps) __THROW;\n\n#ifdef __USE_EXTERN_INLINES\n/* Define inline function as optimization.  */\n\n/* We can use the BTOWC and WCTOB optimizations since we know that all\n   locales must use ASCII encoding for the values in the ASCII range\n   and because the wchar_t encoding is always ISO 10646.  */\nextern wint_t __btowc_alias (int __c) __asm (\"btowc\");\n__extern_inline wint_t\n__NTH (btowc (int __c))\n{ return (__builtin_constant_p (__c) && __c >= '\\0' && __c <= '\\x7f'\n\t  ? (wint_t) __c : __btowc_alias (__c)); }\n\nextern int __wctob_alias (wint_t __c) __asm (\"wctob\");\n__extern_inline int\n__NTH (wctob (wint_t __wc))\n{ return (__builtin_constant_p (__wc) && __wc >= L'\\0' && __wc <= L'\\x7f'\n\t  ? (int) __wc : __wctob_alias (__wc)); }\n\n__extern_inline size_t\n__NTH (mbrlen (const char *__restrict __s, size_t __n,\n\t       mbstate_t *__restrict __ps))\n{ return (__ps != NULL\n\t  ? mbrtowc (NULL, __s, __n, __ps) : __mbrlen (__s, __n, NULL)); }\n#endif\n\n/* Write wide character representation of multibyte character string\n   SRC to DST.  */\nextern size_t mbsrtowcs (wchar_t *__restrict __dst,\n\t\t\t const char **__restrict __src, size_t __len,\n\t\t\t mbstate_t *__restrict __ps) __THROW;\n\n/* Write multibyte character representation of wide character string\n   SRC to DST.  */\nextern size_t wcsrtombs (char *__restrict __dst,\n\t\t\t const wchar_t **__restrict __src, size_t __len,\n\t\t\t mbstate_t *__restrict __ps) __THROW;\n\n\n#ifdef\t__USE_XOPEN2K8\n/* Write wide character representation of at most NMC bytes of the\n   multibyte character string SRC to DST.  */\nextern size_t mbsnrtowcs (wchar_t *__restrict __dst,\n\t\t\t  const char **__restrict __src, size_t __nmc,\n\t\t\t  size_t __len, mbstate_t *__restrict __ps) __THROW;\n\n/* Write multibyte character representation of at most NWC characters\n   from the wide character string SRC to DST.  */\nextern size_t wcsnrtombs (char *__restrict __dst,\n\t\t\t  const wchar_t **__restrict __src,\n\t\t\t  size_t __nwc, size_t __len,\n\t\t\t  mbstate_t *__restrict __ps) __THROW;\n#endif\t/* use POSIX 2008 */\n\n\n/* The following functions are extensions found in X/Open CAE.  */\n#ifdef __USE_XOPEN\n/* Determine number of column positions required for C.  */\nextern int wcwidth (wchar_t __c) __THROW;\n\n/* Determine number of column positions required for first N wide\n   characters (or fewer if S ends before this) in S.  */\nextern int wcswidth (const wchar_t *__s, size_t __n) __THROW;\n#endif\t/* Use X/Open.  */\n\n\n/* Convert initial portion of the wide string NPTR to `double'\n   representation.  */\nextern double wcstod (const wchar_t *__restrict __nptr,\n\t\t      wchar_t **__restrict __endptr) __THROW;\n\n#ifdef __USE_ISOC99\n/* Likewise for `float' and `long double' sizes of floating-point numbers.  */\nextern float wcstof (const wchar_t *__restrict __nptr,\n\t\t     wchar_t **__restrict __endptr) __THROW;\nextern long double wcstold (const wchar_t *__restrict __nptr,\n\t\t\t    wchar_t **__restrict __endptr) __THROW;\n#endif /* C99 */\n\n/* Likewise for `_FloatN' and `_FloatNx' when support is enabled.  */\n\n#if __HAVE_FLOAT16 && defined __USE_GNU\nextern _Float16 wcstof16 (const wchar_t *__restrict __nptr,\n\t\t\t  wchar_t **__restrict __endptr) __THROW;\n#endif\n\n#if __HAVE_FLOAT32 && defined __USE_GNU\nextern _Float32 wcstof32 (const wchar_t *__restrict __nptr,\n\t\t\t  wchar_t **__restrict __endptr) __THROW;\n#endif\n\n#if __HAVE_FLOAT64 && defined __USE_GNU\nextern _Float64 wcstof64 (const wchar_t *__restrict __nptr,\n\t\t\t  wchar_t **__restrict __endptr) __THROW;\n#endif\n\n#if __HAVE_FLOAT128 && defined __USE_GNU\nextern _Float128 wcstof128 (const wchar_t *__restrict __nptr,\n\t\t\t    wchar_t **__restrict __endptr) __THROW;\n#endif\n\n#if __HAVE_FLOAT32X && defined __USE_GNU\nextern _Float32x wcstof32x (const wchar_t *__restrict __nptr,\n\t\t\t    wchar_t **__restrict __endptr) __THROW;\n#endif\n\n#if __HAVE_FLOAT64X && defined __USE_GNU\nextern _Float64x wcstof64x (const wchar_t *__restrict __nptr,\n\t\t\t    wchar_t **__restrict __endptr) __THROW;\n#endif\n\n#if __HAVE_FLOAT128X && defined __USE_GNU\nextern _Float128x wcstof128x (const wchar_t *__restrict __nptr,\n\t\t\t      wchar_t **__restrict __endptr) __THROW;\n#endif\n\n\n/* Convert initial portion of wide string NPTR to `long int'\n   representation.  */\nextern long int wcstol (const wchar_t *__restrict __nptr,\n\t\t\twchar_t **__restrict __endptr, int __base) __THROW;\n\n/* Convert initial portion of wide string NPTR to `unsigned long int'\n   representation.  */\nextern unsigned long int wcstoul (const wchar_t *__restrict __nptr,\n\t\t\t\t  wchar_t **__restrict __endptr, int __base)\n     __THROW;\n\n#ifdef __USE_ISOC99\n/* Convert initial portion of wide string NPTR to `long long int'\n   representation.  */\n__extension__\nextern long long int wcstoll (const wchar_t *__restrict __nptr,\n\t\t\t      wchar_t **__restrict __endptr, int __base)\n     __THROW;\n\n/* Convert initial portion of wide string NPTR to `unsigned long long int'\n   representation.  */\n__extension__\nextern unsigned long long int wcstoull (const wchar_t *__restrict __nptr,\n\t\t\t\t\twchar_t **__restrict __endptr,\n\t\t\t\t\tint __base) __THROW;\n#endif /* ISO C99.  */\n\n#ifdef __USE_GNU\n/* Convert initial portion of wide string NPTR to `long long int'\n   representation.  */\n__extension__\nextern long long int wcstoq (const wchar_t *__restrict __nptr,\n\t\t\t     wchar_t **__restrict __endptr, int __base)\n     __THROW;\n\n/* Convert initial portion of wide string NPTR to `unsigned long long int'\n   representation.  */\n__extension__\nextern unsigned long long int wcstouq (const wchar_t *__restrict __nptr,\n\t\t\t\t       wchar_t **__restrict __endptr,\n\t\t\t\t       int __base) __THROW;\n#endif /* Use GNU.  */\n\n#ifdef __USE_GNU\n/* Parallel versions of the functions above which take the locale to\n   use as an additional parameter.  These are GNU extensions inspired\n   by the POSIX.1-2008 extended locale API.  */\nextern long int wcstol_l (const wchar_t *__restrict __nptr,\n\t\t\t  wchar_t **__restrict __endptr, int __base,\n\t\t\t  locale_t __loc) __THROW;\n\nextern unsigned long int wcstoul_l (const wchar_t *__restrict __nptr,\n\t\t\t\t    wchar_t **__restrict __endptr,\n\t\t\t\t    int __base, locale_t __loc) __THROW;\n\n__extension__\nextern long long int wcstoll_l (const wchar_t *__restrict __nptr,\n\t\t\t\twchar_t **__restrict __endptr,\n\t\t\t\tint __base, locale_t __loc) __THROW;\n\n__extension__\nextern unsigned long long int wcstoull_l (const wchar_t *__restrict __nptr,\n\t\t\t\t\t  wchar_t **__restrict __endptr,\n\t\t\t\t\t  int __base, locale_t __loc)\n     __THROW;\n\nextern double wcstod_l (const wchar_t *__restrict __nptr,\n\t\t\twchar_t **__restrict __endptr, locale_t __loc)\n     __THROW;\n\nextern float wcstof_l (const wchar_t *__restrict __nptr,\n\t\t       wchar_t **__restrict __endptr, locale_t __loc)\n     __THROW;\n\nextern long double wcstold_l (const wchar_t *__restrict __nptr,\n\t\t\t      wchar_t **__restrict __endptr,\n\t\t\t      locale_t __loc) __THROW;\n\n# if __HAVE_FLOAT16\nextern _Float16 wcstof16_l (const wchar_t *__restrict __nptr,\n\t\t\t    wchar_t **__restrict __endptr,\n\t\t\t    locale_t __loc) __THROW;\n# endif\n\n# if __HAVE_FLOAT32\nextern _Float32 wcstof32_l (const wchar_t *__restrict __nptr,\n\t\t\t    wchar_t **__restrict __endptr,\n\t\t\t    locale_t __loc) __THROW;\n# endif\n\n# if __HAVE_FLOAT64\nextern _Float64 wcstof64_l (const wchar_t *__restrict __nptr,\n\t\t\t    wchar_t **__restrict __endptr,\n\t\t\t    locale_t __loc) __THROW;\n# endif\n\n# if __HAVE_FLOAT128\nextern _Float128 wcstof128_l (const wchar_t *__restrict __nptr,\n\t\t\t      wchar_t **__restrict __endptr,\n\t\t\t      locale_t __loc) __THROW;\n# endif\n\n# if __HAVE_FLOAT32X\nextern _Float32x wcstof32x_l (const wchar_t *__restrict __nptr,\n\t\t\t      wchar_t **__restrict __endptr,\n\t\t\t      locale_t __loc) __THROW;\n# endif\n\n# if __HAVE_FLOAT64X\nextern _Float64x wcstof64x_l (const wchar_t *__restrict __nptr,\n\t\t\t      wchar_t **__restrict __endptr,\n\t\t\t      locale_t __loc) __THROW;\n# endif\n\n# if __HAVE_FLOAT128X\nextern _Float128x wcstof128x_l (const wchar_t *__restrict __nptr,\n\t\t\t\twchar_t **__restrict __endptr,\n\t\t\t\tlocale_t __loc) __THROW;\n# endif\n#endif\t/* use GNU */\n\n\n#ifdef __USE_XOPEN2K8\n/* Copy SRC to DEST, returning the address of the terminating L'\\0' in\n   DEST.  */\nextern wchar_t *wcpcpy (wchar_t *__restrict __dest,\n\t\t\tconst wchar_t *__restrict __src) __THROW;\n\n/* Copy no more than N characters of SRC to DEST, returning the address of\n   the last character written into DEST.  */\nextern wchar_t *wcpncpy (wchar_t *__restrict __dest,\n\t\t\t const wchar_t *__restrict __src, size_t __n)\n     __THROW;\n#endif\n\n\n/* Wide character I/O functions.  */\n\n#if defined __USE_XOPEN2K8 || __GLIBC_USE (LIB_EXT2)\n# ifndef __attr_dealloc_fclose\n#   if defined __has_builtin\n#     if __has_builtin (__builtin_fclose)\n/* If the attribute macro hasn't been defined yet (by <stdio.h>) and\n   fclose is a built-in, use it.  */\n#      define __attr_dealloc_fclose __attr_dealloc (__builtin_fclose, 1)\n#     endif\n#   endif\n# endif\n# ifndef __attr_dealloc_fclose\n#  define __attr_dealloc_fclose /* empty */\n# endif\n\n/* Like OPEN_MEMSTREAM, but the stream is wide oriented and produces\n   a wide character string.  */\nextern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) __THROW\n  __attribute_malloc__ __attr_dealloc_fclose;\n#endif\n\n#if defined __USE_ISOC95 || defined __USE_UNIX98\n\n/* Select orientation for stream.  */\nextern int fwide (__FILE *__fp, int __mode) __THROW;\n\n\n/* Write formatted output to STREAM.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int fwprintf (__FILE *__restrict __stream,\n\t\t     const wchar_t *__restrict __format, ...)\n     /* __attribute__ ((__format__ (__wprintf__, 2, 3))) */;\n/* Write formatted output to stdout.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int wprintf (const wchar_t *__restrict __format, ...)\n     /* __attribute__ ((__format__ (__wprintf__, 1, 2))) */;\n/* Write formatted output of at most N characters to S.  */\nextern int swprintf (wchar_t *__restrict __s, size_t __n,\n\t\t     const wchar_t *__restrict __format, ...)\n     __THROW /* __attribute__ ((__format__ (__wprintf__, 3, 4))) */;\n\n/* Write formatted output to S from argument list ARG.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int vfwprintf (__FILE *__restrict __s,\n\t\t      const wchar_t *__restrict __format,\n\t\t      __gnuc_va_list __arg)\n     /* __attribute__ ((__format__ (__wprintf__, 2, 0))) */;\n/* Write formatted output to stdout from argument list ARG.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int vwprintf (const wchar_t *__restrict __format,\n\t\t     __gnuc_va_list __arg)\n     /* __attribute__ ((__format__ (__wprintf__, 1, 0))) */;\n/* Write formatted output of at most N character to S from argument\n   list ARG.  */\nextern int vswprintf (wchar_t *__restrict __s, size_t __n,\n\t\t      const wchar_t *__restrict __format,\n\t\t      __gnuc_va_list __arg)\n     __THROW /* __attribute__ ((__format__ (__wprintf__, 3, 0))) */;\n\n\n/* Read formatted input from STREAM.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int fwscanf (__FILE *__restrict __stream,\n\t\t    const wchar_t *__restrict __format, ...)\n     /* __attribute__ ((__format__ (__wscanf__, 2, 3))) */;\n/* Read formatted input from stdin.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int wscanf (const wchar_t *__restrict __format, ...)\n     /* __attribute__ ((__format__ (__wscanf__, 1, 2))) */;\n/* Read formatted input from S.  */\nextern int swscanf (const wchar_t *__restrict __s,\n\t\t    const wchar_t *__restrict __format, ...)\n     __THROW /* __attribute__ ((__format__ (__wscanf__, 2, 3))) */;\n\n/* For historical reasons, the C99-compliant versions of the scanf\n   functions are at alternative names.  When __LDBL_COMPAT or\n   __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI are in effect, this is handled in\n   bits/wchar-ldbl.h.  */\n#if !__GLIBC_USE (DEPRECATED_SCANF) && !defined __LDBL_COMPAT \\\n     && __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI == 0\n#  ifdef __REDIRECT\nextern int __REDIRECT (fwscanf, (__FILE *__restrict __stream,\n\t\t\t\t const wchar_t *__restrict __format, ...),\n\t\t       __isoc99_fwscanf)\n     /* __attribute__ ((__format__ (__wscanf__, 2, 3))) */;\nextern int __REDIRECT (wscanf, (const wchar_t *__restrict __format, ...),\n\t\t       __isoc99_wscanf)\n     /* __attribute__ ((__format__ (__wscanf__, 1, 2))) */;\nextern int __REDIRECT_NTH (swscanf, (const wchar_t *__restrict __s,\n\t\t\t\t     const wchar_t *__restrict __format,\n\t\t\t\t     ...), __isoc99_swscanf)\n     /* __attribute__ ((__format__ (__wscanf__, 2, 3))) */;\n#  else\nextern int __isoc99_fwscanf (__FILE *__restrict __stream,\n\t\t\t     const wchar_t *__restrict __format, ...);\nextern int __isoc99_wscanf (const wchar_t *__restrict __format, ...);\nextern int __isoc99_swscanf (const wchar_t *__restrict __s,\n\t\t\t     const wchar_t *__restrict __format, ...)\n     __THROW;\n#   define fwscanf __isoc99_fwscanf\n#   define wscanf __isoc99_wscanf\n#   define swscanf __isoc99_swscanf\n#  endif\n# endif\n\n#endif /* Use ISO C95, C99 and Unix98. */\n\n#ifdef __USE_ISOC99\n/* Read formatted input from S into argument list ARG.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int vfwscanf (__FILE *__restrict __s,\n\t\t     const wchar_t *__restrict __format,\n\t\t     __gnuc_va_list __arg)\n     /* __attribute__ ((__format__ (__wscanf__, 2, 0))) */;\n/* Read formatted input from stdin into argument list ARG.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int vwscanf (const wchar_t *__restrict __format,\n\t\t    __gnuc_va_list __arg)\n     /* __attribute__ ((__format__ (__wscanf__, 1, 0))) */;\n/* Read formatted input from S into argument list ARG.  */\nextern int vswscanf (const wchar_t *__restrict __s,\n\t\t     const wchar_t *__restrict __format,\n\t\t     __gnuc_va_list __arg)\n     __THROW /* __attribute__ ((__format__ (__wscanf__, 2, 0))) */;\n\n/* Same redirection as above for the v*wscanf family.  */\n# if !__GLIBC_USE (DEPRECATED_SCANF) \\\n     && (!defined __LDBL_COMPAT || !defined __REDIRECT) \\\n     && (defined __STRICT_ANSI__ || defined __USE_XOPEN2K) \\\n     && __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI == 0\n#  ifdef __REDIRECT\nextern int __REDIRECT (vfwscanf, (__FILE *__restrict __s,\n\t\t\t\t  const wchar_t *__restrict __format,\n\t\t\t\t  __gnuc_va_list __arg), __isoc99_vfwscanf)\n     /* __attribute__ ((__format__ (__wscanf__, 2, 0))) */;\nextern int __REDIRECT (vwscanf, (const wchar_t *__restrict __format,\n\t\t\t\t __gnuc_va_list __arg), __isoc99_vwscanf)\n     /* __attribute__ ((__format__ (__wscanf__, 1, 0))) */;\nextern int __REDIRECT_NTH (vswscanf, (const wchar_t *__restrict __s,\n\t\t\t\t      const wchar_t *__restrict __format,\n\t\t\t\t      __gnuc_va_list __arg), __isoc99_vswscanf)\n     /* __attribute__ ((__format__ (__wscanf__, 2, 0))) */;\n#  else\nextern int __isoc99_vfwscanf (__FILE *__restrict __s,\n\t\t\t      const wchar_t *__restrict __format,\n\t\t\t      __gnuc_va_list __arg);\nextern int __isoc99_vwscanf (const wchar_t *__restrict __format,\n\t\t\t     __gnuc_va_list __arg);\nextern int __isoc99_vswscanf (const wchar_t *__restrict __s,\n\t\t\t      const wchar_t *__restrict __format,\n\t\t\t      __gnuc_va_list __arg) __THROW;\n#   define vfwscanf __isoc99_vfwscanf\n#   define vwscanf __isoc99_vwscanf\n#   define vswscanf __isoc99_vswscanf\n#  endif\n# endif\n\n#endif /* Use ISO C99. */\n\n\n/* Read a character from STREAM.\n\n   These functions are possible cancellation points and therefore not\n   marked with __THROW.  */\nextern wint_t fgetwc (__FILE *__stream);\nextern wint_t getwc (__FILE *__stream);\n\n/* Read a character from stdin.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern wint_t getwchar (void);\n\n\n/* Write a character to STREAM.\n\n   These functions are possible cancellation points and therefore not\n   marked with __THROW.  */\nextern wint_t fputwc (wchar_t __wc, __FILE *__stream);\nextern wint_t putwc (wchar_t __wc, __FILE *__stream);\n\n/* Write a character to stdout.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern wint_t putwchar (wchar_t __wc);\n\n\n/* Get a newline-terminated wide character string of finite length\n   from STREAM.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,\n\t\t\t__FILE *__restrict __stream);\n\n/* Write a string to STREAM.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern int fputws (const wchar_t *__restrict __ws,\n\t\t   __FILE *__restrict __stream);\n\n\n/* Push a character back onto the input buffer of STREAM.\n\n   This function is a possible cancellation point and therefore not\n   marked with __THROW.  */\nextern wint_t ungetwc (wint_t __wc, __FILE *__stream);\n\n\n#ifdef __USE_GNU\n/* These are defined to be equivalent to the `char' functions defined\n   in POSIX.1:1996.\n\n   These functions are not part of POSIX and therefore no official\n   cancellation point.  But due to similarity with an POSIX interface\n   or due to the implementation they are cancellation points and\n   therefore not marked with __THROW.  */\nextern wint_t getwc_unlocked (__FILE *__stream);\nextern wint_t getwchar_unlocked (void);\n\n/* This is the wide character version of a GNU extension.\n\n   This function is not part of POSIX and therefore no official\n   cancellation point.  But due to similarity with an POSIX interface\n   or due to the implementation it is a cancellation point and\n   therefore not marked with __THROW.  */\nextern wint_t fgetwc_unlocked (__FILE *__stream);\n\n/* Faster version when locking is not necessary.\n\n   This function is not part of POSIX and therefore no official\n   cancellation point.  But due to similarity with an POSIX interface\n   or due to the implementation it is a cancellation point and\n   therefore not marked with __THROW.  */\nextern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream);\n\n/* These are defined to be equivalent to the `char' functions defined\n   in POSIX.1:1996.\n\n   These functions are not part of POSIX and therefore no official\n   cancellation point.  But due to similarity with an POSIX interface\n   or due to the implementation they are cancellation points and\n   therefore not marked with __THROW.  */\nextern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream);\nextern wint_t putwchar_unlocked (wchar_t __wc);\n\n\n/* This function does the same as `fgetws' but does not lock the stream.\n\n   This function is not part of POSIX and therefore no official\n   cancellation point.  But due to similarity with an POSIX interface\n   or due to the implementation it is a cancellation point and\n   therefore not marked with __THROW.  */\nextern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n,\n\t\t\t\t __FILE *__restrict __stream);\n\n/* This function does the same as `fputws' but does not lock the stream.\n\n   This function is not part of POSIX and therefore no official\n   cancellation point.  But due to similarity with an POSIX interface\n   or due to the implementation it is a cancellation point and\n   therefore not marked with __THROW.  */\nextern int fputws_unlocked (const wchar_t *__restrict __ws,\n\t\t\t    __FILE *__restrict __stream);\n#endif\n\n\n/* Format TP into S according to FORMAT.\n   Write no more than MAXSIZE wide characters and return the number\n   of wide characters written, or 0 if it would exceed MAXSIZE.  */\nextern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,\n\t\t\tconst wchar_t *__restrict __format,\n\t\t\tconst struct tm *__restrict __tp) __THROW;\n\n# ifdef __USE_GNU\n/* Similar to `wcsftime' but takes the information from\n   the provided locale and not the global locale.  */\nextern size_t wcsftime_l (wchar_t *__restrict __s, size_t __maxsize,\n\t\t\t  const wchar_t *__restrict __format,\n\t\t\t  const struct tm *__restrict __tp,\n\t\t\t  locale_t __loc) __THROW;\n# endif\n\n/* Define some macros helping to catch buffer overflows.  */\n#if __USE_FORTIFY_LEVEL > 0 && defined __fortify_function\n# include <bits/wchar2.h>\n#endif\n\n#include <bits/floatn.h>\n#if defined __LDBL_COMPAT || __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI == 1\n# include <bits/wchar-ldbl.h>\n#endif\n\n__END_DECLS\n\n#endif /* wchar.h  */\n"}],"crc32":4160950541,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]