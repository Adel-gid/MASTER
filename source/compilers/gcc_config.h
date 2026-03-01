
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_GCC_CONFIG_H
#define MASTER_zzz_GCC_CONFIG_H

#include <master_enum.h>

#if !defined(MASTER_zzz_COMPILER_FEATURES_LOADED) && !defined(MASTER_NO_COMPILER_FEATURES)

MASTER_BEGIN_DECLARATIONS

#ifdef __GNUC__
#	define MASTER_PREFER_INLINE __inline
#endif /* #! inline !# */
#define MASTER_COMPILER_SIZEOF_CHAR 1
#define MASTER_COMPILER_SIZEOF_SHORT 2
#define MASTER_COMPILER_SIZEOF_INT 4
#define MASTER_COMPILER_SIZEOF_LONG 4
#define MASTER_COMPILER_SIZEOF_LONG_LONG 8
#define MASTER_COMPILER_SIZEOF_SIZE_T 8
#if defined(__GNUC__) && (__GNUC__ + 0 > 3 || (defined(__GNUC_MINOR__) && __GNUC__ + 0 == 3 && __GNUC_MINOR__ + 0 >= 1))
#	define MASTER_PREFER_RESTRICT __restrict
#endif /* #! Restrict !# */
#if MASTER_COMPILER_HAS_ATTRIBUTE( nonnull )
#	define MASTER_PREFER_NONNULL_ARG( argument ) __attribute__((nonnull(argument)))
#endif /* #! attribute nonnull !# */
#if MASTER_COMPILER_HAS_ATTRIBUTE( access )
#	define MASTER_PREFER_RO_ARG( argumentIndex ) __attribute__((access(read_only, argumentIndex)))
#	define MASTER_PREFER_WO_ARG( argumentIndex ) __attribute__((access(write_only, argumentIndex)))
#	define MASTER_PREFER_RW_ARG( argumentIndex ) __attribute__((access(read_write, argumentIndex)))
#	define MASTER_PREFER_ROS_ARG( argumentIndex, argumentSize ) __attribute__((access(read_only, argumentIndex, argumentSize)))
#	define MASTER_PREFER_WOS_ARG( argumentIndex, argumentSize ) __attribute__((access(write_only, argumentIndex, argumentSize)))
#	define MASTER_PREFER_RWS_ARG( argumentIndex, argumentSize ) __attribute__((access(read_write, argumentIndex, argumentSize)))
#	define MASTER_PREFER_NRW_ARG( argumentIndex ) __attribute__((access(none, argumentIndex)))
#endif /* #! attribute access !# */
#ifdef __GNUC__
#	define MASTER_PREFER_FUNCTION_CONST __attribute__((__const__))
#	define MASTER_PREFER_FUNCTION_PURE __attribute__((__pure__))
#	define MASTER_PREFER_FUNCTION_MALLOC __attribute__((__malloc__))
#endif /* #! function const & function pure & function malloc !# */

#define MASTER_COMPILER_SIMD_USES 1
#define MASTER_COMPILER_WARNING_AVAIL 1

#define MASTER_zzz_COMPILER_FEATURES_LOADED 1

MASTER_END_DECLARATIONS

#endif /* #! Compiler features !# */

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const unsigned int MASTER_zzz_GCC_CONFIG_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_GCC_CONFIG_H !# */

/* #! be master~ !# */
