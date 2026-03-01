
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_TC_CONFIG_H
#define MASTER_zzz_TC_CONFIG_H

#include <master_enum.h>

#if !defined(MASTER_zzz_COMPILER_FEATURES_LOADED) && !defined(MASTER_NO_COMPILER_FEATURES)

MASTER_BEGIN_DECLARATIONS

#define MASTER_COMPILER_SIZEOF_POINTER 2
#define MASTER_COMPILER_SIZEOF_CHAR 1
#define MASTER_COMPILER_SIZEOF_SHORT 2
#define MASTER_COMPILER_SIZEOF_INT 2
#define MASTER_COMPILER_SIZEOF_LONG 4
#define MASTER_COMPILER_SIZEOF_LONG_LONG 4
#define MASTER_COMPILER_SIZEOF_SIZE_T 2

#define MASTER_LIBRARY_HAVE_WCTYPE_H 0
#define MASTER_LIBRARY_HAVE_WCHAR_H 0
#define MASTER_LIBRARY_HAVE_ISO646_H 0
#define MASTER_COMPILER_SIMD_USES 0
#define MASTER_COMPILER_WARNING_AVAIL 0

#define MASTER_zzz_COMPILER_FEATURES_LOADED 1

MASTER_END_DECLARATIONS

#endif /* #! Compiler features !# */

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const unsigned int MASTER_zzz_TC_CONFIG_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_TC_CONFIG_H !# */

/* #! be master~ !# */
