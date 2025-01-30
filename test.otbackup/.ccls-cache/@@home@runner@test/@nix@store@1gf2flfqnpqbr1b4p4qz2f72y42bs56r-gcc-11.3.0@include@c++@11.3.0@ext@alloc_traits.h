[{"ops":[{"insert":"// Allocator traits -*- C++ -*-\n\n// Copyright (C) 2011-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file ext/alloc_traits.h\n *  This file is a GNU extension to the Standard C++ Library.\n */\n\n#ifndef _EXT_ALLOC_TRAITS_H\n#define _EXT_ALLOC_TRAITS_H 1\n\n#pragma GCC system_header\n\n# include <bits/alloc_traits.h>\n#if __cplusplus < 201103L\n# include <bits/allocator.h>  // for __alloc_swap\n#endif\n\nnamespace __gnu_cxx _GLIBCXX_VISIBILITY(default)\n{\n_GLIBCXX_BEGIN_NAMESPACE_VERSION\n\n/**\n * @brief  Uniform interface to C++98 and C++11 allocators.\n * @ingroup allocators\n*/\ntemplate<typename _Alloc, typename = typename _Alloc::value_type>\n  struct __alloc_traits\n#if __cplusplus >= 201103L\n  : std::allocator_traits<_Alloc>\n#endif\n  {\n    typedef _Alloc allocator_type;\n#if __cplusplus >= 201103L\n    typedef std::allocator_traits<_Alloc>           _Base_type;\n    typedef typename _Base_type::value_type         value_type;\n    typedef typename _Base_type::pointer            pointer;\n    typedef typename _Base_type::const_pointer      const_pointer;\n    typedef typename _Base_type::size_type          size_type;\n    typedef typename _Base_type::difference_type    difference_type;\n    // C++11 allocators do not define reference or const_reference\n    typedef value_type&                             reference;\n    typedef const value_type&                       const_reference;\n    using _Base_type::allocate;\n    using _Base_type::deallocate;\n    using _Base_type::construct;\n    using _Base_type::destroy;\n    using _Base_type::max_size;\n\n  private:\n    template<typename _Ptr>\n      using __is_custom_pointer\n\t= std::__and_<std::is_same<pointer, _Ptr>,\n\t\t      std::__not_<std::is_pointer<_Ptr>>>;\n\n  public:\n    // overload construct for non-standard pointer types\n    template<typename _Ptr, typename... _Args>\n      static _GLIBCXX14_CONSTEXPR\n      std::__enable_if_t<__is_custom_pointer<_Ptr>::value>\n      construct(_Alloc& __a, _Ptr __p, _Args&&... __args)\n      noexcept(noexcept(_Base_type::construct(__a, std::__to_address(__p),\n\t\t\t\t\t      std::forward<_Args>(__args)...)))\n      {\n\t_Base_type::construct(__a, std::__to_address(__p),\n\t\t\t      std::forward<_Args>(__args)...);\n      }\n\n    // overload destroy for non-standard pointer types\n    template<typename _Ptr>\n      static _GLIBCXX14_CONSTEXPR\n      std::__enable_if_t<__is_custom_pointer<_Ptr>::value>\n      destroy(_Alloc& __a, _Ptr __p)\n      noexcept(noexcept(_Base_type::destroy(__a, std::__to_address(__p))))\n      { _Base_type::destroy(__a, std::__to_address(__p)); }\n\n    static constexpr _Alloc _S_select_on_copy(const _Alloc& __a)\n    { return _Base_type::select_on_container_copy_construction(__a); }\n\n    static _GLIBCXX14_CONSTEXPR void _S_on_swap(_Alloc& __a, _Alloc& __b)\n    { std::__alloc_on_swap(__a, __b); }\n\n    static constexpr bool _S_propagate_on_copy_assign()\n    { return _Base_type::propagate_on_container_copy_assignment::value; }\n\n    static constexpr bool _S_propagate_on_move_assign()\n    { return _Base_type::propagate_on_container_move_assignment::value; }\n\n    static constexpr bool _S_propagate_on_swap()\n    { return _Base_type::propagate_on_container_swap::value; }\n\n    static constexpr bool _S_always_equal()\n    { return _Base_type::is_always_equal::value; }\n\n    static constexpr bool _S_nothrow_move()\n    { return _S_propagate_on_move_assign() || _S_always_equal(); }\n\n    template<typename _Tp>\n      struct rebind\n      { typedef typename _Base_type::template rebind_alloc<_Tp> other; };\n#else // ! C++11\n\n    typedef typename _Alloc::pointer                pointer;\n    typedef typename _Alloc::const_pointer          const_pointer;\n    typedef typename _Alloc::value_type             value_type;\n    typedef typename _Alloc::reference              reference;\n    typedef typename _Alloc::const_reference        const_reference;\n    typedef typename _Alloc::size_type              size_type;\n    typedef typename _Alloc::difference_type        difference_type;\n\n    _GLIBCXX_NODISCARD static pointer\n    allocate(_Alloc& __a, size_type __n)\n    { return __a.allocate(__n); }\n\n    template<typename _Hint>\n      _GLIBCXX_NODISCARD static pointer\n      allocate(_Alloc& __a, size_type __n, _Hint __hint)\n      { return __a.allocate(__n, __hint); }\n\n    static void deallocate(_Alloc& __a, pointer __p, size_type __n)\n    { __a.deallocate(__p, __n); }\n\n    template<typename _Tp>\n      static void construct(_Alloc& __a, pointer __p, const _Tp& __arg)\n      { __a.construct(__p, __arg); }\n\n    static void destroy(_Alloc& __a, pointer __p)\n    { __a.destroy(__p); }\n\n    static size_type max_size(const _Alloc& __a)\n    { return __a.max_size(); }\n\n    static const _Alloc& _S_select_on_copy(const _Alloc& __a) { return __a; }\n\n    static void _S_on_swap(_Alloc& __a, _Alloc& __b)\n    {\n      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n      // 431. Swapping containers with unequal allocators.\n      std::__alloc_swap<_Alloc>::_S_do_it(__a, __b);\n    }\n\n    template<typename _Tp>\n      struct rebind\n      { typedef typename _Alloc::template rebind<_Tp>::other other; };\n#endif // C++11\n  };\n\n_GLIBCXX_END_NAMESPACE_VERSION\n} // namespace __gnu_cxx\n\n#endif\n"}],"crc32":3077546761,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]