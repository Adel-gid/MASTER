
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_OPERATING_SYSTEM_DETECT_INCLUDE_H__
#define __MASTER_OPERATING_SYSTEM_DETECT_INCLUDE_H__

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#if defined(_AIX_) || defined(__TOS_AIX__)
#	if defined(_AIX3) || defined(_AIX32)
#		define MASTER_OPERATING_SYSTEM_NAME "AIX 3.2"
#	elif defined(_AIX41)
#		define MASTER_OPERATING_SYSTEM_NAME "AIX 4.1"
#	elif defined(_AIX43)
#		define MASTER_OPERATING_SYSTEM_NAME "AIX 4.3"
#	else
#		define MASTER_OPERATING_SYSTEM_NAME "AIX"
#	endif /* #! AIX OS Name !# */
#elif defined(__ANDROID__)
	/* #! Check __ANDROID_API__ !# */
#	define MASTER_OPERATING_SYSTEM_NAME "Android"
#elif defined(UTS)
#	define MASTER_OPERATING_SYSTEM_NAME "Amdahl UTS"
#elif defined(AMIGA) || defined(__amigaos__)
#	define MASTER_OPERATING_SYSTEM_NAME "AmigaOs"
#elif defined(aegis)
#	define MASTER_OPERATING_SYSTEM_NAME "Apollo AEGIS"
#elif defined(apollo)
#	define MASTER_OPERATING_SYSTEM_NAME "Apollo Domain/OS"
#elif defined(__AROS__)
#	define MASTER_OPERATING_SYSTEM_NAME "AROS"
#elif defined(__BEOS__)
	/* #! B_BEOS_VERSION !# */
#	define MASTER_OPERATING_SYSTEM_NAME "BeOS"
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#	if defined(_WIN16) || defined(__WINDOWS__)
#		define MASTER_OPERATING_SYSTEM_NAME "Windows 16-bit"
#	elif (defined(_WIN32) || defined(__WIN32__)) && defined(_WIN64)
#		define MASTER_OPERATING_SYSTEM_NAME "Windows x86-64"
#	elif defined(_WIN32) || defined(__WIN32__)
#		define MASTER_OPERATING_SYSTEM_NAME "Windows x86"
#	elif defined(_WIN64)
#		define MASTER_OPERATING_SYSTEM_NAME "Windows x64"
#	else
#		define MASTER_OPERATING_SYSTEM_NAME "Windows"
#	endif /* #! Windows OS Name !# */
#else
#	define MASTER_OPERATING_SYSTEM_NAME "undefined"
#endif /* #! Operating System !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_OPERATING_SYSTEM_DETECT_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_OPERATING_SYSTEM_DETECT_INCLUDE_H__ !# */

/* #! be master~ !# */
