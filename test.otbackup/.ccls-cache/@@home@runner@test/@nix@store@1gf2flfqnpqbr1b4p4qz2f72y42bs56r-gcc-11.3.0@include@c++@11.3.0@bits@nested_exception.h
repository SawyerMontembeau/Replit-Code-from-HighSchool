[{"ops":[{"insert":"// Nested Exception support header (nested_exception class) for -*- C++ -*-\n\n// Copyright (C) 2009-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file bits/nested_exception.h\n *  This is an internal header file, included by other library headers.\n *  Do not attempt to use it directly. @headername{exception}\n */\n\n#ifndef _GLIBCXX_NESTED_EXCEPTION_H\n#define _GLIBCXX_NESTED_EXCEPTION_H 1\n\n#pragma GCC visibility push(default)\n\n#if __cplusplus < 201103L\n# include <bits/c++0x_warning.h>\n#else\n\n#include <bits/c++config.h>\n#include <bits/move.h>\n\nextern \"C++\" {\n\nnamespace std\n{\n  /**\n   * @addtogroup exceptions\n   * @{\n   */\n\n  /// Exception class with exception_ptr data member.\n  class nested_exception\n  {\n    exception_ptr _M_ptr;\n\n  public:\n    nested_exception() noexcept : _M_ptr(current_exception()) { }\n\n    nested_exception(const nested_exception&) noexcept = default;\n\n    nested_exception& operator=(const nested_exception&) noexcept = default;\n\n    virtual ~nested_exception() noexcept;\n\n    [[noreturn]]\n    void\n    rethrow_nested() const\n    {\n      if (_M_ptr)\n\trethrow_exception(_M_ptr);\n      std::terminate();\n    }\n\n    exception_ptr\n    nested_ptr() const noexcept\n    { return _M_ptr; }\n  };\n\n  /// @cond undocumented\n\n  template<typename _Except>\n    struct _Nested_exception : public _Except, public nested_exception\n    {\n      explicit _Nested_exception(const _Except& __ex)\n      : _Except(__ex)\n      { }\n\n      explicit _Nested_exception(_Except&& __ex)\n      : _Except(static_cast<_Except&&>(__ex))\n      { }\n    };\n\n  // [except.nested]/8\n  // Throw an exception of unspecified type that is publicly derived from\n  // both remove_reference_t<_Tp> and nested_exception.\n  template<typename _Tp>\n    [[noreturn]]\n    inline void\n    __throw_with_nested_impl(_Tp&& __t, true_type)\n    {\n      using _Up = typename remove_reference<_Tp>::type;\n      throw _Nested_exception<_Up>{std::forward<_Tp>(__t)};\n    }\n\n  template<typename _Tp>\n    [[noreturn]]\n    inline void\n    __throw_with_nested_impl(_Tp&& __t, false_type)\n    { throw std::forward<_Tp>(__t); }\n\n  /// @endcond\n\n  /// If @p __t is derived from nested_exception, throws @p __t.\n  /// Else, throws an implementation-defined object derived from both.\n  template<typename _Tp>\n    [[noreturn]]\n    inline void\n    throw_with_nested(_Tp&& __t)\n    {\n      using _Up = typename decay<_Tp>::type;\n      using _CopyConstructible\n\t= __and_<is_copy_constructible<_Up>, is_move_constructible<_Up>>;\n      static_assert(_CopyConstructible::value,\n\t  \"throw_with_nested argument must be CopyConstructible\");\n      using __nest = __and_<is_class<_Up>, __bool_constant<!__is_final(_Up)>,\n\t\t\t    __not_<is_base_of<nested_exception, _Up>>>;\n      std::__throw_with_nested_impl(std::forward<_Tp>(__t), __nest{});\n    }\n\n  /// @cond undocumented\n\n  // Determine if dynamic_cast<const nested_exception&> would be well-formed.\n  template<typename _Tp>\n    using __rethrow_if_nested_cond = typename enable_if<\n      __and_<is_polymorphic<_Tp>,\n\t     __or_<__not_<is_base_of<nested_exception, _Tp>>,\n\t\t   is_convertible<_Tp*, nested_exception*>>>::value\n    >::type;\n\n  // Attempt dynamic_cast to nested_exception and call rethrow_nested().\n  template<typename _Ex>\n    inline __rethrow_if_nested_cond<_Ex>\n    __rethrow_if_nested_impl(const _Ex* __ptr)\n    {\n      if (auto __ne_ptr = dynamic_cast<const nested_exception*>(__ptr))\n\t__ne_ptr->rethrow_nested();\n    }\n\n  // Otherwise, no effects.\n  inline void\n  __rethrow_if_nested_impl(const void*)\n  { }\n\n  /// @endcond\n\n  /// If @p __ex is derived from nested_exception, @p __ex.rethrow_nested().\n  template<typename _Ex>\n    inline void\n    rethrow_if_nested(const _Ex& __ex)\n    { std::__rethrow_if_nested_impl(std::__addressof(__ex)); }\n\n  /// @} group exceptions\n} // namespace std\n\n} // extern \"C++\"\n\n#endif // C++11\n\n#pragma GCC visibility pop\n\n#endif // _GLIBCXX_NESTED_EXCEPTION_H\n"}],"crc32":1153634949,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]