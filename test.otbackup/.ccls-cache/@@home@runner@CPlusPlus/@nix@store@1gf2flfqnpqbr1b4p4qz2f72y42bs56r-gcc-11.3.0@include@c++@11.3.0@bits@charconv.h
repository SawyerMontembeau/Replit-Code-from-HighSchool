[{"ops":[{"insert":"// Numeric conversions (to_string, to_chars) -*- C++ -*-\n\n// Copyright (C) 2017-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file bits/charconv.h\n *  This is an internal header file, included by other library headers.\n *  Do not attempt to use it directly. @headername{charconv}\n */\n\n#ifndef _GLIBCXX_CHARCONV_H\n#define _GLIBCXX_CHARCONV_H 1\n\n#pragma GCC system_header\n\n#if __cplusplus >= 201103L\n\n#include <type_traits>\n\nnamespace std _GLIBCXX_VISIBILITY(default)\n{\n_GLIBCXX_BEGIN_NAMESPACE_VERSION\nnamespace __detail\n{\n  // Generic implementation for arbitrary bases.\n  template<typename _Tp>\n    _GLIBCXX14_CONSTEXPR unsigned\n    __to_chars_len(_Tp __value, int __base = 10) noexcept\n    {\n      static_assert(is_integral<_Tp>::value, \"implementation bug\");\n      static_assert(is_unsigned<_Tp>::value, \"implementation bug\");\n\n      unsigned __n = 1;\n      const unsigned __b2 = __base  * __base;\n      const unsigned __b3 = __b2 * __base;\n      const unsigned long __b4 = __b3 * __base;\n      for (;;)\n\t{\n\t  if (__value < (unsigned)__base) return __n;\n\t  if (__value < __b2) return __n + 1;\n\t  if (__value < __b3) return __n + 2;\n\t  if (__value < __b4) return __n + 3;\n\t  __value /= __b4;\n\t  __n += 4;\n\t}\n    }\n\n  // Write an unsigned integer value to the range [first,first+len).\n  // The caller is required to provide a buffer of exactly the right size\n  // (which can be determined by the __to_chars_len function).\n  template<typename _Tp>\n    void\n    __to_chars_10_impl(char* __first, unsigned __len, _Tp __val) noexcept\n    {\n      static_assert(is_integral<_Tp>::value, \"implementation bug\");\n      static_assert(is_unsigned<_Tp>::value, \"implementation bug\");\n\n      static constexpr char __digits[201] =\n\t\"0001020304050607080910111213141516171819\"\n\t\"2021222324252627282930313233343536373839\"\n\t\"4041424344454647484950515253545556575859\"\n\t\"6061626364656667686970717273747576777879\"\n\t\"8081828384858687888990919293949596979899\";\n      unsigned __pos = __len - 1;\n      while (__val >= 100)\n\t{\n\t  auto const __num = (__val % 100) * 2;\n\t  __val /= 100;\n\t  __first[__pos] = __digits[__num + 1];\n\t  __first[__pos - 1] = __digits[__num];\n\t  __pos -= 2;\n\t}\n      if (__val >= 10)\n\t{\n\t  auto const __num = __val * 2;\n\t  __first[1] = __digits[__num + 1];\n\t  __first[0] = __digits[__num];\n\t}\n      else\n\t__first[0] = '0' + __val;\n    }\n\n} // namespace __detail\n_GLIBCXX_END_NAMESPACE_VERSION\n} // namespace std\n#endif // C++11\n#endif // _GLIBCXX_CHARCONV_H\n"}],"crc32":1572460464,"timestamp":1702397466,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]