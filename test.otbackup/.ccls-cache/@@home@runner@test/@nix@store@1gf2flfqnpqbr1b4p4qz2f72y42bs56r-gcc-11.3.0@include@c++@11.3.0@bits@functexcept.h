[{"ops":[{"insert":"// Function-Based Exception Support -*- C++ -*-\n\n// Copyright (C) 2001-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file bits/functexcept.h\n *  This is an internal header file, included by other library headers.\n *  Do not attempt to use it directly. @headername{exception}\n *\n *  This header provides support for -fno-exceptions.\n */\n\n//\n// ISO C++ 14882: 19.1  Exception classes\n//\n\n#ifndef _FUNCTEXCEPT_H\n#define _FUNCTEXCEPT_H 1\n\n#include <bits/c++config.h>\n#include <bits/exception_defines.h>\n\nnamespace std _GLIBCXX_VISIBILITY(default)\n{\n_GLIBCXX_BEGIN_NAMESPACE_VERSION\n\n  // Helper for exception objects in <except>\n  void\n  __throw_bad_exception(void) __attribute__((__noreturn__));\n\n  // Helper for exception objects in <new>\n  void\n  __throw_bad_alloc(void) __attribute__((__noreturn__));\n\n  void\n  __throw_bad_array_new_length(void) __attribute__((__noreturn__));\n\n  // Helper for exception objects in <typeinfo>\n  void\n  __throw_bad_cast(void) __attribute__((__noreturn__));\n\n  void\n  __throw_bad_typeid(void) __attribute__((__noreturn__));\n\n  // Helpers for exception objects in <stdexcept>\n  void\n  __throw_logic_error(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_domain_error(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_invalid_argument(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_length_error(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_out_of_range(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_out_of_range_fmt(const char*, ...) __attribute__((__noreturn__))\n    __attribute__((__format__(__gnu_printf__, 1, 2)));\n\n  void\n  __throw_runtime_error(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_range_error(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_overflow_error(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_underflow_error(const char*) __attribute__((__noreturn__));\n\n  // Helpers for exception objects in <ios>\n  void\n  __throw_ios_failure(const char*) __attribute__((__noreturn__));\n\n  void\n  __throw_ios_failure(const char*, int) __attribute__((__noreturn__));\n\n  // Helpers for exception objects in <system_error>\n  void\n  __throw_system_error(int) __attribute__((__noreturn__));\n\n  // Helpers for exception objects in <future>\n  void\n  __throw_future_error(int) __attribute__((__noreturn__));\n\n  // Helpers for exception objects in <functional>\n  void\n  __throw_bad_function_call() __attribute__((__noreturn__));\n\n_GLIBCXX_END_NAMESPACE_VERSION\n} // namespace\n\n#endif\n"}],"crc32":2139444538,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]