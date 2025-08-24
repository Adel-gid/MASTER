
/*
 * Copyright (c) 2025 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_ARCHITECTURE_DETECT_INCLUDE_H__
#define __MASTER_ARCHITECTURE_DETECT_INCLUDE_H__

#include <master_enum.h>

#if defined(MASTER_ARCHITECTURE_USE_CUSTOM)
	#if !defined(MASTER_ARCHITECTURE_NAME)
		#warning "Custom architecture needs name, printed as ascii string in macros \"MASTER_ARCHITECTURE_NAME\" (optional)"
	#endif /* #! MASTER_ARCHITECTURE_NAME !# */
	#if !defined(MASTER_ARCHITECTURE_CPU_WIDTH)
		#error "Custom architecture needs cpu width in bits, printed as integer in macros \"MASTER_ARCHITECTURE_CPU_WIDTH\""
	#endif /* #! MASTER_ARCHITECTURE_CPU_WIDTH !# */
	#if !defined(MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE)
		#warning "Custom architecture needs instruction type, printed as ascii string in macros \"MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE\" (optional)"
	#endif /* #! MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE !# */
	#if !defined(MASTER_ARCHITECTURE_UNALIGN_FRIENDLY)
		#warning "Custom architecture needs to know about unalign friendly, printed as boolean 1 or 0 in macros \"MASTER_ARCHITECTURE_UNALIGN_FRIENDLY\" (optional)"
	#endif /* #! MASTER_ARCHITECTURE_UNALIGN_FRIENDLY !# */
	
#elif defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
	#define MASTER_ARCHITECTURE_NAME "Alpha"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 64
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
	
#elif defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
	#define MASTER_ARCHITECTURE_NAME "AMD64"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 64
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"
	#define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
	
#elif defined(__i386__) || defined(__i386) || defined(i386) || defined(_M_IX86) || defined(_M_I386) || defined(__IA32__) || defined(__X86__) || defined(_X86_)
	#define MASTER_ARCHITECTURE_NAME "x86"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"
	#define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
	
#elif defined(__ia64__) || defined(__ia64) || defined(_IA64) || defined(__IA64__) || defined(_M_IA64) || defined(__itanium__)
	#define MASTER_ARCHITECTURE_NAME "Itanium IA-64"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 64
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "EPIC"
	#define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
	
#elif defined(__arm__) || defined(__TARGET_ARCH_ARM) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT)
	#define MASTER_ARCHITECTURE_NAME "ARM"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
	
#elif defined(__aarch64__) || defined(__ARM_ARCH_ISA_A64)
	#define MASTER_ARCHITECTURE_NAME "ARM64"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 64
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
	#define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
	
#elif defined(__bfin) || defined(__BFIN__)
	#define MASTER_ARCHITECTURE_NAME "Blackfin"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 16
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "DSP"
	
#elif defined(__convex__)
	#define MASTER_ARCHITECTURE_NAME "Convex"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
	
#elif defined(__epiphany__)
	#define MASTER_ARCHITECTURE_NAME "Epiphany"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
	
#elif defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
	#define MASTER_ARCHITECTURE_NAME "HP/PA RISC"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 64
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
	
#elif defined(__m68k__) || defined(__mc68000__) || defined(M68000) || defined(__MC68K__)
	#define MASTER_ARCHITECTURE_NAME "Motorola 68k"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"
	
#elif defined(__mips__) || defined(mips) || defined(__MIPS__)
	#define MASTER_ARCHITECTURE_NAME "MIPS"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
	
#elif defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(_ARCH_PPC64) || defined(__powerpc__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
	#if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(_ARCH_PPC64)
		#define MASTER_ARCHITECTURE_CPU_WIDTH 64
		/* #! 32 can be tricky !# */
		#define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
	#else
		#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#endif /* #! 64 !# */
	#define MASTER_ARCHITECTURE_NAME "PowerPC"
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"

#elif defined(pyr)
	#define MASTER_ARCHITECTURE_NAME "Pyramid 9810"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"

#elif defined(__THW_RS6000) || defined(_IBMR2) || defined(_POWER) || defined(_ARCH_PWR)
	#define MASTER_ARCHITECTURE_NAME "RS/6000"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"

#elif defined(__sparc_v9__) || defined(__sparcv9) || defined(__sparc_v8__) || defined(__sparcv8) || defined(__sparc__)
	#if defined(__sparc_v9__) || defined(__sparcv9)
		#define MASTER_ARCHITECTURE_CPU_WIDTH 64
	#else
		#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#endif /* #! V9 !# */
	#define MASTER_ARCHITECTURE_NAME "SPARC"
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"

#elif defined(__sh4__) || defined(__sh3__) || defined(__sh2__) || defined(__sh1__)
	#define MASTER_ARCHITECTURE_NAME "SuperH"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"

#elif defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__) || defined(__s390__)
	#define MASTER_ARCHITECTURE_NAME "SystemZ"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 64
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"

#elif defined(_TMS320C2000_) || defined(__TMS320C2000__) || defined(_TMS320C5X_) || defined(__TMS320C55X__) || defined(_TMS320C6X_) || defined(__TMS320C6X__)
	#define MASTER_ARCHITECTURE_NAME "TMS320"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "DSP"

#elif defined(__TMS470__)
	#define MASTER_ARCHITECTURE_NAME "TMS470"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 32
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "DSP"

#else
	#define MASTER_ARCHITECTURE_NAME "undefined"
	#define MASTER_ARCHITECTURE_CPU_WIDTH 0
	#define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "undefined"

#endif /* #! ARCHITECTURE !# */

#if !defined(MASTER_ARCHITECTURE_UNALIGN_FRIENDLY)
	#define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 0
#endif /* #! ARCHITECTURE UNALIGN FRIENDLY !# */

#endif /* #! __MASTER_ARCHITECTURE_DETECT_INCLUDE_H__ !# */

/* #! be master~ !# */
