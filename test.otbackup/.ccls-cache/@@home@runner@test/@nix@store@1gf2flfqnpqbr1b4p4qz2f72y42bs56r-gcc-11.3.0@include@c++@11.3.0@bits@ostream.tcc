[{"ops":[{"insert":"// ostream classes -*- C++ -*-\n\n// Copyright (C) 1997-2021 Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++ Library.  This library is free\n// software; you can redistribute it and/or modify it under the\n// terms of the GNU General Public License as published by the\n// Free Software Foundation; either version 3, or (at your option)\n// any later version.\n\n// This library is distributed in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General Public License for more details.\n\n// Under Section 7 of GPL version 3, you are granted additional\n// permissions described in the GCC Runtime Library Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n// You should have received a copy of the GNU General Public License and\n// a copy of the GCC Runtime Library Exception along with this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file bits/ostream.tcc\n *  This is an internal header file, included by other library headers.\n *  Do not attempt to use it directly. @headername{ostream}\n */\n\n//\n// ISO C++ 14882: 27.6.2  Output streams\n//\n\n#ifndef _OSTREAM_TCC\n#define _OSTREAM_TCC 1\n\n#pragma GCC system_header\n\n#include <bits/cxxabi_forced.h>\n\nnamespace std _GLIBCXX_VISIBILITY(default)\n{\n_GLIBCXX_BEGIN_NAMESPACE_VERSION\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>::sentry::\n    sentry(basic_ostream<_CharT, _Traits>& __os)\n    : _M_ok(false), _M_os(__os)\n    {\n      // XXX MT\n      if (__os.tie() && __os.good())\n\t__os.tie()->flush();\n\n      if (__os.good())\n\t_M_ok = true;\n      else\n\t__os.setstate(ios_base::failbit);\n    }\n\n  template<typename _CharT, typename _Traits>\n    template<typename _ValueT>\n      basic_ostream<_CharT, _Traits>&\n      basic_ostream<_CharT, _Traits>::\n      _M_insert(_ValueT __v)\n      {\n\tsentry __cerb(*this);\n\tif (__cerb)\n\t  {\n\t    ios_base::iostate __err = ios_base::goodbit;\n\t    __try\n\t      {\n\t\tconst __num_put_type& __np = __check_facet(this->_M_num_put);\n\t\tif (__np.put(*this, *this, this->fill(), __v).failed())\n\t\t  __err |= ios_base::badbit;\n\t      }\n\t    __catch(__cxxabiv1::__forced_unwind&)\n\t      {\n\t\tthis->_M_setstate(ios_base::badbit);\t\t\n\t\t__throw_exception_again;\n\t      }\n\t    __catch(...)\n\t      { this->_M_setstate(ios_base::badbit); }\n\t    if (__err)\n\t      this->setstate(__err);\n\t  }\n\treturn *this;\n      }\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    basic_ostream<_CharT, _Traits>::\n    operator<<(short __n)\n    {\n      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n      // 117. basic_ostream uses nonexistent num_put member functions.\n      const ios_base::fmtflags __fmt = this->flags() & ios_base::basefield;\n      if (__fmt == ios_base::oct || __fmt == ios_base::hex)\n\treturn _M_insert(static_cast<long>(static_cast<unsigned short>(__n)));\n      else\n\treturn _M_insert(static_cast<long>(__n));\n    }\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    basic_ostream<_CharT, _Traits>::\n    operator<<(int __n)\n    {\n      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n      // 117. basic_ostream uses nonexistent num_put member functions.\n      const ios_base::fmtflags __fmt = this->flags() & ios_base::basefield;\n      if (__fmt == ios_base::oct || __fmt == ios_base::hex)\n\treturn _M_insert(static_cast<long>(static_cast<unsigned int>(__n)));\n      else\n\treturn _M_insert(static_cast<long>(__n));\n    }\n  \n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    basic_ostream<_CharT, _Traits>::\n    operator<<(__streambuf_type* __sbin)\n    {\n      ios_base::iostate __err = ios_base::goodbit;\n      sentry __cerb(*this);\n      if (__cerb && __sbin)\n\t{\n\t  __try\n\t    {\n\t      if (!__copy_streambufs(__sbin, this->rdbuf()))\n\t\t__err |= ios_base::failbit;\n\t    }\n\t  __catch(__cxxabiv1::__forced_unwind&)\n\t    {\n\t      this->_M_setstate(ios_base::badbit);\t\t\n\t      __throw_exception_again;\n\t    }\n\t  __catch(...)\n\t    { this->_M_setstate(ios_base::failbit); }\n\t}\n      else if (!__sbin)\n\t__err |= ios_base::badbit;\n      if (__err)\n\tthis->setstate(__err);\n      return *this;\n    }\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    basic_ostream<_CharT, _Traits>::\n    put(char_type __c)\n    {\n      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n      // DR 60. What is a formatted input function?\n      // basic_ostream::put(char_type) is an unformatted output function.\n      // DR 63. Exception-handling policy for unformatted output.\n      // Unformatted output functions should catch exceptions thrown\n      // from streambuf members.\n      sentry __cerb(*this);\n      if (__cerb)\n\t{\n\t  ios_base::iostate __err = ios_base::goodbit;\n\t  __try\n\t    {\n\t      const int_type __put = this->rdbuf()->sputc(__c);\n\t      if (traits_type::eq_int_type(__put, traits_type::eof()))\n\t\t__err |= ios_base::badbit;\n\t    }\n\t  __catch(__cxxabiv1::__forced_unwind&)\n\t    {\n\t      this->_M_setstate(ios_base::badbit);\t\t\n\t      __throw_exception_again;\n\t    }\n\t  __catch(...)\n\t    { this->_M_setstate(ios_base::badbit); }\n\t  if (__err)\n\t    this->setstate(__err);\n\t}\n      return *this;\n    }\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    basic_ostream<_CharT, _Traits>::\n    write(const _CharT* __s, streamsize __n)\n    {\n      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n      // DR 60. What is a formatted input function?\n      // basic_ostream::write(const char_type*, streamsize) is an\n      // unformatted output function.\n      // DR 63. Exception-handling policy for unformatted output.\n      // Unformatted output functions should catch exceptions thrown\n      // from streambuf members.\n      sentry __cerb(*this);\n      if (__cerb)\n\t{\n\t  __try\n\t    { _M_write(__s, __n); }\n\t  __catch(__cxxabiv1::__forced_unwind&)\n\t    {\n\t      this->_M_setstate(ios_base::badbit);\t\t\n\t      __throw_exception_again;\n\t    }\n\t  __catch(...)\n\t    { this->_M_setstate(ios_base::badbit); }\n\t}\n      return *this;\n    }\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    basic_ostream<_CharT, _Traits>::\n    flush()\n    {\n      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n      // DR 60. What is a formatted input function?\n      // basic_ostream::flush() is *not* an unformatted output function.\n      ios_base::iostate __err = ios_base::goodbit;\n      __try\n\t{\n\t  if (this->rdbuf() && this->rdbuf()->pubsync() == -1)\n\t    __err |= ios_base::badbit;\n\t}\n      __catch(__cxxabiv1::__forced_unwind&)\n\t{\n\t  this->_M_setstate(ios_base::badbit);\t\t\n\t  __throw_exception_again;\n\t}\n      __catch(...)\n\t{ this->_M_setstate(ios_base::badbit); }\n      if (__err)\n\tthis->setstate(__err);\n      return *this;\n    }\n\n  template<typename _CharT, typename _Traits>\n    typename basic_ostream<_CharT, _Traits>::pos_type\n    basic_ostream<_CharT, _Traits>::\n    tellp()\n    {\n      pos_type __ret = pos_type(-1);\n      __try\n\t{\n\t  if (!this->fail())\n\t    __ret = this->rdbuf()->pubseekoff(0, ios_base::cur, ios_base::out);\n\t}\n      __catch(__cxxabiv1::__forced_unwind&)\n\t{\n\t  this->_M_setstate(ios_base::badbit);\t\t\n\t  __throw_exception_again;\n\t}\n      __catch(...)\n\t{ this->_M_setstate(ios_base::badbit); }\n      return __ret;\n    }\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    basic_ostream<_CharT, _Traits>::\n    seekp(pos_type __pos)\n    {\n      ios_base::iostate __err = ios_base::goodbit;\n      __try\n\t{\n\t  if (!this->fail())\n\t    {\n\t      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n\t      // 136.  seekp, seekg setting wrong streams?\n\t      const pos_type __p = this->rdbuf()->pubseekpos(__pos,\n\t\t\t\t\t\t\t     ios_base::out);\n\n\t      // 129. Need error indication from seekp() and seekg()\n\t      if (__p == pos_type(off_type(-1)))\n\t\t__err |= ios_base::failbit;\n\t    }\n\t}\n      __catch(__cxxabiv1::__forced_unwind&)\n\t{\n\t  this->_M_setstate(ios_base::badbit);\t\t\n\t  __throw_exception_again;\n\t}\n      __catch(...)\n\t{ this->_M_setstate(ios_base::badbit); }\n      if (__err)\n\tthis->setstate(__err);\n      return *this;\n    }\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    basic_ostream<_CharT, _Traits>::\n    seekp(off_type __off, ios_base::seekdir __dir)\n    {\n      ios_base::iostate __err = ios_base::goodbit;\n      __try\n\t{\n\t  if (!this->fail())\n\t    {\n\t      // _GLIBCXX_RESOLVE_LIB_DEFECTS\n\t      // 136.  seekp, seekg setting wrong streams?\n\t      const pos_type __p = this->rdbuf()->pubseekoff(__off, __dir,\n\t\t\t\t\t\t\t     ios_base::out);\n\n\t      // 129. Need error indication from seekp() and seekg()\n\t      if (__p == pos_type(off_type(-1)))\n\t\t__err |= ios_base::failbit;\n\t    }\n\t}\n      __catch(__cxxabiv1::__forced_unwind&)\n\t{\n\t  this->_M_setstate(ios_base::badbit);\t\t\n\t  __throw_exception_again;\n\t}\n      __catch(...)\n\t{ this->_M_setstate(ios_base::badbit); }\n      if (__err)\n\tthis->setstate(__err);\n      return *this;\n    }\n\n  template<typename _CharT, typename _Traits>\n    basic_ostream<_CharT, _Traits>&\n    operator<<(basic_ostream<_CharT, _Traits>& __out, const char* __s)\n    {\n      if (!__s)\n\t__out.setstate(ios_base::badbit);\n      else\n\t{\n\t  // _GLIBCXX_RESOLVE_LIB_DEFECTS\n\t  // 167.  Improper use of traits_type::length()\n\t  const size_t __clen = char_traits<char>::length(__s);\n\t  __try\n\t    {\n\t      struct __ptr_guard\n\t      {\n\t\t_CharT *__p;\n\t\t__ptr_guard (_CharT *__ip): __p(__ip) { }\n\t\t~__ptr_guard() { delete[] __p; }\n\t\t_CharT* __get() { return __p; }\n\t      } __pg (new _CharT[__clen]);\n\n\t      _CharT *__ws = __pg.__get();\n\t      for (size_t  __i = 0; __i < __clen; ++__i)\n\t\t__ws[__i] = __out.widen(__s[__i]);\n\t      __ostream_insert(__out, __ws, __clen);\n\t    }\n\t  __catch(__cxxabiv1::__forced_unwind&)\n\t    {\n\t      __out._M_setstate(ios_base::badbit);\n\t      __throw_exception_again;\n\t    }\n\t  __catch(...)\n\t    { __out._M_setstate(ios_base::badbit); }\n\t}\n      return __out;\n    }\n\n  // Inhibit implicit instantiations for required instantiations,\n  // which are defined via explicit instantiations elsewhere.\n#if _GLIBCXX_EXTERN_TEMPLATE\n  extern template class basic_ostream<char>;\n  extern template ostream& endl(ostream&);\n  extern template ostream& ends(ostream&);\n  extern template ostream& flush(ostream&);\n  extern template ostream& operator<<(ostream&, char);\n  extern template ostream& operator<<(ostream&, unsigned char);\n  extern template ostream& operator<<(ostream&, signed char);\n  extern template ostream& operator<<(ostream&, const char*);\n  extern template ostream& operator<<(ostream&, const unsigned char*);\n  extern template ostream& operator<<(ostream&, const signed char*);\n\n  extern template ostream& ostream::_M_insert(long);\n  extern template ostream& ostream::_M_insert(unsigned long);\n  extern template ostream& ostream::_M_insert(bool);\n#ifdef _GLIBCXX_USE_LONG_LONG\n  extern template ostream& ostream::_M_insert(long long);\n  extern template ostream& ostream::_M_insert(unsigned long long);\n#endif\n  extern template ostream& ostream::_M_insert(double);\n  extern template ostream& ostream::_M_insert(long double);\n  extern template ostream& ostream::_M_insert(const void*);\n\n#ifdef _GLIBCXX_USE_WCHAR_T\n  extern template class basic_ostream<wchar_t>;\n  extern template wostream& endl(wostream&);\n  extern template wostream& ends(wostream&);\n  extern template wostream& flush(wostream&);\n  extern template wostream& operator<<(wostream&, wchar_t);\n  extern template wostream& operator<<(wostream&, char);\n  extern template wostream& operator<<(wostream&, const wchar_t*);\n  extern template wostream& operator<<(wostream&, const char*);\n\n  extern template wostream& wostream::_M_insert(long);\n  extern template wostream& wostream::_M_insert(unsigned long);\n  extern template wostream& wostream::_M_insert(bool);\n#ifdef _GLIBCXX_USE_LONG_LONG\n  extern template wostream& wostream::_M_insert(long long);\n  extern template wostream& wostream::_M_insert(unsigned long long);\n#endif\n  extern template wostream& wostream::_M_insert(double);\n  extern template wostream& wostream::_M_insert(long double);\n  extern template wostream& wostream::_M_insert(const void*);\n#endif\n#endif\n\n_GLIBCXX_END_NAMESPACE_VERSION\n} // namespace std\n\n#endif\n"}],"crc32":2840239605,"timestamp":1704214355,"tsString":"2024-01-02 16:52:28.0 +00:00:00","version":1}]