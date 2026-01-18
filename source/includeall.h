
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_INCLUDE_ALL_INCLUDE_H
#define MASTER_zRIVATE_INCLUDE_ALL_INCLUDE_H

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

/* #! Science !# */
#include <masmath.h>

/* #! Encodings !# */
#include <charmaplib.h>

/* #! Some Functions !# */
#include <randomlib.h>
#include <algolib.h>

/* #! Crypthography !# */
#include <hashlib.h>
#include <checksum.h>

/* #! For metadata only !# */
#include <compilers/gcc_config.h>

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	#define MASTER_FULL_LIBRARY_SUM_OF_LINES (MASTER_zRIVATE_INCLUDEALL_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_CODE_STYLE_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_ARCHITECTURE_DETECT_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_OPERATING_SYSTEM_DETECT_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_COMPILER_DETECT_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_ABSTRACT_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_SIMD_DETECT_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_DISTANCES_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_BITLIB_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_MASMATH_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_CHARMAPLIB_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_RANDOMLIB_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_ALGOLIB_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_HASHLIB_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_CHECKSUM_INCLUDE_H_LAST_LINE + \
											  MASTER_zRIVATE_GCC_CONFIG_INCLUDE_H_LAST_LINE)
	const UI4 MASTER_zRIVATE_INCLUDEALL_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#else
#	define MASTER_FULL_LIBRARY_SUM_OF_LINES (-1)
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_INCLUDE_ALL_INCLUDE_H !# */

/* #! be master~ !# */
