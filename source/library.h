
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_LIBRARY_H
#define MASTER_zzz_LIBRARY_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

/* #! C/C++ Standard !# */

#ifdef __cplusplus
#	define MASTER_C_STANDARD 0
#	if __cplusplus + 0 >= 202302L
#		define MASTER_CPP_STANDARD 2023
#		define MASTER_COMPILER_LANGUAGE "C++23"
#	elif __cplusplus + 0 >= 202002L
#		define MASTER_CPP_STANDARD 2020
#		define MASTER_COMPILER_LANGUAGE "C++20"
#	elif __cplusplus + 0 >= 201703L
#		define MASTER_CPP_STANDARD 2017
#		define MASTER_COMPILER_LANGUAGE "C++17"
#	elif __cplusplus + 0 >= 201402L
#		define MASTER_CPP_STANDARD 2014
#		define MASTER_COMPILER_LANGUAGE "C++14"
#	elif __cplusplus + 0 >= 201103L
#		define MASTER_CPP_STANDARD 2011
#		define MASTER_COMPILER_LANGUAGE "C++11"
#	elif __cplusplus + 0 >= 199711L
#		define MASTER_CPP_STANDARD 2003
#		define MASTER_COMPILER_LANGUAGE "C++98/03"
#	else
#		define MASTER_CPP_STANDARD 1990
#		define MASTER_COMPILER_LANGUAGE "C++90"
#	endif /* #! __cplusplus !# */
#elif defined(__STDC__)
#	define MASTER_CPP_STANDARD 0
#	if defined(__STDC_VERSION__)
#		if __STDC_VERSION__ + 0 >= 202311L
#			define MASTER_C_STANDARD 2023
#			define MASTER_COMPILER_LANGUAGE "C23"
#		elif __STDC_VERSION__ + 0 >= 201710L
#			define MASTER_C_STANDARD 2017
#			define MASTER_COMPILER_LANGUAGE "C17"
#		elif __STDC_VERSION__ + 0 >= 201112L
#			define MASTER_C_STANDARD 2011
#			define MASTER_COMPILER_LANGUAGE "C11"
#		elif __STDC_VERSION__ + 0 >= 199901L
#			define MASTER_C_STANDARD 1999
#			define MASTER_COMPILER_LANGUAGE "C99"
#		elif __STDC_VERSION__ + 0 >= 199409L
#			define MASTER_C_STANDARD 1995
#			define MASTER_COMPILER_LANGUAGE "C95"
#		else
#			define MASTER_C_STANDARD 1989
#			define MASTER_COMPILER_LANGUAGE "C90"
#		endif /* #! __STDC_VERSION__ !# */
#	else
#		define MASTER_C_STANDARD 1989
#		define MASTER_COMPILER_LANGUAGE "C89"
#	endif /* #! __STDC_VERSION__ !# */
#else
#	define MASTER_C_STANDARD 1978
#	define MASTER_COMPILER_LANGUAGE "K&R C (C78)"
#endif /* #! __STDC__ !# */

#define MASTER_PREFER_C89_SUPPORTED (MASTER_C_STANDARD >= 1989)
#define MASTER_PREFER_C95_SUPPORTED (MASTER_C_STANDARD >= 1994)
#define MASTER_PREFER_C99_SUPPORTED (MASTER_C_STANDARD >= 1999)
#define MASTER_PREFER_C11_SUPPORTED (MASTER_C_STANDARD >= 2011)
#define MASTER_PREFER_C17_SUPPORTED (MASTER_C_STANDARD >= 2017)
#define MASTER_PREFER_C23_SUPPORTED (MASTER_C_STANDARD >= 2023)
#define MASTER_PREFER_C29_SUPPORTED (MASTER_C_STANDARD >= 2029)
#define MASTER_PREFER_C_SUPPORTED (MASTER_C_STANDARD != 0)

#define MASTER_PREFER_CPP98_SUPPORTED (MASTER_CPP_STANDARD >= 1998)
#define MASTER_PREFER_CPP03_SUPPORTED (MASTER_CPP_STANDARD >= 2003)
#define MASTER_PREFER_CPP11_SUPPORTED (MASTER_CPP_STANDARD >= 2011)
#define MASTER_PREFER_CPP14_SUPPORTED (MASTER_CPP_STANDARD >= 2014)
#define MASTER_PREFER_CPP17_SUPPORTED (MASTER_CPP_STANDARD >= 2017)
#define MASTER_PREFER_CPP20_SUPPORTED (MASTER_CPP_STANDARD >= 2020)
#define MASTER_PREFER_CPP23_SUPPORTED (MASTER_CPP_STANDARD >= 2023)
#define MASTER_PREFER_CPP26_SUPPORTED (MASTER_CPP_STANDARD >= 2026)
#define MASTER_PREFER_CPP_SUPPORTED (MASTER_CPP_STANDARD != 0)

#ifdef MASTER_LIBRARY_INCLUDE_DEPRECATED
#	if (100 * MASTER_LIBRARY_INCLUDE_DEPRECATED + 2 == 200)
#		undef MASTER_LIBRARY_INCLUDE_DEPRECATED
#		define MASTER_LIBRARY_INCLUDE_DEPRECATED 1
#	else
#		if (100 * MASTER_LIBRARY_INCLUDE_DEPRECATED + 2 <= 2)
#			undef MASTER_LIBRARY_INCLUDE_DEPRECATED
#			define MASTER_LIBRARY_INCLUDE_DEPRECATED 0
#		else
#			undef MASTER_LIBRARY_INCLUDE_DEPRECATED
#			define MASTER_LIBRARY_INCLUDE_DEPRECATED 1
#		endif /* #! To 0/1 !# */
#	endif /* #! Defined / Undefined !# */
#endif /* #! assert.h !# */

#ifndef MASTER_LIBRARY_INCLUDE_DEPRECATED
#	define MASTER_LIBRARY_INCLUDE_DEPRECATED 0
#endif /* #! Include Deprecated !# */

/* #! Third-party configuration !# */

#ifdef HAVE_CONFIG_H
#	ifdef MASTER_ERROR_IF_GNU_AUTOCONF
#		ifdef MASTER_PREFER_C89_SUPPORTED
 #			error "Got GNU Autoconfig & user request to send error."
#		else
			MASTER_ERRORRISE "Got GNU Autoconfig & user request to send error."
#		endif /* #! Error !# */
#	elif defined(MASTER_WARNING_IF_GNU_AUTOCONF)
#		ifdef MASTER_COMPILER_WARNING_AVAIL
 #			warning "Got GNU Autoconfig & user request to send warning."
#		endif /* #! Warning !# */
#	elif !defined(MASTER_NO_GNU_AUTOCONF)
#		include <config.h>
#		if !defined(PACKAGE_NAME) || !defined(PACKAGE_VERSION) || !defined(PACKAGE_STRING) || !defined(PACKAGE_TARNAME) || !defined(PACKAGE_BUGREPORT) || !defined(PACKAGE_URL) || !defined(STDC_HEADERS)
#			ifdef MASTER_PREFER_C89_SUPPORTED
 #				error "Expected GNU Autoconfig, but some macroses are missed."
#			else
				MASTER_ERRORRISE "Expected GNU Autoconfig, but some macroses are missed."
#			endif /* #! Error !# */
#		endif /* #! GNU Autoconf check !# */
#	endif /* #! Third-party library !# */
#endif /* #! Got an config.h !# */

/* #! MASTER Enumerate Supported Libraries !# */

/* #! GNU Autoconf !# */

#ifdef HAVE_DOS_H
#	define MASTER_LIBRARY_HAVE_DOS_H 1
#endif /* #! dos.h !# */

#ifdef HAVE_AIO_H
#	define MASTER_LIBRARY_HAVE_AIO_H 1
#endif /* #! aio.h !# */

#ifdef HAVE_ARPA_INET_H
#	define MASTER_LIBRARY_HAVE_ARPA_INET_H 1
#endif /* #! arpa/inet.h !# */

#ifdef HAVE_CPIO_H
#	define MASTER_LIBRARY_HAVE_CPIO_H 1
#endif /* #! cpio.h !# */

#ifdef HAVE_DEVCTL_H
#	define MASTER_LIBRARY_HAVE_DEVCTL_H 1
#endif /* #! devctl.h !# */

#ifdef HAVE_DIRENT_H
#	define MASTER_LIBRARY_HAVE_DIRENT_H 1
#endif /* #! dirent.h !# */

#ifdef HAVE_DLFCN_H
#	define MASTER_LIBRARY_HAVE_DLFCN_H 1
#endif /* #! dlfcn.h !# */

#ifdef HAVE_ENDIAN_H
#	define MASTER_LIBRARY_HAVE_ENDIAN_H 1
#endif /* #! endian.h !# */

#ifdef HAVE_FCNTL_H
#	define MASTER_LIBRARY_HAVE_FCNTL_H 1
#endif /* #! fcntl.h !# */

#ifdef HAVE_FMTMSG_H
#	define MASTER_LIBRARY_HAVE_FMTMSG_H 1
#endif /* #! fmtmsg.h !# */

#ifdef HAVE_FNMATCH_H
#	define MASTER_LIBRARY_HAVE_FNMATCH_H 1
#endif /* #! fnmatch.h !# */

#ifdef HAVE_FTW_H
#	define MASTER_LIBRARY_HAVE_FTW_H 1
#endif /* #! ftw.h !# */

#ifdef HAVE_GLOB_H
#	define MASTER_LIBRARY_HAVE_GLOB_H 1
#endif /* #! glob.h !# */

#ifdef HAVE_GRP_H
#	define MASTER_LIBRARY_HAVE_GRP_H 1
#endif /* #! grp.h !# */

#ifdef HAVE_ICONV_H
#	define MASTER_LIBRARY_HAVE_ICONV_H 1
#endif /* #! iconv.h !# */

#ifdef HAVE_LANGINFO_H
#	define MASTER_LIBRARY_HAVE_LANGINFO_H 1
#endif /* #! langinfo.h !# */

#ifdef HAVE_LIBGEN_H
#	define MASTER_LIBRARY_HAVE_LIBGEN_H 1
#endif /* #! libgen.h !# */

#ifdef HAVE_LIBINTL_H
#	define MASTER_LIBRARY_HAVE_LIBINTL_H 1
#endif /* #! libintl.h !# */

#ifdef HAVE_MONETARY_H
#	define MASTER_LIBRARY_HAVE_MONETARY_H 1
#endif /* #! monetary.h !# */

#ifdef HAVE_MQUEUE_H
#	define MASTER_LIBRARY_HAVE_MQUEUE_H 1
#endif /* #! mqueue.h !# */

#ifdef HAVE_NDBM_H
#	define MASTER_LIBRARY_HAVE_NDBM_H 1
#endif /* #! ndbm.h !# */

#ifdef HAVE_NET_IF_H
#	define MASTER_LIBRARY_HAVE_NET_IF_H 1
#endif /* #! net/if.h !# */

#ifdef HAVE_NETDB_H
#	define MASTER_LIBRARY_HAVE_NETDB_H 1
#endif /* #! netdb.h !# */

#ifdef HAVE_NETINET_IN_H
#	define MASTER_LIBRARY_HAVE_NETINET_IN_H 1
#endif /* #! netinet/in.h !# */

#ifdef HAVE_NETINET_TCP_H
#	define MASTER_LIBRARY_HAVE_NETINET_TCP_H 1
#endif /* #! netinet/tcp.h !# */

#ifdef HAVE_NL_TYPES_H
#	define MASTER_LIBRARY_HAVE_NL_TYPES_H 1
#endif /* #! nl_types.h !# */

#ifdef HAVE_POLL_H
#	define MASTER_LIBRARY_HAVE_POLL_H 1
#endif /* #! poll.h !# */

#ifdef HAVE_PTHREAD_H
#	define MASTER_LIBRARY_HAVE_PTHREAD_H 1
#endif /* #! pthread.h !# */

#ifdef HAVE_PWD_H
#	define MASTER_LIBRARY_HAVE_PWD_H 1
#endif /* #! pwd.h !# */

#ifdef HAVE_REGEX_H
#	define MASTER_LIBRARY_HAVE_REGEX_H 1
#endif /* #! regex.h !# */

#ifdef HAVE_SCHED_H
#	define MASTER_LIBRARY_HAVE_SCHED_H 1
#endif /* #! sched.h !# */

#ifdef HAVE_SEARCH_H
#	define MASTER_LIBRARY_HAVE_SEARCH_H 1
#endif /* #! search.h !# */

#ifdef HAVE_SEMAPHORE_H
#	define MASTER_LIBRARY_HAVE_SEMAPHORE_H 1
#endif /* #! semaphore.h !# */

#ifdef HAVE_SPAWN_H
#	define MASTER_LIBRARY_HAVE_SPAWN_H 1
#endif /* #! spawn.h !# */

#ifdef HAVE_STDALIGN_H
#	define MASTER_LIBRARY_HAVE_STDALIGN_H 1
#endif /* #! stdalign.h !# */

#ifdef HAVE_STRINGS_H
#	define MASTER_LIBRARY_HAVE_STRINGS_H 1
#endif /* #! strings.h !# */

#ifdef HAVE_STROPTS_H
#	define MASTER_LIBRARY_HAVE_STROPTS_H 1
#endif /* #! stropts.h !# */

#ifdef HAVE_SYS_IPC_H
#	define MASTER_LIBRARY_HAVE_SYS_IPC_H 1
#endif /* #! sys/ipc.h !# */

#ifdef HAVE_SYS_MMAN_H
#	define MASTER_LIBRARY_HAVE_SYS_MMAN_H 1
#endif /* #! sys/mman.h !# */

#ifdef HAVE_SYS_MSG_H
#	define MASTER_LIBRARY_HAVE_SYS_MSG_H 1
#endif /* #! sys/msg.h !# */

#ifdef HAVE_SYS_RESOURCE_H
#	define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H 1
#endif /* #! sys/resource.h !# */

#ifdef HAVE_SYS_SELECT_H
#	define MASTER_LIBRARY_HAVE_SYS_SELECT_H 1
#endif /* #! sys/select.h !# */

#ifdef HAVE_SYS_SEM_H
#	define MASTER_LIBRARY_HAVE_SYS_SEM_H 1
#endif /* #! sys/sem.h !# */

#ifdef HAVE_SYS_SHM_H
#	define MASTER_LIBRARY_HAVE_SYS_SHM_H 1
#endif /* #! sys/shm.h !# */

#ifdef HAVE_SYS_SOCKET_H
#	define MASTER_LIBRARY_HAVE_SYS_SOCKET_H 1
#endif /* #! sys/socket.h !# */

#ifdef HAVE_SYS_STAT_H
#	define MASTER_LIBRARY_HAVE_SYS_STAT_H 1
#endif /* #! sys/stat.h !# */

#ifdef HAVE_SYS_STATVFS_H
#	define MASTER_LIBRARY_HAVE_SYS_STATVFS_H 1
#endif /* #! sys/statvfs.h !# */

#ifdef HAVE_SYS_TIME_H
#	define MASTER_LIBRARY_HAVE_SYS_TIME_H 1
#endif /* #! sys/time.h !# */

#ifdef HAVE_SYS_TIMES_H
#	define MASTER_LIBRARY_HAVE_SYS_TIMES_H 1
#endif /* #! sys/times.h !# */

#ifdef HAVE_SYS_TYPES_H
#	define MASTER_LIBRARY_HAVE_SYS_TYPES_H 1
#endif /* #! sys/types.h !# */

#ifdef HAVE_SYS_UIO_H
#	define MASTER_LIBRARY_HAVE_SYS_UIO_H 1
#endif /* #! sys/uio.h !# */

#ifdef HAVE_SYS_UN_H
#	define MASTER_LIBRARY_HAVE_SYS_UN_H 1
#endif /* #! sys/un.h !# */

#ifdef HAVE_SYS_UTSNAME_H
#	define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H 1
#endif /* #! sys/utsname.h !# */

#ifdef HAVE_SYS_WAIT_H
#	define MASTER_LIBRARY_HAVE_SYS_WAIT_H 1
#endif /* #! sys/wait.h !# */

#ifdef HAVE_SYSLOG_H
#	define MASTER_LIBRARY_HAVE_SYSLOG_H 1
#endif /* #! syslog.h !# */

#ifdef HAVE_TAR_H
#	define MASTER_LIBRARY_HAVE_TAR_H 1
#endif /* #! tar.h !# */

#ifdef HAVE_TERMIOS_H
#	define MASTER_LIBRARY_HAVE_TERMIOS_H 1
#endif /* #! termios.h !# */

#ifdef HAVE_TRACE_H
#	define MASTER_LIBRARY_HAVE_TRACE_H 1
#endif /* #! trace.h !# */

#ifdef HAVE_UCONTEXT_H
#	define MASTER_LIBRARY_HAVE_UCONTEXT_H 1
#endif /* #! ucontext.h !# */

#ifdef HAVE_ULIMIT_H
#	define MASTER_LIBRARY_HAVE_ULIMIT_H 1
#endif /* #! ulimit.h !# */

#ifdef HAVE_UNISTD_H
#	define MASTER_LIBRARY_HAVE_UNISTD_H 1
#endif /* #! unistd.h !# */

#ifdef HAVE_UTIME_H
#	define MASTER_LIBRARY_HAVE_UTIME_H 1
#endif /* #! utime.h !# */

#ifdef HAVE_UTMPX_H
#	define MASTER_LIBRARY_HAVE_UTMPX_H 1
#endif /* #! utmpx.h !# */

#ifdef HAVE_WORDEXP_H
#	define MASTER_LIBRARY_HAVE_WORDEXP_H 1
#endif /* #! wordexp.h !# */

#ifdef HAVE_WINDOWS_H
#	define MASTER_LIBRARY_HAVE_WINDOWS_H 1
#endif /* #! windows.h !# */

#ifdef HAVE_CONIO_H
#	define MASTER_LIBRARY_HAVE_CONIO_H 1
#endif /* #! conio.h !# */

#ifdef HAVE_BASETSD_H
#	define MASTER_LIBRARY_HAVE_BASETSD_H 1
#endif /* #! basetsd.h !# */

#ifdef HAVE_GUIDDEF_H
#	define MASTER_LIBRARY_HAVE_GUIDDEF_H 1
#endif /* #! guiddef.h !# */

#ifdef HAVE_IMM_H
#	define MASTER_LIBRARY_HAVE_IMM_H 1
#endif /* #! imm.h !# */

#ifdef HAVE_WINBASE_H
#	define MASTER_LIBRARY_HAVE_WINBASE_H 1
#endif /* #! winbase.h !# */

#ifdef HAVE_WINCON_H
#	define MASTER_LIBRARY_HAVE_WINCON_H 1
#endif /* #! wincon.h !# */

#ifdef HAVE_WINDEF_H
#	define MASTER_LIBRARY_HAVE_WINDEF_H 1
#endif /* #! windef.h !# */

#ifdef HAVE_WINERROR_H
#	define MASTER_LIBRARY_HAVE_WINERROR_H 1
#endif /* #! winerror.h !# */

#ifdef HAVE_WINGDI_H
#	define MASTER_LIBRARY_HAVE_WINGDI_H 1
#endif /* #! wingdi.h !# */

#ifdef HAVE_WINNETWK_H
#	define MASTER_LIBRARY_HAVE_WINNETWK_H 1
#endif /* #! winnetwk.h !# */

#ifdef HAVE_WINNLS_H
#	define MASTER_LIBRARY_HAVE_WINNLS_H 1
#endif /* #! winnls.h !# */

#ifdef HAVE_WINNT_H
#	define MASTER_LIBRARY_HAVE_WINNT_H 1
#endif /* #! winnt.h !# */

#ifdef HAVE_WINREG_H
#	define MASTER_LIBRARY_HAVE_WINREG_H 1
#endif /* #! winreg.h !# */

#ifdef HAVE_WINSVC_H
#	define MASTER_LIBRARY_HAVE_WINSVC_H 1
#endif /* #! winsvc.h !# */

#ifdef HAVE_WINUSER_H
#	define MASTER_LIBRARY_HAVE_WINUSER_H 1
#endif /* #! winuser.h !# */

#ifdef HAVE_WINVER_H
#	define MASTER_LIBRARY_HAVE_WINVER_H 1
#endif /* #! winver.h !# */

#ifdef HAVE_CDERR_H
#	define MASTER_LIBRARY_HAVE_CDERR_H 1
#endif /* #! cderr.h !# */

#ifdef HAVE_COMMLDG_H
#	define MASTER_LIBRARY_HAVE_COMMLDG_H 1
#endif /* #! commldg.h !# */

#ifdef HAVE_DDE_H
#	define MASTER_LIBRARY_HAVE_DDE_H 1
#endif /* #! dde.h !# */

#ifdef HAVE_DDEML_H
#	define MASTER_LIBRARY_HAVE_DDEML_H 1
#endif /* #! ddeml.h !# */

#ifdef HAVE_DLGS_H
#	define MASTER_LIBRARY_HAVE_DLGS_H 1
#endif /* #! dlgs.h !# */

#ifdef HAVE_LZEXPAND_H
#	define MASTER_LIBRARY_HAVE_LZEXPAND_H 1
#endif /* #! lzexpand.h !# */

#ifdef HAVE_MMSYSTEM_H
#	define MASTER_LIBRARY_HAVE_MMSYSTEM_H 1
#endif /* #! mmsystem.h !# */

#ifdef HAVE_NB3MASTER_ANSWER_N_H
#	define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H 1
#endif /* #! nb3master/answer/n.h !# */

#ifdef HAVE_RPC_H
#	define MASTER_LIBRARY_HAVE_RPC_H 1
#endif /* #! rpc.h !# */

#ifdef HAVE_SHELLAPI_H
#	define MASTER_LIBRARY_HAVE_SHELLAPI_H 1
#endif /* #! shellapi.h !# */

#ifdef HAVE_WINCRYPT_H
#	define MASTER_LIBRARY_HAVE_WINCRYPT_H 1
#endif /* #! wincrypt.h !# */

#ifdef HAVE_WINPERF_H
#	define MASTER_LIBRARY_HAVE_WINPERF_H 1
#endif /* #! winperf.h !# */

#ifdef HAVE_WINRESRC_H
#	define MASTER_LIBRARY_HAVE_WINRESRC_H 1
#endif /* #! winresrc.h !# */

#ifdef HAVE_WINSOCK_H
#	define MASTER_LIBRARY_HAVE_WINSOCK_H 1
#endif /* #! winsock.h !# */

#ifdef HAVE_WINSPOOL_H
#	define MASTER_LIBRARY_HAVE_WINSPOOL_H 1
#endif /* #! winspool.h !# */

#ifdef HAVE_WINBGIM_H
#	define MASTER_LIBRARY_HAVE_WINBGIM_H 1
#endif /* #! winbgim.h !# */

#ifdef HAVE_OLE2_H
#	define MASTER_LIBRARY_HAVE_OLE2_H 1
#endif /* #! ole2.h !# */

#ifdef HAVE_OBJBASE_H
#	define MASTER_LIBRARY_HAVE_OBJBASE_H 1
#endif /* #! objbase.h !# */

#ifdef HAVE_OLEAUTO_H
#	define MASTER_LIBRARY_HAVE_OLEAUTO_H 1
#endif /* #! oleauto.h !# */

#ifdef HAVE_OLETLID_H
#	define MASTER_LIBRARY_HAVE_OLETLID_H 1
#endif /* #! oletlid.h !# */

#ifdef HAVE_ASSERT_H
#	define MASTER_LIBRARY_HAVE_ASSERT_H 1
#endif /* #! assert.h !# */

#ifdef HAVE_COMPLEX_H
#	define MASTER_LIBRARY_HAVE_COMPLEX_H 1
#endif /* #! complex.h !# */

#ifdef HAVE_CTYPE_H
#	define MASTER_LIBRARY_HAVE_CTYPE_H 1
#endif /* #! ctype.h !# */

#ifdef HAVE_ERRNO_H
#	define MASTER_LIBRARY_HAVE_ERRNO_H 1
#endif /* #! errno.h !# */

#ifdef HAVE_FENV_H
#	define MASTER_LIBRARY_HAVE_FENV_H 1
#endif /* #! fenv.h !# */

#ifdef HAVE_FLOAT_H
#	define MASTER_LIBRARY_HAVE_FLOAT_H 1
#endif /* #! float.h !# */

#ifdef HAVE_INTTYPES_H
#	define MASTER_LIBRARY_HAVE_INTTYPES_H 1
#endif /* #! inttypes.h !# */

#ifdef HAVE_ISO646_H
#	define MASTER_LIBRARY_HAVE_ISO646_H 1
#endif /* #! iso646.h !# */

#ifdef HAVE_LIMITS_H
#	define MASTER_LIBRARY_HAVE_LIMITS_H 1
#endif /* #! limits.h !# */

#ifdef HAVE_LOCALE_H
#	define MASTER_LIBRARY_HAVE_LOCALE_H 1
#endif /* #! locale.h !# */

#ifdef HAVE_MATH_H
#	define MASTER_LIBRARY_HAVE_MATH_H 1
#endif /* #! math.h !# */

#ifdef HAVE_SETJMP_H
#	define MASTER_LIBRARY_HAVE_SETJMP_H 1
#endif /* #! setjmp.h !# */

#ifdef HAVE_SIGNAL_H
#	define MASTER_LIBRARY_HAVE_SIGNAL_H 1
#endif /* #! signal.h !# */

#ifdef HAVE_STDARG_H
#	define MASTER_LIBRARY_HAVE_STDARG_H 1
#endif /* #! stdarg.h !# */

#ifdef HAVE_STDATOMIC_H
#	define MASTER_LIBRARY_HAVE_STDATOMIC_H 1
#endif /* #! stdatomic.h !# */

#ifdef HAVE_STDBIT_H
#	define MASTER_LIBRARY_HAVE_STDBIT_H 1
#endif /* #! stdbit.h !# */

#ifdef HAVE_STDBOOL_H
#	define MASTER_LIBRARY_HAVE_STDBOOL_H 1
#endif /* #! stdbool.h !# */

#ifdef HAVE_STDCKDINT_H
#	define MASTER_LIBRARY_HAVE_STDCKDINT_H 1
#endif /* #! stdckdint.h !# */

#ifdef HAVE_STDDEF_H
#	define MASTER_LIBRARY_HAVE_STDDEF_H 1
#endif /* #! stddef.h !# */

#ifdef HAVE_STDINT_H
#	define MASTER_LIBRARY_HAVE_STDINT_H 1
#endif /* #! stdint.h !# */

#ifdef HAVE_STDIO_H
#	define MASTER_LIBRARY_HAVE_STDIO_H 1
#endif /* #! stdio.h !# */

#ifdef HAVE_STDLIB_H
#	define MASTER_LIBRARY_HAVE_STDLIB_H 1
#endif /* #! stdlib.h !# */

#ifdef HAVE_STDMCHAR_H
#	define MASTER_LIBRARY_HAVE_STDMCHAR_H 1
#endif /* #! stdmchar.h !# */

#ifdef HAVE_STDNORETURN_H
#	define MASTER_LIBRARY_HAVE_STDNORETURN_H 1
#endif /* #! stdnoreturn.h !# */

#ifdef HAVE_STRING_H
#	define MASTER_LIBRARY_HAVE_STRING_H 1
#endif /* #! string.h !# */

#ifdef HAVE_TGMATH_H
#	define MASTER_LIBRARY_HAVE_TGMATH_H 1
#endif /* #! tgmath.h !# */

#ifdef HAVE_THREADS_H
#	define MASTER_LIBRARY_HAVE_THREADS_H 1
#endif /* #! threads.h !# */

#ifdef HAVE_TIME_H
#	define MASTER_LIBRARY_HAVE_TIME_H 1
#endif /* #! time.h !# */

#ifdef HAVE_UCHAR_H
#	define MASTER_LIBRARY_HAVE_UCHAR_H 1
#endif /* #! uchar.h !# */

#ifdef HAVE_WCHAR_H
#	define MASTER_LIBRARY_HAVE_WCHAR_H 1
#endif /* #! wchar.h !# */

#ifdef HAVE_WCTYPE_H
#	define MASTER_LIBRARY_HAVE_WCTYPE_H 1
#endif /* #! wctype.h !# */

#ifdef HAVE_CSTDLIB
#	define MASTER_LIBRARY_HAVE_CSTDLIB 1
#endif /* #! cstdlib !# */

#ifdef HAVE_EXECUTION
#	define MASTER_LIBRARY_HAVE_EXECUTION 1
#endif /* #! execution !# */

#ifdef HAVE_CFLOAT
#	define MASTER_LIBRARY_HAVE_CFLOAT 1
#endif /* #! cfloat !# */

#ifdef HAVE_CLIMITS
#	define MASTER_LIBRARY_HAVE_CLIMITS 1
#endif /* #! climits !# */

#ifdef HAVE_COMPARE
#	define MASTER_LIBRARY_HAVE_COMPARE 1
#endif /* #! compare !# */

#ifdef HAVE_CONTRACTS
#	define MASTER_LIBRARY_HAVE_CONTRACTS 1
#endif /* #! contracts !# */

#ifdef HAVE_COROUTINE
#	define MASTER_LIBRARY_HAVE_COROUTINE 1
#endif /* #! coroutine !# */

#ifdef HAVE_CSETJMP
#	define MASTER_LIBRARY_HAVE_CSETJMP 1
#endif /* #! csetjmp !# */

#ifdef HAVE_CSIGNAL
#	define MASTER_LIBRARY_HAVE_CSIGNAL 1
#endif /* #! csignal !# */

#ifdef HAVE_CSTDARG
#	define MASTER_LIBRARY_HAVE_CSTDARG 1
#endif /* #! cstdarg !# */

#ifdef HAVE_CSTDDEF
#	define MASTER_LIBRARY_HAVE_CSTDDEF 1
#endif /* #! cstddef !# */

#ifdef HAVE_CSTDINT
#	define MASTER_LIBRARY_HAVE_CSTDINT 1
#endif /* #! cstdint !# */

#ifdef HAVE_EXCEPTION
#	define MASTER_LIBRARY_HAVE_EXCEPTION 1
#endif /* #! exception !# */

#ifdef HAVE_INITIALIZER_LIST
#	define MASTER_LIBRARY_HAVE_INITIALIZER_LIST 1
#endif /* #! initializer_list !# */

#ifdef HAVE_LIMITS
#	define MASTER_LIBRARY_HAVE_LIMITS 1
#endif /* #! limits !# */

#ifdef HAVE_NEW
#	define MASTER_LIBRARY_HAVE_NEW 1
#endif /* #! new !# */

#ifdef HAVE_SOURCE_LOCATION
#	define MASTER_LIBRARY_HAVE_SOURCE_LOCATION 1
#endif /* #! source_location !# */

#ifdef HAVE_STDFLOAT
#	define MASTER_LIBRARY_HAVE_STDFLOAT 1
#endif /* #! stdfloat !# */

#ifdef HAVE_TYPEINDEX
#	define MASTER_LIBRARY_HAVE_TYPEINDEX 1
#endif /* #! typeindex !# */

#ifdef HAVE_TYPEINFO
#	define MASTER_LIBRARY_HAVE_TYPEINFO 1
#endif /* #! typeinfo !# */

#ifdef HAVE_VERSION
#	define MASTER_LIBRARY_HAVE_VERSION 1
#endif /* #! version !# */

#ifdef HAVE_CONCEPTS
#	define MASTER_LIBRARY_HAVE_CONCEPTS 1
#endif /* #! concepts !# */

#ifdef HAVE_CASSERT
#	define MASTER_LIBRARY_HAVE_CASSERT 1
#endif /* #! cassert !# */

#ifdef HAVE_CERRNO
#	define MASTER_LIBRARY_HAVE_CERRNO 1
#endif /* #! cerrno !# */

#ifdef HAVE_DEBUGGING
#	define MASTER_LIBRARY_HAVE_DEBUGGING 1
#endif /* #! debugging !# */

#ifdef HAVE_STACKTRACE
#	define MASTER_LIBRARY_HAVE_STACKTRACE 1
#endif /* #! stacktrace !# */

#ifdef HAVE_STDEXCEPT
#	define MASTER_LIBRARY_HAVE_STDEXCEPT 1
#endif /* #! stdexcept !# */

#ifdef HAVE_SYSTEM_ERROR
#	define MASTER_LIBRARY_HAVE_SYSTEM_ERROR 1
#endif /* #! system_error !# */

#ifdef HAVE_MEMORY
#	define MASTER_LIBRARY_HAVE_MEMORY 1
#endif /* #! memory !# */

#ifdef HAVE_MEMORY_RESOURCE
#	define MASTER_LIBRARY_HAVE_MEMORY_RESOURCE 1
#endif /* #! memory_resource !# */

#ifdef HAVE_SCOPED_ALLOCATOR
#	define MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR 1
#endif /* #! scoped_allocator !# */

#ifdef HAVE_RATIO
#	define MASTER_LIBRARY_HAVE_RATIO 1
#endif /* #! ratio !# */

#ifdef HAVE_TYPE_TRAITS
#	define MASTER_LIBRARY_HAVE_TYPE_TRAITS 1
#endif /* #! type_traits !# */

#ifdef HAVE_ANY
#	define MASTER_LIBRARY_HAVE_ANY 1
#endif /* #! any !# */

#ifdef HAVE_BIT
#	define MASTER_LIBRARY_HAVE_BIT 1
#endif /* #! bit !# */

#ifdef HAVE_BITSET
#	define MASTER_LIBRARY_HAVE_BITSET 1
#endif /* #! bitset !# */

#ifdef HAVE_EXPECTED
#	define MASTER_LIBRARY_HAVE_EXPECTED 1
#endif /* #! expected !# */

#ifdef HAVE_FUNCTIONAL
#	define MASTER_LIBRARY_HAVE_FUNCTIONAL 1
#endif /* #! functional !# */

#ifdef HAVE_OPTIONAL
#	define MASTER_LIBRARY_HAVE_OPTIONAL 1
#endif /* #! optional !# */

#ifdef HAVE_TUPLE
#	define MASTER_LIBRARY_HAVE_TUPLE 1
#endif /* #! tuple !# */

#ifdef HAVE_UTILITY
#	define MASTER_LIBRARY_HAVE_UTILITY 1
#endif /* #! utility !# */

#ifdef HAVE_VARIANT
#	define MASTER_LIBRARY_HAVE_VARIANT 1
#endif /* #! variant !# */

#ifdef HAVE_ARRAY
#	define MASTER_LIBRARY_HAVE_ARRAY 1
#endif /* #! array !# */

#ifdef HAVE_DEQUE
#	define MASTER_LIBRARY_HAVE_DEQUE 1
#endif /* #! deque !# */

#ifdef HAVE_FLAT_MAP
#	define MASTER_LIBRARY_HAVE_FLAT_MAP 1
#endif /* #! flat_map !# */

#ifdef HAVE_FLAT_SET
#	define MASTER_LIBRARY_HAVE_FLAT_SET 1
#endif /* #! flat_set !# */

#ifdef HAVE_FORWARD_LIST
#	define MASTER_LIBRARY_HAVE_FORWARD_LIST 1
#endif /* #! forward_list !# */

#ifdef HAVE_HIVE
#	define MASTER_LIBRARY_HAVE_HIVE 1
#endif /* #! hive !# */

#ifdef HAVE_INPLACE_VECTOR
#	define MASTER_LIBRARY_HAVE_INPLACE_VECTOR 1
#endif /* #! inplace_vector !# */

#ifdef HAVE_LIST
#	define MASTER_LIBRARY_HAVE_LIST 1
#endif /* #! list !# */

#ifdef HAVE_MAP
#	define MASTER_LIBRARY_HAVE_MAP 1
#endif /* #! map !# */

#ifdef HAVE_MDSPAN
#	define MASTER_LIBRARY_HAVE_MDSPAN 1
#endif /* #! mdspan !# */

#ifdef HAVE_QUEUE
#	define MASTER_LIBRARY_HAVE_QUEUE 1
#endif /* #! queue !# */

#ifdef HAVE_SET
#	define MASTER_LIBRARY_HAVE_SET 1
#endif /* #! set !# */

#ifdef HAVE_SPAN
#	define MASTER_LIBRARY_HAVE_SPAN 1
#endif /* #! span !# */

#ifdef HAVE_STACK
#	define MASTER_LIBRARY_HAVE_STACK 1
#endif /* #! stack !# */

#ifdef HAVE_UNORDERED_MAP
#	define MASTER_LIBRARY_HAVE_UNORDERED_MAP 1
#endif /* #! unordered_map !# */

#ifdef HAVE_UNORDERED_SET
#	define MASTER_LIBRARY_HAVE_UNORDERED_SET 1
#endif /* #! unordered_set !# */

#ifdef HAVE_VECTOR
#	define MASTER_LIBRARY_HAVE_VECTOR 1
#endif /* #! vector !# */

#ifdef HAVE_ITERATOR
#	define MASTER_LIBRARY_HAVE_ITERATOR 1
#endif /* #! iterator !# */

#ifdef HAVE_GENERATOR
#	define MASTER_LIBRARY_HAVE_GENERATOR 1
#endif /* #! generator !# */

#ifdef HAVE_RANGES
#	define MASTER_LIBRARY_HAVE_RANGES 1
#endif /* #! ranges !# */

#ifdef HAVE_ALGORITHM
#	define MASTER_LIBRARY_HAVE_ALGORITHM 1
#endif /* #! algorithm !# */

#ifdef HAVE_NUMERIC
#	define MASTER_LIBRARY_HAVE_NUMERIC 1
#endif /* #! numeric !# */

#ifdef HAVE_CSTRING
#	define MASTER_LIBRARY_HAVE_CSTRING 1
#endif /* #! cstring !# */

#ifdef HAVE_STRING
#	define MASTER_LIBRARY_HAVE_STRING 1
#endif /* #! string !# */

#ifdef HAVE_STRING_VIEW
#	define MASTER_LIBRARY_HAVE_STRING_VIEW 1
#endif /* #! string_view !# */

#ifdef HAVE_CCTYPE
#	define MASTER_LIBRARY_HAVE_CCTYPE 1
#endif /* #! cctype !# */

#ifdef HAVE_CHARCONV
#	define MASTER_LIBRARY_HAVE_CHARCONV 1
#endif /* #! charconv !# */

#ifdef HAVE_CLOCALE
#	define MASTER_LIBRARY_HAVE_CLOCALE 1
#endif /* #! clocale !# */

#ifdef HAVE_CODECVT
#	define MASTER_LIBRARY_HAVE_CODECVT 1
#endif /* #! codecvt !# */

#ifdef HAVE_CUCHAR
#	define MASTER_LIBRARY_HAVE_CUCHAR 1
#endif /* #! cuchar !# */

#ifdef HAVE_CWCHAR
#	define MASTER_LIBRARY_HAVE_CWCHAR 1
#endif /* #! cwchar !# */

#ifdef HAVE_CWCTYPE
#	define MASTER_LIBRARY_HAVE_CWCTYPE 1
#endif /* #! cwctype !# */

#ifdef HAVE_FORMAT
#	define MASTER_LIBRARY_HAVE_FORMAT 1
#endif /* #! format !# */

#ifdef HAVE_LOCALE
#	define MASTER_LIBRARY_HAVE_LOCALE 1
#endif /* #! locale !# */

#ifdef HAVE_REGEX
#	define MASTER_LIBRARY_HAVE_REGEX 1
#endif /* #! regex !# */

#ifdef HAVE_TEXT_ENCODING
#	define MASTER_LIBRARY_HAVE_TEXT_ENCODING 1
#endif /* #! text_encoding !# */

#ifdef HAVE_CFENV
#	define MASTER_LIBRARY_HAVE_CFENV 1
#endif /* #! cfenv !# */

#ifdef HAVE_CMATH
#	define MASTER_LIBRARY_HAVE_CMATH 1
#endif /* #! cmath !# */

#ifdef HAVE_COMPLEX
#	define MASTER_LIBRARY_HAVE_COMPLEX 1
#endif /* #! complex !# */

#ifdef HAVE_LINALG
#	define MASTER_LIBRARY_HAVE_LINALG 1
#endif /* #! linalg !# */

#ifdef HAVE_NUMBERS
#	define MASTER_LIBRARY_HAVE_NUMBERS 1
#endif /* #! numbers !# */

#ifdef HAVE_RANDOM
#	define MASTER_LIBRARY_HAVE_RANDOM 1
#endif /* #! random !# */

#ifdef HAVE_SIMD
#	define MASTER_LIBRARY_HAVE_SIMD 1
#endif /* #! simd !# */

#ifdef HAVE_VALARRAY
#	define MASTER_LIBRARY_HAVE_VALARRAY 1
#endif /* #! valarray !# */

#ifdef HAVE_CHRONO
#	define MASTER_LIBRARY_HAVE_CHRONO 1
#endif /* #! chrono !# */

#ifdef HAVE_CTIME
#	define MASTER_LIBRARY_HAVE_CTIME 1
#endif /* #! ctime !# */

#ifdef HAVE_CINTTYPES
#	define MASTER_LIBRARY_HAVE_CINTTYPES 1
#endif /* #! cinttypes !# */

#ifdef HAVE_CSTDIO
#	define MASTER_LIBRARY_HAVE_CSTDIO 1
#endif /* #! cstdio !# */

#ifdef HAVE_FILESYSTEM
#	define MASTER_LIBRARY_HAVE_FILESYSTEM 1
#endif /* #! filesystem !# */

#ifdef HAVE_FSTREAM
#	define MASTER_LIBRARY_HAVE_FSTREAM 1
#endif /* #! fstream !# */

#ifdef HAVE_IOMANIP
#	define MASTER_LIBRARY_HAVE_IOMANIP 1
#endif /* #! iomanip !# */

#ifdef HAVE_IOS
#	define MASTER_LIBRARY_HAVE_IOS 1
#endif /* #! ios !# */

#ifdef HAVE_IOSFWD
#	define MASTER_LIBRARY_HAVE_IOSFWD 1
#endif /* #! iosfwd !# */

#ifdef HAVE_IOSTREAM
#	define MASTER_LIBRARY_HAVE_IOSTREAM 1
#endif /* #! iostream !# */

#ifdef HAVE_ISTREAM
#	define MASTER_LIBRARY_HAVE_ISTREAM 1
#endif /* #! istream !# */

#ifdef HAVE_OSTREAM
#	define MASTER_LIBRARY_HAVE_OSTREAM 1
#endif /* #! ostream !# */

#ifdef HAVE_PRINT
#	define MASTER_LIBRARY_HAVE_PRINT 1
#endif /* #! print !# */

#ifdef HAVE_SPANSTREAM
#	define MASTER_LIBRARY_HAVE_SPANSTREAM 1
#endif /* #! spanstream !# */

#ifdef HAVE_SSTREAM
#	define MASTER_LIBRARY_HAVE_SSTREAM 1
#endif /* #! sstream !# */

#ifdef HAVE_STREAMBUF
#	define MASTER_LIBRARY_HAVE_STREAMBUF 1
#endif /* #! streambuf !# */

#ifdef HAVE_STRSTREAM
#	define MASTER_LIBRARY_HAVE_STRSTREAM 1
#endif /* #! strstream !# */

#ifdef HAVE_SYNCSTREAM
#	define MASTER_LIBRARY_HAVE_SYNCSTREAM 1
#endif /* #! syncstream !# */

#ifdef HAVE_ATOMIC
#	define MASTER_LIBRARY_HAVE_ATOMIC 1
#endif /* #! atomic !# */

#ifdef HAVE_BARRIER
#	define MASTER_LIBRARY_HAVE_BARRIER 1
#endif /* #! barrier !# */

#ifdef HAVE_CONDITION_VARIABLE
#	define MASTER_LIBRARY_HAVE_CONDITION_VARIABLE 1
#endif /* #! condition_variable !# */

#ifdef HAVE_FUTURE
#	define MASTER_LIBRARY_HAVE_FUTURE 1
#endif /* #! future !# */

#ifdef HAVE_HAZARD_POINTER
#	define MASTER_LIBRARY_HAVE_HAZARD_POINTER 1
#endif /* #! hazard_pointer !# */

#ifdef HAVE_LATCH
#	define MASTER_LIBRARY_HAVE_LATCH 1
#endif /* #! latch !# */

#ifdef HAVE_MUTEX
#	define MASTER_LIBRARY_HAVE_MUTEX 1
#endif /* #! mutex !# */

#ifdef HAVE_RCU
#	define MASTER_LIBRARY_HAVE_RCU 1
#endif /* #! rcu !# */

#ifdef HAVE_SEMAPHORE
#	define MASTER_LIBRARY_HAVE_SEMAPHORE 1
#endif /* #! semaphore !# */

#ifdef HAVE_SHARED_MUTEX
#	define MASTER_LIBRARY_HAVE_SHARED_MUTEX 1
#endif /* #! shared_mutex !# */

#ifdef HAVE_STOP_TOKEN
#	define MASTER_LIBRARY_HAVE_STOP_TOKEN 1
#endif /* #! stop_token !# */

#ifdef HAVE_THREAD
#	define MASTER_LIBRARY_HAVE_THREAD 1
#endif /* #! thread !# */

#ifdef HAVE_CCOMPLEX
#	define MASTER_LIBRARY_HAVE_CCOMPLEX 1
#endif /* #! ccomplex !# */

#ifdef HAVE_CTGMATH
#	define MASTER_LIBRARY_HAVE_CTGMATH 1
#endif /* #! ctgmath !# */

#ifdef HAVE_CISO646
#	define MASTER_LIBRARY_HAVE_CISO646 1
#endif /* #! ciso646 !# */

#ifdef HAVE_CSTDALIGN
#	define MASTER_LIBRARY_HAVE_CSTDALIGN 1
#endif /* #! cstdalign !# */

#ifdef HAVE_CSTDBOOL
#	define MASTER_LIBRARY_HAVE_CSTDBOOL 1
#endif /* #! cstdbool !# */

/* #! Normalisation Of Macroses !# */

#ifdef MASTER_LIBRARY_HAVE_DOS_H
#	define MASTER_LIBRARY_HAVE_DOS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DOS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_DOS_H
#		define MASTER_LIBRARY_HAVE_DOS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DOS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DOS_H
#			define MASTER_LIBRARY_HAVE_DOS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DOS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DOS_H
#				define MASTER_LIBRARY_HAVE_DOS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_DOS_H
#				define MASTER_LIBRARY_HAVE_DOS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! dos.h !# */

#ifdef MASTER_LIBRARY_HAVE_AIO_H
#	define MASTER_LIBRARY_HAVE_AIO_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_AIO_H) == 40001
#		undef MASTER_LIBRARY_HAVE_AIO_H
#		define MASTER_LIBRARY_HAVE_AIO_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_AIO_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_AIO_H
#			define MASTER_LIBRARY_HAVE_AIO_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_AIO_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_AIO_H
#				define MASTER_LIBRARY_HAVE_AIO_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_AIO_H
#				define MASTER_LIBRARY_HAVE_AIO_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! aio.h !# */

#ifdef MASTER_LIBRARY_HAVE_ARPA_INET_H
#	define MASTER_LIBRARY_HAVE_ARPA_INET_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ARPA_INET_H) == 40001
#		undef MASTER_LIBRARY_HAVE_ARPA_INET_H
#		define MASTER_LIBRARY_HAVE_ARPA_INET_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ARPA_INET_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ARPA_INET_H
#			define MASTER_LIBRARY_HAVE_ARPA_INET_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ARPA_INET_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ARPA_INET_H
#				define MASTER_LIBRARY_HAVE_ARPA_INET_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_ARPA_INET_H
#				define MASTER_LIBRARY_HAVE_ARPA_INET_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! arpa/inet.h !# */

#ifdef MASTER_LIBRARY_HAVE_CPIO_H
#	define MASTER_LIBRARY_HAVE_CPIO_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CPIO_H) == 40001
#		undef MASTER_LIBRARY_HAVE_CPIO_H
#		define MASTER_LIBRARY_HAVE_CPIO_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CPIO_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CPIO_H
#			define MASTER_LIBRARY_HAVE_CPIO_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CPIO_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CPIO_H
#				define MASTER_LIBRARY_HAVE_CPIO_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_CPIO_H
#				define MASTER_LIBRARY_HAVE_CPIO_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cpio.h !# */

#ifdef MASTER_LIBRARY_HAVE_DEVCTL_H
#	define MASTER_LIBRARY_HAVE_DEVCTL_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DEVCTL_H) == 40001
#		undef MASTER_LIBRARY_HAVE_DEVCTL_H
#		define MASTER_LIBRARY_HAVE_DEVCTL_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DEVCTL_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DEVCTL_H
#			define MASTER_LIBRARY_HAVE_DEVCTL_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DEVCTL_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DEVCTL_H
#				define MASTER_LIBRARY_HAVE_DEVCTL_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_DEVCTL_H
#				define MASTER_LIBRARY_HAVE_DEVCTL_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! devctl.h !# */

#ifdef MASTER_LIBRARY_HAVE_DIRENT_H
#	define MASTER_LIBRARY_HAVE_DIRENT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DIRENT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_DIRENT_H
#		define MASTER_LIBRARY_HAVE_DIRENT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DIRENT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DIRENT_H
#			define MASTER_LIBRARY_HAVE_DIRENT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DIRENT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DIRENT_H
#				define MASTER_LIBRARY_HAVE_DIRENT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_DIRENT_H
#				define MASTER_LIBRARY_HAVE_DIRENT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! dirent.h !# */

#ifdef MASTER_LIBRARY_HAVE_DLFCN_H
#	define MASTER_LIBRARY_HAVE_DLFCN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DLFCN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_DLFCN_H
#		define MASTER_LIBRARY_HAVE_DLFCN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DLFCN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DLFCN_H
#			define MASTER_LIBRARY_HAVE_DLFCN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DLFCN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DLFCN_H
#				define MASTER_LIBRARY_HAVE_DLFCN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_DLFCN_H
#				define MASTER_LIBRARY_HAVE_DLFCN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! dlfcn.h !# */

#ifdef MASTER_LIBRARY_HAVE_ENDIAN_H
#	define MASTER_LIBRARY_HAVE_ENDIAN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ENDIAN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_ENDIAN_H
#		define MASTER_LIBRARY_HAVE_ENDIAN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ENDIAN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ENDIAN_H
#			define MASTER_LIBRARY_HAVE_ENDIAN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ENDIAN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ENDIAN_H
#				define MASTER_LIBRARY_HAVE_ENDIAN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_ENDIAN_H
#				define MASTER_LIBRARY_HAVE_ENDIAN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! endian.h !# */

#ifdef MASTER_LIBRARY_HAVE_FCNTL_H
#	define MASTER_LIBRARY_HAVE_FCNTL_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FCNTL_H) == 40001
#		undef MASTER_LIBRARY_HAVE_FCNTL_H
#		define MASTER_LIBRARY_HAVE_FCNTL_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FCNTL_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FCNTL_H
#			define MASTER_LIBRARY_HAVE_FCNTL_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FCNTL_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FCNTL_H
#				define MASTER_LIBRARY_HAVE_FCNTL_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_FCNTL_H
#				define MASTER_LIBRARY_HAVE_FCNTL_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! fcntl.h !# */

#ifdef MASTER_LIBRARY_HAVE_FMTMSG_H
#	define MASTER_LIBRARY_HAVE_FMTMSG_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FMTMSG_H) == 40001
#		undef MASTER_LIBRARY_HAVE_FMTMSG_H
#		define MASTER_LIBRARY_HAVE_FMTMSG_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FMTMSG_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FMTMSG_H
#			define MASTER_LIBRARY_HAVE_FMTMSG_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FMTMSG_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FMTMSG_H
#				define MASTER_LIBRARY_HAVE_FMTMSG_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_FMTMSG_H
#				define MASTER_LIBRARY_HAVE_FMTMSG_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! fmtmsg.h !# */

#ifdef MASTER_LIBRARY_HAVE_FNMATCH_H
#	define MASTER_LIBRARY_HAVE_FNMATCH_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FNMATCH_H) == 40001
#		undef MASTER_LIBRARY_HAVE_FNMATCH_H
#		define MASTER_LIBRARY_HAVE_FNMATCH_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FNMATCH_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FNMATCH_H
#			define MASTER_LIBRARY_HAVE_FNMATCH_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FNMATCH_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FNMATCH_H
#				define MASTER_LIBRARY_HAVE_FNMATCH_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_FNMATCH_H
#				define MASTER_LIBRARY_HAVE_FNMATCH_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! fnmatch.h !# */

#ifdef MASTER_LIBRARY_HAVE_FTW_H
#	define MASTER_LIBRARY_HAVE_FTW_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FTW_H) == 40001
#		undef MASTER_LIBRARY_HAVE_FTW_H
#		define MASTER_LIBRARY_HAVE_FTW_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FTW_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FTW_H
#			define MASTER_LIBRARY_HAVE_FTW_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FTW_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FTW_H
#				define MASTER_LIBRARY_HAVE_FTW_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_FTW_H
#				define MASTER_LIBRARY_HAVE_FTW_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ftw.h !# */

#ifdef MASTER_LIBRARY_HAVE_GLOB_H
#	define MASTER_LIBRARY_HAVE_GLOB_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_GLOB_H) == 40001
#		undef MASTER_LIBRARY_HAVE_GLOB_H
#		define MASTER_LIBRARY_HAVE_GLOB_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_GLOB_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_GLOB_H
#			define MASTER_LIBRARY_HAVE_GLOB_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_GLOB_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_GLOB_H
#				define MASTER_LIBRARY_HAVE_GLOB_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_GLOB_H
#				define MASTER_LIBRARY_HAVE_GLOB_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! glob.h !# */

#ifdef MASTER_LIBRARY_HAVE_GRP_H
#	define MASTER_LIBRARY_HAVE_GRP_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_GRP_H) == 40001
#		undef MASTER_LIBRARY_HAVE_GRP_H
#		define MASTER_LIBRARY_HAVE_GRP_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_GRP_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_GRP_H
#			define MASTER_LIBRARY_HAVE_GRP_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_GRP_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_GRP_H
#				define MASTER_LIBRARY_HAVE_GRP_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_GRP_H
#				define MASTER_LIBRARY_HAVE_GRP_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! grp.h !# */

#ifdef MASTER_LIBRARY_HAVE_ICONV_H
#	define MASTER_LIBRARY_HAVE_ICONV_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ICONV_H) == 40001
#		undef MASTER_LIBRARY_HAVE_ICONV_H
#		define MASTER_LIBRARY_HAVE_ICONV_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ICONV_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ICONV_H
#			define MASTER_LIBRARY_HAVE_ICONV_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ICONV_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ICONV_H
#				define MASTER_LIBRARY_HAVE_ICONV_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_ICONV_H
#				define MASTER_LIBRARY_HAVE_ICONV_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! iconv.h !# */

#ifdef MASTER_LIBRARY_HAVE_LANGINFO_H
#	define MASTER_LIBRARY_HAVE_LANGINFO_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LANGINFO_H) == 40001
#		undef MASTER_LIBRARY_HAVE_LANGINFO_H
#		define MASTER_LIBRARY_HAVE_LANGINFO_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LANGINFO_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LANGINFO_H
#			define MASTER_LIBRARY_HAVE_LANGINFO_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LANGINFO_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LANGINFO_H
#				define MASTER_LIBRARY_HAVE_LANGINFO_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_LANGINFO_H
#				define MASTER_LIBRARY_HAVE_LANGINFO_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! langinfo.h !# */

#ifdef MASTER_LIBRARY_HAVE_LIBGEN_H
#	define MASTER_LIBRARY_HAVE_LIBGEN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LIBGEN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_LIBGEN_H
#		define MASTER_LIBRARY_HAVE_LIBGEN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LIBGEN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LIBGEN_H
#			define MASTER_LIBRARY_HAVE_LIBGEN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LIBGEN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LIBGEN_H
#				define MASTER_LIBRARY_HAVE_LIBGEN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_LIBGEN_H
#				define MASTER_LIBRARY_HAVE_LIBGEN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! libgen.h !# */

#ifdef MASTER_LIBRARY_HAVE_LIBINTL_H
#	define MASTER_LIBRARY_HAVE_LIBINTL_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LIBINTL_H) == 40001
#		undef MASTER_LIBRARY_HAVE_LIBINTL_H
#		define MASTER_LIBRARY_HAVE_LIBINTL_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LIBINTL_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LIBINTL_H
#			define MASTER_LIBRARY_HAVE_LIBINTL_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LIBINTL_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LIBINTL_H
#				define MASTER_LIBRARY_HAVE_LIBINTL_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_LIBINTL_H
#				define MASTER_LIBRARY_HAVE_LIBINTL_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! libintl.h !# */

#ifdef MASTER_LIBRARY_HAVE_MONETARY_H
#	define MASTER_LIBRARY_HAVE_MONETARY_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MONETARY_H) == 40001
#		undef MASTER_LIBRARY_HAVE_MONETARY_H
#		define MASTER_LIBRARY_HAVE_MONETARY_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MONETARY_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MONETARY_H
#			define MASTER_LIBRARY_HAVE_MONETARY_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MONETARY_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MONETARY_H
#				define MASTER_LIBRARY_HAVE_MONETARY_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_MONETARY_H
#				define MASTER_LIBRARY_HAVE_MONETARY_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! monetary.h !# */

#ifdef MASTER_LIBRARY_HAVE_MQUEUE_H
#	define MASTER_LIBRARY_HAVE_MQUEUE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MQUEUE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_MQUEUE_H
#		define MASTER_LIBRARY_HAVE_MQUEUE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MQUEUE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MQUEUE_H
#			define MASTER_LIBRARY_HAVE_MQUEUE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MQUEUE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MQUEUE_H
#				define MASTER_LIBRARY_HAVE_MQUEUE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_MQUEUE_H
#				define MASTER_LIBRARY_HAVE_MQUEUE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! mqueue.h !# */

#ifdef MASTER_LIBRARY_HAVE_NDBM_H
#	define MASTER_LIBRARY_HAVE_NDBM_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NDBM_H) == 40001
#		undef MASTER_LIBRARY_HAVE_NDBM_H
#		define MASTER_LIBRARY_HAVE_NDBM_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NDBM_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NDBM_H
#			define MASTER_LIBRARY_HAVE_NDBM_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NDBM_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NDBM_H
#				define MASTER_LIBRARY_HAVE_NDBM_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_NDBM_H
#				define MASTER_LIBRARY_HAVE_NDBM_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ndbm.h !# */

#ifdef MASTER_LIBRARY_HAVE_NET_IF_H
#	define MASTER_LIBRARY_HAVE_NET_IF_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NET_IF_H) == 40001
#		undef MASTER_LIBRARY_HAVE_NET_IF_H
#		define MASTER_LIBRARY_HAVE_NET_IF_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NET_IF_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NET_IF_H
#			define MASTER_LIBRARY_HAVE_NET_IF_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NET_IF_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NET_IF_H
#				define MASTER_LIBRARY_HAVE_NET_IF_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_NET_IF_H
#				define MASTER_LIBRARY_HAVE_NET_IF_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! net/if.h !# */

#ifdef MASTER_LIBRARY_HAVE_NETDB_H
#	define MASTER_LIBRARY_HAVE_NETDB_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NETDB_H) == 40001
#		undef MASTER_LIBRARY_HAVE_NETDB_H
#		define MASTER_LIBRARY_HAVE_NETDB_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NETDB_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NETDB_H
#			define MASTER_LIBRARY_HAVE_NETDB_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NETDB_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NETDB_H
#				define MASTER_LIBRARY_HAVE_NETDB_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_NETDB_H
#				define MASTER_LIBRARY_HAVE_NETDB_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! netdb.h !# */

#ifdef MASTER_LIBRARY_HAVE_NETINET_IN_H
#	define MASTER_LIBRARY_HAVE_NETINET_IN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NETINET_IN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_NETINET_IN_H
#		define MASTER_LIBRARY_HAVE_NETINET_IN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NETINET_IN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NETINET_IN_H
#			define MASTER_LIBRARY_HAVE_NETINET_IN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NETINET_IN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NETINET_IN_H
#				define MASTER_LIBRARY_HAVE_NETINET_IN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_NETINET_IN_H
#				define MASTER_LIBRARY_HAVE_NETINET_IN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! netinet/in.h !# */

#ifdef MASTER_LIBRARY_HAVE_NETINET_TCP_H
#	define MASTER_LIBRARY_HAVE_NETINET_TCP_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NETINET_TCP_H) == 40001
#		undef MASTER_LIBRARY_HAVE_NETINET_TCP_H
#		define MASTER_LIBRARY_HAVE_NETINET_TCP_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NETINET_TCP_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NETINET_TCP_H
#			define MASTER_LIBRARY_HAVE_NETINET_TCP_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NETINET_TCP_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NETINET_TCP_H
#				define MASTER_LIBRARY_HAVE_NETINET_TCP_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_NETINET_TCP_H
#				define MASTER_LIBRARY_HAVE_NETINET_TCP_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! netinet/tcp.h !# */

#ifdef MASTER_LIBRARY_HAVE_NL_TYPES_H
#	define MASTER_LIBRARY_HAVE_NL_TYPES_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NL_TYPES_H) == 40001
#		undef MASTER_LIBRARY_HAVE_NL_TYPES_H
#		define MASTER_LIBRARY_HAVE_NL_TYPES_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NL_TYPES_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NL_TYPES_H
#			define MASTER_LIBRARY_HAVE_NL_TYPES_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NL_TYPES_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NL_TYPES_H
#				define MASTER_LIBRARY_HAVE_NL_TYPES_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_NL_TYPES_H
#				define MASTER_LIBRARY_HAVE_NL_TYPES_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! nl_types.h !# */

#ifdef MASTER_LIBRARY_HAVE_POLL_H
#	define MASTER_LIBRARY_HAVE_POLL_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_POLL_H) == 40001
#		undef MASTER_LIBRARY_HAVE_POLL_H
#		define MASTER_LIBRARY_HAVE_POLL_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_POLL_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_POLL_H
#			define MASTER_LIBRARY_HAVE_POLL_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_POLL_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_POLL_H
#				define MASTER_LIBRARY_HAVE_POLL_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_POLL_H
#				define MASTER_LIBRARY_HAVE_POLL_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! poll.h !# */

#ifdef MASTER_LIBRARY_HAVE_PTHREAD_H
#	define MASTER_LIBRARY_HAVE_PTHREAD_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_PTHREAD_H) == 40001
#		undef MASTER_LIBRARY_HAVE_PTHREAD_H
#		define MASTER_LIBRARY_HAVE_PTHREAD_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_PTHREAD_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_PTHREAD_H
#			define MASTER_LIBRARY_HAVE_PTHREAD_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_PTHREAD_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_PTHREAD_H
#				define MASTER_LIBRARY_HAVE_PTHREAD_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_PTHREAD_H
#				define MASTER_LIBRARY_HAVE_PTHREAD_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! pthread.h !# */

#ifdef MASTER_LIBRARY_HAVE_PWD_H
#	define MASTER_LIBRARY_HAVE_PWD_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_PWD_H) == 40001
#		undef MASTER_LIBRARY_HAVE_PWD_H
#		define MASTER_LIBRARY_HAVE_PWD_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_PWD_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_PWD_H
#			define MASTER_LIBRARY_HAVE_PWD_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_PWD_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_PWD_H
#				define MASTER_LIBRARY_HAVE_PWD_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_PWD_H
#				define MASTER_LIBRARY_HAVE_PWD_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! pwd.h !# */

#ifdef MASTER_LIBRARY_HAVE_REGEX_H
#	define MASTER_LIBRARY_HAVE_REGEX_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_REGEX_H) == 40001
#		undef MASTER_LIBRARY_HAVE_REGEX_H
#		define MASTER_LIBRARY_HAVE_REGEX_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_REGEX_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_REGEX_H
#			define MASTER_LIBRARY_HAVE_REGEX_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_REGEX_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_REGEX_H
#				define MASTER_LIBRARY_HAVE_REGEX_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_REGEX_H
#				define MASTER_LIBRARY_HAVE_REGEX_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! regex.h !# */

#ifdef MASTER_LIBRARY_HAVE_SCHED_H
#	define MASTER_LIBRARY_HAVE_SCHED_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SCHED_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SCHED_H
#		define MASTER_LIBRARY_HAVE_SCHED_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SCHED_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SCHED_H
#			define MASTER_LIBRARY_HAVE_SCHED_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SCHED_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SCHED_H
#				define MASTER_LIBRARY_HAVE_SCHED_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SCHED_H
#				define MASTER_LIBRARY_HAVE_SCHED_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sched.h !# */

#ifdef MASTER_LIBRARY_HAVE_SEARCH_H
#	define MASTER_LIBRARY_HAVE_SEARCH_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SEARCH_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SEARCH_H
#		define MASTER_LIBRARY_HAVE_SEARCH_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SEARCH_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SEARCH_H
#			define MASTER_LIBRARY_HAVE_SEARCH_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SEARCH_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SEARCH_H
#				define MASTER_LIBRARY_HAVE_SEARCH_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SEARCH_H
#				define MASTER_LIBRARY_HAVE_SEARCH_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! search.h !# */

#ifdef MASTER_LIBRARY_HAVE_SEMAPHORE_H
#	define MASTER_LIBRARY_HAVE_SEMAPHORE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SEMAPHORE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SEMAPHORE_H
#		define MASTER_LIBRARY_HAVE_SEMAPHORE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SEMAPHORE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SEMAPHORE_H
#			define MASTER_LIBRARY_HAVE_SEMAPHORE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SEMAPHORE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SEMAPHORE_H
#				define MASTER_LIBRARY_HAVE_SEMAPHORE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SEMAPHORE_H
#				define MASTER_LIBRARY_HAVE_SEMAPHORE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! semaphore.h !# */

#ifdef MASTER_LIBRARY_HAVE_SPAWN_H
#	define MASTER_LIBRARY_HAVE_SPAWN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SPAWN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SPAWN_H
#		define MASTER_LIBRARY_HAVE_SPAWN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SPAWN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SPAWN_H
#			define MASTER_LIBRARY_HAVE_SPAWN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SPAWN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SPAWN_H
#				define MASTER_LIBRARY_HAVE_SPAWN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SPAWN_H
#				define MASTER_LIBRARY_HAVE_SPAWN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! spawn.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDALIGN_H
#	define MASTER_LIBRARY_HAVE_STDALIGN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDALIGN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDALIGN_H
#		define MASTER_LIBRARY_HAVE_STDALIGN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDALIGN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDALIGN_H
#			define MASTER_LIBRARY_HAVE_STDALIGN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDALIGN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDALIGN_H
#				define MASTER_LIBRARY_HAVE_STDALIGN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDALIGN_H
#				define MASTER_LIBRARY_HAVE_STDALIGN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdalign.h !# */

#ifdef MASTER_LIBRARY_HAVE_STRINGS_H
#	define MASTER_LIBRARY_HAVE_STRINGS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STRINGS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STRINGS_H
#		define MASTER_LIBRARY_HAVE_STRINGS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STRINGS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STRINGS_H
#			define MASTER_LIBRARY_HAVE_STRINGS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STRINGS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STRINGS_H
#				define MASTER_LIBRARY_HAVE_STRINGS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STRINGS_H
#				define MASTER_LIBRARY_HAVE_STRINGS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! strings.h !# */

#ifdef MASTER_LIBRARY_HAVE_STROPTS_H
#	define MASTER_LIBRARY_HAVE_STROPTS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STROPTS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STROPTS_H
#		define MASTER_LIBRARY_HAVE_STROPTS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STROPTS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STROPTS_H
#			define MASTER_LIBRARY_HAVE_STROPTS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STROPTS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STROPTS_H
#				define MASTER_LIBRARY_HAVE_STROPTS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STROPTS_H
#				define MASTER_LIBRARY_HAVE_STROPTS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stropts.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_IPC_H
#	define MASTER_LIBRARY_HAVE_SYS_IPC_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_IPC_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_IPC_H
#		define MASTER_LIBRARY_HAVE_SYS_IPC_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_IPC_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_IPC_H
#			define MASTER_LIBRARY_HAVE_SYS_IPC_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_IPC_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_IPC_H
#				define MASTER_LIBRARY_HAVE_SYS_IPC_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_IPC_H
#				define MASTER_LIBRARY_HAVE_SYS_IPC_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/ipc.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_MMAN_H
#	define MASTER_LIBRARY_HAVE_SYS_MMAN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_MMAN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_MMAN_H
#		define MASTER_LIBRARY_HAVE_SYS_MMAN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_MMAN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_MMAN_H
#			define MASTER_LIBRARY_HAVE_SYS_MMAN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_MMAN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_MMAN_H
#				define MASTER_LIBRARY_HAVE_SYS_MMAN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_MMAN_H
#				define MASTER_LIBRARY_HAVE_SYS_MMAN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/mman.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_MSG_H
#	define MASTER_LIBRARY_HAVE_SYS_MSG_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_MSG_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_MSG_H
#		define MASTER_LIBRARY_HAVE_SYS_MSG_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_MSG_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_MSG_H
#			define MASTER_LIBRARY_HAVE_SYS_MSG_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_MSG_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_MSG_H
#				define MASTER_LIBRARY_HAVE_SYS_MSG_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_MSG_H
#				define MASTER_LIBRARY_HAVE_SYS_MSG_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/msg.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_RESOURCE_H
#	define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_RESOURCE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_RESOURCE_H
#		define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_RESOURCE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_RESOURCE_H
#			define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_RESOURCE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_RESOURCE_H
#				define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_RESOURCE_H
#				define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/resource.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_SELECT_H
#	define MASTER_LIBRARY_HAVE_SYS_SELECT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_SELECT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_SELECT_H
#		define MASTER_LIBRARY_HAVE_SYS_SELECT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_SELECT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_SELECT_H
#			define MASTER_LIBRARY_HAVE_SYS_SELECT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_SELECT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_SELECT_H
#				define MASTER_LIBRARY_HAVE_SYS_SELECT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_SELECT_H
#				define MASTER_LIBRARY_HAVE_SYS_SELECT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/select.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_SEM_H
#	define MASTER_LIBRARY_HAVE_SYS_SEM_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_SEM_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_SEM_H
#		define MASTER_LIBRARY_HAVE_SYS_SEM_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_SEM_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_SEM_H
#			define MASTER_LIBRARY_HAVE_SYS_SEM_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_SEM_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_SEM_H
#				define MASTER_LIBRARY_HAVE_SYS_SEM_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_SEM_H
#				define MASTER_LIBRARY_HAVE_SYS_SEM_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/sem.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_SHM_H
#	define MASTER_LIBRARY_HAVE_SYS_SHM_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_SHM_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_SHM_H
#		define MASTER_LIBRARY_HAVE_SYS_SHM_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_SHM_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_SHM_H
#			define MASTER_LIBRARY_HAVE_SYS_SHM_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_SHM_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_SHM_H
#				define MASTER_LIBRARY_HAVE_SYS_SHM_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_SHM_H
#				define MASTER_LIBRARY_HAVE_SYS_SHM_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/shm.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_SOCKET_H
#	define MASTER_LIBRARY_HAVE_SYS_SOCKET_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_SOCKET_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_SOCKET_H
#		define MASTER_LIBRARY_HAVE_SYS_SOCKET_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_SOCKET_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_SOCKET_H
#			define MASTER_LIBRARY_HAVE_SYS_SOCKET_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_SOCKET_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_SOCKET_H
#				define MASTER_LIBRARY_HAVE_SYS_SOCKET_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_SOCKET_H
#				define MASTER_LIBRARY_HAVE_SYS_SOCKET_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/socket.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_STAT_H
#	define MASTER_LIBRARY_HAVE_SYS_STAT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_STAT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_STAT_H
#		define MASTER_LIBRARY_HAVE_SYS_STAT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_STAT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_STAT_H
#			define MASTER_LIBRARY_HAVE_SYS_STAT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_STAT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_STAT_H
#				define MASTER_LIBRARY_HAVE_SYS_STAT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_STAT_H
#				define MASTER_LIBRARY_HAVE_SYS_STAT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/stat.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_STATVFS_H
#	define MASTER_LIBRARY_HAVE_SYS_STATVFS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_STATVFS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_STATVFS_H
#		define MASTER_LIBRARY_HAVE_SYS_STATVFS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_STATVFS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_STATVFS_H
#			define MASTER_LIBRARY_HAVE_SYS_STATVFS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_STATVFS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_STATVFS_H
#				define MASTER_LIBRARY_HAVE_SYS_STATVFS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_STATVFS_H
#				define MASTER_LIBRARY_HAVE_SYS_STATVFS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/statvfs.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_TIME_H
#	define MASTER_LIBRARY_HAVE_SYS_TIME_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_TIME_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_TIME_H
#		define MASTER_LIBRARY_HAVE_SYS_TIME_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_TIME_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_TIME_H
#			define MASTER_LIBRARY_HAVE_SYS_TIME_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_TIME_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_TIME_H
#				define MASTER_LIBRARY_HAVE_SYS_TIME_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_TIME_H
#				define MASTER_LIBRARY_HAVE_SYS_TIME_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/time.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_TIMES_H
#	define MASTER_LIBRARY_HAVE_SYS_TIMES_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_TIMES_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_TIMES_H
#		define MASTER_LIBRARY_HAVE_SYS_TIMES_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_TIMES_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_TIMES_H
#			define MASTER_LIBRARY_HAVE_SYS_TIMES_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_TIMES_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_TIMES_H
#				define MASTER_LIBRARY_HAVE_SYS_TIMES_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_TIMES_H
#				define MASTER_LIBRARY_HAVE_SYS_TIMES_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/times.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_TYPES_H
#	define MASTER_LIBRARY_HAVE_SYS_TYPES_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_TYPES_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_TYPES_H
#		define MASTER_LIBRARY_HAVE_SYS_TYPES_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_TYPES_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_TYPES_H
#			define MASTER_LIBRARY_HAVE_SYS_TYPES_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_TYPES_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_TYPES_H
#				define MASTER_LIBRARY_HAVE_SYS_TYPES_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_TYPES_H
#				define MASTER_LIBRARY_HAVE_SYS_TYPES_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/types.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_UIO_H
#	define MASTER_LIBRARY_HAVE_SYS_UIO_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_UIO_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_UIO_H
#		define MASTER_LIBRARY_HAVE_SYS_UIO_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_UIO_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_UIO_H
#			define MASTER_LIBRARY_HAVE_SYS_UIO_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_UIO_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_UIO_H
#				define MASTER_LIBRARY_HAVE_SYS_UIO_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_UIO_H
#				define MASTER_LIBRARY_HAVE_SYS_UIO_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/uio.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_UN_H
#	define MASTER_LIBRARY_HAVE_SYS_UN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_UN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_UN_H
#		define MASTER_LIBRARY_HAVE_SYS_UN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_UN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_UN_H
#			define MASTER_LIBRARY_HAVE_SYS_UN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_UN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_UN_H
#				define MASTER_LIBRARY_HAVE_SYS_UN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_UN_H
#				define MASTER_LIBRARY_HAVE_SYS_UN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/un.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_UTSNAME_H
#	define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_UTSNAME_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_UTSNAME_H
#		define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_UTSNAME_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_UTSNAME_H
#			define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_UTSNAME_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_UTSNAME_H
#				define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_UTSNAME_H
#				define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/utsname.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYS_WAIT_H
#	define MASTER_LIBRARY_HAVE_SYS_WAIT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYS_WAIT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYS_WAIT_H
#		define MASTER_LIBRARY_HAVE_SYS_WAIT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYS_WAIT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYS_WAIT_H
#			define MASTER_LIBRARY_HAVE_SYS_WAIT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYS_WAIT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYS_WAIT_H
#				define MASTER_LIBRARY_HAVE_SYS_WAIT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYS_WAIT_H
#				define MASTER_LIBRARY_HAVE_SYS_WAIT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sys/wait.h !# */

#ifdef MASTER_LIBRARY_HAVE_SYSLOG_H
#	define MASTER_LIBRARY_HAVE_SYSLOG_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYSLOG_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SYSLOG_H
#		define MASTER_LIBRARY_HAVE_SYSLOG_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYSLOG_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYSLOG_H
#			define MASTER_LIBRARY_HAVE_SYSLOG_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYSLOG_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYSLOG_H
#				define MASTER_LIBRARY_HAVE_SYSLOG_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYSLOG_H
#				define MASTER_LIBRARY_HAVE_SYSLOG_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! syslog.h !# */

#ifdef MASTER_LIBRARY_HAVE_TAR_H
#	define MASTER_LIBRARY_HAVE_TAR_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TAR_H) == 40001
#		undef MASTER_LIBRARY_HAVE_TAR_H
#		define MASTER_LIBRARY_HAVE_TAR_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TAR_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TAR_H
#			define MASTER_LIBRARY_HAVE_TAR_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TAR_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TAR_H
#				define MASTER_LIBRARY_HAVE_TAR_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_TAR_H
#				define MASTER_LIBRARY_HAVE_TAR_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! tar.h !# */

#ifdef MASTER_LIBRARY_HAVE_TERMIOS_H
#	define MASTER_LIBRARY_HAVE_TERMIOS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TERMIOS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_TERMIOS_H
#		define MASTER_LIBRARY_HAVE_TERMIOS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TERMIOS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TERMIOS_H
#			define MASTER_LIBRARY_HAVE_TERMIOS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TERMIOS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TERMIOS_H
#				define MASTER_LIBRARY_HAVE_TERMIOS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_TERMIOS_H
#				define MASTER_LIBRARY_HAVE_TERMIOS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! termios.h !# */

#ifdef MASTER_LIBRARY_HAVE_TRACE_H
#	define MASTER_LIBRARY_HAVE_TRACE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TRACE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_TRACE_H
#		define MASTER_LIBRARY_HAVE_TRACE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TRACE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TRACE_H
#			define MASTER_LIBRARY_HAVE_TRACE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TRACE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TRACE_H
#				define MASTER_LIBRARY_HAVE_TRACE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_TRACE_H
#				define MASTER_LIBRARY_HAVE_TRACE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! trace.h !# */

#ifdef MASTER_LIBRARY_HAVE_UCONTEXT_H
#	define MASTER_LIBRARY_HAVE_UCONTEXT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_UCONTEXT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_UCONTEXT_H
#		define MASTER_LIBRARY_HAVE_UCONTEXT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_UCONTEXT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_UCONTEXT_H
#			define MASTER_LIBRARY_HAVE_UCONTEXT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_UCONTEXT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_UCONTEXT_H
#				define MASTER_LIBRARY_HAVE_UCONTEXT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_UCONTEXT_H
#				define MASTER_LIBRARY_HAVE_UCONTEXT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ucontext.h !# */

#ifdef MASTER_LIBRARY_HAVE_ULIMIT_H
#	define MASTER_LIBRARY_HAVE_ULIMIT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ULIMIT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_ULIMIT_H
#		define MASTER_LIBRARY_HAVE_ULIMIT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ULIMIT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ULIMIT_H
#			define MASTER_LIBRARY_HAVE_ULIMIT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ULIMIT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ULIMIT_H
#				define MASTER_LIBRARY_HAVE_ULIMIT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_ULIMIT_H
#				define MASTER_LIBRARY_HAVE_ULIMIT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ulimit.h !# */

#ifdef MASTER_LIBRARY_HAVE_UNISTD_H
#	define MASTER_LIBRARY_HAVE_UNISTD_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_UNISTD_H) == 40001
#		undef MASTER_LIBRARY_HAVE_UNISTD_H
#		define MASTER_LIBRARY_HAVE_UNISTD_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_UNISTD_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_UNISTD_H
#			define MASTER_LIBRARY_HAVE_UNISTD_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_UNISTD_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_UNISTD_H
#				define MASTER_LIBRARY_HAVE_UNISTD_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_UNISTD_H
#				define MASTER_LIBRARY_HAVE_UNISTD_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! unistd.h !# */

#ifdef MASTER_LIBRARY_HAVE_UTIME_H
#	define MASTER_LIBRARY_HAVE_UTIME_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_UTIME_H) == 40001
#		undef MASTER_LIBRARY_HAVE_UTIME_H
#		define MASTER_LIBRARY_HAVE_UTIME_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_UTIME_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_UTIME_H
#			define MASTER_LIBRARY_HAVE_UTIME_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_UTIME_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_UTIME_H
#				define MASTER_LIBRARY_HAVE_UTIME_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_UTIME_H
#				define MASTER_LIBRARY_HAVE_UTIME_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! utime.h !# */

#ifdef MASTER_LIBRARY_HAVE_UTMPX_H
#	define MASTER_LIBRARY_HAVE_UTMPX_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_UTMPX_H) == 40001
#		undef MASTER_LIBRARY_HAVE_UTMPX_H
#		define MASTER_LIBRARY_HAVE_UTMPX_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_UTMPX_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_UTMPX_H
#			define MASTER_LIBRARY_HAVE_UTMPX_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_UTMPX_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_UTMPX_H
#				define MASTER_LIBRARY_HAVE_UTMPX_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_UTMPX_H
#				define MASTER_LIBRARY_HAVE_UTMPX_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! utmpx.h !# */

#ifdef MASTER_LIBRARY_HAVE_WORDEXP_H
#	define MASTER_LIBRARY_HAVE_WORDEXP_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WORDEXP_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WORDEXP_H
#		define MASTER_LIBRARY_HAVE_WORDEXP_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WORDEXP_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WORDEXP_H
#			define MASTER_LIBRARY_HAVE_WORDEXP_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WORDEXP_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WORDEXP_H
#				define MASTER_LIBRARY_HAVE_WORDEXP_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WORDEXP_H
#				define MASTER_LIBRARY_HAVE_WORDEXP_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! wordexp.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINDOWS_H
#	define MASTER_LIBRARY_HAVE_WINDOWS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINDOWS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINDOWS_H
#		define MASTER_LIBRARY_HAVE_WINDOWS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINDOWS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINDOWS_H
#			define MASTER_LIBRARY_HAVE_WINDOWS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINDOWS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINDOWS_H
#				define MASTER_LIBRARY_HAVE_WINDOWS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINDOWS_H
#				define MASTER_LIBRARY_HAVE_WINDOWS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! windows.h !# */

#ifdef MASTER_LIBRARY_HAVE_CONIO_H
#	define MASTER_LIBRARY_HAVE_CONIO_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CONIO_H) == 40001
#		undef MASTER_LIBRARY_HAVE_CONIO_H
#		define MASTER_LIBRARY_HAVE_CONIO_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CONIO_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CONIO_H
#			define MASTER_LIBRARY_HAVE_CONIO_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CONIO_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CONIO_H
#				define MASTER_LIBRARY_HAVE_CONIO_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_CONIO_H
#				define MASTER_LIBRARY_HAVE_CONIO_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! conio.h !# */

#ifdef MASTER_LIBRARY_HAVE_BASETSD_H
#	define MASTER_LIBRARY_HAVE_BASETSD_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_BASETSD_H) == 40001
#		undef MASTER_LIBRARY_HAVE_BASETSD_H
#		define MASTER_LIBRARY_HAVE_BASETSD_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_BASETSD_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_BASETSD_H
#			define MASTER_LIBRARY_HAVE_BASETSD_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_BASETSD_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_BASETSD_H
#				define MASTER_LIBRARY_HAVE_BASETSD_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_BASETSD_H
#				define MASTER_LIBRARY_HAVE_BASETSD_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! basetsd.h !# */

#ifdef MASTER_LIBRARY_HAVE_GUIDDEF_H
#	define MASTER_LIBRARY_HAVE_GUIDDEF_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_GUIDDEF_H) == 40001
#		undef MASTER_LIBRARY_HAVE_GUIDDEF_H
#		define MASTER_LIBRARY_HAVE_GUIDDEF_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_GUIDDEF_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_GUIDDEF_H
#			define MASTER_LIBRARY_HAVE_GUIDDEF_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_GUIDDEF_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_GUIDDEF_H
#				define MASTER_LIBRARY_HAVE_GUIDDEF_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_GUIDDEF_H
#				define MASTER_LIBRARY_HAVE_GUIDDEF_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! guiddef.h !# */

#ifdef MASTER_LIBRARY_HAVE_IMM_H
#	define MASTER_LIBRARY_HAVE_IMM_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_IMM_H) == 40001
#		undef MASTER_LIBRARY_HAVE_IMM_H
#		define MASTER_LIBRARY_HAVE_IMM_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_IMM_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_IMM_H
#			define MASTER_LIBRARY_HAVE_IMM_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_IMM_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_IMM_H
#				define MASTER_LIBRARY_HAVE_IMM_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_IMM_H
#				define MASTER_LIBRARY_HAVE_IMM_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! imm.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINBASE_H
#	define MASTER_LIBRARY_HAVE_WINBASE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINBASE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINBASE_H
#		define MASTER_LIBRARY_HAVE_WINBASE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINBASE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINBASE_H
#			define MASTER_LIBRARY_HAVE_WINBASE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINBASE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINBASE_H
#				define MASTER_LIBRARY_HAVE_WINBASE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINBASE_H
#				define MASTER_LIBRARY_HAVE_WINBASE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winbase.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINCON_H
#	define MASTER_LIBRARY_HAVE_WINCON_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINCON_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINCON_H
#		define MASTER_LIBRARY_HAVE_WINCON_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINCON_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINCON_H
#			define MASTER_LIBRARY_HAVE_WINCON_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINCON_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINCON_H
#				define MASTER_LIBRARY_HAVE_WINCON_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINCON_H
#				define MASTER_LIBRARY_HAVE_WINCON_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! wincon.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINDEF_H
#	define MASTER_LIBRARY_HAVE_WINDEF_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINDEF_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINDEF_H
#		define MASTER_LIBRARY_HAVE_WINDEF_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINDEF_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINDEF_H
#			define MASTER_LIBRARY_HAVE_WINDEF_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINDEF_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINDEF_H
#				define MASTER_LIBRARY_HAVE_WINDEF_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINDEF_H
#				define MASTER_LIBRARY_HAVE_WINDEF_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! windef.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINERROR_H
#	define MASTER_LIBRARY_HAVE_WINERROR_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINERROR_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINERROR_H
#		define MASTER_LIBRARY_HAVE_WINERROR_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINERROR_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINERROR_H
#			define MASTER_LIBRARY_HAVE_WINERROR_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINERROR_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINERROR_H
#				define MASTER_LIBRARY_HAVE_WINERROR_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINERROR_H
#				define MASTER_LIBRARY_HAVE_WINERROR_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winerror.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINGDI_H
#	define MASTER_LIBRARY_HAVE_WINGDI_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINGDI_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINGDI_H
#		define MASTER_LIBRARY_HAVE_WINGDI_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINGDI_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINGDI_H
#			define MASTER_LIBRARY_HAVE_WINGDI_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINGDI_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINGDI_H
#				define MASTER_LIBRARY_HAVE_WINGDI_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINGDI_H
#				define MASTER_LIBRARY_HAVE_WINGDI_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! wingdi.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINNETWK_H
#	define MASTER_LIBRARY_HAVE_WINNETWK_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINNETWK_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINNETWK_H
#		define MASTER_LIBRARY_HAVE_WINNETWK_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINNETWK_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINNETWK_H
#			define MASTER_LIBRARY_HAVE_WINNETWK_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINNETWK_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINNETWK_H
#				define MASTER_LIBRARY_HAVE_WINNETWK_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINNETWK_H
#				define MASTER_LIBRARY_HAVE_WINNETWK_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winnetwk.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINNLS_H
#	define MASTER_LIBRARY_HAVE_WINNLS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINNLS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINNLS_H
#		define MASTER_LIBRARY_HAVE_WINNLS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINNLS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINNLS_H
#			define MASTER_LIBRARY_HAVE_WINNLS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINNLS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINNLS_H
#				define MASTER_LIBRARY_HAVE_WINNLS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINNLS_H
#				define MASTER_LIBRARY_HAVE_WINNLS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winnls.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINNT_H
#	define MASTER_LIBRARY_HAVE_WINNT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINNT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINNT_H
#		define MASTER_LIBRARY_HAVE_WINNT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINNT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINNT_H
#			define MASTER_LIBRARY_HAVE_WINNT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINNT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINNT_H
#				define MASTER_LIBRARY_HAVE_WINNT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINNT_H
#				define MASTER_LIBRARY_HAVE_WINNT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winnt.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINREG_H
#	define MASTER_LIBRARY_HAVE_WINREG_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINREG_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINREG_H
#		define MASTER_LIBRARY_HAVE_WINREG_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINREG_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINREG_H
#			define MASTER_LIBRARY_HAVE_WINREG_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINREG_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINREG_H
#				define MASTER_LIBRARY_HAVE_WINREG_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINREG_H
#				define MASTER_LIBRARY_HAVE_WINREG_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winreg.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINSVC_H
#	define MASTER_LIBRARY_HAVE_WINSVC_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINSVC_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINSVC_H
#		define MASTER_LIBRARY_HAVE_WINSVC_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINSVC_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINSVC_H
#			define MASTER_LIBRARY_HAVE_WINSVC_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINSVC_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINSVC_H
#				define MASTER_LIBRARY_HAVE_WINSVC_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINSVC_H
#				define MASTER_LIBRARY_HAVE_WINSVC_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winsvc.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINUSER_H
#	define MASTER_LIBRARY_HAVE_WINUSER_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINUSER_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINUSER_H
#		define MASTER_LIBRARY_HAVE_WINUSER_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINUSER_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINUSER_H
#			define MASTER_LIBRARY_HAVE_WINUSER_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINUSER_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINUSER_H
#				define MASTER_LIBRARY_HAVE_WINUSER_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINUSER_H
#				define MASTER_LIBRARY_HAVE_WINUSER_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winuser.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINVER_H
#	define MASTER_LIBRARY_HAVE_WINVER_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINVER_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINVER_H
#		define MASTER_LIBRARY_HAVE_WINVER_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINVER_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINVER_H
#			define MASTER_LIBRARY_HAVE_WINVER_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINVER_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINVER_H
#				define MASTER_LIBRARY_HAVE_WINVER_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINVER_H
#				define MASTER_LIBRARY_HAVE_WINVER_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winver.h !# */

#ifdef MASTER_LIBRARY_HAVE_CDERR_H
#	define MASTER_LIBRARY_HAVE_CDERR_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CDERR_H) == 40001
#		undef MASTER_LIBRARY_HAVE_CDERR_H
#		define MASTER_LIBRARY_HAVE_CDERR_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CDERR_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CDERR_H
#			define MASTER_LIBRARY_HAVE_CDERR_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CDERR_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CDERR_H
#				define MASTER_LIBRARY_HAVE_CDERR_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_CDERR_H
#				define MASTER_LIBRARY_HAVE_CDERR_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cderr.h !# */

#ifdef MASTER_LIBRARY_HAVE_COMMLDG_H
#	define MASTER_LIBRARY_HAVE_COMMLDG_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_COMMLDG_H) == 40001
#		undef MASTER_LIBRARY_HAVE_COMMLDG_H
#		define MASTER_LIBRARY_HAVE_COMMLDG_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_COMMLDG_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_COMMLDG_H
#			define MASTER_LIBRARY_HAVE_COMMLDG_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_COMMLDG_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_COMMLDG_H
#				define MASTER_LIBRARY_HAVE_COMMLDG_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_COMMLDG_H
#				define MASTER_LIBRARY_HAVE_COMMLDG_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! commldg.h !# */

#ifdef MASTER_LIBRARY_HAVE_DDE_H
#	define MASTER_LIBRARY_HAVE_DDE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DDE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_DDE_H
#		define MASTER_LIBRARY_HAVE_DDE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DDE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DDE_H
#			define MASTER_LIBRARY_HAVE_DDE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DDE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DDE_H
#				define MASTER_LIBRARY_HAVE_DDE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_DDE_H
#				define MASTER_LIBRARY_HAVE_DDE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! dde.h !# */

#ifdef MASTER_LIBRARY_HAVE_DDEML_H
#	define MASTER_LIBRARY_HAVE_DDEML_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DDEML_H) == 40001
#		undef MASTER_LIBRARY_HAVE_DDEML_H
#		define MASTER_LIBRARY_HAVE_DDEML_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DDEML_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DDEML_H
#			define MASTER_LIBRARY_HAVE_DDEML_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DDEML_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DDEML_H
#				define MASTER_LIBRARY_HAVE_DDEML_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_DDEML_H
#				define MASTER_LIBRARY_HAVE_DDEML_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ddeml.h !# */

#ifdef MASTER_LIBRARY_HAVE_DLGS_H
#	define MASTER_LIBRARY_HAVE_DLGS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DLGS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_DLGS_H
#		define MASTER_LIBRARY_HAVE_DLGS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DLGS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DLGS_H
#			define MASTER_LIBRARY_HAVE_DLGS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DLGS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DLGS_H
#				define MASTER_LIBRARY_HAVE_DLGS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_DLGS_H
#				define MASTER_LIBRARY_HAVE_DLGS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! dlgs.h !# */

#ifdef MASTER_LIBRARY_HAVE_LZEXPAND_H
#	define MASTER_LIBRARY_HAVE_LZEXPAND_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LZEXPAND_H) == 40001
#		undef MASTER_LIBRARY_HAVE_LZEXPAND_H
#		define MASTER_LIBRARY_HAVE_LZEXPAND_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LZEXPAND_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LZEXPAND_H
#			define MASTER_LIBRARY_HAVE_LZEXPAND_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LZEXPAND_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LZEXPAND_H
#				define MASTER_LIBRARY_HAVE_LZEXPAND_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_LZEXPAND_H
#				define MASTER_LIBRARY_HAVE_LZEXPAND_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! lzexpand.h !# */

#ifdef MASTER_LIBRARY_HAVE_MMSYSTEM_H
#	define MASTER_LIBRARY_HAVE_MMSYSTEM_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MMSYSTEM_H) == 40001
#		undef MASTER_LIBRARY_HAVE_MMSYSTEM_H
#		define MASTER_LIBRARY_HAVE_MMSYSTEM_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MMSYSTEM_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MMSYSTEM_H
#			define MASTER_LIBRARY_HAVE_MMSYSTEM_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MMSYSTEM_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MMSYSTEM_H
#				define MASTER_LIBRARY_HAVE_MMSYSTEM_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_MMSYSTEM_H
#				define MASTER_LIBRARY_HAVE_MMSYSTEM_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! mmsystem.h !# */

#ifdef MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H
#	define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H) == 40001
#		undef MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H
#		define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H
#			define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H
#				define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H
#				define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! nb3master/answer/n.h !# */

#ifdef MASTER_LIBRARY_HAVE_RPC_H
#	define MASTER_LIBRARY_HAVE_RPC_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_RPC_H) == 40001
#		undef MASTER_LIBRARY_HAVE_RPC_H
#		define MASTER_LIBRARY_HAVE_RPC_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_RPC_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_RPC_H
#			define MASTER_LIBRARY_HAVE_RPC_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_RPC_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_RPC_H
#				define MASTER_LIBRARY_HAVE_RPC_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_RPC_H
#				define MASTER_LIBRARY_HAVE_RPC_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! rpc.h !# */

#ifdef MASTER_LIBRARY_HAVE_SHELLAPI_H
#	define MASTER_LIBRARY_HAVE_SHELLAPI_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SHELLAPI_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SHELLAPI_H
#		define MASTER_LIBRARY_HAVE_SHELLAPI_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SHELLAPI_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SHELLAPI_H
#			define MASTER_LIBRARY_HAVE_SHELLAPI_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SHELLAPI_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SHELLAPI_H
#				define MASTER_LIBRARY_HAVE_SHELLAPI_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SHELLAPI_H
#				define MASTER_LIBRARY_HAVE_SHELLAPI_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! shellapi.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINCRYPT_H
#	define MASTER_LIBRARY_HAVE_WINCRYPT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINCRYPT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINCRYPT_H
#		define MASTER_LIBRARY_HAVE_WINCRYPT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINCRYPT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINCRYPT_H
#			define MASTER_LIBRARY_HAVE_WINCRYPT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINCRYPT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINCRYPT_H
#				define MASTER_LIBRARY_HAVE_WINCRYPT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINCRYPT_H
#				define MASTER_LIBRARY_HAVE_WINCRYPT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! wincrypt.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINPERF_H
#	define MASTER_LIBRARY_HAVE_WINPERF_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINPERF_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINPERF_H
#		define MASTER_LIBRARY_HAVE_WINPERF_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINPERF_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINPERF_H
#			define MASTER_LIBRARY_HAVE_WINPERF_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINPERF_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINPERF_H
#				define MASTER_LIBRARY_HAVE_WINPERF_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINPERF_H
#				define MASTER_LIBRARY_HAVE_WINPERF_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winperf.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINRESRC_H
#	define MASTER_LIBRARY_HAVE_WINRESRC_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINRESRC_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINRESRC_H
#		define MASTER_LIBRARY_HAVE_WINRESRC_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINRESRC_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINRESRC_H
#			define MASTER_LIBRARY_HAVE_WINRESRC_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINRESRC_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINRESRC_H
#				define MASTER_LIBRARY_HAVE_WINRESRC_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINRESRC_H
#				define MASTER_LIBRARY_HAVE_WINRESRC_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winresrc.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINSOCK_H
#	define MASTER_LIBRARY_HAVE_WINSOCK_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINSOCK_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINSOCK_H
#		define MASTER_LIBRARY_HAVE_WINSOCK_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINSOCK_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINSOCK_H
#			define MASTER_LIBRARY_HAVE_WINSOCK_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINSOCK_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINSOCK_H
#				define MASTER_LIBRARY_HAVE_WINSOCK_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINSOCK_H
#				define MASTER_LIBRARY_HAVE_WINSOCK_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winsock.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINSPOOL_H
#	define MASTER_LIBRARY_HAVE_WINSPOOL_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINSPOOL_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINSPOOL_H
#		define MASTER_LIBRARY_HAVE_WINSPOOL_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINSPOOL_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINSPOOL_H
#			define MASTER_LIBRARY_HAVE_WINSPOOL_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINSPOOL_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINSPOOL_H
#				define MASTER_LIBRARY_HAVE_WINSPOOL_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINSPOOL_H
#				define MASTER_LIBRARY_HAVE_WINSPOOL_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winspool.h !# */

#ifdef MASTER_LIBRARY_HAVE_WINBGIM_H
#	define MASTER_LIBRARY_HAVE_WINBGIM_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WINBGIM_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WINBGIM_H
#		define MASTER_LIBRARY_HAVE_WINBGIM_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WINBGIM_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WINBGIM_H
#			define MASTER_LIBRARY_HAVE_WINBGIM_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WINBGIM_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WINBGIM_H
#				define MASTER_LIBRARY_HAVE_WINBGIM_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WINBGIM_H
#				define MASTER_LIBRARY_HAVE_WINBGIM_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! winbgim.h !# */

#ifdef MASTER_LIBRARY_HAVE_OLE2_H
#	define MASTER_LIBRARY_HAVE_OLE2_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_OLE2_H) == 40001
#		undef MASTER_LIBRARY_HAVE_OLE2_H
#		define MASTER_LIBRARY_HAVE_OLE2_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_OLE2_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_OLE2_H
#			define MASTER_LIBRARY_HAVE_OLE2_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_OLE2_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_OLE2_H
#				define MASTER_LIBRARY_HAVE_OLE2_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_OLE2_H
#				define MASTER_LIBRARY_HAVE_OLE2_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ole2.h !# */

#ifdef MASTER_LIBRARY_HAVE_OBJBASE_H
#	define MASTER_LIBRARY_HAVE_OBJBASE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_OBJBASE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_OBJBASE_H
#		define MASTER_LIBRARY_HAVE_OBJBASE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_OBJBASE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_OBJBASE_H
#			define MASTER_LIBRARY_HAVE_OBJBASE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_OBJBASE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_OBJBASE_H
#				define MASTER_LIBRARY_HAVE_OBJBASE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_OBJBASE_H
#				define MASTER_LIBRARY_HAVE_OBJBASE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! objbase.h !# */

#ifdef MASTER_LIBRARY_HAVE_OLEAUTO_H
#	define MASTER_LIBRARY_HAVE_OLEAUTO_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_OLEAUTO_H) == 40001
#		undef MASTER_LIBRARY_HAVE_OLEAUTO_H
#		define MASTER_LIBRARY_HAVE_OLEAUTO_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_OLEAUTO_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_OLEAUTO_H
#			define MASTER_LIBRARY_HAVE_OLEAUTO_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_OLEAUTO_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_OLEAUTO_H
#				define MASTER_LIBRARY_HAVE_OLEAUTO_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_OLEAUTO_H
#				define MASTER_LIBRARY_HAVE_OLEAUTO_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! oleauto.h !# */

#ifdef MASTER_LIBRARY_HAVE_OLETLID_H
#	define MASTER_LIBRARY_HAVE_OLETLID_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_OLETLID_H) == 40001
#		undef MASTER_LIBRARY_HAVE_OLETLID_H
#		define MASTER_LIBRARY_HAVE_OLETLID_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_OLETLID_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_OLETLID_H
#			define MASTER_LIBRARY_HAVE_OLETLID_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_OLETLID_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_OLETLID_H
#				define MASTER_LIBRARY_HAVE_OLETLID_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_OLETLID_H
#				define MASTER_LIBRARY_HAVE_OLETLID_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! oletlid.h !# */

#ifdef MASTER_LIBRARY_HAVE_ASSERT_H
#	define MASTER_LIBRARY_HAVE_ASSERT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ASSERT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_ASSERT_H
#		define MASTER_LIBRARY_HAVE_ASSERT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ASSERT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ASSERT_H
#			define MASTER_LIBRARY_HAVE_ASSERT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ASSERT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ASSERT_H
#				define MASTER_LIBRARY_HAVE_ASSERT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_ASSERT_H
#				define MASTER_LIBRARY_HAVE_ASSERT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! assert.h !# */

#ifdef MASTER_LIBRARY_HAVE_COMPLEX_H
#	define MASTER_LIBRARY_HAVE_COMPLEX_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_COMPLEX_H) == 40001
#		undef MASTER_LIBRARY_HAVE_COMPLEX_H
#		define MASTER_LIBRARY_HAVE_COMPLEX_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_COMPLEX_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_COMPLEX_H
#			define MASTER_LIBRARY_HAVE_COMPLEX_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_COMPLEX_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_COMPLEX_H
#				define MASTER_LIBRARY_HAVE_COMPLEX_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_COMPLEX_H
#				define MASTER_LIBRARY_HAVE_COMPLEX_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! complex.h !# */

#ifdef MASTER_LIBRARY_HAVE_CTYPE_H
#	define MASTER_LIBRARY_HAVE_CTYPE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CTYPE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_CTYPE_H
#		define MASTER_LIBRARY_HAVE_CTYPE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CTYPE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CTYPE_H
#			define MASTER_LIBRARY_HAVE_CTYPE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CTYPE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CTYPE_H
#				define MASTER_LIBRARY_HAVE_CTYPE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_CTYPE_H
#				define MASTER_LIBRARY_HAVE_CTYPE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ctype.h !# */

#ifdef MASTER_LIBRARY_HAVE_ERRNO_H
#	define MASTER_LIBRARY_HAVE_ERRNO_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ERRNO_H) == 40001
#		undef MASTER_LIBRARY_HAVE_ERRNO_H
#		define MASTER_LIBRARY_HAVE_ERRNO_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ERRNO_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ERRNO_H
#			define MASTER_LIBRARY_HAVE_ERRNO_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ERRNO_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ERRNO_H
#				define MASTER_LIBRARY_HAVE_ERRNO_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_ERRNO_H
#				define MASTER_LIBRARY_HAVE_ERRNO_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! errno.h !# */

#ifdef MASTER_LIBRARY_HAVE_FENV_H
#	define MASTER_LIBRARY_HAVE_FENV_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FENV_H) == 40001
#		undef MASTER_LIBRARY_HAVE_FENV_H
#		define MASTER_LIBRARY_HAVE_FENV_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FENV_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FENV_H
#			define MASTER_LIBRARY_HAVE_FENV_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FENV_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FENV_H
#				define MASTER_LIBRARY_HAVE_FENV_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_FENV_H
#				define MASTER_LIBRARY_HAVE_FENV_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! fenv.h !# */

#ifdef MASTER_LIBRARY_HAVE_FLOAT_H
#	define MASTER_LIBRARY_HAVE_FLOAT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FLOAT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_FLOAT_H
#		define MASTER_LIBRARY_HAVE_FLOAT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FLOAT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FLOAT_H
#			define MASTER_LIBRARY_HAVE_FLOAT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FLOAT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FLOAT_H
#				define MASTER_LIBRARY_HAVE_FLOAT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_FLOAT_H
#				define MASTER_LIBRARY_HAVE_FLOAT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! float.h !# */

#ifdef MASTER_LIBRARY_HAVE_INTTYPES_H
#	define MASTER_LIBRARY_HAVE_INTTYPES_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_INTTYPES_H) == 40001
#		undef MASTER_LIBRARY_HAVE_INTTYPES_H
#		define MASTER_LIBRARY_HAVE_INTTYPES_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_INTTYPES_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_INTTYPES_H
#			define MASTER_LIBRARY_HAVE_INTTYPES_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_INTTYPES_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_INTTYPES_H
#				define MASTER_LIBRARY_HAVE_INTTYPES_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_INTTYPES_H
#				define MASTER_LIBRARY_HAVE_INTTYPES_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! inttypes.h !# */

#ifdef MASTER_LIBRARY_HAVE_ISO646_H
#	define MASTER_LIBRARY_HAVE_ISO646_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ISO646_H) == 40001
#		undef MASTER_LIBRARY_HAVE_ISO646_H
#		define MASTER_LIBRARY_HAVE_ISO646_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ISO646_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ISO646_H
#			define MASTER_LIBRARY_HAVE_ISO646_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ISO646_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ISO646_H
#				define MASTER_LIBRARY_HAVE_ISO646_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_ISO646_H
#				define MASTER_LIBRARY_HAVE_ISO646_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! iso646.h !# */

#ifdef MASTER_LIBRARY_HAVE_LIMITS_H
#	define MASTER_LIBRARY_HAVE_LIMITS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LIMITS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_LIMITS_H
#		define MASTER_LIBRARY_HAVE_LIMITS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LIMITS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LIMITS_H
#			define MASTER_LIBRARY_HAVE_LIMITS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LIMITS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LIMITS_H
#				define MASTER_LIBRARY_HAVE_LIMITS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_LIMITS_H
#				define MASTER_LIBRARY_HAVE_LIMITS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! limits.h !# */

#ifdef MASTER_LIBRARY_HAVE_LOCALE_H
#	define MASTER_LIBRARY_HAVE_LOCALE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LOCALE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_LOCALE_H
#		define MASTER_LIBRARY_HAVE_LOCALE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LOCALE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LOCALE_H
#			define MASTER_LIBRARY_HAVE_LOCALE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LOCALE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LOCALE_H
#				define MASTER_LIBRARY_HAVE_LOCALE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_LOCALE_H
#				define MASTER_LIBRARY_HAVE_LOCALE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! locale.h !# */

#ifdef MASTER_LIBRARY_HAVE_MATH_H
#	define MASTER_LIBRARY_HAVE_MATH_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MATH_H) == 40001
#		undef MASTER_LIBRARY_HAVE_MATH_H
#		define MASTER_LIBRARY_HAVE_MATH_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MATH_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MATH_H
#			define MASTER_LIBRARY_HAVE_MATH_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MATH_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MATH_H
#				define MASTER_LIBRARY_HAVE_MATH_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_MATH_H
#				define MASTER_LIBRARY_HAVE_MATH_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! math.h !# */

#ifdef MASTER_LIBRARY_HAVE_SETJMP_H
#	define MASTER_LIBRARY_HAVE_SETJMP_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SETJMP_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SETJMP_H
#		define MASTER_LIBRARY_HAVE_SETJMP_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SETJMP_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SETJMP_H
#			define MASTER_LIBRARY_HAVE_SETJMP_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SETJMP_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SETJMP_H
#				define MASTER_LIBRARY_HAVE_SETJMP_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SETJMP_H
#				define MASTER_LIBRARY_HAVE_SETJMP_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! setjmp.h !# */

#ifdef MASTER_LIBRARY_HAVE_SIGNAL_H
#	define MASTER_LIBRARY_HAVE_SIGNAL_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SIGNAL_H) == 40001
#		undef MASTER_LIBRARY_HAVE_SIGNAL_H
#		define MASTER_LIBRARY_HAVE_SIGNAL_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SIGNAL_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SIGNAL_H
#			define MASTER_LIBRARY_HAVE_SIGNAL_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SIGNAL_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SIGNAL_H
#				define MASTER_LIBRARY_HAVE_SIGNAL_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_SIGNAL_H
#				define MASTER_LIBRARY_HAVE_SIGNAL_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! signal.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDARG_H
#	define MASTER_LIBRARY_HAVE_STDARG_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDARG_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDARG_H
#		define MASTER_LIBRARY_HAVE_STDARG_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDARG_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDARG_H
#			define MASTER_LIBRARY_HAVE_STDARG_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDARG_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDARG_H
#				define MASTER_LIBRARY_HAVE_STDARG_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDARG_H
#				define MASTER_LIBRARY_HAVE_STDARG_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdarg.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDATOMIC_H
#	define MASTER_LIBRARY_HAVE_STDATOMIC_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDATOMIC_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDATOMIC_H
#		define MASTER_LIBRARY_HAVE_STDATOMIC_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDATOMIC_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDATOMIC_H
#			define MASTER_LIBRARY_HAVE_STDATOMIC_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDATOMIC_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDATOMIC_H
#				define MASTER_LIBRARY_HAVE_STDATOMIC_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDATOMIC_H
#				define MASTER_LIBRARY_HAVE_STDATOMIC_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdatomic.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDBIT_H
#	define MASTER_LIBRARY_HAVE_STDBIT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDBIT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDBIT_H
#		define MASTER_LIBRARY_HAVE_STDBIT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDBIT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDBIT_H
#			define MASTER_LIBRARY_HAVE_STDBIT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDBIT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDBIT_H
#				define MASTER_LIBRARY_HAVE_STDBIT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDBIT_H
#				define MASTER_LIBRARY_HAVE_STDBIT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdbit.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDBOOL_H
#	define MASTER_LIBRARY_HAVE_STDBOOL_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDBOOL_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDBOOL_H
#		define MASTER_LIBRARY_HAVE_STDBOOL_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDBOOL_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDBOOL_H
#			define MASTER_LIBRARY_HAVE_STDBOOL_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDBOOL_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDBOOL_H
#				define MASTER_LIBRARY_HAVE_STDBOOL_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDBOOL_H
#				define MASTER_LIBRARY_HAVE_STDBOOL_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdbool.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDCKDINT_H
#	define MASTER_LIBRARY_HAVE_STDCKDINT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDCKDINT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDCKDINT_H
#		define MASTER_LIBRARY_HAVE_STDCKDINT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDCKDINT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDCKDINT_H
#			define MASTER_LIBRARY_HAVE_STDCKDINT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDCKDINT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDCKDINT_H
#				define MASTER_LIBRARY_HAVE_STDCKDINT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDCKDINT_H
#				define MASTER_LIBRARY_HAVE_STDCKDINT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdckdint.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDDEF_H
#	define MASTER_LIBRARY_HAVE_STDDEF_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDDEF_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDDEF_H
#		define MASTER_LIBRARY_HAVE_STDDEF_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDDEF_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDDEF_H
#			define MASTER_LIBRARY_HAVE_STDDEF_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDDEF_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDDEF_H
#				define MASTER_LIBRARY_HAVE_STDDEF_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDDEF_H
#				define MASTER_LIBRARY_HAVE_STDDEF_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stddef.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDINT_H
#	define MASTER_LIBRARY_HAVE_STDINT_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDINT_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDINT_H
#		define MASTER_LIBRARY_HAVE_STDINT_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDINT_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDINT_H
#			define MASTER_LIBRARY_HAVE_STDINT_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDINT_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDINT_H
#				define MASTER_LIBRARY_HAVE_STDINT_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDINT_H
#				define MASTER_LIBRARY_HAVE_STDINT_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdint.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDIO_H
#	define MASTER_LIBRARY_HAVE_STDIO_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDIO_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDIO_H
#		define MASTER_LIBRARY_HAVE_STDIO_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDIO_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDIO_H
#			define MASTER_LIBRARY_HAVE_STDIO_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDIO_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDIO_H
#				define MASTER_LIBRARY_HAVE_STDIO_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDIO_H
#				define MASTER_LIBRARY_HAVE_STDIO_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdio.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDLIB_H
#	define MASTER_LIBRARY_HAVE_STDLIB_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDLIB_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDLIB_H
#		define MASTER_LIBRARY_HAVE_STDLIB_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDLIB_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDLIB_H
#			define MASTER_LIBRARY_HAVE_STDLIB_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDLIB_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDLIB_H
#				define MASTER_LIBRARY_HAVE_STDLIB_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDLIB_H
#				define MASTER_LIBRARY_HAVE_STDLIB_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdlib.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDMCHAR_H
#	define MASTER_LIBRARY_HAVE_STDMCHAR_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDMCHAR_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDMCHAR_H
#		define MASTER_LIBRARY_HAVE_STDMCHAR_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDMCHAR_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDMCHAR_H
#			define MASTER_LIBRARY_HAVE_STDMCHAR_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDMCHAR_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDMCHAR_H
#				define MASTER_LIBRARY_HAVE_STDMCHAR_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDMCHAR_H
#				define MASTER_LIBRARY_HAVE_STDMCHAR_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdmchar.h !# */

#ifdef MASTER_LIBRARY_HAVE_STDNORETURN_H
#	define MASTER_LIBRARY_HAVE_STDNORETURN_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDNORETURN_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STDNORETURN_H
#		define MASTER_LIBRARY_HAVE_STDNORETURN_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDNORETURN_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDNORETURN_H
#			define MASTER_LIBRARY_HAVE_STDNORETURN_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDNORETURN_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDNORETURN_H
#				define MASTER_LIBRARY_HAVE_STDNORETURN_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDNORETURN_H
#				define MASTER_LIBRARY_HAVE_STDNORETURN_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdnoreturn.h !# */

#ifdef MASTER_LIBRARY_HAVE_STRING_H
#	define MASTER_LIBRARY_HAVE_STRING_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STRING_H) == 40001
#		undef MASTER_LIBRARY_HAVE_STRING_H
#		define MASTER_LIBRARY_HAVE_STRING_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STRING_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STRING_H
#			define MASTER_LIBRARY_HAVE_STRING_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STRING_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STRING_H
#				define MASTER_LIBRARY_HAVE_STRING_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_STRING_H
#				define MASTER_LIBRARY_HAVE_STRING_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! string.h !# */

#ifdef MASTER_LIBRARY_HAVE_TGMATH_H
#	define MASTER_LIBRARY_HAVE_TGMATH_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TGMATH_H) == 40001
#		undef MASTER_LIBRARY_HAVE_TGMATH_H
#		define MASTER_LIBRARY_HAVE_TGMATH_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TGMATH_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TGMATH_H
#			define MASTER_LIBRARY_HAVE_TGMATH_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TGMATH_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TGMATH_H
#				define MASTER_LIBRARY_HAVE_TGMATH_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_TGMATH_H
#				define MASTER_LIBRARY_HAVE_TGMATH_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! tgmath.h !# */

#ifdef MASTER_LIBRARY_HAVE_THREADS_H
#	define MASTER_LIBRARY_HAVE_THREADS_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_THREADS_H) == 40001
#		undef MASTER_LIBRARY_HAVE_THREADS_H
#		define MASTER_LIBRARY_HAVE_THREADS_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_THREADS_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_THREADS_H
#			define MASTER_LIBRARY_HAVE_THREADS_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_THREADS_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_THREADS_H
#				define MASTER_LIBRARY_HAVE_THREADS_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_THREADS_H
#				define MASTER_LIBRARY_HAVE_THREADS_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! threads.h !# */

#ifdef MASTER_LIBRARY_HAVE_TIME_H
#	define MASTER_LIBRARY_HAVE_TIME_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TIME_H) == 40001
#		undef MASTER_LIBRARY_HAVE_TIME_H
#		define MASTER_LIBRARY_HAVE_TIME_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TIME_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TIME_H
#			define MASTER_LIBRARY_HAVE_TIME_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TIME_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TIME_H
#				define MASTER_LIBRARY_HAVE_TIME_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_TIME_H
#				define MASTER_LIBRARY_HAVE_TIME_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! time.h !# */

#ifdef MASTER_LIBRARY_HAVE_UCHAR_H
#	define MASTER_LIBRARY_HAVE_UCHAR_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_UCHAR_H) == 40001
#		undef MASTER_LIBRARY_HAVE_UCHAR_H
#		define MASTER_LIBRARY_HAVE_UCHAR_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_UCHAR_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_UCHAR_H
#			define MASTER_LIBRARY_HAVE_UCHAR_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_UCHAR_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_UCHAR_H
#				define MASTER_LIBRARY_HAVE_UCHAR_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_UCHAR_H
#				define MASTER_LIBRARY_HAVE_UCHAR_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! uchar.h !# */

#ifdef MASTER_LIBRARY_HAVE_WCHAR_H
#	define MASTER_LIBRARY_HAVE_WCHAR_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WCHAR_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WCHAR_H
#		define MASTER_LIBRARY_HAVE_WCHAR_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WCHAR_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WCHAR_H
#			define MASTER_LIBRARY_HAVE_WCHAR_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WCHAR_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WCHAR_H
#				define MASTER_LIBRARY_HAVE_WCHAR_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WCHAR_H
#				define MASTER_LIBRARY_HAVE_WCHAR_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! wchar.h !# */

#ifdef MASTER_LIBRARY_HAVE_WCTYPE_H
#	define MASTER_LIBRARY_HAVE_WCTYPE_H0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_WCTYPE_H) == 40001
#		undef MASTER_LIBRARY_HAVE_WCTYPE_H
#		define MASTER_LIBRARY_HAVE_WCTYPE_H 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_WCTYPE_H + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_WCTYPE_H
#			define MASTER_LIBRARY_HAVE_WCTYPE_H 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_WCTYPE_H + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_WCTYPE_H
#				define MASTER_LIBRARY_HAVE_WCTYPE_H 0
#			else
#				undef MASTER_LIBRARY_HAVE_WCTYPE_H
#				define MASTER_LIBRARY_HAVE_WCTYPE_H 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! wctype.h !# */

#ifdef MASTER_LIBRARY_HAVE_CSTDLIB
#	define MASTER_LIBRARY_HAVE_CSTDLIB0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSTDLIB) == 40001
#		undef MASTER_LIBRARY_HAVE_CSTDLIB
#		define MASTER_LIBRARY_HAVE_CSTDLIB 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSTDLIB + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSTDLIB
#			define MASTER_LIBRARY_HAVE_CSTDLIB 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSTDLIB + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSTDLIB
#				define MASTER_LIBRARY_HAVE_CSTDLIB 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSTDLIB
#				define MASTER_LIBRARY_HAVE_CSTDLIB 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cstdlib !# */

#ifdef MASTER_LIBRARY_HAVE_EXECUTION
#	define MASTER_LIBRARY_HAVE_EXECUTION0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_EXECUTION) == 40001
#		undef MASTER_LIBRARY_HAVE_EXECUTION
#		define MASTER_LIBRARY_HAVE_EXECUTION 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_EXECUTION + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_EXECUTION
#			define MASTER_LIBRARY_HAVE_EXECUTION 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_EXECUTION + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_EXECUTION
#				define MASTER_LIBRARY_HAVE_EXECUTION 0
#			else
#				undef MASTER_LIBRARY_HAVE_EXECUTION
#				define MASTER_LIBRARY_HAVE_EXECUTION 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! execution !# */

#ifdef MASTER_LIBRARY_HAVE_CFLOAT
#	define MASTER_LIBRARY_HAVE_CFLOAT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CFLOAT) == 40001
#		undef MASTER_LIBRARY_HAVE_CFLOAT
#		define MASTER_LIBRARY_HAVE_CFLOAT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CFLOAT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CFLOAT
#			define MASTER_LIBRARY_HAVE_CFLOAT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CFLOAT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CFLOAT
#				define MASTER_LIBRARY_HAVE_CFLOAT 0
#			else
#				undef MASTER_LIBRARY_HAVE_CFLOAT
#				define MASTER_LIBRARY_HAVE_CFLOAT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cfloat !# */

#ifdef MASTER_LIBRARY_HAVE_CLIMITS
#	define MASTER_LIBRARY_HAVE_CLIMITS0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CLIMITS) == 40001
#		undef MASTER_LIBRARY_HAVE_CLIMITS
#		define MASTER_LIBRARY_HAVE_CLIMITS 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CLIMITS + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CLIMITS
#			define MASTER_LIBRARY_HAVE_CLIMITS 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CLIMITS + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CLIMITS
#				define MASTER_LIBRARY_HAVE_CLIMITS 0
#			else
#				undef MASTER_LIBRARY_HAVE_CLIMITS
#				define MASTER_LIBRARY_HAVE_CLIMITS 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! climits !# */

#ifdef MASTER_LIBRARY_HAVE_COMPARE
#	define MASTER_LIBRARY_HAVE_COMPARE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_COMPARE) == 40001
#		undef MASTER_LIBRARY_HAVE_COMPARE
#		define MASTER_LIBRARY_HAVE_COMPARE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_COMPARE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_COMPARE
#			define MASTER_LIBRARY_HAVE_COMPARE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_COMPARE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_COMPARE
#				define MASTER_LIBRARY_HAVE_COMPARE 0
#			else
#				undef MASTER_LIBRARY_HAVE_COMPARE
#				define MASTER_LIBRARY_HAVE_COMPARE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! compare !# */

#ifdef MASTER_LIBRARY_HAVE_CONTRACTS
#	define MASTER_LIBRARY_HAVE_CONTRACTS0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CONTRACTS) == 40001
#		undef MASTER_LIBRARY_HAVE_CONTRACTS
#		define MASTER_LIBRARY_HAVE_CONTRACTS 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CONTRACTS + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CONTRACTS
#			define MASTER_LIBRARY_HAVE_CONTRACTS 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CONTRACTS + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CONTRACTS
#				define MASTER_LIBRARY_HAVE_CONTRACTS 0
#			else
#				undef MASTER_LIBRARY_HAVE_CONTRACTS
#				define MASTER_LIBRARY_HAVE_CONTRACTS 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! contracts !# */

#ifdef MASTER_LIBRARY_HAVE_COROUTINE
#	define MASTER_LIBRARY_HAVE_COROUTINE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_COROUTINE) == 40001
#		undef MASTER_LIBRARY_HAVE_COROUTINE
#		define MASTER_LIBRARY_HAVE_COROUTINE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_COROUTINE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_COROUTINE
#			define MASTER_LIBRARY_HAVE_COROUTINE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_COROUTINE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_COROUTINE
#				define MASTER_LIBRARY_HAVE_COROUTINE 0
#			else
#				undef MASTER_LIBRARY_HAVE_COROUTINE
#				define MASTER_LIBRARY_HAVE_COROUTINE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! coroutine !# */

#ifdef MASTER_LIBRARY_HAVE_CSETJMP
#	define MASTER_LIBRARY_HAVE_CSETJMP0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSETJMP) == 40001
#		undef MASTER_LIBRARY_HAVE_CSETJMP
#		define MASTER_LIBRARY_HAVE_CSETJMP 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSETJMP + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSETJMP
#			define MASTER_LIBRARY_HAVE_CSETJMP 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSETJMP + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSETJMP
#				define MASTER_LIBRARY_HAVE_CSETJMP 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSETJMP
#				define MASTER_LIBRARY_HAVE_CSETJMP 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! csetjmp !# */

#ifdef MASTER_LIBRARY_HAVE_CSIGNAL
#	define MASTER_LIBRARY_HAVE_CSIGNAL0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSIGNAL) == 40001
#		undef MASTER_LIBRARY_HAVE_CSIGNAL
#		define MASTER_LIBRARY_HAVE_CSIGNAL 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSIGNAL + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSIGNAL
#			define MASTER_LIBRARY_HAVE_CSIGNAL 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSIGNAL + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSIGNAL
#				define MASTER_LIBRARY_HAVE_CSIGNAL 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSIGNAL
#				define MASTER_LIBRARY_HAVE_CSIGNAL 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! csignal !# */

#ifdef MASTER_LIBRARY_HAVE_CSTDARG
#	define MASTER_LIBRARY_HAVE_CSTDARG0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSTDARG) == 40001
#		undef MASTER_LIBRARY_HAVE_CSTDARG
#		define MASTER_LIBRARY_HAVE_CSTDARG 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSTDARG + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSTDARG
#			define MASTER_LIBRARY_HAVE_CSTDARG 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSTDARG + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSTDARG
#				define MASTER_LIBRARY_HAVE_CSTDARG 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSTDARG
#				define MASTER_LIBRARY_HAVE_CSTDARG 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cstdarg !# */

#ifdef MASTER_LIBRARY_HAVE_CSTDDEF
#	define MASTER_LIBRARY_HAVE_CSTDDEF0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSTDDEF) == 40001
#		undef MASTER_LIBRARY_HAVE_CSTDDEF
#		define MASTER_LIBRARY_HAVE_CSTDDEF 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSTDDEF + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSTDDEF
#			define MASTER_LIBRARY_HAVE_CSTDDEF 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSTDDEF + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSTDDEF
#				define MASTER_LIBRARY_HAVE_CSTDDEF 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSTDDEF
#				define MASTER_LIBRARY_HAVE_CSTDDEF 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cstddef !# */

#ifdef MASTER_LIBRARY_HAVE_CSTDINT
#	define MASTER_LIBRARY_HAVE_CSTDINT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSTDINT) == 40001
#		undef MASTER_LIBRARY_HAVE_CSTDINT
#		define MASTER_LIBRARY_HAVE_CSTDINT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSTDINT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSTDINT
#			define MASTER_LIBRARY_HAVE_CSTDINT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSTDINT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSTDINT
#				define MASTER_LIBRARY_HAVE_CSTDINT 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSTDINT
#				define MASTER_LIBRARY_HAVE_CSTDINT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cstdint !# */

#ifdef MASTER_LIBRARY_HAVE_EXCEPTION
#	define MASTER_LIBRARY_HAVE_EXCEPTION0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_EXCEPTION) == 40001
#		undef MASTER_LIBRARY_HAVE_EXCEPTION
#		define MASTER_LIBRARY_HAVE_EXCEPTION 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_EXCEPTION + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_EXCEPTION
#			define MASTER_LIBRARY_HAVE_EXCEPTION 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_EXCEPTION + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_EXCEPTION
#				define MASTER_LIBRARY_HAVE_EXCEPTION 0
#			else
#				undef MASTER_LIBRARY_HAVE_EXCEPTION
#				define MASTER_LIBRARY_HAVE_EXCEPTION 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! exception !# */

#ifdef MASTER_LIBRARY_HAVE_INITIALIZER_LIST
#	define MASTER_LIBRARY_HAVE_INITIALIZER_LIST0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_INITIALIZER_LIST) == 40001
#		undef MASTER_LIBRARY_HAVE_INITIALIZER_LIST
#		define MASTER_LIBRARY_HAVE_INITIALIZER_LIST 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_INITIALIZER_LIST + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_INITIALIZER_LIST
#			define MASTER_LIBRARY_HAVE_INITIALIZER_LIST 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_INITIALIZER_LIST + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_INITIALIZER_LIST
#				define MASTER_LIBRARY_HAVE_INITIALIZER_LIST 0
#			else
#				undef MASTER_LIBRARY_HAVE_INITIALIZER_LIST
#				define MASTER_LIBRARY_HAVE_INITIALIZER_LIST 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! initializer_list !# */

#ifdef MASTER_LIBRARY_HAVE_LIMITS
#	define MASTER_LIBRARY_HAVE_LIMITS0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LIMITS) == 40001
#		undef MASTER_LIBRARY_HAVE_LIMITS
#		define MASTER_LIBRARY_HAVE_LIMITS 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LIMITS + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LIMITS
#			define MASTER_LIBRARY_HAVE_LIMITS 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LIMITS + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LIMITS
#				define MASTER_LIBRARY_HAVE_LIMITS 0
#			else
#				undef MASTER_LIBRARY_HAVE_LIMITS
#				define MASTER_LIBRARY_HAVE_LIMITS 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! limits !# */

#ifdef MASTER_LIBRARY_HAVE_NEW
#	define MASTER_LIBRARY_HAVE_NEW0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NEW) == 40001
#		undef MASTER_LIBRARY_HAVE_NEW
#		define MASTER_LIBRARY_HAVE_NEW 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NEW + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NEW
#			define MASTER_LIBRARY_HAVE_NEW 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NEW + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NEW
#				define MASTER_LIBRARY_HAVE_NEW 0
#			else
#				undef MASTER_LIBRARY_HAVE_NEW
#				define MASTER_LIBRARY_HAVE_NEW 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! new !# */

#ifdef MASTER_LIBRARY_HAVE_SOURCE_LOCATION
#	define MASTER_LIBRARY_HAVE_SOURCE_LOCATION0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SOURCE_LOCATION) == 40001
#		undef MASTER_LIBRARY_HAVE_SOURCE_LOCATION
#		define MASTER_LIBRARY_HAVE_SOURCE_LOCATION 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SOURCE_LOCATION + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SOURCE_LOCATION
#			define MASTER_LIBRARY_HAVE_SOURCE_LOCATION 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SOURCE_LOCATION + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SOURCE_LOCATION
#				define MASTER_LIBRARY_HAVE_SOURCE_LOCATION 0
#			else
#				undef MASTER_LIBRARY_HAVE_SOURCE_LOCATION
#				define MASTER_LIBRARY_HAVE_SOURCE_LOCATION 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! source_location !# */

#ifdef MASTER_LIBRARY_HAVE_STDFLOAT
#	define MASTER_LIBRARY_HAVE_STDFLOAT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDFLOAT) == 40001
#		undef MASTER_LIBRARY_HAVE_STDFLOAT
#		define MASTER_LIBRARY_HAVE_STDFLOAT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDFLOAT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDFLOAT
#			define MASTER_LIBRARY_HAVE_STDFLOAT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDFLOAT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDFLOAT
#				define MASTER_LIBRARY_HAVE_STDFLOAT 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDFLOAT
#				define MASTER_LIBRARY_HAVE_STDFLOAT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdfloat !# */

#ifdef MASTER_LIBRARY_HAVE_TYPEINDEX
#	define MASTER_LIBRARY_HAVE_TYPEINDEX0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TYPEINDEX) == 40001
#		undef MASTER_LIBRARY_HAVE_TYPEINDEX
#		define MASTER_LIBRARY_HAVE_TYPEINDEX 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TYPEINDEX + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TYPEINDEX
#			define MASTER_LIBRARY_HAVE_TYPEINDEX 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TYPEINDEX + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TYPEINDEX
#				define MASTER_LIBRARY_HAVE_TYPEINDEX 0
#			else
#				undef MASTER_LIBRARY_HAVE_TYPEINDEX
#				define MASTER_LIBRARY_HAVE_TYPEINDEX 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! typeindex !# */

#ifdef MASTER_LIBRARY_HAVE_TYPEINFO
#	define MASTER_LIBRARY_HAVE_TYPEINFO0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TYPEINFO) == 40001
#		undef MASTER_LIBRARY_HAVE_TYPEINFO
#		define MASTER_LIBRARY_HAVE_TYPEINFO 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TYPEINFO + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TYPEINFO
#			define MASTER_LIBRARY_HAVE_TYPEINFO 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TYPEINFO + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TYPEINFO
#				define MASTER_LIBRARY_HAVE_TYPEINFO 0
#			else
#				undef MASTER_LIBRARY_HAVE_TYPEINFO
#				define MASTER_LIBRARY_HAVE_TYPEINFO 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! typeinfo !# */

#ifdef MASTER_LIBRARY_HAVE_VERSION
#	define MASTER_LIBRARY_HAVE_VERSION0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_VERSION) == 40001
#		undef MASTER_LIBRARY_HAVE_VERSION
#		define MASTER_LIBRARY_HAVE_VERSION 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_VERSION + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_VERSION
#			define MASTER_LIBRARY_HAVE_VERSION 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_VERSION + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_VERSION
#				define MASTER_LIBRARY_HAVE_VERSION 0
#			else
#				undef MASTER_LIBRARY_HAVE_VERSION
#				define MASTER_LIBRARY_HAVE_VERSION 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! version !# */

#ifdef MASTER_LIBRARY_HAVE_CONCEPTS
#	define MASTER_LIBRARY_HAVE_CONCEPTS0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CONCEPTS) == 40001
#		undef MASTER_LIBRARY_HAVE_CONCEPTS
#		define MASTER_LIBRARY_HAVE_CONCEPTS 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CONCEPTS + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CONCEPTS
#			define MASTER_LIBRARY_HAVE_CONCEPTS 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CONCEPTS + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CONCEPTS
#				define MASTER_LIBRARY_HAVE_CONCEPTS 0
#			else
#				undef MASTER_LIBRARY_HAVE_CONCEPTS
#				define MASTER_LIBRARY_HAVE_CONCEPTS 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! concepts !# */

#ifdef MASTER_LIBRARY_HAVE_CASSERT
#	define MASTER_LIBRARY_HAVE_CASSERT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CASSERT) == 40001
#		undef MASTER_LIBRARY_HAVE_CASSERT
#		define MASTER_LIBRARY_HAVE_CASSERT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CASSERT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CASSERT
#			define MASTER_LIBRARY_HAVE_CASSERT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CASSERT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CASSERT
#				define MASTER_LIBRARY_HAVE_CASSERT 0
#			else
#				undef MASTER_LIBRARY_HAVE_CASSERT
#				define MASTER_LIBRARY_HAVE_CASSERT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cassert !# */

#ifdef MASTER_LIBRARY_HAVE_CERRNO
#	define MASTER_LIBRARY_HAVE_CERRNO0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CERRNO) == 40001
#		undef MASTER_LIBRARY_HAVE_CERRNO
#		define MASTER_LIBRARY_HAVE_CERRNO 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CERRNO + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CERRNO
#			define MASTER_LIBRARY_HAVE_CERRNO 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CERRNO + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CERRNO
#				define MASTER_LIBRARY_HAVE_CERRNO 0
#			else
#				undef MASTER_LIBRARY_HAVE_CERRNO
#				define MASTER_LIBRARY_HAVE_CERRNO 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cerrno !# */

#ifdef MASTER_LIBRARY_HAVE_DEBUGGING
#	define MASTER_LIBRARY_HAVE_DEBUGGING0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DEBUGGING) == 40001
#		undef MASTER_LIBRARY_HAVE_DEBUGGING
#		define MASTER_LIBRARY_HAVE_DEBUGGING 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DEBUGGING + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DEBUGGING
#			define MASTER_LIBRARY_HAVE_DEBUGGING 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DEBUGGING + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DEBUGGING
#				define MASTER_LIBRARY_HAVE_DEBUGGING 0
#			else
#				undef MASTER_LIBRARY_HAVE_DEBUGGING
#				define MASTER_LIBRARY_HAVE_DEBUGGING 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! debugging !# */

#ifdef MASTER_LIBRARY_HAVE_STACKTRACE
#	define MASTER_LIBRARY_HAVE_STACKTRACE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STACKTRACE) == 40001
#		undef MASTER_LIBRARY_HAVE_STACKTRACE
#		define MASTER_LIBRARY_HAVE_STACKTRACE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STACKTRACE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STACKTRACE
#			define MASTER_LIBRARY_HAVE_STACKTRACE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STACKTRACE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STACKTRACE
#				define MASTER_LIBRARY_HAVE_STACKTRACE 0
#			else
#				undef MASTER_LIBRARY_HAVE_STACKTRACE
#				define MASTER_LIBRARY_HAVE_STACKTRACE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stacktrace !# */

#ifdef MASTER_LIBRARY_HAVE_STDEXCEPT
#	define MASTER_LIBRARY_HAVE_STDEXCEPT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STDEXCEPT) == 40001
#		undef MASTER_LIBRARY_HAVE_STDEXCEPT
#		define MASTER_LIBRARY_HAVE_STDEXCEPT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STDEXCEPT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STDEXCEPT
#			define MASTER_LIBRARY_HAVE_STDEXCEPT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STDEXCEPT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STDEXCEPT
#				define MASTER_LIBRARY_HAVE_STDEXCEPT 0
#			else
#				undef MASTER_LIBRARY_HAVE_STDEXCEPT
#				define MASTER_LIBRARY_HAVE_STDEXCEPT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stdexcept !# */

#ifdef MASTER_LIBRARY_HAVE_SYSTEM_ERROR
#	define MASTER_LIBRARY_HAVE_SYSTEM_ERROR0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYSTEM_ERROR) == 40001
#		undef MASTER_LIBRARY_HAVE_SYSTEM_ERROR
#		define MASTER_LIBRARY_HAVE_SYSTEM_ERROR 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYSTEM_ERROR + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYSTEM_ERROR
#			define MASTER_LIBRARY_HAVE_SYSTEM_ERROR 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYSTEM_ERROR + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYSTEM_ERROR
#				define MASTER_LIBRARY_HAVE_SYSTEM_ERROR 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYSTEM_ERROR
#				define MASTER_LIBRARY_HAVE_SYSTEM_ERROR 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! system_error !# */

#ifdef MASTER_LIBRARY_HAVE_MEMORY
#	define MASTER_LIBRARY_HAVE_MEMORY0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MEMORY) == 40001
#		undef MASTER_LIBRARY_HAVE_MEMORY
#		define MASTER_LIBRARY_HAVE_MEMORY 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MEMORY + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MEMORY
#			define MASTER_LIBRARY_HAVE_MEMORY 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MEMORY + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MEMORY
#				define MASTER_LIBRARY_HAVE_MEMORY 0
#			else
#				undef MASTER_LIBRARY_HAVE_MEMORY
#				define MASTER_LIBRARY_HAVE_MEMORY 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! memory !# */

#ifdef MASTER_LIBRARY_HAVE_MEMORY_RESOURCE
#	define MASTER_LIBRARY_HAVE_MEMORY_RESOURCE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MEMORY_RESOURCE) == 40001
#		undef MASTER_LIBRARY_HAVE_MEMORY_RESOURCE
#		define MASTER_LIBRARY_HAVE_MEMORY_RESOURCE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MEMORY_RESOURCE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MEMORY_RESOURCE
#			define MASTER_LIBRARY_HAVE_MEMORY_RESOURCE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MEMORY_RESOURCE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MEMORY_RESOURCE
#				define MASTER_LIBRARY_HAVE_MEMORY_RESOURCE 0
#			else
#				undef MASTER_LIBRARY_HAVE_MEMORY_RESOURCE
#				define MASTER_LIBRARY_HAVE_MEMORY_RESOURCE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! memory_resource !# */

#ifdef MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR
#	define MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR) == 40001
#		undef MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR
#		define MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR
#			define MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR
#				define MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR 0
#			else
#				undef MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR
#				define MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! scoped_allocator !# */

#ifdef MASTER_LIBRARY_HAVE_RATIO
#	define MASTER_LIBRARY_HAVE_RATIO0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_RATIO) == 40001
#		undef MASTER_LIBRARY_HAVE_RATIO
#		define MASTER_LIBRARY_HAVE_RATIO 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_RATIO + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_RATIO
#			define MASTER_LIBRARY_HAVE_RATIO 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_RATIO + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_RATIO
#				define MASTER_LIBRARY_HAVE_RATIO 0
#			else
#				undef MASTER_LIBRARY_HAVE_RATIO
#				define MASTER_LIBRARY_HAVE_RATIO 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ratio !# */

#ifdef MASTER_LIBRARY_HAVE_TYPE_TRAITS
#	define MASTER_LIBRARY_HAVE_TYPE_TRAITS0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TYPE_TRAITS) == 40001
#		undef MASTER_LIBRARY_HAVE_TYPE_TRAITS
#		define MASTER_LIBRARY_HAVE_TYPE_TRAITS 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TYPE_TRAITS + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TYPE_TRAITS
#			define MASTER_LIBRARY_HAVE_TYPE_TRAITS 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TYPE_TRAITS + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TYPE_TRAITS
#				define MASTER_LIBRARY_HAVE_TYPE_TRAITS 0
#			else
#				undef MASTER_LIBRARY_HAVE_TYPE_TRAITS
#				define MASTER_LIBRARY_HAVE_TYPE_TRAITS 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! type_traits !# */

#ifdef MASTER_LIBRARY_HAVE_ANY
#	define MASTER_LIBRARY_HAVE_ANY0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ANY) == 40001
#		undef MASTER_LIBRARY_HAVE_ANY
#		define MASTER_LIBRARY_HAVE_ANY 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ANY + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ANY
#			define MASTER_LIBRARY_HAVE_ANY 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ANY + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ANY
#				define MASTER_LIBRARY_HAVE_ANY 0
#			else
#				undef MASTER_LIBRARY_HAVE_ANY
#				define MASTER_LIBRARY_HAVE_ANY 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! any !# */

#ifdef MASTER_LIBRARY_HAVE_BIT
#	define MASTER_LIBRARY_HAVE_BIT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_BIT) == 40001
#		undef MASTER_LIBRARY_HAVE_BIT
#		define MASTER_LIBRARY_HAVE_BIT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_BIT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_BIT
#			define MASTER_LIBRARY_HAVE_BIT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_BIT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_BIT
#				define MASTER_LIBRARY_HAVE_BIT 0
#			else
#				undef MASTER_LIBRARY_HAVE_BIT
#				define MASTER_LIBRARY_HAVE_BIT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! bit !# */

#ifdef MASTER_LIBRARY_HAVE_BITSET
#	define MASTER_LIBRARY_HAVE_BITSET0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_BITSET) == 40001
#		undef MASTER_LIBRARY_HAVE_BITSET
#		define MASTER_LIBRARY_HAVE_BITSET 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_BITSET + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_BITSET
#			define MASTER_LIBRARY_HAVE_BITSET 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_BITSET + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_BITSET
#				define MASTER_LIBRARY_HAVE_BITSET 0
#			else
#				undef MASTER_LIBRARY_HAVE_BITSET
#				define MASTER_LIBRARY_HAVE_BITSET 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! bitset !# */

#ifdef MASTER_LIBRARY_HAVE_EXPECTED
#	define MASTER_LIBRARY_HAVE_EXPECTED0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_EXPECTED) == 40001
#		undef MASTER_LIBRARY_HAVE_EXPECTED
#		define MASTER_LIBRARY_HAVE_EXPECTED 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_EXPECTED + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_EXPECTED
#			define MASTER_LIBRARY_HAVE_EXPECTED 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_EXPECTED + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_EXPECTED
#				define MASTER_LIBRARY_HAVE_EXPECTED 0
#			else
#				undef MASTER_LIBRARY_HAVE_EXPECTED
#				define MASTER_LIBRARY_HAVE_EXPECTED 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! expected !# */

#ifdef MASTER_LIBRARY_HAVE_FUNCTIONAL
#	define MASTER_LIBRARY_HAVE_FUNCTIONAL0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FUNCTIONAL) == 40001
#		undef MASTER_LIBRARY_HAVE_FUNCTIONAL
#		define MASTER_LIBRARY_HAVE_FUNCTIONAL 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FUNCTIONAL + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FUNCTIONAL
#			define MASTER_LIBRARY_HAVE_FUNCTIONAL 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FUNCTIONAL + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FUNCTIONAL
#				define MASTER_LIBRARY_HAVE_FUNCTIONAL 0
#			else
#				undef MASTER_LIBRARY_HAVE_FUNCTIONAL
#				define MASTER_LIBRARY_HAVE_FUNCTIONAL 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! functional !# */

#ifdef MASTER_LIBRARY_HAVE_OPTIONAL
#	define MASTER_LIBRARY_HAVE_OPTIONAL0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_OPTIONAL) == 40001
#		undef MASTER_LIBRARY_HAVE_OPTIONAL
#		define MASTER_LIBRARY_HAVE_OPTIONAL 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_OPTIONAL + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_OPTIONAL
#			define MASTER_LIBRARY_HAVE_OPTIONAL 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_OPTIONAL + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_OPTIONAL
#				define MASTER_LIBRARY_HAVE_OPTIONAL 0
#			else
#				undef MASTER_LIBRARY_HAVE_OPTIONAL
#				define MASTER_LIBRARY_HAVE_OPTIONAL 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! optional !# */

#ifdef MASTER_LIBRARY_HAVE_TUPLE
#	define MASTER_LIBRARY_HAVE_TUPLE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TUPLE) == 40001
#		undef MASTER_LIBRARY_HAVE_TUPLE
#		define MASTER_LIBRARY_HAVE_TUPLE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TUPLE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TUPLE
#			define MASTER_LIBRARY_HAVE_TUPLE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TUPLE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TUPLE
#				define MASTER_LIBRARY_HAVE_TUPLE 0
#			else
#				undef MASTER_LIBRARY_HAVE_TUPLE
#				define MASTER_LIBRARY_HAVE_TUPLE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! tuple !# */

#ifdef MASTER_LIBRARY_HAVE_UTILITY
#	define MASTER_LIBRARY_HAVE_UTILITY0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_UTILITY) == 40001
#		undef MASTER_LIBRARY_HAVE_UTILITY
#		define MASTER_LIBRARY_HAVE_UTILITY 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_UTILITY + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_UTILITY
#			define MASTER_LIBRARY_HAVE_UTILITY 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_UTILITY + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_UTILITY
#				define MASTER_LIBRARY_HAVE_UTILITY 0
#			else
#				undef MASTER_LIBRARY_HAVE_UTILITY
#				define MASTER_LIBRARY_HAVE_UTILITY 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! utility !# */

#ifdef MASTER_LIBRARY_HAVE_VARIANT
#	define MASTER_LIBRARY_HAVE_VARIANT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_VARIANT) == 40001
#		undef MASTER_LIBRARY_HAVE_VARIANT
#		define MASTER_LIBRARY_HAVE_VARIANT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_VARIANT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_VARIANT
#			define MASTER_LIBRARY_HAVE_VARIANT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_VARIANT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_VARIANT
#				define MASTER_LIBRARY_HAVE_VARIANT 0
#			else
#				undef MASTER_LIBRARY_HAVE_VARIANT
#				define MASTER_LIBRARY_HAVE_VARIANT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! variant !# */

#ifdef MASTER_LIBRARY_HAVE_ARRAY
#	define MASTER_LIBRARY_HAVE_ARRAY0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ARRAY) == 40001
#		undef MASTER_LIBRARY_HAVE_ARRAY
#		define MASTER_LIBRARY_HAVE_ARRAY 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ARRAY + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ARRAY
#			define MASTER_LIBRARY_HAVE_ARRAY 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ARRAY + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ARRAY
#				define MASTER_LIBRARY_HAVE_ARRAY 0
#			else
#				undef MASTER_LIBRARY_HAVE_ARRAY
#				define MASTER_LIBRARY_HAVE_ARRAY 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! array !# */

#ifdef MASTER_LIBRARY_HAVE_DEQUE
#	define MASTER_LIBRARY_HAVE_DEQUE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_DEQUE) == 40001
#		undef MASTER_LIBRARY_HAVE_DEQUE
#		define MASTER_LIBRARY_HAVE_DEQUE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_DEQUE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_DEQUE
#			define MASTER_LIBRARY_HAVE_DEQUE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_DEQUE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_DEQUE
#				define MASTER_LIBRARY_HAVE_DEQUE 0
#			else
#				undef MASTER_LIBRARY_HAVE_DEQUE
#				define MASTER_LIBRARY_HAVE_DEQUE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! deque !# */

#ifdef MASTER_LIBRARY_HAVE_FLAT_MAP
#	define MASTER_LIBRARY_HAVE_FLAT_MAP0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FLAT_MAP) == 40001
#		undef MASTER_LIBRARY_HAVE_FLAT_MAP
#		define MASTER_LIBRARY_HAVE_FLAT_MAP 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FLAT_MAP + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FLAT_MAP
#			define MASTER_LIBRARY_HAVE_FLAT_MAP 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FLAT_MAP + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FLAT_MAP
#				define MASTER_LIBRARY_HAVE_FLAT_MAP 0
#			else
#				undef MASTER_LIBRARY_HAVE_FLAT_MAP
#				define MASTER_LIBRARY_HAVE_FLAT_MAP 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! flat_map !# */

#ifdef MASTER_LIBRARY_HAVE_FLAT_SET
#	define MASTER_LIBRARY_HAVE_FLAT_SET0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FLAT_SET) == 40001
#		undef MASTER_LIBRARY_HAVE_FLAT_SET
#		define MASTER_LIBRARY_HAVE_FLAT_SET 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FLAT_SET + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FLAT_SET
#			define MASTER_LIBRARY_HAVE_FLAT_SET 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FLAT_SET + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FLAT_SET
#				define MASTER_LIBRARY_HAVE_FLAT_SET 0
#			else
#				undef MASTER_LIBRARY_HAVE_FLAT_SET
#				define MASTER_LIBRARY_HAVE_FLAT_SET 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! flat_set !# */

#ifdef MASTER_LIBRARY_HAVE_FORWARD_LIST
#	define MASTER_LIBRARY_HAVE_FORWARD_LIST0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FORWARD_LIST) == 40001
#		undef MASTER_LIBRARY_HAVE_FORWARD_LIST
#		define MASTER_LIBRARY_HAVE_FORWARD_LIST 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FORWARD_LIST + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FORWARD_LIST
#			define MASTER_LIBRARY_HAVE_FORWARD_LIST 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FORWARD_LIST + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FORWARD_LIST
#				define MASTER_LIBRARY_HAVE_FORWARD_LIST 0
#			else
#				undef MASTER_LIBRARY_HAVE_FORWARD_LIST
#				define MASTER_LIBRARY_HAVE_FORWARD_LIST 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! forward_list !# */

#ifdef MASTER_LIBRARY_HAVE_HIVE
#	define MASTER_LIBRARY_HAVE_HIVE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_HIVE) == 40001
#		undef MASTER_LIBRARY_HAVE_HIVE
#		define MASTER_LIBRARY_HAVE_HIVE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_HIVE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_HIVE
#			define MASTER_LIBRARY_HAVE_HIVE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_HIVE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_HIVE
#				define MASTER_LIBRARY_HAVE_HIVE 0
#			else
#				undef MASTER_LIBRARY_HAVE_HIVE
#				define MASTER_LIBRARY_HAVE_HIVE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! hive !# */

#ifdef MASTER_LIBRARY_HAVE_INPLACE_VECTOR
#	define MASTER_LIBRARY_HAVE_INPLACE_VECTOR0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_INPLACE_VECTOR) == 40001
#		undef MASTER_LIBRARY_HAVE_INPLACE_VECTOR
#		define MASTER_LIBRARY_HAVE_INPLACE_VECTOR 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_INPLACE_VECTOR + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_INPLACE_VECTOR
#			define MASTER_LIBRARY_HAVE_INPLACE_VECTOR 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_INPLACE_VECTOR + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_INPLACE_VECTOR
#				define MASTER_LIBRARY_HAVE_INPLACE_VECTOR 0
#			else
#				undef MASTER_LIBRARY_HAVE_INPLACE_VECTOR
#				define MASTER_LIBRARY_HAVE_INPLACE_VECTOR 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! inplace_vector !# */

#ifdef MASTER_LIBRARY_HAVE_LIST
#	define MASTER_LIBRARY_HAVE_LIST0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LIST) == 40001
#		undef MASTER_LIBRARY_HAVE_LIST
#		define MASTER_LIBRARY_HAVE_LIST 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LIST + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LIST
#			define MASTER_LIBRARY_HAVE_LIST 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LIST + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LIST
#				define MASTER_LIBRARY_HAVE_LIST 0
#			else
#				undef MASTER_LIBRARY_HAVE_LIST
#				define MASTER_LIBRARY_HAVE_LIST 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! list !# */

#ifdef MASTER_LIBRARY_HAVE_MAP
#	define MASTER_LIBRARY_HAVE_MAP0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MAP) == 40001
#		undef MASTER_LIBRARY_HAVE_MAP
#		define MASTER_LIBRARY_HAVE_MAP 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MAP + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MAP
#			define MASTER_LIBRARY_HAVE_MAP 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MAP + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MAP
#				define MASTER_LIBRARY_HAVE_MAP 0
#			else
#				undef MASTER_LIBRARY_HAVE_MAP
#				define MASTER_LIBRARY_HAVE_MAP 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! map !# */

#ifdef MASTER_LIBRARY_HAVE_MDSPAN
#	define MASTER_LIBRARY_HAVE_MDSPAN0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MDSPAN) == 40001
#		undef MASTER_LIBRARY_HAVE_MDSPAN
#		define MASTER_LIBRARY_HAVE_MDSPAN 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MDSPAN + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MDSPAN
#			define MASTER_LIBRARY_HAVE_MDSPAN 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MDSPAN + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MDSPAN
#				define MASTER_LIBRARY_HAVE_MDSPAN 0
#			else
#				undef MASTER_LIBRARY_HAVE_MDSPAN
#				define MASTER_LIBRARY_HAVE_MDSPAN 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! mdspan !# */

#ifdef MASTER_LIBRARY_HAVE_QUEUE
#	define MASTER_LIBRARY_HAVE_QUEUE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_QUEUE) == 40001
#		undef MASTER_LIBRARY_HAVE_QUEUE
#		define MASTER_LIBRARY_HAVE_QUEUE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_QUEUE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_QUEUE
#			define MASTER_LIBRARY_HAVE_QUEUE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_QUEUE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_QUEUE
#				define MASTER_LIBRARY_HAVE_QUEUE 0
#			else
#				undef MASTER_LIBRARY_HAVE_QUEUE
#				define MASTER_LIBRARY_HAVE_QUEUE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! queue !# */

#ifdef MASTER_LIBRARY_HAVE_SET
#	define MASTER_LIBRARY_HAVE_SET0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SET) == 40001
#		undef MASTER_LIBRARY_HAVE_SET
#		define MASTER_LIBRARY_HAVE_SET 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SET + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SET
#			define MASTER_LIBRARY_HAVE_SET 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SET + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SET
#				define MASTER_LIBRARY_HAVE_SET 0
#			else
#				undef MASTER_LIBRARY_HAVE_SET
#				define MASTER_LIBRARY_HAVE_SET 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! set !# */

#ifdef MASTER_LIBRARY_HAVE_SPAN
#	define MASTER_LIBRARY_HAVE_SPAN0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SPAN) == 40001
#		undef MASTER_LIBRARY_HAVE_SPAN
#		define MASTER_LIBRARY_HAVE_SPAN 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SPAN + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SPAN
#			define MASTER_LIBRARY_HAVE_SPAN 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SPAN + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SPAN
#				define MASTER_LIBRARY_HAVE_SPAN 0
#			else
#				undef MASTER_LIBRARY_HAVE_SPAN
#				define MASTER_LIBRARY_HAVE_SPAN 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! span !# */

#ifdef MASTER_LIBRARY_HAVE_STACK
#	define MASTER_LIBRARY_HAVE_STACK0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STACK) == 40001
#		undef MASTER_LIBRARY_HAVE_STACK
#		define MASTER_LIBRARY_HAVE_STACK 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STACK + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STACK
#			define MASTER_LIBRARY_HAVE_STACK 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STACK + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STACK
#				define MASTER_LIBRARY_HAVE_STACK 0
#			else
#				undef MASTER_LIBRARY_HAVE_STACK
#				define MASTER_LIBRARY_HAVE_STACK 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stack !# */

#ifdef MASTER_LIBRARY_HAVE_UNORDERED_MAP
#	define MASTER_LIBRARY_HAVE_UNORDERED_MAP0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_UNORDERED_MAP) == 40001
#		undef MASTER_LIBRARY_HAVE_UNORDERED_MAP
#		define MASTER_LIBRARY_HAVE_UNORDERED_MAP 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_UNORDERED_MAP + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_UNORDERED_MAP
#			define MASTER_LIBRARY_HAVE_UNORDERED_MAP 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_UNORDERED_MAP + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_UNORDERED_MAP
#				define MASTER_LIBRARY_HAVE_UNORDERED_MAP 0
#			else
#				undef MASTER_LIBRARY_HAVE_UNORDERED_MAP
#				define MASTER_LIBRARY_HAVE_UNORDERED_MAP 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! unordered_map !# */

#ifdef MASTER_LIBRARY_HAVE_UNORDERED_SET
#	define MASTER_LIBRARY_HAVE_UNORDERED_SET0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_UNORDERED_SET) == 40001
#		undef MASTER_LIBRARY_HAVE_UNORDERED_SET
#		define MASTER_LIBRARY_HAVE_UNORDERED_SET 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_UNORDERED_SET + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_UNORDERED_SET
#			define MASTER_LIBRARY_HAVE_UNORDERED_SET 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_UNORDERED_SET + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_UNORDERED_SET
#				define MASTER_LIBRARY_HAVE_UNORDERED_SET 0
#			else
#				undef MASTER_LIBRARY_HAVE_UNORDERED_SET
#				define MASTER_LIBRARY_HAVE_UNORDERED_SET 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! unordered_set !# */

#ifdef MASTER_LIBRARY_HAVE_VECTOR
#	define MASTER_LIBRARY_HAVE_VECTOR0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_VECTOR) == 40001
#		undef MASTER_LIBRARY_HAVE_VECTOR
#		define MASTER_LIBRARY_HAVE_VECTOR 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_VECTOR + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_VECTOR
#			define MASTER_LIBRARY_HAVE_VECTOR 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_VECTOR + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_VECTOR
#				define MASTER_LIBRARY_HAVE_VECTOR 0
#			else
#				undef MASTER_LIBRARY_HAVE_VECTOR
#				define MASTER_LIBRARY_HAVE_VECTOR 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! vector !# */

#ifdef MASTER_LIBRARY_HAVE_ITERATOR
#	define MASTER_LIBRARY_HAVE_ITERATOR0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ITERATOR) == 40001
#		undef MASTER_LIBRARY_HAVE_ITERATOR
#		define MASTER_LIBRARY_HAVE_ITERATOR 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ITERATOR + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ITERATOR
#			define MASTER_LIBRARY_HAVE_ITERATOR 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ITERATOR + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ITERATOR
#				define MASTER_LIBRARY_HAVE_ITERATOR 0
#			else
#				undef MASTER_LIBRARY_HAVE_ITERATOR
#				define MASTER_LIBRARY_HAVE_ITERATOR 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! iterator !# */

#ifdef MASTER_LIBRARY_HAVE_GENERATOR
#	define MASTER_LIBRARY_HAVE_GENERATOR0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_GENERATOR) == 40001
#		undef MASTER_LIBRARY_HAVE_GENERATOR
#		define MASTER_LIBRARY_HAVE_GENERATOR 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_GENERATOR + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_GENERATOR
#			define MASTER_LIBRARY_HAVE_GENERATOR 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_GENERATOR + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_GENERATOR
#				define MASTER_LIBRARY_HAVE_GENERATOR 0
#			else
#				undef MASTER_LIBRARY_HAVE_GENERATOR
#				define MASTER_LIBRARY_HAVE_GENERATOR 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! generator !# */

#ifdef MASTER_LIBRARY_HAVE_RANGES
#	define MASTER_LIBRARY_HAVE_RANGES0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_RANGES) == 40001
#		undef MASTER_LIBRARY_HAVE_RANGES
#		define MASTER_LIBRARY_HAVE_RANGES 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_RANGES + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_RANGES
#			define MASTER_LIBRARY_HAVE_RANGES 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_RANGES + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_RANGES
#				define MASTER_LIBRARY_HAVE_RANGES 0
#			else
#				undef MASTER_LIBRARY_HAVE_RANGES
#				define MASTER_LIBRARY_HAVE_RANGES 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ranges !# */

#ifdef MASTER_LIBRARY_HAVE_ALGORITHM
#	define MASTER_LIBRARY_HAVE_ALGORITHM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ALGORITHM) == 40001
#		undef MASTER_LIBRARY_HAVE_ALGORITHM
#		define MASTER_LIBRARY_HAVE_ALGORITHM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ALGORITHM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ALGORITHM
#			define MASTER_LIBRARY_HAVE_ALGORITHM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ALGORITHM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ALGORITHM
#				define MASTER_LIBRARY_HAVE_ALGORITHM 0
#			else
#				undef MASTER_LIBRARY_HAVE_ALGORITHM
#				define MASTER_LIBRARY_HAVE_ALGORITHM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! algorithm !# */

#ifdef MASTER_LIBRARY_HAVE_NUMERIC
#	define MASTER_LIBRARY_HAVE_NUMERIC0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NUMERIC) == 40001
#		undef MASTER_LIBRARY_HAVE_NUMERIC
#		define MASTER_LIBRARY_HAVE_NUMERIC 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NUMERIC + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NUMERIC
#			define MASTER_LIBRARY_HAVE_NUMERIC 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NUMERIC + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NUMERIC
#				define MASTER_LIBRARY_HAVE_NUMERIC 0
#			else
#				undef MASTER_LIBRARY_HAVE_NUMERIC
#				define MASTER_LIBRARY_HAVE_NUMERIC 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! numeric !# */

#ifdef MASTER_LIBRARY_HAVE_CSTRING
#	define MASTER_LIBRARY_HAVE_CSTRING0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSTRING) == 40001
#		undef MASTER_LIBRARY_HAVE_CSTRING
#		define MASTER_LIBRARY_HAVE_CSTRING 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSTRING + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSTRING
#			define MASTER_LIBRARY_HAVE_CSTRING 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSTRING + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSTRING
#				define MASTER_LIBRARY_HAVE_CSTRING 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSTRING
#				define MASTER_LIBRARY_HAVE_CSTRING 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cstring !# */

#ifdef MASTER_LIBRARY_HAVE_STRING
#	define MASTER_LIBRARY_HAVE_STRING0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STRING) == 40001
#		undef MASTER_LIBRARY_HAVE_STRING
#		define MASTER_LIBRARY_HAVE_STRING 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STRING + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STRING
#			define MASTER_LIBRARY_HAVE_STRING 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STRING + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STRING
#				define MASTER_LIBRARY_HAVE_STRING 0
#			else
#				undef MASTER_LIBRARY_HAVE_STRING
#				define MASTER_LIBRARY_HAVE_STRING 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! string !# */

#ifdef MASTER_LIBRARY_HAVE_STRING_VIEW
#	define MASTER_LIBRARY_HAVE_STRING_VIEW0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STRING_VIEW) == 40001
#		undef MASTER_LIBRARY_HAVE_STRING_VIEW
#		define MASTER_LIBRARY_HAVE_STRING_VIEW 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STRING_VIEW + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STRING_VIEW
#			define MASTER_LIBRARY_HAVE_STRING_VIEW 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STRING_VIEW + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STRING_VIEW
#				define MASTER_LIBRARY_HAVE_STRING_VIEW 0
#			else
#				undef MASTER_LIBRARY_HAVE_STRING_VIEW
#				define MASTER_LIBRARY_HAVE_STRING_VIEW 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! string_view !# */

#ifdef MASTER_LIBRARY_HAVE_CCTYPE
#	define MASTER_LIBRARY_HAVE_CCTYPE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CCTYPE) == 40001
#		undef MASTER_LIBRARY_HAVE_CCTYPE
#		define MASTER_LIBRARY_HAVE_CCTYPE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CCTYPE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CCTYPE
#			define MASTER_LIBRARY_HAVE_CCTYPE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CCTYPE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CCTYPE
#				define MASTER_LIBRARY_HAVE_CCTYPE 0
#			else
#				undef MASTER_LIBRARY_HAVE_CCTYPE
#				define MASTER_LIBRARY_HAVE_CCTYPE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cctype !# */

#ifdef MASTER_LIBRARY_HAVE_CHARCONV
#	define MASTER_LIBRARY_HAVE_CHARCONV0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CHARCONV) == 40001
#		undef MASTER_LIBRARY_HAVE_CHARCONV
#		define MASTER_LIBRARY_HAVE_CHARCONV 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CHARCONV + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CHARCONV
#			define MASTER_LIBRARY_HAVE_CHARCONV 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CHARCONV + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CHARCONV
#				define MASTER_LIBRARY_HAVE_CHARCONV 0
#			else
#				undef MASTER_LIBRARY_HAVE_CHARCONV
#				define MASTER_LIBRARY_HAVE_CHARCONV 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! charconv !# */

#ifdef MASTER_LIBRARY_HAVE_CLOCALE
#	define MASTER_LIBRARY_HAVE_CLOCALE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CLOCALE) == 40001
#		undef MASTER_LIBRARY_HAVE_CLOCALE
#		define MASTER_LIBRARY_HAVE_CLOCALE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CLOCALE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CLOCALE
#			define MASTER_LIBRARY_HAVE_CLOCALE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CLOCALE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CLOCALE
#				define MASTER_LIBRARY_HAVE_CLOCALE 0
#			else
#				undef MASTER_LIBRARY_HAVE_CLOCALE
#				define MASTER_LIBRARY_HAVE_CLOCALE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! clocale !# */

#ifdef MASTER_LIBRARY_HAVE_CODECVT
#	define MASTER_LIBRARY_HAVE_CODECVT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CODECVT) == 40001
#		undef MASTER_LIBRARY_HAVE_CODECVT
#		define MASTER_LIBRARY_HAVE_CODECVT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CODECVT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CODECVT
#			define MASTER_LIBRARY_HAVE_CODECVT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CODECVT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CODECVT
#				define MASTER_LIBRARY_HAVE_CODECVT 0
#			else
#				undef MASTER_LIBRARY_HAVE_CODECVT
#				define MASTER_LIBRARY_HAVE_CODECVT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! codecvt !# */

#ifdef MASTER_LIBRARY_HAVE_CUCHAR
#	define MASTER_LIBRARY_HAVE_CUCHAR0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CUCHAR) == 40001
#		undef MASTER_LIBRARY_HAVE_CUCHAR
#		define MASTER_LIBRARY_HAVE_CUCHAR 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CUCHAR + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CUCHAR
#			define MASTER_LIBRARY_HAVE_CUCHAR 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CUCHAR + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CUCHAR
#				define MASTER_LIBRARY_HAVE_CUCHAR 0
#			else
#				undef MASTER_LIBRARY_HAVE_CUCHAR
#				define MASTER_LIBRARY_HAVE_CUCHAR 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cuchar !# */

#ifdef MASTER_LIBRARY_HAVE_CWCHAR
#	define MASTER_LIBRARY_HAVE_CWCHAR0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CWCHAR) == 40001
#		undef MASTER_LIBRARY_HAVE_CWCHAR
#		define MASTER_LIBRARY_HAVE_CWCHAR 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CWCHAR + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CWCHAR
#			define MASTER_LIBRARY_HAVE_CWCHAR 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CWCHAR + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CWCHAR
#				define MASTER_LIBRARY_HAVE_CWCHAR 0
#			else
#				undef MASTER_LIBRARY_HAVE_CWCHAR
#				define MASTER_LIBRARY_HAVE_CWCHAR 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cwchar !# */

#ifdef MASTER_LIBRARY_HAVE_CWCTYPE
#	define MASTER_LIBRARY_HAVE_CWCTYPE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CWCTYPE) == 40001
#		undef MASTER_LIBRARY_HAVE_CWCTYPE
#		define MASTER_LIBRARY_HAVE_CWCTYPE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CWCTYPE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CWCTYPE
#			define MASTER_LIBRARY_HAVE_CWCTYPE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CWCTYPE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CWCTYPE
#				define MASTER_LIBRARY_HAVE_CWCTYPE 0
#			else
#				undef MASTER_LIBRARY_HAVE_CWCTYPE
#				define MASTER_LIBRARY_HAVE_CWCTYPE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cwctype !# */

#ifdef MASTER_LIBRARY_HAVE_FORMAT
#	define MASTER_LIBRARY_HAVE_FORMAT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FORMAT) == 40001
#		undef MASTER_LIBRARY_HAVE_FORMAT
#		define MASTER_LIBRARY_HAVE_FORMAT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FORMAT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FORMAT
#			define MASTER_LIBRARY_HAVE_FORMAT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FORMAT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FORMAT
#				define MASTER_LIBRARY_HAVE_FORMAT 0
#			else
#				undef MASTER_LIBRARY_HAVE_FORMAT
#				define MASTER_LIBRARY_HAVE_FORMAT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! format !# */

#ifdef MASTER_LIBRARY_HAVE_LOCALE
#	define MASTER_LIBRARY_HAVE_LOCALE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LOCALE) == 40001
#		undef MASTER_LIBRARY_HAVE_LOCALE
#		define MASTER_LIBRARY_HAVE_LOCALE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LOCALE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LOCALE
#			define MASTER_LIBRARY_HAVE_LOCALE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LOCALE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LOCALE
#				define MASTER_LIBRARY_HAVE_LOCALE 0
#			else
#				undef MASTER_LIBRARY_HAVE_LOCALE
#				define MASTER_LIBRARY_HAVE_LOCALE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! locale !# */

#ifdef MASTER_LIBRARY_HAVE_REGEX
#	define MASTER_LIBRARY_HAVE_REGEX0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_REGEX) == 40001
#		undef MASTER_LIBRARY_HAVE_REGEX
#		define MASTER_LIBRARY_HAVE_REGEX 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_REGEX + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_REGEX
#			define MASTER_LIBRARY_HAVE_REGEX 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_REGEX + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_REGEX
#				define MASTER_LIBRARY_HAVE_REGEX 0
#			else
#				undef MASTER_LIBRARY_HAVE_REGEX
#				define MASTER_LIBRARY_HAVE_REGEX 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! regex !# */

#ifdef MASTER_LIBRARY_HAVE_TEXT_ENCODING
#	define MASTER_LIBRARY_HAVE_TEXT_ENCODING0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_TEXT_ENCODING) == 40001
#		undef MASTER_LIBRARY_HAVE_TEXT_ENCODING
#		define MASTER_LIBRARY_HAVE_TEXT_ENCODING 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_TEXT_ENCODING + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_TEXT_ENCODING
#			define MASTER_LIBRARY_HAVE_TEXT_ENCODING 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_TEXT_ENCODING + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_TEXT_ENCODING
#				define MASTER_LIBRARY_HAVE_TEXT_ENCODING 0
#			else
#				undef MASTER_LIBRARY_HAVE_TEXT_ENCODING
#				define MASTER_LIBRARY_HAVE_TEXT_ENCODING 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! text_encoding !# */

#ifdef MASTER_LIBRARY_HAVE_CFENV
#	define MASTER_LIBRARY_HAVE_CFENV0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CFENV) == 40001
#		undef MASTER_LIBRARY_HAVE_CFENV
#		define MASTER_LIBRARY_HAVE_CFENV 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CFENV + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CFENV
#			define MASTER_LIBRARY_HAVE_CFENV 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CFENV + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CFENV
#				define MASTER_LIBRARY_HAVE_CFENV 0
#			else
#				undef MASTER_LIBRARY_HAVE_CFENV
#				define MASTER_LIBRARY_HAVE_CFENV 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cfenv !# */

#ifdef MASTER_LIBRARY_HAVE_CMATH
#	define MASTER_LIBRARY_HAVE_CMATH0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CMATH) == 40001
#		undef MASTER_LIBRARY_HAVE_CMATH
#		define MASTER_LIBRARY_HAVE_CMATH 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CMATH + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CMATH
#			define MASTER_LIBRARY_HAVE_CMATH 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CMATH + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CMATH
#				define MASTER_LIBRARY_HAVE_CMATH 0
#			else
#				undef MASTER_LIBRARY_HAVE_CMATH
#				define MASTER_LIBRARY_HAVE_CMATH 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cmath !# */

#ifdef MASTER_LIBRARY_HAVE_COMPLEX
#	define MASTER_LIBRARY_HAVE_COMPLEX0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_COMPLEX) == 40001
#		undef MASTER_LIBRARY_HAVE_COMPLEX
#		define MASTER_LIBRARY_HAVE_COMPLEX 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_COMPLEX + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_COMPLEX
#			define MASTER_LIBRARY_HAVE_COMPLEX 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_COMPLEX + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_COMPLEX
#				define MASTER_LIBRARY_HAVE_COMPLEX 0
#			else
#				undef MASTER_LIBRARY_HAVE_COMPLEX
#				define MASTER_LIBRARY_HAVE_COMPLEX 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! complex !# */

#ifdef MASTER_LIBRARY_HAVE_LINALG
#	define MASTER_LIBRARY_HAVE_LINALG0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LINALG) == 40001
#		undef MASTER_LIBRARY_HAVE_LINALG
#		define MASTER_LIBRARY_HAVE_LINALG 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LINALG + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LINALG
#			define MASTER_LIBRARY_HAVE_LINALG 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LINALG + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LINALG
#				define MASTER_LIBRARY_HAVE_LINALG 0
#			else
#				undef MASTER_LIBRARY_HAVE_LINALG
#				define MASTER_LIBRARY_HAVE_LINALG 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! linalg !# */

#ifdef MASTER_LIBRARY_HAVE_NUMBERS
#	define MASTER_LIBRARY_HAVE_NUMBERS0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_NUMBERS) == 40001
#		undef MASTER_LIBRARY_HAVE_NUMBERS
#		define MASTER_LIBRARY_HAVE_NUMBERS 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_NUMBERS + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_NUMBERS
#			define MASTER_LIBRARY_HAVE_NUMBERS 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_NUMBERS + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_NUMBERS
#				define MASTER_LIBRARY_HAVE_NUMBERS 0
#			else
#				undef MASTER_LIBRARY_HAVE_NUMBERS
#				define MASTER_LIBRARY_HAVE_NUMBERS 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! numbers !# */

#ifdef MASTER_LIBRARY_HAVE_RANDOM
#	define MASTER_LIBRARY_HAVE_RANDOM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_RANDOM) == 40001
#		undef MASTER_LIBRARY_HAVE_RANDOM
#		define MASTER_LIBRARY_HAVE_RANDOM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_RANDOM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_RANDOM
#			define MASTER_LIBRARY_HAVE_RANDOM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_RANDOM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_RANDOM
#				define MASTER_LIBRARY_HAVE_RANDOM 0
#			else
#				undef MASTER_LIBRARY_HAVE_RANDOM
#				define MASTER_LIBRARY_HAVE_RANDOM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! random !# */

#ifdef MASTER_LIBRARY_HAVE_SIMD
#	define MASTER_LIBRARY_HAVE_SIMD0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SIMD) == 40001
#		undef MASTER_LIBRARY_HAVE_SIMD
#		define MASTER_LIBRARY_HAVE_SIMD 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SIMD + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SIMD
#			define MASTER_LIBRARY_HAVE_SIMD 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SIMD + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SIMD
#				define MASTER_LIBRARY_HAVE_SIMD 0
#			else
#				undef MASTER_LIBRARY_HAVE_SIMD
#				define MASTER_LIBRARY_HAVE_SIMD 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! simd !# */

#ifdef MASTER_LIBRARY_HAVE_VALARRAY
#	define MASTER_LIBRARY_HAVE_VALARRAY0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_VALARRAY) == 40001
#		undef MASTER_LIBRARY_HAVE_VALARRAY
#		define MASTER_LIBRARY_HAVE_VALARRAY 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_VALARRAY + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_VALARRAY
#			define MASTER_LIBRARY_HAVE_VALARRAY 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_VALARRAY + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_VALARRAY
#				define MASTER_LIBRARY_HAVE_VALARRAY 0
#			else
#				undef MASTER_LIBRARY_HAVE_VALARRAY
#				define MASTER_LIBRARY_HAVE_VALARRAY 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! valarray !# */

#ifdef MASTER_LIBRARY_HAVE_CHRONO
#	define MASTER_LIBRARY_HAVE_CHRONO0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CHRONO) == 40001
#		undef MASTER_LIBRARY_HAVE_CHRONO
#		define MASTER_LIBRARY_HAVE_CHRONO 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CHRONO + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CHRONO
#			define MASTER_LIBRARY_HAVE_CHRONO 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CHRONO + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CHRONO
#				define MASTER_LIBRARY_HAVE_CHRONO 0
#			else
#				undef MASTER_LIBRARY_HAVE_CHRONO
#				define MASTER_LIBRARY_HAVE_CHRONO 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! chrono !# */

#ifdef MASTER_LIBRARY_HAVE_CTIME
#	define MASTER_LIBRARY_HAVE_CTIME0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CTIME) == 40001
#		undef MASTER_LIBRARY_HAVE_CTIME
#		define MASTER_LIBRARY_HAVE_CTIME 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CTIME + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CTIME
#			define MASTER_LIBRARY_HAVE_CTIME 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CTIME + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CTIME
#				define MASTER_LIBRARY_HAVE_CTIME 0
#			else
#				undef MASTER_LIBRARY_HAVE_CTIME
#				define MASTER_LIBRARY_HAVE_CTIME 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ctime !# */

#ifdef MASTER_LIBRARY_HAVE_CINTTYPES
#	define MASTER_LIBRARY_HAVE_CINTTYPES0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CINTTYPES) == 40001
#		undef MASTER_LIBRARY_HAVE_CINTTYPES
#		define MASTER_LIBRARY_HAVE_CINTTYPES 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CINTTYPES + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CINTTYPES
#			define MASTER_LIBRARY_HAVE_CINTTYPES 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CINTTYPES + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CINTTYPES
#				define MASTER_LIBRARY_HAVE_CINTTYPES 0
#			else
#				undef MASTER_LIBRARY_HAVE_CINTTYPES
#				define MASTER_LIBRARY_HAVE_CINTTYPES 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cinttypes !# */

#ifdef MASTER_LIBRARY_HAVE_CSTDIO
#	define MASTER_LIBRARY_HAVE_CSTDIO0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSTDIO) == 40001
#		undef MASTER_LIBRARY_HAVE_CSTDIO
#		define MASTER_LIBRARY_HAVE_CSTDIO 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSTDIO + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSTDIO
#			define MASTER_LIBRARY_HAVE_CSTDIO 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSTDIO + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSTDIO
#				define MASTER_LIBRARY_HAVE_CSTDIO 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSTDIO
#				define MASTER_LIBRARY_HAVE_CSTDIO 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cstdio !# */

#ifdef MASTER_LIBRARY_HAVE_FILESYSTEM
#	define MASTER_LIBRARY_HAVE_FILESYSTEM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FILESYSTEM) == 40001
#		undef MASTER_LIBRARY_HAVE_FILESYSTEM
#		define MASTER_LIBRARY_HAVE_FILESYSTEM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FILESYSTEM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FILESYSTEM
#			define MASTER_LIBRARY_HAVE_FILESYSTEM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FILESYSTEM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FILESYSTEM
#				define MASTER_LIBRARY_HAVE_FILESYSTEM 0
#			else
#				undef MASTER_LIBRARY_HAVE_FILESYSTEM
#				define MASTER_LIBRARY_HAVE_FILESYSTEM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! filesystem !# */

#ifdef MASTER_LIBRARY_HAVE_FSTREAM
#	define MASTER_LIBRARY_HAVE_FSTREAM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FSTREAM) == 40001
#		undef MASTER_LIBRARY_HAVE_FSTREAM
#		define MASTER_LIBRARY_HAVE_FSTREAM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FSTREAM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FSTREAM
#			define MASTER_LIBRARY_HAVE_FSTREAM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FSTREAM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FSTREAM
#				define MASTER_LIBRARY_HAVE_FSTREAM 0
#			else
#				undef MASTER_LIBRARY_HAVE_FSTREAM
#				define MASTER_LIBRARY_HAVE_FSTREAM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! fstream !# */

#ifdef MASTER_LIBRARY_HAVE_IOMANIP
#	define MASTER_LIBRARY_HAVE_IOMANIP0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_IOMANIP) == 40001
#		undef MASTER_LIBRARY_HAVE_IOMANIP
#		define MASTER_LIBRARY_HAVE_IOMANIP 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_IOMANIP + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_IOMANIP
#			define MASTER_LIBRARY_HAVE_IOMANIP 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_IOMANIP + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_IOMANIP
#				define MASTER_LIBRARY_HAVE_IOMANIP 0
#			else
#				undef MASTER_LIBRARY_HAVE_IOMANIP
#				define MASTER_LIBRARY_HAVE_IOMANIP 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! iomanip !# */

#ifdef MASTER_LIBRARY_HAVE_IOS
#	define MASTER_LIBRARY_HAVE_IOS0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_IOS) == 40001
#		undef MASTER_LIBRARY_HAVE_IOS
#		define MASTER_LIBRARY_HAVE_IOS 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_IOS + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_IOS
#			define MASTER_LIBRARY_HAVE_IOS 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_IOS + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_IOS
#				define MASTER_LIBRARY_HAVE_IOS 0
#			else
#				undef MASTER_LIBRARY_HAVE_IOS
#				define MASTER_LIBRARY_HAVE_IOS 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ios !# */

#ifdef MASTER_LIBRARY_HAVE_IOSFWD
#	define MASTER_LIBRARY_HAVE_IOSFWD0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_IOSFWD) == 40001
#		undef MASTER_LIBRARY_HAVE_IOSFWD
#		define MASTER_LIBRARY_HAVE_IOSFWD 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_IOSFWD + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_IOSFWD
#			define MASTER_LIBRARY_HAVE_IOSFWD 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_IOSFWD + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_IOSFWD
#				define MASTER_LIBRARY_HAVE_IOSFWD 0
#			else
#				undef MASTER_LIBRARY_HAVE_IOSFWD
#				define MASTER_LIBRARY_HAVE_IOSFWD 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! iosfwd !# */

#ifdef MASTER_LIBRARY_HAVE_IOSTREAM
#	define MASTER_LIBRARY_HAVE_IOSTREAM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_IOSTREAM) == 40001
#		undef MASTER_LIBRARY_HAVE_IOSTREAM
#		define MASTER_LIBRARY_HAVE_IOSTREAM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_IOSTREAM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_IOSTREAM
#			define MASTER_LIBRARY_HAVE_IOSTREAM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_IOSTREAM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_IOSTREAM
#				define MASTER_LIBRARY_HAVE_IOSTREAM 0
#			else
#				undef MASTER_LIBRARY_HAVE_IOSTREAM
#				define MASTER_LIBRARY_HAVE_IOSTREAM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! iostream !# */

#ifdef MASTER_LIBRARY_HAVE_ISTREAM
#	define MASTER_LIBRARY_HAVE_ISTREAM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ISTREAM) == 40001
#		undef MASTER_LIBRARY_HAVE_ISTREAM
#		define MASTER_LIBRARY_HAVE_ISTREAM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ISTREAM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ISTREAM
#			define MASTER_LIBRARY_HAVE_ISTREAM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ISTREAM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ISTREAM
#				define MASTER_LIBRARY_HAVE_ISTREAM 0
#			else
#				undef MASTER_LIBRARY_HAVE_ISTREAM
#				define MASTER_LIBRARY_HAVE_ISTREAM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! istream !# */

#ifdef MASTER_LIBRARY_HAVE_OSTREAM
#	define MASTER_LIBRARY_HAVE_OSTREAM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_OSTREAM) == 40001
#		undef MASTER_LIBRARY_HAVE_OSTREAM
#		define MASTER_LIBRARY_HAVE_OSTREAM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_OSTREAM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_OSTREAM
#			define MASTER_LIBRARY_HAVE_OSTREAM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_OSTREAM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_OSTREAM
#				define MASTER_LIBRARY_HAVE_OSTREAM 0
#			else
#				undef MASTER_LIBRARY_HAVE_OSTREAM
#				define MASTER_LIBRARY_HAVE_OSTREAM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ostream !# */

#ifdef MASTER_LIBRARY_HAVE_PRINT
#	define MASTER_LIBRARY_HAVE_PRINT0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_PRINT) == 40001
#		undef MASTER_LIBRARY_HAVE_PRINT
#		define MASTER_LIBRARY_HAVE_PRINT 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_PRINT + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_PRINT
#			define MASTER_LIBRARY_HAVE_PRINT 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_PRINT + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_PRINT
#				define MASTER_LIBRARY_HAVE_PRINT 0
#			else
#				undef MASTER_LIBRARY_HAVE_PRINT
#				define MASTER_LIBRARY_HAVE_PRINT 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! print !# */

#ifdef MASTER_LIBRARY_HAVE_SPANSTREAM
#	define MASTER_LIBRARY_HAVE_SPANSTREAM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SPANSTREAM) == 40001
#		undef MASTER_LIBRARY_HAVE_SPANSTREAM
#		define MASTER_LIBRARY_HAVE_SPANSTREAM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SPANSTREAM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SPANSTREAM
#			define MASTER_LIBRARY_HAVE_SPANSTREAM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SPANSTREAM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SPANSTREAM
#				define MASTER_LIBRARY_HAVE_SPANSTREAM 0
#			else
#				undef MASTER_LIBRARY_HAVE_SPANSTREAM
#				define MASTER_LIBRARY_HAVE_SPANSTREAM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! spanstream !# */

#ifdef MASTER_LIBRARY_HAVE_SSTREAM
#	define MASTER_LIBRARY_HAVE_SSTREAM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SSTREAM) == 40001
#		undef MASTER_LIBRARY_HAVE_SSTREAM
#		define MASTER_LIBRARY_HAVE_SSTREAM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SSTREAM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SSTREAM
#			define MASTER_LIBRARY_HAVE_SSTREAM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SSTREAM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SSTREAM
#				define MASTER_LIBRARY_HAVE_SSTREAM 0
#			else
#				undef MASTER_LIBRARY_HAVE_SSTREAM
#				define MASTER_LIBRARY_HAVE_SSTREAM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! sstream !# */

#ifdef MASTER_LIBRARY_HAVE_STREAMBUF
#	define MASTER_LIBRARY_HAVE_STREAMBUF0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STREAMBUF) == 40001
#		undef MASTER_LIBRARY_HAVE_STREAMBUF
#		define MASTER_LIBRARY_HAVE_STREAMBUF 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STREAMBUF + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STREAMBUF
#			define MASTER_LIBRARY_HAVE_STREAMBUF 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STREAMBUF + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STREAMBUF
#				define MASTER_LIBRARY_HAVE_STREAMBUF 0
#			else
#				undef MASTER_LIBRARY_HAVE_STREAMBUF
#				define MASTER_LIBRARY_HAVE_STREAMBUF 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! streambuf !# */

#ifdef MASTER_LIBRARY_HAVE_STRSTREAM
#	define MASTER_LIBRARY_HAVE_STRSTREAM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STRSTREAM) == 40001
#		undef MASTER_LIBRARY_HAVE_STRSTREAM
#		define MASTER_LIBRARY_HAVE_STRSTREAM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STRSTREAM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STRSTREAM
#			define MASTER_LIBRARY_HAVE_STRSTREAM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STRSTREAM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STRSTREAM
#				define MASTER_LIBRARY_HAVE_STRSTREAM 0
#			else
#				undef MASTER_LIBRARY_HAVE_STRSTREAM
#				define MASTER_LIBRARY_HAVE_STRSTREAM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! strstream !# */

#ifdef MASTER_LIBRARY_HAVE_SYNCSTREAM
#	define MASTER_LIBRARY_HAVE_SYNCSTREAM0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SYNCSTREAM) == 40001
#		undef MASTER_LIBRARY_HAVE_SYNCSTREAM
#		define MASTER_LIBRARY_HAVE_SYNCSTREAM 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SYNCSTREAM + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SYNCSTREAM
#			define MASTER_LIBRARY_HAVE_SYNCSTREAM 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SYNCSTREAM + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SYNCSTREAM
#				define MASTER_LIBRARY_HAVE_SYNCSTREAM 0
#			else
#				undef MASTER_LIBRARY_HAVE_SYNCSTREAM
#				define MASTER_LIBRARY_HAVE_SYNCSTREAM 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! syncstream !# */

#ifdef MASTER_LIBRARY_HAVE_ATOMIC
#	define MASTER_LIBRARY_HAVE_ATOMIC0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_ATOMIC) == 40001
#		undef MASTER_LIBRARY_HAVE_ATOMIC
#		define MASTER_LIBRARY_HAVE_ATOMIC 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_ATOMIC + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_ATOMIC
#			define MASTER_LIBRARY_HAVE_ATOMIC 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_ATOMIC + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_ATOMIC
#				define MASTER_LIBRARY_HAVE_ATOMIC 0
#			else
#				undef MASTER_LIBRARY_HAVE_ATOMIC
#				define MASTER_LIBRARY_HAVE_ATOMIC 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! atomic !# */

#ifdef MASTER_LIBRARY_HAVE_BARRIER
#	define MASTER_LIBRARY_HAVE_BARRIER0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_BARRIER) == 40001
#		undef MASTER_LIBRARY_HAVE_BARRIER
#		define MASTER_LIBRARY_HAVE_BARRIER 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_BARRIER + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_BARRIER
#			define MASTER_LIBRARY_HAVE_BARRIER 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_BARRIER + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_BARRIER
#				define MASTER_LIBRARY_HAVE_BARRIER 0
#			else
#				undef MASTER_LIBRARY_HAVE_BARRIER
#				define MASTER_LIBRARY_HAVE_BARRIER 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! barrier !# */

#ifdef MASTER_LIBRARY_HAVE_CONDITION_VARIABLE
#	define MASTER_LIBRARY_HAVE_CONDITION_VARIABLE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CONDITION_VARIABLE) == 40001
#		undef MASTER_LIBRARY_HAVE_CONDITION_VARIABLE
#		define MASTER_LIBRARY_HAVE_CONDITION_VARIABLE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CONDITION_VARIABLE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CONDITION_VARIABLE
#			define MASTER_LIBRARY_HAVE_CONDITION_VARIABLE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CONDITION_VARIABLE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CONDITION_VARIABLE
#				define MASTER_LIBRARY_HAVE_CONDITION_VARIABLE 0
#			else
#				undef MASTER_LIBRARY_HAVE_CONDITION_VARIABLE
#				define MASTER_LIBRARY_HAVE_CONDITION_VARIABLE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! condition_variable !# */

#ifdef MASTER_LIBRARY_HAVE_FUTURE
#	define MASTER_LIBRARY_HAVE_FUTURE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_FUTURE) == 40001
#		undef MASTER_LIBRARY_HAVE_FUTURE
#		define MASTER_LIBRARY_HAVE_FUTURE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_FUTURE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_FUTURE
#			define MASTER_LIBRARY_HAVE_FUTURE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_FUTURE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_FUTURE
#				define MASTER_LIBRARY_HAVE_FUTURE 0
#			else
#				undef MASTER_LIBRARY_HAVE_FUTURE
#				define MASTER_LIBRARY_HAVE_FUTURE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! future !# */

#ifdef MASTER_LIBRARY_HAVE_HAZARD_POINTER
#	define MASTER_LIBRARY_HAVE_HAZARD_POINTER0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_HAZARD_POINTER) == 40001
#		undef MASTER_LIBRARY_HAVE_HAZARD_POINTER
#		define MASTER_LIBRARY_HAVE_HAZARD_POINTER 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_HAZARD_POINTER + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_HAZARD_POINTER
#			define MASTER_LIBRARY_HAVE_HAZARD_POINTER 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_HAZARD_POINTER + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_HAZARD_POINTER
#				define MASTER_LIBRARY_HAVE_HAZARD_POINTER 0
#			else
#				undef MASTER_LIBRARY_HAVE_HAZARD_POINTER
#				define MASTER_LIBRARY_HAVE_HAZARD_POINTER 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! hazard_pointer !# */

#ifdef MASTER_LIBRARY_HAVE_LATCH
#	define MASTER_LIBRARY_HAVE_LATCH0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_LATCH) == 40001
#		undef MASTER_LIBRARY_HAVE_LATCH
#		define MASTER_LIBRARY_HAVE_LATCH 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_LATCH + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_LATCH
#			define MASTER_LIBRARY_HAVE_LATCH 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_LATCH + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_LATCH
#				define MASTER_LIBRARY_HAVE_LATCH 0
#			else
#				undef MASTER_LIBRARY_HAVE_LATCH
#				define MASTER_LIBRARY_HAVE_LATCH 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! latch !# */

#ifdef MASTER_LIBRARY_HAVE_MUTEX
#	define MASTER_LIBRARY_HAVE_MUTEX0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_MUTEX) == 40001
#		undef MASTER_LIBRARY_HAVE_MUTEX
#		define MASTER_LIBRARY_HAVE_MUTEX 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_MUTEX + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_MUTEX
#			define MASTER_LIBRARY_HAVE_MUTEX 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_MUTEX + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_MUTEX
#				define MASTER_LIBRARY_HAVE_MUTEX 0
#			else
#				undef MASTER_LIBRARY_HAVE_MUTEX
#				define MASTER_LIBRARY_HAVE_MUTEX 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! mutex !# */

#ifdef MASTER_LIBRARY_HAVE_RCU
#	define MASTER_LIBRARY_HAVE_RCU0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_RCU) == 40001
#		undef MASTER_LIBRARY_HAVE_RCU
#		define MASTER_LIBRARY_HAVE_RCU 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_RCU + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_RCU
#			define MASTER_LIBRARY_HAVE_RCU 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_RCU + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_RCU
#				define MASTER_LIBRARY_HAVE_RCU 0
#			else
#				undef MASTER_LIBRARY_HAVE_RCU
#				define MASTER_LIBRARY_HAVE_RCU 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! rcu !# */

#ifdef MASTER_LIBRARY_HAVE_SEMAPHORE
#	define MASTER_LIBRARY_HAVE_SEMAPHORE0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SEMAPHORE) == 40001
#		undef MASTER_LIBRARY_HAVE_SEMAPHORE
#		define MASTER_LIBRARY_HAVE_SEMAPHORE 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SEMAPHORE + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SEMAPHORE
#			define MASTER_LIBRARY_HAVE_SEMAPHORE 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SEMAPHORE + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SEMAPHORE
#				define MASTER_LIBRARY_HAVE_SEMAPHORE 0
#			else
#				undef MASTER_LIBRARY_HAVE_SEMAPHORE
#				define MASTER_LIBRARY_HAVE_SEMAPHORE 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! semaphore !# */

#ifdef MASTER_LIBRARY_HAVE_SHARED_MUTEX
#	define MASTER_LIBRARY_HAVE_SHARED_MUTEX0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_SHARED_MUTEX) == 40001
#		undef MASTER_LIBRARY_HAVE_SHARED_MUTEX
#		define MASTER_LIBRARY_HAVE_SHARED_MUTEX 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_SHARED_MUTEX + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_SHARED_MUTEX
#			define MASTER_LIBRARY_HAVE_SHARED_MUTEX 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_SHARED_MUTEX + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_SHARED_MUTEX
#				define MASTER_LIBRARY_HAVE_SHARED_MUTEX 0
#			else
#				undef MASTER_LIBRARY_HAVE_SHARED_MUTEX
#				define MASTER_LIBRARY_HAVE_SHARED_MUTEX 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! shared_mutex !# */

#ifdef MASTER_LIBRARY_HAVE_STOP_TOKEN
#	define MASTER_LIBRARY_HAVE_STOP_TOKEN0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_STOP_TOKEN) == 40001
#		undef MASTER_LIBRARY_HAVE_STOP_TOKEN
#		define MASTER_LIBRARY_HAVE_STOP_TOKEN 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_STOP_TOKEN + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_STOP_TOKEN
#			define MASTER_LIBRARY_HAVE_STOP_TOKEN 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_STOP_TOKEN + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_STOP_TOKEN
#				define MASTER_LIBRARY_HAVE_STOP_TOKEN 0
#			else
#				undef MASTER_LIBRARY_HAVE_STOP_TOKEN
#				define MASTER_LIBRARY_HAVE_STOP_TOKEN 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! stop_token !# */

#ifdef MASTER_LIBRARY_HAVE_THREAD
#	define MASTER_LIBRARY_HAVE_THREAD0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_THREAD) == 40001
#		undef MASTER_LIBRARY_HAVE_THREAD
#		define MASTER_LIBRARY_HAVE_THREAD 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_THREAD + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_THREAD
#			define MASTER_LIBRARY_HAVE_THREAD 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_THREAD + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_THREAD
#				define MASTER_LIBRARY_HAVE_THREAD 0
#			else
#				undef MASTER_LIBRARY_HAVE_THREAD
#				define MASTER_LIBRARY_HAVE_THREAD 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! thread !# */

#ifdef MASTER_LIBRARY_HAVE_CCOMPLEX
#	define MASTER_LIBRARY_HAVE_CCOMPLEX0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CCOMPLEX) == 40001
#		undef MASTER_LIBRARY_HAVE_CCOMPLEX
#		define MASTER_LIBRARY_HAVE_CCOMPLEX 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CCOMPLEX + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CCOMPLEX
#			define MASTER_LIBRARY_HAVE_CCOMPLEX 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CCOMPLEX + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CCOMPLEX
#				define MASTER_LIBRARY_HAVE_CCOMPLEX 0
#			else
#				undef MASTER_LIBRARY_HAVE_CCOMPLEX
#				define MASTER_LIBRARY_HAVE_CCOMPLEX 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ccomplex !# */

#ifdef MASTER_LIBRARY_HAVE_CTGMATH
#	define MASTER_LIBRARY_HAVE_CTGMATH0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CTGMATH) == 40001
#		undef MASTER_LIBRARY_HAVE_CTGMATH
#		define MASTER_LIBRARY_HAVE_CTGMATH 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CTGMATH + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CTGMATH
#			define MASTER_LIBRARY_HAVE_CTGMATH 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CTGMATH + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CTGMATH
#				define MASTER_LIBRARY_HAVE_CTGMATH 0
#			else
#				undef MASTER_LIBRARY_HAVE_CTGMATH
#				define MASTER_LIBRARY_HAVE_CTGMATH 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ctgmath !# */

#ifdef MASTER_LIBRARY_HAVE_CISO646
#	define MASTER_LIBRARY_HAVE_CISO6460L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CISO646) == 40001
#		undef MASTER_LIBRARY_HAVE_CISO646
#		define MASTER_LIBRARY_HAVE_CISO646 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CISO646 + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CISO646
#			define MASTER_LIBRARY_HAVE_CISO646 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CISO646 + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CISO646
#				define MASTER_LIBRARY_HAVE_CISO646 0
#			else
#				undef MASTER_LIBRARY_HAVE_CISO646
#				define MASTER_LIBRARY_HAVE_CISO646 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! ciso646 !# */

#ifdef MASTER_LIBRARY_HAVE_CSTDALIGN
#	define MASTER_LIBRARY_HAVE_CSTDALIGN0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSTDALIGN) == 40001
#		undef MASTER_LIBRARY_HAVE_CSTDALIGN
#		define MASTER_LIBRARY_HAVE_CSTDALIGN 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSTDALIGN + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSTDALIGN
#			define MASTER_LIBRARY_HAVE_CSTDALIGN 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSTDALIGN + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSTDALIGN
#				define MASTER_LIBRARY_HAVE_CSTDALIGN 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSTDALIGN
#				define MASTER_LIBRARY_HAVE_CSTDALIGN 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cstdalign !# */

#ifdef MASTER_LIBRARY_HAVE_CSTDBOOL
#	define MASTER_LIBRARY_HAVE_CSTDBOOL0L 40001
#	if MASTER_L_POSTFIX_S(MASTER_LIBRARY_HAVE_CSTDBOOL) == 40001
#		undef MASTER_LIBRARY_HAVE_CSTDBOOL
#		define MASTER_LIBRARY_HAVE_CSTDBOOL 1
#	else
#		if (100 * MASTER_LIBRARY_HAVE_CSTDBOOL + 2 == 200)
#			undef MASTER_LIBRARY_HAVE_CSTDBOOL
#			define MASTER_LIBRARY_HAVE_CSTDBOOL 1
#		else
#			if (100 * MASTER_LIBRARY_HAVE_CSTDBOOL + 2 <= 2)
#				undef MASTER_LIBRARY_HAVE_CSTDBOOL
#				define MASTER_LIBRARY_HAVE_CSTDBOOL 0
#			else
#				undef MASTER_LIBRARY_HAVE_CSTDBOOL
#				define MASTER_LIBRARY_HAVE_CSTDBOOL 1
#			endif /* #! To 0/1 !# */
#		endif /* #! Defined / Undefined !# */
#	endif /* #! Brackets Check !# */
#endif /* #! cstdbool !# */

MASTER_END_DECLARATIONS

/* #! No Dependencies !# */

#ifdef MASTER_NO_LIBC_DEPENDENCIES
#	define MASTER_LIBRARY_HAVE_ASSERT_H 0
#	define MASTER_LIBRARY_HAVE_COMPLEX_H 0
#	define MASTER_LIBRARY_HAVE_CTYPE_H 0
#	define MASTER_LIBRARY_HAVE_ERRNO_H 0
#	define MASTER_LIBRARY_HAVE_FENV_H 0
#	define MASTER_LIBRARY_HAVE_FLOAT_H 0
#	define MASTER_LIBRARY_HAVE_INTTYPES_H 0
#	define MASTER_LIBRARY_HAVE_ISO646_H 0
#	define MASTER_LIBRARY_HAVE_LIMITS_H 0
#	define MASTER_LIBRARY_HAVE_LOCALE_H 0
#	define MASTER_LIBRARY_HAVE_MATH_H 0
#	define MASTER_LIBRARY_HAVE_SETJMP_H 0
#	define MASTER_LIBRARY_HAVE_SIGNAL_H 0
#	define MASTER_LIBRARY_HAVE_STDARG_H 0
#	define MASTER_LIBRARY_HAVE_STDATOMIC_H 0
#	define MASTER_LIBRARY_HAVE_STDBIT_H 0
#	define MASTER_LIBRARY_HAVE_STDCKDINT_H 0
#	define MASTER_LIBRARY_HAVE_STDDEF_H 0
#	define MASTER_LIBRARY_HAVE_STDINT_H 0
#	define MASTER_LIBRARY_HAVE_STDIO_H 0
#	define MASTER_LIBRARY_HAVE_STDLIB_H 0
#	define MASTER_LIBRARY_HAVE_STDMCHAR_H 0
#	define MASTER_LIBRARY_HAVE_STRING_H 0
#	define MASTER_LIBRARY_HAVE_TGMATH_H 0
#	define MASTER_LIBRARY_HAVE_THREADS_H 0
#	define MASTER_LIBRARY_HAVE_TIME_H 0
#	define MASTER_LIBRARY_HAVE_UCHAR_H 0
#	define MASTER_LIBRARY_HAVE_WCHAR_H 0
#	define MASTER_LIBRARY_HAVE_WCTYPE_H 0
#endif /* #! No libc Dependencies !# */

#ifdef MASTER_NO_POSIX_DEPENDENCIES
#	define MASTER_LIBRARY_HAVE_AIO_H 0
#	define MASTER_LIBRARY_HAVE_ARPA_INET_H 0
#	define MASTER_LIBRARY_HAVE_CPIO_H 0
#	define MASTER_LIBRARY_HAVE_DEVCTL_H 0
#	define MASTER_LIBRARY_HAVE_DIRENT_H 0
#	define MASTER_LIBRARY_HAVE_DLFCN_H 0
#	define MASTER_LIBRARY_HAVE_ENDIAN_H 0
#	define MASTER_LIBRARY_HAVE_FCNTL_H 0
#	define MASTER_LIBRARY_HAVE_FMTMSG_H 0
#	define MASTER_LIBRARY_HAVE_FNMATCH_H 0
#	define MASTER_LIBRARY_HAVE_FTW_H 0
#	define MASTER_LIBRARY_HAVE_GLOB_H 0
#	define MASTER_LIBRARY_HAVE_GRP_H 0
#	define MASTER_LIBRARY_HAVE_ICONV_H 0
#	define MASTER_LIBRARY_HAVE_LANGINFO_H 0
#	define MASTER_LIBRARY_HAVE_LIBGEN_H 0
#	define MASTER_LIBRARY_HAVE_LIBINTL_H 0
#	define MASTER_LIBRARY_HAVE_MONETARY_H 0
#	define MASTER_LIBRARY_HAVE_MQUEUE_H 0
#	define MASTER_LIBRARY_HAVE_NDBM_H 0
#	define MASTER_LIBRARY_HAVE_NET_IF_H 0
#	define MASTER_LIBRARY_HAVE_NETDB_H 0
#	define MASTER_LIBRARY_HAVE_NETINET_IN_H 0
#	define MASTER_LIBRARY_HAVE_NETINET_TCP_H 0
#	define MASTER_LIBRARY_HAVE_NL_TYPES_H 0
#	define MASTER_LIBRARY_HAVE_POLL_H 0
#	define MASTER_LIBRARY_HAVE_PTHREAD_H 0
#	define MASTER_LIBRARY_HAVE_PWD_H 0
#	define MASTER_LIBRARY_HAVE_REGEX_H 0
#	define MASTER_LIBRARY_HAVE_SCHED_H 0
#	define MASTER_LIBRARY_HAVE_SEARCH_H 0
#	define MASTER_LIBRARY_HAVE_SEMAPHORE_H 0
#	define MASTER_LIBRARY_HAVE_SPAWN_H 0
#	define MASTER_LIBRARY_HAVE_STRINGS_H 0
#	define MASTER_LIBRARY_HAVE_STROPTS_H 0
#	define MASTER_LIBRARY_HAVE_SYS_IPC_H 0
#	define MASTER_LIBRARY_HAVE_SYS_MMAN_H 0
#	define MASTER_LIBRARY_HAVE_SYS_MSG_H 0
#	define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H 0
#	define MASTER_LIBRARY_HAVE_SYS_SELECT_H 0
#	define MASTER_LIBRARY_HAVE_SYS_SEM_H 0
#	define MASTER_LIBRARY_HAVE_SYS_SHM_H 0
#	define MASTER_LIBRARY_HAVE_SYS_SOCKET_H 0
#	define MASTER_LIBRARY_HAVE_SYS_STAT_H 0
#	define MASTER_LIBRARY_HAVE_SYS_STATVFS_H 0
#	define MASTER_LIBRARY_HAVE_SYS_TIME_H 0
#	define MASTER_LIBRARY_HAVE_SYS_TIMES_H 0
#	define MASTER_LIBRARY_HAVE_SYS_TYPES_H 0
#	define MASTER_LIBRARY_HAVE_SYS_UIO_H 0
#	define MASTER_LIBRARY_HAVE_SYS_UN_H 0
#	define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H 0
#	define MASTER_LIBRARY_HAVE_SYS_WAIT_H 0
#	define MASTER_LIBRARY_HAVE_SYSLOG_H 0
#	define MASTER_LIBRARY_HAVE_TAR_H 0
#	define MASTER_LIBRARY_HAVE_TERMIOS_H 0
#	define MASTER_LIBRARY_HAVE_TRACE_H 0
#	define MASTER_LIBRARY_HAVE_UCONTEXT_H 0
#	define MASTER_LIBRARY_HAVE_ULIMIT_H 0
#	define MASTER_LIBRARY_HAVE_UTIME_H 0
#	define MASTER_LIBRARY_HAVE_UTMPX_H 0
#	define MASTER_LIBRARY_HAVE_WORDEXP_H 0
#else
#	ifndef MASTER_LIBRARY_HAVE_UNISTD_H
#		if MASTER_COMPILER_HAS_INCLUDE("unistd.h")
#			define MASTER_LIBRARY_HAVE_UNISTD_H 1
#		else
#			define MASTER_LIBRARY_HAVE_UNISTD_H 0
#		endif /* #! Has include !# */
#	endif /* #! unistd.h !# */
#	if MASTER_LIBRARY_HAVE_UNISTD_H == 1
#		include <unistd.h>
#		if !defined(MASTER_PREFER_POSIX_SUPPORTED) && defined(_POSIX_VERSION)
#			define MASTER_PREFER_POSIX_SUPPORTED 1
#		else
#			define MASTER_PREFER_POSIX_SUPPORTED 0
#		endif /* #! POSIX Support !# */
#	endif /* #! unistd.h !# */
#endif /* #! No POSIX Dependencies !# */

#ifdef MASTER_NO_WINDOWS_DEPENDENCIES
#	define MASTER_LIBRARY_HAVE_WINDOWS_H 0
#	define MASTER_LIBRARY_HAVE_CONIO_H 0
#	define MASTER_LIBRARY_HAVE_BASETSD_H 0
#	define MASTER_LIBRARY_HAVE_GUIDDEF_H 0
#	define MASTER_LIBRARY_HAVE_IMM_H 0
#	define MASTER_LIBRARY_HAVE_WINBASE_H 0
#	define MASTER_LIBRARY_HAVE_WINCON_H 0
#	define MASTER_LIBRARY_HAVE_WINDEF_H 0
#	define MASTER_LIBRARY_HAVE_WINERROR_H 0
#	define MASTER_LIBRARY_HAVE_WINGDI_H 0
#	define MASTER_LIBRARY_HAVE_WINNETWK_H 0
#	define MASTER_LIBRARY_HAVE_WINNLS_H 0
#	define MASTER_LIBRARY_HAVE_WINNT_H 0
#	define MASTER_LIBRARY_HAVE_WINREG_H 0
#	define MASTER_LIBRARY_HAVE_WINSVC_H 0
#	define MASTER_LIBRARY_HAVE_WINUSER_H 0
#	define MASTER_LIBRARY_HAVE_WINVER_H 0
#	define MASTER_LIBRARY_HAVE_CDERR_H 0
#	define MASTER_LIBRARY_HAVE_COMMLDG_H 0
#	define MASTER_LIBRARY_HAVE_DDE_H 0
#	define MASTER_LIBRARY_HAVE_DDEML_H 0
#	define MASTER_LIBRARY_HAVE_DLGS_H 0
#	define MASTER_LIBRARY_HAVE_LZEXPAND_H 0
#	define MASTER_LIBRARY_HAVE_MMSYSTEM_H 0
#	define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H 0
#	define MASTER_LIBRARY_HAVE_RPC_H 0
#	define MASTER_LIBRARY_HAVE_SHELLAPI_H 0
#	define MASTER_LIBRARY_HAVE_WINCRYPT_H 0
#	define MASTER_LIBRARY_HAVE_WINPERF_H 0
#	define MASTER_LIBRARY_HAVE_WINRESRC_H 0
#	define MASTER_LIBRARY_HAVE_WINSOCK_H 0
#	define MASTER_LIBRARY_HAVE_WINSPOOL_H 0
#	define MASTER_LIBRARY_HAVE_WINBGIM_H 0
#	define MASTER_LIBRARY_HAVE_OLE2_H 0
#	define MASTER_LIBRARY_HAVE_OBJBASE_H 0
#	define MASTER_LIBRARY_HAVE_OLEAUTO_H 0
#	define MASTER_LIBRARY_HAVE_OLETLID_H 0
#endif /* #! No Windows Dependencies !# */

#ifdef MASTER_NO_MSDOS_DEPENDENCIES
#	define MASTER_LIBRARY_HAVE_DOS_H 0
#endif /* #! No MSDOS Dependencies !# */

/* #! Plarform Specific Dependencies Close !# */

#ifndef MASTER_PREFER_POSIX_SUPPORTED
#	define MASTER_PREFER_POSIX_SUPPORTED 0
#endif /* #! POSIX Supported !# */

#ifndef MASTER_PREFER_WINDOWS_SUPPORTED
#	define MASTER_PREFER_WINDOWS_SUPPORTED 0
#endif /* #! Windows Supported !# */

#ifndef MASTER_PREFER_MSDOS_SUPPORTED
#	define MASTER_PREFER_MSDOS_SUPPORTED 0
#endif /* #! MSDOS Supported !# */

/* #! Smart Check Availability !# */

#ifndef MASTER_LIBRARY_HAVE_DOS_H
#	if MASTER_PREFER_MSDOS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("dos.h")
#		define MASTER_LIBRARY_HAVE_DOS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_DOS_H 0
#	endif /* #! Has include !# */
#endif /* #! dos.h !# */

#ifndef MASTER_LIBRARY_HAVE_AIO_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("aio.h")
#		define MASTER_LIBRARY_HAVE_AIO_H 1
#	else
#		define MASTER_LIBRARY_HAVE_AIO_H 0
#	endif /* #! Has include !# */
#endif /* #! aio.h !# */

#ifndef MASTER_LIBRARY_HAVE_ARPA_INET_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("arpa/inet.h")
#		define MASTER_LIBRARY_HAVE_ARPA_INET_H 1
#	else
#		define MASTER_LIBRARY_HAVE_ARPA_INET_H 0
#	endif /* #! Has include !# */
#endif /* #! arpa/inet.h !# */

#ifndef MASTER_LIBRARY_HAVE_CPIO_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cpio.h")
#		define MASTER_LIBRARY_HAVE_CPIO_H 1
#	else
#		define MASTER_LIBRARY_HAVE_CPIO_H 0
#	endif /* #! Has include !# */
#endif /* #! cpio.h !# */

#ifndef MASTER_LIBRARY_HAVE_DEVCTL_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("devctl.h")
#		define MASTER_LIBRARY_HAVE_DEVCTL_H 1
#	else
#		define MASTER_LIBRARY_HAVE_DEVCTL_H 0
#	endif /* #! Has include !# */
#endif /* #! devctl.h !# */

#ifndef MASTER_LIBRARY_HAVE_DIRENT_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("dirent.h")
#		define MASTER_LIBRARY_HAVE_DIRENT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_DIRENT_H 0
#	endif /* #! Has include !# */
#endif /* #! dirent.h !# */

#ifndef MASTER_LIBRARY_HAVE_DLFCN_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("dlfcn.h")
#		define MASTER_LIBRARY_HAVE_DLFCN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_DLFCN_H 0
#	endif /* #! Has include !# */
#endif /* #! dlfcn.h !# */

#ifndef MASTER_LIBRARY_HAVE_ENDIAN_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("endian.h")
#		define MASTER_LIBRARY_HAVE_ENDIAN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_ENDIAN_H 0
#	endif /* #! Has include !# */
#endif /* #! endian.h !# */

#ifndef MASTER_LIBRARY_HAVE_FCNTL_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("fcntl.h")
#		define MASTER_LIBRARY_HAVE_FCNTL_H 1
#	else
#		define MASTER_LIBRARY_HAVE_FCNTL_H 0
#	endif /* #! Has include !# */
#endif /* #! fcntl.h !# */

#ifndef MASTER_LIBRARY_HAVE_FMTMSG_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("fmtmsg.h")
#		define MASTER_LIBRARY_HAVE_FMTMSG_H 1
#	else
#		define MASTER_LIBRARY_HAVE_FMTMSG_H 0
#	endif /* #! Has include !# */
#endif /* #! fmtmsg.h !# */

#ifndef MASTER_LIBRARY_HAVE_FNMATCH_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("fnmatch.h")
#		define MASTER_LIBRARY_HAVE_FNMATCH_H 1
#	else
#		define MASTER_LIBRARY_HAVE_FNMATCH_H 0
#	endif /* #! Has include !# */
#endif /* #! fnmatch.h !# */

#ifndef MASTER_LIBRARY_HAVE_FTW_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ftw.h")
#		define MASTER_LIBRARY_HAVE_FTW_H 1
#	else
#		define MASTER_LIBRARY_HAVE_FTW_H 0
#	endif /* #! Has include !# */
#endif /* #! ftw.h !# */

#ifndef MASTER_LIBRARY_HAVE_GLOB_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("glob.h")
#		define MASTER_LIBRARY_HAVE_GLOB_H 1
#	else
#		define MASTER_LIBRARY_HAVE_GLOB_H 0
#	endif /* #! Has include !# */
#endif /* #! glob.h !# */

#ifndef MASTER_LIBRARY_HAVE_GRP_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("grp.h")
#		define MASTER_LIBRARY_HAVE_GRP_H 1
#	else
#		define MASTER_LIBRARY_HAVE_GRP_H 0
#	endif /* #! Has include !# */
#endif /* #! grp.h !# */

#ifndef MASTER_LIBRARY_HAVE_ICONV_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("iconv.h")
#		define MASTER_LIBRARY_HAVE_ICONV_H 1
#	else
#		define MASTER_LIBRARY_HAVE_ICONV_H 0
#	endif /* #! Has include !# */
#endif /* #! iconv.h !# */

#ifndef MASTER_LIBRARY_HAVE_LANGINFO_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("langinfo.h")
#		define MASTER_LIBRARY_HAVE_LANGINFO_H 1
#	else
#		define MASTER_LIBRARY_HAVE_LANGINFO_H 0
#	endif /* #! Has include !# */
#endif /* #! langinfo.h !# */

#ifndef MASTER_LIBRARY_HAVE_LIBGEN_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("libgen.h")
#		define MASTER_LIBRARY_HAVE_LIBGEN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_LIBGEN_H 0
#	endif /* #! Has include !# */
#endif /* #! libgen.h !# */

#ifndef MASTER_LIBRARY_HAVE_LIBINTL_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("libintl.h")
#		define MASTER_LIBRARY_HAVE_LIBINTL_H 1
#	else
#		define MASTER_LIBRARY_HAVE_LIBINTL_H 0
#	endif /* #! Has include !# */
#endif /* #! libintl.h !# */

#ifndef MASTER_LIBRARY_HAVE_MONETARY_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("monetary.h")
#		define MASTER_LIBRARY_HAVE_MONETARY_H 1
#	else
#		define MASTER_LIBRARY_HAVE_MONETARY_H 0
#	endif /* #! Has include !# */
#endif /* #! monetary.h !# */

#ifndef MASTER_LIBRARY_HAVE_MQUEUE_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("mqueue.h")
#		define MASTER_LIBRARY_HAVE_MQUEUE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_MQUEUE_H 0
#	endif /* #! Has include !# */
#endif /* #! mqueue.h !# */

#ifndef MASTER_LIBRARY_HAVE_NDBM_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ndbm.h")
#		define MASTER_LIBRARY_HAVE_NDBM_H 1
#	else
#		define MASTER_LIBRARY_HAVE_NDBM_H 0
#	endif /* #! Has include !# */
#endif /* #! ndbm.h !# */

#ifndef MASTER_LIBRARY_HAVE_NET_IF_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("net/if.h")
#		define MASTER_LIBRARY_HAVE_NET_IF_H 1
#	else
#		define MASTER_LIBRARY_HAVE_NET_IF_H 0
#	endif /* #! Has include !# */
#endif /* #! net/if.h !# */

#ifndef MASTER_LIBRARY_HAVE_NETDB_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("netdb.h")
#		define MASTER_LIBRARY_HAVE_NETDB_H 1
#	else
#		define MASTER_LIBRARY_HAVE_NETDB_H 0
#	endif /* #! Has include !# */
#endif /* #! netdb.h !# */

#ifndef MASTER_LIBRARY_HAVE_NETINET_IN_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("netinet/in.h")
#		define MASTER_LIBRARY_HAVE_NETINET_IN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_NETINET_IN_H 0
#	endif /* #! Has include !# */
#endif /* #! netinet/in.h !# */

#ifndef MASTER_LIBRARY_HAVE_NETINET_TCP_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("netinet/tcp.h")
#		define MASTER_LIBRARY_HAVE_NETINET_TCP_H 1
#	else
#		define MASTER_LIBRARY_HAVE_NETINET_TCP_H 0
#	endif /* #! Has include !# */
#endif /* #! netinet/tcp.h !# */

#ifndef MASTER_LIBRARY_HAVE_NL_TYPES_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("nl_types.h")
#		define MASTER_LIBRARY_HAVE_NL_TYPES_H 1
#	else
#		define MASTER_LIBRARY_HAVE_NL_TYPES_H 0
#	endif /* #! Has include !# */
#endif /* #! nl_types.h !# */

#ifndef MASTER_LIBRARY_HAVE_POLL_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("poll.h")
#		define MASTER_LIBRARY_HAVE_POLL_H 1
#	else
#		define MASTER_LIBRARY_HAVE_POLL_H 0
#	endif /* #! Has include !# */
#endif /* #! poll.h !# */

#ifndef MASTER_LIBRARY_HAVE_PTHREAD_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("pthread.h")
#		define MASTER_LIBRARY_HAVE_PTHREAD_H 1
#	else
#		define MASTER_LIBRARY_HAVE_PTHREAD_H 0
#	endif /* #! Has include !# */
#endif /* #! pthread.h !# */

#ifndef MASTER_LIBRARY_HAVE_PWD_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("pwd.h")
#		define MASTER_LIBRARY_HAVE_PWD_H 1
#	else
#		define MASTER_LIBRARY_HAVE_PWD_H 0
#	endif /* #! Has include !# */
#endif /* #! pwd.h !# */

#ifndef MASTER_LIBRARY_HAVE_REGEX_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("regex.h")
#		define MASTER_LIBRARY_HAVE_REGEX_H 1
#	else
#		define MASTER_LIBRARY_HAVE_REGEX_H 0
#	endif /* #! Has include !# */
#endif /* #! regex.h !# */

#ifndef MASTER_LIBRARY_HAVE_SCHED_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sched.h")
#		define MASTER_LIBRARY_HAVE_SCHED_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SCHED_H 0
#	endif /* #! Has include !# */
#endif /* #! sched.h !# */

#ifndef MASTER_LIBRARY_HAVE_SEARCH_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("search.h")
#		define MASTER_LIBRARY_HAVE_SEARCH_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SEARCH_H 0
#	endif /* #! Has include !# */
#endif /* #! search.h !# */

#ifndef MASTER_LIBRARY_HAVE_SEMAPHORE_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("semaphore.h")
#		define MASTER_LIBRARY_HAVE_SEMAPHORE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SEMAPHORE_H 0
#	endif /* #! Has include !# */
#endif /* #! semaphore.h !# */

#ifndef MASTER_LIBRARY_HAVE_SPAWN_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("spawn.h")
#		define MASTER_LIBRARY_HAVE_SPAWN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SPAWN_H 0
#	endif /* #! Has include !# */
#endif /* #! spawn.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDALIGN_H
#	if ((MASTER_PREFER_C11_SUPPORTED && (!MASTER_PREFER_C23_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1)) || MASTER_PREFER_CPP11_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdalign.h")
#		define MASTER_LIBRARY_HAVE_STDALIGN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDALIGN_H 0
#	endif /* #! Has include !# */
#endif /* #! stdalign.h !# */

#ifndef MASTER_LIBRARY_HAVE_STRINGS_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("strings.h")
#		define MASTER_LIBRARY_HAVE_STRINGS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STRINGS_H 0
#	endif /* #! Has include !# */
#endif /* #! strings.h !# */

#ifndef MASTER_LIBRARY_HAVE_STROPTS_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("stropts.h")
#		define MASTER_LIBRARY_HAVE_STROPTS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STROPTS_H 0
#	endif /* #! Has include !# */
#endif /* #! stropts.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_IPC_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/ipc.h")
#		define MASTER_LIBRARY_HAVE_SYS_IPC_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_IPC_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/ipc.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_MMAN_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/mman.h")
#		define MASTER_LIBRARY_HAVE_SYS_MMAN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_MMAN_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/mman.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_MSG_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/msg.h")
#		define MASTER_LIBRARY_HAVE_SYS_MSG_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_MSG_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/msg.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_RESOURCE_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/resource.h")
#		define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_RESOURCE_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/resource.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_SELECT_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/select.h")
#		define MASTER_LIBRARY_HAVE_SYS_SELECT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_SELECT_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/select.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_SEM_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/sem.h")
#		define MASTER_LIBRARY_HAVE_SYS_SEM_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_SEM_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/sem.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_SHM_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/shm.h")
#		define MASTER_LIBRARY_HAVE_SYS_SHM_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_SHM_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/shm.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_SOCKET_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/socket.h")
#		define MASTER_LIBRARY_HAVE_SYS_SOCKET_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_SOCKET_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/socket.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_STAT_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/stat.h")
#		define MASTER_LIBRARY_HAVE_SYS_STAT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_STAT_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/stat.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_STATVFS_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/statvfs.h")
#		define MASTER_LIBRARY_HAVE_SYS_STATVFS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_STATVFS_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/statvfs.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_TIME_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/time.h")
#		define MASTER_LIBRARY_HAVE_SYS_TIME_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_TIME_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/time.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_TIMES_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/times.h")
#		define MASTER_LIBRARY_HAVE_SYS_TIMES_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_TIMES_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/times.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_TYPES_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/types.h")
#		define MASTER_LIBRARY_HAVE_SYS_TYPES_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_TYPES_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/types.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_UIO_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/uio.h")
#		define MASTER_LIBRARY_HAVE_SYS_UIO_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_UIO_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/uio.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_UN_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/un.h")
#		define MASTER_LIBRARY_HAVE_SYS_UN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_UN_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/un.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_UTSNAME_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/utsname.h")
#		define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_UTSNAME_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/utsname.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYS_WAIT_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sys/wait.h")
#		define MASTER_LIBRARY_HAVE_SYS_WAIT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYS_WAIT_H 0
#	endif /* #! Has include !# */
#endif /* #! sys/wait.h !# */

#ifndef MASTER_LIBRARY_HAVE_SYSLOG_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("syslog.h")
#		define MASTER_LIBRARY_HAVE_SYSLOG_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SYSLOG_H 0
#	endif /* #! Has include !# */
#endif /* #! syslog.h !# */

#ifndef MASTER_LIBRARY_HAVE_TAR_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("tar.h")
#		define MASTER_LIBRARY_HAVE_TAR_H 1
#	else
#		define MASTER_LIBRARY_HAVE_TAR_H 0
#	endif /* #! Has include !# */
#endif /* #! tar.h !# */

#ifndef MASTER_LIBRARY_HAVE_TERMIOS_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("termios.h")
#		define MASTER_LIBRARY_HAVE_TERMIOS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_TERMIOS_H 0
#	endif /* #! Has include !# */
#endif /* #! termios.h !# */

#ifndef MASTER_LIBRARY_HAVE_TRACE_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("trace.h")
#		define MASTER_LIBRARY_HAVE_TRACE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_TRACE_H 0
#	endif /* #! Has include !# */
#endif /* #! trace.h !# */

#ifndef MASTER_LIBRARY_HAVE_UCONTEXT_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ucontext.h")
#		define MASTER_LIBRARY_HAVE_UCONTEXT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_UCONTEXT_H 0
#	endif /* #! Has include !# */
#endif /* #! ucontext.h !# */

#ifndef MASTER_LIBRARY_HAVE_ULIMIT_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ulimit.h")
#		define MASTER_LIBRARY_HAVE_ULIMIT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_ULIMIT_H 0
#	endif /* #! Has include !# */
#endif /* #! ulimit.h !# */

#ifndef MASTER_LIBRARY_HAVE_UTIME_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("utime.h")
#		define MASTER_LIBRARY_HAVE_UTIME_H 1
#	else
#		define MASTER_LIBRARY_HAVE_UTIME_H 0
#	endif /* #! Has include !# */
#endif /* #! utime.h !# */

#ifndef MASTER_LIBRARY_HAVE_UTMPX_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("utmpx.h")
#		define MASTER_LIBRARY_HAVE_UTMPX_H 1
#	else
#		define MASTER_LIBRARY_HAVE_UTMPX_H 0
#	endif /* #! Has include !# */
#endif /* #! utmpx.h !# */

#ifndef MASTER_LIBRARY_HAVE_WORDEXP_H
#	if MASTER_PREFER_POSIX_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("wordexp.h")
#		define MASTER_LIBRARY_HAVE_WORDEXP_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WORDEXP_H 0
#	endif /* #! Has include !# */
#endif /* #! wordexp.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINDOWS_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("windows.h")
#		define MASTER_LIBRARY_HAVE_WINDOWS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINDOWS_H 0
#	endif /* #! Has include !# */
#endif /* #! windows.h !# */

#ifndef MASTER_LIBRARY_HAVE_CONIO_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("conio.h")
#		define MASTER_LIBRARY_HAVE_CONIO_H 1
#	else
#		define MASTER_LIBRARY_HAVE_CONIO_H 0
#	endif /* #! Has include !# */
#endif /* #! conio.h !# */

#ifndef MASTER_LIBRARY_HAVE_BASETSD_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("basetsd.h")
#		define MASTER_LIBRARY_HAVE_BASETSD_H 1
#	else
#		define MASTER_LIBRARY_HAVE_BASETSD_H 0
#	endif /* #! Has include !# */
#endif /* #! basetsd.h !# */

#ifndef MASTER_LIBRARY_HAVE_GUIDDEF_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("guiddef.h")
#		define MASTER_LIBRARY_HAVE_GUIDDEF_H 1
#	else
#		define MASTER_LIBRARY_HAVE_GUIDDEF_H 0
#	endif /* #! Has include !# */
#endif /* #! guiddef.h !# */

#ifndef MASTER_LIBRARY_HAVE_IMM_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("imm.h")
#		define MASTER_LIBRARY_HAVE_IMM_H 1
#	else
#		define MASTER_LIBRARY_HAVE_IMM_H 0
#	endif /* #! Has include !# */
#endif /* #! imm.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINBASE_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winbase.h")
#		define MASTER_LIBRARY_HAVE_WINBASE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINBASE_H 0
#	endif /* #! Has include !# */
#endif /* #! winbase.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINCON_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("wincon.h")
#		define MASTER_LIBRARY_HAVE_WINCON_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINCON_H 0
#	endif /* #! Has include !# */
#endif /* #! wincon.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINDEF_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("windef.h")
#		define MASTER_LIBRARY_HAVE_WINDEF_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINDEF_H 0
#	endif /* #! Has include !# */
#endif /* #! windef.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINERROR_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winerror.h")
#		define MASTER_LIBRARY_HAVE_WINERROR_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINERROR_H 0
#	endif /* #! Has include !# */
#endif /* #! winerror.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINGDI_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("wingdi.h")
#		define MASTER_LIBRARY_HAVE_WINGDI_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINGDI_H 0
#	endif /* #! Has include !# */
#endif /* #! wingdi.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINNETWK_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winnetwk.h")
#		define MASTER_LIBRARY_HAVE_WINNETWK_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINNETWK_H 0
#	endif /* #! Has include !# */
#endif /* #! winnetwk.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINNLS_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winnls.h")
#		define MASTER_LIBRARY_HAVE_WINNLS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINNLS_H 0
#	endif /* #! Has include !# */
#endif /* #! winnls.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINNT_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winnt.h")
#		define MASTER_LIBRARY_HAVE_WINNT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINNT_H 0
#	endif /* #! Has include !# */
#endif /* #! winnt.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINREG_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winreg.h")
#		define MASTER_LIBRARY_HAVE_WINREG_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINREG_H 0
#	endif /* #! Has include !# */
#endif /* #! winreg.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINSVC_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winsvc.h")
#		define MASTER_LIBRARY_HAVE_WINSVC_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINSVC_H 0
#	endif /* #! Has include !# */
#endif /* #! winsvc.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINUSER_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winuser.h")
#		define MASTER_LIBRARY_HAVE_WINUSER_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINUSER_H 0
#	endif /* #! Has include !# */
#endif /* #! winuser.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINVER_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winver.h")
#		define MASTER_LIBRARY_HAVE_WINVER_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINVER_H 0
#	endif /* #! Has include !# */
#endif /* #! winver.h !# */

#ifndef MASTER_LIBRARY_HAVE_CDERR_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cderr.h")
#		define MASTER_LIBRARY_HAVE_CDERR_H 1
#	else
#		define MASTER_LIBRARY_HAVE_CDERR_H 0
#	endif /* #! Has include !# */
#endif /* #! cderr.h !# */

#ifndef MASTER_LIBRARY_HAVE_COMMLDG_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("commldg.h")
#		define MASTER_LIBRARY_HAVE_COMMLDG_H 1
#	else
#		define MASTER_LIBRARY_HAVE_COMMLDG_H 0
#	endif /* #! Has include !# */
#endif /* #! commldg.h !# */

#ifndef MASTER_LIBRARY_HAVE_DDE_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("dde.h")
#		define MASTER_LIBRARY_HAVE_DDE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_DDE_H 0
#	endif /* #! Has include !# */
#endif /* #! dde.h !# */

#ifndef MASTER_LIBRARY_HAVE_DDEML_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ddeml.h")
#		define MASTER_LIBRARY_HAVE_DDEML_H 1
#	else
#		define MASTER_LIBRARY_HAVE_DDEML_H 0
#	endif /* #! Has include !# */
#endif /* #! ddeml.h !# */

#ifndef MASTER_LIBRARY_HAVE_DLGS_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("dlgs.h")
#		define MASTER_LIBRARY_HAVE_DLGS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_DLGS_H 0
#	endif /* #! Has include !# */
#endif /* #! dlgs.h !# */

#ifndef MASTER_LIBRARY_HAVE_LZEXPAND_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("lzexpand.h")
#		define MASTER_LIBRARY_HAVE_LZEXPAND_H 1
#	else
#		define MASTER_LIBRARY_HAVE_LZEXPAND_H 0
#	endif /* #! Has include !# */
#endif /* #! lzexpand.h !# */

#ifndef MASTER_LIBRARY_HAVE_MMSYSTEM_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("mmsystem.h")
#		define MASTER_LIBRARY_HAVE_MMSYSTEM_H 1
#	else
#		define MASTER_LIBRARY_HAVE_MMSYSTEM_H 0
#	endif /* #! Has include !# */
#endif /* #! mmsystem.h !# */

#ifndef MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("nb3master/answer/n.h")
#		define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H 1
#	else
#		define MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H 0
#	endif /* #! Has include !# */
#endif /* #! nb3master/answer/n.h !# */

#ifndef MASTER_LIBRARY_HAVE_RPC_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("rpc.h")
#		define MASTER_LIBRARY_HAVE_RPC_H 1
#	else
#		define MASTER_LIBRARY_HAVE_RPC_H 0
#	endif /* #! Has include !# */
#endif /* #! rpc.h !# */

#ifndef MASTER_LIBRARY_HAVE_SHELLAPI_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("shellapi.h")
#		define MASTER_LIBRARY_HAVE_SHELLAPI_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SHELLAPI_H 0
#	endif /* #! Has include !# */
#endif /* #! shellapi.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINCRYPT_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("wincrypt.h")
#		define MASTER_LIBRARY_HAVE_WINCRYPT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINCRYPT_H 0
#	endif /* #! Has include !# */
#endif /* #! wincrypt.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINPERF_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winperf.h")
#		define MASTER_LIBRARY_HAVE_WINPERF_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINPERF_H 0
#	endif /* #! Has include !# */
#endif /* #! winperf.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINRESRC_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winresrc.h")
#		define MASTER_LIBRARY_HAVE_WINRESRC_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINRESRC_H 0
#	endif /* #! Has include !# */
#endif /* #! winresrc.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINSOCK_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winsock.h")
#		define MASTER_LIBRARY_HAVE_WINSOCK_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINSOCK_H 0
#	endif /* #! Has include !# */
#endif /* #! winsock.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINSPOOL_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winspool.h")
#		define MASTER_LIBRARY_HAVE_WINSPOOL_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINSPOOL_H 0
#	endif /* #! Has include !# */
#endif /* #! winspool.h !# */

#ifndef MASTER_LIBRARY_HAVE_WINBGIM_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("winbgim.h")
#		define MASTER_LIBRARY_HAVE_WINBGIM_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WINBGIM_H 0
#	endif /* #! Has include !# */
#endif /* #! winbgim.h !# */

#ifndef MASTER_LIBRARY_HAVE_OLE2_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ole2.h")
#		define MASTER_LIBRARY_HAVE_OLE2_H 1
#	else
#		define MASTER_LIBRARY_HAVE_OLE2_H 0
#	endif /* #! Has include !# */
#endif /* #! ole2.h !# */

#ifndef MASTER_LIBRARY_HAVE_OBJBASE_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("objbase.h")
#		define MASTER_LIBRARY_HAVE_OBJBASE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_OBJBASE_H 0
#	endif /* #! Has include !# */
#endif /* #! objbase.h !# */

#ifndef MASTER_LIBRARY_HAVE_OLEAUTO_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("oleauto.h")
#		define MASTER_LIBRARY_HAVE_OLEAUTO_H 1
#	else
#		define MASTER_LIBRARY_HAVE_OLEAUTO_H 0
#	endif /* #! Has include !# */
#endif /* #! oleauto.h !# */

#ifndef MASTER_LIBRARY_HAVE_OLETLID_H
#	if MASTER_PREFER_WINDOWS_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("oletlid.h")
#		define MASTER_LIBRARY_HAVE_OLETLID_H 1
#	else
#		define MASTER_LIBRARY_HAVE_OLETLID_H 0
#	endif /* #! Has include !# */
#endif /* #! oletlid.h !# */

#ifndef MASTER_LIBRARY_HAVE_ASSERT_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("assert.h")
#		define MASTER_LIBRARY_HAVE_ASSERT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_ASSERT_H 0
#	endif /* #! Has include !# */
#endif /* #! assert.h !# */

#ifndef MASTER_LIBRARY_HAVE_COMPLEX_H
#	if (MASTER_PREFER_C99_SUPPORTED || MASTER_PREFER_CPP11_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("complex.h")
#		define MASTER_LIBRARY_HAVE_COMPLEX_H 1
#	else
#		define MASTER_LIBRARY_HAVE_COMPLEX_H 0
#	endif /* #! Has include !# */
#endif /* #! complex.h !# */

#ifndef MASTER_LIBRARY_HAVE_CTYPE_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("ctype.h")
#		define MASTER_LIBRARY_HAVE_CTYPE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_CTYPE_H 0
#	endif /* #! Has include !# */
#endif /* #! ctype.h !# */

#ifndef MASTER_LIBRARY_HAVE_ERRNO_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("errno.h")
#		define MASTER_LIBRARY_HAVE_ERRNO_H 1
#	else
#		define MASTER_LIBRARY_HAVE_ERRNO_H 0
#	endif /* #! Has include !# */
#endif /* #! errno.h !# */

#ifndef MASTER_LIBRARY_HAVE_FENV_H
#	if (MASTER_PREFER_C99_SUPPORTED || MASTER_PREFER_CPP11_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("fenv.h")
#		define MASTER_LIBRARY_HAVE_FENV_H 1
#	else
#		define MASTER_LIBRARY_HAVE_FENV_H 0
#	endif /* #! Has include !# */
#endif /* #! fenv.h !# */

#ifndef MASTER_LIBRARY_HAVE_FLOAT_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("float.h")
#		define MASTER_LIBRARY_HAVE_FLOAT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_FLOAT_H 0
#	endif /* #! Has include !# */
#endif /* #! float.h !# */

#ifndef MASTER_LIBRARY_HAVE_INTTYPES_H
#	if (MASTER_PREFER_C99_SUPPORTED || MASTER_PREFER_CPP11_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("inttypes.h")
#		define MASTER_LIBRARY_HAVE_INTTYPES_H 1
#	else
#		define MASTER_LIBRARY_HAVE_INTTYPES_H 0
#	endif /* #! Has include !# */
#endif /* #! inttypes.h !# */

#ifndef MASTER_LIBRARY_HAVE_ISO646_H
#	if (MASTER_PREFER_C95_SUPPORTED || MASTER_PREFER_CPP98_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("iso646.h")
#		define MASTER_LIBRARY_HAVE_ISO646_H 1
#	else
#		define MASTER_LIBRARY_HAVE_ISO646_H 0
#	endif /* #! Has include !# */
#endif /* #! iso646.h !# */

#ifndef MASTER_LIBRARY_HAVE_LIMITS_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("limits.h")
#		define MASTER_LIBRARY_HAVE_LIMITS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_LIMITS_H 0
#	endif /* #! Has include !# */
#endif /* #! limits.h !# */

#ifndef MASTER_LIBRARY_HAVE_LOCALE_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("locale.h")
#		define MASTER_LIBRARY_HAVE_LOCALE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_LOCALE_H 0
#	endif /* #! Has include !# */
#endif /* #! locale.h !# */

#ifndef MASTER_LIBRARY_HAVE_MATH_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("math.h")
#		define MASTER_LIBRARY_HAVE_MATH_H 1
#	else
#		define MASTER_LIBRARY_HAVE_MATH_H 0
#	endif /* #! Has include !# */
#endif /* #! math.h !# */

#ifndef MASTER_LIBRARY_HAVE_SETJMP_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("setjmp.h")
#		define MASTER_LIBRARY_HAVE_SETJMP_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SETJMP_H 0
#	endif /* #! Has include !# */
#endif /* #! setjmp.h !# */

#ifndef MASTER_LIBRARY_HAVE_SIGNAL_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("signal.h")
#		define MASTER_LIBRARY_HAVE_SIGNAL_H 1
#	else
#		define MASTER_LIBRARY_HAVE_SIGNAL_H 0
#	endif /* #! Has include !# */
#endif /* #! signal.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDARG_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdarg.h")
#		define MASTER_LIBRARY_HAVE_STDARG_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDARG_H 0
#	endif /* #! Has include !# */
#endif /* #! stdarg.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDATOMIC_H
#	if (MASTER_PREFER_C11_SUPPORTED || MASTER_PREFER_CPP23_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdatomic.h")
#		define MASTER_LIBRARY_HAVE_STDATOMIC_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDATOMIC_H 0
#	endif /* #! Has include !# */
#endif /* #! stdatomic.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDBIT_H
#	if (MASTER_PREFER_C23_SUPPORTED || MASTER_PREFER_CPP26_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdbit.h")
#		define MASTER_LIBRARY_HAVE_STDBIT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDBIT_H 0
#	endif /* #! Has include !# */
#endif /* #! stdbit.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDBOOL_H
#	if ((MASTER_PREFER_C99_SUPPORTED && (!MASTER_PREFER_C23_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1)) || MASTER_PREFER_CPP11_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdbool.h")
#		define MASTER_LIBRARY_HAVE_STDBOOL_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDBOOL_H 0
#	endif /* #! Has include !# */
#endif /* #! stdbool.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDCKDINT_H
#	if (MASTER_PREFER_C23_SUPPORTED || MASTER_PREFER_CPP26_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdckdint.h")
#		define MASTER_LIBRARY_HAVE_STDCKDINT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDCKDINT_H 0
#	endif /* #! Has include !# */
#endif /* #! stdckdint.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDDEF_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stddef.h")
#		define MASTER_LIBRARY_HAVE_STDDEF_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDDEF_H 0
#	endif /* #! Has include !# */
#endif /* #! stddef.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDINT_H
#	if (MASTER_PREFER_C99_SUPPORTED || MASTER_PREFER_CPP11_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdint.h")
#		define MASTER_LIBRARY_HAVE_STDINT_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDINT_H 0
#	endif /* #! Has include !# */
#endif /* #! stdint.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDIO_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdio.h")
#		define MASTER_LIBRARY_HAVE_STDIO_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDIO_H 0
#	endif /* #! Has include !# */
#endif /* #! stdio.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDLIB_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("stdlib.h")
#		define MASTER_LIBRARY_HAVE_STDLIB_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDLIB_H 0
#	endif /* #! Has include !# */
#endif /* #! stdlib.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDMCHAR_H
#	if MASTER_PREFER_C29_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("stdmchar.h")
#		define MASTER_LIBRARY_HAVE_STDMCHAR_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDMCHAR_H 0
#	endif /* #! Has include !# */
#endif /* #! stdmchar.h !# */

#ifndef MASTER_LIBRARY_HAVE_STDNORETURN_H
#	if ((MASTER_PREFER_C11_SUPPORTED && (!MASTER_PREFER_C23_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1))) && MASTER_COMPILER_CAN_INCLUDE("stdnoreturn.h")
#		define MASTER_LIBRARY_HAVE_STDNORETURN_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STDNORETURN_H 0
#	endif /* #! Has include !# */
#endif /* #! stdnoreturn.h !# */

#ifndef MASTER_LIBRARY_HAVE_STRING_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("string.h")
#		define MASTER_LIBRARY_HAVE_STRING_H 1
#	else
#		define MASTER_LIBRARY_HAVE_STRING_H 0
#	endif /* #! Has include !# */
#endif /* #! string.h !# */

#ifndef MASTER_LIBRARY_HAVE_TGMATH_H
#	if (MASTER_PREFER_C99_SUPPORTED || MASTER_PREFER_CPP11_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("tgmath.h")
#		define MASTER_LIBRARY_HAVE_TGMATH_H 1
#	else
#		define MASTER_LIBRARY_HAVE_TGMATH_H 0
#	endif /* #! Has include !# */
#endif /* #! tgmath.h !# */

#ifndef MASTER_LIBRARY_HAVE_THREADS_H
#	if MASTER_PREFER_C11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("threads.h")
#		define MASTER_LIBRARY_HAVE_THREADS_H 1
#	else
#		define MASTER_LIBRARY_HAVE_THREADS_H 0
#	endif /* #! Has include !# */
#endif /* #! threads.h !# */

#ifndef MASTER_LIBRARY_HAVE_TIME_H
#	if (MASTER_PREFER_C_SUPPORTED || MASTER_PREFER_CPP_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("time.h")
#		define MASTER_LIBRARY_HAVE_TIME_H 1
#	else
#		define MASTER_LIBRARY_HAVE_TIME_H 0
#	endif /* #! Has include !# */
#endif /* #! time.h !# */

#ifndef MASTER_LIBRARY_HAVE_UCHAR_H
#	if (MASTER_PREFER_C11_SUPPORTED || MASTER_PREFER_CPP11_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("uchar.h")
#		define MASTER_LIBRARY_HAVE_UCHAR_H 1
#	else
#		define MASTER_LIBRARY_HAVE_UCHAR_H 0
#	endif /* #! Has include !# */
#endif /* #! uchar.h !# */

#ifndef MASTER_LIBRARY_HAVE_WCHAR_H
#	if (MASTER_PREFER_C95_SUPPORTED || MASTER_PREFER_CPP98_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("wchar.h")
#		define MASTER_LIBRARY_HAVE_WCHAR_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WCHAR_H 0
#	endif /* #! Has include !# */
#endif /* #! wchar.h !# */

#ifndef MASTER_LIBRARY_HAVE_WCTYPE_H
#	if (MASTER_PREFER_C95_SUPPORTED || MASTER_PREFER_CPP98_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("wctype.h")
#		define MASTER_LIBRARY_HAVE_WCTYPE_H 1
#	else
#		define MASTER_LIBRARY_HAVE_WCTYPE_H 0
#	endif /* #! Has include !# */
#endif /* #! wctype.h !# */

#ifndef MASTER_LIBRARY_HAVE_CSTDLIB
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cstdlib")
#		define MASTER_LIBRARY_HAVE_CSTDLIB 1
#	else
#		define MASTER_LIBRARY_HAVE_CSTDLIB 0
#	endif /* #! Has include !# */
#endif /* #! cstdlib !# */

#ifndef MASTER_LIBRARY_HAVE_EXECUTION
#	if MASTER_PREFER_CPP17_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("execution")
#		define MASTER_LIBRARY_HAVE_EXECUTION 1
#	else
#		define MASTER_LIBRARY_HAVE_EXECUTION 0
#	endif /* #! Has include !# */
#endif /* #! execution !# */

#ifndef MASTER_LIBRARY_HAVE_CFLOAT
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cfloat")
#		define MASTER_LIBRARY_HAVE_CFLOAT 1
#	else
#		define MASTER_LIBRARY_HAVE_CFLOAT 0
#	endif /* #! Has include !# */
#endif /* #! cfloat !# */

#ifndef MASTER_LIBRARY_HAVE_CLIMITS
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("climits")
#		define MASTER_LIBRARY_HAVE_CLIMITS 1
#	else
#		define MASTER_LIBRARY_HAVE_CLIMITS 0
#	endif /* #! Has include !# */
#endif /* #! climits !# */

#ifndef MASTER_LIBRARY_HAVE_COMPARE
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("compare")
#		define MASTER_LIBRARY_HAVE_COMPARE 1
#	else
#		define MASTER_LIBRARY_HAVE_COMPARE 0
#	endif /* #! Has include !# */
#endif /* #! compare !# */

#ifndef MASTER_LIBRARY_HAVE_CONTRACTS
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("contracts")
#		define MASTER_LIBRARY_HAVE_CONTRACTS 1
#	else
#		define MASTER_LIBRARY_HAVE_CONTRACTS 0
#	endif /* #! Has include !# */
#endif /* #! contracts !# */

#ifndef MASTER_LIBRARY_HAVE_COROUTINE
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("coroutine")
#		define MASTER_LIBRARY_HAVE_COROUTINE 1
#	else
#		define MASTER_LIBRARY_HAVE_COROUTINE 0
#	endif /* #! Has include !# */
#endif /* #! coroutine !# */

#ifndef MASTER_LIBRARY_HAVE_CSETJMP
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("csetjmp")
#		define MASTER_LIBRARY_HAVE_CSETJMP 1
#	else
#		define MASTER_LIBRARY_HAVE_CSETJMP 0
#	endif /* #! Has include !# */
#endif /* #! csetjmp !# */

#ifndef MASTER_LIBRARY_HAVE_CSIGNAL
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("csignal")
#		define MASTER_LIBRARY_HAVE_CSIGNAL 1
#	else
#		define MASTER_LIBRARY_HAVE_CSIGNAL 0
#	endif /* #! Has include !# */
#endif /* #! csignal !# */

#ifndef MASTER_LIBRARY_HAVE_CSTDARG
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cstdarg")
#		define MASTER_LIBRARY_HAVE_CSTDARG 1
#	else
#		define MASTER_LIBRARY_HAVE_CSTDARG 0
#	endif /* #! Has include !# */
#endif /* #! cstdarg !# */

#ifndef MASTER_LIBRARY_HAVE_CSTDDEF
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cstddef")
#		define MASTER_LIBRARY_HAVE_CSTDDEF 1
#	else
#		define MASTER_LIBRARY_HAVE_CSTDDEF 0
#	endif /* #! Has include !# */
#endif /* #! cstddef !# */

#ifndef MASTER_LIBRARY_HAVE_CSTDINT
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cstdint")
#		define MASTER_LIBRARY_HAVE_CSTDINT 1
#	else
#		define MASTER_LIBRARY_HAVE_CSTDINT 0
#	endif /* #! Has include !# */
#endif /* #! cstdint !# */

#ifndef MASTER_LIBRARY_HAVE_EXCEPTION
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("exception")
#		define MASTER_LIBRARY_HAVE_EXCEPTION 1
#	else
#		define MASTER_LIBRARY_HAVE_EXCEPTION 0
#	endif /* #! Has include !# */
#endif /* #! exception !# */

#ifndef MASTER_LIBRARY_HAVE_INITIALIZER_LIST
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("initializer_list")
#		define MASTER_LIBRARY_HAVE_INITIALIZER_LIST 1
#	else
#		define MASTER_LIBRARY_HAVE_INITIALIZER_LIST 0
#	endif /* #! Has include !# */
#endif /* #! initializer_list !# */

#ifndef MASTER_LIBRARY_HAVE_LIMITS
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("limits")
#		define MASTER_LIBRARY_HAVE_LIMITS 1
#	else
#		define MASTER_LIBRARY_HAVE_LIMITS 0
#	endif /* #! Has include !# */
#endif /* #! limits !# */

#ifndef MASTER_LIBRARY_HAVE_NEW
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("new")
#		define MASTER_LIBRARY_HAVE_NEW 1
#	else
#		define MASTER_LIBRARY_HAVE_NEW 0
#	endif /* #! Has include !# */
#endif /* #! new !# */

#ifndef MASTER_LIBRARY_HAVE_SOURCE_LOCATION
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("source_location")
#		define MASTER_LIBRARY_HAVE_SOURCE_LOCATION 1
#	else
#		define MASTER_LIBRARY_HAVE_SOURCE_LOCATION 0
#	endif /* #! Has include !# */
#endif /* #! source_location !# */

#ifndef MASTER_LIBRARY_HAVE_STDFLOAT
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("stdfloat")
#		define MASTER_LIBRARY_HAVE_STDFLOAT 1
#	else
#		define MASTER_LIBRARY_HAVE_STDFLOAT 0
#	endif /* #! Has include !# */
#endif /* #! stdfloat !# */

#ifndef MASTER_LIBRARY_HAVE_TYPEINDEX
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("typeindex")
#		define MASTER_LIBRARY_HAVE_TYPEINDEX 1
#	else
#		define MASTER_LIBRARY_HAVE_TYPEINDEX 0
#	endif /* #! Has include !# */
#endif /* #! typeindex !# */

#ifndef MASTER_LIBRARY_HAVE_TYPEINFO
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("typeinfo")
#		define MASTER_LIBRARY_HAVE_TYPEINFO 1
#	else
#		define MASTER_LIBRARY_HAVE_TYPEINFO 0
#	endif /* #! Has include !# */
#endif /* #! typeinfo !# */

#ifndef MASTER_LIBRARY_HAVE_VERSION
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("version")
#		define MASTER_LIBRARY_HAVE_VERSION 1
#	else
#		define MASTER_LIBRARY_HAVE_VERSION 0
#	endif /* #! Has include !# */
#endif /* #! version !# */

#ifndef MASTER_LIBRARY_HAVE_CONCEPTS
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("concepts")
#		define MASTER_LIBRARY_HAVE_CONCEPTS 1
#	else
#		define MASTER_LIBRARY_HAVE_CONCEPTS 0
#	endif /* #! Has include !# */
#endif /* #! concepts !# */

#ifndef MASTER_LIBRARY_HAVE_CASSERT
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cassert")
#		define MASTER_LIBRARY_HAVE_CASSERT 1
#	else
#		define MASTER_LIBRARY_HAVE_CASSERT 0
#	endif /* #! Has include !# */
#endif /* #! cassert !# */

#ifndef MASTER_LIBRARY_HAVE_CERRNO
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cerrno")
#		define MASTER_LIBRARY_HAVE_CERRNO 1
#	else
#		define MASTER_LIBRARY_HAVE_CERRNO 0
#	endif /* #! Has include !# */
#endif /* #! cerrno !# */

#ifndef MASTER_LIBRARY_HAVE_DEBUGGING
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("debugging")
#		define MASTER_LIBRARY_HAVE_DEBUGGING 1
#	else
#		define MASTER_LIBRARY_HAVE_DEBUGGING 0
#	endif /* #! Has include !# */
#endif /* #! debugging !# */

#ifndef MASTER_LIBRARY_HAVE_STACKTRACE
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("stacktrace")
#		define MASTER_LIBRARY_HAVE_STACKTRACE 1
#	else
#		define MASTER_LIBRARY_HAVE_STACKTRACE 0
#	endif /* #! Has include !# */
#endif /* #! stacktrace !# */

#ifndef MASTER_LIBRARY_HAVE_STDEXCEPT
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("stdexcept")
#		define MASTER_LIBRARY_HAVE_STDEXCEPT 1
#	else
#		define MASTER_LIBRARY_HAVE_STDEXCEPT 0
#	endif /* #! Has include !# */
#endif /* #! stdexcept !# */

#ifndef MASTER_LIBRARY_HAVE_SYSTEM_ERROR
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("system_error")
#		define MASTER_LIBRARY_HAVE_SYSTEM_ERROR 1
#	else
#		define MASTER_LIBRARY_HAVE_SYSTEM_ERROR 0
#	endif /* #! Has include !# */
#endif /* #! system_error !# */

#ifndef MASTER_LIBRARY_HAVE_MEMORY
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("memory")
#		define MASTER_LIBRARY_HAVE_MEMORY 1
#	else
#		define MASTER_LIBRARY_HAVE_MEMORY 0
#	endif /* #! Has include !# */
#endif /* #! memory !# */

#ifndef MASTER_LIBRARY_HAVE_MEMORY_RESOURCE
#	if MASTER_PREFER_CPP17_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("memory_resource")
#		define MASTER_LIBRARY_HAVE_MEMORY_RESOURCE 1
#	else
#		define MASTER_LIBRARY_HAVE_MEMORY_RESOURCE 0
#	endif /* #! Has include !# */
#endif /* #! memory_resource !# */

#ifndef MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("scoped_allocator")
#		define MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR 1
#	else
#		define MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR 0
#	endif /* #! Has include !# */
#endif /* #! scoped_allocator !# */

#ifndef MASTER_LIBRARY_HAVE_RATIO
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ratio")
#		define MASTER_LIBRARY_HAVE_RATIO 1
#	else
#		define MASTER_LIBRARY_HAVE_RATIO 0
#	endif /* #! Has include !# */
#endif /* #! ratio !# */

#ifndef MASTER_LIBRARY_HAVE_TYPE_TRAITS
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("type_traits")
#		define MASTER_LIBRARY_HAVE_TYPE_TRAITS 1
#	else
#		define MASTER_LIBRARY_HAVE_TYPE_TRAITS 0
#	endif /* #! Has include !# */
#endif /* #! type_traits !# */

#ifndef MASTER_LIBRARY_HAVE_ANY
#	if MASTER_PREFER_CPP17_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("any")
#		define MASTER_LIBRARY_HAVE_ANY 1
#	else
#		define MASTER_LIBRARY_HAVE_ANY 0
#	endif /* #! Has include !# */
#endif /* #! any !# */

#ifndef MASTER_LIBRARY_HAVE_BIT
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("bit")
#		define MASTER_LIBRARY_HAVE_BIT 1
#	else
#		define MASTER_LIBRARY_HAVE_BIT 0
#	endif /* #! Has include !# */
#endif /* #! bit !# */

#ifndef MASTER_LIBRARY_HAVE_BITSET
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("bitset")
#		define MASTER_LIBRARY_HAVE_BITSET 1
#	else
#		define MASTER_LIBRARY_HAVE_BITSET 0
#	endif /* #! Has include !# */
#endif /* #! bitset !# */

#ifndef MASTER_LIBRARY_HAVE_EXPECTED
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("expected")
#		define MASTER_LIBRARY_HAVE_EXPECTED 1
#	else
#		define MASTER_LIBRARY_HAVE_EXPECTED 0
#	endif /* #! Has include !# */
#endif /* #! expected !# */

#ifndef MASTER_LIBRARY_HAVE_FUNCTIONAL
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("functional")
#		define MASTER_LIBRARY_HAVE_FUNCTIONAL 1
#	else
#		define MASTER_LIBRARY_HAVE_FUNCTIONAL 0
#	endif /* #! Has include !# */
#endif /* #! functional !# */

#ifndef MASTER_LIBRARY_HAVE_OPTIONAL
#	if MASTER_PREFER_CPP17_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("optional")
#		define MASTER_LIBRARY_HAVE_OPTIONAL 1
#	else
#		define MASTER_LIBRARY_HAVE_OPTIONAL 0
#	endif /* #! Has include !# */
#endif /* #! optional !# */

#ifndef MASTER_LIBRARY_HAVE_TUPLE
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("tuple")
#		define MASTER_LIBRARY_HAVE_TUPLE 1
#	else
#		define MASTER_LIBRARY_HAVE_TUPLE 0
#	endif /* #! Has include !# */
#endif /* #! tuple !# */

#ifndef MASTER_LIBRARY_HAVE_UTILITY
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("utility")
#		define MASTER_LIBRARY_HAVE_UTILITY 1
#	else
#		define MASTER_LIBRARY_HAVE_UTILITY 0
#	endif /* #! Has include !# */
#endif /* #! utility !# */

#ifndef MASTER_LIBRARY_HAVE_VARIANT
#	if MASTER_PREFER_CPP17_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("variant")
#		define MASTER_LIBRARY_HAVE_VARIANT 1
#	else
#		define MASTER_LIBRARY_HAVE_VARIANT 0
#	endif /* #! Has include !# */
#endif /* #! variant !# */

#ifndef MASTER_LIBRARY_HAVE_ARRAY
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("array")
#		define MASTER_LIBRARY_HAVE_ARRAY 1
#	else
#		define MASTER_LIBRARY_HAVE_ARRAY 0
#	endif /* #! Has include !# */
#endif /* #! array !# */

#ifndef MASTER_LIBRARY_HAVE_DEQUE
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("deque")
#		define MASTER_LIBRARY_HAVE_DEQUE 1
#	else
#		define MASTER_LIBRARY_HAVE_DEQUE 0
#	endif /* #! Has include !# */
#endif /* #! deque !# */

#ifndef MASTER_LIBRARY_HAVE_FLAT_MAP
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("flat_map")
#		define MASTER_LIBRARY_HAVE_FLAT_MAP 1
#	else
#		define MASTER_LIBRARY_HAVE_FLAT_MAP 0
#	endif /* #! Has include !# */
#endif /* #! flat_map !# */

#ifndef MASTER_LIBRARY_HAVE_FLAT_SET
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("flat_set")
#		define MASTER_LIBRARY_HAVE_FLAT_SET 1
#	else
#		define MASTER_LIBRARY_HAVE_FLAT_SET 0
#	endif /* #! Has include !# */
#endif /* #! flat_set !# */

#ifndef MASTER_LIBRARY_HAVE_FORWARD_LIST
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("forward_list")
#		define MASTER_LIBRARY_HAVE_FORWARD_LIST 1
#	else
#		define MASTER_LIBRARY_HAVE_FORWARD_LIST 0
#	endif /* #! Has include !# */
#endif /* #! forward_list !# */

#ifndef MASTER_LIBRARY_HAVE_HIVE
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("hive")
#		define MASTER_LIBRARY_HAVE_HIVE 1
#	else
#		define MASTER_LIBRARY_HAVE_HIVE 0
#	endif /* #! Has include !# */
#endif /* #! hive !# */

#ifndef MASTER_LIBRARY_HAVE_INPLACE_VECTOR
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("inplace_vector")
#		define MASTER_LIBRARY_HAVE_INPLACE_VECTOR 1
#	else
#		define MASTER_LIBRARY_HAVE_INPLACE_VECTOR 0
#	endif /* #! Has include !# */
#endif /* #! inplace_vector !# */

#ifndef MASTER_LIBRARY_HAVE_LIST
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("list")
#		define MASTER_LIBRARY_HAVE_LIST 1
#	else
#		define MASTER_LIBRARY_HAVE_LIST 0
#	endif /* #! Has include !# */
#endif /* #! list !# */

#ifndef MASTER_LIBRARY_HAVE_MAP
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("map")
#		define MASTER_LIBRARY_HAVE_MAP 1
#	else
#		define MASTER_LIBRARY_HAVE_MAP 0
#	endif /* #! Has include !# */
#endif /* #! map !# */

#ifndef MASTER_LIBRARY_HAVE_MDSPAN
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("mdspan")
#		define MASTER_LIBRARY_HAVE_MDSPAN 1
#	else
#		define MASTER_LIBRARY_HAVE_MDSPAN 0
#	endif /* #! Has include !# */
#endif /* #! mdspan !# */

#ifndef MASTER_LIBRARY_HAVE_QUEUE
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("queue")
#		define MASTER_LIBRARY_HAVE_QUEUE 1
#	else
#		define MASTER_LIBRARY_HAVE_QUEUE 0
#	endif /* #! Has include !# */
#endif /* #! queue !# */

#ifndef MASTER_LIBRARY_HAVE_SET
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("set")
#		define MASTER_LIBRARY_HAVE_SET 1
#	else
#		define MASTER_LIBRARY_HAVE_SET 0
#	endif /* #! Has include !# */
#endif /* #! set !# */

#ifndef MASTER_LIBRARY_HAVE_SPAN
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("span")
#		define MASTER_LIBRARY_HAVE_SPAN 1
#	else
#		define MASTER_LIBRARY_HAVE_SPAN 0
#	endif /* #! Has include !# */
#endif /* #! span !# */

#ifndef MASTER_LIBRARY_HAVE_STACK
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("stack")
#		define MASTER_LIBRARY_HAVE_STACK 1
#	else
#		define MASTER_LIBRARY_HAVE_STACK 0
#	endif /* #! Has include !# */
#endif /* #! stack !# */

#ifndef MASTER_LIBRARY_HAVE_UNORDERED_MAP
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("unordered_map")
#		define MASTER_LIBRARY_HAVE_UNORDERED_MAP 1
#	else
#		define MASTER_LIBRARY_HAVE_UNORDERED_MAP 0
#	endif /* #! Has include !# */
#endif /* #! unordered_map !# */

#ifndef MASTER_LIBRARY_HAVE_UNORDERED_SET
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("unordered_set")
#		define MASTER_LIBRARY_HAVE_UNORDERED_SET 1
#	else
#		define MASTER_LIBRARY_HAVE_UNORDERED_SET 0
#	endif /* #! Has include !# */
#endif /* #! unordered_set !# */

#ifndef MASTER_LIBRARY_HAVE_VECTOR
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("vector")
#		define MASTER_LIBRARY_HAVE_VECTOR 1
#	else
#		define MASTER_LIBRARY_HAVE_VECTOR 0
#	endif /* #! Has include !# */
#endif /* #! vector !# */

#ifndef MASTER_LIBRARY_HAVE_ITERATOR
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("iterator")
#		define MASTER_LIBRARY_HAVE_ITERATOR 1
#	else
#		define MASTER_LIBRARY_HAVE_ITERATOR 0
#	endif /* #! Has include !# */
#endif /* #! iterator !# */

#ifndef MASTER_LIBRARY_HAVE_GENERATOR
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("generator")
#		define MASTER_LIBRARY_HAVE_GENERATOR 1
#	else
#		define MASTER_LIBRARY_HAVE_GENERATOR 0
#	endif /* #! Has include !# */
#endif /* #! generator !# */

#ifndef MASTER_LIBRARY_HAVE_RANGES
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ranges")
#		define MASTER_LIBRARY_HAVE_RANGES 1
#	else
#		define MASTER_LIBRARY_HAVE_RANGES 0
#	endif /* #! Has include !# */
#endif /* #! ranges !# */

#ifndef MASTER_LIBRARY_HAVE_ALGORITHM
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("algorithm")
#		define MASTER_LIBRARY_HAVE_ALGORITHM 1
#	else
#		define MASTER_LIBRARY_HAVE_ALGORITHM 0
#	endif /* #! Has include !# */
#endif /* #! algorithm !# */

#ifndef MASTER_LIBRARY_HAVE_NUMERIC
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("numeric")
#		define MASTER_LIBRARY_HAVE_NUMERIC 1
#	else
#		define MASTER_LIBRARY_HAVE_NUMERIC 0
#	endif /* #! Has include !# */
#endif /* #! numeric !# */

#ifndef MASTER_LIBRARY_HAVE_CSTRING
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cstring")
#		define MASTER_LIBRARY_HAVE_CSTRING 1
#	else
#		define MASTER_LIBRARY_HAVE_CSTRING 0
#	endif /* #! Has include !# */
#endif /* #! cstring !# */

#ifndef MASTER_LIBRARY_HAVE_STRING
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("string")
#		define MASTER_LIBRARY_HAVE_STRING 1
#	else
#		define MASTER_LIBRARY_HAVE_STRING 0
#	endif /* #! Has include !# */
#endif /* #! string !# */

#ifndef MASTER_LIBRARY_HAVE_STRING_VIEW
#	if MASTER_PREFER_CPP17_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("string_view")
#		define MASTER_LIBRARY_HAVE_STRING_VIEW 1
#	else
#		define MASTER_LIBRARY_HAVE_STRING_VIEW 0
#	endif /* #! Has include !# */
#endif /* #! string_view !# */

#ifndef MASTER_LIBRARY_HAVE_CCTYPE
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cctype")
#		define MASTER_LIBRARY_HAVE_CCTYPE 1
#	else
#		define MASTER_LIBRARY_HAVE_CCTYPE 0
#	endif /* #! Has include !# */
#endif /* #! cctype !# */

#ifndef MASTER_LIBRARY_HAVE_CHARCONV
#	if MASTER_PREFER_CPP17_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("charconv")
#		define MASTER_LIBRARY_HAVE_CHARCONV 1
#	else
#		define MASTER_LIBRARY_HAVE_CHARCONV 0
#	endif /* #! Has include !# */
#endif /* #! charconv !# */

#ifndef MASTER_LIBRARY_HAVE_CLOCALE
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("clocale")
#		define MASTER_LIBRARY_HAVE_CLOCALE 1
#	else
#		define MASTER_LIBRARY_HAVE_CLOCALE 0
#	endif /* #! Has include !# */
#endif /* #! clocale !# */

#ifndef MASTER_LIBRARY_HAVE_CODECVT
#	if ((MASTER_PREFER_CPP11_SUPPORTED && (!MASTER_PREFER_CPP17_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1) && !MASTER_PREFER_CPP26_SUPPORTED)) && MASTER_COMPILER_CAN_INCLUDE("codecvt")
#		define MASTER_LIBRARY_HAVE_CODECVT 1
#	else
#		define MASTER_LIBRARY_HAVE_CODECVT 0
#	endif /* #! Has include !# */
#endif /* #! codecvt !# */

#ifndef MASTER_LIBRARY_HAVE_CUCHAR
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cuchar")
#		define MASTER_LIBRARY_HAVE_CUCHAR 1
#	else
#		define MASTER_LIBRARY_HAVE_CUCHAR 0
#	endif /* #! Has include !# */
#endif /* #! cuchar !# */

#ifndef MASTER_LIBRARY_HAVE_CWCHAR
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cwchar")
#		define MASTER_LIBRARY_HAVE_CWCHAR 1
#	else
#		define MASTER_LIBRARY_HAVE_CWCHAR 0
#	endif /* #! Has include !# */
#endif /* #! cwchar !# */

#ifndef MASTER_LIBRARY_HAVE_CWCTYPE
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cwctype")
#		define MASTER_LIBRARY_HAVE_CWCTYPE 1
#	else
#		define MASTER_LIBRARY_HAVE_CWCTYPE 0
#	endif /* #! Has include !# */
#endif /* #! cwctype !# */

#ifndef MASTER_LIBRARY_HAVE_FORMAT
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("format")
#		define MASTER_LIBRARY_HAVE_FORMAT 1
#	else
#		define MASTER_LIBRARY_HAVE_FORMAT 0
#	endif /* #! Has include !# */
#endif /* #! format !# */

#ifndef MASTER_LIBRARY_HAVE_LOCALE
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("locale")
#		define MASTER_LIBRARY_HAVE_LOCALE 1
#	else
#		define MASTER_LIBRARY_HAVE_LOCALE 0
#	endif /* #! Has include !# */
#endif /* #! locale !# */

#ifndef MASTER_LIBRARY_HAVE_REGEX
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("regex")
#		define MASTER_LIBRARY_HAVE_REGEX 1
#	else
#		define MASTER_LIBRARY_HAVE_REGEX 0
#	endif /* #! Has include !# */
#endif /* #! regex !# */

#ifndef MASTER_LIBRARY_HAVE_TEXT_ENCODING
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("text_encoding")
#		define MASTER_LIBRARY_HAVE_TEXT_ENCODING 1
#	else
#		define MASTER_LIBRARY_HAVE_TEXT_ENCODING 0
#	endif /* #! Has include !# */
#endif /* #! text_encoding !# */

#ifndef MASTER_LIBRARY_HAVE_CFENV
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cfenv")
#		define MASTER_LIBRARY_HAVE_CFENV 1
#	else
#		define MASTER_LIBRARY_HAVE_CFENV 0
#	endif /* #! Has include !# */
#endif /* #! cfenv !# */

#ifndef MASTER_LIBRARY_HAVE_CMATH
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cmath")
#		define MASTER_LIBRARY_HAVE_CMATH 1
#	else
#		define MASTER_LIBRARY_HAVE_CMATH 0
#	endif /* #! Has include !# */
#endif /* #! cmath !# */

#ifndef MASTER_LIBRARY_HAVE_COMPLEX
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("complex")
#		define MASTER_LIBRARY_HAVE_COMPLEX 1
#	else
#		define MASTER_LIBRARY_HAVE_COMPLEX 0
#	endif /* #! Has include !# */
#endif /* #! complex !# */

#ifndef MASTER_LIBRARY_HAVE_LINALG
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("linalg")
#		define MASTER_LIBRARY_HAVE_LINALG 1
#	else
#		define MASTER_LIBRARY_HAVE_LINALG 0
#	endif /* #! Has include !# */
#endif /* #! linalg !# */

#ifndef MASTER_LIBRARY_HAVE_NUMBERS
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("numbers")
#		define MASTER_LIBRARY_HAVE_NUMBERS 1
#	else
#		define MASTER_LIBRARY_HAVE_NUMBERS 0
#	endif /* #! Has include !# */
#endif /* #! numbers !# */

#ifndef MASTER_LIBRARY_HAVE_RANDOM
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("random")
#		define MASTER_LIBRARY_HAVE_RANDOM 1
#	else
#		define MASTER_LIBRARY_HAVE_RANDOM 0
#	endif /* #! Has include !# */
#endif /* #! random !# */

#ifndef MASTER_LIBRARY_HAVE_SIMD
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("simd")
#		define MASTER_LIBRARY_HAVE_SIMD 1
#	else
#		define MASTER_LIBRARY_HAVE_SIMD 0
#	endif /* #! Has include !# */
#endif /* #! simd !# */

#ifndef MASTER_LIBRARY_HAVE_VALARRAY
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("valarray")
#		define MASTER_LIBRARY_HAVE_VALARRAY 1
#	else
#		define MASTER_LIBRARY_HAVE_VALARRAY 0
#	endif /* #! Has include !# */
#endif /* #! valarray !# */

#ifndef MASTER_LIBRARY_HAVE_CHRONO
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("chrono")
#		define MASTER_LIBRARY_HAVE_CHRONO 1
#	else
#		define MASTER_LIBRARY_HAVE_CHRONO 0
#	endif /* #! Has include !# */
#endif /* #! chrono !# */

#ifndef MASTER_LIBRARY_HAVE_CTIME
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ctime")
#		define MASTER_LIBRARY_HAVE_CTIME 1
#	else
#		define MASTER_LIBRARY_HAVE_CTIME 0
#	endif /* #! Has include !# */
#endif /* #! ctime !# */

#ifndef MASTER_LIBRARY_HAVE_CINTTYPES
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cinttypes")
#		define MASTER_LIBRARY_HAVE_CINTTYPES 1
#	else
#		define MASTER_LIBRARY_HAVE_CINTTYPES 0
#	endif /* #! Has include !# */
#endif /* #! cinttypes !# */

#ifndef MASTER_LIBRARY_HAVE_CSTDIO
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("cstdio")
#		define MASTER_LIBRARY_HAVE_CSTDIO 1
#	else
#		define MASTER_LIBRARY_HAVE_CSTDIO 0
#	endif /* #! Has include !# */
#endif /* #! cstdio !# */

#ifndef MASTER_LIBRARY_HAVE_FILESYSTEM
#	if MASTER_PREFER_CPP17_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("filesystem")
#		define MASTER_LIBRARY_HAVE_FILESYSTEM 1
#	else
#		define MASTER_LIBRARY_HAVE_FILESYSTEM 0
#	endif /* #! Has include !# */
#endif /* #! filesystem !# */

#ifndef MASTER_LIBRARY_HAVE_FSTREAM
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("fstream")
#		define MASTER_LIBRARY_HAVE_FSTREAM 1
#	else
#		define MASTER_LIBRARY_HAVE_FSTREAM 0
#	endif /* #! Has include !# */
#endif /* #! fstream !# */

#ifndef MASTER_LIBRARY_HAVE_IOMANIP
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("iomanip")
#		define MASTER_LIBRARY_HAVE_IOMANIP 1
#	else
#		define MASTER_LIBRARY_HAVE_IOMANIP 0
#	endif /* #! Has include !# */
#endif /* #! iomanip !# */

#ifndef MASTER_LIBRARY_HAVE_IOS
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ios")
#		define MASTER_LIBRARY_HAVE_IOS 1
#	else
#		define MASTER_LIBRARY_HAVE_IOS 0
#	endif /* #! Has include !# */
#endif /* #! ios !# */

#ifndef MASTER_LIBRARY_HAVE_IOSFWD
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("iosfwd")
#		define MASTER_LIBRARY_HAVE_IOSFWD 1
#	else
#		define MASTER_LIBRARY_HAVE_IOSFWD 0
#	endif /* #! Has include !# */
#endif /* #! iosfwd !# */

#ifndef MASTER_LIBRARY_HAVE_IOSTREAM
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("iostream")
#		define MASTER_LIBRARY_HAVE_IOSTREAM 1
#	else
#		define MASTER_LIBRARY_HAVE_IOSTREAM 0
#	endif /* #! Has include !# */
#endif /* #! iostream !# */

#ifndef MASTER_LIBRARY_HAVE_ISTREAM
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("istream")
#		define MASTER_LIBRARY_HAVE_ISTREAM 1
#	else
#		define MASTER_LIBRARY_HAVE_ISTREAM 0
#	endif /* #! Has include !# */
#endif /* #! istream !# */

#ifndef MASTER_LIBRARY_HAVE_OSTREAM
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("ostream")
#		define MASTER_LIBRARY_HAVE_OSTREAM 1
#	else
#		define MASTER_LIBRARY_HAVE_OSTREAM 0
#	endif /* #! Has include !# */
#endif /* #! ostream !# */

#ifndef MASTER_LIBRARY_HAVE_PRINT
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("print")
#		define MASTER_LIBRARY_HAVE_PRINT 1
#	else
#		define MASTER_LIBRARY_HAVE_PRINT 0
#	endif /* #! Has include !# */
#endif /* #! print !# */

#ifndef MASTER_LIBRARY_HAVE_SPANSTREAM
#	if MASTER_PREFER_CPP23_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("spanstream")
#		define MASTER_LIBRARY_HAVE_SPANSTREAM 1
#	else
#		define MASTER_LIBRARY_HAVE_SPANSTREAM 0
#	endif /* #! Has include !# */
#endif /* #! spanstream !# */

#ifndef MASTER_LIBRARY_HAVE_SSTREAM
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("sstream")
#		define MASTER_LIBRARY_HAVE_SSTREAM 1
#	else
#		define MASTER_LIBRARY_HAVE_SSTREAM 0
#	endif /* #! Has include !# */
#endif /* #! sstream !# */

#ifndef MASTER_LIBRARY_HAVE_STREAMBUF
#	if MASTER_PREFER_CPP98_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("streambuf")
#		define MASTER_LIBRARY_HAVE_STREAMBUF 1
#	else
#		define MASTER_LIBRARY_HAVE_STREAMBUF 0
#	endif /* #! Has include !# */
#endif /* #! streambuf !# */

#ifndef MASTER_LIBRARY_HAVE_STRSTREAM
#	if ((MASTER_PREFER_CPP98_SUPPORTED && (!MASTER_PREFER_CPP98_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1) && !MASTER_PREFER_CPP26_SUPPORTED)) && MASTER_COMPILER_CAN_INCLUDE("strstream")
#		define MASTER_LIBRARY_HAVE_STRSTREAM 1
#	else
#		define MASTER_LIBRARY_HAVE_STRSTREAM 0
#	endif /* #! Has include !# */
#endif /* #! strstream !# */

#ifndef MASTER_LIBRARY_HAVE_SYNCSTREAM
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("syncstream")
#		define MASTER_LIBRARY_HAVE_SYNCSTREAM 1
#	else
#		define MASTER_LIBRARY_HAVE_SYNCSTREAM 0
#	endif /* #! Has include !# */
#endif /* #! syncstream !# */

#ifndef MASTER_LIBRARY_HAVE_ATOMIC
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("atomic")
#		define MASTER_LIBRARY_HAVE_ATOMIC 1
#	else
#		define MASTER_LIBRARY_HAVE_ATOMIC 0
#	endif /* #! Has include !# */
#endif /* #! atomic !# */

#ifndef MASTER_LIBRARY_HAVE_BARRIER
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("barrier")
#		define MASTER_LIBRARY_HAVE_BARRIER 1
#	else
#		define MASTER_LIBRARY_HAVE_BARRIER 0
#	endif /* #! Has include !# */
#endif /* #! barrier !# */

#ifndef MASTER_LIBRARY_HAVE_CONDITION_VARIABLE
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("condition_variable")
#		define MASTER_LIBRARY_HAVE_CONDITION_VARIABLE 1
#	else
#		define MASTER_LIBRARY_HAVE_CONDITION_VARIABLE 0
#	endif /* #! Has include !# */
#endif /* #! condition_variable !# */

#ifndef MASTER_LIBRARY_HAVE_FUTURE
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("future")
#		define MASTER_LIBRARY_HAVE_FUTURE 1
#	else
#		define MASTER_LIBRARY_HAVE_FUTURE 0
#	endif /* #! Has include !# */
#endif /* #! future !# */

#ifndef MASTER_LIBRARY_HAVE_HAZARD_POINTER
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("hazard_pointer")
#		define MASTER_LIBRARY_HAVE_HAZARD_POINTER 1
#	else
#		define MASTER_LIBRARY_HAVE_HAZARD_POINTER 0
#	endif /* #! Has include !# */
#endif /* #! hazard_pointer !# */

#ifndef MASTER_LIBRARY_HAVE_LATCH
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("latch")
#		define MASTER_LIBRARY_HAVE_LATCH 1
#	else
#		define MASTER_LIBRARY_HAVE_LATCH 0
#	endif /* #! Has include !# */
#endif /* #! latch !# */

#ifndef MASTER_LIBRARY_HAVE_MUTEX
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("mutex")
#		define MASTER_LIBRARY_HAVE_MUTEX 1
#	else
#		define MASTER_LIBRARY_HAVE_MUTEX 0
#	endif /* #! Has include !# */
#endif /* #! mutex !# */

#ifndef MASTER_LIBRARY_HAVE_RCU
#	if MASTER_PREFER_CPP26_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("rcu")
#		define MASTER_LIBRARY_HAVE_RCU 1
#	else
#		define MASTER_LIBRARY_HAVE_RCU 0
#	endif /* #! Has include !# */
#endif /* #! rcu !# */

#ifndef MASTER_LIBRARY_HAVE_SEMAPHORE
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("semaphore")
#		define MASTER_LIBRARY_HAVE_SEMAPHORE 1
#	else
#		define MASTER_LIBRARY_HAVE_SEMAPHORE 0
#	endif /* #! Has include !# */
#endif /* #! semaphore !# */

#ifndef MASTER_LIBRARY_HAVE_SHARED_MUTEX
#	if MASTER_PREFER_CPP14_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("shared_mutex")
#		define MASTER_LIBRARY_HAVE_SHARED_MUTEX 1
#	else
#		define MASTER_LIBRARY_HAVE_SHARED_MUTEX 0
#	endif /* #! Has include !# */
#endif /* #! shared_mutex !# */

#ifndef MASTER_LIBRARY_HAVE_STOP_TOKEN
#	if MASTER_PREFER_CPP20_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("stop_token")
#		define MASTER_LIBRARY_HAVE_STOP_TOKEN 1
#	else
#		define MASTER_LIBRARY_HAVE_STOP_TOKEN 0
#	endif /* #! Has include !# */
#endif /* #! stop_token !# */

#ifndef MASTER_LIBRARY_HAVE_THREAD
#	if MASTER_PREFER_CPP11_SUPPORTED && MASTER_COMPILER_CAN_INCLUDE("thread")
#		define MASTER_LIBRARY_HAVE_THREAD 1
#	else
#		define MASTER_LIBRARY_HAVE_THREAD 0
#	endif /* #! Has include !# */
#endif /* #! thread !# */

#ifndef MASTER_LIBRARY_HAVE_CCOMPLEX
#	if ((MASTER_PREFER_CPP11_SUPPORTED && (!MASTER_PREFER_CPP17_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1) && !MASTER_PREFER_CPP20_SUPPORTED)) && MASTER_COMPILER_CAN_INCLUDE("ccomplex")
#		define MASTER_LIBRARY_HAVE_CCOMPLEX 1
#	else
#		define MASTER_LIBRARY_HAVE_CCOMPLEX 0
#	endif /* #! Has include !# */
#endif /* #! ccomplex !# */

#ifndef MASTER_LIBRARY_HAVE_CTGMATH
#	if ((MASTER_PREFER_CPP11_SUPPORTED && (!MASTER_PREFER_CPP17_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1) && !MASTER_PREFER_CPP20_SUPPORTED)) && MASTER_COMPILER_CAN_INCLUDE("ctgmath")
#		define MASTER_LIBRARY_HAVE_CTGMATH 1
#	else
#		define MASTER_LIBRARY_HAVE_CTGMATH 0
#	endif /* #! Has include !# */
#endif /* #! ctgmath !# */

#ifndef MASTER_LIBRARY_HAVE_CISO646
#	if (MASTER_PREFER_CPP98_SUPPORTED && !MASTER_PREFER_CPP20_SUPPORTED) && MASTER_COMPILER_CAN_INCLUDE("ciso646")
#		define MASTER_LIBRARY_HAVE_CISO646 1
#	else
#		define MASTER_LIBRARY_HAVE_CISO646 0
#	endif /* #! Has include !# */
#endif /* #! ciso646 !# */

#ifndef MASTER_LIBRARY_HAVE_CSTDALIGN
#	if ((MASTER_PREFER_CPP11_SUPPORTED && (!MASTER_PREFER_CPP17_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1) && !MASTER_PREFER_CPP20_SUPPORTED)) && MASTER_COMPILER_CAN_INCLUDE("cstdalign")
#		define MASTER_LIBRARY_HAVE_CSTDALIGN 1
#	else
#		define MASTER_LIBRARY_HAVE_CSTDALIGN 0
#	endif /* #! Has include !# */
#endif /* #! cstdalign !# */

#ifndef MASTER_LIBRARY_HAVE_CSTDBOOL
#	if ((MASTER_PREFER_CPP11_SUPPORTED && (!MASTER_PREFER_CPP17_SUPPORTED || MASTER_LIBRARY_INCLUDE_DEPRECATED == 1) && !MASTER_PREFER_CPP20_SUPPORTED)) && MASTER_COMPILER_CAN_INCLUDE("cstdbool")
#		define MASTER_LIBRARY_HAVE_CSTDBOOL 1
#	else
#		define MASTER_LIBRARY_HAVE_CSTDBOOL 0
#	endif /* #! Has include !# */
#endif /* #! cstdbool !# */

/* #! Total Include !# */

#if MASTER_LIBRARY_HAVE_DOS_H == 1
#	include <dos.h>
#endif /* #! dos.h !# */

#if MASTER_LIBRARY_HAVE_AIO_H == 1
#	include <aio.h>
#endif /* #! aio.h !# */

#if MASTER_LIBRARY_HAVE_ARPA_INET_H == 1
#	include <arpa/inet.h>
#endif /* #! arpa/inet.h !# */

#if MASTER_LIBRARY_HAVE_CPIO_H == 1
#	include <cpio.h>
#endif /* #! cpio.h !# */

#if MASTER_LIBRARY_HAVE_DEVCTL_H == 1
#	include <devctl.h>
#endif /* #! devctl.h !# */

#if MASTER_LIBRARY_HAVE_DIRENT_H == 1
#	include <dirent.h>
#endif /* #! dirent.h !# */

#if MASTER_LIBRARY_HAVE_DLFCN_H == 1
#	include <dlfcn.h>
#endif /* #! dlfcn.h !# */

#if MASTER_LIBRARY_HAVE_ENDIAN_H == 1
#	include <endian.h>
#endif /* #! endian.h !# */

#if MASTER_LIBRARY_HAVE_FCNTL_H == 1
#	include <fcntl.h>
#endif /* #! fcntl.h !# */

#if MASTER_LIBRARY_HAVE_FMTMSG_H == 1
#	include <fmtmsg.h>
#endif /* #! fmtmsg.h !# */

#if MASTER_LIBRARY_HAVE_FNMATCH_H == 1
#	include <fnmatch.h>
#endif /* #! fnmatch.h !# */

#if MASTER_LIBRARY_HAVE_FTW_H == 1
#	include <ftw.h>
#endif /* #! ftw.h !# */

#if MASTER_LIBRARY_HAVE_GLOB_H == 1
#	include <glob.h>
#endif /* #! glob.h !# */

#if MASTER_LIBRARY_HAVE_GRP_H == 1
#	include <grp.h>
#endif /* #! grp.h !# */

#if MASTER_LIBRARY_HAVE_ICONV_H == 1
#	include <iconv.h>
#endif /* #! iconv.h !# */

#if MASTER_LIBRARY_HAVE_LANGINFO_H == 1
#	include <langinfo.h>
#endif /* #! langinfo.h !# */

#if MASTER_LIBRARY_HAVE_LIBGEN_H == 1
#	include <libgen.h>
#endif /* #! libgen.h !# */

#if MASTER_LIBRARY_HAVE_LIBINTL_H == 1
#	include <libintl.h>
#endif /* #! libintl.h !# */

#if MASTER_LIBRARY_HAVE_MONETARY_H == 1
#	include <monetary.h>
#endif /* #! monetary.h !# */

#if MASTER_LIBRARY_HAVE_MQUEUE_H == 1
#	include <mqueue.h>
#endif /* #! mqueue.h !# */

#if MASTER_LIBRARY_HAVE_NDBM_H == 1
#	include <ndbm.h>
#endif /* #! ndbm.h !# */

#if MASTER_LIBRARY_HAVE_NET_IF_H == 1
#	include <net/if.h>
#endif /* #! net/if.h !# */

#if MASTER_LIBRARY_HAVE_NETDB_H == 1
#	include <netdb.h>
#endif /* #! netdb.h !# */

#if MASTER_LIBRARY_HAVE_NETINET_IN_H == 1
#	include <netinet/in.h>
#endif /* #! netinet/in.h !# */

#if MASTER_LIBRARY_HAVE_NETINET_TCP_H == 1
#	include <netinet/tcp.h>
#endif /* #! netinet/tcp.h !# */

#if MASTER_LIBRARY_HAVE_NL_TYPES_H == 1
#	include <nl_types.h>
#endif /* #! nl_types.h !# */

#if MASTER_LIBRARY_HAVE_POLL_H == 1
#	include <poll.h>
#endif /* #! poll.h !# */

#if MASTER_LIBRARY_HAVE_PTHREAD_H == 1
#	include <pthread.h>
#endif /* #! pthread.h !# */

#if MASTER_LIBRARY_HAVE_PWD_H == 1
#	include <pwd.h>
#endif /* #! pwd.h !# */

#if MASTER_LIBRARY_HAVE_REGEX_H == 1
#	include <regex.h>
#endif /* #! regex.h !# */

#if MASTER_LIBRARY_HAVE_SCHED_H == 1
#	include <sched.h>
#endif /* #! sched.h !# */

#if MASTER_LIBRARY_HAVE_SEARCH_H == 1
#	include <search.h>
#endif /* #! search.h !# */

#if MASTER_LIBRARY_HAVE_SEMAPHORE_H == 1
#	include <semaphore.h>
#endif /* #! semaphore.h !# */

#if MASTER_LIBRARY_HAVE_SPAWN_H == 1
#	include <spawn.h>
#endif /* #! spawn.h !# */

#if MASTER_LIBRARY_HAVE_STDALIGN_H == 1
#	include <stdalign.h>
#endif /* #! stdalign.h !# */

#if MASTER_LIBRARY_HAVE_STRINGS_H == 1
#	include <strings.h>
#endif /* #! strings.h !# */

#if MASTER_LIBRARY_HAVE_STROPTS_H == 1
#	include <stropts.h>
#endif /* #! stropts.h !# */

#if MASTER_LIBRARY_HAVE_SYS_IPC_H == 1
#	include <sys/ipc.h>
#endif /* #! sys/ipc.h !# */

#if MASTER_LIBRARY_HAVE_SYS_MMAN_H == 1
#	include <sys/mman.h>
#endif /* #! sys/mman.h !# */

#if MASTER_LIBRARY_HAVE_SYS_MSG_H == 1
#	include <sys/msg.h>
#endif /* #! sys/msg.h !# */

#if MASTER_LIBRARY_HAVE_SYS_RESOURCE_H == 1
#	include <sys/resource.h>
#endif /* #! sys/resource.h !# */

#if MASTER_LIBRARY_HAVE_SYS_SELECT_H == 1
#	include <sys/select.h>
#endif /* #! sys/select.h !# */

#if MASTER_LIBRARY_HAVE_SYS_SEM_H == 1
#	include <sys/sem.h>
#endif /* #! sys/sem.h !# */

#if MASTER_LIBRARY_HAVE_SYS_SHM_H == 1
#	include <sys/shm.h>
#endif /* #! sys/shm.h !# */

#if MASTER_LIBRARY_HAVE_SYS_SOCKET_H == 1
#	include <sys/socket.h>
#endif /* #! sys/socket.h !# */

#if MASTER_LIBRARY_HAVE_SYS_STAT_H == 1
#	include <sys/stat.h>
#endif /* #! sys/stat.h !# */

#if MASTER_LIBRARY_HAVE_SYS_STATVFS_H == 1
#	include <sys/statvfs.h>
#endif /* #! sys/statvfs.h !# */

#if MASTER_LIBRARY_HAVE_SYS_TIME_H == 1
#	include <sys/time.h>
#endif /* #! sys/time.h !# */

#if MASTER_LIBRARY_HAVE_SYS_TIMES_H == 1
#	include <sys/times.h>
#endif /* #! sys/times.h !# */

#if MASTER_LIBRARY_HAVE_SYS_TYPES_H == 1
#	include <sys/types.h>
#endif /* #! sys/types.h !# */

#if MASTER_LIBRARY_HAVE_SYS_UIO_H == 1
#	include <sys/uio.h>
#endif /* #! sys/uio.h !# */

#if MASTER_LIBRARY_HAVE_SYS_UN_H == 1
#	include <sys/un.h>
#endif /* #! sys/un.h !# */

#if MASTER_LIBRARY_HAVE_SYS_UTSNAME_H == 1
#	include <sys/utsname.h>
#endif /* #! sys/utsname.h !# */

#if MASTER_LIBRARY_HAVE_SYS_WAIT_H == 1
#	include <sys/wait.h>
#endif /* #! sys/wait.h !# */

#if MASTER_LIBRARY_HAVE_SYSLOG_H == 1
#	include <syslog.h>
#endif /* #! syslog.h !# */

#if MASTER_LIBRARY_HAVE_TAR_H == 1
#	include <tar.h>
#endif /* #! tar.h !# */

#if MASTER_LIBRARY_HAVE_TERMIOS_H == 1
#	include <termios.h>
#endif /* #! termios.h !# */

#if MASTER_LIBRARY_HAVE_TRACE_H == 1
#	include <trace.h>
#endif /* #! trace.h !# */

#if MASTER_LIBRARY_HAVE_UCONTEXT_H == 1
#	include <ucontext.h>
#endif /* #! ucontext.h !# */

#if MASTER_LIBRARY_HAVE_ULIMIT_H == 1
#	include <ulimit.h>
#endif /* #! ulimit.h !# */

#if MASTER_LIBRARY_HAVE_UTIME_H == 1
#	include <utime.h>
#endif /* #! utime.h !# */

#if MASTER_LIBRARY_HAVE_UTMPX_H == 1
#	include <utmpx.h>
#endif /* #! utmpx.h !# */

#if MASTER_LIBRARY_HAVE_WORDEXP_H == 1
#	include <wordexp.h>
#endif /* #! wordexp.h !# */

#if MASTER_LIBRARY_HAVE_WINDOWS_H == 1
#	include <windows.h>
#endif /* #! windows.h !# */

#if MASTER_LIBRARY_HAVE_CONIO_H == 1
#	include <conio.h>
#endif /* #! conio.h !# */

#if MASTER_LIBRARY_HAVE_BASETSD_H == 1
#	include <basetsd.h>
#endif /* #! basetsd.h !# */

#if MASTER_LIBRARY_HAVE_GUIDDEF_H == 1
#	include <guiddef.h>
#endif /* #! guiddef.h !# */

#if MASTER_LIBRARY_HAVE_IMM_H == 1
#	include <imm.h>
#endif /* #! imm.h !# */

#if MASTER_LIBRARY_HAVE_WINBASE_H == 1
#	include <winbase.h>
#endif /* #! winbase.h !# */

#if MASTER_LIBRARY_HAVE_WINCON_H == 1
#	include <wincon.h>
#endif /* #! wincon.h !# */

#if MASTER_LIBRARY_HAVE_WINDEF_H == 1
#	include <windef.h>
#endif /* #! windef.h !# */

#if MASTER_LIBRARY_HAVE_WINERROR_H == 1
#	include <winerror.h>
#endif /* #! winerror.h !# */

#if MASTER_LIBRARY_HAVE_WINGDI_H == 1
#	include <wingdi.h>
#endif /* #! wingdi.h !# */

#if MASTER_LIBRARY_HAVE_WINNETWK_H == 1
#	include <winnetwk.h>
#endif /* #! winnetwk.h !# */

#if MASTER_LIBRARY_HAVE_WINNLS_H == 1
#	include <winnls.h>
#endif /* #! winnls.h !# */

#if MASTER_LIBRARY_HAVE_WINNT_H == 1
#	include <winnt.h>
#endif /* #! winnt.h !# */

#if MASTER_LIBRARY_HAVE_WINREG_H == 1
#	include <winreg.h>
#endif /* #! winreg.h !# */

#if MASTER_LIBRARY_HAVE_WINSVC_H == 1
#	include <winsvc.h>
#endif /* #! winsvc.h !# */

#if MASTER_LIBRARY_HAVE_WINUSER_H == 1
#	include <winuser.h>
#endif /* #! winuser.h !# */

#if MASTER_LIBRARY_HAVE_WINVER_H == 1
#	include <winver.h>
#endif /* #! winver.h !# */

#if MASTER_LIBRARY_HAVE_CDERR_H == 1
#	include <cderr.h>
#endif /* #! cderr.h !# */

#if MASTER_LIBRARY_HAVE_COMMLDG_H == 1
#	include <commldg.h>
#endif /* #! commldg.h !# */

#if MASTER_LIBRARY_HAVE_DDE_H == 1
#	include <dde.h>
#endif /* #! dde.h !# */

#if MASTER_LIBRARY_HAVE_DDEML_H == 1
#	include <ddeml.h>
#endif /* #! ddeml.h !# */

#if MASTER_LIBRARY_HAVE_DLGS_H == 1
#	include <dlgs.h>
#endif /* #! dlgs.h !# */

#if MASTER_LIBRARY_HAVE_LZEXPAND_H == 1
#	include <lzexpand.h>
#endif /* #! lzexpand.h !# */

#if MASTER_LIBRARY_HAVE_MMSYSTEM_H == 1
#	include <mmsystem.h>
#endif /* #! mmsystem.h !# */

#if MASTER_LIBRARY_HAVE_NB3MASTER_ANSWER_N_H == 1
#	include <nb3master/answer/n.h>
#endif /* #! nb3master/answer/n.h !# */

#if MASTER_LIBRARY_HAVE_RPC_H == 1
#	include <rpc.h>
#endif /* #! rpc.h !# */

#if MASTER_LIBRARY_HAVE_SHELLAPI_H == 1
#	include <shellapi.h>
#endif /* #! shellapi.h !# */

#if MASTER_LIBRARY_HAVE_WINCRYPT_H == 1
#	include <wincrypt.h>
#endif /* #! wincrypt.h !# */

#if MASTER_LIBRARY_HAVE_WINPERF_H == 1
#	include <winperf.h>
#endif /* #! winperf.h !# */

#if MASTER_LIBRARY_HAVE_WINRESRC_H == 1
#	include <winresrc.h>
#endif /* #! winresrc.h !# */

#if MASTER_LIBRARY_HAVE_WINSOCK_H == 1
#	include <winsock.h>
#endif /* #! winsock.h !# */

#if MASTER_LIBRARY_HAVE_WINSPOOL_H == 1
#	include <winspool.h>
#endif /* #! winspool.h !# */

#if MASTER_LIBRARY_HAVE_WINBGIM_H == 1
#	include <winbgim.h>
#endif /* #! winbgim.h !# */

#if MASTER_LIBRARY_HAVE_OLE2_H == 1
#	include <ole2.h>
#endif /* #! ole2.h !# */

#if MASTER_LIBRARY_HAVE_OBJBASE_H == 1
#	include <objbase.h>
#endif /* #! objbase.h !# */

#if MASTER_LIBRARY_HAVE_OLEAUTO_H == 1
#	include <oleauto.h>
#endif /* #! oleauto.h !# */

#if MASTER_LIBRARY_HAVE_OLETLID_H == 1
#	include <oletlid.h>
#endif /* #! oletlid.h !# */

#if MASTER_LIBRARY_HAVE_ASSERT_H == 1
#	include <assert.h>
#endif /* #! assert.h !# */

#if MASTER_LIBRARY_HAVE_COMPLEX_H == 1
#	include <complex.h>
#endif /* #! complex.h !# */

#if MASTER_LIBRARY_HAVE_CTYPE_H == 1
#	include <ctype.h>
#endif /* #! ctype.h !# */

#if MASTER_LIBRARY_HAVE_ERRNO_H == 1
#	include <errno.h>
#endif /* #! errno.h !# */

#if MASTER_LIBRARY_HAVE_FENV_H == 1
#	include <fenv.h>
#endif /* #! fenv.h !# */

#if MASTER_LIBRARY_HAVE_FLOAT_H == 1
#	include <float.h>
#endif /* #! float.h !# */

#if MASTER_LIBRARY_HAVE_INTTYPES_H == 1
#	include <inttypes.h>
#endif /* #! inttypes.h !# */

#if MASTER_LIBRARY_HAVE_ISO646_H == 1
#	include <iso646.h>
#endif /* #! iso646.h !# */

#if MASTER_LIBRARY_HAVE_LIMITS_H == 1
#	include <limits.h>
#endif /* #! limits.h !# */

#if MASTER_LIBRARY_HAVE_LOCALE_H == 1
#	include <locale.h>
#endif /* #! locale.h !# */

#if MASTER_LIBRARY_HAVE_MATH_H == 1
#	include <math.h>
#endif /* #! math.h !# */

#if MASTER_LIBRARY_HAVE_SETJMP_H == 1
#	include <setjmp.h>
#endif /* #! setjmp.h !# */

#if MASTER_LIBRARY_HAVE_SIGNAL_H == 1
#	include <signal.h>
#endif /* #! signal.h !# */

#if MASTER_LIBRARY_HAVE_STDARG_H == 1
#	include <stdarg.h>
#endif /* #! stdarg.h !# */

#if MASTER_LIBRARY_HAVE_STDATOMIC_H == 1
#	include <stdatomic.h>
#endif /* #! stdatomic.h !# */

#if MASTER_LIBRARY_HAVE_STDBIT_H == 1
#	include <stdbit.h>
#endif /* #! stdbit.h !# */

#if MASTER_LIBRARY_HAVE_STDBOOL_H == 1
#	include <stdbool.h>
#endif /* #! stdbool.h !# */

#if MASTER_LIBRARY_HAVE_STDCKDINT_H == 1
#	include <stdckdint.h>
#endif /* #! stdckdint.h !# */

#if MASTER_LIBRARY_HAVE_STDDEF_H == 1
#	include <stddef.h>
#endif /* #! stddef.h !# */

#if MASTER_LIBRARY_HAVE_STDINT_H == 1
#	include <stdint.h>
#endif /* #! stdint.h !# */

#if MASTER_LIBRARY_HAVE_STDIO_H == 1
#	include <stdio.h>
#endif /* #! stdio.h !# */

#if MASTER_LIBRARY_HAVE_STDLIB_H == 1
#	include <stdlib.h>
#endif /* #! stdlib.h !# */

#if MASTER_LIBRARY_HAVE_STDMCHAR_H == 1
#	include <stdmchar.h>
#endif /* #! stdmchar.h !# */

#if MASTER_LIBRARY_HAVE_STDNORETURN_H == 1
#	include <stdnoreturn.h>
#endif /* #! stdnoreturn.h !# */

#if MASTER_LIBRARY_HAVE_STRING_H == 1
#	include <string.h>
#endif /* #! string.h !# */

#if MASTER_LIBRARY_HAVE_TGMATH_H == 1
#	include <tgmath.h>
#endif /* #! tgmath.h !# */

#if MASTER_LIBRARY_HAVE_THREADS_H == 1
#	include <threads.h>
#endif /* #! threads.h !# */

#if MASTER_LIBRARY_HAVE_TIME_H == 1
#	include <time.h>
#endif /* #! time.h !# */

#if MASTER_LIBRARY_HAVE_UCHAR_H == 1
#	include <uchar.h>
#endif /* #! uchar.h !# */

#if MASTER_LIBRARY_HAVE_WCHAR_H == 1
#	include <wchar.h>
#endif /* #! wchar.h !# */

#if MASTER_LIBRARY_HAVE_WCTYPE_H == 1
#	include <wctype.h>
#endif /* #! wctype.h !# */

#if MASTER_LIBRARY_HAVE_CSTDLIB == 1
#	include <cstdlib>
#endif /* #! cstdlib !# */

#if MASTER_LIBRARY_HAVE_EXECUTION == 1
#	include <execution>
#endif /* #! execution !# */

#if MASTER_LIBRARY_HAVE_CFLOAT == 1
#	include <cfloat>
#endif /* #! cfloat !# */

#if MASTER_LIBRARY_HAVE_CLIMITS == 1
#	include <climits>
#endif /* #! climits !# */

#if MASTER_LIBRARY_HAVE_COMPARE == 1
#	include <compare>
#endif /* #! compare !# */

#if MASTER_LIBRARY_HAVE_CONTRACTS == 1
#	include <contracts>
#endif /* #! contracts !# */

#if MASTER_LIBRARY_HAVE_COROUTINE == 1
#	include <coroutine>
#endif /* #! coroutine !# */

#if MASTER_LIBRARY_HAVE_CSETJMP == 1
#	include <csetjmp>
#endif /* #! csetjmp !# */

#if MASTER_LIBRARY_HAVE_CSIGNAL == 1
#	include <csignal>
#endif /* #! csignal !# */

#if MASTER_LIBRARY_HAVE_CSTDARG == 1
#	include <cstdarg>
#endif /* #! cstdarg !# */

#if MASTER_LIBRARY_HAVE_CSTDDEF == 1
#	include <cstddef>
#endif /* #! cstddef !# */

#if MASTER_LIBRARY_HAVE_CSTDINT == 1
#	include <cstdint>
#endif /* #! cstdint !# */

#if MASTER_LIBRARY_HAVE_EXCEPTION == 1
#	include <exception>
#endif /* #! exception !# */

#if MASTER_LIBRARY_HAVE_INITIALIZER_LIST == 1
#	include <initializer_list>
#endif /* #! initializer_list !# */

#if MASTER_LIBRARY_HAVE_LIMITS == 1
#	include <limits>
#endif /* #! limits !# */

#if MASTER_LIBRARY_HAVE_NEW == 1
#	include <new>
#endif /* #! new !# */

#if MASTER_LIBRARY_HAVE_SOURCE_LOCATION == 1
#	include <source_location>
#endif /* #! source_location !# */

#if MASTER_LIBRARY_HAVE_STDFLOAT == 1
#	include <stdfloat>
#endif /* #! stdfloat !# */

#if MASTER_LIBRARY_HAVE_TYPEINDEX == 1
#	include <typeindex>
#endif /* #! typeindex !# */

#if MASTER_LIBRARY_HAVE_TYPEINFO == 1
#	include <typeinfo>
#endif /* #! typeinfo !# */

#if MASTER_LIBRARY_HAVE_VERSION == 1
#	include <version>
#endif /* #! version !# */

#if MASTER_LIBRARY_HAVE_CONCEPTS == 1
#	include <concepts>
#endif /* #! concepts !# */

#if MASTER_LIBRARY_HAVE_CASSERT == 1
#	include <cassert>
#endif /* #! cassert !# */

#if MASTER_LIBRARY_HAVE_CERRNO == 1
#	include <cerrno>
#endif /* #! cerrno !# */

#if MASTER_LIBRARY_HAVE_DEBUGGING == 1
#	include <debugging>
#endif /* #! debugging !# */

#if MASTER_LIBRARY_HAVE_STACKTRACE == 1
#	include <stacktrace>
#endif /* #! stacktrace !# */

#if MASTER_LIBRARY_HAVE_STDEXCEPT == 1
#	include <stdexcept>
#endif /* #! stdexcept !# */

#if MASTER_LIBRARY_HAVE_SYSTEM_ERROR == 1
#	include <system_error>
#endif /* #! system_error !# */

#if MASTER_LIBRARY_HAVE_MEMORY == 1
#	include <memory>
#endif /* #! memory !# */

#if MASTER_LIBRARY_HAVE_MEMORY_RESOURCE == 1
#	include <memory_resource>
#endif /* #! memory_resource !# */

#if MASTER_LIBRARY_HAVE_SCOPED_ALLOCATOR == 1
#	include <scoped_allocator>
#endif /* #! scoped_allocator !# */

#if MASTER_LIBRARY_HAVE_RATIO == 1
#	include <ratio>
#endif /* #! ratio !# */

#if MASTER_LIBRARY_HAVE_TYPE_TRAITS == 1
#	include <type_traits>
#endif /* #! type_traits !# */

#if MASTER_LIBRARY_HAVE_ANY == 1
#	include <any>
#endif /* #! any !# */

#if MASTER_LIBRARY_HAVE_BIT == 1
#	include <bit>
#endif /* #! bit !# */

#if MASTER_LIBRARY_HAVE_BITSET == 1
#	include <bitset>
#endif /* #! bitset !# */

#if MASTER_LIBRARY_HAVE_EXPECTED == 1
#	include <expected>
#endif /* #! expected !# */

#if MASTER_LIBRARY_HAVE_FUNCTIONAL == 1
#	include <functional>
#endif /* #! functional !# */

#if MASTER_LIBRARY_HAVE_OPTIONAL == 1
#	include <optional>
#endif /* #! optional !# */

#if MASTER_LIBRARY_HAVE_TUPLE == 1
#	include <tuple>
#endif /* #! tuple !# */

#if MASTER_LIBRARY_HAVE_UTILITY == 1
#	include <utility>
#endif /* #! utility !# */

#if MASTER_LIBRARY_HAVE_VARIANT == 1
#	include <variant>
#endif /* #! variant !# */

#if MASTER_LIBRARY_HAVE_ARRAY == 1
#	include <array>
#endif /* #! array !# */

#if MASTER_LIBRARY_HAVE_DEQUE == 1
#	include <deque>
#endif /* #! deque !# */

#if MASTER_LIBRARY_HAVE_FLAT_MAP == 1
#	include <flat_map>
#endif /* #! flat_map !# */

#if MASTER_LIBRARY_HAVE_FLAT_SET == 1
#	include <flat_set>
#endif /* #! flat_set !# */

#if MASTER_LIBRARY_HAVE_FORWARD_LIST == 1
#	include <forward_list>
#endif /* #! forward_list !# */

#if MASTER_LIBRARY_HAVE_HIVE == 1
#	include <hive>
#endif /* #! hive !# */

#if MASTER_LIBRARY_HAVE_INPLACE_VECTOR == 1
#	include <inplace_vector>
#endif /* #! inplace_vector !# */

#if MASTER_LIBRARY_HAVE_LIST == 1
#	include <list>
#endif /* #! list !# */

#if MASTER_LIBRARY_HAVE_MAP == 1
#	include <map>
#endif /* #! map !# */

#if MASTER_LIBRARY_HAVE_MDSPAN == 1
#	include <mdspan>
#endif /* #! mdspan !# */

#if MASTER_LIBRARY_HAVE_QUEUE == 1
#	include <queue>
#endif /* #! queue !# */

#if MASTER_LIBRARY_HAVE_SET == 1
#	include <set>
#endif /* #! set !# */

#if MASTER_LIBRARY_HAVE_SPAN == 1
#	include <span>
#endif /* #! span !# */

#if MASTER_LIBRARY_HAVE_STACK == 1
#	include <stack>
#endif /* #! stack !# */

#if MASTER_LIBRARY_HAVE_UNORDERED_MAP == 1
#	include <unordered_map>
#endif /* #! unordered_map !# */

#if MASTER_LIBRARY_HAVE_UNORDERED_SET == 1
#	include <unordered_set>
#endif /* #! unordered_set !# */

#if MASTER_LIBRARY_HAVE_VECTOR == 1
#	include <vector>
#endif /* #! vector !# */

#if MASTER_LIBRARY_HAVE_ITERATOR == 1
#	include <iterator>
#endif /* #! iterator !# */

#if MASTER_LIBRARY_HAVE_GENERATOR == 1
#	include <generator>
#endif /* #! generator !# */

#if MASTER_LIBRARY_HAVE_RANGES == 1
#	include <ranges>
#endif /* #! ranges !# */

#if MASTER_LIBRARY_HAVE_ALGORITHM == 1
#	include <algorithm>
#endif /* #! algorithm !# */

#if MASTER_LIBRARY_HAVE_NUMERIC == 1
#	include <numeric>
#endif /* #! numeric !# */

#if MASTER_LIBRARY_HAVE_CSTRING == 1
#	include <cstring>
#endif /* #! cstring !# */

#if MASTER_LIBRARY_HAVE_STRING == 1
#	include <string>
#endif /* #! string !# */

#if MASTER_LIBRARY_HAVE_STRING_VIEW == 1
#	include <string_view>
#endif /* #! string_view !# */

#if MASTER_LIBRARY_HAVE_CCTYPE == 1
#	include <cctype>
#endif /* #! cctype !# */

#if MASTER_LIBRARY_HAVE_CHARCONV == 1
#	include <charconv>
#endif /* #! charconv !# */

#if MASTER_LIBRARY_HAVE_CLOCALE == 1
#	include <clocale>
#endif /* #! clocale !# */

#if MASTER_LIBRARY_HAVE_CODECVT == 1
#	include <codecvt>
#endif /* #! codecvt !# */

#if MASTER_LIBRARY_HAVE_CUCHAR == 1
#	include <cuchar>
#endif /* #! cuchar !# */

#if MASTER_LIBRARY_HAVE_CWCHAR == 1
#	include <cwchar>
#endif /* #! cwchar !# */

#if MASTER_LIBRARY_HAVE_CWCTYPE == 1
#	include <cwctype>
#endif /* #! cwctype !# */

#if MASTER_LIBRARY_HAVE_FORMAT == 1
#	include <format>
#endif /* #! format !# */

#if MASTER_LIBRARY_HAVE_LOCALE == 1
#	include <locale>
#endif /* #! locale !# */

#if MASTER_LIBRARY_HAVE_REGEX == 1
#	include <regex>
#endif /* #! regex !# */

#if MASTER_LIBRARY_HAVE_TEXT_ENCODING == 1
#	include <text_encoding>
#endif /* #! text_encoding !# */

#if MASTER_LIBRARY_HAVE_CFENV == 1
#	include <cfenv>
#endif /* #! cfenv !# */

#if MASTER_LIBRARY_HAVE_CMATH == 1
#	include <cmath>
#endif /* #! cmath !# */

#if MASTER_LIBRARY_HAVE_COMPLEX == 1
#	include <complex>
#endif /* #! complex !# */

#if MASTER_LIBRARY_HAVE_LINALG == 1
#	include <linalg>
#endif /* #! linalg !# */

#if MASTER_LIBRARY_HAVE_NUMBERS == 1
#	include <numbers>
#endif /* #! numbers !# */

#if MASTER_LIBRARY_HAVE_RANDOM == 1
#	include <random>
#endif /* #! random !# */

#if MASTER_LIBRARY_HAVE_SIMD == 1
#	include <simd>
#endif /* #! simd !# */

#if MASTER_LIBRARY_HAVE_VALARRAY == 1
#	include <valarray>
#endif /* #! valarray !# */

#if MASTER_LIBRARY_HAVE_CHRONO == 1
#	include <chrono>
#endif /* #! chrono !# */

#if MASTER_LIBRARY_HAVE_CTIME == 1
#	include <ctime>
#endif /* #! ctime !# */

#if MASTER_LIBRARY_HAVE_CINTTYPES == 1
#	include <cinttypes>
#endif /* #! cinttypes !# */

#if MASTER_LIBRARY_HAVE_CSTDIO == 1
#	include <cstdio>
#endif /* #! cstdio !# */

#if MASTER_LIBRARY_HAVE_FILESYSTEM == 1
#	include <filesystem>
#endif /* #! filesystem !# */

#if MASTER_LIBRARY_HAVE_FSTREAM == 1
#	include <fstream>
#endif /* #! fstream !# */

#if MASTER_LIBRARY_HAVE_IOMANIP == 1
#	include <iomanip>
#endif /* #! iomanip !# */

#if MASTER_LIBRARY_HAVE_IOS == 1
#	include <ios>
#endif /* #! ios !# */

#if MASTER_LIBRARY_HAVE_IOSFWD == 1
#	include <iosfwd>
#endif /* #! iosfwd !# */

#if MASTER_LIBRARY_HAVE_IOSTREAM == 1
#	include <iostream>
#endif /* #! iostream !# */

#if MASTER_LIBRARY_HAVE_ISTREAM == 1
#	include <istream>
#endif /* #! istream !# */

#if MASTER_LIBRARY_HAVE_OSTREAM == 1
#	include <ostream>
#endif /* #! ostream !# */

#if MASTER_LIBRARY_HAVE_PRINT == 1
#	include <print>
#endif /* #! print !# */

#if MASTER_LIBRARY_HAVE_SPANSTREAM == 1
#	include <spanstream>
#endif /* #! spanstream !# */

#if MASTER_LIBRARY_HAVE_SSTREAM == 1
#	include <sstream>
#endif /* #! sstream !# */

#if MASTER_LIBRARY_HAVE_STREAMBUF == 1
#	include <streambuf>
#endif /* #! streambuf !# */

#if MASTER_LIBRARY_HAVE_STRSTREAM == 1
#	include <strstream>
#endif /* #! strstream !# */

#if MASTER_LIBRARY_HAVE_SYNCSTREAM == 1
#	include <syncstream>
#endif /* #! syncstream !# */

#if MASTER_LIBRARY_HAVE_ATOMIC == 1
#	include <atomic>
#endif /* #! atomic !# */

#if MASTER_LIBRARY_HAVE_BARRIER == 1
#	include <barrier>
#endif /* #! barrier !# */

#if MASTER_LIBRARY_HAVE_CONDITION_VARIABLE == 1
#	include <condition_variable>
#endif /* #! condition_variable !# */

#if MASTER_LIBRARY_HAVE_FUTURE == 1
#	include <future>
#endif /* #! future !# */

#if MASTER_LIBRARY_HAVE_HAZARD_POINTER == 1
#	include <hazard_pointer>
#endif /* #! hazard_pointer !# */

#if MASTER_LIBRARY_HAVE_LATCH == 1
#	include <latch>
#endif /* #! latch !# */

#if MASTER_LIBRARY_HAVE_MUTEX == 1
#	include <mutex>
#endif /* #! mutex !# */

#if MASTER_LIBRARY_HAVE_RCU == 1
#	include <rcu>
#endif /* #! rcu !# */

#if MASTER_LIBRARY_HAVE_SEMAPHORE == 1
#	include <semaphore>
#endif /* #! semaphore !# */

#if MASTER_LIBRARY_HAVE_SHARED_MUTEX == 1
#	include <shared_mutex>
#endif /* #! shared_mutex !# */

#if MASTER_LIBRARY_HAVE_STOP_TOKEN == 1
#	include <stop_token>
#endif /* #! stop_token !# */

#if MASTER_LIBRARY_HAVE_THREAD == 1
#	include <thread>
#endif /* #! thread !# */

#if MASTER_LIBRARY_HAVE_CCOMPLEX == 1
#	include <ccomplex>
#endif /* #! ccomplex !# */

#if MASTER_LIBRARY_HAVE_CTGMATH == 1
#	include <ctgmath>
#endif /* #! ctgmath !# */

#if MASTER_LIBRARY_HAVE_CISO646 == 1
#	include <ciso646>
#endif /* #! ciso646 !# */

#if MASTER_LIBRARY_HAVE_CSTDALIGN == 1
#	include <cstdalign>
#endif /* #! cstdalign !# */

#if MASTER_LIBRARY_HAVE_CSTDBOOL == 1
#	include <cstdbool>
#endif /* #! cstdbool !# */

#define MASTER_LIBRARY_C_LIBS_AVAIL (32)
#define MASTER_LIBRARY_CPP_LIBS_AVAIL (150)
#define MASTER_LIBRARY_POSIX_LIBS_AVAIL (61)
#define MASTER_LIBRARY_WINDOWS_LIBS_AVAIL (37)
#define MASTER_LIBRARY_MSDOS_LIBS_AVAIL (1)
#define MASTER_LIBRARY_TPC_LIBS_AVAIL (0)
#define MASTER_LIBRARY_TPCPP_LIBS_AVAIL (0)

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const unsigned int MASTER_zzz_LIBRARY_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_LIBRARY_H !# */

/* #! be master~ !# */
