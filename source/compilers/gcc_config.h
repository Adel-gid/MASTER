
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_GCC_CONFIG_INCLUDE_H
#define MASTER_zRIVATE_GCC_CONFIG_INCLUDE_H

#include <master_enum.h>

#if !defined(MASTER_zRIVATE_COMPILER_FEATURES_LOADED) && !defined(MASTER_NO_COMPILER_FEATURES)

MASTER_BEGIN_DECLARATIONS

#define MASTER_COMPILER_C89_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_C95_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_C99_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_C11_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_C17_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_C23_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_CPP98_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_CPP03_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_CPP11_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_CPP14_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_CPP17_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_CPP20_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_CPP23_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_GNU_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_GNUPP_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_TRIGRAPH_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_COM_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_EXE_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_ELF_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_BIN_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_PE_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_MACH_O_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_COFF_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_XCOFF_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_SHARED_LIB_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_OBJ_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_ASM_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_PREPROC_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_COMPILE_TYPE 0 /* #! Default Value !# */
#define MASTER_COMPILER_ARCH64_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_ARM_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_THUMB_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_MIPS_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_PPC_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_PPC64_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_MIPS64_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_X86_64_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_I386_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_X16_COMPILE_AVAILABLE MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_SIZEOF_POINTER sizeof(void *) /* #! Default Value !# */
#define MASTER_COMPILER_SIZEOF_CHAR sizeof(char) /* #! Default Value !# */
#define MASTER_COMPILER_SIZEOF_SHORT sizeof(short) /* #! Default Value !# */
#define MASTER_COMPILER_SIZEOF_INT sizeof(int) /* #! Default Value !# */
#define MASTER_COMPILER_SIZEOF_LONG sizeof(long) /* #! Default Value !# */
#define MASTER_COMPILER_SIZEOF_LONG_LONG sizeof(long long) /* #! Default Value !# */
#define MASTER_COMPILER_SIZEOF_SIZE_T sizeof(size_t) /* #! Default Value !# */
#define MASTER_COMPILER_BYTE_ALIGN_UNDER_QUESTION /* #! Default Value !# */
#define MASTER_COMPILER_HAS_SIGNED_INT_8 MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_HAS_SIGNED_INT_16 MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_HAS_SIGNED_INT_32 MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_HAS_SIGNED_INT_64 MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_HAS_UNSIGNED_INT_8 MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_HAS_UNSIGNED_INT_16 MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_HAS_UNSIGNED_INT_32 MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_COMPILER_HAS_UNSIGNED_INT_64 MASTER_UNKNOWN /* #! Default Value !# */
#define MASTER_PREFER_OPTIMIZE /* #! Default Value !# */
#define MASTER_PREFER_NOOPTIMIZE /* #! Default Value !# */
#define MASTER_PREFER_NOINLINE /* #! Default Value !# */
#ifdef __cplusplus
#	define MASTER_PREFER_INLINE inline /* #! Default Value !# */
#else
#	if defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 199901L
#define MASTER_PREFER_INLINE inline /* #! Default Value !# */
#	else
#define MASTER_PREFER_INLINE /* #! Default Value !# */
#	endif /* #! C99+ !# */
#endif /* #! C++ !# */
#define MASTER_PREFER_FORCE_INLINE /* #! Default Value !# */
#if defined(__GNUC__) && (__GNUC__ + 0 > 3 || (defined(__GNUC_MINOR__) && __GNUC__ + 0 == 3 && __GNUC_MINOR__ + 0 >= 1))
#	define MASTER_PREFER_RESTRICT __restrict
#endif /* #! Restrict !# */
/* #! DEFINE RESTRICT OUT !# */
#ifdef __cplusplus
#	define MASTER_PREFER_EXTERN extern /* #! Default Value !# */
#else
#	define MASTER_PREFER_EXTERN /* #! Default Value !# */
#endif /* #! C++ !# */
#define MASTER_PREFER_STATIC static /* #! Default Value !# */
#define MASTER_PREFER_ASM_VOLATILE __asm__ /* #! Default Value !# */
#define MASTER_PREFER_VALUE_REQUIRED /* #! Default Value !# */
#define MASTER_PREFER_RETURN_REQUIRED /* #! Default Value !# */
#define MASTER_PREFER_WARN( message ) /* #! Default Value !# */
#define MASTER_PREFER_ERROR( message ) /* #! Default Value !# */
#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 201710L)
#	define MASTER_PREFER_OUTDATED [[deprecated]] /* #! Default Value !# */
#else
#	define MASTER_PREFER_OUTDATED /* #! Default Value !# */
#endif /* #! C++ / C17+ !# */
#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 202311L)
#	define MASTER_PREFER_UNUSED [[maybe_unused]] /* #! Default Value !# */
#else
#	define MASTER_PREFER_UNUSED /* #! Default Value !# */
#endif /* #! C++ / C23+ !# */
#define MASTER_PREFER_UNSAFE /* #! Default Value !# */
#define MASTER_PREFER_NO_RETURN /* #! Default Value !# */
#define MASTER_PREFER_WEAK /* #! Default Value !# */
#define MASTER_PREFER_LIKELY( expression ) (expression) /* #! Default Value !# */
#define MASTER_PREFER_UNLIKELY( expression ) (expression) /* #! Default Value !# */
#define MASTER_PREFER_UNREACHABLE /* #! Default Value !# */
#define MASTER_PREFER_FALLTHROUGH /* #! Default Value !# */
#define MASTER_PREFER_HOT /* #! Default Value !# */
#define MASTER_PREFER_COLD /* #! Default Value !# */
#define MASTER_PREFER_FAR /* #! Default Value !# */
#define MASTER_PREFER_NEAR /* #! Default Value !# */
#define MASTER_PREFER_INTERRUPT /* #! Default Value !# */
#define MASTER_PREFER_SEGMENT /* #! Default Value !# */
#define MASTER_PREFER_PACKED /* #! Default Value !# */
#define MASTER_PREFER_INLINEOUS /* #! Default Value !# */
#define MASTER_PREFER_TYPEOF( expression ) /* #! Default Value !# */
#define MASTER_PREFER_STATIC_ASSERT( expression, message ) /* #! Default Value !# */
#define MASTER_PREFER_CONSTRUCTOR /* #! Default Value !# */
#define MASTER_PREFER_DESTRUCTOR /* #! Default Value !# */
#define MASTER_PREFER_FUNCTION_NAKED /* #! Default Value !# */
#define MASTER_PREFER_FUNCTION_MALLOC /* #! Default Value !# */
#define MASTER_PREFER_FUNCTION_PURE /* #! Default Value !# */
#define MASTER_PREFER_FUNCTION_CONST /* #! Default Value !# */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 201112L
#	define MASTER_PREFER_ALIGNAS( align_value ) _Alignas(align_value) /* #! Default Value !# */
#elif defined(__cplusplus) && __cplusplus + 0 >= 201103L
#	define MASTER_PREFER_ALIGNAS( align_value ) alignas(align_value) /* #! Default Value !# */
#else
#	define MASTER_PREFER_ALIGNAS( align_value ) /* #! Default Value !# */
#endif /* #! Align as !# */
#define MASTER_PREFER_IMPORT /* #! Default Value !# */
#define MASTER_PREFER_EXPORT /* #! Default Value !# */
#define MASTER_PREFER_VISIBLE /* #! Default Value !# */
#define MASTER_PREFER_HIDDEN /* #! Default Value !# */
#define MASTER_PREFER_MAY_ALIAS /* #! Default Value !# */
#define MASTER_PREFER_PREFETCH( pointer ) ((void)(pointer)) /* #! Default Value !# */
#define MASTER_PREFER_PUSH_POP_AVAILABLE (0) /* #! Default Value !# */

#define MASTER_zRIVATE_COMPILER_FEATURES_LOADED 1

MASTER_END_DECLARATIONS

#endif /* #! Compiler features !# */

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_GCC_CONFIG_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_GCC_CONFIG_INCLUDE_H !# */

/* #! be master~ !# */
