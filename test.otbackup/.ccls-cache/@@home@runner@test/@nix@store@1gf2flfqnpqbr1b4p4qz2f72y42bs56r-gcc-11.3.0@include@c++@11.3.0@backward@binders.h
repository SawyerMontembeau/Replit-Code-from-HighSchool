[{"ops":[{"insert":"// Functor implementations -*- C++ -*-\n\n// Copyright (C) 2001-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/*\n *\n * Copyright (c) 1994\n * Hewlett-Packard Company\n *\n * Permission to use, copy, modify, distribute and sell this software\n * and its documentation for any purpose is hereby granted without fee,\n * provided that the above copyright notice appear in all copies and\n * that both that copyright notice and this permission notice appear\n * in supporting documentation.  Hewlett-Packard Company makes no\n * representations about the suitability of this software for any\n * purpose.  It is provided \"as is\" without express or implied warranty.\n *\n *\n * Copyright (c) 1996-1998\n * Silicon Graphics Computer Systems, Inc.\n *\n * Permission to use, copy, modify, distribute and sell this software\n * and its documentation for any purpose is hereby granted without fee,\n * provided that the above copyright notice appear in all copies and\n * that both that copyright notice and this permission notice appear\n * in supporting documentation.  Silicon Graphics makes no\n * representations about the suitability of this software for any\n * purpose.  It is provided \"as is\" without express or implied warranty.\n */\n\n/** @file backward/binders.h\n *  This is an internal header file, included by other library headers.\n *  Do not attempt to use it directly. @headername{functional}\n */\n\n#ifndef _BACKWARD_BINDERS_H\n#define _BACKWARD_BINDERS_H 1\n\n// Suppress deprecated warning for this file.\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored \"-Wdeprecated-declarations\"\n\nnamespace std _GLIBCXX_VISIBILITY(default)\n{\n_GLIBCXX_BEGIN_NAMESPACE_VERSION\n\n  // 20.3.6 binders\n  /** @defgroup binders Binder Classes\n   * @ingroup functors\n   *\n   *  Binders turn functions/functors with two arguments into functors\n   *  with a single argument, storing an argument to be applied later.\n   *  For example, a variable @c B of type @c binder1st is constructed\n   *  from a functor @c f and an argument @c x. Later, B's @c\n   *  operator() is called with a single argument @c y. The return\n   *  value is the value of @c f(x,y). @c B can be @a called with\n   *  various arguments (y1, y2, ...) and will in turn call @c\n   *  f(x,y1), @c f(x,y2), ...\n   *\n   *  The function @c bind1st is provided to save some typing. It takes the\n   *  function and an argument as parameters, and returns an instance of\n   *  @c binder1st.\n   *\n   *  The type @c binder2nd and its creator function @c bind2nd do the same\n   *  thing, but the stored argument is passed as the second parameter instead\n   *  of the first, e.g., @c bind2nd(std::minus<float>(),1.3) will create a\n   *  functor whose @c operator() accepts a floating-point number, subtracts\n   *  1.3 from it, and returns the result. (If @c bind1st had been used,\n   *  the functor would perform <em>1.3 - x</em> instead.\n   *\n   *  Creator-wrapper functions like @c bind1st are intended to be used in\n   *  calling algorithms. Their return values will be temporary objects.\n   *  (The goal is to not require you to type names like\n   *  @c std::binder1st<std::plus<int>> for declaring a variable to hold the\n   *  return value from @c bind1st(std::plus<int>(),5).\n   *\n   *  These become more useful when combined with the composition functions.\n   *\n   *  These functions are deprecated in C++11 and can be replaced by\n   *  @c std::bind (or @c std::tr1::bind) which is more powerful and flexible,\n   *  supporting functions with any number of arguments.  Uses of @c bind1st\n   *  can be replaced by @c std::bind(f, x, std::placeholders::_1) and\n   *  @c bind2nd by @c std::bind(f, std::placeholders::_1, x).\n   *  @{\n   */\n  /// One of the @link binders binder functors@endlink.\n  template<typename _Operation>\n    class binder1st\n    : public unary_function<typename _Operation::second_argument_type,\n\t\t\t    typename _Operation::result_type>\n    {\n    protected:\n      _Operation op;\n      typename _Operation::first_argument_type value;\n\n    public:\n      binder1st(const _Operation& __x,\n\t\tconst typename _Operation::first_argument_type& __y)\n      : op(__x), value(__y) { }\n\n      typename _Operation::result_type\n      operator()(const typename _Operation::second_argument_type& __x) const\n      { return op(value, __x); }\n\n      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n      // 109.  Missing binders for non-const sequence elements\n      typename _Operation::result_type\n      operator()(typename _Operation::second_argument_type& __x) const\n      { return op(value, __x); }\n    } _GLIBCXX11_DEPRECATED_SUGGEST(\"std::bind\");\n\n  /// One of the @link binders binder functors@endlink.\n  template<typename _Operation, typename _Tp>\n    inline binder1st<_Operation>\n    bind1st(const _Operation& __fn, const _Tp& __x)\n    {\n      typedef typename _Operation::first_argument_type _Arg1_type;\n      return binder1st<_Operation>(__fn, _Arg1_type(__x));\n    }\n\n  /// One of the @link binders binder functors@endlink.\n  template<typename _Operation>\n    class binder2nd\n    : public unary_function<typename _Operation::first_argument_type,\n\t\t\t    typename _Operation::result_type>\n    {\n    protected:\n      _Operation op;\n      typename _Operation::second_argument_type value;\n\n    public:\n      binder2nd(const _Operation& __x,\n\t\tconst typename _Operation::second_argument_type& __y)\n      : op(__x), value(__y) { }\n\n      typename _Operation::result_type\n      operator()(const typename _Operation::first_argument_type& __x) const\n      { return op(__x, value); }\n\n      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n      // 109.  Missing binders for non-const sequence elements\n      typename _Operation::result_type\n      operator()(typename _Operation::first_argument_type& __x) const\n      { return op(__x, value); }\n    } _GLIBCXX11_DEPRECATED_SUGGEST(\"std::bind\");\n\n  /// One of the @link binders binder functors@endlink.\n  template<typename _Operation, typename _Tp>\n    inline binder2nd<_Operation>\n    bind2nd(const _Operation& __fn, const _Tp& __x)\n    {\n      typedef typename _Operation::second_argument_type _Arg2_type;\n      return binder2nd<_Operation>(__fn, _Arg2_type(__x));\n    } \n  /** @}  */\n\n_GLIBCXX_END_NAMESPACE_VERSION\n} // namespace\n\n#pragma GCC diagnostic pop\n\n#endif /* _BACKWARD_BINDERS_H */\n"}],"crc32":251668746,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]