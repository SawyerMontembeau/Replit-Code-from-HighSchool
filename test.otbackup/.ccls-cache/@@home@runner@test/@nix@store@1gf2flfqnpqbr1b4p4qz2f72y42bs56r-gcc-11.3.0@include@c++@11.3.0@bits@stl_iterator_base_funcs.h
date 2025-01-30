[{"ops":[{"insert":"// Functions used by iterators -*- C++ -*-\n\n// Copyright (C) 2001-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/*\n *\n * Copyright (c) 1994\n * Hewlett-Packard Company\n *\n * Permission to use, copy, modify, distribute and sell this software\n * and its documentation for any purpose is hereby granted without fee,\n * provided that the above copyright notice appear in all copies and\n * that both that copyright notice and this permission notice appear\n * in supporting documentation.  Hewlett-Packard Company makes no\n * representations about the suitability of this software for any\n * purpose.  It is provided \"as is\" without express or implied warranty.\n *\n *\n * Copyright (c) 1996-1998\n * Silicon Graphics Computer Systems, Inc.\n *\n * Permission to use, copy, modify, distribute and sell this software\n * and its documentation for any purpose is hereby granted without fee,\n * provided that the above copyright notice appear in all copies and\n * that both that copyright notice and this permission notice appear\n * in supporting documentation.  Silicon Graphics makes no\n * representations about the suitability of this software for any\n * purpose.  It is provided \"as is\" without express or implied warranty.\n */\n\n/** @file bits/stl_iterator_base_funcs.h\n *  This is an internal header file, included by other library headers.\n *  Do not attempt to use it directly. @headername{iterator}\n *\n *  This file contains all of the general iterator-related utility\n *  functions, such as distance() and advance().\n */\n\n#ifndef _STL_ITERATOR_BASE_FUNCS_H\n#define _STL_ITERATOR_BASE_FUNCS_H 1\n\n#pragma GCC system_header\n\n#include <bits/concept_check.h>\n#include <debug/assertions.h>\n\nnamespace std _GLIBCXX_VISIBILITY(default)\n{\n_GLIBCXX_BEGIN_NAMESPACE_VERSION\n\n_GLIBCXX_BEGIN_NAMESPACE_CONTAINER\n  // Forward declaration for the overloads of __distance.\n  template <typename> struct _List_iterator;\n  template <typename> struct _List_const_iterator;\n_GLIBCXX_END_NAMESPACE_CONTAINER\n\n  template<typename _InputIterator>\n    inline _GLIBCXX14_CONSTEXPR\n    typename iterator_traits<_InputIterator>::difference_type\n    __distance(_InputIterator __first, _InputIterator __last,\n               input_iterator_tag)\n    {\n      // concept requirements\n      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)\n\n      typename iterator_traits<_InputIterator>::difference_type __n = 0;\n      while (__first != __last)\n\t{\n\t  ++__first;\n\t  ++__n;\n\t}\n      return __n;\n    }\n\n  template<typename _RandomAccessIterator>\n    inline _GLIBCXX14_CONSTEXPR\n    typename iterator_traits<_RandomAccessIterator>::difference_type\n    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,\n               random_access_iterator_tag)\n    {\n      // concept requirements\n      __glibcxx_function_requires(_RandomAccessIteratorConcept<\n\t\t\t\t  _RandomAccessIterator>)\n      return __last - __first;\n    }\n\n#if _GLIBCXX_USE_CXX11_ABI\n  // Forward declaration because of the qualified call in distance.\n  template<typename _Tp>\n    ptrdiff_t\n    __distance(_GLIBCXX_STD_C::_List_iterator<_Tp>,\n\t       _GLIBCXX_STD_C::_List_iterator<_Tp>,\n\t       input_iterator_tag);\n\n  template<typename _Tp>\n    ptrdiff_t\n    __distance(_GLIBCXX_STD_C::_List_const_iterator<_Tp>,\n\t       _GLIBCXX_STD_C::_List_const_iterator<_Tp>,\n\t       input_iterator_tag);\n#endif\n\n  /**\n   *  @brief A generalization of pointer arithmetic.\n   *  @param  __first  An input iterator.\n   *  @param  __last  An input iterator.\n   *  @return  The distance between them.\n   *\n   *  Returns @c n such that __first + n == __last.  This requires\n   *  that @p __last must be reachable from @p __first.  Note that @c\n   *  n may be negative.\n   *\n   *  For random access iterators, this uses their @c + and @c - operations\n   *  and are constant time.  For other %iterator classes they are linear time.\n  */\n  template<typename _InputIterator>\n    inline _GLIBCXX17_CONSTEXPR\n    typename iterator_traits<_InputIterator>::difference_type\n    distance(_InputIterator __first, _InputIterator __last)\n    {\n      // concept requirements -- taken care of in __distance\n      return std::__distance(__first, __last,\n\t\t\t     std::__iterator_category(__first));\n    }\n\n  template<typename _InputIterator, typename _Distance>\n    inline _GLIBCXX14_CONSTEXPR void\n    __advance(_InputIterator& __i, _Distance __n, input_iterator_tag)\n    {\n      // concept requirements\n      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)\n      __glibcxx_assert(__n >= 0);\n      while (__n--)\n\t++__i;\n    }\n\n  template<typename _BidirectionalIterator, typename _Distance>\n    inline _GLIBCXX14_CONSTEXPR void\n    __advance(_BidirectionalIterator& __i, _Distance __n,\n\t      bidirectional_iterator_tag)\n    {\n      // concept requirements\n      __glibcxx_function_requires(_BidirectionalIteratorConcept<\n\t\t\t\t  _BidirectionalIterator>)\n      if (__n > 0)\n        while (__n--)\n\t  ++__i;\n      else\n        while (__n++)\n\t  --__i;\n    }\n\n  template<typename _RandomAccessIterator, typename _Distance>\n    inline _GLIBCXX14_CONSTEXPR void\n    __advance(_RandomAccessIterator& __i, _Distance __n,\n              random_access_iterator_tag)\n    {\n      // concept requirements\n      __glibcxx_function_requires(_RandomAccessIteratorConcept<\n\t\t\t\t  _RandomAccessIterator>)\n      if (__builtin_constant_p(__n) && __n == 1)\n\t++__i;\n      else if (__builtin_constant_p(__n) && __n == -1)\n\t--__i;\n      else\n\t__i += __n;\n    }\n\n  /**\n   *  @brief A generalization of pointer arithmetic.\n   *  @param  __i  An input iterator.\n   *  @param  __n  The @a delta by which to change @p __i.\n   *  @return  Nothing.\n   *\n   *  This increments @p i by @p n.  For bidirectional and random access\n   *  iterators, @p __n may be negative, in which case @p __i is decremented.\n   *\n   *  For random access iterators, this uses their @c + and @c - operations\n   *  and are constant time.  For other %iterator classes they are linear time.\n  */\n  template<typename _InputIterator, typename _Distance>\n    inline _GLIBCXX17_CONSTEXPR void\n    advance(_InputIterator& __i, _Distance __n)\n    {\n      // concept requirements -- taken care of in __advance\n      typename iterator_traits<_InputIterator>::difference_type __d = __n;\n      std::__advance(__i, __d, std::__iterator_category(__i));\n    }\n\n#if __cplusplus >= 201103L\n\n  template<typename _InputIterator>\n    inline _GLIBCXX17_CONSTEXPR _InputIterator\n    next(_InputIterator __x, typename\n\t iterator_traits<_InputIterator>::difference_type __n = 1)\n    {\n      // concept requirements\n      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)\n      std::advance(__x, __n);\n      return __x;\n    }\n\n  template<typename _BidirectionalIterator>\n    inline _GLIBCXX17_CONSTEXPR _BidirectionalIterator\n    prev(_BidirectionalIterator __x, typename\n\t iterator_traits<_BidirectionalIterator>::difference_type __n = 1) \n    {\n      // concept requirements\n      __glibcxx_function_requires(_BidirectionalIteratorConcept<\n\t\t\t\t  _BidirectionalIterator>)\n      std::advance(__x, -__n);\n      return __x;\n    }\n\n#endif // C++11\n\n_GLIBCXX_END_NAMESPACE_VERSION\n} // namespace\n\n#endif /* _STL_ITERATOR_BASE_FUNCS_H */\n"}],"crc32":596013513,"timestamp":1704214356,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]