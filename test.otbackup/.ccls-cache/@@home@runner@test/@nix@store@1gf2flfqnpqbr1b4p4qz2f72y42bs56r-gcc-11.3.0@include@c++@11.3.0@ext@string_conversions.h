[{"ops":[{"insert":"// String Conversions -*- C++ -*-\n\n// Copyright (C) 2008-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file ext/string_conversions.h\n *  This file is a GNU extension to the Standard C++ Library.\n */\n\n#ifndef _STRING_CONVERSIONS_H\n#define _STRING_CONVERSIONS_H 1\n\n#pragma GCC system_header\n\n#if __cplusplus < 201103L\n# include <bits/c++0x_warning.h>\n#else\n\n#include <bits/c++config.h>\n#include <ext/numeric_traits.h>\n#include <bits/functexcept.h>\n#include <cstdlib>\n#include <cwchar>\n#include <cstdio>\n#include <cerrno>\n\nnamespace __gnu_cxx _GLIBCXX_VISIBILITY(default)\n{\n_GLIBCXX_BEGIN_NAMESPACE_VERSION\n\n  // Helper for all the sto* functions.\n  template<typename _TRet, typename _Ret = _TRet, typename _CharT,\n\t   typename... _Base>\n    _Ret\n    __stoa(_TRet (*__convf) (const _CharT*, _CharT**, _Base...),\n\t   const char* __name, const _CharT* __str, std::size_t* __idx,\n\t   _Base... __base)\n    {\n      _Ret __ret;\n\n      _CharT* __endptr;\n\n      struct _Save_errno {\n\t_Save_errno() : _M_errno(errno) { errno = 0; }\n\t~_Save_errno() { if (errno == 0) errno = _M_errno; }\n\tint _M_errno;\n      } const __save_errno;\n\n      struct _Range_chk {\n\t  static bool\n\t  _S_chk(_TRet, std::false_type) { return false; }\n\n\t  static bool\n\t  _S_chk(_TRet __val, std::true_type) // only called when _Ret is int\n\t  {\n\t    return __val < _TRet(__numeric_traits<int>::__min)\n\t      || __val > _TRet(__numeric_traits<int>::__max);\n\t  }\n      };\n\n      const _TRet __tmp = __convf(__str, &__endptr, __base...);\n\n      if (__endptr == __str)\n\tstd::__throw_invalid_argument(__name);\n      else if (errno == ERANGE\n\t  || _Range_chk::_S_chk(__tmp, std::is_same<_Ret, int>{}))\n\tstd::__throw_out_of_range(__name);\n      else\n\t__ret = __tmp;\n\n      if (__idx)\n\t*__idx = __endptr - __str;\n\n      return __ret;\n    }\n\n  // Helper for the to_string / to_wstring functions.\n  template<typename _String, typename _CharT = typename _String::value_type>\n    _String\n    __to_xstring(int (*__convf) (_CharT*, std::size_t, const _CharT*,\n\t\t\t\t __builtin_va_list), std::size_t __n,\n\t\t const _CharT* __fmt, ...)\n    {\n      // XXX Eventually the result should be constructed in-place in\n      // the __cxx11 string, likely with the help of internal hooks.\n      _CharT* __s = static_cast<_CharT*>(__builtin_alloca(sizeof(_CharT)\n\t\t\t\t\t\t\t  * __n));\n\n      __builtin_va_list __args;\n      __builtin_va_start(__args, __fmt);\n\n      const int __len = __convf(__s, __n, __fmt, __args);\n\n      __builtin_va_end(__args);\n\n      return _String(__s, __s + __len);\n    }\n\n_GLIBCXX_END_NAMESPACE_VERSION\n} // namespace\n\n#endif // C++11\n\n#endif // _STRING_CONVERSIONS_H\n"}],"crc32":1206194472,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]