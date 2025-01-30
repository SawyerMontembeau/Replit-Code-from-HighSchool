[{"ops":[{"insert":"// The  -*- C++ -*- type traits classes for internal use in libstdc++\n\n// Copyright (C) 2000-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file bits/cpp_type_traits.h\n *  This is an internal header file, included by other library headers.\n *  Do not attempt to use it directly. @headername{ext/type_traits}\n */\n\n// Written by Gabriel Dos Reis <dosreis@cmla.ens-cachan.fr>\n\n#ifndef _CPP_TYPE_TRAITS_H\n#define _CPP_TYPE_TRAITS_H 1\n\n#pragma GCC system_header\n\n#include <bits/c++config.h>\n\n//\n// This file provides some compile-time information about various types.\n// These representations were designed, on purpose, to be constant-expressions\n// and not types as found in <bits/type_traits.h>.  In particular, they\n// can be used in control structures and the optimizer hopefully will do\n// the obvious thing.\n//\n// Why integral expressions, and not functions nor types?\n// Firstly, these compile-time entities are used as template-arguments\n// so function return values won't work:  We need compile-time entities.\n// We're left with types and constant  integral expressions.\n// Secondly, from the point of view of ease of use, type-based compile-time\n// information is -not- *that* convenient.  One has to write lots of\n// overloaded functions and to hope that the compiler will select the right\n// one. As a net effect, the overall structure isn't very clear at first\n// glance.\n// Thirdly, partial ordering and overload resolution (of function templates)\n// is highly costly in terms of compiler-resource.  It is a Good Thing to\n// keep these resource consumption as least as possible.\n//\n// See valarray_array.h for a case use.\n//\n// -- Gaby (dosreis@cmla.ens-cachan.fr) 2000-03-06.\n//\n// Update 2005: types are also provided and <bits/type_traits.h> has been\n// removed.\n//\n\nextern \"C++\" {\n\nnamespace std _GLIBCXX_VISIBILITY(default)\n{\n_GLIBCXX_BEGIN_NAMESPACE_VERSION\n\n  struct __true_type { };\n  struct __false_type { };\n\n  template<bool>\n    struct __truth_type\n    { typedef __false_type __type; };\n\n  template<>\n    struct __truth_type<true>\n    { typedef __true_type __type; };\n\n  // N.B. The conversions to bool are needed due to the issue\n  // explained in c++/19404.\n  template<class _Sp, class _Tp>\n    struct __traitor\n    {\n      enum { __value = bool(_Sp::__value) || bool(_Tp::__value) };\n      typedef typename __truth_type<__value>::__type __type;\n    };\n\n  // Compare for equality of types.\n  template<typename, typename>\n    struct __are_same\n    {\n      enum { __value = 0 };\n      typedef __false_type __type;\n    };\n\n  template<typename _Tp>\n    struct __are_same<_Tp, _Tp>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  // Holds if the template-argument is a void type.\n  template<typename _Tp>\n    struct __is_void\n    {\n      enum { __value = 0 };\n      typedef __false_type __type;\n    };\n\n  template<>\n    struct __is_void<void>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  //\n  // Integer types\n  //\n  template<typename _Tp>\n    struct __is_integer\n    {\n      enum { __value = 0 };\n      typedef __false_type __type;\n    };\n\n  // Thirteen specializations (yes there are eleven standard integer\n  // types; <em>long long</em> and <em>unsigned long long</em> are\n  // supported as extensions).  Up to four target-specific __int<N>\n  // types are supported as well.\n  template<>\n    struct __is_integer<bool>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<char>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<signed char>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<unsigned char>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n# ifdef __WCHAR_TYPE__\n  template<>\n    struct __is_integer<wchar_t>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n# endif\n\n#ifdef _GLIBCXX_USE_CHAR8_T\n  template<>\n    struct __is_integer<char8_t>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n#endif\n\n#if __cplusplus >= 201103L\n  template<>\n    struct __is_integer<char16_t>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<char32_t>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n#endif\n\n  template<>\n    struct __is_integer<short>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<unsigned short>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<int>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<unsigned int>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<long>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<unsigned long>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<long long>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_integer<unsigned long long>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n#define __INT_N(TYPE) \t\t\t\\\n  template<>\t\t\t\t\\\n    struct __is_integer<TYPE>\t\t\\\n    {\t\t\t\t\t\\\n      enum { __value = 1 };\t\t\\\n      typedef __true_type __type;\t\\\n    };\t\t\t\t\t\\\n  template<>\t\t\t\t\\\n    struct __is_integer<unsigned TYPE>\t\\\n    {\t\t\t\t\t\\\n      enum { __value = 1 };\t\t\\\n      typedef __true_type __type;\t\\\n    };\n\n#ifdef __GLIBCXX_TYPE_INT_N_0\n__INT_N(__GLIBCXX_TYPE_INT_N_0)\n#endif\n#ifdef __GLIBCXX_TYPE_INT_N_1\n__INT_N(__GLIBCXX_TYPE_INT_N_1)\n#endif\n#ifdef __GLIBCXX_TYPE_INT_N_2\n__INT_N(__GLIBCXX_TYPE_INT_N_2)\n#endif\n#ifdef __GLIBCXX_TYPE_INT_N_3\n__INT_N(__GLIBCXX_TYPE_INT_N_3)\n#endif\n\n#undef __INT_N\n\n  //\n  // Floating point types\n  //\n  template<typename _Tp>\n    struct __is_floating\n    {\n      enum { __value = 0 };\n      typedef __false_type __type;\n    };\n\n  // three specializations (float, double and 'long double')\n  template<>\n    struct __is_floating<float>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_floating<double>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_floating<long double>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  //\n  // Pointer types\n  //\n  template<typename _Tp>\n    struct __is_pointer\n    {\n      enum { __value = 0 };\n      typedef __false_type __type;\n    };\n\n  template<typename _Tp>\n    struct __is_pointer<_Tp*>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  //\n  // An arithmetic type is an integer type or a floating point type\n  //\n  template<typename _Tp>\n    struct __is_arithmetic\n    : public __traitor<__is_integer<_Tp>, __is_floating<_Tp> >\n    { };\n\n  //\n  // A scalar type is an arithmetic type or a pointer type\n  // \n  template<typename _Tp>\n    struct __is_scalar\n    : public __traitor<__is_arithmetic<_Tp>, __is_pointer<_Tp> >\n    { };\n\n  //\n  // For use in std::copy and std::find overloads for streambuf iterators.\n  //\n  template<typename _Tp>\n    struct __is_char\n    {\n      enum { __value = 0 };\n      typedef __false_type __type;\n    };\n\n  template<>\n    struct __is_char<char>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n#ifdef __WCHAR_TYPE__\n  template<>\n    struct __is_char<wchar_t>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n#endif\n\n  template<typename _Tp>\n    struct __is_byte\n    {\n      enum { __value = 0 };\n      typedef __false_type __type;\n    };\n\n  template<>\n    struct __is_byte<char>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_byte<signed char>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n  template<>\n    struct __is_byte<unsigned char>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n\n#if __cplusplus >= 201703L\n  enum class byte : unsigned char;\n\n  template<>\n    struct __is_byte<byte>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n#endif // C++17\n\n#ifdef _GLIBCXX_USE_CHAR8_T\n  template<>\n    struct __is_byte<char8_t>\n    {\n      enum { __value = 1 };\n      typedef __true_type __type;\n    };\n#endif\n\n  template<typename> struct iterator_traits;\n\n  // A type that is safe for use with memcpy, memmove, memcmp etc.\n  template<typename _Tp>\n    struct __is_nonvolatile_trivially_copyable\n    {\n      enum { __value = __is_trivially_copyable(_Tp) };\n    };\n\n  // Cannot use memcpy/memmove/memcmp on volatile types even if they are\n  // trivially copyable, so ensure __memcpyable<volatile int*, volatile int*>\n  // and similar will be false.\n  template<typename _Tp>\n    struct __is_nonvolatile_trivially_copyable<volatile _Tp>\n    {\n      enum { __value = 0 };\n    };\n\n  // Whether two iterator types can be used with memcpy/memmove.\n  template<typename _OutputIter, typename _InputIter>\n    struct __memcpyable\n    {\n      enum { __value = 0 };\n    };\n\n  template<typename _Tp>\n    struct __memcpyable<_Tp*, _Tp*>\n    : __is_nonvolatile_trivially_copyable<_Tp>\n    { };\n\n  template<typename _Tp>\n    struct __memcpyable<_Tp*, const _Tp*>\n    : __is_nonvolatile_trivially_copyable<_Tp>\n    { };\n\n  // Whether two iterator types can be used with memcmp.\n  // This trait only says it's well-formed to use memcmp, not that it\n  // gives the right answer for a given algorithm. So for example, std::equal\n  // needs to add additional checks that the types are integers or pointers,\n  // because other trivially copyable types can overload operator==.\n  template<typename _Iter1, typename _Iter2>\n    struct __memcmpable\n    {\n      enum { __value = 0 };\n    };\n\n  // OK to use memcmp with pointers to trivially copyable types.\n  template<typename _Tp>\n    struct __memcmpable<_Tp*, _Tp*>\n    : __is_nonvolatile_trivially_copyable<_Tp>\n    { };\n\n  template<typename _Tp>\n    struct __memcmpable<const _Tp*, _Tp*>\n    : __is_nonvolatile_trivially_copyable<_Tp>\n    { };\n\n  template<typename _Tp>\n    struct __memcmpable<_Tp*, const _Tp*>\n    : __is_nonvolatile_trivially_copyable<_Tp>\n    { };\n\n  // Whether memcmp can be used to determine ordering for a type\n  // e.g. in std::lexicographical_compare or three-way comparisons.\n  // True for unsigned integer-like types where comparing each byte in turn\n  // as an unsigned char yields the right result. This is true for all\n  // unsigned integers on big endian targets, but only unsigned narrow\n  // character types (and std::byte) on little endian targets.\n  template<typename _Tp, bool _TreatAsBytes =\n#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__\n\t__is_integer<_Tp>::__value\n#else\n\t__is_byte<_Tp>::__value\n#endif\n    >\n    struct __is_memcmp_ordered\n    {\n      static const bool __value = _Tp(-1) > _Tp(1); // is unsigned\n    };\n\n  template<typename _Tp>\n    struct __is_memcmp_ordered<_Tp, false>\n    {\n      static const bool __value = false;\n    };\n\n  // Whether two types can be compared using memcmp.\n  template<typename _Tp, typename _Up, bool = sizeof(_Tp) == sizeof(_Up)>\n    struct __is_memcmp_ordered_with\n    {\n      static const bool __value = __is_memcmp_ordered<_Tp>::__value\n\t&& __is_memcmp_ordered<_Up>::__value;\n    };\n\n  template<typename _Tp, typename _Up>\n    struct __is_memcmp_ordered_with<_Tp, _Up, false>\n    {\n      static const bool __value = false;\n    };\n\n#if __cplusplus >= 201703L\n#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__\n  // std::byte is not an integer, but it can be compared using memcmp.\n  template<>\n    struct __is_memcmp_ordered<std::byte, false>\n    { static constexpr bool __value = true; };\n#endif\n\n  // std::byte can only be compared to itself, not to other types.\n  template<>\n    struct __is_memcmp_ordered_with<std::byte, std::byte, true>\n    { static constexpr bool __value = true; };\n\n  template<typename _Tp, bool _SameSize>\n    struct __is_memcmp_ordered_with<_Tp, std::byte, _SameSize>\n    { static constexpr bool __value = false; };\n\n  template<typename _Up, bool _SameSize>\n    struct __is_memcmp_ordered_with<std::byte, _Up, _SameSize>\n    { static constexpr bool __value = false; };\n#endif\n\n  //\n  // Move iterator type\n  //\n  template<typename _Tp>\n    struct __is_move_iterator\n    {\n      enum { __value = 0 };\n      typedef __false_type __type;\n    };\n\n  // Fallback implementation of the function in bits/stl_iterator.h used to\n  // remove the move_iterator wrapper.\n  template<typename _Iterator>\n    _GLIBCXX20_CONSTEXPR\n    inline _Iterator\n    __miter_base(_Iterator __it)\n    { return __it; }\n\n_GLIBCXX_END_NAMESPACE_VERSION\n} // namespace\n} // extern \"C++\"\n\n#endif //_CPP_TYPE_TRAITS_H\n"}],"crc32":1083784324,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]