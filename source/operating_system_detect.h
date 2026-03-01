
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_OS_DETECT_H
#define MASTER_zzz_OS_DETECT_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#define MASTER_zzz_OS_GENNAME( format, arguments, argumentList ) \
\
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, char *, MASTER_zzz_GetOSName, ( void ) ); \
\
MASTER_DEFINE_FUNCTION0( \
	MASTER_NO_FLAGS, \
	MASTER_EMPTY_DESCRIPTION, \
	/* ! */ MASTER_zzz_GetOSName /* ! */, \
	char * \
) { \
	static char osName[32]; \
	static int isGened = 0; \
	if (isGened == 0) { \
		snprintf(osName, 32, format MASTER_CONCAT_FALL(MASTER_UNARG_END, arguments) argumentList); \
		isGened = 1; \
	} \
	return osName; \
}

#if defined(_AIX_) || defined(__TOS_AIX__)
#	if defined(_AIX3) || defined(_AIX32)
#		define MASTER_OS_NAME "AIX 3.2"
#	elif defined(_AIX41)
#		define MASTER_OS_NAME "AIX 4.1"
#	elif defined(_AIX43)
#		define MASTER_OS_NAME "AIX 4.3"
#	else
#		define MASTER_OS_NAME "AIX"
#	endif /* #! AIX OS Name !# */
#elif defined(__ANDROID__)
#	ifndef __ANDROID_API__
#		define MASTER_OS_NAME "Android"
#	elif __ANDROID_API__ == 36
#		define MASTER_OS_NAME "Android 16 (Baklava)"
#	elif __ANDROID_API__ == 35
#		define MASTER_OS_NAME "Android 15 (Vanilla Ice Cream)"
#	elif __ANDROID_API__ == 34
#		define MASTER_OS_NAME "Android 14 (Upside Down Cake)"
#	elif __ANDROID_API__ == 33
#		define MASTER_OS_NAME "Android 13 (Tiramisu)"
#	elif __ANDROID_API__ == 32
#		define MASTER_OS_NAME "Android 12L (Snow Cone)"
#	elif __ANDROID_API__ == 31
#		define MASTER_OS_NAME "Android 12 (Snow Cone)"
#	elif __ANDROID_API__ == 30
#		define MASTER_OS_NAME "Android 11 (Red Velvet Cake)"
#	elif __ANDROID_API__ == 29
#		define MASTER_OS_NAME "Android 10 (Quince Tart)"
#	elif __ANDROID_API__ == 28
#		define MASTER_OS_NAME "Android 9 (Pie)"
#	elif __ANDROID_API__ == 27
#		define MASTER_OS_NAME "Android 8.1 (Oreo)"
#	elif __ANDROID_API__ == 26
#		define MASTER_OS_NAME "Android 8.0 (Oreo)"
#	elif __ANDROID_API__ == 25
#		define MASTER_OS_NAME "Android 7.1 (Nougat)"
#	elif __ANDROID_API__ == 24
#		define MASTER_OS_NAME "Android 7.0 (Nougat)"
#	elif __ANDROID_API__ == 23
#		define MASTER_OS_NAME "Android 6 (Marshmallow)"
#	elif __ANDROID_API__ == 22
#		define MASTER_OS_NAME "Android 5.1 (Lollipop)"
#	elif __ANDROID_API__ == 21
#		define MASTER_OS_NAME "Android 5.0 (Lollipop)"
#	elif __ANDROID_API__ == 20
#		define MASTER_OS_NAME "Android 4.4W (KitKat)"
#	elif __ANDROID_API__ == 19
#		define MASTER_OS_NAME "Android 4.4 (KitKat)"
#	elif __ANDROID_API__ == 18
#		define MASTER_OS_NAME "Android 4.3 (Jelly Bean)"
#	elif __ANDROID_API__ == 17
#		define MASTER_OS_NAME "Android 4.2 (Jelly Bean)"
#	elif __ANDROID_API__ == 16
#		define MASTER_OS_NAME "Android 4.1 (Jelly Bean)"
#	elif __ANDROID_API__ == 15
#		define MASTER_OS_NAME "Android 4.0.3 / 4.0.4 (Ice Cream Sandwich)"
#	elif __ANDROID_API__ == 14
#		define MASTER_OS_NAME "Android 4.0.1 / 4.0.2 (Ice Cream Sandwich)"
#	elif __ANDROID_API__ == 13
#		define MASTER_OS_NAME "Android 3.2 (Honeycomb)"
#	elif __ANDROID_API__ == 12
#		define MASTER_OS_NAME "Android 3.1 (Honeycomb)"
#	elif __ANDROID_API__ == 11
#		define MASTER_OS_NAME "Android 3.0 (Honeycomb)"
#	elif __ANDROID_API__ == 10
#		define MASTER_OS_NAME "Android 2.3.3 - 2.3.7 (Gingerbreak)"
#	elif __ANDROID_API__ == 9
#		define MASTER_OS_NAME "Android 2.3.0 - 2.3.2 (Gingerbreak)"
#	elif __ANDROID_API__ == 8
#		define MASTER_OS_NAME "Android 2.2 (Froyo)"
#	elif __ANDROID_API__ == 7
#		define MASTER_OS_NAME "Android 2.1 (Eclair)"
#	elif __ANDROID_API__ == 6
#		define MASTER_OS_NAME "Android 2.0.1 (Eclair)"
#	elif __ANDROID_API__ == 5
#		define MASTER_OS_NAME "Android 2.0 (Eclair)"
#	elif __ANDROID_API__ == 4
#		define MASTER_OS_NAME "Android 1.6 (Donut)"
#	elif __ANDROID_API__ == 3
#		define MASTER_OS_NAME "Android 1.5 (Cupcake)"
#	elif __ANDROID_API__ == 2
#		define MASTER_OS_NAME "Android 1.1 (Petit Four)"
#	elif __ANDROID_API__ == 1
#		define MASTER_OS_NAME "Android 1.0"
#	else
#		define MASTER_OS_NAME "Android - Unknown"
#	endif /* #! Android API !# */
#elif defined(UTS)
#	define MASTER_OS_NAME "Amdahl UTS"
#elif defined(AMIGA) || defined(__amigaos__)
#	define MASTER_OS_NAME "AmigaOs"
#elif defined(aegis)
#	define MASTER_OS_NAME "Apollo AEGIS"
#elif defined(apollo)
#	define MASTER_OS_NAME "Apollo Domain/OS"
#elif defined(__AROS__)
#	define MASTER_OS_NAME "AROS"
#elif defined(__BEOS__)
#	ifndef B_BEOS_VERSION
#		define MASTER_OS_NAME "BeOS"
#	elif B_BEOS_VERSION + 0 == 0x0400
#		define MASTER_OS_NAME "BeOS 4.0"
#	elif B_BEOS_VERSION + 0 == 0x0450
#		define MASTER_OS_NAME "BeOS 4.5"
#	elif B_BEOS_VERSION + 0 == 0x0500
#		define MASTER_OS_NAME "BeOS 5.0"
#	else
#		define MASTER_OS_NAME "BeOS"
#	endif /* #! BeOS Name !# */
#elif defined(__bg__) || defined(__THW_BLUEGENE__)
	/* #! __bqd__, __TOS_BGQ__ !# */
#	define MASTER_OS_NAME "Blue Gene"
#elif defined(_SYSTYPE_BSD)
	/* #! BSD !# */
#	if defined(BSD4_2)
#		define MASTER_OS_NAME "BSD 4.2"
#	elif defined(BSD4_3)
#		define MASTER_OS_NAME "BSD 4.3"
#	elif defined(BSD4_4)
#		define MASTER_OS_NAME "BSD 4.4"
#	else
#		define MASTER_OS_NAME "BSD"
#	endif /* #! BSD Name !# */
#elif defined(__bsdi__)
#	define MASTER_OS_NAME "BSD/OS"
#elif defined(__convex__)
#	define MASTER_OS_NAME "ConvexOS"
#elif defined(__CPM) || defined(CPM)
#	define MASTER_OS_NAME "CP/M"
#elif defined(__CYGWIN__)
#	define MASTER_OS_NAME "Cygwin"
#elif defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#	define MASTER_OS_NAME "DG/UX"
#elif defined(__DragonFly__)
#	define MASTER_OS_NAME "DragonFly"
#elif defined(_SEQUENT_) || defined(sequent)
#	define MASTER_OS_NAME "DYNIX/ptx"
#elif defined(__ECOS)
#	define MASTER_OS_NAME "eCos"
#elif defined(EMSCRIPTEN) || defined(__EMSCRIPTEN__)
#	if defined(__EMSCRIPTEN_major__) && defined(__EMSCRIPTEN_minor__) && defined(__EMSCRIPTEN_tiny__)
#		define MASTER_OS_NAME "Emscripten " MASTER_STRINGIFY_FALL(__EMSCRIPTEN_major__) "." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_minor__) "." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_tiny__)
#	elif defined(__EMSCRIPTEN_major__) && defined(__EMSCRIPTEN_minor__)
#		define MASTER_OS_NAME "Emscripten " MASTER_STRINGIFY_FALL(__EMSCRIPTEN_major__) "." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_minor__)
#	elif defined(__EMSCRIPTEN_major__) && defined(__EMSCRIPTEN_tiny__)
#		define MASTER_OS_NAME "Emscripten " MASTER_STRINGIFY_FALL(__EMSCRIPTEN_major__) ".x." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_tiny__)
#	elif defined(__EMSCRIPTEN_major__)
#		define MASTER_OS_NAME "Emscripten " MASTER_STRINGIFY_FALL(__EMSCRIPTEN_major__)
#	elif defined(__EMSCRIPTEN_minor__) && defined(__EMSCRIPTEN_tiny__)
#		define MASTER_OS_NAME "Emscripten x." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_minor__) "." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_tiny__)
#	elif defined(__EMSCRIPTEN_minor__)
#		define MASTER_OS_NAME "Emscripten x." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_minor__)
#	elif defined(__EMSCRIPTEN_tiny__)
#		define MASTER_OS_NAME "Emscripten x.x." MASTER_STRINGIFY_FALL(__EMSCRIPTEN_tiny__)
#	else
#		define MASTER_OS_NAME "Emscripten"
#	endif /* #! Emscripten Name !# */
#elif defined(__EMX__)
#	define MASTER_OS_NAME "EMX"
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
	/* #! __FreeBSD_version !# */
#	if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#		define MASTER_OS_NAME "GNU/FreeBSD Kernel " MASTER_STRINGIFY_FALL(__FreeBSD__)
#	else
#		define MASTER_OS_NAME "FreeBSD " MASTER_STRINGIFY_FALL(__FreeBSD__)
#	endif /* #! Kernel use !# */
#	define MASTER_PREFER_POSIX_SUPPORTED 1
#elif defined(__Fuchsia__)
#	ifndef __Fuchsia_API_level__
#		define MASTER_OS_NAME "Fuchsia"
#	else
#		define MASTER_OS_NAME "Fuchsia " MASTER_STRINGIFY_FALL(__Fuchsia_API_level__)
#	endif /* #! Fuchsia Name !# */
#elif defined(__GNU__) || defined(__gnu_hurd__)
#	ifdef __GNU__
#		define MASTER_OS_NAME "GNU"
#	else
#		define MASTER_OS_NAME "GNU Hurd"
#	endif /* #! GNU Name !# */
#elif defined(__gnu_linux__)
#	define MASTER_OS_NAME "GNU/Linux"
#elif defined(__HAIKU__)
	/* #! B_HAIKU_VERSION !# */
#	if !defined(B_HAIKU_VERSION)
#		define MASTER_OS_NAME "Haiku"
#	else
#		define MASTER_OS_NAME "Haiku Unknown"
#	endif /* #! Haiku Name !# */
#elif defined(__hiuxmpp)
#	define MASTER_OS_NAME "HI-UX MPP"
#elif defined(__hpux) || defined(_hpux) || defined(hpux)
#	define MASTER_OS_NAME "HP-UX"
#elif defined(__OS400__)
#	if !defined(__OS400_TGTVRM__)
#		define MASTER_OS_NAME "IBM OS/400"
#	else
#		define MASTER_OS_NAME "IBM OS/400 Unknown"
#	endif /* #! OS400 Name !# */
#elif defined(__illumos__)
#	define MASTER_OS_NAME "Illumos"
#elif defined(__INTEGRITY)
#	define MASTER_OS_NAME "INTEGRITY"
#elif defined(__INTERIX)
#	define MASTER_OS_NAME "Interix"
#elif defined(__sgi) || defined(sgi)
#	define MASTER_OS_NAME "IRIX"
#elif defined(__linux__) || defined(__linux) || defined(linux)
#	define MASTER_OS_NAME "Linux"
#	define MASTER_PREFER_POSIX_SUPPORTED 1
#elif defined(__Lynx__)
#	define MASTER_OS_NAME "LynxOS"
#elif defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#	define MASTER_OS_NAME "MacOS"
#	define MASTER_PREFER_POSIX_SUPPORTED 1
#elif defined(__OS9000) || defined(_OSK)
#	define MASTER_OS_NAME "Microware OS-9"
#elif defined(__MidnightBSD__) || defined(__MidnightBSD_kernel__)
	/* #! BSD, __MidnightBSD_version !# */
#	define MASTER_OS_NAME "MidnightBSD"
#elif defined(__minix)
#	define MASTER_OS_NAME "MINIX"
#elif defined(__MINT__)
#	define MASTER_OS_NAME "MiNT"
#elif defined(__MORPHOS__)
#	define MASTER_OS_NAME "MorphOS"
#elif defined(__mpexl) || defined(mpeix)
#	define MASTER_OS_NAME "MPE/iX"
#elif defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__) || defined(MSDOS)
#	define MASTER_OS_NAME "MSDOS"
#elif defined(__MSX) || defined(MSX)
#	define MASTER_OS_NAME "MSX"
#elif defined(__native_client__)
#	define MASTER_OS_NAME "Native Client"
#elif defined(__NetBSD__)
	/* #! BSD, __NetBSD_Version__ !# */
#	define MASTER_OS_NAME "NetBSD"
#elif defined(NeXT)
#	define MASTER_OS_NAME "NeXTSTEP"
#elif defined(__TANDEM)
#	define MASTER_OS_NAME "NonStop"
#elif defined(__nucleus__)
#	define MASTER_OS_NAME "Nucleus RTOS"
#elif defined(__OpenBSD__)
	/* #! BSD !# */
#	define MASTER_OS_NAME "OpenBSD"
#elif defined(__OS2__) || defined(_OS2) || defined(__TOS_OS2__) || defined(OS2)
#	define MASTER_OS_NAME "OS/2"
#elif defined(__palmos__)
#	define MASTER_OS_NAME "Palm OS"
#elif defined(EPLAN9)
#	define MASTER_OS_NAME "Plan 9"
#elif defined(pyr)
#	define MASTER_OS_NAME "Pyramid DC/OSx"
#elif defined(__QNX__) || defined(__QNXNTO__)
#	ifdef BBNDK_VERSION_CURRENT
		MASTER_zzz_OS_GENNAME( "QNX %d.%d.%d", 3, (((BBNDK_VERSION_CURRENT + 0) / 100000000) % 100, ((BBNDK_VERSION_CURRENT + 0) / 1000) % 1000, (BBNDK_VERSION_CURRENT + 0) % 1000) )
#		define MASTER_OS_NAME MASTER_zzz_GetOSName()
#	elif defined(_NTO_VERSION)
		MASTER_zzz_OS_GENNAME( "QNX %d.%d", 2, (((_NTO_VERSION + 0) / 100) % 10, (_NTO_VERSION + 0) % 100) )
#		define MASTER_OS_NAME MASTER_zzz_GetOSName()
#	else
#		define MASTER_OS_NAME "QNX"
#	endif /* #! OS Name !# */
#elif defined(sinux)
#	define MASTER_OS_NAME "Reliant UNIX"
#elif defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
#	define MASTER_OS_NAME "SCO OpenServer"
#elif defined(__serenity__)
#	define MASTER_OS_NAME "SerenityOS"
#elif defined(sun) || defined(__sun)
	/* #! Version !# */
#	define MASTER_OS_NAME "Solaris"
#elif defined(__VOS__)
#	ifdef MASTER_REJECT_STRING_CONCAT
		MASTER_zzz_OS_GENNAME( "Stratus VOS %d", 1, (__VOS__ + 0) )
#		define MASTER_OS_NAME MASTER_zzz_GetOSName()
#	else
#		define MASTER_OS_NAME "Stratus VOS " MASTER_STRINGIFY_FALL(__VOS__)
#	endif /* #! String concatenation !# */
#elif defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#	define MASTER_OS_NAME "SVR4"
#elif defined(__SYLLABLE__)
#	define MASTER_OS_NAME "Syllable"
#elif defined(__SYMBIAN32__)
#	define MASTER_OS_NAME "Symbian OS"
#elif defined(__osf__) || defined(__osf)
#	define MASTER_OS_NAME "Tru64 (OSF/1)"
#elif defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || (defined(unix) && defined(vax))
#	define MASTER_OS_NAME "Ultrix"
#elif defined(_UNICOS)
#	ifdef MASTER_REJECT_STRING_CONCAT
		MASTER_zzz_OS_GENNAME( "UNICOS %d", 1, (_UNICOS + 0) )
#		define MASTER_OS_NAME MASTER_zzz_GetOSName()
#	else
#		define MASTER_OS_NAME "UNICOS " MASTER_STRINGIFY_FALL(_UNICOS)
#	endif /* #! String concatenation !# */
#elif defined(_CRAY) || defined(__crayx1)
#	define MASTER_OS_NAME "UNICOS/mp"
#elif defined(__unix__) || defined(__unix)
#	define MASTER_OS_NAME "UNIX"
#	define MASTER_PREFER_POSIX_SUPPORTED 1
#elif defined(sco) || defined(_UNIXWARE7)
#	define MASTER_OS_NAME "UnixWare"
#elif defined(_UWIN)
#	define MASTER_OS_NAME "U/Win"
#elif defined(VMS) || defined(__VMS)
#	ifdef __VMS_VER
		MASTER_zzz_OS_GENNAME( "VMS %d.%d.%d.%d.%d", 5, (((__VMS_VER + 0) / 10000000) % 100, ((__VMS_VER + 0) / 100000) % 100, ((__VMS_VER + 0) / 10000) % 10, ((__VMS_VER + 0) / 100) % 100, (__VMS_VER + 0) % 100) )
#		define MASTER_OS_NAME MASTER_zzz_GetOSName()
#	else
#		define MASTER_OS_NAME "VMS"
#	endif /* #! OS Name !# */
#elif defined(__VXWORKS__) || defined(__vxworks)
#	if defined(_WRS_VXWORKS_MAJOR) || defined(_WRS_VXWORKS_MINOR) || defined(_WRS_VXWORKS_MAINT)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_OS_GENNAME( "VxWorks %d.%d.%d", 3, (_WRS_VXWORKS_MAJOR + 0, _WRS_VXWORKS_MINOR + 0, _WRS_VXWORKS_MAINT + 0) )
#			define MASTER_OS_NAME MASTER_zzz_GetOSName()
#		else
#			define MASTER_OS_NAME "VxWorks " MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MAJOR) "." MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MINOR) "." MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MAINT)
#		endif /* #! String concatenation !# */
#	elif defined(_WRS_VXWORKS_MAJOR) || defined(_WRS_VXWORKS_MINOR)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_OS_GENNAME( "VxWorks %d.%d.x", 2, (_WRS_VXWORKS_MAJOR + 0, _WRS_VXWORKS_MINOR + 0) )
#			define MASTER_OS_NAME MASTER_zzz_GetOSName()
#		else
#			define MASTER_OS_NAME "VxWorks " MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MAJOR) "." MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MINOR) ".x"
#		endif /* #! String concatenation !# */
#	elif defined(_WRS_VXWORKS_MAJOR) || defined(_WRS_VXWORKS_MAINT)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_OS_GENNAME( "VxWorks %d.x.%d", 2, (_WRS_VXWORKS_MAJOR + 0, _WRS_VXWORKS_MAINT + 0) )
#			define MASTER_OS_NAME MASTER_zzz_GetOSName()
#		else
#			define MASTER_OS_NAME "VxWorks " MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MAJOR) ".x." MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MAINT)
#		endif /* #! String concatenation !# */
#	elif defined(_WRS_VXWORKS_MAJOR)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_OS_GENNAME( "VxWorks %d.x.x", 1, (_WRS_VXWORKS_MAJOR + 0) )
#			define MASTER_OS_NAME MASTER_zzz_GetOSName()
#		else
#			define MASTER_OS_NAME "VxWorks " MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MAJOR) ".x.x"
#		endif /* #! String concatenation !# */
#	elif defined(_WRS_VXWORKS_MINOR) || defined(_WRS_VXWORKS_MAINT)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_OS_GENNAME( "VxWorks x.%d.%d", 2, (_WRS_VXWORKS_MINOR + 0, _WRS_VXWORKS_MAINT + 0) )
#			define MASTER_OS_NAME MASTER_zzz_GetOSName()
#		else
#			define MASTER_OS_NAME "VxWorks x." MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MINOR) "." MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MAINT)
#		endif /* #! String concatenation !# */
#	elif defined(_WRS_VXWORKS_MINOR)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_OS_GENNAME( "VxWorks x.%d.x", 1, (_WRS_VXWORKS_MINOR + 0) )
#			define MASTER_OS_NAME MASTER_zzz_GetOSName()
#		else
#			define MASTER_OS_NAME "VxWorks x." MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MINOR) ".x"
#		endif /* #! String concatenation !# */
#	elif defined(_WRS_VXWORKS_MAINT)
#		ifdef MASTER_REJECT_STRING_CONCAT
			MASTER_zzz_OS_GENNAME( "VxWorks x.x.%d", 1, (_WRS_VXWORKS_MAINT + 0) )
#			define MASTER_OS_NAME MASTER_zzz_GetOSName()
#		else
#			define MASTER_OS_NAME "VxWorks x.x." MASTER_STRINGIFY_FALL(_WRS_VXWORKS_MAINT)
#		endif /* #! String concatenation !# */
#	else
#		define MASTER_OS_NAME "VxWorks"
#	endif /* #! OS Name !# */
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#	if defined(_WIN16) || defined(__WINDOWS__)
#		define MASTER_OS_NAME "Windows 16-bit"
#	elif (defined(_WIN32) || defined(__WIN32__)) && defined(_WIN64)
#		define MASTER_OS_NAME "Windows x86-64"
#	elif defined(_WIN32) || defined(__WIN32__)
#		define MASTER_OS_NAME "Windows x86"
#	elif defined(_WIN64)
#		define MASTER_OS_NAME "Windows x64"
#	else
#		define MASTER_OS_NAME "Windows"
#	endif /* #! Windows OS Name !# */
#	define MASTER_PREFER_WINDOWS_SUPPORTED 1
#elif defined(_WIN32_WCE)
	MASTER_zzz_OS_GENNAME( "Windows CE %d.%d", 2, (((_WIN32_WCE + 0) / 100) % 10, (_WIN32_WCE + 0) % 100) )
#	define MASTER_OS_NAME MASTER_zzz_GetOSName()
#	define MASTER_PREFER_WINDOWS_SUPPORTED 1
#elif defined(_WINDU_SOURCE)
	MASTER_zzz_OS_GENNAME( "Wind/U %d.%d.%d", 3, (((_WINDU_SOURCE + 0) >> 16) & 0xFF, ((_WINDU_SOURCE + 0) >> 8) & 0xFF, (_WINDU_SOURCE + 0) & 0xFF) )
#	define MASTER_OS_NAME MASTER_zzz_GetOSName()
#elif defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#	define MASTER_OS_NAME "MVS"
#elif defined(__VM__) || defined(__HOS_VM__) || defined(__TOS_VM__)
#	define MASTER_OS_NAME "VM"
#else
#	define MASTER_OS_NAME "undefined"
#endif /* #! Operating System !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const unsigned int MASTER_zzz_OS_DETECT_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_OS_DETECT_H !# */

/* #! be master~ !# */
