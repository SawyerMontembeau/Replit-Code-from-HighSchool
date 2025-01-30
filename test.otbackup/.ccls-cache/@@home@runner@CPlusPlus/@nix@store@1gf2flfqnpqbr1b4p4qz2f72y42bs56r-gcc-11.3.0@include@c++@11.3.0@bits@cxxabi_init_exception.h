[{"ops":[{"insert":"// ABI Support -*- C++ -*-\n\n// Copyright (C) 2016-2021 Free Software Foundation, Inc.\n//\n// This file is part of GCC.\n//\n// GCC is free software; you can redistribute it and/or modify\n// it under the terms of the GNU General Public License as published by\n// the Free Software Foundation; either version 3, or (at your option)\n// any later version.\n//\n// GCC is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n//\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file bits/cxxabi_init_exception.h\n *  This is an internal header file, included by other library headers.\n *  Do not attempt to use it directly.\n */\n\n#ifndef _CXXABI_INIT_EXCEPTION_H\n#define _CXXABI_INIT_EXCEPTION_H 1\n\n#pragma GCC system_header\n\n#pragma GCC visibility push(default)\n\n#include <stddef.h>\n#include <bits/c++config.h>\n\n#ifndef _GLIBCXX_CDTOR_CALLABI\n#define _GLIBCXX_CDTOR_CALLABI\n#define _GLIBCXX_HAVE_CDTOR_CALLABI 0\n#else\n#define _GLIBCXX_HAVE_CDTOR_CALLABI 1\n#endif\n\n#ifdef __cplusplus\n\nnamespace std\n{\n  class type_info;\n}\n\nnamespace __cxxabiv1\n{\n  struct __cxa_refcounted_exception;\n\n  extern \"C\"\n    {\n      // Allocate memory for the primary exception plus the thrown object.\n      void*\n      __cxa_allocate_exception(size_t) _GLIBCXX_NOTHROW;\n\n      void\n      __cxa_free_exception(void*) _GLIBCXX_NOTHROW;\n\n      // Initialize exception (this is a GNU extension)\n      __cxa_refcounted_exception*\n      __cxa_init_primary_exception(void *object, std::type_info *tinfo,\n                void (_GLIBCXX_CDTOR_CALLABI *dest) (void *)) _GLIBCXX_NOTHROW;\n\n    }\n} // namespace __cxxabiv1\n\n#endif\n\n#pragma GCC visibility pop\n\n#endif // _CXXABI_INIT_EXCEPTION_H\n"}],"crc32":2532306513,"timestamp":1702397466,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]