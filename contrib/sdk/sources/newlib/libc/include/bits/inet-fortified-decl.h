/* Declarations of checking macros for inet functions.
   Copyright (C) 2025 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_INET_FORTIFIED_DEC_H
#define _BITS_INET_FORTIFIED_DEC_H 1

#ifndef _ARPA_INET_H
# error "Never include <bits/inet-fortified-decl.h> directly; use <arpa/inet.h> instead."
#endif

const char* __inet_ntop_chk(int, const void*, char*, socklen_t, size_t);

int __inet_pton_chk(int, const char*, void*, size_t);

#endif /* bits/inet-fortified-decl.h.  */