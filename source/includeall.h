
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_INCLUDE_ALL_H
#define MASTER_zzz_INCLUDE_ALL_H

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

/* #! Some Dependencies !# */
#include <library.h>

/* #! For metadata only !# */
#include <compilers/gcc_config.h>
#include <compilers/tc_config.h>
#include <compilers/tcc_config.h>

MASTER_END_DECLARATIONS

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
#	define MASTER_FULL_LIBRARY_SUM_OF_LINES (MASTER_zzz_INCLUDEALL_H_LLINE + \
											 MASTER_zzz_CODE_STYLE_H_LLINE + \
											 MASTER_zzz_ARCH_DETECT_H_LLINE + \
											 MASTER_zzz_OS_DETECT_H_LLINE + \
											 MASTER_zzz_COMPILER_DETECT_H_LLINE + \
											 MASTER_zzz_ABSTRACT_H_LLINE + \
											 MASTER_zzz_SIMD_DETECT_H_LLINE + \
											 MASTER_zzz_DISTANCES_H_LLINE + \
											 MASTER_zzz_BITLIB_H_LLINE + \
											 MASTER_zzz_MASMATH_H_LLINE + \
											 MASTER_zzz_CHARMAPLIB_H_LLINE + \
											 MASTER_zzz_RANDOMLIB_H_LLINE + \
											 MASTER_zzz_ALGOLIB_H_LLINE + \
											 MASTER_zzz_HASHLIB_H_LLINE + \
											 MASTER_zzz_CHECKSUM_H_LLINE + \
											 MASTER_zzz_LIBRARY_H_LLINE + \
											 MASTER_zzz_GCC_CONFIG_H_LLINE + \
											 MASTER_zzz_TC_CONFIG_H_LLINE + \
											 MASTER_zzz_TCC_CONFIG_H_LLINE)
	const UI4 MASTER_zzz_INCLUDEALL_H_LLINE = MASTER_LINE + 8;
#else
#	define MASTER_FULL_LIBRARY_SUM_OF_LINES (-1)
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_INCLUDE_ALL_H !# */

/* #! be master~ !# */
