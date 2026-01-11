
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_ARCHITECTURE_DETECT_INCLUDE_H__
#define __MASTER_ARCHITECTURE_DETECT_INCLUDE_H__

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#if defined(MASTER_ARCHITECTURE_USE_CUSTOM)
#	if !defined(MASTER_ARCHITECTURE_NAME)
#		warning "Custom architecture needs name, printed as ascii string in macros \"MASTER_ARCHITECTURE_NAME\" (optional)"
#	endif /* #! MASTER_ARCHITECTURE_NAME !# */
#	if !defined(MASTER_ARCHITECTURE_CPU_WIDTH)
#		error "Custom architecture needs cpu width in bits, printed as integer in macros \"MASTER_ARCHITECTURE_CPU_WIDTH\""
#	endif /* #! MASTER_ARCHITECTURE_CPU_WIDTH !# */
#	if !defined(MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE)
#		warning "Custom architecture needs instruction type, printed as ascii string in macros \"MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE\" (optional)"
#	endif /* #! MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE !# */
#	if !defined(MASTER_ARCHITECTURE_UNALIGN_FRIENDLY)
#		warning "Custom architecture needs to know about unalign friendly, printed as boolean 1 or 0 in macros \"MASTER_ARCHITECTURE_UNALIGN_FRIENDLY\" (optional)"
#	endif /* #! MASTER_ARCHITECTURE_UNALIGN_FRIENDLY !# */
#	if !defined(MASTER_ARCHITECTURE_ENDIAN)
#		warning "Custom architecture needs to know about endian, printed as macros MASTER_(LITTLE|BIG|PDP|UNKNOWN)_ENDIAN from master_enum.h in macros \"MASTER_ARCHITECTURE_ENDIAN\" (optional)"
#	endif /* #! MASTER_ARCHITECTURE_ENDIAN !# */
#elif defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
#	if defined(__alpha_ev4__)
#		define MASTER_ARCHITECTURE_NAME "Alpha EV4"
#	elif defined(__alpha_ev5__)
#		define MASTER_ARCHITECTURE_NAME "Alpha EV5"
#	elif defined(__alpha_ev6__)
#		define MASTER_ARCHITECTURE_NAME "Alpha EV6"
#	else
#		define MASTER_ARCHITECTURE_NAME "Alpha"
#	endif /* #! Alpha Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 64
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#	define MASTER_ARCHITECTURE_NAME "AMD64"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 64
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"
#	define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
#elif defined(__arm) || defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT)
#	if defined(__ARM_ARCH_2__)
#		define MASTER_ARCHITECTURE_NAME "ARM 2"
#	elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
#		define MASTER_ARCHITECTURE_NAME "ARM 3"
#	elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
#		define MASTER_ARCHITECTURE_NAME "ARM 4T"
#	elif defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5E__) || _M_ARM + 0 == 5
#		define MASTER_ARCHITECTURE_NAME "ARM 5"
#	elif defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__) || defined(__ARM_ARCH_5TEJ__)
#		define MASTER_ARCHITECTURE_NAME "ARM 5T"
#	elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__) || _M_ARM + 0 == 6
#		define MASTER_ARCHITECTURE_NAME "ARM 6"
#	elif defined(__ARM_ARCH_6T2__)
#		define MASTER_ARCHITECTURE_NAME "ARM 6T2"
#	elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__) || _M_ARM + 0 == 7
#		define MASTER_ARCHITECTURE_NAME "ARM 7"
#	else
#		define MASTER_ARCHITECTURE_NAME "ARM"
#	endif /* #! ARM Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__aarch64__) || defined(_M_ARM64)
#	define MASTER_ARCHITECTURE_NAME "ARM64"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 64
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#	define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
#elif defined(__bfin) || defined(__BFIN__) || defined(__ADSPBLACKFIN__)
	/* #! https://www.analog.com/media/en/dsp-documentation/software-manuals/cces-blackfincompiler-library-manual.pdf !# */
#	define MASTER_ARCHITECTURE_NAME "Blackfin"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 16
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "DSP"
#elif defined(__convex__)
#	if defined(__convex_c1__)
#		define MASTER_ARCHITECTURE_NAME "Convex C1"
#	elif defined(__convex_c2__)
#		define MASTER_ARCHITECTURE_NAME "Convex C2"
#	elif defined(__convex_c32__)
#		define MASTER_ARCHITECTURE_NAME "Convex C32xx"
#	elif defined(__convex_c34__)
#		define MASTER_ARCHITECTURE_NAME "Convex C34xx"
#	elif defined(__convex_c38__)
#		define MASTER_ARCHITECTURE_NAME "Convex C38xx"
#	else
#		define MASTER_ARCHITECTURE_NAME "Convex"
#	endif /* #! Convex Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__e2k__)
#	if defined(__elbrus_1cplus__)
#		define MASTER_ARCHITECTURE_NAME "Elbrus 1C+"
#	elif defined(__elbrus_8c__)
#		define MASTER_ARCHITECTURE_NAME "Elbrus 8C"
#	elif defined(__elbrus_2c3__)
#		define MASTER_ARCHITECTURE_NAME "Elbrus 2C3"
#	elif defined(__elbrus_12c__)
#		define MASTER_ARCHITECTURE_NAME "Elbrus 12C"
#	elif defined(__elbrus_16c__)
#		define MASTER_ARCHITECTURE_NAME "Elbrus 16C"
#	else
#		define MASTER_ARCHITECTURE_NAME "Elbrus"
#	endif /* #! Elbrus Architecture Name !# */
	/*
#	define MASTER_ARCHITECTURE_CPU_WIDTH 
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE 
	*/
#elif defined(__epiphany__)
#	define MASTER_ARCHITECTURE_NAME "Epiphany"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
#	if defined(_PA_RISC1_0)
#		define MASTER_ARCHITECTURE_NAME "PA RISC 1.0"
#	elif defined(_PA_RISC1_1) || defined(__HPPA11__) || defined(__PA7100__)
#		define MASTER_ARCHITECTURE_NAME "PA RISC 1.1"
#	elif defined(_PA_RISC2_0) || defined(__RISC2_0__) || defined(__HPPA20__) || defined(__PA8000__)
#		define MASTER_ARCHITECTURE_NAME "PA RISC 2.0"
#	else
#		define MASTER_ARCHITECTURE_NAME "HP/PA RISC"
#	endif /* #! HP/PA RISC Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 64
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__8080__) || defined(__8085__) || defined(__Z80) || defined(__Z180)
#	define MASTER_ARCHITECTURE_NAME "Intel x80"
	/*
#	define MASTER_ARCHITECTURE_CPU_WIDTH 
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE 
#	define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 
	*/
#elif defined(__i386__) || defined(__i386) || defined(i386) || defined(_M_IX86) || defined(_M_I386) || defined(_M_I86) || defined(__IA32__) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
#	if (defined(_M_IX86) && _M_IX86 + 0 == 300) || (defined(__I86__) && __I86__ + 0 == 3)
#		define MASTER_ARCHITECTURE_NAME "Intel 80386"
#	elif (defined(_M_IX86) && _M_IX86 + 0 == 400) || (defined(__I86__) && __I86__ + 0 == 4)
#		define MASTER_ARCHITECTURE_NAME "Intel 80486"
#	elif (defined(_M_IX86) && _M_IX86 + 0 == 500) || (defined(__I86__) && __I86__ + 0 == 5)
#		define MASTER_ARCHITECTURE_NAME "Intel Pentium"
#	elif (defined(_M_IX86) && _M_IX86 + 0 == 600) || (defined(__I86__) && __I86__ + 0 == 6)
#		define MASTER_ARCHITECTURE_NAME "Intel Pentium Pro/II"
#	else
#		define MASTER_ARCHITECTURE_NAME "Intel x86"
#	endif /* #! Intel x86 Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"
#	define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
#elif defined(__ia64__) || defined(__ia64) || defined(_IA64) || defined(__IA64__) || defined(_M_IA64) || defined(__itanium__)
#	define MASTER_ARCHITECTURE_NAME "Itanium IA-64"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 64
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "EPIC"
#	define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
#elif defined(__loongarch__)
#	define MASTER_ARCHITECTURE_NAME "Loong Arch"
	/*
#	define MASTER_ARCHITECTURE_CPU_WIDTH 
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE 
	*/
#elif defined(__m68k__) || defined(__mc68000__) || defined(M68000) || defined(__MC68K__)
#	if defined(__mc68000__) || defined(__MC68000__)
#		define MASTER_ARCHITECTURE_NAME "Motorola 68000"
#	elif defined(__mc68010__)
#		define MASTER_ARCHITECTURE_NAME "Motorola 68010"
#	elif defined(__mc68020__) || defined(__MC68020__)
#		define MASTER_ARCHITECTURE_NAME "Motorola 68020"
#	elif defined(__mc68030__) || defined(__MC68030__)
#		define MASTER_ARCHITECTURE_NAME "Motorola 68030"
#	elif defined(__mc68040__)
#		define MASTER_ARCHITECTURE_NAME "Motorola 68040"
#	elif defined(__mc68060__)
#		define MASTER_ARCHITECTURE_NAME "Motorola 68060"
#	else
#		define MASTER_ARCHITECTURE_NAME "Motorola 68k"
#	endif /* #! Motorola Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"
#elif defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
#	if (defined(_MIPS_ISA_MIPS1) || __mips + 0 == 1) && !defined(_R3000)
#		define MASTER_ARCHITECTURE_NAME "MIPS R2000"
#	elif (defined(_MIPS_ISA_MIPS1) || __mips + 0 == 1) && defined(_R3000)
#		define MASTER_ARCHITECTURE_NAME "MIPS R3000"
#	elif defined(_R4000)
#		define MASTER_ARCHITECTURE_NAME "MIPS R4000"
#	elif defined(_MIPS_ISA_MIPS3) || __mips + 0 == 3 || defined(__MIPS_ISA3__)
#		define MASTER_ARCHITECTURE_NAME "MIPS R4400"
#	elif defined(_MIPS_ISA_MIPS2) || __mips + 0 == 2 || defined(__MIPS_ISA2__)
#		define MASTER_ARCHITECTURE_NAME "MIPS R6000"
#	elif defined(_MIPS_ISA_MIPS4) || __mips + 0 == 4 || defined(__MIPS_ISA4__)
#		define MASTER_ARCHITECTURE_NAME "MIPS R8000 / R10000"
#	else
#		define MASTER_ARCHITECTURE_NAME "MIPS"
#	endif /* #! MIPS Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__ve__) || defined(__ve) || defined(__NEC__)
#	define MASTER_ARCHITECTURE_NAME "NEC SX-Aurora TSUBASA"
	/*
#	define MASTER_ARCHITECTURE_CPU_WIDTH 
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE 
	*/
#elif defined(__pnacl__)
#	define MASTER_ARCHITECTURE_NAME "PNaCl"
	/*
#	define MASTER_ARCHITECTURE_CPU_WIDTH 
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE 
	*/
#elif defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(__powerpc64__) || defined(__ppc) || defined(__ppc__) || defined(__PPC__) || defined(__ppc64__) || defined(__PPC64__) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || defined(_M_PPC)
#	if defined(_ARCH_440)
#		define MASTER_ARCHITECTURE_NAME "PowerPC 440"
#	elif defined(_ARCH_450)
#		define MASTER_ARCHITECTURE_NAME "PowerPC 450"
#	elif defined(_ARCH_601) || defined(__ppc601) || _M_PPC + 0 == 601
#		define MASTER_ARCHITECTURE_NAME "PowerPC 601"
#	elif defined(_ARCH_603) || defined(__ppc603) || _M_PPC + 0 == 603
#		define MASTER_ARCHITECTURE_NAME "PowerPC 603"
#	elif defined(_ARCH_604) || defined(__ppc604) || _M_PPC + 0 == 604
#		define MASTER_ARCHITECTURE_NAME "PowerPC 604"
#	elif defined(_ARCH_620)
#		define MASTER_ARCHITECTURE_NAME "PowerPC 620"
#	else
#		define MASTER_ARCHITECTURE_NAME "PowerPC"
#	endif /* #! PowerPC Architecture Name !# */
#	if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(_ARCH_PPC64)
#		define MASTER_ARCHITECTURE_CPU_WIDTH 64
		/* #! 32 can be tricky !# */
#		define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 1
#	else
#		define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	endif /* #! 64 !# */
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(pyr)
#	define MASTER_ARCHITECTURE_NAME "Pyramid 9810"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"
#elif defined(__riscv) || defined(__riscv_xlen)
#	if defined(__riscv_xlen)
#		define MASTER_ARCHITECTURE_NAME "RISC-V " MASTER_STRINGIFY_FALL(__riscv_xlen)
#	else
#		define MASTER_ARCHITECTURE_NAME "RISC-V"
#	endif /* #! RISC-V Architecture Name !# */
	/*
#	define MASTER_ARCHITECTURE_CPU_WIDTH 
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE 
	*/
#elif defined(__THW_RS6000) || defined(_IBMR2) || defined(_POWER) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_ARCH_PWR3) || defined(_ARCH_PWR4)
#	define MASTER_ARCHITECTURE_NAME "RS/6000"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__sparc) || defined(__sparc__) || defined(__sparc_v8__) || defined(__sparcv8) || defined(__sparc_v9__) || defined(__sparcv9)
#	if defiend(__sparcv8) || defined(__sparc_v8__)
#		define MASTER_ARCHITECTURE_NAME "SPARC v8 / SuperSPARC"
#	elif defiend(__sparcv9) || defined(__sparc_v9__)
#		define MASTER_ARCHITECTURE_NAME "SPARC v9 / UltraSPARC"
#	else
#		define MASTER_ARCHITECTURE_NAME "SPARC"
#	endif /* #! SPARC Architecture Name !# */
#	if defined(__sparc_v9__) || defined(__sparcv9)
#		define MASTER_ARCHITECTURE_CPU_WIDTH 64
#	else
#		define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	endif /* #! V9 !# */
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__sh__) || defined(__sh1__) || defined(__sh2__) || defined(__sh3__) || defined(__sh4__) || defined(__SH3__) || defined(__SH4__) || defined(__SH5__)
#	if defined(__sh1__)
#		define MASTER_ARCHITECTURE_NAME "SuperH 1"
#	elif defined(__sh2__)
#		define MASTER_ARCHITECTURE_NAME "SuperH 2"
#	elif defined(__sh3__) || defined(__SH3__)
#		define MASTER_ARCHITECTURE_NAME "SuperH 3"
#	elif defined(__SH4__)
#		define MASTER_ARCHITECTURE_NAME "SuperH 4"
#	elif defined(__SH5__)
#		define MASTER_ARCHITECTURE_NAME "SuperH 5"
#	else
#		define MASTER_ARCHITECTURE_NAME "SuperH"
#	endif /* #! SuperH Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "RISC"
#elif defined(__370__) || defined(__THW_370__) || defined(__s390__) || defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#	if defined(__370__) || defined(__THW_370__)
#		define MASTER_ARCHITECTURE_NAME "SystemZ /370"
#	elif defined(__s390__)
#		define MASTER_ARCHITECTURE_NAME "SystemZ /390"
#	elif defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#		define MASTER_ARCHITECTURE_NAME "SystemZ /Architecture"
#	else
#		define MASTER_ARCHITECTURE_NAME "SystemZ"
#	endif /* #! SystemZ Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 64
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "CISC"
#elif defined(_TMS320C2XX) || defined(__TMS320C2000__) || defined(_TMS320C5X) || defined(__TMS320C55X__) || defined(_TMS320C6X) || defined(__TMS320C6X__)
#	if defined(_TMS320C28X)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C28x"
#	elif defined(_TMS320C5XX)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C5xx"
#	elif defined(__TMS320C55X__)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C55x"
#	elif defined(_TMS320C6200)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C6200"
#	elif defined(_TMS320C6400)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C6400"
#	elif defined(_TMS320C6400_PLUS)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C6400+"
#	elif defined(_TMS320C6600)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C6600"
#	elif defined(_TMS320C6700)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C6700"
#	elif defined(_TMS320C6700_PLUS)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C6700+"
#	elif defined(_TMS320C6740)
#		define MASTER_ARCHITECTURE_NAME "TMS320 C6740"
#	else
#		define MASTER_ARCHITECTURE_NAME "TMS320"
#	endif /* #! TMS320 Architecture Name !# */
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "DSP"
#elif defined(__TMS470__)
#	define MASTER_ARCHITECTURE_NAME "TMS470"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 32
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "DSP"
#else
#	define MASTER_ARCHITECTURE_NAME "undefined"
#	define MASTER_ARCHITECTURE_CPU_WIDTH 0
#	define MASTER_ARCHITECTURE_INSTRUCTIONS_TYPE "undefined"
#endif /* #! ARCHITECTURE !# */

#ifndef MASTER_ARCHITECTURE_ENDIAN
#	ifdef __BYTE_ORDER__
#		if defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_BIG_ENDIAN
#		elif defined(__ORDER_LITTLE_ENDIAN__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_LITTLE_ENDIAN
#		elif defined(__ORDER_NUXI_ENDIAN__) && __BYTE_ORDER__ == __ORDER_NUXI_ENDIAN__
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_NUXI_ENDIAN
#		elif defined(__ORDER_PDP_ENDIAN__) && __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_PDP_ENDIAN
#		endif /* #! Byte Order !# */
#	endif /* #! __BYTE_ORDER__ !# */
#endif /* #! MASTER_ARCHITECTURE_ENDIAN !# */

#ifndef MASTER_ARCHITECTURE_ENDIAN
#	ifdef __FLOAT_WORD_ORDER__
#		if defined(__ORDER_BIG_ENDIAN__) && __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_BIG_ENDIAN
#		elif defined(__ORDER_LITTLE_ENDIAN__) && __FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_LITTLE_ENDIAN
#		elif defined(__ORDER_NUXI_ENDIAN__) && __FLOAT_WORD_ORDER__ == __ORDER_NUXI_ENDIAN__
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_NUXI_ENDIAN
#		elif defined(__ORDER_PDP_ENDIAN__) && __FLOAT_WORD_ORDER__ == __ORDER_PDP_ENDIAN__
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_PDP_ENDIAN
#		endif /* #! Byte Order !# */
#	endif /* #! Detecting !# */
#endif /* #! MASTER_ARCHITECTURE_ENDIAN !# */

#ifndef MASTER_ARCHITECTURE_ENDIAN
#	if defined(__LITTLE_ENDIAN__) || \
	   defined(__ARMEL__) || \
	   defined(__THUMBEL__) || \
	   defined(__AARCH64EL__) || \
	   defined(_MIPSEL) || \
	   defined(__MIPSEL) || \
	   defined(__MIPSEL__) || \
	   defined(__amd64__) || \
	   defined(__x86_64__) || \
	   defined(_M_X64) || \
	   defined(__i386__) || \
	   defined(_M_IX86) || \
	   defined(__alpha__) || \
	   defined(__ia64__) || \
	   defined(_M_IA64) || \
	   defined(__bfin)
#		define MASTER_ARCHITECTURE_ENDIAN MASTER_LITTLE_ENDIAN
#	elif defined(__BIG_ENDIAN__) || \
		 defined(__ARMEB__) || \
		 defined(__THUMBEB__) || \
		 defined(__AARCH64EB__) || \
		 defined(_MIPSEB) || \
		 defined(__MIPSEB) || \
		 defined(__MIPSEB__) || \
		 defined(__m68k__) || \
		 defined(__sparc__) || \
		 defined(__hppa__) || \
		 defined(__s390x__) || \
		 defined(__zarch__) || \
		 defined(pyr)
#		define MASTER_ARCHITECTURE_ENDIAN MASTER_BIG_ENDIAN
#	elif defined(__arm__) || defined(__aarch64__)
#		define MASTER_ARCHITECTURE_ENDIAN MASTER_LITTLE_ENDIAN
#	elif defined(__powerpc__) || defined(__ppc__) || defined(_ARCH_PPC)
#		if defined(_LITTLE_ENDIAN)
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_LITTLE_ENDIAN
#		else
#			define MASTER_ARCHITECTURE_ENDIAN MASTER_BIG_ENDIAN
#		endif /* #! POWERPC !# */
#	elif defined(__mips__)
#		define MASTER_ARCHITECTURE_ENDIAN MASTER_BIG_ENDIAN
#	endif /* #! Architecture Endian !# */
#endif /* #! MASTER_ARCHITECTURE_ENDIAN !# */

#if !defined(MASTER_ARCHITECTURE_UNALIGN_FRIENDLY)
#	define MASTER_ARCHITECTURE_UNALIGN_FRIENDLY 0
#endif /* #! ARCHITECTURE UNALIGN FRIENDLY !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_ARCHITECTURE_DETECT_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_ARCHITECTURE_DETECT_INCLUDE_H__ !# */

/* #! be master~ !# */
