
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_COMPILER_DETECT_INCLUDE_H__
#define __MASTER_COMPILER_DETECT_INCLUDE_H__

#include <master_enum.h>

#ifdef MASTER_COMPILER_USE_CUSTOM
#	ifndef MASTER_COMPILER_NAME
#		warning "Custom compiler needs name, printed as ascii string in macros \"MASTER_COMPILER_NAME\" (optional)"
#	endif /* #! MASTER_COMPILER_NAME !# */
#elif defined(_ACC_)
#	define MASTER_COMPILER_NAME "ACC"
#elif defined(__CMB__)
#	if __VERSION__ == 1000 && __REVISION__ == 2
#		define MASTER_COMPILER_NAME "Altium MicroBlaze C 1.0r2"
#	elif __BUILD__ == 1022001
#		define MASTER_COMPILER_NAME "Altium MicroBlaze C 1.22.2"
#	else
#		define MASTER_COMPILER_NAME "Altium MicroBlaze C"
#	endif /* #! Altium MicroBlaze C Compiler Name!# */
#elif defined(__CHC__)
#	if __VERSION__ == 2001 && __REVISION__ == 1
#		define MASTER_COMPILER_NAME "Altium C-to-Hardware 2.1r1"
#	elif __BUILD__ == 1022001
#		define MASTER_COMPILER_NAME "Altium C-to-Hardware 1.22.2"
#	else
#		define MASTER_COMPILER_NAME "Altium C-to-Hardware"
#	endif /* #! Altium C-to-Hardware Compiler Name!# */
#elif defined(__ACK__)
#	define MASTER_COMPILER_NAME "Amsterdam Compiler Kit"
#elif defined(__CC_ARM)
#	if __ARMCC_VERSION == 300503
#		define MASTER_COMPILER_NAME "ARM Compiler 3.0"
#	else
#		define MASTER_COMPILER_NAME "ARM Compiler"
#	endif /* #! ARM Compiler Name!# */
#elif defined(AZTEC_C) || defined(__AZTEC_C__)
#	if __VERSION == 520
#		define MASTER_COMPILER_NAME "Aztec C 5.20"
#	else
#		define MASTER_COMPILER_NAME "Aztec C"
#	endif /* #! Aztec C Compiler Name!# */
#elif defined(__BORLANDC__) || defined(__CODEGEARDC__)
#	if __BORLANDC__ == 0x200
#		define MASTER_COMPILER_NAME "Borland C++ 2.0"
#	elif __BORLANDC__ == 0x400
#		define MASTER_COMPILER_NAME "Borland C++ 3.0"
#	elif __BORLANDC__ == 0x410
#		define MASTER_COMPILER_NAME "Borland C++ 3.1"
#	elif __BORLANDC__ == 0x452
#		define MASTER_COMPILER_NAME "Borland C++ 4.0"
#	elif __BORLANDC__ == 0x500
#		define MASTER_COMPILER_NAME "Borland C++ 5.0"
#	elif __BORLANDC__ == 0x520
#		define MASTER_COMPILER_NAME "Borland C++ 5.02"
#	elif __BORLANDC__ == 0x550
#		define MASTER_COMPILER_NAME "Borland C++ 5.5"
#	elif __BORLANDC__ == 0x551
#		define MASTER_COMPILER_NAME "Borland C++ 5.51"
#	elif __BORLANDC__ == 0x562
#		define MASTER_COMPILER_NAME "Borland C++ 5.6.4"
#	elif __BORLANDC__ == 0x570
#		define MASTER_COMPILER_NAME "Borland C++ 2006"
#	elif __BORLANDC__ == 0x590
#		define MASTER_COMPILER_NAME "Borland C++ 2007"
#	elif __BORLANDC__ == 0x613
#		define MASTER_COMPILER_NAME "Borland C++ 2009"
#	elif __BORLANDC__ == 0x621
#		define MASTER_COMPILER_NAME "Borland C++ 2010"
#	elif __BORLANDC__ == 0x630
#		define MASTER_COMPILER_NAME "Borland C++ XE"
#	elif __BORLANDC__ == 0x640
#		define MASTER_COMPILER_NAME "Borland C++ XE2"
#	elif __BORLANDC__ == 0x650
#		define MASTER_COMPILER_NAME "Borland C++ XE3"
#	elif __BORLANDC__ == 0x660
#		define MASTER_COMPILER_NAME "Borland C++ XE4"
#	else
#		define MASTER_COMPILER_NAME "Borland C++"
#	endif /* #! Borland C++ Compiler Name !# */
#elif defined(__CC65__)
#	if __CC65__ == 0x2A1
#		define MASTER_COMPILER_NAME "CC65 2.10.1"
#	else
#		define MASTER_COMPILER_NAME "CC65"
#	endif /* #! CC65 Compiler Name !# */
#elif defined(__TINYC__)
#	define MASTER_COMPILER_NAME "Tiny C"
#else
#	define MASTER_COMPILER_NAME "undefined"
#endif /* #! __MASTER_INTEGER_INCLUDE_H__ !# */

#endif /* #! __MASTER_COMPILER_DETECT_INCLUDE_H__ !# */

/* #! be master~ !# */
