#include <config.h>
#include <stdio.h>
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

int main(int argc, char **argv)
{
puts("/* This is an OS dependent, generated file */");
puts("\n");
puts("#ifndef __ROKEN_H__");
puts("#define __ROKEN_H__");
puts("");
puts("/* -*- C -*- */");
puts("/*");
puts(" * Copyright (c) 1995-2005 Kungliga Tekniska Högskolan");
puts(" * (Royal Institute of Technology, Stockholm, Sweden).");
puts(" * All rights reserved.");
puts(" * ");
puts(" * Redistribution and use in source and binary forms, with or without");
puts(" * modification, are permitted provided that the following conditions");
puts(" * are met:");
puts(" * ");
puts(" * 1. Redistributions of source code must retain the above copyright");
puts(" *    notice, this list of conditions and the following disclaimer.");
puts(" * ");
puts(" * 2. Redistributions in binary form must reproduce the above copyright");
puts(" *    notice, this list of conditions and the following disclaimer in the");
puts(" *    documentation and/or other materials provided with the distribution.");
puts(" * ");
puts(" * 3. Neither the name of the Institute nor the names of its contributors");
puts(" *    may be used to endorse or promote products derived from this software");
puts(" *    without specific prior written permission.");
puts(" * ");
puts(" * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND");
puts(" * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE");
puts(" * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE");
puts(" * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE");
puts(" * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL");
puts(" * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS");
puts(" * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)");
puts(" * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT");
puts(" * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY");
puts(" * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF");
puts(" * SUCH DAMAGE.");
puts(" */");
puts("");
puts("#include <stdio.h>");
puts("#include <stdlib.h>");
puts("#include <stdarg.h>");
#ifdef HAVE_STDINT_H
puts("#include <stdint.h>");
#endif
puts("#include <string.h>");
puts("#include <signal.h>");
puts("");
#ifndef ROKEN_LIB_FUNCTION
#ifdef _WIN32
puts("#  define ROKEN_LIB_CALL     __cdecl");
puts("#  ifdef ROKEN_LIB_DYNAMIC");
puts("#    define ROKEN_LIB_FUNCTION __declspec(dllimport)");
puts("#    define ROKEN_LIB_VARIABLE __declspec(dllimport)");
puts("#  else");
puts("#    define ROKEN_LIB_FUNCTION");
puts("#    define ROKEN_LIB_VARIABLE");
puts("#  endif");
#else
puts("#define ROKEN_LIB_FUNCTION");
puts("#define ROKEN_LIB_CALL");
puts("#define ROKEN_LIB_VARIABLE");
#endif
#endif
puts("");
#ifdef HAVE_WINSOCK
puts("/* Declarations for Microsoft Windows */");
puts("");
puts("#include <winsock2.h>");
puts("#include <ws2tcpip.h>");
puts("");
puts("/*");
puts(" * error codes for inet_ntop/inet_pton ");
puts(" */");
puts("#define EAFNOSUPPORT WSAEAFNOSUPPORT");
puts("");
puts("typedef SOCKET rk_socket_t;");
puts("");
puts("#define rk_closesocket(x) closesocket(x)");
puts("#define rk_INVALID_SOCKET INVALID_SOCKET");
puts("#define rk_IS_BAD_SOCKET(s) ((s) == INVALID_SOCKET)");
puts("#define rk_IS_SOCKET_ERROR(rv) ((rv) == SOCKET_ERROR)");
puts("#define rk_SOCK_ERRNO WSAGetLastError()");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL rk_SOCK_IOCTL(SOCKET s, long cmd, int * argp);");
puts("");
puts("/* Microsoft VC 2010 POSIX definitions */");
#ifndef ENOTSOCK
puts("#define ENOTSOCK		128");
#endif
#ifndef ENOTSUP
puts("#define ENOTSUP                 129");
#endif
#ifndef EOVERFLOW
puts("#define EOVERFLOW               132");
#endif
#ifndef ETIMEDOUT
puts("#define ETIMEDOUT               138");
#endif
#ifndef EWOULDBLOCK
puts("#define EWOULDBLOCK             140");
#endif
puts("");
puts("#define rk_SOCK_INIT() rk_WSAStartup()");
puts("#define rk_SOCK_EXIT() rk_WSACleanup()");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL rk_WSAStartup(void);");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL rk_WSACleanup(void);");
puts("");
#else  /* not WinSock */
puts("");
puts("typedef int rk_socket_t;");
puts("");
puts("#define rk_closesocket(x) close(x)");
puts("#define rk_SOCK_IOCTL(s,c,a) ioctl((s),(c),(a))");
puts("#define rk_IS_BAD_SOCKET(s) ((s) < 0)");
puts("#define rk_IS_SOCKET_ERROR(rv) ((rv) < 0)");
puts("#define rk_SOCK_ERRNO errno");
puts("#define rk_INVALID_SOCKET (-1)");
puts("");
puts("#define rk_SOCK_INIT() 0");
puts("#define rk_SOCK_EXIT() do { } while(0)");
puts("");
#endif
puts("");
#ifndef IN_LOOPBACKNET
puts("#define IN_LOOPBACKNET 127");
#endif
puts("");
#ifdef _MSC_VER
puts("/* Declarations for Microsoft Visual C runtime on Windows */");
puts("");
puts("#include<process.h>");
puts("");
puts("#include<io.h>");
puts("");
#ifndef __BIT_TYPES_DEFINED__
puts("#define __BIT_TYPES_DEFINED__");
puts("");
puts("typedef __int8             int8_t;");
puts("typedef __int16            int16_t;");
puts("typedef __int32            int32_t;");
puts("typedef __int64            int64_t;");
puts("typedef unsigned __int8    uint8_t;");
puts("typedef unsigned __int16   uint16_t;");
puts("typedef unsigned __int32   uint32_t;");
puts("typedef unsigned __int64   uint64_t;");
puts("typedef uint8_t            u_int8_t;");
puts("typedef uint16_t           u_int16_t;");
puts("typedef uint32_t           u_int32_t;");
puts("typedef uint64_t           u_int64_t;");
puts("");
#endif  /* __BIT_TYPES_DEFINED__ */
puts("");
puts("#define UNREACHABLE(x) x");
puts("#define UNUSED_ARGUMENT(x) ((void) x)");
puts("");
puts("#define RETSIGTYPE void");
puts("");
puts("#define VOID_RETSIGTYPE 1");
puts("");
#ifdef VOID_RETSIGTYPE
puts("#define SIGRETURN(x) return");
#else
puts("#define SIGRETURN(x) return (RETSIGTYPE)(x)");
#endif
puts("");
#ifndef CPP_ONLY
puts("");
puts("typedef int pid_t;");
puts("");
puts("typedef unsigned int gid_t;");
puts("");
puts("typedef unsigned int uid_t;");
puts("");
puts("typedef unsigned short mode_t;");
puts("");
#endif
puts("");
#ifndef __cplusplus
puts("#define inline __inline");
#endif
puts("");
#else
puts("");
puts("#define UNREACHABLE(x)");
puts("#define UNUSED_ARGUMENT(x)");
puts("");
#endif
puts("");
#ifdef _AIX
puts("struct ether_addr;");
puts("struct sockaddr_dl;");
#endif
#ifdef HAVE_SYS_PARAM_H
puts("#include <sys/param.h>");
#endif
#ifdef HAVE_INTTYPES_H
puts("#include <inttypes.h>");
#endif
#ifdef HAVE_SYS_TYPES_H
puts("#include <sys/types.h>");
#endif
#ifdef HAVE_SYS_BITYPES_H
puts("#include <sys/bitypes.h>");
#endif
#ifdef HAVE_BIND_BITYPES_H
puts("#include <bind/bitypes.h>");
#endif
#ifdef HAVE_NETINET_IN6_MACHTYPES_H
puts("#include <netinet/in6_machtypes.h>");
#endif
#ifdef HAVE_UNISTD_H
puts("#include <unistd.h>");
#endif
#ifdef HAVE_SYS_SOCKET_H
puts("#include <sys/socket.h>");
#endif
#ifdef HAVE_SYS_UIO_H
puts("#include <sys/uio.h>");
#endif
#ifdef HAVE_GRP_H
puts("#include <grp.h>");
#endif
#ifdef HAVE_SYS_STAT_H
puts("#include <sys/stat.h>");
#endif
#ifdef HAVE_NETINET_IN_H
puts("#include <netinet/in.h>");
#endif
#ifdef HAVE_NETINET_IN6_H
puts("#include <netinet/in6.h>");
#endif
#ifdef HAVE_NETINET6_IN6_H
puts("#include <netinet6/in6.h>");
#endif
#ifdef HAVE_ARPA_INET_H
puts("#include <arpa/inet.h>");
#endif
#ifdef HAVE_NETDB_H
puts("#include <netdb.h>");
#endif
#ifdef HAVE_ARPA_NAMESER_H
puts("#include <arpa/nameser.h>");
#endif
#ifdef HAVE_RESOLV_H
puts("#include <resolv.h>");
#endif
#ifdef HAVE_SYSLOG_H
puts("#include <syslog.h>");
#endif
#ifdef HAVE_FCNTL_H
puts("#include <fcntl.h>");
#endif
#ifdef HAVE_ERRNO_H
puts("#include <errno.h>");
#endif
puts("#include <err.h>");
#ifdef HAVE_TERMIOS_H
puts("#include <termios.h>");
#endif
#ifdef HAVE_SYS_IOCTL_H
puts("#include <sys/ioctl.h>");
#endif
#ifdef TIME_WITH_SYS_TIME
puts("#include <sys/time.h>");
puts("#include <time.h>");
#elif defined(HAVE_SYS_TIME_H)
puts("#include <sys/time.h>");
#else
puts("#include <time.h>");
#endif
puts("");
#ifdef HAVE_PATHS_H
puts("#include <paths.h>");
#endif
puts("");
#ifdef HAVE_DIRENT_H
puts("#include <dirent.h>");
#endif
puts("");
#ifdef BACKSLASH_PATH_DELIM
puts("#define rk_PATH_DELIM '\\\\'");
#endif
puts("");
#ifndef HAVE_SSIZE_T
#ifndef SSIZE_T_DEFINED
#ifdef ssize_t
puts("#undef ssize_t");
#endif
#ifdef _WIN64
puts("typedef __int64 ssize_t;");
#else
puts("typedef int ssize_t;");
#endif
puts("#define SSIZE_T_DEFINED");
#endif  /* SSIZE_T_DEFINED */
#endif  /* HAVE_SSIZE_T */
puts("");
puts("#include <roken-common.h>");
puts("");
puts("ROKEN_CPP_START");
puts("");
#ifdef HAVE_UINTPTR_T
puts("#define rk_UNCONST(x) ((void *)(uintptr_t)(const void *)(x))");
#else
puts("#define rk_UNCONST(x) ((void *)(unsigned long)(const void *)(x))");
#endif
puts("");
#if !defined(HAVE_SETSID) && defined(HAVE__SETSID)
puts("#define setsid _setsid");
#endif
puts("");
#ifdef _MSC_VER
puts("/* Additional macros for Visual C/C++ runtime */");
puts("");
puts("#define close	_close");
puts("");
puts("#define getpid	_getpid");
puts("");
puts("#define open	_open");
puts("");
puts("#define chdir   _chdir");
puts("");
puts("#define fsync   _commit");
puts("");
puts("/* The MSVC implementation of snprintf is not C99 compliant.  */");
puts("#define snprintf    rk_snprintf");
puts("#define vsnprintf   rk_vsnprintf");
puts("#define vasnprintf  rk_vasnprintf");
puts("#define vasprintf   rk_vasprintf");
puts("#define asnprintf   rk_asnprintf");
puts("#define asprintf    rk_asprintf");
puts("");
puts("#define _PIPE_BUFFER_SZ 8192");
puts("#define pipe(fds) _pipe((fds), _PIPE_BUFFER_SZ, O_BINARY);");
puts("");
puts("#define ftruncate(fd, sz) _chsize((fd), (sz))");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("rk_snprintf (char *str, size_t sz, const char *format, ...);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("rk_asprintf (char **ret, const char *format, ...);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("rk_asnprintf (char **ret, size_t max_sz, const char *format, ...);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("rk_vasprintf (char **ret, const char *format, va_list args);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("rk_vasnprintf (char **ret, size_t max_sz, const char *format, va_list args);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("rk_vsnprintf (char *str, size_t sz, const char *format, va_list args);");
puts("");
puts("/* missing stat.h predicates */");
puts("");
puts("#define S_ISREG(m) (((m) & _S_IFREG) == _S_IFREG)");
puts("");
puts("#define S_ISDIR(m) (((m) & _S_IFDIR) == _S_IFDIR)");
puts("");
puts("#define S_ISCHR(m) (((m) & _S_IFCHR) == _S_IFCHR)");
puts("");
puts("#define S_ISFIFO(m) (((m) & _S_IFIFO) == _S_IFIFO)");
puts("");
puts("/* The following are not implemented:");
puts("");
puts(" S_ISLNK(m)");
puts(" S_ISSOCK(m)");
puts(" S_ISBLK(m)");
puts("*/");
puts("");
#endif  /* _MSC_VER */
puts("");
#ifdef HAVE_WINSOCK
puts("");
puts("/* While we are at it, define WinSock specific scatter gather socket");
puts("   I/O. */");
puts("");
puts("#define iovec    _WSABUF");
puts("#define iov_base buf");
puts("#define iov_len  len");
puts("");
puts("struct msghdr {");
puts("    void           *msg_name;");
puts("    socklen_t       msg_namelen;");
puts("    struct iovec   *msg_iov;");
puts("    size_t          msg_iovlen;");
puts("    void           *msg_control;");
puts("    socklen_t       msg_controllen;");
puts("    int             msg_flags;");
puts("};");
puts("");
puts("#define sendmsg sendmsg_w32");
puts("");
puts("ROKEN_LIB_FUNCTION ssize_t ROKEN_LIB_CALL");
puts("sendmsg_w32(rk_socket_t s, const struct msghdr * msg, int flags);");
puts("");
#endif	/* HAVE_WINSOCK */
puts("");
#ifndef HAVE_PUTENV
puts("#define putenv rk_putenv");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL putenv(const char *);");
#endif
puts("");
#if !defined(HAVE_SETENV) || defined(NEED_SETENV_PROTO)
#ifndef HAVE_SETENV
puts("#define setenv rk_setenv");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL setenv(const char *, const char *, int);");
#endif
puts("");
#if !defined(HAVE_UNSETENV) || defined(NEED_UNSETENV_PROTO)
#ifndef HAVE_UNSETENV
puts("#define unsetenv rk_unsetenv");
#endif
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL unsetenv(const char *);");
#endif
puts("");
#if !defined(HAVE_GETUSERSHELL) || defined(NEED_GETUSERSHELL_PROTO)
#ifndef HAVE_GETUSERSHELL
puts("#define getusershell rk_getusershell");
puts("#define endusershell rk_endusershell");
#endif
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL getusershell(void);");
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL endusershell(void);");
#endif
puts("");
#if !defined(HAVE_SNPRINTF) || defined(NEED_SNPRINTF_PROTO)
#ifndef HAVE_SNPRINTF
puts("#define snprintf rk_snprintf");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("     rk_snprintf (char *, size_t, const char *, ...)");
puts("     __attribute__ ((format (printf, 3, 4)));");
#endif
puts("");
#if !defined(HAVE_VSNPRINTF) || defined(NEED_VSNPRINTF_PROTO)
#ifndef HAVE_VSNPRINTF
puts("#define vsnprintf rk_vsnprintf");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL ");
puts("     rk_vsnprintf (char *, size_t, const char *, va_list)");
puts("     __attribute__((format (printf, 3, 0)));");
#endif
puts("");
#if !defined(HAVE_ASPRINTF) || defined(NEED_ASPRINTF_PROTO)
#ifndef HAVE_ASPRINTF
puts("#define asprintf rk_asprintf");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("     rk_asprintf (char **, const char *, ...)");
puts("     __attribute__ ((format (printf, 2, 3)));");
#endif
puts("");
#if !defined(HAVE_VASPRINTF) || defined(NEED_VASPRINTF_PROTO)
#ifndef HAVE_VASPRINTF
puts("#define vasprintf rk_vasprintf");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("    rk_vasprintf (char **, const char *, va_list)");
puts("     __attribute__((format (printf, 2, 0)));");
#endif
puts("");
#if !defined(HAVE_ASNPRINTF) || defined(NEED_ASNPRINTF_PROTO)
#ifndef HAVE_ASNPRINTF
puts("#define asnprintf rk_asnprintf");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("    rk_asnprintf (char **, size_t, const char *, ...)");
puts("     __attribute__ ((format (printf, 3, 4)));");
#endif
puts("");
#if !defined(HAVE_VASNPRINTF) || defined(NEED_VASNPRINTF_PROTO)
#ifndef HAVE_VASNPRINTF
puts("#define vasnprintf rk_vasnprintf");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("    vasnprintf (char **, size_t, const char *, va_list)");
puts("     __attribute__((format (printf, 3, 0)));");
#endif
puts("");
#ifndef HAVE_STRDUP
puts("#define strdup rk_strdup");
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL strdup(const char *);");
#endif
puts("");
#if !defined(HAVE_STRNDUP) || defined(NEED_STRNDUP_PROTO)
#ifndef HAVE_STRNDUP
puts("#define strndup rk_strndup");
#endif
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL strndup(const char *, size_t);");
#endif
puts("");
#ifndef HAVE_STRLWR
puts("#define strlwr rk_strlwr");
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL strlwr(char *);");
#endif
puts("");
#ifndef HAVE_STRNLEN
puts("#define strnlen rk_strnlen");
puts("ROKEN_LIB_FUNCTION size_t ROKEN_LIB_CALL strnlen(const char*, size_t);");
#endif
puts("");
#if !defined(HAVE_STRSEP) || defined(NEED_STRSEP_PROTO)
#ifndef HAVE_STRSEP
puts("#define strsep rk_strsep");
#endif
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL strsep(char**, const char*);");
#endif
puts("");
#if !defined(HAVE_STRSEP_COPY) || defined(NEED_STRSEP_COPY_PROTO)
#ifndef HAVE_STRSEP_COPY
puts("#define strsep_copy rk_strsep_copy");
#endif
puts("ROKEN_LIB_FUNCTION ssize_t ROKEN_LIB_CALL strsep_copy(const char**, const char*, char*, size_t);");
#endif
puts("");
#ifndef HAVE_STRCASECMP
puts("#define strcasecmp rk_strcasecmp");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL strcasecmp(const char *, const char *);");
#endif
puts("");
#ifdef NEED_FCLOSE_PROTO
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL fclose(FILE *);");
#endif
puts("");
#ifdef NEED_STRTOK_R_PROTO
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL strtok_r(char *, const char *, char **);");
#endif
puts("");
#ifndef HAVE_STRUPR
puts("#define strupr rk_strupr");
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL strupr(char *);");
#endif
puts("");
#ifndef HAVE_STRLCPY
puts("#define strlcpy rk_strlcpy");
puts("ROKEN_LIB_FUNCTION size_t ROKEN_LIB_CALL strlcpy (char *, const char *, size_t);");
#endif
puts("");
#ifndef HAVE_STRLCAT
puts("#define strlcat rk_strlcat");
puts("ROKEN_LIB_FUNCTION size_t ROKEN_LIB_CALL strlcat (char *, const char *, size_t);");
#endif
puts("");
#ifndef HAVE_GETDTABLESIZE
puts("#define getdtablesize rk_getdtablesize");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL getdtablesize(void);");
#endif
puts("");
#if !defined(HAVE_STRERROR) && !defined(strerror)
puts("#define strerror rk_strerror");
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL strerror(int);");
#endif
puts("");
#if (!defined(HAVE_STRERROR_R) && !defined(strerror_r)) || (!defined(STRERROR_R_PROTO_COMPATIBLE) && defined(HAVE_STRERROR_R))
puts("int ROKEN_LIB_FUNCTION rk_strerror_r(int, char *, size_t);");
#else
puts("#define rk_strerror_r strerror_r");
#endif
puts("");
#if !defined(HAVE_HSTRERROR) || defined(NEED_HSTRERROR_PROTO)
#ifndef HAVE_HSTRERROR
puts("#define hstrerror rk_hstrerror");
#endif
puts("/* This causes a fatal error under Psoriasis */");
#ifndef SunOS
puts("ROKEN_LIB_FUNCTION const char * ROKEN_LIB_CALL hstrerror(int);");
#endif
#endif
puts("");
#if !HAVE_DECL_H_ERRNO
puts("extern int h_errno;");
#endif
puts("");
#if !defined(HAVE_INET_ATON) || defined(NEED_INET_ATON_PROTO)
#ifndef HAVE_INET_ATON
puts("#define inet_aton rk_inet_aton");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL inet_aton(const char *, struct in_addr *);");
#endif
puts("");
#ifndef HAVE_INET_NTOP
puts("#define inet_ntop rk_inet_ntop");
puts("ROKEN_LIB_FUNCTION const char * ROKEN_LIB_CALL");
puts("inet_ntop(int af, const void *src, char *dst, size_t size);");
#endif
puts("");
#ifndef HAVE_INET_PTON
puts("#define inet_pton rk_inet_pton");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("inet_pton(int, const char *, void *);");
#endif
puts("");
#ifndef HAVE_GETCWD
puts("#define getcwd rk_getcwd");
puts("ROKEN_LIB_FUNCTION char* ROKEN_LIB_CALL getcwd(char *, size_t);");
#endif
puts("");
#ifdef HAVE_PWD_H
puts("#include <pwd.h>");
puts("ROKEN_LIB_FUNCTION struct passwd * ROKEN_LIB_CALL k_getpwnam (const char *);");
puts("ROKEN_LIB_FUNCTION struct passwd * ROKEN_LIB_CALL k_getpwuid (uid_t);");
#endif
puts("");
puts("ROKEN_LIB_FUNCTION const char * ROKEN_LIB_CALL get_default_username (void);");
puts("");
#ifndef HAVE_SETEUID
puts("#define seteuid rk_seteuid");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL seteuid(uid_t);");
#endif
puts("");
#ifndef HAVE_SETEGID
puts("#define setegid rk_setegid");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL setegid(gid_t);");
#endif
puts("");
#ifndef HAVE_LSTAT
puts("#define lstat rk_lstat");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL lstat(const char *, struct stat *);");
#endif
puts("");
#if !defined(HAVE_MKSTEMP) || defined(NEED_MKSTEMP_PROTO)
#ifndef HAVE_MKSTEMP
puts("#define mkstemp rk_mkstemp");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL mkstemp(char *);");
#endif
puts("");
#ifndef HAVE_CGETENT
puts("#define cgetent rk_cgetent");
puts("#define cgetstr rk_cgetstr");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL cgetent(char **, char **, const char *);");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL cgetstr(char *, const char *, char **);");
#endif
puts("");
#ifndef HAVE_INITGROUPS
puts("#define initgroups rk_initgroups");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL initgroups(const char *, gid_t);");
#endif
puts("");
#ifndef HAVE_FCHOWN
puts("#define fchown rk_fchown");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL fchown(int, uid_t, gid_t);");
#endif
puts("");
#ifdef RENAME_DOES_NOT_UNLINK
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL rk_rename(const char *, const char *);");
#else
puts("#define rk_rename(__rk_rn_from,__rk_rn_to) rename(__rk_rn_from,__rk_rn_to)");
#endif
puts("");
#if !defined(HAVE_DAEMON) || defined(NEED_DAEMON_PROTO)
#ifndef HAVE_DAEMON
puts("#define daemon rk_daemon");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL daemon(int, int);");
#endif
puts("");
#ifndef HAVE_CHOWN
puts("#define chown rk_chown");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL chown(const char *, uid_t, gid_t);");
#endif
puts("");
#ifndef HAVE_RCMD
puts("#define rcmd rk_rcmd");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("    rcmd(char **, unsigned short, const char *,");
puts("	 const char *, const char *, int *);");
#endif
puts("");
#if !defined(HAVE_INNETGR) || defined(NEED_INNETGR_PROTO)
#ifndef HAVE_INNETGR
puts("#define innetgr rk_innetgr");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL innetgr(const char*, const char*,");
puts("    const char*, const char*);");
#endif
puts("");
#ifndef HAVE_IRUSEROK
puts("#define iruserok rk_iruserok");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL iruserok(unsigned, int, ");
puts("    const char *, const char *);");
#endif
puts("");
#if !defined(HAVE_GETHOSTNAME) || defined(NEED_GETHOSTNAME_PROTO)
#ifndef HAVE_GETHOSTNAME
puts("#define gethostname rk_gethostname");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL gethostname(char *, int);");
#endif
puts("");
#ifndef HAVE_WRITEV
puts("#define writev rk_writev");
puts("ROKEN_LIB_FUNCTION ssize_t ROKEN_LIB_CALL");
puts("writev(int, const struct iovec *, int);");
#endif
puts("");
#ifndef HAVE_READV
puts("#define readv rk_readv");
puts("ROKEN_LIB_FUNCTION ssize_t ROKEN_LIB_CALL");
puts("readv(int, const struct iovec *, int);");
#endif
puts("");
#ifndef HAVE_PIDFILE
#ifdef NO_PIDFILES
puts("#define pidfile(x) ((void) 0)");
#else
puts("#define pidfile rk_pidfile");
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL pidfile (const char*);");
#endif
#endif
puts("");
#ifndef HAVE_BSWAP32
puts("#define bswap32 rk_bswap32");
puts("ROKEN_LIB_FUNCTION unsigned int ROKEN_LIB_CALL bswap32(unsigned int);");
#endif
puts("");
#ifndef HAVE_BSWAP16
puts("#define bswap16 rk_bswap16");
puts("ROKEN_LIB_FUNCTION unsigned short ROKEN_LIB_CALL bswap16(unsigned short);");
#endif
puts("");
#ifndef HAVE_FLOCK
#ifndef LOCK_SH
puts("#define LOCK_SH   1		/* Shared lock */");
#endif
#ifndef	LOCK_EX
puts("#define LOCK_EX   2		/* Exclusive lock */");
#endif
#ifndef LOCK_NB
puts("#define LOCK_NB   4		/* Don't block when locking */");
#endif
#ifndef LOCK_UN
puts("#define LOCK_UN   8		/* Unlock */");
#endif
puts("");
puts("#define flock(_x,_y) rk_flock(_x,_y)");
puts("int rk_flock(int fd, int operation);");
#endif /* HAVE_FLOCK */
puts("");
#ifndef HAVE_DIRFD
#ifdef HAVE_DIR_DD_FD
puts("#define dirfd(x) ((x)->dd_fd)");
#else
#ifndef _WIN32 /* Windows code never calls dirfd */
puts("#error Missing dirfd() and ->dd_fd");
#endif
#endif
#endif
puts("");
puts("ROKEN_LIB_FUNCTION time_t ROKEN_LIB_CALL tm2time (struct tm, int);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL unix_verify_user(char *, char *);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL roken_concat (char *, size_t, ...);");
puts("");
puts("ROKEN_LIB_FUNCTION size_t ROKEN_LIB_CALL roken_mconcat (char **, size_t, ...);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL roken_vconcat (char *, size_t, va_list);");
puts("");
puts("ROKEN_LIB_FUNCTION size_t ROKEN_LIB_CALL");
puts("    roken_vmconcat (char **, size_t, va_list);");
puts("");
puts("ROKEN_LIB_FUNCTION ssize_t ROKEN_LIB_CALL");
puts("    net_write (rk_socket_t, const void *, size_t);");
puts("");
puts("ROKEN_LIB_FUNCTION ssize_t ROKEN_LIB_CALL");
puts("    net_read (rk_socket_t, void *, size_t);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("    issuid(void);");
puts("");
#ifndef HAVE_STRUCT_WINSIZE
puts("struct winsize {");
puts("	unsigned short ws_row, ws_col;");
puts("	unsigned short ws_xpixel, ws_ypixel;");
puts("};");
#endif
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL get_window_size(int fd, int *, int *);");
puts("");
#ifndef HAVE_VSYSLOG
puts("#define vsyslog rk_vsyslog");
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL vsyslog(int, const char *, va_list);");
#endif
puts("");
#ifndef HAVE_GETOPT
puts("#define getopt rk_getopt");
puts("#define optarg rk_optarg");
puts("#define optind rk_optind");
puts("#define opterr rk_opterr");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("getopt(int nargc, char * const *nargv, const char *ostr);");
#endif
puts("");
#if !HAVE_DECL_OPTARG
puts("ROKEN_LIB_VARIABLE extern char *optarg;");
#endif
#if !HAVE_DECL_OPTIND
puts("ROKEN_LIB_VARIABLE extern int optind;");
#endif
#if !HAVE_DECL_OPTERR
puts("ROKEN_LIB_VARIABLE extern int opterr;");
#endif
puts("");
#ifndef HAVE_GETIPNODEBYNAME
puts("#define getipnodebyname rk_getipnodebyname");
puts("ROKEN_LIB_FUNCTION struct hostent * ROKEN_LIB_CALL");
puts("getipnodebyname (const char *, int, int, int *);");
#endif
puts("");
#ifndef HAVE_GETIPNODEBYADDR
puts("#define getipnodebyaddr rk_getipnodebyaddr");
puts("ROKEN_LIB_FUNCTION struct hostent * ROKEN_LIB_CALL");
puts("getipnodebyaddr (const void *, size_t, int, int *);");
#endif
puts("");
#ifndef HAVE_FREEHOSTENT
puts("#define freehostent rk_freehostent");
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL");
puts("freehostent (struct hostent *);");
#endif
puts("");
#ifndef HAVE_COPYHOSTENT
puts("#define copyhostent rk_copyhostent");
puts("ROKEN_LIB_FUNCTION struct hostent * ROKEN_LIB_CALL");
puts("copyhostent (const struct hostent *);");
#endif
puts("");
#ifndef HAVE_SOCKLEN_T
puts("typedef int socklen_t;");
#endif
puts("");
#ifndef HAVE_STRUCT_SOCKADDR_STORAGE
puts("");
#ifndef HAVE_SA_FAMILY_T
puts("typedef unsigned short sa_family_t;");
#endif
puts("");
#ifdef HAVE_IPV6
puts("#define _SS_MAXSIZE sizeof(struct sockaddr_in6)");
#else
puts("#define _SS_MAXSIZE sizeof(struct sockaddr_in)");
#endif
puts("");
puts("#define _SS_ALIGNSIZE	sizeof(unsigned long)");
puts("");
#if HAVE_STRUCT_SOCKADDR_SA_LEN
puts("");
puts("typedef unsigned char roken_sa_family_t;");
puts("");
puts("#define _SS_PAD1SIZE   ((2 * _SS_ALIGNSIZE - sizeof (roken_sa_family_t) - sizeof(unsigned char)) % _SS_ALIGNSIZE)");
puts("#define _SS_PAD2SIZE   (_SS_MAXSIZE - (sizeof (roken_sa_family_t) + sizeof(unsigned char) + _SS_PAD1SIZE + _SS_ALIGNSIZE))");
puts("");
puts("struct sockaddr_storage {");
puts("    unsigned char	ss_len;");
puts("    roken_sa_family_t	ss_family;");
puts("    char		__ss_pad1[_SS_PAD1SIZE];");
puts("    unsigned long	__ss_align[_SS_PAD2SIZE / sizeof(unsigned long) + 1];");
puts("};");
puts("");
#else /* !HAVE_STRUCT_SOCKADDR_SA_LEN */
puts("");
puts("typedef unsigned short roken_sa_family_t;");
puts("");
puts("#define _SS_PAD1SIZE   ((2 * _SS_ALIGNSIZE - sizeof (roken_sa_family_t)) % _SS_ALIGNSIZE)");
puts("#define _SS_PAD2SIZE   (_SS_MAXSIZE - (sizeof (roken_sa_family_t) + _SS_PAD1SIZE + _SS_ALIGNSIZE))");
puts("");
puts("struct sockaddr_storage {");
puts("    roken_sa_family_t	ss_family;");
puts("    char		__ss_pad1[_SS_PAD1SIZE];");
puts("    unsigned long	__ss_align[_SS_PAD2SIZE / sizeof(unsigned long) + 1];");
puts("};");
puts("");
#endif /* HAVE_STRUCT_SOCKADDR_SA_LEN */
puts("");
#endif /* HAVE_STRUCT_SOCKADDR_STORAGE */
puts("");
#ifndef HAVE_STRUCT_ADDRINFO
puts("struct addrinfo {");
puts("    int    ai_flags;");
puts("    int    ai_family;");
puts("    int    ai_socktype;");
puts("    int    ai_protocol;");
puts("    size_t ai_addrlen;");
puts("    char  *ai_canonname;");
puts("    struct sockaddr *ai_addr;");
puts("    struct addrinfo *ai_next;");
puts("};");
#endif
puts("");
#ifndef HAVE_GETADDRINFO
puts("#define getaddrinfo rk_getaddrinfo");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("getaddrinfo(const char *,");
puts("	    const char *,");
puts("	    const struct addrinfo *,");
puts("	    struct addrinfo **);");
#endif
puts("");
#ifndef HAVE_GETNAMEINFO
puts("#define getnameinfo rk_getnameinfo");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("getnameinfo(const struct sockaddr *, socklen_t,");
puts("		char *, size_t,");
puts("		char *, size_t,");
puts("		int);");
#endif
puts("");
#ifndef HAVE_FREEADDRINFO
puts("#define freeaddrinfo rk_freeaddrinfo");
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL");
puts("freeaddrinfo(struct addrinfo *);");
#endif
puts("");
#ifndef HAVE_GAI_STRERROR
puts("#define gai_strerror rk_gai_strerror");
puts("ROKEN_LIB_FUNCTION const char * ROKEN_LIB_CALL");
puts("gai_strerror(int);");
#endif
puts("");
#ifdef NO_SLEEP
puts("");
puts("ROKEN_LIB_FUNCTION unsigned int ROKEN_LIB_CALL");
puts("sleep(unsigned int seconds);");
puts("");
#endif
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("getnameinfo_verified(const struct sockaddr *, socklen_t,");
puts("		     char *, size_t,");
puts("		     char *, size_t,");
puts("		     int);");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("roken_getaddrinfo_hostspec(const char *, int, struct addrinfo **); ");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("roken_getaddrinfo_hostspec2(const char *, int, int, struct addrinfo **);");
puts("");
#ifndef HAVE_STRFTIME
puts("#define strftime rk_strftime");
puts("ROKEN_LIB_FUNCTION size_t ROKEN_LIB_CALL");
puts("strftime (char *, size_t, const char *, const struct tm *);");
#endif
puts("");
#ifndef HAVE_STRPTIME
puts("#define strptime rk_strptime");
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL");
puts("strptime (const char *, const char *, struct tm *);");
#endif
puts("");
#ifndef HAVE_GETTIMEOFDAY
puts("#define gettimeofday rk_gettimeofday");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("gettimeofday (struct timeval *, void *);");
#endif
puts("");
#ifndef HAVE_EMALLOC
puts("#define emalloc rk_emalloc");
puts("ROKEN_LIB_FUNCTION void * ROKEN_LIB_CALL emalloc (size_t);");
#endif
#ifndef HAVE_ECALLOC
puts("#define ecalloc rk_ecalloc");
puts("ROKEN_LIB_FUNCTION void * ROKEN_LIB_CALL ecalloc(size_t, size_t);");
#endif
#ifndef HAVE_EREALLOC
puts("#define erealloc rk_erealloc");
puts("ROKEN_LIB_FUNCTION void * ROKEN_LIB_CALL erealloc (void *, size_t);");
#endif
#ifndef HAVE_ESTRDUP
puts("#define estrdup rk_estrdup");
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL estrdup (const char *);");
#endif
puts("");
puts("/*");
puts(" * kludges and such");
puts(" */");
puts("");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("roken_gethostby_setup(const char*, const char*);");
puts("ROKEN_LIB_FUNCTION struct hostent* ROKEN_LIB_CALL");
puts("roken_gethostbyname(const char*);");
puts("ROKEN_LIB_FUNCTION struct hostent* ROKEN_LIB_CALL ");
puts("roken_gethostbyaddr(const void*, size_t, int);");
puts("");
#ifdef GETSERVBYNAME_PROTO_COMPATIBLE
puts("#define roken_getservbyname(x,y) getservbyname(x,y)");
#else
puts("#define roken_getservbyname(x,y) getservbyname((char *)x, (char *)y)");
#endif
puts("");
#ifdef OPENLOG_PROTO_COMPATIBLE
puts("#define roken_openlog(a,b,c) openlog(a,b,c)");
#else
puts("#define roken_openlog(a,b,c) openlog((char *)a,b,c)");
#endif
puts("");
#ifdef GETSOCKNAME_PROTO_COMPATIBLE
puts("#define roken_getsockname(a,b,c) getsockname(a,b,c)");
#else
puts("#define roken_getsockname(a,b,c) getsockname(a, b, (void*)c)");
#endif
puts("");
#ifndef HAVE_SETPROGNAME
puts("#define setprogname rk_setprogname");
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL setprogname(const char *);");
#endif
puts("");
#ifndef HAVE_GETPROGNAME
puts("#define getprogname rk_getprogname");
puts("ROKEN_LIB_FUNCTION const char * ROKEN_LIB_CALL getprogname(void);");
#endif
puts("");
#if !defined(HAVE_SETPROGNAME) && !defined(HAVE_GETPROGNAME) && !HAVE_DECL___PROGNAME
puts("extern const char *__progname;");
#endif
puts("");
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL");
puts("mini_inetd_addrinfo (struct addrinfo*, rk_socket_t *);");
puts("");
puts("ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL");
puts("mini_inetd (int, rk_socket_t *);");
puts("");
#ifndef HAVE_LOCALTIME_R
puts("#define localtime_r rk_localtime_r");
puts("ROKEN_LIB_FUNCTION struct tm * ROKEN_LIB_CALL");
puts("localtime_r(const time_t *, struct tm *);");
#endif
puts("");
#if !defined(HAVE_STRSVIS) || defined(NEED_STRSVIS_PROTO)
#ifndef HAVE_STRSVIS
puts("#define strsvis rk_strsvis");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("strsvis(char *, const char *, int, const char *);");
#endif
puts("");
#if !defined(HAVE_STRSVISX) || defined(NEED_STRSVISX_PROTO)
#ifndef HAVE_STRSVISX
puts("#define strsvisx rk_strsvisx");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("strsvisx(char *, const char *, size_t, int, const char *);");
#endif
puts("");
#if !defined(HAVE_STRUNVIS) || defined(NEED_STRUNVIS_PROTO)
#ifndef HAVE_STRUNVIS
puts("#define strunvis rk_strunvis");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("strunvis(char *, const char *);");
#endif
puts("");
#if !defined(HAVE_STRVIS) || defined(NEED_STRVIS_PROTO)
#ifndef HAVE_STRVIS
puts("#define strvis rk_strvis");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("strvis(char *, const char *, int);");
#endif
puts("");
#if !defined(HAVE_STRVISX) || defined(NEED_STRVISX_PROTO)
#ifndef HAVE_STRVISX
puts("#define strvisx rk_strvisx");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("strvisx(char *, const char *, size_t, int);");
#endif
puts("");
#if !defined(HAVE_SVIS) || defined(NEED_SVIS_PROTO)
#ifndef HAVE_SVIS
puts("#define svis rk_svis");
#endif
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL");
puts("svis(char *, int, int, int, const char *);");
#endif
puts("");
#if !defined(HAVE_UNVIS) || defined(NEED_UNVIS_PROTO)
#ifndef HAVE_UNVIS
puts("#define unvis rk_unvis");
#endif
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("unvis(char *, int, int *, int);");
#endif
puts("");
#if !defined(HAVE_VIS) || defined(NEED_VIS_PROTO)
#ifndef HAVE_VIS
puts("#define vis rk_vis");
#endif
puts("ROKEN_LIB_FUNCTION char * ROKEN_LIB_CALL");
puts("vis(char *, int, int, int);");
#endif
puts("");
#if !defined(HAVE_CLOSEFROM)
puts("#define closefrom rk_closefrom");
puts("ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL");
puts("closefrom(int);");
#endif
puts("");
#if !defined(HAVE_TIMEGM)
puts("#define timegm rk_timegm");
puts("ROKEN_LIB_FUNCTION time_t ROKEN_LIB_CALL");
puts("rk_timegm(struct tm *tm);");
#endif
puts("");
#ifdef NEED_QSORT
puts("#define qsort rk_qsort");
puts("void");
puts("rk_qsort(void *, size_t, size_t, int (*)(const void *, const void *));");
#endif
puts("");
#if defined(HAVE_ARC4RANDOM)
puts("#define rk_random() arc4random()");
#elif defined(HAVE_RANDOM)
puts("#define rk_random() random()");
#else
puts("#define rk_random() rand()");
#endif
puts("");
#ifndef HAVE_TDELETE
puts("#define tdelete(a,b,c) rk_tdelete(a,b,c)");
#endif
#ifndef HAVE_TFIND
puts("#define tfind(a,b,c) rk_tfind(a,b,c)");
#endif
#ifndef HAVE_TSEARCH
puts("#define tsearch(a,b,c) rk_tsearch(a,b,c)");
#endif
#ifndef HAVE_TWALK
puts("#define twalk(a,b) rk_twalk(a,b)");
#endif
puts("");
#if defined(__linux__) && defined(SOCK_CLOEXEC) && !defined(SOCKET_WRAPPER_REPLACE) && !defined(__SOCKET_WRAPPER_H__)
puts("#undef socket");
puts("#define socket(_fam,_type,_prot) rk_socket(_fam,_type,_prot)");
puts("int ROKEN_LIB_FUNCTION rk_socket(int, int, int);");
#endif
puts("");
#ifdef SOCKET_WRAPPER_REPLACE
puts("#include <socket_wrapper.h>");
#endif
puts("");
puts("ROKEN_CPP_END");
puts("");
puts("#endif /* __ROKEN_H__ */");
return 0;
}
