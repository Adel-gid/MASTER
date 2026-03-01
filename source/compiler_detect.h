
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_COMPILER_DETECT_H
#define MASTER_zzz_COMPILER_DETECT_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#ifdef __cplusplus
#	define MASTER_LANGUAGE_NAME "C++"
#else
#	define MASTER_LANGUAGE_NAME "C"
#endif /* #! C++ !# */

#define MASTER_zzz_COMPILER_GENNAME( format, arguments, argumentList ) \
\
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, char *, MASTER_zzz_GetCompilerName, ( void ) ); \
\
MASTER_DEFINE_FUNCTION0( \
	MASTER_NO_FLAGS, \
	MASTER_EMPTY_DESCRIPTION, \
	/* ! */ MASTER_zzz_GetCompilerName /* ! */, \
	char * \
) { \
	static char compilerName[32]; \
	static int isGened = 0; \
	if (isGened == 0) { \
		snprintf(compilerName, 32, format MASTER_CONCAT_FALL(MASTER_UNARG_END, arguments) argumentList); \
		isGened = 1; \
	} \
	return compilerName; \
}

#ifdef MASTER_COMPILER_USE_CUSTOM
#	ifndef MASTER_COMPILER_NAME
#		if MASTER_COMPILER_WARNING_AVAIL == 1
 #			warning "Custom compiler needs name, printed as ascii string in macros \"MASTER_COMPILER_NAME\" (optional)"
#		endif /* #! Warning !# */
#	endif /* #! MASTER_COMPILER_NAME !# */
#elif defined(_ACC_)
#	define MASTER_COMPILER_NAME "ACC"
#elif defined(__CMB__)
#	if __VERSION__ + 0 == 1000 && __REVISION__ + 0 == 2
#		define MASTER_COMPILER_NAME "Altium MicroBlaze C 1.0r2"
#	elif __BUILD__ + 0 == 1022001
#		define MASTER_COMPILER_NAME "Altium MicroBlaze C 1.22.2"
#	else
#		define MASTER_COMPILER_NAME "Altium MicroBlaze C"
#	endif /* #! Altium MicroBlaze C Compiler Name!# */
#elif defined(__CHC__)
#	if __VERSION__ + 0 == 2001 && __REVISION__ + 0 == 1
#		define MASTER_COMPILER_NAME "Altium C-to-Hardware 2.1r1"
#	elif __BUILD__ + 0 == 1022001
#		define MASTER_COMPILER_NAME "Altium C-to-Hardware 1.22.2"
#	else
#		define MASTER_COMPILER_NAME "Altium C-to-Hardware"
#	endif /* #! Altium C-to-Hardware Compiler Name!# */
#elif defined(__ACK__)
#	define MASTER_COMPILER_NAME "Amsterdam Compiler Kit"
#elif defined(__CC_ARM)
#	if __ARMCC_VERSION + 0 == 300503
#		define MASTER_COMPILER_NAME "ARM Compiler 3.0"
#	else
#		define MASTER_COMPILER_NAME "ARM Compiler"
#	endif /* #! ARM Compiler Name!# */
#elif defined(AZTEC_C) || defined(__AZTEC_C__)
#	if __VERSION + 0 == 520
#		define MASTER_COMPILER_NAME "Aztec C 5.20"
#	else
#		define MASTER_COMPILER_NAME "Aztec C"
#	endif /* #! Aztec C Compiler Name!# */
#elif defined(__BORLANDC__) || defined(__CODEGEARDC__)
#	if __BORLANDC__ + 0 == 0x200
#		define MASTER_COMPILER_NAME "Borland C++ 2.0"
#	elif __BORLANDC__ + 0 == 0x400
#		define MASTER_COMPILER_NAME "Borland C++ 3.0"
#	elif __BORLANDC__ + 0 == 0x410
#		define MASTER_COMPILER_NAME "Borland C++ 3.1"
#	elif __BORLANDC__ + 0 == 0x452
#		define MASTER_COMPILER_NAME "Borland C++ 4.0"
#	elif __BORLANDC__ + 0 == 0x500
#		define MASTER_COMPILER_NAME "Borland C++ 5.0"
#	elif __BORLANDC__ + 0 == 0x520
#		define MASTER_COMPILER_NAME "Borland C++ 5.02"
#	elif __BORLANDC__ + 0 == 0x550
#		define MASTER_COMPILER_NAME "Borland C++ 5.5"
#	elif __BORLANDC__ + 0 == 0x551
#		define MASTER_COMPILER_NAME "Borland C++ 5.51"
#	elif __BORLANDC__ + 0 == 0x562
#		define MASTER_COMPILER_NAME "Borland C++ 5.6.4"
#	elif __BORLANDC__ + 0 == 0x570
#		define MASTER_COMPILER_NAME "Borland C++ 2006"
#	elif __BORLANDC__ + 0 == 0x590
#		define MASTER_COMPILER_NAME "Borland C++ 2007"
#	elif __BORLANDC__ + 0 == 0x613
#		define MASTER_COMPILER_NAME "Borland C++ 2009"
#	elif __BORLANDC__ + 0 == 0x621
#		define MASTER_COMPILER_NAME "Borland C++ 2010"
#	elif __BORLANDC__ + 0 == 0x630
#		define MASTER_COMPILER_NAME "Borland C++ XE"
#	elif __BORLANDC__ + 0 == 0x640
#		define MASTER_COMPILER_NAME "Borland C++ XE2"
#	elif __BORLANDC__ + 0 == 0x650
#		define MASTER_COMPILER_NAME "Borland C++ XE3"
#	elif __BORLANDC__ + 0 == 0x660
#		define MASTER_COMPILER_NAME "Borland C++ XE4"
#	else
#		define MASTER_COMPILER_NAME "Borland C++"
#	endif /* #! Borland C++ Compiler Name !# */
#elif defined(__CC65__)
#	if __CC65__ + 0 == 0x2A1
#		define MASTER_COMPILER_NAME "CC65 2.10.1"
#	else
#		define MASTER_COMPILER_NAME "CC65"
#	endif /* #! CC65 Compiler Name !# */
#elif defined(__clang__)
#	define MASTER_COMPILER_NAME "clang"
	/* #! Version? !# */
#elif defined(__COMO__)
#	if __COMO_VERSION__ + 0 == 230
#		define MASTER_COMPILER_NAME "Comeau C++ 2.3"
#	else
#		define MASTER_COMPILER_NAME "Comeau C++"
#	endif /* #! Comeau C++ Compiler Name !# */
#elif defined(__DECC) || defined(__DECCXX) || defined(__VAXC) || defined(VAXC)
#	ifdef __DECC
#		if __DECC_VER + 0 == 60090001
#			define MASTER_COMPILER_NAME "Compaq C 6.0-001"
#		else
#			define MASTER_COMPILER_NAME "Compaq C"
#		endif /* #! Compaq C Compiler Name !# */
#	elif defined(__DECCXX)
#		define MASTER_COMPILER_NAME "Compaq C++"
#	else
#		define MASTER_COMPILER_NAME "Compaq " MASTER_LANGUAGE_NAME " Obsolete"
#	endif /* #! Determine Compiler !# */
#elif defined(__convexc__)
#	define MASTER_COMPILER_NAME "Convex C"
#elif defined(__COMPCERT__)
#	define MASTER_COMPILER_NAME "CompCert"
#elif defined(__COVERITY__)
#	define MASTER_COMPILER_NAME "Coverity " MASTER_LANGUAGE_NAME " Static Analyzer"
#elif defined(_CRAYC)
#	define MASTER_COMPILER_NAME "Cray C"
#elif defined(__GNUC__)
#	if defined(__GNUC_MINOR__) && defined(__GNUC_PATCHLEVEL__)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_COMPILER_GENNAME( "GCC %s %d.%d.%d", 4, (MASTER_LANGUAGE_NAME, __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__) )
#			define MASTER_COMPILER_NAME MASTER_zzz_GetCompilerName()
#		else
#			define MASTER_COMPILER_NAME "GCC " MASTER_LANGUAGE_NAME " " MASTER_STRINGIFY_FALL(__GNUC__) "." MASTER_STRINGIFY_FALL(__GNUC_MINOR__) "." MASTER_STRINGIFY_FALL(__GNUC_PATCHLEVEL__)
#		endif /* #! String concatenation !# */
#	elif defined(__GNUC_MINOR__)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_COMPILER_GENNAME( "GCC %s %d.%d.x", 3, (MASTER_LANGUAGE_NAME, __GNUC__, __GNUC_MINOR__) )
#			define MASTER_COMPILER_NAME MASTER_zzz_GetCompilerName()
#		else
#			define MASTER_COMPILER_NAME "GCC " MASTER_LANGUAGE_NAME " " MASTER_STRINGIFY_FALL(__GNUC__) "." MASTER_STRINGIFY_FALL(__GNUC_MINOR__) ".x"
#		endif /* #! String concatenation !# */
#	elif defined(__GNUC_PATCHLEVEL__)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_COMPILER_GENNAME( "GCC %s %d.x.%d", 3, (MASTER_LANGUAGE_NAME, __GNUC__, __GNUC_PATCHLEVEL__) )
#			define MASTER_COMPILER_NAME MASTER_zzz_GetCompilerName()
#		else
#			define MASTER_COMPILER_NAME "GCC " MASTER_LANGUAGE_NAME " " MASTER_STRINGIFY_FALL(__GNUC__) ".x." MASTER_STRINGIFY_FALL(__GNUC_PATCHLEVEL__)
#		endif /* #! String concatenation !# */
#	else
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_COMPILER_GENNAME( "GCC %s %d.x.x", 2, (MASTER_LANGUAGE_NAME, __GNUC__) )
#			define MASTER_COMPILER_NAME MASTER_zzz_GetCompilerName()
#		else
#			define MASTER_COMPILER_NAME "GCC " MASTER_LANGUAGE_NAME " " MASTER_STRINGIFY_FALL(__GNUC__) ".x.x"
#		endif /* #! String concatenation !# */
#	endif /* #! GCC Compiler Name !# */
#	include <compilers/gcc_config.h>
#elif defined(THINKC3) || defined(THINKC4)
#	ifdef THINKC3
#		define MASTER_COMPILER_NAME "Think C 3"
#	elif defined(THINKC4)
#		define MASTER_COMPILER_NAME "Think C 4"
#	else
#		define MASTER_COMPILER_NAME "Think C"
#	endif /* #! Think C Compiler Name !# */
#elif defined(__IMAGECRAFT__)
#	define MASTER_COMPILER_NAME "ImageCraft C"
#elif defined(__INTEL_COMPILER) || defined(__ICC) || defined(__ECC) || defined(__ICL)
#	define MASTER_COMPILER_NAME "Intel " MASTER_LANGUAGE_NAME
#elif defined(__llvm__)
#	define MASTER_COMPILER_NAME "LLVM"
#elif defined(__MINGW32__) || defined(__MINGW64__)
#	ifdef __MINGW32__
#		define MASTER_COMPILER_NAME "MinGW32"
#	elif defined(__MINGW64__)
#		define MASTER_COMPILER_NAME "MinGW64"
#	endif /* #! MinGW Compiler Name !# */
#elif defined(__TINYC__)
#	define MASTER_COMPILER_NAME "Tiny C"
#	include <compilers/tcc_config.h>
#elif defined(__TURBOC__)
#	define MASTER_COMPILER_NAME "Turbo " MASTER_LANGUAGE_NAME
#	include <compilers/tc_config.h>
#elif defined(_UCC)
#	if _MAJOR_REV + 0 == 2 && _MINOR_REV + 0 == 1
#		define MASTER_COMPILER_NAME "Ultimate " MASTER_LANGUAGE_NAME " 2.1"
#	else
#		if defined(_MAJOR_REV) && defined(_MINOR_REV)
#			define MASTER_COMPILER_NAME "Ultimate " MASTER_LANGUAGE_NAME " " #_MAJOR_REV "." #_MINOR_REV
#		elif defined(_MAJOR_REV)
#			define MASTER_COMPILER_NAME "Ultimate " MASTER_LANGUAGE_NAME " " #_MAJOR_REV
#		elif defined(_MINOR_REV)
#			define MASTER_COMPILER_NAME "Ultimate " MASTER_LANGUAGE_NAME " x." #_MINOR_REV
#		else
#			define MASTER_COMPILER_NAME "Ultimate " MASTER_LANGUAGE_NAME
#		endif /* #! Version !# */
#	endif /* #! Ultimate " MASTER_LANGUAGE_NAME " Compiler Name !# */
#elif defined(__USLC__)
#	if __SCO_VERSION__ + 0 == 302199801
#		define MASTER_COMPILER_NAME "USL C 3.2"
#	elif __SCO_VERSION__ + 0 == 304200805
#		define MASTER_COMPILER_NAME "USL C 3.4"
#	elif __SCO_VERSION__ + 0 == 402200805
#		define MASTER_COMPILER_NAME "USL C 4.2"
#	else
#		define MASTER_COMPILER_NAME "USL C"
#	endif /* #! USL C Compiler Name !# */
#elif defined(__VBCC__)
#	define MASTER_COMPILER_NAME "VBCC"
#elif defined(__WATCOMC__)
#	define MASTER_COMPILER_NAME "Watcom C++"
#elif defined(__SCCZ80) || defined(SCCZ80) || defined(__SDCC)
#	define MASTER_COMPILER_NAME "Z88DK"
#elif defined(__ZTC__)
#	define MASTER_COMPILER_NAME "Zortech C++"
#else
#	define MASTER_COMPILER_NAME "undefined"
#endif /* #! MASTER_zzz_INTEGER_H !# */

#ifndef MASTER_COMPILER_SIMD_USES
#	define MASTER_COMPILER_SIMD_USES 0
#endif /* #! Using SIMD !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const unsigned int MASTER_zzz_COMPILER_DETECT_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_COMPILER_DETECT_H !# */

/* #! be master~ !# */
