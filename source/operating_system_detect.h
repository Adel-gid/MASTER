
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_OPERATING_SYSTEM_DETECT_INCLUDE_H
#define MASTER_zRIVATE_OPERATING_SYSTEM_DETECT_INCLUDE_H

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
#	ifndef __ANDROID_API__
#		define MASTER_OPERATING_SYSTEM_NAME "Android"
#	elif __ANDROID_API__ == 36
#		define MASTER_OPERATING_SYSTEM_NAME "Android 16 (Baklava)"
#	elif __ANDROID_API__ == 35
#		define MASTER_OPERATING_SYSTEM_NAME "Android 15 (Vanilla Ice Cream)"
#	elif __ANDROID_API__ == 34
#		define MASTER_OPERATING_SYSTEM_NAME "Android 14 (Upside Down Cake)"
#	elif __ANDROID_API__ == 33
#		define MASTER_OPERATING_SYSTEM_NAME "Android 13 (Tiramisu)"
#	elif __ANDROID_API__ == 32
#		define MASTER_OPERATING_SYSTEM_NAME "Android 12L (Snow Cone)"
#	elif __ANDROID_API__ == 31
#		define MASTER_OPERATING_SYSTEM_NAME "Android 12 (Snow Cone)"
#	elif __ANDROID_API__ == 30
#		define MASTER_OPERATING_SYSTEM_NAME "Android 11 (Red Velvet Cake)"
#	elif __ANDROID_API__ == 29
#		define MASTER_OPERATING_SYSTEM_NAME "Android 10 (Quince Tart)"
#	elif __ANDROID_API__ == 28
#		define MASTER_OPERATING_SYSTEM_NAME "Android 9 (Pie)"
#	elif __ANDROID_API__ == 27
#		define MASTER_OPERATING_SYSTEM_NAME "Android 8.1 (Oreo)"
#	elif __ANDROID_API__ == 26
#		define MASTER_OPERATING_SYSTEM_NAME "Android 8.0 (Oreo)"
#	elif __ANDROID_API__ == 25
#		define MASTER_OPERATING_SYSTEM_NAME "Android 7.1 (Nougat)"
#	elif __ANDROID_API__ == 24
#		define MASTER_OPERATING_SYSTEM_NAME "Android 7.0 (Nougat)"
#	elif __ANDROID_API__ == 23
#		define MASTER_OPERATING_SYSTEM_NAME "Android 6 (Marshmallow)"
#	elif __ANDROID_API__ == 22
#		define MASTER_OPERATING_SYSTEM_NAME "Android 5.1 (Lollipop)"
#	elif __ANDROID_API__ == 21
#		define MASTER_OPERATING_SYSTEM_NAME "Android 5.0 (Lollipop)"
#	elif __ANDROID_API__ == 20
#		define MASTER_OPERATING_SYSTEM_NAME "Android 4.4W (KitKat)"
#	elif __ANDROID_API__ == 19
#		define MASTER_OPERATING_SYSTEM_NAME "Android 4.4 (KitKat)"
#	elif __ANDROID_API__ == 18
#		define MASTER_OPERATING_SYSTEM_NAME "Android 4.3 (Jelly Bean)"
#	elif __ANDROID_API__ == 17
#		define MASTER_OPERATING_SYSTEM_NAME "Android 4.2 (Jelly Bean)"
#	elif __ANDROID_API__ == 16
#		define MASTER_OPERATING_SYSTEM_NAME "Android 4.1 (Jelly Bean)"
#	elif __ANDROID_API__ == 15
#		define MASTER_OPERATING_SYSTEM_NAME "Android 4.0.3 / 4.0.4 (Ice Cream Sandwich)"
#	elif __ANDROID_API__ == 14
#		define MASTER_OPERATING_SYSTEM_NAME "Android 4.0.1 / 4.0.2 (Ice Cream Sandwich)"
#	elif __ANDROID_API__ == 13
#		define MASTER_OPERATING_SYSTEM_NAME "Android 3.2 (Honeycomb)"
#	elif __ANDROID_API__ == 12
#		define MASTER_OPERATING_SYSTEM_NAME "Android 3.1 (Honeycomb)"
#	elif __ANDROID_API__ == 11
#		define MASTER_OPERATING_SYSTEM_NAME "Android 3.0 (Honeycomb)"
#	elif __ANDROID_API__ == 10
#		define MASTER_OPERATING_SYSTEM_NAME "Android 2.3.3 - 2.3.7 (Gingerbreak)"
#	elif __ANDROID_API__ == 9
#		define MASTER_OPERATING_SYSTEM_NAME "Android 2.3.0 - 2.3.2 (Gingerbreak)"
#	elif __ANDROID_API__ == 8
#		define MASTER_OPERATING_SYSTEM_NAME "Android 2.2 (Froyo)"
#	elif __ANDROID_API__ == 7
#		define MASTER_OPERATING_SYSTEM_NAME "Android 2.1 (Eclair)"
#	elif __ANDROID_API__ == 6
#		define MASTER_OPERATING_SYSTEM_NAME "Android 2.0.1 (Eclair)"
#	elif __ANDROID_API__ == 5
#		define MASTER_OPERATING_SYSTEM_NAME "Android 2.0 (Eclair)"
#	elif __ANDROID_API__ == 4
#		define MASTER_OPERATING_SYSTEM_NAME "Android 1.6 (Donut)"
#	elif __ANDROID_API__ == 3
#		define MASTER_OPERATING_SYSTEM_NAME "Android 1.5 (Cupcake)"
#	elif __ANDROID_API__ == 2
#		define MASTER_OPERATING_SYSTEM_NAME "Android 1.1 (Petit Four)"
#	elif __ANDROID_API__ == 1
#		define MASTER_OPERATING_SYSTEM_NAME "Android 1.0"
#	else
#		define MASTER_OPERATING_SYSTEM_NAME "Android - Unknown"
#	endif /* #! Android API !# */
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
#	ifndef B_BEOS_VERSION
#		define MASTER_OPERATING_SYSTEM_NAME "BeOS"
#	elif B_BEOS_VERSION + 0 == 0x0400
#		define MASTER_OPERATING_SYSTEM_NAME "BeOS 4.0"
#	elif B_BEOS_VERSION + 0 == 0x0450
#		define MASTER_OPERATING_SYSTEM_NAME "BeOS 4.5"
#	elif B_BEOS_VERSION + 0 == 0x0500
#		define MASTER_OPERATING_SYSTEM_NAME "BeOS 5.0"
#	else
#		define MASTER_OPERATING_SYSTEM_NAME "BeOS"
#	endif /* #! BeOS Name !# */
#elif defined(__bg__) || defined(__THW_BLUEGENE__)
	/* #! __bqd__, __TOS_BGQ__ !# */
#	define MASTER_OPERATING_SYSTEM_NAME "Blue Gene"
#elif defined(__NetBSD__) || defined(__OpenBSD__) || defined(__MidnightBSD__) || defined(_SYSTYPE_BSD)
	/* #! BSD !# */
#	if defined(BSD4_2)
#		define MASTER_OPERATING_SYSTEM_NAME "BSD 4.2"
#	elif defined(BSD4_3)
#		define MASTER_OPERATING_SYSTEM_NAME "BSD 4.3"
#	elif defined(BSD4_4)
#		define MASTER_OPERATING_SYSTEM_NAME "BSD 4.4"
#	else
#		define MASTER_OPERATING_SYSTEM_NAME "BSD"
#	endif /* #! BSD Name !# */
#elif defined(__bsdi__)
#	define MASTER_OPERATING_SYSTEM_NAME "BSD/OS"
#elif defined(__convex__)
#	define MASTER_OPERATING_SYSTEM_NAME "ConvexOS"
#elif defined(__CPM) || defined(CPM)
#	define MASTER_OPERATING_SYSTEM_NAME "CP/M"
#elif defined(__CYGWIN__)
#	define MASTER_OPERATING_SYSTEM_NAME "Cygwin"
#elif defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#	define MASTER_OPERATING_SYSTEM_NAME "DG/UX"
#elif defined(__DragonFly__)
#	define MASTER_OPERATING_SYSTEM_NAME "DragonFly"
#elif defined(_SEQUENT_) || defined(sequent)
#	define MASTER_OPERATING_SYSTEM_NAME "DYNIX/ptx"
#elif defined(__ECOS)
#	define MASTER_OPERATING_SYSTEM_NAME "eCos"
#elif defined(EMSCRIPTEN) || defined(__EMSCRIPTEN__)
#	if defined(__EMSCRIPTEN_major__) && defined(__EMSCRIPTEN_minor__) && defined(__EMSCRIPTEN_tiny__)
#		define MASTER_OPERATING_SYSTEM_NAME "Emscripten " MASTER_STRINGIFY_FALL(__EMSCRIPTEN_major__) "." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_minor__) "." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_tiny__)
#	elif defined(__EMSCRIPTEN_major__) && defined(__EMSCRIPTEN_minor__)
#		define MASTER_OPERATING_SYSTEM_NAME "Emscripten " MASTER_STRINGIFY_FALL(__EMSCRIPTEN_major__) "." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_minor__)
#	elif defined(__EMSCRIPTEN_major__) && defined(__EMSCRIPTEN_tiny__)
#		define MASTER_OPERATING_SYSTEM_NAME "Emscripten " MASTER_STRINGIFY_FALL(__EMSCRIPTEN_major__) ".x." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_tiny__)
#	elif defined(__EMSCRIPTEN_major__)
#		define MASTER_OPERATING_SYSTEM_NAME "Emscripten " MASTER_STRINGIFY_FALL(__EMSCRIPTEN_major__)
#	elif defined(__EMSCRIPTEN_minor__) && defined(__EMSCRIPTEN_tiny__)
#		define MASTER_OPERATING_SYSTEM_NAME "Emscripten x." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_minor__) "." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_tiny__)
#	elif defined(__EMSCRIPTEN_minor__)
#		define MASTER_OPERATING_SYSTEM_NAME "Emscripten x." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_minor__)
#	elif defined(__EMSCRIPTEN_tiny__)
#		define MASTER_OPERATING_SYSTEM_NAME "Emscripten x.x." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_tiny__)
#	else
#		define MASTER_OPERATING_SYSTEM_NAME "Emscripten"
#	endif /* #! Emscripten Name !# */
#elif defined(__EMX__)
#	define MASTER_OPERATING_SYSTEM_NAME "EMX"
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
	/* #! __FreeBSD_version !# */
#	define MASTER_OPERATING_SYSTEM_NAME "FreeBSD " MASTER_STRINGIFY_FALL(__FreeBSD__)
#elif defined(__Fuchsia__)
#	ifndef __Fuchsia_API_level__
#		define MASTER_OPERATING_SYSTEM_NAME "Fuchsia"
#	else
#		define MASTER_OPERATING_SYSTEM_NAME "Fuchsia " MASTER_STRINGIFY_FALL(__Fuchsia_API_level__)
#	endif /* #! Fuchsia Name !# */
#elif defined(__GNU__) || defined(__gnu_hurd__)
#	ifdef __GNU__
#		define MASTER_OPERATING_SYSTEM_NAME "GNU"
#	else
#		define MASTER_OPERATING_SYSTEM_NAME "GNU Hurd"
#	endif /* #! GNU Name !# */
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
	const UI4 MASTER_zRIVATE_OPERATING_SYSTEM_DETECT_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_OPERATING_SYSTEM_DETECT_INCLUDE_H !# */

/* #! be master~ !# */
