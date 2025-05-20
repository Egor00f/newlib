/* asm/byteorder.h

   Copyright 1996, 1998, 2001 Red Hat, Inc.

This file is part of Cygwin.

This software is a copyrighted work licensed under the terms of the
Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
details. */

#ifndef _I386_BYTEORDER_H
#define _I386_BYTEORDER_H


#ifdef __cplusplus
extern "C" {
#endif

#if 0
#undef ntohl
#undef ntohs
#undef htonl
#undef htons
#endif

#if 1
#define ntohl(x) x
#define ntohs(x) x
#define htonl(x) x
#define htons(x) x

#endif

#ifdef __cplusplus
}
#endif

#endif
