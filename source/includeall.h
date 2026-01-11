
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_INCLUDE_ALL_INCLUDE_H__
#define __MASTER_INCLUDE_ALL_INCLUDE_H__

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

/* #! Metadata & Important !# */
#include <architecture_detect.h>
#include <operating_system_detect.h>
#include <compiler_detect.h>

/* #! Types !# */
#include <abstract.h>

/* #! SIMD !# */
#include <simd_detect.h>

/* #! Strings & Raw Bytes !# */
#include <distances.h>
#include <bitlib.h>

/* #! Encodings !# */
#include <charmaplib.h>

/* #! Some Functions !# */
#include <randomlib.h>
#include <algolib.h>

/* #! Crypthography !# */
#include <hashlib.h>
#include <checksum.h>

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	#define __MASTER_FULL_LIBRARY_SUM_OF_LINES__ (__MASTER_INCLUDEALL_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_CODE_STYLE_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_ARCHITECTURE_DETECT_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_OPERATING_SYSTEM_DETECT_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_COMPILER_DETECT_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_ABSTRACT_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_SIMD_DETECT_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_DISTANCES_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_BITLIB_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_CHARMAPLIB_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_RANDOMLIB_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_ALGOLIB_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_HASHLIB_INCLUDE_H_LAST_LINE__ + \
												 __MASTER_CHECKSUM_INCLUDE_H_LAST_LINE__)
	const UI4 __MASTER_INCLUDEALL_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_INCLUDE_ALL_INCLUDE_H__ !# */

/* #! be master~ !# */
