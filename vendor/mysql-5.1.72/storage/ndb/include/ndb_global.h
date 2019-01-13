/* Copyright (c) 2003-2007 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA */

#ifndef NDB_GLOBAL_H
#define NDB_GLOBAL_H

#include <my_config.h>
#include <ndb_types.h>

#define NDB_PORT "1186"
#define NDB_TCP_BASE_PORT "@ndb_port_base@"

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(WIN32)
#define NDB_WIN32
#include <winsock2.h>
#define PATH_MAX 256
#define DIR_SEPARATOR "\\"
#define MYSQLCLUSTERDIR "c:\\mysql\\mysql-cluster"
#define HAVE_STRCASECMP
#define strcasecmp _strcmpi
#pragma warning(disable: 4503 4786)
#else
#undef NDB_WIN32
#define DIR_SEPARATOR "/"
#endif

#include <my_global.h>

#if ! (NDB_SIZEOF_CHAR == SIZEOF_CHAR)
#error "Invalid define for Uint8"
#endif

#if ! (NDB_SIZEOF_INT == SIZEOF_INT)
#error "Invalid define for Uint32"
#endif

#if ! (NDB_SIZEOF_LONG_LONG == SIZEOF_LONG_LONG)
#error "Invalid define for Uint64"
#endif

#include <my_alarm.h>

#ifdef _AIX
#undef _H_STRINGS
#endif
#include <m_string.h>
#include <m_ctype.h>
#include <ctype.h>

#ifdef HAVE_STDARG_H
#include <stdarg.h>
#endif

#ifdef TIME_WITH_SYS_TIME
#include <time.h>
#endif

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#ifdef HAVE_SYS_STAT_H
  #if defined(__cplusplus) && defined(_APP32_64BIT_OFF_T) && defined(_INCLUDE_AES_SOURCE)
    #undef _INCLUDE_AES_SOURCE
    #include <sys/stat.h>
    #define _INCLUDE_AES_SOURCE
  #else
    #include <sys/stat.h>
  #endif
#endif

#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif

#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

#ifdef HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif

#ifndef HAVE_STRDUP
extern char * strdup(const char *s);
#endif

#ifndef HAVE_STRCASECMP
extern int strcasecmp(const char *s1, const char *s2);
extern int strncasecmp(const char *s1, const char *s2, size_t n);
#endif

static const char table_name_separator =  '/';

#if defined(_AIX) || defined(WIN32) || defined(NDB_VC98)
#define STATIC_CONST(x) enum { x }
#else
#define STATIC_CONST(x) static const Uint32 x
#endif

#ifdef  __cplusplus
extern "C" {
#endif
	
#include <assert.h>

#ifdef  __cplusplus
}
#endif

#include "ndb_init.h"

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

#if defined(_lint) || defined(FORCE_INIT_OF_VARS)
#define LINT_SET_PTR = {0,0}
#else
#define LINT_SET_PTR
#endif

#ifndef MIN
#define MIN(x,y) (((x)<(y))?(x):(y))
#endif

#ifndef MAX
#define MAX(x,y) (((x)>(y))?(x):(y))
#endif

#define NDB_O_DIRECT_WRITE_ALIGNMENT 512

#endif
