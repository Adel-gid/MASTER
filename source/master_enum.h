
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_CODE_STYLE_INCLUDE_H
#define MASTER_zRIVATE_CODE_STYLE_INCLUDE_H

#define MASTER_VERSION (((11) << 18) | ((1) << 14) | (2026))

/* #! MASTER Minimal Package !# */

typedef unsigned char UI1;
typedef unsigned short UI2;
typedef unsigned int UI4;
typedef signed char SI1;
typedef signed short SI2;
typedef signed int SI4;

typedef UI4 OUI; /* #! Unknown type but prefers unsigned int !# */
typedef SI4 OSI; /* #! Unknown type but prefers signed int !# */
typedef double UF; /* #! Unknown type but prefers float !# */
typedef UI4 UT; /* #! Unknown type !# */

#define MASTER_8BIT_NUMBER UI1
#define MASTER_16BIT_NUMBER UI2
#define MASTER_32BIT_NUMBER UI4
#define MASTER_64BIT_NUMBER UI8

/* #! MASTER Syntax !# */

#define otherwise else if
#define nul 0

/* #! MASTER Predefined Macroses !# */

/* #!! K&R !!# */
#define MASTER_LINE __LINE__
#define MASTER_FILE __FILE__

/* #!! C89 !!# */
#define MASTER_DATE __DATE__
#define MASTER_TIME __TIME__
#define MASTER_STDC __STDC__

/* #!! C99 !!# */
#define MASTER_FUNC __func__

/* #! compiler trash !# */

#define MASTER_UNKNOWN (-1)
#define MASTER_UNSUPPORTING (0)
#define MASTER_PARTIAL_SUPPORTING (5)
#define MASTER_SUPPORTING (10)
#define MASTER_SUPPORT_STATE( nivel ) (nivel)

#ifdef __cplusplus
#	define MASTER_BEGIN_DECLARATIONS extern "C" {
#	define MASTER_END_DECLARATIONS }
#else
#	define MASTER_BEGIN_DECLARATIONS
#	define MASTER_END_DECLARATIONS
#endif /* #! C++ !# */

MASTER_BEGIN_DECLARATIONS

#if !defined(MASTER_NO_COMPILER_SETTINGS_DEPENDENCY)
#	include <compiler_detect.h>
#endif /* #! compiler_detect.h !# */
#ifndef MASTER_zRIVATE_COMPILER_FEATURES_LOADED
#	define MASTER_COMPILER_C89_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_C95_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_C99_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_C11_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_C17_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_C23_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_CPP98_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_CPP03_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_CPP11_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_CPP14_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_CPP17_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_CPP20_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_CPP23_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_GNU_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_GNUPP_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_TRIGRAPH_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_COM_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_EXE_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_ELF_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_BIN_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_PE_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_MACH_O_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_COFF_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_XCOFF_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_SHARED_LIB_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_OBJ_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_ASM_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_PREPROC_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_COMPILE_TYPE
#	define MASTER_COMPILER_ARCH64_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_ARM_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_THUMB_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_MIPS_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_PPC_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_PPC64_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_MIPS64_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_X86_64_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_I386_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_X16_COMPILE_AVAILABLE MASTER_UNKNOWN
#	define MASTER_COMPILER_SIZEOF_POINTER sizeof(void *)
#	define MASTER_COMPILER_SIZEOF_CHAR sizeof(char)
#	define MASTER_COMPILER_SIZEOF_SHORT sizeof(short)
#	define MASTER_COMPILER_SIZEOF_INT sizeof(int)
#	define MASTER_COMPILER_SIZEOF_LONG sizeof(long)
#	define MASTER_COMPILER_SIZEOF_LONG_LONG sizeof(long long)
#	define MASTER_COMPILER_SIZEOF_SIZE_T sizeof(size_t)
#	define MASTER_COMPILER_BYTE_ALIGN_UNDER_QUESTION
#	define MASTER_COMPILER_HAS_SIGNED_INT_8 MASTER_UNKNOWN
#	define MASTER_COMPILER_HAS_SIGNED_INT_16 MASTER_UNKNOWN
#	define MASTER_COMPILER_HAS_SIGNED_INT_32 MASTER_UNKNOWN
#	define MASTER_COMPILER_HAS_SIGNED_INT_64 MASTER_UNKNOWN
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_8 MASTER_UNKNOWN
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_16 MASTER_UNKNOWN
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_32 MASTER_UNKNOWN
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_64 MASTER_UNKNOWN
#	define MASTER_PREFER_OPTIMIZE
#	define MASTER_PREFER_NOOPTIMIZE
#	define MASTER_PREFER_NOINLINE
#	ifdef __cplusplus
#		define MASTER_PREFER_INLINE inline
#	else
#		if defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 199901L
#			define MASTER_PREFER_INLINE inline
#		else
#			define MASTER_PREFER_INLINE
#		endif /* #! C99+ !# */
#	endif /* #! C++ !# */
#	define MASTER_PREFER_FORCE_INLINE
#	ifdef __cplusplus
#		define MASTER_PREFER_EXTERN extern
#	else
#		define MASTER_PREFER_EXTERN
#	endif /* #! C++ !# */
#	define MASTER_PREFER_STATIC static
#	define MASTER_PREFER_ASM_VOLATILE __asm__
#	define MASTER_PREFER_VALUE_REQUIRED
#	define MASTER_PREFER_RETURN_REQUIRED
#	define MASTER_PREFER_WARN( message )
#	define MASTER_PREFER_ERROR( message )
#	if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 201710L)
#		define MASTER_PREFER_OUTDATED [[deprecated]]
#	else
#		define MASTER_PREFER_OUTDATED
#	endif /* #! C++ / C17+ !# */
#	if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 202311L)
#		define MASTER_PREFER_UNUSED [[maybe_unused]]
#	else
#		define MASTER_PREFER_UNUSED
#	endif /* #! C++ / C23+ !# */
#	define MASTER_PREFER_UNSAFE
#	define MASTER_PREFER_NO_RETURN
#	define MASTER_PREFER_WEAK
#	define MASTER_PREFER_LIKELY( expression ) (expression)
#	define MASTER_PREFER_UNLIKELY( expression ) (expression)
#	define MASTER_PREFER_UNREACHABLE
#	define MASTER_PREFER_FALLTHROUGH
#	define MASTER_PREFER_HOT
#	define MASTER_PREFER_COLD
#	define MASTER_PREFER_FAR
#	define MASTER_PREFER_NEAR
#	define MASTER_PREFER_INTERRUPT
#	define MASTER_PREFER_SEGMENT
#	define MASTER_PREFER_PACKED
#	define MASTER_PREFER_INLINEOUS
#	define MASTER_PREFER_TYPEOF( expression )
#	define MASTER_PREFER_STATIC_ASSERT( expression, message )
#	define MASTER_PREFER_CONSTRUCTOR
#	define MASTER_PREFER_DESTRUCTOR
#	define MASTER_PREFER_FUNCTION_NAKED
#	define MASTER_PREFER_FUNCTION_MALLOC
#	define MASTER_PREFER_FUNCTION_PURE
#	define MASTER_PREFER_FUNCTION_CONST
#	if defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 201112L
#		define MASTER_PREFER_ALIGNAS( align_value ) _Alignas(align_value)
#	elif defined(__cplusplus) && __cplusplus + 0 >= 201103L
#		define MASTER_PREFER_ALIGNAS( align_value ) alignas(align_value)
#	else
#		define MASTER_PREFER_ALIGNAS( align_value )
#	endif /* #! Align as !# */
#	define MASTER_PREFER_IMPORT
#	define MASTER_PREFER_EXPORT
#	define MASTER_PREFER_VISIBLE
#	define MASTER_PREFER_HIDDEN
#	define MASTER_PREFER_MAY_ALIAS
#	define MASTER_PREFER_PREFETCH( pointer ) ((void)(pointer))
#	define MASTER_PREFER_PUSH_POP_AVAILABLE (0)
#	define MASTER_zRIVATE_COMPILER_FEATURES_LOADED 0
#endif /* #! Compiler / Standard !# */
#ifndef MASTER_PREFER_RESTRICT
#	if defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 199901L
#		define MASTER_PREFER_RESTRICT restrict
#	else
#		define MASTER_PREFER_RESTRICT
#	endif /* #! C99+ !# */
#endif /* #! Restrict !# */
#ifdef MASTER_NO_RESTRICTIONS
#	undef MASTER_PREFER_RESTRICT
#	define MASTER_PREFER_RESTRICT
#endif /* #! Turn off restrictions !# */

#define MASTER_PREFER_NONNULL MASTER_PREFER_VALUE_REQUIRED
#define MASTER_PREFER_DEPRECATED MASTER_PREFER_OUTDATED

#if defined(__has_include) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_INCLUDE( include_file ) __has_include(include_file)
#else
#	define MASTER_COMPILER_HAS_INCLUDE( include_file ) (0)
#endif /* #! Has include !# */
#if defined(__has_attribute) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_ATTRIBUTE( attribute ) __has_attribute(attribute)
#else
#	define MASTER_COMPILER_HAS_ATTRIBUTE( attribute ) (0)
#endif /* #! Has attribute !# */
#if defined(__has_builtin) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_BUILTIN( builtin_method ) __has_builtin(builtin_method)
#else
#	define MASTER_COMPILER_HAS_BUILTIN( builtin_method ) (0)
#endif /* #! Has builtin !# */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L && defined(__has_c_attribute) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_C_ATTRIBUTE( attribute ) __has_c_attribute(attribute)
#else
#	define MASTER_COMPILER_HAS_C_ATTRIBUTE( attribute ) (0)
#endif /* #! Has C attribute !# */
#if defined(__cplusplus) && defined(__has_cpp_attribute) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_CPP_ATTRIBUTE( attribute ) __has_cpp_attribute(attribute)
#else
#	define MASTER_COMPILER_HAS_CPP_ATTRIBUTE( attribute ) (0)
#endif /* #! Has C++ attribute !# */

/*
#ifdef __cplusplus
#	define MASTER_PREFER_INLINE inline
#else
#	if defined(__GNUC__) || defined(_MSC_VER)
#		define MASTER_PREFER_INLINE __inline
#	elif defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 199901L
#		define MASTER_PREFER_INLINE inline
#	else
#		define MASTER_PREFER_INLINE
#	endif
#endif
#if defined(__GNUC__) || defined(__clang__)
#	define MASTER_PREFER_FORCE_INLINE __inline__ __attribute__((__always_inline__))
#	define MASTER_PREFER_NO_INLINE __attribute__((__noinline__))
#elif defined(_MSC_VER)
#	define MASTER_PREFER_FORCE_INLINE __forceinline
#	define MASTER_PREFER_NO_INLINE __declspec(noinline)
#else
#	define MASTER_PREFER_FORCE_INLINE MASTER_PREFER_INLINE
#	define MASTER_PREFER_NO_INLINE
#endif
#define MASTER_PREFER_STATIC static
#if ((defined(sum) || defined(__sun))) && defined(__cplusplus)
#	define MASTER_PREFER_RESTRICT
#elif defined(__clang__) || \
	  (defined(_MSC_VER) && (_MSC_VER + 0 >= 1400)) || \
	  (defined(__INTEL_COMPILER) && (__INTEL_COMPILER + 0 >= 1300))
#	define MASTER_PREFER_RESTRICT __restrict
#else
#	define MASTER_PREFER_RESTRICT
#endif
#ifdef __cplusplus
#	define MASTER_PREFER_EXTERN extern
#else
#	define MASTER_PREFER_EXTERN
#endif
#define MASTER_PREFER_HOT
#define MASTER_PREFER_COLD
#define MASTER_PREFER_VISIBLE
#define MASTER_PREFER_HIDDEN
#if defined(__GNUC__)
#	define MASTER_PREFER_UNUSED __attribute__((__unused__))
#elif defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 202311L)
#	define MASTER_PREFER_UNUSED [[maybe_unused]]
#else
#	define MASTER_PREFER_UNUSED
#endif
#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 201710L)
#	define MASTER_PREFER_OUTDATED [[deprecated]]
#else
#	define MASTER_PREFER_OUTDATED
#endif
#if defined(_WIN32) && defined(_MSC_VER)
#	define MASTER_PREFER_EXPORT __declspec(dllexport)
#else
#	define MASTER_PREFER_EXPORT
#endif
#if defined(_WIN32) && defined(_MSC_VER)
#	define MASTER_PREFER_IMPORT __declspec(dllimport)
#else
#	define MASTER_PREFER_IMPORT
#endif
#ifdef __GNUC__
#	define MASTER_PREFER_FUNCTION_CONST __attribute__((__const__))
#	define MASTER_PREFER_FUNCTION_PURE __attribute__((__pure__))
#	define MASTER_PREFER_FUNCTION_MALLOC __attribute__((__malloc__))
#else
#	define MASTER_PREFER_FUNCTION_CONST
#	define MASTER_PREFER_FUNCTION_PURE
#	define MASTER_PREFER_FUNCTION_MALLOC
#endif
#if MASTER_COMPILER_HAS_C_ATTRIBUTE(fallthrough) || MASTER_COMPILER_HAS_CPP_ATTRIBUTE(fallthrough)
#	define MASTER_PREFER_FALLTHROUGH [[fallthrough]]
#elif MASTER_COMPILER_HAS_ATTRIBUTE(__fallthrough__)
#	define MASTER_PREFER_FALLTHROUGH __attribute__((__fallthrough__))
#else
#	define MASTER_PREFER_FALLTHROUGH
#endif
#if MASTER_COMPILER_HAS_ATTRIBUTE(noescape)
#	define MASTER_PREFER_NOESCAPE __attribute__((__noescape__))
#else
#	define MASTER_PREFER_NOESCAPE
#endif
#if MASTER_COMPILER_HAS_BUILTIN(__builtin_unreachable)
#	define MASTER_PREFER_UNREACHABLE __builtin_unreachable()
#elif defined(_MSC_VER)
#	define MASTER_PREFER_UNREACHABLE __assume(0)
#else
#	define MASTER_PREFER_UNREACHABLE
#endif
#if MASTER_COMPILER_HAS_BUILTIN(__builtin_assume)
#	define MASTER_PREFER_ASSUME( expression ) __builtin_assume(expression)
#else
#	define MASTER_PREFER_ASSUME( expression ) if (!(expression)) { MASTER_PREFER_UNREACHABLE; }
#endif
#if (defined(__GNUC__) && __GNUC__ + 0 >= 3) || (defined(__INTEL_COMPILER) && __INTEL_COMPILER + 0 >= 800) || defined(__clang__)
#	define MASTER_PREFER_LIKELY( expression ) __builtin_expect(expression, 1)
#	define MASTER_PREFER_UNLIKELY( expression ) __builtin_expect(expression, 0)
#else
#	define MASTER_PREFER_LIKELY( expression )
#	define MASTER_PREFER_UNLIKELY( expression )
#endif
#if defined(__GNUC__) || defined(__clang__)
#	define MASTER_PREFER_MAY_ALIAS __attribute__((__may_alias__))
#else
#	define MASTER_PREFER_MAY_ALIAS
#endif
#if defined(__GNUC__) && (__GNUC__ + 0 >= 4 || (__GNUC__ + 0 == 3 && __GNUC_MINOR__ + 0 >= 1))
#	define MASTER_PREFER_PREFETCH( pointer ) __builtin_prefetch(pointer, 0, 3)
#else
#	define MASTER_PREFER_PREFETCH( pointer ) ((void)(pointer))
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 201112L
#	define MASTER_PREFER_ALIGNAS( align_value ) _Alignas(align_value)
#	define MASTER_PREFER_MEMBER_ALIGN( align_value, variable_type ) variable_type MASTER_PREFER_ALIGNAS(align_value)
#	define MASTER_PREFER_VARIABLE_ALIGN( align_value, variable_type, variable_name ) variable_type MASTER_PREFER_ALIGNAS(align_value) variable_name
#elif defined(__cplusplus) && __cplusplus + 0 >= 201103L
#	define MASTER_PREFER_ALIGNAS( align_value ) alignas(align_value)
#	define MASTER_PREFER_MEMBER_ALIGN( align_value, variable_type ) variable_type MASTER_PREFER_ALIGNAS(align_value)
#	define MASTER_PREFER_VARIABLE_ALIGN( align_value, variable_type, variable_name ) variable_type MASTER_PREFER_ALIGNAS(align_value) variable_name
#elif defined(__GNUC__)
#	define MASTER_PREFER_ALIGNAS( align_value ) __attribute__((aligned(align_value)))
#	define MASTER_PREFER_MEMBER_ALIGN( align_value, variable_type ) MASTER_PREFER_ALIGNAS(align_value) variable_type

#	define MASTER_PREFER_VARIABLE_ALIGN( align_value, variable_type, variable_name ) MASTER_PREFER_ALIGNAS(align_value) variable_type variable_name
#elif defined(_MSC_VER)
#	define MASTER_PREFER_ALIGNAS( align_value ) __declspec(align(align_value))
#	define MASTER_PREFER_MEMBER_ALIGN( align_value, variable_type ) variable_type MASTER_PREFER_ALIGNAS(align_value)
#	define MASTER_PREFER_VARIABLE_ALIGN( align_value, variable_type, variable_name ) variable_type MASTER_PREFER_ALIGNAS(align_value) variable_name
#else
#	define MASTER_PREFER_ALIGNAS( align_value )
#	define MASTER_PREFER_MEMBER_ALIGN( align_value, variable_type ) variable_type
#	define MASTER_PREFER_VARIABLE_ALIGN( align_value, variable_type, variable_name ) variable_type variable_name
#endif
#if defined(__GNUC__) || defined(__clang__)
#	define MASTER_COMPILER_PREFER_GUARD( variable ) __asm__ ("":"+r"(variable))
#else
#	define MASTER_COMPILER_PREFER_GUARD( variable )
#endif
#if defined(__clang__) && defined(__ARM_ARCH) && !defined(__wasm__)
#	define MASTER_COMPILER_PREFER_GUARD_NEON( variable ) __asm__ ("":"+w"(variable))
#else
#	define MASTER_COMPILER_PREFER_GUARD_NEON( variable )
#endif
*/

#ifdef __cplusplus
#	define MASTER_C_STANDARD 0
#	if __cplusplus + 0 >= 202302L
#		define MASTER_CPP_STANDARD 2023
#		define MASTER_COMPILER_LANGUAGE "C++23"
#	elif __cplusplus + 0 >= 202002L
#		define MASTER_CPP_STANDARD 2020
#		define MASTER_COMPILER_LANGUAGE "C++20"
#	elif __cplusplus + 0 >= 201703L
#		define MASTER_CPP_STANDARD 2017
#		define MASTER_COMPILER_LANGUAGE "C++17"
#	elif __cplusplus + 0 >= 201402L
#		define MASTER_CPP_STANDARD 2014
#		define MASTER_COMPILER_LANGUAGE "C++14"
#	elif __cplusplus + 0 >= 201103L
#		define MASTER_CPP_STANDARD 2011
#		define MASTER_COMPILER_LANGUAGE "C++11"
#	elif __cplusplus + 0 >= 199711L
#		define MASTER_CPP_STANDARD 1997
#		define MASTER_COMPILER_LANGUAGE "C++97"
#	else
#		define MASTER_CPP_STANDARD 1997
#		define MASTER_COMPILER_LANGUAGE "C++97"
#	endif /* #! __cplusplus !# */
#elif defined(__STDC__)
#	define MASTER_CPP_STANDARD 0
#	if defined(__STDC_VERSION__)
#		if __STDC_VERSION__ + 0 >= 202311L
#			define MASTER_C_STANDARD 2023
#			define MASTER_COMPILER_LANGUAGE "C23"
#		elif __STDC_VERSION__ + 0 >= 201710L
#			define MASTER_C_STANDARD 2017
#			define MASTER_COMPILER_LANGUAGE "C17"
#		elif __STDC_VERSION__ + 0 >= 201112L
#			define MASTER_C_STANDARD 2011
#			define MASTER_COMPILER_LANGUAGE "C11"
#		elif __STDC_VERSION__ + 0 >= 199901L
#			define MASTER_C_STANDARD 1999
#			define MASTER_COMPILER_LANGUAGE "C99"
#		elif __STDC_VERSION__ + 0 >= 199409L
#			define MASTER_C_STANDARD 1994
#			define MASTER_COMPILER_LANGUAGE "C94"
#		else
#			define MASTER_C_STANDARD 1989
#			define MASTER_COMPILER_LANGUAGE "C90"
#		endif /* #! __STDC_VERSION__ !# */
#	else
#		define MASTER_C_STANDARD 1989
#		define MASTER_COMPILER_LANGUAGE "C89"
#	endif /* #! __STDC_VERSION__ !# */
#else
#	define MASTER_C_STANDARD 1978
#	define MASTER_COMPILER_LANGUAGE "K&R C (C78)"
#endif /* #! __STDC__ !# */

#define MASTER_PREFER_C89_SUPPORTED (MASTER_C_STANDARD >= 1989)
#define MASTER_PREFER_C94_SUPPORTED (MASTER_C_STANDARD >= 1994)
#define MASTER_PREFER_C99_SUPPORTED (MASTER_C_STANDARD >= 1999)
#define MASTER_PREFER_C11_SUPPORTED (MASTER_C_STANDARD >= 2011)
#define MASTER_PREFER_C17_SUPPORTED (MASTER_C_STANDARD >= 2017)
#define MASTER_PREFER_C23_SUPPORTED (MASTER_C_STANDARD >= 2023)

#define MASTER_PREFER_CPP98_SUPPORTED (MASTER_CPP_STANDARD >= 1997)
#define MASTER_PREFER_CPP11_SUPPORTED (MASTER_CPP_STANDARD >= 2011)
#define MASTER_PREFER_CPP14_SUPPORTED (MASTER_CPP_STANDARD >= 2014)
#define MASTER_PREFER_CPP17_SUPPORTED (MASTER_CPP_STANDARD >= 2017)
#define MASTER_PREFER_CPP20_SUPPORTED (MASTER_CPP_STANDARD >= 2020)
#define MASTER_PREFER_CPP23_SUPPORTED (MASTER_CPP_STANDARD >= 2023)

/* #! MASTER Generalization Of Macroses !# */

#ifdef MASTER_NO_DEPENDENCIES
#	define MASTER_NO_LIBC_DEPENDENCIES
#	define MASTER_NO_MASTER_DEPENDENCIES
#endif /* #! MASTER_NO_DEPENDENCIES !# */

#ifdef MASTER_NO_LIBC_DEPENDENCIES
#	define MASTER_NO_STRING_DEPENDENCY
#	define MASTER_NO_LIMITS_DEPENDENCY
#endif /* #! MASTER_NO_LIBC_DEPENDENCIES !# */

#ifdef MASTER_NO_MASTER_DEPENDENCIES
#	define MASTER_NO_ARCHITECTURE_DETECT_DEPENDENCY
#	define MASTER_NO_COMPILER_SETTINGS_DEPENDENCY
#endif /* #! MASTER_NO_MASTER_DEPENDENCIES !# */

/* #! MASTER Types !# */

#if (!defined(__STDC_VERSION__) && !defined(MASTER_IGNORE_C89_STD_64_VARIABLES)) || defined(MASTER_TRADITONAL)
#	define MASTER_zRIVATE_PREFER_LONGLONG long
#	define MASTER_zRIVATE_PREFER_64 0
#else
#	define MASTER_zRIVATE_PREFER_LONGLONG long long
#	define MASTER_zRIVATE_PREFER_64 1
#endif /* #! C89 Long Long Check !# */

#ifndef MASTER_64_AVAILABLE
#	ifdef __cplusplus
#		if __cplusplus + 0 >= 201103L
			typedef unsigned long long MASTER_maxint;
#			define MASTER_64_AVAILABLE 1
#		else
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		endif /* #! C++98 Check !# */
#	elif !defined(MASTER_NO_LIMITS_DEPENDENCY) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#		include <limits.h>
#		if defined(ULLONG_MAX)
			typedef unsigned MASTER_zRIVATE_PREFER_LONGLONG MASTER_maxint;
#			define MASTER_64_AVAILABLE MASTER_zRIVATE_PREFER_64
#		elif defined(ULONG_MAX) && (ULONG_MAX + 0 >= 0xFFFFFFFFFFFFFFFFULL)
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE MASTER_zRIVATE_PREFER_64
#		else
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		endif /* #! C version !# */
#	elif !defined(MASTER_NO_ARCHITECTURE_DETECT_DEPENDENCY) && !defined(MASTER_IGNORE_ARCHITECTURE)
#		include <architecture_detect.h>
#		if MASTER_ARCHITECTURE_CPU_WIDTH >= 64
#			if !defined(__STDC_VERSION__)
				typedef unsigned MASTER_zRIVATE_PREFER_LONGLONG MASTER_maxint;
#			else
				typedef unsigned MASTER_zRIVATE_PREFER_LONGLONG MASTER_maxint;
#			endif /* #! C89 !# */
#			define MASTER_64_AVAILABLE MASTER_zRIVATE_PREFER_64
#		elif MASTER_ARCHITECTURE_CPU_WIDTH >= 32
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		else
			typedef unsigned short MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		endif /* #! MASTER_ARCHITECTURE_CPU_WIDTH !# */
#	else
#		if !defined(MASTER_IGNORE_C89_STD_64_VARIABLES)
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		else
#			ifdef MASTER_NO_LIMITS_DEPENDENCY
				typedef unsigned short MASTER_maxint;
#				define MASTER_64_AVAILABLE 0
#			else
#				include <limits.h>
#				if defined(ULONG_MAX) && (ULONG_MAX + 0 >= 0xFFFFFFFFFFFFFFFFULL)
					typedef unsigned MASTER_zRIVATE_PREFER_LONGLONG MASTER_maxint;
#					define MASTER_64_AVAILABLE MASTER_zRIVATE_PREFER_64
#				elif defined(ULONG_MAX) && (ULONG_MAX >= 0xFFFFFFFFUL)
					typedef unsigned long MASTER_maxint;
#					define MASTER_64_AVAILABLE 0
#				else
					typedef unsigned short MASTER_maxint;
#					define MASTER_64_AVAILABLE 0
#				endif /* #! Long variables check !# */
#			endif /* #! MASTER_NO_LIMITS_DEPENDENCY !# */
#		endif /* #! MASTER_IGNORE_C89_STD_64_VARIABLES !# */
#	endif /* #! C / C++ check !# */
#endif /* #! MASTER_64_AVAILABLE !# */

#if MASTER_64_AVAILABLE == 1
#	define MASTER_UI8_TYPE unsigned long long int
#	define MASTER_SI8_TYPE signed long long int
	typedef MASTER_SI8_TYPE MASTER_signed_maxint;
	typedef MASTER_UI8_TYPE MASTER_unsigned_maxint;
#	define MASTER_SIGNED_MAXINT_MIN MASTER_SI8_MIN
#	define MASTER_SIGNED_MAXINT_MAX MASTER_SI8_MAX
#	define MASTER_UNSIGNED_MAXINT_MIN MASTER_UI8_MIN
#	define MASTER_UNSIGNED_MAXINT_MAX MASTER_UI8_MAX
#else
	typedef SI4 MASTER_signed_maxint;
	typedef UI4 MASTER_unsigned_maxint;
#	define MASTER_SIGNED_MAXINT_MIN MASTER_SI4_MIN
#	define MASTER_SIGNED_MAXINT_MAX MASTER_SI4_MAX
#	define MASTER_UNSIGNED_MAXINT_MIN MASTER_UI4_MIN
#	define MASTER_UNSIGNED_MAXINT_MAX MASTER_UI4_MAX
#endif /* #! MASTER_64_AVAILABLE !# */

#ifdef MASTER_UI8_TYPE
	typedef MASTER_UI8_TYPE UI8;
#else
#	define MASTER_UI8_ARRAY_TYPE 1
	typedef UI4 UI8[2];
#endif /* #! UI8 Type !# */

#ifdef MASTER_UI16_TYPE
	typedef MASTER_UI16_TYPE UI16;
#else
#	define MASTER_UI16_ARRAY_TYPE 1
	typedef UI4 UI16[4];
#endif /* #! UI16 Type !# */

#ifdef MASTER_UI32_TYPE
	typedef MASTER_UI32_TYPE UI32;
#else
#	define MASTER_UI32_ARRAY_TYPE 1
	typedef UI4 UI32[8];
#endif /* #! UI32 Type !# */

#ifdef MASTER_UI64_TYPE
	typedef MASTER_UI64_TYPE UI64;
#else
#	define MASTER_UI64_ARRAY_TYPE 1
	typedef UI4 UI64[16];
#endif /* #! UI64 Type !# */

#ifdef MASTER_UI128_TYPE
	typedef MASTER_UI128_TYPE UI128;
#else
#	define MASTER_UI128_ARRAY_TYPE 1
	typedef UI4 UI128[32];
#endif /* #! UI128 Type !# */

#ifdef MASTER_SI8_TYPE
	typedef MASTER_SI8_TYPE SI8;
#endif /* #! SI8 Type !# */

#ifdef MASTER_SI16_TYPE
	typedef MASTER_SI16_TYPE SI16;
#endif /* #! SI16 Type !# */

#ifdef MASTER_SI32_TYPE
	typedef MASTER_SI32_TYPE SI32;
#endif /* #! SI32 Type !# */

#ifdef MASTER_SI64_TYPE
	typedef MASTER_SI64_TYPE SI64;
#endif /* #! SI64 Type !# */

#ifdef MASTER_SI128_TYPE
	typedef MASTER_SI128_TYPE SI128;
#endif /* #! SI128 Type !# */

#ifdef MASTER_YEAR_IN_BYTE
#	define MASTER_TO_YEARS( year_value ) (UI1)((year_value) - 2038)
#	define MASTER_GET_YEARS( year_value ) (2038 + (year_value))
	typedef SI1 MASTER_year;
#else
#	define MASTER_TO_YEARS( year_value ) (year_value)
#	define MASTER_GET_YEARS( year_value ) (year_value)
	typedef UI2 MASTER_year;
#endif /* #! MASTER_YEAR_IN_BYTE !# */

/* #! MASTER Integers Values !# */

#define MASTER_L_POSTFIX_C( value ) value##L
#define MASTER_LL_POSTFIX_C( value ) value##LL
#define MASTER_UL_POSTFIX_C( value ) value##UL
#define MASTER_ULL_POSTFIX_C( value ) value##ULL

#define MASTER_SI4_POSTFIX_C( value ) value##L
#define MASTER_UI4_POSTFIX_C( value ) value##UL

#define MASTER_SI8_POSTFIX_C( value ) value##LL
#define MASTER_UI8_POSTFIX_C( value ) value##ULL

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ + 0 < 199001L
#	define MASTER_CONSTANT( constant ) MASTER_UI4_POSTFIX_C( constant )
#else
#	define MASTER_CONSTANT( constant ) MASTER_UI8_POSTFIX_C( constant )
#endif /* #! C89 Variables !# */

#define MASTER_UI1_BITS (sizeof(UI1) << 3)
#define MASTER_UI2_BITS (sizeof(UI2) << 3)
#define MASTER_UI4_BITS (sizeof(UI4) << 3)
#define MASTER_UI8_BITS (sizeof(UI8) << 3)
#define MASTER_UI16_BITS (sizeof(UI16) << 3)
#define MASTER_UI32_BITS (sizeof(UI32) << 3)
#define MASTER_UI64_BITS (sizeof(UI64) << 3)
#define MASTER_UI128_BITS (sizeof(UI128) << 3)

#define MASTER_SI1_BITS (sizeof(SI1) << 3)
#define MASTER_SI2_BITS (sizeof(SI2) << 3)
#define MASTER_SI4_BITS (sizeof(SI4) << 3)
#define MASTER_SI8_BITS (sizeof(SI8) << 3)
#define MASTER_SI16_BITS (sizeof(SI16) << 3)
#define MASTER_SI32_BITS (sizeof(SI32) << 3)
#define MASTER_SI64_BITS (sizeof(SI64) << 3)
#define MASTER_SI128_BITS (sizeof(SI128) << 3)

#define MASTER_SI1_MIN (SI1)((SI1)1 << (MASTER_SI1_BITS - 1))
#define MASTER_SI1_MAX (SI1)((UI1)MASTER_SI1_MIN - (UI1)1)
#define MASTER_SI2_MIN (SI2)((SI2)1 << (MASTER_SI2_BITS - 1))
#define MASTER_SI2_MAX (SI2)((UI2)MASTER_SI2_MIN - (UI2)1)
#define MASTER_SI4_MIN (SI4)((SI4)1 << (MASTER_SI4_BITS - (SI4)1))
#define MASTER_SI4_MAX (SI4)((UI4)MASTER_SI4_MIN - (UI4)1)
#ifdef MASTER_SI8_TYPE
#	define MASTER_SI8_MIN (SI8)((SI8)1 << (MASTER_SI8_BITS - 1))
#	define MASTER_SI8_MAX (SI8)((UI8)MASTER_SI4_MIN - MASTER_SI8_POSTFIX_C(1))
#endif /* #! SI8 !# */

#define MASTER_UI1_MIN (UI1)0
#define MASTER_UI1_MAX (UI1)(MASTER_UI1_MIN - 1)
#define MASTER_UI2_MIN (UI2)0
#define MASTER_UI2_MAX (UI2)(MASTER_UI2_MIN - 1)
#define MASTER_UI4_MIN (UI4)MASTER_CONSTANT(0)
#define MASTER_UI4_MAX (UI4)(MASTER_UI4_MIN - MASTER_UI4_POSTFIX_C(1))
#ifdef MASTER_UI8_TYPE
#	define MASTER_UI8_MIN (UI8)MASTER_CONSTANT(0)
#	define MASTER_UI8_MAX (UI8)(MASTER_UI8_MIN - MASTER_UI8_POSTFIX_C(1))
#endif /* #! UI8 !# */

#define MASTER_OUI_BITS (sizeof(OUI) << 3)
#define MASTER_OSI_BITS (sizeof(OSI) << 3)
#define MASTER_UT_BITS (sizeof(UT) << 3)

#define MASTER_MAXINT_BITS (sizeof(MASTER_maxint) << 3)

/* #! MASTER Errors !# */

#ifndef MASTER_MINIMALIZE_ERROR_CODES
#	define MASTER_ERROR_COMMENT( error_code, base_value ) error_code
#else
#	define MASTER_ERROR_COMMENT( error_code, base_value ) error_code = base_value
#endif /* #! MASTER_MINIMALIZE_RETURN_CODES !# */

typedef enum {
	MASTER_NO_ERROR = 0,
	MASTER_ERROR = 1
} MASTER_error;

const char * const MASTER_error_codes[] = {
	"No error",
	"Error",
#ifndef MASTER_MINIMALIZE_ERROR_CODES
#endif /* #! MASTER_MINIMALIZE_RETURN_CODES !# */
};

#ifndef MASTER_DONT_USE_OPTIONAL_ERROR_CODES
	typedef MASTER_error MASTER_optional_error;
#	define MASTER_OPTIONAL_ERROR_CODE( error_code ) (error_code)
#else
	typedef void MASTER_optional_error;
#	define MASTER_OPTIONAL_ERROR_CODE( error_code )
#endif /* #! MASTER_DONT_USE_OPTIONAL_RET_CODE !# */

#define MASTER_IS_SUCCESS(code) ((code) == MASTER_NO_ERROR)
#define MASTER_IS_FAILURE(code) ((code) != MASTER_NO_ERROR)

/* #! MASTER Assertion !# */

#ifdef MASTER_ENABLE_ASSERTIONS
#	ifndef MASTER_ASSERT
#		error "With defined "MASTER_ENABLE_ASSERTIONS" function "MASTER_ASSERT" with arguments (expr) must be defined."
#	endif /* #! MASTER_FUNCTION_ASSERTION !# */
#else
#	define MASTER_ASSERT( expression )
#endif /* #! MASTER_ENABLE_ASSERTIONS !# */

/* #! MASTER Memory Functions !# */

#if !defined(MASTER_CUSTOM_MEMORY_FUNCTIONS) && ( \
	defined(MASTER_MALLOC) || defined(MASTER_REALLOC) || defined(MASTER_CALLOC) || defined(MASTER_FREE))
#	warning "Some user memory functions are defined, but macro 'MASTER_CUSTOM_MEMORY_FUNCTIONS' is undefined. Defining 'MASTER_CUSTOM_MEMORY_FUNCTIONS'"
#	define MASTER_CUSTOM_MEMORY_FUNCTIONS
#endif /* #! Predefined Memory Functions Check !# */

#if defined(MASTER_CUSTOM_MEMORY_FUNCTIONS)
#ifndef MASTER_MALLOC
#		error "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_MALLOC" must be defined."
#	endif /* #! MASTER_MALLOC !# */
#	ifndef MASTER_REALLOC
#		error "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_REALLOC" must be defined."
#	endif /* #! MASTER_REALLOC !# */
#	ifndef MASTER_CALLOC
#		error "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_CALLOC" must be defined."
#	endif /* #! MASTER_CALLOC !# */
#	ifndef MASTER_FREE
#		error "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_FREE" must be defined."
#	endif /* #! MASTER_FREE !# */
#elif defined(MASTER_NO_STDLIB_DEPENDENCY)
#	ifndef MASTER_MALLOC
#		error "With no stdlib dependency function "MASTER_MALLOC" must be defined."
#	endif /* #! MASTER_MALLOC !# */
#	ifndef MASTER_REALLOC
#		error "With no stdlib dependency function "MASTER_REALLOC" must be defined."
#	endif /* #! MASTER_REALLOC !# */
#	ifndef MASTER_CALLOC
#		error "With no stdlib dependency function "MASTER_CALLOC" must be defined."
#	endif /* #! MASTER_CALLOC !# */
#	ifndef MASTER_FREE
#		error "With no stdlib dependency function "MASTER_FREE" must be defined."
#	endif /* #! MASTER_FREE !# */
#elif defined(MASTER_MEMORY_SAFE)
#	include <stdlib.h>
#	ifndef MASTER_FUNCTION_ON_FAILURE_MALLOC
#		error "With defined "MASTER_MEMORY_SAFE" function "MASTER_FUNCTION_ON_FAILURE_MALLOC" must be defined."
#	endif /* #! MASTER_FUNCTION_ON_FAILURE_MALLOC !# */
#	ifndef MASTER_FUNCTION_ON_FAILURE_CALLOC
#		error "With defined "MASTER_MEMORY_SAFE" function "MASTER_FUNCTION_ON_FAILURE_CALLOC" must be defined."
#	endif /* #! MASTER_FUNCTION_ON_FAILURE_CALLOC !# */
#	ifndef MASTER_FUNCTION_ON_FAILURE_REALLOC
#		error "With defined "MASTER_MEMORY_SAFE" function "MASTER_FUNCTION_ON_FAILURE_REALLOC" must be defined."
#	endif /* #! MASTER_FUNCTION_ON_FAILURE_REALLOC !# */
#	ifndef MASTER_FUNCTION_ON_NULL_IN_FREE
#		error "With defined "MASTER_MEMORY_SAFE" function "MASTER_FUNCTION_ON_NULL_IN_FREE" must be defined."
#	endif /* #! MASTER_FUNCTION_ON_NULL_IN_FREE !# */
#	define MASTER_MALLOC( __size ) ({ \
		void * __ptr = (void *)malloc(__size); \
		if (__ptr == 0 && __size > 0) MASTER_FUNCTION_ON_FAILURE_MALLOC; \
		__ptr; })
#	define MASTER_CALLOC( __count, __size ) ({ \
		void * __ptr = (void *)calloc(__count, __size); \
		if (__ptr == 0 && __size > 0) MASTER_FUNCTION_ON_FAILURE_CALLOC; \
		__ptr; })
#	define MASTER_REALLOC( __ptr, __size ) ({ \
		void * __new_ptr = (void *)realloc(__ptr, __size); \
		if (__ptr == 0 && __size > 0) MASTER_FUNCTION_ON_FAILURE_REALLOC; \
		__new_ptr; })
#	define MASTER_FREE( __ptr ) do { \
		if (__ptr == 0) MASTER_FUNCTION_ON_NULL_IN_FREE; \
		free(__ptr, __size); } while (0)
#else
#	include <stdlib.h>
#	define MASTER_MALLOC( __size ) malloc(__size)
#	define MASTER_CALLOC( __count, __size ) calloc(__count, __size)
#	define MASTER_REALLOC( __ptr, __size ) realloc(__ptr, __size)
#	define MASTER_FREE( __ptr ) free(__ptr)
#endif /* #! MASTER_MEMORY_SAFE !# */

/* #! MASTER Code Manipulations !# */

#define MASTER_REPEAT2( code ) code code
#define MASTER_REPEAT3( code ) code code code
#define MASTER_REPEAT4( code ) code code code code
#define MASTER_REPEAT5( code ) code code code code code
#define MASTER_CODE_REPEAT2( code ) code; code
#define MASTER_CODE_REPEAT3( code ) code; code; code
#define MASTER_CODE_REPEAT4( code ) code; code; code; code
#define MASTER_CODE_REPEAT5( code ) code; code; code; code; code
#define MASTER_DO_CODE_REPEAT2( code ) do { MASTER_REPEAT2(code); } while (0)
#define MASTER_DO_CODE_REPEAT3( code ) do { MASTER_REPEAT3(code); } while (0)
#define MASTER_DO_CODE_REPEAT4( code ) do { MASTER_REPEAT4(code); } while (0)
#define MASTER_DO_CODE_REPEAT5( code ) do { MASTER_REPEAT5(code); } while (0)
#define MASTER_XMACRO_CREATE_ENUM( name, value, Unused3_ ) name = value,
#define MASTER_XMACRO_CASE_STRING( name, Unused2_, string ) case name : return string;
#define MASTER_XMACRO_CREATE_NAME_ARRAY( name, Unused2_, Unused3_ ) #name,
#define MASTER_XMACRO_CREATE_VALUE_DICTIONARY( name, value, Unused3_ ) #name " : " #value,
#define MASTER_XMACRO_CREATE_STRING_DICTIONARY( name, Unused2_, string ) #name " : " #string,
#define MASTER_ERRORRISE ;!@;
#define MASTER_NOTHING ;
#define MASTER_TO_BOOL( expression ) (!!(expression))
#define MASTER_STATIC_ASSERT( expression ) (void)(sizeof(char [1 - 2 * !(expression)]))
#define MASTER_UNARG_BEGIN0()
#define MASTER_UNARG_BEGIN1( argument1 ) argument1,
#define MASTER_UNARG_BEGIN2( argument1, argument2 ) argument1, argument2,
#define MASTER_UNARG_BEGIN3( argument1, argument2, argument3 ) argument1, argument2, argument3,
#define MASTER_UNARG_BEGIN4( argument1, argument2, argument3, argument4 ) argument1, argument2, argument3, argument4,
#define MASTER_UNARG_BEGIN5( argument1, argument2, argument3, argument4, argument5 ) argument1, argument2, argument3, argument4, argument5,
#define MASTER_UNARG_BEGIN6( argument1, argument2, argument3, argument4, argument5, argument6 ) argument1, argument2, argument3, argument4, argument5, argument6,
#define MASTER_UNARG_BEGIN7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) argument1, argument2, argument3, argument4, argument5, argument6, argument7,
#define MASTER_UNARG_BEGIN8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8,
#define MASTER_UNARG_END0()
#define MASTER_UNARG_END1( argument1 ) , argument1
#define MASTER_UNARG_END2( argument1, argument2 ) , argument1, argument2
#define MASTER_UNARG_END3( argument1, argument2, argument3 ) , argument1, argument2, argument3
#define MASTER_UNARG_END4( argument1, argument2, argument3, argument4 ) , argument1, argument2, argument3, argument4
#define MASTER_UNARG_END5( argument1, argument2, argument3, argument4, argument5 ) , argument1, argument2, argument3, argument4, argument5
#define MASTER_UNARG_END6( argument1, argument2, argument3, argument4, argument5, argument6 ) , argument1, argument2, argument3, argument4, argument5, argument6
#define MASTER_UNARG_END7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) , argument1, argument2, argument3, argument4, argument5, argument6, argument7
#define MASTER_UNARG_END8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) , argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8

/* #! MASTER Checks !# */

#define MASTER_RETURN_IF_NUL( pointer, retval ) do { \
		if ((pointer) == 0) return retval; \
	} while (0)
#define MASTER_GOTO_IF_NUL( pointer, label ) do { \
		if ((pointer) == 0) goto label; \
	} while (0)
#define MASTER_ASSERT_IF_NUL( pointer ) do { \
		MASTER_ASSERT((pointer) != 0); \
	} while (0)

#if !defined(MASTER_DONT_CHECK_NUL_OPERANDS) && !defined(MASTER_ASSERT_IF_NUL_OPERAND)
#	define MASTER_zRIVATE_CHECK_NUL_RETURN( pointer, retval ) MASTER_RETURN_IF_NUL(pointer, retval)
#	define MASTER_zRIVATE_CHECK_NUL_GOTO( pointer, retval ) MASTER_GOTO_IF_NUL(pointer, retval)
#	define MASTER_zRIVATE_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
#elif !defined(MASTER_DONT_CHECK_NUL_OPERANDS) && defined(MASTER_ASSERT_IF_NUL_OPERAND)
#	define MASTER_zRIVATE_CHECK_NUL_RETURN( pointer, retval ) MASTER_ASSERT_IF_NUL(pointer)
#	define MASTER_zRIVATE_CHECK_NUL_GOTO( pointer, retval ) MASTER_ASSERT_IF_NUL(pointer)
#	define MASTER_zRIVATE_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
#else
#	define MASTER_zRIVATE_CHECK_NUL_RETURN( pointer, retval )
#	define MASTER_zRIVATE_CHECK_NUL_GOTO( pointer, retval )
#	ifdef MASTER_ENABLE_ASSERTIONS
#		define MASTER_zRIVATE_CHECK_NUL_ASSERT( pointer )
#	else
#		define MASTER_zRIVATE_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
#	endif /* #! MASTER_ENABLE_ASSERTIONS !# */
#endif /* #! MASTER_DONT_CHECK_NUL_OPERANDS !# */

/* #! MASTER Argument List Macroses !# */

#define MASTER_KAIR_ARG( arg_type, argument ) argument
#define MASTER_KAIR_DECL( arg_type, argument ) arg_type argument
#define MASTER_KAIR_EXTERN_ARGS_LIST( arguments ) ()
#define MASTER_KAIR_FORMAT0() ( void )
#define MASTER_KAIR_FORMAT1( argument ) ( MASTER_KAIR_ARG argument ) MASTER_KAIR_DECL argument;
#define MASTER_KAIR_FORMAT2( argument1, argument2 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2;
#define MASTER_KAIR_FORMAT3( argument1, argument2, argument3 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3;
#define MASTER_KAIR_FORMAT4( argument1, argument2, argument3, argument4 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4;
#define MASTER_KAIR_FORMAT5( argument1, argument2, argument3, argument4, argument5 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4, MASTER_KAIR_ARG argument5 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4; MASTER_KAIR_DECL argument5;
#define MASTER_KAIR_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4, MASTER_KAIR_ARG argument5, MASTER_KAIR_ARG argument6 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4; MASTER_KAIR_DECL argument5; MASTER_KAIR_DECL argument6;
#define MASTER_KAIR_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4, MASTER_KAIR_ARG argument5, MASTER_KAIR_ARG argument6, MASTER_KAIR_ARG argument7 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4; MASTER_KAIR_DECL argument5; MASTER_KAIR_DECL argument6; MASTER_KAIR_DECL argument7;
#define MASTER_KAIR_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4, MASTER_KAIR_ARG argument5, MASTER_KAIR_ARG argument6, MASTER_KAIR_ARG argument7, MASTER_KAIR_ARG argument8 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4; MASTER_KAIR_DECL argument5; MASTER_KAIR_DECL argument6; MASTER_KAIR_DECL argument7; MASTER_KAIR_DECL argument8;

#define MASTER_STD_DECL( arg_type, argument ) arg_type argument
#define MASTER_STD_EXTERN_ARGS_LIST( arguments ) arguments
#define MASTER_STD_FORMAT0() ( void )
#define MASTER_STD_FORMAT1( argument ) ( MASTER_STD_DECL argument )
#define MASTER_STD_FORMAT2( argument1, argument2 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2 )
#define MASTER_STD_FORMAT3( argument1, argument2, argument3 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3 )
#define MASTER_STD_FORMAT4( argument1, argument2, argument3, argument4 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4 )
#define MASTER_STD_FORMAT5( argument1, argument2, argument3, argument4, argument5 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4, MASTER_STD_DECL argument5 )
#define MASTER_STD_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4, MASTER_STD_DECL argument5, MASTER_STD_DECL argument6 )
#define MASTER_STD_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4, MASTER_STD_DECL argument5, MASTER_STD_DECL argument6, MASTER_STD_DECL argument7 )
#define MASTER_STD_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4, MASTER_STD_DECL argument5, MASTER_STD_DECL argument6, MASTER_STD_DECL argument7, MASTER_STD_DECL argument8 )

#if defined(__cplusplus) || (defined(__STDC__) && !defined(MASTER_TRADITIONAL_COMPILE))
	/* #! Modern compilers need prototypes !# */
#	ifdef MASTER_CHECK_IF_FUNCTION_IS_EXTERNED_BUT_NOT_IMPLEMENTED
#		define MASTER_EXTERN_FUNCTION( flags, return_value_and_extras, function_name, arguments ) MASTER_PREFER_EXTERN return_value_and_extras function_name MASTER_STD_EXTERN_ARGS_LIST(arguments); \
	return_value_and_extras (*MASTER_CONCAT_FALL(function_name, _Pointer))MASTER_STD_EXTERN_ARGS_LIST(arguments) = function_name
#	else
#		define MASTER_EXTERN_FUNCTION( flags, return_value_and_extras, function_name, arguments ) MASTER_PREFER_EXTERN return_value_and_extras function_name MASTER_STD_EXTERN_ARGS_LIST(arguments)
#	endif /* #! Extension : Function is externed but not implemented !# */
#	define MASTER_ARGLIST_FORMAT0() MASTER_STD_FORMAT0()
#	define MASTER_ARGLIST_FORMAT1( argument ) MASTER_STD_FORMAT1(argument)
#	define MASTER_ARGLIST_FORMAT2( argument1, argument2 ) MASTER_STD_FORMAT2( argument1, argument2 )
#	define MASTER_ARGLIST_FORMAT3( argument1, argument2, argument3 ) MASTER_STD_FORMAT3( argument1, argument2, argument3 )
#	define MASTER_ARGLIST_FORMAT4( argument1, argument2, argument3, argument4 ) MASTER_STD_FORMAT4( argument1, argument2, argument3, argument4 )
#	define MASTER_ARGLIST_FORMAT5( argument1, argument2, argument3, argument4, argument5 ) MASTER_STD_FORMAT5( argument1, argument2, argument3, argument4, argument5 )
#	define MASTER_ARGLIST_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 ) MASTER_STD_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 )
#	define MASTER_ARGLIST_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) MASTER_STD_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 )
#	define MASTER_ARGLIST_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) MASTER_STD_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 )
#else
	/* #! Traditional compilers need only declarations !# */
#	ifdef MASTER_CHECK_IF_FUNCTION_IS_EXTERNED_BUT_NOT_IMPLEMENTED
#		define MASTER_EXTERN_FUNCTION( flags, return_value_and_extras, function_name, arguments ) MASTER_PREFER_EXTERN return_value_and_extras function_name MASTER_KAIR_EXTERN_ARGS_LIST(arguments); \
	return_value_and_extras (*MASTER_CONCAT_FALL(function_name, _Pointer))MASTER_KAIR_EXTERN_ARGS_LIST(arguments) = function_name
#	else
#		define MASTER_EXTERN_FUNCTION( flags, return_value_and_extras, function_name, arguments ) MASTER_PREFER_EXTERN return_value_and_extras function_name MASTER_KAIR_EXTERN_ARGS_LIST(arguments)
#	endif /* #! Extension : Function is externed but not implemented !# */
#	define MASTER_ARGLIST_FORMAT0() MASTER_KAIR_FORMAT0()
#	define MASTER_ARGLIST_FORMAT1( argument ) MASTER_KAIR_FORMAT1(argument)
#	define MASTER_ARGLIST_FORMAT2( argument1, argument2 ) MASTER_KAIR_FORMAT2( argument1, argument2 )
#	define MASTER_ARGLIST_FORMAT3( argument1, argument2, argument3 ) MASTER_KAIR_FORMAT3( argument1, argument2, argument3 )
#	define MASTER_ARGLIST_FORMAT4( argument1, argument2, argument3, argument4 ) MASTER_KAIR_FORMAT4( argument1, argument2, argument3, argument4 )
#	define MASTER_ARGLIST_FORMAT5( argument1, argument2, argument3, argument4, argument5 ) MASTER_KAIR_FORMAT5( argument1, argument2, argument3, argument4, argument5 )
#	define MASTER_ARGLIST_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 ) MASTER_KAIR_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 )
#	define MASTER_ARGLIST_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) MASTER_KAIR_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 )
#	define MASTER_ARGLIST_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) MASTER_KAIR_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 )
#endif /* #! Detect Argument List Compability for C & C++ !# */

#define MASTER_DEFINE_FUNCTION0( flags, description, function_name, return_value_and_extras ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT0()
#define MASTER_DEFINE_FUNCTION1( flags, description, function_name, return_value_and_extras, argument ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT1(argument)
#define MASTER_DEFINE_FUNCTION2( flags, description, function_name, return_value_and_extras, argument1, argument2 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT2(argument1, argument2)
#define MASTER_DEFINE_FUNCTION3( flags, description, function_name, return_value_and_extras, argument1, argument2, argument3 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT3(argument1, argument2, argument3)
#define MASTER_DEFINE_FUNCTION4( flags, description, function_name, return_value_and_extras, argument1, argument2, argument3, argument4 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT4(argument1, argument2, argument3, argument4)
#define MASTER_DEFINE_FUNCTION5( flags, description, function_name, return_value_and_extras, argument1, argument2, argument3, argument4, argument5 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT5(argument1, argument2, argument3, argument4, argument5)
#define MASTER_DEFINE_FUNCTION6( flags, description, function_name, return_value_and_extras, argument1, argument2, argument3, argument4, argument5, argument6 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT6(argument1, argument2, argument3, argument4, argument5, argument6)
#define MASTER_DEFINE_FUNCTION7( flags, description, function_name, return_value_and_extras, argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT7(argument1, argument2, argument3, argument4, argument5, argument6, argument7)
#define MASTER_DEFINE_FUNCTION8( flags, description, function_name, return_value_and_extras, argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT8(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8)

#define MASTER_EMPTY_DESCRIPTION /* #! No description is provided !# */
#define MASTER_NO_FLAGS

/* #! MASTER Undefined Behaviour Runtime Checker && MASTER Some Operators !# */

#ifdef MASTER_RUNTIME_UB_CHECKS
#	define MASTER_MACRO_OPERATORS_UB_CALLBACK_DEFINE( bytes, bits_max ) \
		MASTER_PREFER_INLINE UI ## bytes \
		MASTER_RSH ## bytes ## _Callback( const UI ## bytes value, const UI1 bits, const char * const filename, const UI4 line ) { \
			if (bits >= ((bytes) << 3)) { \
				printf("Warning [file %s, line %u] : Rshift UB got (bits>=" #bits_max ", bits=%d)", filename, line, bits); \
				return 0; \
			} \
			return value >> bits; \
		} \
		\
		MASTER_PREFER_INLINE UI ## bytes \
		MASTER_LSH ## bytes ## _Callback( const UI ## bytes value, const UI1 bits, const char * const filename, const UI4 line ) { \
			if (bits >= ((bytes) << 3)) { \
				printf("Warning [file %s, line %u] : Lshift UB got (bits>=" #bits_max ", bits=%d)", filename, line, bits); \
				return 0; \
			} \
			return value << bits; \
		}
	MASTER_MACRO_OPERATORS_UB_CALLBACK_DEFINE( 1, 8 )
	MASTER_MACRO_OPERATORS_UB_CALLBACK_DEFINE( 2, 16 )
	MASTER_MACRO_OPERATORS_UB_CALLBACK_DEFINE( 4, 32 )
#	define MASTER_RSH1( value, bit_count ) MASTER_RSH1_Callback(value, bit_count, MASTER_FILE, MASTER_LINE)
#	define MASTER_RSH2( value, bit_count ) MASTER_RSH2_Callback(value, bit_count, MASTER_FILE, MASTER_LINE)
#	define MASTER_RSH4( value, bit_count ) MASTER_RSH4_Callback(value, bit_count, MASTER_FILE, MASTER_LINE)
#	define MASTER_LSH1( value, bit_count ) MASTER_LSH1_Callback(value, bit_count, MASTER_FILE, MASTER_LINE)
#	define MASTER_LSH2( value, bit_count ) MASTER_LSH2_Callback(value, bit_count, MASTER_FILE, MASTER_LINE)
#	define MASTER_LSH4( value, bit_count ) MASTER_LSH4_Callback(value, bit_count, MASTER_FILE, MASTER_LINE)
#else
#	define MASTER_RSH1( value, bit_count ) (UI1)(((UI1)(value)) >> (bit_count))
#	define MASTER_RSH2( value, bit_count ) (UI2)(((UI2)(value)) >> (bit_count))
#	define MASTER_RSH4( value, bit_count ) (UI4)(((UI4)(value)) >> (bit_count))
#	define MASTER_LSH1( value, bit_count ) (UI1)(((UI1)(value)) << (bit_count))
#	define MASTER_LSH2( value, bit_count ) (UI2)(((UI2)(value)) << (bit_count))
#	define MASTER_LSH4( value, bit_count ) (UI4)(((UI4)(value)) << (bit_count))
#endif /* #! MASTER_RUNTIME_UB_CHECKS !# */

/* #! MASTER Align !# */

#define MASTER_ALIGNPOW2( value, bit_count ) ((((value) >> (bit_count)) + !!((value) & ((1 << (bit_count)) - 1))) << (bit_count))
#define MASTER_ALIGN2( value ) MASTER_ALIGNPOW2( value, 1 )
#define MASTER_ALIGN4( value ) MASTER_ALIGNPOW2( value, 2 )
#define MASTER_ALIGN8( value ) MASTER_ALIGNPOW2( value, 3 )
#define MASTER_ALIGN16( value ) MASTER_ALIGNPOW2( value, 4 )
#define MASTER_ALIGN( value, bit_count ) ((((value) / (bit_count)) + !!((value) % (bit_count))) * (bit_count))

/* #! MASTER String !# */

/* #! TODO : Use !# */
#ifndef MASTER_USE_LONG_STRING
	typedef char MASTER_char;
#	define MASTER_CHAR( character ) character
#	define MASTER_STRING( string ) string
#else
	typedef UI4 MASTER_char;
#	define MASTER_CHAR( character ) L##character
#	define MASTER_STRING( string ) L##string
#endif /* #! Short / Long Strings !# */

#define MASTER_STRINGIFY( string ) #string
#define MASTER_STRINGIFY_FALL( string ) MASTER_STRINGIFY(string)
#define MASTER_CONCAT( string1, string2 ) string1##string2
#define MASTER_CONCAT3( string1, string2, string3 ) string1##string2##string3
#define MASTER_CONCAT4( string1, string2, string3, string4 ) string1##string2##string3##string4
#define MASTER_CONCAT_FALL( string1, string2 ) MASTER_CONCAT( string1, string2 )
#define MASTER_CONCAT3_FALL( string1, string2, string3 ) MASTER_CONCAT3( string1, string2, string3 )
#define MASTER_CONCAT4_FALL( string1, string2, string3, string4 ) MASTER_CONCAT4( string1, string2, string3, string4 )

/* #! MASTER Simple Macroses !# */

#define MASTER_MEMBER_SIZE( structure, member ) sizeof(((const structure * const)0)->member)
#define MASTER_MAX_BRANCHLESS( value1, value2 ) ((value2) ^ (((value1) ^ (value2)) & (-((value1) < (value2)))))
/* #! MASTER_SI<N>_MIN <= value1 - value2 <= MASTER_SI<N>_MAX !# */
#define MASTER_MAX_QUICK( value1, value2 ) ((value2) + (((value1) - (value2)) & (((value1) - (value2)) >> (sizeof(value1) * 8 - 1))))
#define MASTER_MAX( value1, value2 ) (((value1) > (value2)) ? (value1) : (value2))
#define MASTER_MAX3( value1, value2, value3 ) MASTER_MAX(value1, MASTER_MAX(value2, value3))
#define MASTER_MAX4( value1, value2, value3, value4 ) MASTER_MAX(MASTER_MAX(value1, value2), MASTER_MAX(value3, value4))
#define MASTER_IMAX( value1, value2 ) (value1) = MASTER_MAX(value1, value2)
#define MASTER_IMAX3( value1, value2, value3 ) (value1) = MASTER_MAX3(value1, value2, value3)
#define MASTER_IMAX4( value1, value2, value3, value4 ) (value1) = MASTER_MAX4(value1, value2, value3, value4)
#define MASTER_MIN_BRANCHLESS( value1, value2 ) ((value1) ^ (((value1) ^ (value2)) & (-((value1) < (value2)))))
/* #! MASTER_SI<N>_MIN <= value1 - value2 <= MASTER_SI<N>_MAX !# */
#define MASTER_MIN_QUICK( value1, value2 ) ((value1) - (((value1) - (value2)) & (((value1) - (value2)) >> (sizeof(value1) * 8 - 1))))
#define MASTER_MIN( value1, value2 ) (((value1) < (value2)) ? (value1) : (value2))
#define MASTER_MIN3( value1, value2, value3 ) MASTER_MIN(value1, MASTER_MIN(value2, value3))
#define MASTER_MIN4( value1, value2, value3, value4 ) MASTER_MIN(MASTER_MIN(value1, value2), MASTER_MIN(value3, value4))
#define MASTER_IMIN( value1, value2 ) (value1) = MASTER_MIN(value1, value2)
#define MASTER_IMIN3( value1, value2, value3 ) (value1) = MASTER_MIN3(value1, value2, value3)
#define MASTER_IMIN4( value1, value2, value3, value4 ) (value1) = MASTER_MIN4(value1, value2, value3, value4)
#define MASTER_CLAMP( value, min_value, max_value ) MASTER_MAX(min_value, MASTER_MIN(max_value, value))
#define MASTER_ICLAMP( value, min_value, max_value ) (value) = MASTER_CLAMP(value, min_value, max_value)
#define MASTER_ABS( value ) (((value) < 0) ? (-(value)) : (value))
#define MASTER_ABS_BRANCHLESS( value ) (((value) + ((value) >> (sizeof(value) * 8 - 1))) - ((value) >> (sizeof(value) * 8 - 1)))
#define MASTER_SIGN( value ) ((value > 0) - (value < 0))
#define MASTER_PARITYSIGN( value ) (1 | (-((value) & 1)))
#define MASTER_INVPARITYSIGN( value ) ((((value) & 1) << 1) - 1)
#define MASTER_OPPOSITE_SIGNS( value1, value2 ) (((value1) ^ (value2)) < 0)
#define MASTER_SQUARE( value ) ((value) * (value))
#define MASTER_2BYTES_TO_INT( value1, value2 ) (((value1) << 8) | (value2))
#define MASTER_4BYTES_TO_INT( value1, value2, value3, value4 ) (((value1) << 24) | ((value2) << 16) | ((value3) << 8) | (value4))
/* #! TODO : sign extending !# */
#define MASTER_STATE_BITS( value, bit_maask, to_set ) (value) ^= ((-(to_set)) ^ (value)) & (bit_mask)
#define MASTER_MERGE_BITS( value1, value2, bit_mask ) ((value1) ^ (((value1) ^ (value2)) & (bit_mask)))
#define MASTER_ISINRANGE_CC( value, low_value, high_value ) ((low_value) <= (value) && (value) <= (high_value))
#define MASTER_ISINRANGE_CO( value, low_value, high_value ) ((low_value) <= (value) && (value) < (high_value))
#define MASTER_ISINRANGE_OC( value, low_value, high_value ) ((low_value) < (value) && (value) <= (high_value))
#define MASTER_ISINRANGE_OO( value, low_value, high_value ) ((low_value) < (value) && (value) < (high_value))
#define MASTER_ISINRANGE( value, low_value, high_value ) MASTER_ISINRANGE_CC(value, low_value, high_value)
#define MASTER_WRAP( number, limit ) (((number) >= (limit)) ? (0) : (number))

#ifndef MASTER_UNSAFE_HOWMANY
#	define MASTER_DIV_CEIL2( value ) (((value) >> 1) + !!((value) & 1))
#	define MASTER_DIV_CEIL4( value ) (((value) >> 2) + !!((value) & 3))
#	define MASTER_DIV_CEIL8( value ) (((value) >> 3) + !!((value) & 7))
#	define MASTER_DIV_CEIL16( value ) (((value) >> 4) + !!((value) & 15))
#	define MASTER_DIV_CEIL_POW2( value, bit_count ) (((value) >> bit_count) + !!((value) & ((1 << (bit_count)) - 1)))
#	define MASTER_HOWMANY( value, subvalue ) (((value) / (subvalue)) + !!((value) % (subvalue)))
#else
	/* #! Value can be overflowed after plus and there will be information loses !# */
#	define MASTER_DIV_CEIL2( value ) (((value) + 1) >> 1)
#	define MASTER_DIV_CEIL4( value ) (((value) + 3) >> 2)
#	define MASTER_DIV_CEIL8( value ) (((value) + 7) >> 3)
#	define MASTER_DIV_CEIL16( value ) (((value) + 15) >> 4)
#	define MASTER_DIV_CEIL_POW2( value, bit_count ) (((value) + ((1 << (bit_count)) - 1)) >> (bit_count))
#	define MASTER_HOWMANY( value, subvalue ) (((value) + ((subvalue) - 1)) / (subvalue))
#endif /* #! Safe / Unsafe Howmany !# */

#define MASTER_HOWMANY2( value ) MASTER_DIV_CEIL2( value )
#define MASTER_HOWMANY4( value ) MASTER_DIV_CEIL4( value )
#define MASTER_HOWMANY8( value ) MASTER_DIV_CEIL8( value )
#define MASTER_HOWMANY16( value ) MASTER_DIV_CEIL16( value )
#define MASTER_HOWMANY_POW2( value, bit_count ) MASTER_DIV_CEIL_POW2( value, bit_count )
#define MASTER_BITS_TO_BYTES( value ) MASTER_DIV_CEIL8( value )

#define MASTER_PADDINGLEN( value, modulo, residue ) (((residue) - ((value) + 1) % (modulo) + (modulo)) % (modulo))
#define MASTER_PADDEDLEN( value, modulo, residue ) ((value) + 1 + MASTER_PADDINGLEN(value, modulo, residue))
#define MASTER_PADDINGLEN_POW2( value, log2modulo, residue ) ((((residue) - ((value) + 1)) & ((1 << (log2modulo)) - 1)))
#define MASTER_PADDEDLEN_POW2( value, log2modulo, residue ) ((value) + 1 + MASTER_PADDINGLEN_POW2(value, log2modulo, residue))

/* #! MASTER Some Functions !# */

#ifndef MASTER_NO_STRING_DEPENDENCY
#	include <string.h>
#	define MASTER_CPRCAT strcat
#	define MASTER_CPRCHR strchr
#	define MASTER_CPRCMP strcmp
#	define MASTER_CPRCOLL strcoll
#	define MASTER_CPRCPY strcpy
#	define MASTER_CPRCSPN strcspn
#	define MASTER_CPRERROR strerror
#	define MASTER_CPRLEN strlen
#	define MASTER_CPRNCAT strncat
#	define MASTER_CPRNCMP strncmp
#	define MASTER_CPRNCPY strncpy
#	define MASTER_CPRPBRK strpbrk
#	define MASTER_CPRRCHR strrchr
#	define MASTER_CPRSPN strspn
#	define MASTER_CPRCPR strstr
#	define MASTER_CPRTOK strtok
#	define MASTER_CPRXFRM strxfrm
#	define MASTER_MEMCHR memchr
#	define MASTER_MEMCMP memcmp
#	define MASTER_MEMCPY memcpy
#	define MASTER_MEMMOV memmove
#	define MASTER_MEMSET memset
#elif !defined(MASTER_STRING_DEFINED_FUNCTIONS_PARTIONLY)
#	error "Custom string.h functions are not supporting yet."
#endif /* #! MASTER_NO_STRING_DEPENDENCY !# */

/* #! MASTER Power Manipulations !# */

#define MASTER_ISPOW2( value ) ((value) > 0 && !((value) & ((value) - 1)))
#if MASTER_64_AVAILABLE == 1
#	define MASTER_ISPOW4( value ) (MASTER_ISPOW2(value) && ((value) & 0x5555555555555555ULL))
#	define MASTER_ISPOW8( value ) (MASTER_ISPOW2(value) && ((value) & 0x9249249249249249ULL))
#	define MASTER_ISPOW16( value ) (MASTER_ISPOW2(value) && ((value) & 0x1111111111111111ULL))
#else
#	define MASTER_ISPOW4( value ) (MASTER_ISPOW2(value) && ((value) & 0x55555555UL))
#	define MASTER_ISPOW8( value ) (MASTER_ISPOW2(value) && ((value) & 0x49249249UL))
#	define MASTER_ISPOW16( value ) (MASTER_ISPOW2(value) && ((value) & 0x11111111UL))
#endif /* #! 64 Bits !# */

/* #! MASTER Overflow Macroses !# */

#define MASTER_ADD_OVERFLOW_UI1( value1, value2, carry ) (carry) = (((value1) >= ((UI1)-1) - (value2)) ? (1) : (0))
#define MASTER_ADD_OVERFLOW_UI2( value1, value2, carry ) (carry) = (((value1) >= ((UI2)-1) - (value2)) ? (1) : (0))
#define MASTER_ADD_OVERFLOW_UI4( value1, value2, carry ) (carry) = (((value1) >= ((UI4)-1) - (value2)) ? (1) : (0))
#if MASTER_64_AVAILABLE == 1
#	define MASTER_ADD_OVERFLOW_UI8( value1, value2, carry ) (carry) = (((value1) >= ((UI8)-1) - (value2)) ? (1) : (0))
#endif /* #! 64 Bits !# */

/* #! MASTER Shifts !# */

#define MASTER_RLLN( value, shift, bit_count ) (((value) << (shift)) | ((value) >> ((bit_count) - (shift))))
#define MASTER_RLRN( value, shift, bit_count ) (((value) >> (shift)) | ((value) << ((bit_count) - (shift))))

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateleft8)
#	define MASTER_RLL1( value, shift ) __builtin_rotateleft8(value, shift)
#else
#	define MASTER_RLL1( value, shift ) MASTER_RLLN(value, shift, 8)
#endif /* #! Rotate left 1 byte !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateleft16)
#	define MASTER_RLL2( value, shift ) __builtin_rotateleft16(value, shift)
#else
#	define MASTER_RLL2( value, shift ) MASTER_RLLN(value, shift, 16)
#endif /* #! Rotate left 2 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateleft32)
#	define MASTER_RLL4( value, shift ) __builtin_rotateleft32(value, shift)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_stdc_rotate_left)
#	define MASTER_RLL4( value, shift ) __builtin_stdc_rotate_left(value, shift)
#elif defined(_MSC_VER)
#	define MASTER_RLL4( value, shift ) _rotl(value, shift)
#else
#	define MASTER_RLL4( value, shift ) MASTER_RLLN(value, shift, 32)
#endif /* #! Rotate left 4 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateleft64)
#	define MASTER_RLL8( value, shift ) __builtin_rotateleft64(value, shift)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_stdc_rotate_left)
#	define MASTER_RLL8( value, shift ) __builtin_stdc_rotate_left(value, shift)
#elif defined(_MSC_VER)
#	define MASTER_RLL8( value, shift ) _rotl64(value, shift)
#else
#	define MASTER_RLL8( value, shift ) MASTER_RLLN(value, shift, 64)
#endif /* #! Rotate left 8 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateright8)
#	define MASTER_RLR1( value, shift ) __builtin_rotateright8(value, shift)
#else
#	define MASTER_RLR1( value, shift ) MASTER_RLRN(value, shift, 8)
#endif /* #! Rotate right 1 byte !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateright16)
#	define MASTER_RLR2( value, shift ) __builtin_rotateright16(value, shift)
#else
#	define MASTER_RLR2( value, shift ) MASTER_RLRN(value, shift, 16)
#endif /* #! Rotate right 2 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateright32)
#	define MASTER_RLR4( value, shift ) __builtin_rotateright32(value, shift)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_stdc_rotate_right)
#	define MASTER_RLR4( value, shift ) __builtin_stdc_rotate_right(value, shift)
#elif defined(_MSC_VER)
#	define MASTER_RLR4( value, shift ) _rotr(value, shift)
#else
#	define MASTER_RLR4( value, shift ) MASTER_RLRN(value, shift, 32)
#endif /* #! Rotate right 4 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateright64)
#	define MASTER_RLR8( value, shift ) __builtin_rotateright64(value, shift)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_stdc_rotate_right)
#	define MASTER_RLR8( value, shift ) __builtin_stdc_rotate_right(value, shift)
#elif defined(_MSC_VER)
#	define MASTER_RLR8( value, shift ) _rotr64(value, shift)
#else
#	define MASTER_RLR8( value, shift ) MASTER_RLRN(value, shift, 64)
#endif /* #! Rotate right 8 bytes !# */

/* #! add (((value) < 0) ? (-1 - ((-1 - (value)) >> (shift))) : ((value) >> (shift))) ? !# */
#define MASTER_SRAGEN( value, shift ) (((value) < 0) ? (~((~(value)) >> (shift))) : ((value) >> (shift)))
#define MASTER_SRA1( value, shift ) (((value) >> (shift)) | (((value) & 0x80) ? (~(0xFF  >> (shift))) : 0))
#define MASTER_SRA2( value, shift ) (((value) >> (shift)) | (((value) & 0x8000) ? (~(0xFFFF  >> (shift))) : 0))
#define MASTER_SRA4( value, shift ) (((value) >> (shift)) | (((value) & 0x80000000) ? (~(0xFFFFFFFF  >> (shift))) : 0))
#define MASTER_SRA8( value, shift ) (((value) >> (shift)) | (((value) & 0x8000000000000000) ? (~(0xFFFFFFFFFFFFFFFF  >> (shift))) : 0))

/* #! MASTER Endian !# */

#define MASTER_LITTLE_ENDIAN_ORDER 0x04030201
#define MASTER_BIG_ENDIAN_ORDER 0x01020304
#define MASTER_NUXI_ENDIAN_ORDER 0x03040102
#define MASTER_PDP_ENDIAN_ORDER 0x02010403

#define MASTER_UNKNOWN_ENDIAN 0
#define MASTER_LITTLE_ENDIAN 1
#define MASTER_BIG_ENDIAN 2
#define MASTER_NUXI_ENDIAN 3
#define MASTER_PDP_ENDIAN 4

#if (defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || (defined(__LITTLE_ENDIAN__) && __LITTLE_ENDIAN__ + 0 == 1)
#	define MASTER_ENDIANNESS MASTER_LITTLE_ENDIAN
#elif (defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || (defined(__BIG_ENDIAN__) && __BIG_ENDIAN__ + 0 == 1)
#	define MASTER_ENDIANNESS MASTER_BIG_ENDIAN
#elif (defined(__BYTE_ORDER__) && defined(__ORDER_NUXI_ENDIAN__) && __BYTE_ORDER__ == __ORDER_NUXI_ENDIAN__) || (defined(__NUXI_ENDIAN__) && __NUXI_ENDIAN__ + 0 == 1)
#	define MASTER_ENDIANNESS MASTER_NUXI_ENDIAN
#elif (defined(__BYTE_ORDER__) && defined(__ORDER_PDP_ENDIAN__) && __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__) || (defined(__PDP_ENDIAN__) && __PDP_ENDIAN__ + 0 == 1)
#	define MASTER_ENDIANNESS MASTER_PDP_ENDIAN
#else
#	ifndef MASTER_NO_ARCHITECTURE_DETECT_DEPENDENCY
#		include <architecture_detect.h>
#		if MASTER_ARCHITECTURE_ENDIAN == MASTER_LITTLE_ENDIAN
#			define MASTER_ENDIANNESS MASTER_LITTLE_ENDIAN
#		elif MASTER_ARCHITECTURE_ENDIAN == MASTER_BIG_ENDIAN
#			define MASTER_ENDIANNESS MASTER_BIG_ENDIAN
#		elif MASTER_ARCHITECTURE_ENDIAN == MASTER_NUXI_ENDIAN
#			define MASTER_ENDIANNESS MASTER_NUXI_ENDIAN
#		elif MASTER_ARCHITECTURE_ENDIAN == MASTER_PDP_ENDIAN
#			define MASTER_ENDIANNESS MASTER_PDP_ENDIAN
#		endif * #! Architecture Endian !# */
#	endif /* #! MASTER_NO_ARCHITECTURE_DETECT_DEPENDENCY !# */
#	ifndef MASTER_ENDIANNESS
		UI1 MASTER_ENDIANNESS = 0;
		void
		MASTER_getEndianness( void ) {
			union {
				UI4 ui4_value;
				UI1 ui1_value[4];
			} number;
			number.ui1_value[0] = 0x01;
			number.ui1_value[1] = 0x02;
			number.ui1_value[2] = 0x03;
			number.ui1_value[3] = 0x04;
			if (number.ui4_value == MASTER_BIG_ENDIAN_ORDER)
				MASTER_ENDIANNESS = MASTER_BIG_ENDIAN;
			otherwise (number.ui4_value == MASTER_LITTLE_ENDIAN_ORDER)
				MASTER_ENDIANNESS = MASTER_LITTLE_ENDIAN;
			otherwise (number.ui4_value == MASTER_NUXI_ENDIAN_ORDER)
				MASTER_ENDIANNESS = MASTER_NUXI_ENDIAN;
			otherwise (number.ui4_value == MASTER_PDP_ENDIAN_ORDER)
				MASTER_ENDIANNESS = MASTER_PDP_ENDIAN;
			else
				MASTER_ENDIANNESS = MASTER_UNKNOWN_ENDIAN;
		}
#		warning "Unknown endianness. Using generic. Please, use function MASTER_getEndianness() in begin in main."
#		define MASTER_ENDIANNESS MASTER_getEndianness()
#		define MASTER_UNKNOWN_ENDIANNESS
#	endif /* #! MASTER_ENDIANNESS !# */
#endif /* #! ENDIANNESS !# */

#if defined(_MSC_VER)
#	define MASTER_BSWAP2( value ) _byteswap_ushort(value)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_bswap16)
#	define MASTER_BSWAP2( value ) __builtin_bswap16(value)
#else
#	define MASTER_BSWAP2( value ) (((value) >> 8) | ((value) << 8))
#endif /* #! Byte swap 2 bytes !# */

#if defined(_MSC_VER)
#	define MASTER_BSWAP4( value ) _byteswap_ulong(value)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_bswap32)
#	define MASTER_BSWAP4( value ) __builtin_bswap32(value)
#else
#	define MASTER_BSWAP4( value ) ( \
	(((value) >> 24) & 0x000000FF) | \
	(((value) >>  8) & 0x0000FF00) | \
	(((value) <<  8) & 0x00FF0000) | \
	(((value) << 24) & 0xFF000000))
#endif /* #! Byte swap 4 bytes !# */

#if defined(_MSC_VER)
#	define MASTER_BSWAP8( value ) _byteswap_ulong(value)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_bswap64)
#	define MASTER_BSWAP8( value ) __builtin_bswap64(value)
#else
#	define MASTER_BSWAP8( value ) ( \
	(((value) >> 56) & 0x00000000000000FF) | \
	(((value) >> 40) & 0x000000000000FF00) | \
	(((value) >> 24) & 0x0000000000FF0000) | \
	(((value) >>  8) & 0x00000000FF000000) | \
	(((value) <<  8) & 0x000000FF00000000) | \
	(((value) << 24) & 0x0000FF0000000000) | \
	(((value) << 40) & 0x00FF000000000000) | \
	(((value) << 56) & 0xFF00000000000000))
#endif /* #! Byte swap 8 bytes !# */
#define MASTER_BSWAP_GENERIC( value, byte_count ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_BSWAP2(value)) : ((byte_count) == 4) ? (MASTER_BSWAP4(value)) : (MASTER_BSWAP8(value)))

#define MASTER_IS_LE() (MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN)
#define MASTER_IS_BE() (MASTER_ENDIANNESS == MASTER_BIG_ENDIAN)
#define MASTER_IS_NUXI() (MASTER_ENDIANNESS == MASTER_NUXI_ENDIAN)
#define MASTER_IS_PDP() (MASTER_ENDIANNESS == MASTER_PDP_ENDIAN)
#ifdef MASTER_UNKNOWN_ENDIANNESS
#	define MASTER_IS_GENE() (1)
#else
#	define MASTER_IS_GENE() (0)
#endif /* #! MASTER_UNKNOWN_ENDIANNESS !# */

#define MASTER_L2LE2( value ) (value)
#define MASTER_L2LE4( value ) (value)
#define MASTER_L2LE8( value ) (value)
#define MASTER_L2BE2( value ) MASTER_BSWAP2(value)
#define MASTER_L2BE4( value ) MASTER_BSWAP4(value)
#define MASTER_L2BE8( value ) MASTER_BSWAP8(value)
#define MASTER_L2NUXI2( value ) (value)
#define MASTER_L2NUXI4( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_L2NUXI8( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))
#define MASTER_L2PDPE2( value ) MASTER_BSWAP2(value)
#define MASTER_L2PDPE4( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_L2PDPE8( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_L2LE( value ) (value)
#define MASTER_L2BE( value ) MASTER_BSWAP_GENERIC(value, sizeof(value))
#define MASTER_L2NUXI( value, byte_count ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_L2NUXI2(value)) : ((byte_count) == 4) ? (MASTER_L2NUXI4(value)) : (MASTER_L2NUXI8(value)))
#define MASTER_L2PDPE( value, byte_count ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_L2PDPE2(value)) : ((byte_count) == 4) ? (MASTER_L2PDPE4(value)) : (MASTER_L2PDP64(value)))

#define MASTER_B2LE2( value ) MASTER_BSWAP2(value)
#define MASTER_B2LE4( value ) MASTER_BSWAP4(value)
#define MASTER_B2LE8( value ) MASTER_BSWAP8(value)
#define MASTER_B2BE2( value ) (value)
#define MASTER_B2BE4( value ) (value)
#define MASTER_B2BE8( value ) (value)
#define MASTER_B2NUXI2( value ) MASTER_BSWAP2(value)
#define MASTER_B2NUXI4( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_B2NUXI8( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_B2PDPE2( value ) (value)
#define MASTER_B2PDPE4( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_B2PDPE8( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))
#define MASTER_B2LE( value ) MASTER_BSWAP_GENERIC(value, sizeof(value))
#define MASTER_B2BE( value ) (value)
#define MASTER_B2NUXI( value, byte_count ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_B2NUXI2(value)) : ((byte_count) == 4) ? (MASTER_B2NUXI4(value)) : (MASTER_B2NUXI8(value)))
#define MASTER_B2PDPE( value, byte_count ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_B2PDPE2(value)) : ((byte_count) == 4) ? (MASTER_B2PDPE4(value)) : (MASTER_B2PDP64(value)))

#define MASTER_NUXI2LE2( value ) (value)
#define MASTER_NUXI2LE4( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_NUXI2LE8( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_NUXI2BE2( value ) MASTER_BSWAP2(value)
#define MASTER_NUXI2BE4( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_NUXI2BE8( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_NUXI2NUXI2( value ) (value)
#define MASTER_NUXI2NUXI4( value ) (value)
#define MASTER_NUXI2NUXI8( value ) (value)
#define MASTER_NUXI2PDPE2( value ) MASTER_BSWAP2(value)
#define MASTER_NUXI2PDPE4( value ) MASTER_BSWAP4(value)
#define MASTER_NUXI2PDPE8( value ) MASTER_BSWAP8(value)
#define MASTER_NUXI2LE( value ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_NUXI2LE2(value)) : ((byte_count) == 4) ? (MASTER_NUXI2LE4(value)) : (MASTER_NUXI2LE8(value)))
#define MASTER_NUXI2BE( value ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_NUXI2BE2(value)) : ((byte_count) == 4) ? (MASTER_NUXI2BE4(value)) : (MASTER_NUXI2BE8(value)))
#define MASTER_NUXI2NUXI( value ) (value)
#define MASTER_NUXI2PDPE( value, byte_count ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_NUXI2PDPE2(value)) : ((byte_count) == 4) ? (MASTER_NUXI2PDPE4(value)) : (MASTER_NUXI2PDPE8(value)))

#define MASTER_PDP2LE2( value ) MASTER_BSWAP2(value)
#define MASTER_PDP2LE4( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_PDP2LE8( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_PDP2BE2( value ) (value)
#define MASTER_PDP2BE4( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_PDP2BE8( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))
#define MASTER_PDP2NUXI2( value ) MASTER_BSWAP2(value)
#define MASTER_PDP2NUXI4( value ) MASTER_BSWAP4(value)
#define MASTER_PDP2NUXI8( value ) MASTER_BSWAP8(value)
#define MASTER_PDP2PDPE2( value ) (value)
#define MASTER_PDP2PDPE4( value ) (value)
#define MASTER_PDP2PDPE8( value ) (value)
#define MASTER_PDP2LE( value ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_PDP2LE2(value)) : ((byte_count) == 4) ? (MASTER_PDP2LE4(value)) : (MASTER_PDP2LE8(value)))
#define MASTER_PDP2BE( value ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_PDP2BE2(value)) : ((byte_count) == 4) ? (MASTER_PDP2BE4(value)) : (MASTER_PDP2BE8(value)))
#define MASTER_PDP2NUXI( value, byte_count ) ( \
	((byte_count) == 1) ? (value) : ((byte_count) == 2) ? (MASTER_PDP2NUXI2(value)) : ((byte_count) == 4) ? (MASTER_PDP2NUXI4(value)) : (MASTER_PDP2NUXI8(value)))
#define MASTER_PDP2PDPE( value, byte_count ) (value)

#define MASTER_FUNC_ENDIAN( endian_little_func, endian_big_func, endian_nuxi_func, endian_pdp_func ) ( \
	(MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN) ? (endian_little_func) : \
	(MASTER_ENDIANNESS == MASTER_BIG_ENDIAN) ? (endian_big_func) : \
	(MASTER_ENDIANNESS == MASTER_NUXI_ENDIAN) ? (endian_nuxi_func) : (endian_pdp_func))

#define MASTER_ITERATE_L2H_LE( value ) ((value) += 1)
#define MASTER_ITERATE_H2L_LE( value ) ((value) -= 1)
#define MASTER_ITERATE_L2H_BE( value ) ((value) -= 1)
#define MASTER_ITERATE_H2L_BE( value ) ((value) += 1)
#define MASTER_ITERATE_L2H_PDP( value ) (((value) & 1) ? ((value) &= ~1) : ((value) += 3))
#define MASTER_ITERATE_H2L_PDP( value ) ((!((value) & 1)) ? ((value) |= 1) : ((value) -= 3))

#define MASTER_LELOW( min_value, max_value ) (min_value)
#define MASTER_LEHIGH( min_value, max_value ) (max_value)
#define MASTER_BELOW( min_value, max_value ) (max_value)
#define MASTER_BEHIGH( min_value, max_value ) (min_value)
#define MASTER_PDPELOW( min_value, max_value ) ((min_value) + 1)
#define MASTER_PDPEHIGH( min_value, max_value ) ((max_value) - 1)

/* #! TODO : NUXI, PDP !# */

#define MASTER_PTRLE2( ui1_pointer ) ((UI2)(ui1_pointer)[0] | ((UI2)(ui1_pointer)[1] << 8))
#define MASTER_PTRLE4( ui1_pointer ) ((UI4)(ui1_pointer)[0] | ((UI4)(ui1_pointer)[1] << 8) | ((UI4)(ui1_pointer)[2] << 16) | ((UI4)(ui1_pointer)[3] << 24))
#define MASTER_PTRLE8( ui1_pointer ) ((UI8)(ui1_pointer)[0] | ((UI8)(ui1_pointer)[1] << 8) | ((UI8)(ui1_pointer)[2] << 16) | ((UI8)(ui1_pointer)[3] << 24) | ((UI8)(ui1_pointer)[4] << 32) | ((UI8)(ui1_pointer)[5] << 40) | ((UI8)(ui1_pointer)[6] << 48) | ((UI8)(ui1_pointer)[7] << 56))
#define MASTER_PTRBE2( ui1_pointer ) ((UI2)(ui1_pointer)[1] | ((UI2)(ui1_pointer)[0] << 8))
#define MASTER_PTRBE4( ui1_pointer ) ((UI4)(ui1_pointer)[3] | ((UI4)(ui1_pointer)[2] << 8) | ((UI4)(ui1_pointer)[1] << 16) | ((UI4)(ui1_pointer)[0] << 24))
#define MASTER_PTRBE8( ui1_pointer ) ((UI8)(ui1_pointer)[7] | ((UI8)(ui1_pointer)[6] << 8) | ((UI8)(ui1_pointer)[5] << 16) | ((UI8)(ui1_pointer)[4] << 24) | ((UI8)(ui1_pointer)[3] << 32) | ((UI8)(ui1_pointer)[2] << 40) | ((UI8)(ui1_pointer)[1] << 48) | ((UI8)(ui1_pointer)[0] << 56))

#ifndef MASTER_UNKNOWN_ENDIANNESS
#	if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
#		define MASTER_TOLE( value ) (value)
#		define MASTER_TOLE2( value ) (value)
#		define MASTER_TOLE4( value ) (value)
#		define MASTER_TOLE8( value ) (value)
#		define MASTER_TOBE( value ) MASTER_L2BE(value)
#		define MASTER_TOBE2( value ) MASTER_L2BE2(value)
#		define MASTER_TOBE4( value ) MASTER_L2BE4(value)
#		define MASTER_TOBE8( value ) MASTER_L2BE8(value)
#		define MASTER_TONUXI( value ) MASTER_L2NUXI(value)
#		define MASTER_TONUXI2( value ) MASTER_L2NUXI2(value)
#		define MASTER_TONUXI4( value ) MASTER_L2NUXI4(value)
#		define MASTER_TONUXI8( value ) MASTER_L2NUXI8(value)
#		define MASTER_TOPDPE( value ) MASTER_L2PDPE(value)
#		define MASTER_TOPDPE2( value ) MASTER_L2PDPE2(value)
#		define MASTER_TOPDPE4( value ) MASTER_L2PDPE4(value)
#		define MASTER_TOPDPE8( value ) MASTER_L2PDPE8(value)
#		define MASTER_FROMLE( value ) (value)
#		define MASTER_FROMLE2( value ) (value)
#		define MASTER_FROMLE4( value ) (value)
#		define MASTER_FROMLE8( value ) (value)
#		define MASTER_FROMBE( value ) MASTER_B2LE(value)
#		define MASTER_FROMBE2( value ) MASTER_B2LE2(value)
#		define MASTER_FROMBE4( value ) MASTER_B2LE4(value)
#		define MASTER_FROMBE8( value ) MASTER_B2LE8(value)
#		define MASTER_FROMNUXI( value ) MASTER_NUXI2LE(value)
#		define MASTER_FROMNUXI2( value ) MASTER_NUXI2LE2(value)
#		define MASTER_FROMNUXI4( value ) MASTER_NUXI2LE4(value)
#		define MASTER_FROMNUXI8( value ) MASTER_NUXI2LE8(value)
#		define MASTER_FROMPDPE( value ) MASTER_PDP2LE(value)
#		define MASTER_FROMPDPE2( value ) MASTER_PDP2LE2(value)
#		define MASTER_FROMPDPE4( value ) MASTER_PDP2LE4(value)
#		define MASTER_FROMPDPE8( value ) MASTER_PDP2LE8(value)
#		define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_LE(value)
#		define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_LE(value)
#		define MASTER_GLIBE( min_value, max_value ) MASTER_LELOW( min_value, max_value )
#		define MASTER_GHIBE( min_value, max_value ) MASTER_LEHIGH( min_value, max_value )
#	elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
#		define MASTER_TOLE( value ) MASTER_B2LE(value)
#		define MASTER_TOLE2( value ) MASTER_B2LE2(value)
#		define MASTER_TOLE4( value ) MASTER_B2LE4(value)
#		define MASTER_TOLE8( value ) MASTER_B2LE8(value)
#		define MASTER_TOBE( value ) (value)
#		define MASTER_TOBE2( value ) (value)
#		define MASTER_TOBE4( value ) (value)
#		define MASTER_TOBE8( value ) (value)
#		define MASTER_TONUXI( value ) MASTER_B2NUXI(value)
#		define MASTER_TONUXI2( value ) MASTER_B2NUXI2(value)
#		define MASTER_TONUXI4( value ) MASTER_B2NUXI4(value)
#		define MASTER_TONUXI8( value ) MASTER_B2NUXI8(value)
#		define MASTER_TOPDPE( value ) MASTER_B2PDPE(value)
#		define MASTER_TOPDPE2( value ) MASTER_B2PDPE2(value)
#		define MASTER_TOPDPE4( value ) MASTER_B2PDPE4(value)
#		define MASTER_TOPDPE8( value ) MASTER_B2PDPE8(value)
#		define MASTER_FROMLE( value ) MASTER_L2BE(value)
#		define MASTER_FROMLE2( value ) MASTER_L2BE2(value)
#		define MASTER_FROMLE4( value ) MASTER_L2BE4(value)
#		define MASTER_FROMLE8( value ) MASTER_L2BE8(value)
#		define MASTER_FROMBE( value ) (value)
#		define MASTER_FROMBE2( value ) (value)
#		define MASTER_FROMBE4( value ) (value)
#		define MASTER_FROMBE8( value ) (value)
#		define MASTER_FROMNUXI( value ) MASTER_NUXI2BE(value)
#		define MASTER_FROMNUXI2( value ) MASTER_NUXI2BE2(value)
#		define MASTER_FROMNUXI4( value ) MASTER_NUXI2BE4(value)
#		define MASTER_FROMNUXI8( value ) MASTER_NUXI2BE8(value)
#		define MASTER_FROMPDPE( value ) MASTER_PDP2BE(value)
#		define MASTER_FROMPDPE2( value ) MASTER_PDP2BE2(value)
#		define MASTER_FROMPDPE4( value ) MASTER_PDP2BE4(value)
#		define MASTER_FROMPDPE8( value ) MASTER_PDP2BE8(value)
#		define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_BE(value)
#		define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_BE(value)
#		define MASTER_GLIBE( min_value, max_value ) MASTER_BELOW( min_value, max_value )
#		define MASTER_GHIBE( min_value, max_value ) MASTER_BEHIGH( min_value, max_value )
#	elif MASTER_ENDIANNESS == MASTER_NUXI_ENDIAN
#		define MASTER_TOLE( value ) MASTER_NUXI2LE(value)
#		define MASTER_TOLE2( value ) MASTER_NUXI2LE2(value)
#		define MASTER_TOLE4( value ) MASTER_NUXI2LE4(value)
#		define MASTER_TOLE8( value ) MASTER_NUXI2LE8(value)
#		define MASTER_TOBE( value ) MASTER_NUXI2BE(value)
#		define MASTER_TOBE2( value ) MASTER_NUXI2BE2(value)
#		define MASTER_TOBE4( value ) MASTER_NUXI2BE4(value)
#		define MASTER_TOBE8( value ) MASTER_NUXI2BE8(value)
#		define MASTER_TONUXI( value ) (value)
#		define MASTER_TONUXI2( value ) (value)
#		define MASTER_TONUXI4( value ) (value)
#		define MASTER_TONUXI8( value ) (value)
#		define MASTER_TOPDPE( value ) MASTER_NUXI2PDPE(value)
#		define MASTER_TOPDPE2( value ) MASTER_NUXI2PDPE2(value)
#		define MASTER_TOPDPE4( value ) MASTER_NUXI2PDPE4(value)
#		define MASTER_TOPDPE8( value ) MASTER_NUXI2PDPE8(value)
#		define MASTER_FROMLE( value ) MASTER_L2PDPE(value)
#		define MASTER_FROMLE2( value ) MASTER_L2PDPE2(value)
#		define MASTER_FROMLE4( value ) MASTER_L2PDPE4(value)
#		define MASTER_FROMLE8( value ) MASTER_L2PDPE8(value)
#		define MASTER_FROMBE( value ) MASTER_B2NUXI(value)
#		define MASTER_FROMBE2( value ) MASTER_B2NUXI2(value)
#		define MASTER_FROMBE4( value ) MASTER_B2NUXI4(value)
#		define MASTER_FROMBE8( value ) MASTER_B2NUXI8(value)
#		define MASTER_FROMNUXI( value ) (value)
#		define MASTER_FROMNUXI2( value ) (value)
#		define MASTER_FROMNUXI4( value ) (value)
#		define MASTER_FROMNUXI8( value ) (value)
#		define MASTER_FROMPDPE( value ) MASTER_PDP2NUXI(value)
#		define MASTER_FROMPDPE2( value ) MASTER_PDP2NUXI2(value)
#		define MASTER_FROMPDPE4( value ) MASTER_PDP2NUXI4(value)
#		define MASTER_FROMPDPE8( value ) MASTER_PDP2NUXI8(value)
#		define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_PDPE(value)
#		define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_PDPE(value)
#		define MASTER_GLIBE( min_value, max_value ) MASTER_PDPELOW( min_value, max_value )
#		define MASTER_GHIBE( min_value, max_value ) MASTER_PDPEHIGH( min_value, max_value )
#	elif MASTER_ENDIANNESS == MASTER_PDP_ENDIAN
		/* #! PDP have maximum 32 bits. But in 64 bit endian will be 78563412 !# */
#		define MASTER_TOLE( value ) MASTER_PDP2LE(value)
#		define MASTER_TOLE2( value ) MASTER_PDP2LE2(value)
#		define MASTER_TOLE4( value ) MASTER_PDP2LE4(value)
#		define MASTER_TOLE8( value ) MASTER_PDP2LE8(value)
#		define MASTER_TOBE( value ) MASTER_PDP2BE(value)
#		define MASTER_TOBE2( value ) MASTER_PDP2BE2(value)
#		define MASTER_TOBE4( value ) MASTER_PDP2BE4(value)
#		define MASTER_TOBE8( value ) MASTER_PDP2BE8(value)
#		define MASTER_TONUXI( value ) MASTER_PDP2NUXI(value)
#		define MASTER_TONUXI2( value ) MASTER_PDP2NUXI2(value)
#		define MASTER_TONUXI4( value ) MASTER_PDP2NUXI4(value)
#		define MASTER_TONUXI8( value ) MASTER_PDP2NUXI8(value)
#		define MASTER_TOPDPE( value ) (value)
#		define MASTER_TOPDPE2( value ) (value)
#		define MASTER_TOPDPE4( value ) (value)
#		define MASTER_TOPDPE8( value ) (value)
#		define MASTER_FROMLE( value ) MASTER_L2PDPE(value)
#		define MASTER_FROMLE2( value ) MASTER_L2PDPE2(value)
#		define MASTER_FROMLE4( value ) MASTER_L2PDPE4(value)
#		define MASTER_FROMLE8( value ) MASTER_L2PDPE8(value)
#		define MASTER_FROMBE( value ) MASTER_B2PDPE(value)
#		define MASTER_FROMBE2( value ) MASTER_B2PDPE2(value)
#		define MASTER_FROMBE4( value ) MASTER_B2PDPE4(value)
#		define MASTER_FROMBE8( value ) MASTER_B2PDPE8(value)
#		define MASTER_FROMNUXI( value ) MASTER_NUXI2PDPE(value)
#		define MASTER_FROMNUXI2( value ) MASTER_NUXI2PDPE2(value)
#		define MASTER_FROMNUXI4( value ) MASTER_NUXI2PDPE4(value)
#		define MASTER_FROMNUXI8( value ) MASTER_NUXI2PDPE8(value)
#		define MASTER_FROMPDPE( value ) (value)
#		define MASTER_FROMPDPE2( value ) (value)
#		define MASTER_FROMPDPE4( value ) (value)
#		define MASTER_FROMPDPE8( value ) (value)
#		define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_PDPE(value)
#		define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_PDPE(value)
#		define MASTER_GLIBE( min_value, max_value ) MASTER_PDPELOW( min_value, max_value )
#		define MASTER_GHIBE( min_value, max_value ) MASTER_PDPEHIGH( min_value, max_value )
#	endif /* #! Endianness !# */
#else /* #! MASTER_UNKNOWN_ENDIAN - runtime check !# */
/* #! TODO !# */
#	define MASTER_TOLE( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE(value), MASTER_B2LE(value), MASTER_NUXI2LE(value), MASTER_PDP2LE(value))
#	define MASTER_TOLE2( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE2(value), MASTER_B2LE2(value), MASTER_NUXI2LE2(value), MASTER_PDP2LE2(value))
#	define MASTER_TOLE4( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE4(value), MASTER_B2LE4(value), MASTER_NUXI2LE4(value), MASTER_PDP2LE4(value))
#	define MASTER_TOLE8( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE8(value), MASTER_B2LE8(value), MASTER_NUXI2LE8(value), MASTER_PDP2LE8(value))
#	define MASTER_TOBE( value ) MASTER_FUNC_ENDIAN(MASTER_L2BE(value), MASTER_B2BE(value), MASTER_NUXI2BE(value), MASTER_PDP2BE(value))
#	define MASTER_TOBE2( value ) MASTER_FUNC_ENDIAN(MASTER_L2BE2(value), MASTER_B2BE2(value), MASTER_NUXI2BE2(value), MASTER_PDP2BE2(value))
#	define MASTER_TOBE4( value ) MASTER_FUNC_ENDIAN(MASTER_L2BE4(value), MASTER_B2BE4(value), MASTER_NUXI2BE4(value), MASTER_PDP2BE4(value))
#	define MASTER_TOBE8( value ) MASTER_FUNC_ENDIAN(MASTER_L2BE8(value), MASTER_B2BE8(value), MASTER_NUXI2BE8(value), MASTER_PDP2BE8(value))
#	define MASTER_TONUXI( value ) MASTER_FUNC_ENDIAN(MASTER_L2NUXI(value), MASTER_B2NUXI(value), MASTER_NUXI2NUXI(value), MASTER_PDP2NUXI(value))
#	define MASTER_TONUXI2( value ) MASTER_FUNC_ENDIAN(MASTER_L2NUXI2(value), MASTER_B2NUXI2(value), MASTER_NUXI2NUXI2(value), MASTER_PDP2NUXI2(value))
#	define MASTER_TONUXI4( value ) MASTER_FUNC_ENDIAN(MASTER_L2NUXI4(value), MASTER_B2NUXI4(value), MASTER_NUXI2NUXI4(value), MASTER_PDP2NUXI4(value))
#	define MASTER_TONUXI8( value ) MASTER_FUNC_ENDIAN(MASTER_L2NUXI8(value), MASTER_B2NUXI8(value), MASTER_NUXI2NUXI8(value), MASTER_PDP2NUXI8(value))
#	define MASTER_TOPDPE( value ) MASTER_FUNC_ENDIAN(MASTER_L2PDPE(value), MASTER_B2PDPE(value), MASTER_NUXI2PDPE(value), MASTER_PDP2PDPE(value))
#	define MASTER_TOPDPE2( value ) MASTER_FUNC_ENDIAN(MASTER_L2PDPE2(value), MASTER_B2PDPE2(value), MASTER_NUXI2PDPE2(value), MASTER_PDP2PDPE2(value))
#	define MASTER_TOPDPE4( value ) MASTER_FUNC_ENDIAN(MASTER_L2PDPE4(value), MASTER_B2PDPE4(value), MASTER_NUXI2PDPE4(value), MASTER_PDP2PDPE4(value))
#	define MASTER_TOPDPE8( value ) MASTER_FUNC_ENDIAN(MASTER_L2PDPE8(value), MASTER_B2PDPE8(value), MASTER_NUXI2PDPE8(value), MASTER_PDP2PDPE8(value))
#	define MASTER_FROMLE( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE(value), MASTER_L2BE(value), MASTER_L2NUXI(value), MASTER_L2PDPE(value))
#	define MASTER_FROMLE2( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE2(value), MASTER_L2BE2(value), MASTER_L2NUXI2(value), MASTER_L2PDPE2(value))
#	define MASTER_FROMLE4( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE4(value), MASTER_L2BE4(value), MASTER_L2NUXI4(value), MASTER_L2PDPE4(value))
#	define MASTER_FROMLE8( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE8(value), MASTER_L2BE8(value), MASTER_L2NUXI8(value), MASTER_L2PDPE8(value))
#	define MASTER_FROMBE( value ) MASTER_FUNC_ENDIAN(MASTER_B2LE(value), MASTER_B2BE(value), MASTER_B2NUXI(value), MASTER_B2PDPE(value))
#	define MASTER_FROMBE2( value ) MASTER_FUNC_ENDIAN(MASTER_B2LE2(value), MASTER_B2BE2(value), MASTER_B2NUXI2(value), MASTER_B2PDPE2(value))
#	define MASTER_FROMBE4( value ) MASTER_FUNC_ENDIAN(MASTER_B2LE4(value), MASTER_B2BE4(value), MASTER_B2NUXI4(value), MASTER_B2PDPE4(value))
#	define MASTER_FROMBE8( value ) MASTER_FUNC_ENDIAN(MASTER_B2LE8(value), MASTER_B2BE8(value), MASTER_B2NUXI8(value), MASTER_B2PDPE8(value))
#	define MASTER_FROMNUXI( value ) MASTER_FUNC_ENDIAN(MASTER_NUXI2LE(value), MASTER_NUXI2BE(value), MASTER_NUXI2NUXI(value), MASTER_NUXI2PDPE(value))
#	define MASTER_FROMNUXI2( value ) MASTER_FUNC_ENDIAN(MASTER_NUXI2LE2(value), MASTER_NUXI2BE2(value), MASTER_NUXI2NUXI2(value), MASTER_NUXI2PDPE2(value))
#	define MASTER_FROMNUXI4( value ) MASTER_FUNC_ENDIAN(MASTER_NUXI2LE4(value), MASTER_NUXI2BE4(value), MASTER_NUXI2NUXI4(value), MASTER_NUXI2PDPE4(value))
#	define MASTER_FROMNUXI8( value ) MASTER_FUNC_ENDIAN(MASTER_NUXI2LE8(value), MASTER_NUXI2BE8(value), MASTER_NUXI2NUXI8(value), MASTER_NUXI2PDPE8(value))
#	define MASTER_FROMPDPE( value ) MASTER_FUNC_ENDIAN(MASTER_PDP2LE(value), MASTER_PDP2BE(value), MASTER_PDP2NUXI(value), MASTER_PDP2PDPE(value))
#	define MASTER_FROMPDPE2( value ) MASTER_FUNC_ENDIAN(MASTER_PDP2LE2(value), MASTER_PDP2BE2(value), MASTER_PDP2NUXI2(value), MASTER_PDP2PDPE2(value))
#	define MASTER_FROMPDPE4( value ) MASTER_FUNC_ENDIAN(MASTER_PDP2LE4(value), MASTER_PDP2BE4(value), MASTER_PDP2NUXI4(value), MASTER_PDP2PDPE4(value))
#	define MASTER_FROMPDPE8( value ) MASTER_FUNC_ENDIAN(MASTER_PDP2LE8(value), MASTER_PDP2BE8(value), MASTER_PDP2NUXI8(value), MASTER_PDP2PDPE8(value))
/* #! TODO !# */
#	define MASTER_ITERATE_L2H( value )
#	define MASTER_ITERATE_H2L( value )
#	define MASTER_GLIBE( min_value, max_value )
#	define MASTER_GHIBE( min_value, max_value )
#endif /* #! Endianness !# */

/* #! MASTER Saturation Functions !# */

#define MASTER_SaturateSI1( value ) (SI1)MASTER_CLAMP(value, MASTER_SI1_MIN, MASTER_SI1_MAX)
#define MASTER_SaturateSI2( value ) (SI2)MASTER_CLAMP(value, MASTER_SI2_MIN, MASTER_SI2_MAX)
#define MASTER_SaturateSI4( value ) (SI4)MASTER_CLAMP(value, MASTER_SI4_MIN, MASTER_SI4_MAX)
#define MASTER_SaturateUI1( value ) (UI1)MASTER_CLAMP(value, MASTER_UI1_MIN, MASTER_UI1_MAX)
#define MASTER_SaturateUI2( value ) (UI2)MASTER_CLAMP(value, MASTER_UI2_MIN, MASTER_UI2_MAX)
#define MASTER_SaturateUI4( value ) (UI4)MASTER_CLAMP(value, MASTER_UI4_MIN, MASTER_UI4_MAX)

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI1, MASTER_AddSaturateSI1, ( const SI1, const SI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI2, MASTER_AddSaturateSI2, ( const SI2, const SI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_AddSaturateSI4, ( const SI4, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI1, MASTER_SubSaturateSI1, ( const SI1, const SI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI2, MASTER_SubSaturateSI2, ( const SI2, const SI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_SubSaturateSI4, ( const SI4, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI1, MASTER_MulSaturateSI1, ( const SI1, const SI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI2, MASTER_MulSaturateSI2, ( const SI2, const SI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_MulSaturateSI4, ( const SI4, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_AddSaturateUI1, ( const UI1, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_AddSaturateUI2, ( const UI2, const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_AddSaturateUI4, ( const UI4, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_SubSaturateUI1, ( const UI1, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_SubSaturateUI2, ( const UI2, const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_SubSaturateUI4, ( const UI4, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_MulSaturateUI1, ( const UI1, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_MulSaturateUI2, ( const UI2, const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_MulSaturateUI4, ( const UI4, const UI4 ) );
#if MASTER_64_AVAILABLE == 1
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI8, MASTER_AddSaturateSI8, ( const SI8, const SI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI8, MASTER_SubSaturateSI8, ( const SI8, const SI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI8, MASTER_MulSaturateSI8, ( const SI8, const SI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_AddSaturateUI8, ( const UI8, const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_SubSaturateUI8, ( const UI8, const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_MulSaturateUI8, ( const UI8, const UI8 ) );
#endif /* #! 64 Bits !# */

#define MASTER_zRIVATE_MACROS_DEFINE_AddSaturateSIx( variable_type ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_AddSaturate ## variable_type /* ! */, \
		variable_type, \
		( const variable_type, value1 ), \
		( const variable_type, value2 ) \
	) { \
		const variable_type value3 = value1 + value2; \
		if (value1 > 0 && value2 > 0 && value3 < 0) return MASTER_ ## variable_type ## _MAX; \
		if (value1 < 0 && value2 < 0 && value3 > 0) return MASTER_ ## variable_type ## _MIN; \
		return value3; \
	}

#define MASTER_zRIVATE_MACROS_DEFINE_AddSaturateUIx( variable_type ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_AddSaturate ## variable_type /* ! */, \
		variable_type, \
		( const variable_type, value1 ), \
		( const variable_type, value2 ) \
	) { \
		const variable_type value3 = value1 + value2; \
		if (value3 < value1) return MASTER_ ## variable_type ## _MAX; \
		return value3; \
	}

#define MASTER_zRIVATE_MACROS_DEFINE_SubSaturateSIx( variable_type ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_SubSaturate ## variable_type /* ! */, \
		variable_type, \
		( const variable_type, value1 ), \
		( const variable_type, value2 ) \
	) { \
		const variable_type value3 = value1 - value2; \
		if (value1 >= 0 && value2 < 0 && value3 < 0) return MASTER_ ## variable_type ## _MAX; \
		if (value1 < 0 && value2 > 0 && value3 > 0) return MASTER_ ## variable_type ## _MIN; \
		return value3; \
	}

#define MASTER_zRIVATE_MACROS_DEFINE_SubSaturateUIx( variable_type ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_SubSaturate ## variable_type /* ! */, \
		variable_type, \
		( const variable_type, value1 ), \
		( const variable_type, value2 ) \
	) { \
		const variable_type value3 = value1 - value2; \
		if (value3 > value1) return MASTER_ ## variable_type ## _MIN; \
		return value3; \
	}

#define MASTER_zRIVATE_MACROS_DEFINE_MulSaturateSIx( variable_type ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_MulSaturate ## variable_type /* ! */, \
		variable_type, \
		( const variable_type, value1 ), \
		( const variable_type, value2 ) \
	) { \
		const variable_type value3 = value1 * value2; \
		return (value2 != 0 && value3 / value2 != value1) ? ( ((value1 > 0) == (value2 > 0)) ? (MASTER_ ## variable_type ## _MAX) : (MASTER_ ## variable_type ## _MIN) ) : (value3); \
	}

#define MASTER_zRIVATE_MACROS_DEFINE_MulSaturateUIx( variable_type ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_MulSaturate ## variable_type /* ! */, \
		variable_type, \
		( const variable_type, value1 ), \
		( const variable_type, value2 ) \
	) { \
		const variable_type value3 = value1 * value2; \
		if (value2 != 0 && value3 / value2 != value1) return MASTER_ ## variable_type ## _MAX; \
		return value3; \
	}

MASTER_zRIVATE_MACROS_DEFINE_AddSaturateSIx( SI1 )
MASTER_zRIVATE_MACROS_DEFINE_SubSaturateSIx( SI1 )
MASTER_zRIVATE_MACROS_DEFINE_MulSaturateSIx( SI1 )
MASTER_zRIVATE_MACROS_DEFINE_AddSaturateSIx( SI2 )
MASTER_zRIVATE_MACROS_DEFINE_SubSaturateSIx( SI2 )
MASTER_zRIVATE_MACROS_DEFINE_MulSaturateSIx( SI2 )
MASTER_zRIVATE_MACROS_DEFINE_AddSaturateSIx( SI4 )
MASTER_zRIVATE_MACROS_DEFINE_SubSaturateSIx( SI4 )
MASTER_zRIVATE_MACROS_DEFINE_MulSaturateSIx( SI4 )
MASTER_zRIVATE_MACROS_DEFINE_AddSaturateUIx( UI1 )
MASTER_zRIVATE_MACROS_DEFINE_SubSaturateUIx( UI1 )
MASTER_zRIVATE_MACROS_DEFINE_MulSaturateUIx( UI1 )
MASTER_zRIVATE_MACROS_DEFINE_AddSaturateUIx( UI2 )
MASTER_zRIVATE_MACROS_DEFINE_SubSaturateUIx( UI2 )
MASTER_zRIVATE_MACROS_DEFINE_MulSaturateUIx( UI2 )
MASTER_zRIVATE_MACROS_DEFINE_AddSaturateUIx( UI4 )
MASTER_zRIVATE_MACROS_DEFINE_SubSaturateUIx( UI4 )
MASTER_zRIVATE_MACROS_DEFINE_MulSaturateUIx( UI4 )
#if MASTER_64_AVAILABLE == 1
	MASTER_zRIVATE_MACROS_DEFINE_AddSaturateSIx( SI8 )
	MASTER_zRIVATE_MACROS_DEFINE_SubSaturateSIx( SI8 )
	MASTER_zRIVATE_MACROS_DEFINE_MulSaturateSIx( SI8 )
	MASTER_zRIVATE_MACROS_DEFINE_AddSaturateUIx( UI8 )
	MASTER_zRIVATE_MACROS_DEFINE_SubSaturateUIx( UI8 )
	MASTER_zRIVATE_MACROS_DEFINE_MulSaturateUIx( UI8 )
#endif /* #! 64 Bits !# */

#undef MASTER_zRIVATE_MACROS_DEFINE_AddSaturateUIx
#undef MASTER_zRIVATE_MACROS_DEFINE_AddSaturateSIx
#undef MASTER_zRIVATE_MACROS_DEFINE_SubSaturateUIx
#undef MASTER_zRIVATE_MACROS_DEFINE_SubSaturateSIx
#undef MASTER_zRIVATE_MACROS_DEFINE_MulSaturateUIx
#undef MASTER_zRIVATE_MACROS_DEFINE_MulSaturateSIx

/* #! MASTER Comment !# */

#define MASTER_COMMENT( comment )
#define MASTER_UNUSED( variable ) (void)variable

/* #! MASTER Libraries States !# */

#define MASTER_LIBRARY_STATE_MASK 0x7
#define MASTER_LIBRARY_INCREMENT_MASK 0x8
#define MASTER_LIBRARY_CHARNAME_MASK 0x30
#define MASTER_LIBRARY_ARGS_MASK 0xC0
#define MASTER_LIBRARY_GRAPHS_MASK 0x100
#define MASTER_LIBRARY_DEPENDENCY_MASK 0x200

#define MASTER_LIBRARY_STATE_SHIFT 0
#define MASTER_LIBRARY_INCREMENT_SHIFT 3
#define MASTER_LIBRARY_CHARNAME_SHIFT 4
#define MASTER_LIBRARY_ARGS_SHIFT 6
#define MASTER_LIBRARY_GRAPHS_SHIFT 8
#define MASTER_LIBRARY_DEPENDENCY_SHIFT 9

/* #!! States !!# */
#define MASTER_LIBRARY_UNAVAILABLE (0 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_INDEV (1 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_TESTING (2 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_AVAILABLE (3 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_COMPLETED (4 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_DEPRECATED (5 << MASTER_LIBRARY_STATE_SHIFT)

/* #!! Increment / Decrement !## */
#define MASTER_LIBRARY_INCREMENTHATE (1 << MASTER_LIBRARY_INCREMENT_MASK)
#define MASTER_LIBRARY_INCREMENT (0 << MASTER_LIBRARY_INCREMENT_MASK)

/* #!! Character Name !!# */
#define MASTER_LIBRARY_FiCViN (2 << MASTER_LIBRARY_CHARNAME_SHIFT)
#define MASTER_LIBRARY_OCViNHATE (1 << MASTER_LIBRARY_CHARNAME_SHIFT)
#define MASTER_LIBRARY_OCViN (0 << MASTER_LIBRARY_CHARNAME_SHIFT)

/* #!! Arguments !!# */
#define MASTER_LIBRARY_MASTERARGS (2 << MASTER_LIBRARY_ARGS_SHIFT)
#define MASTER_LIBRARY_KAIRARGS (1 << MASTER_LIBRARY_ARGS_SHIFT)
#define MASTER_LIBRARY_STDARGS (0 << MASTER_LIBRARY_ARGS_SHIFT)
#define MASTER_LIBRARY_NO_FUNCTIONS (1 << MASTER_LIBRARY_ARGS_SHIFT)

/* #!! Graphs !!# */
#define MASTER_LIBRARY_GRAPHSHATE (1 << MASTER_LIBRARY_GRAPHS_SHIFT)
#define MASTER_LIBRARY_TRIODUOGRAPHS (0 << MASTER_LIBRARY_GRAPHS_SHIFT)

/* #!! Dependency !!# */
#define MASTER_LIBRARY_FREESTANDING (1 << MASTER_LIBRARY_DEPENDENCY_SHIFT)
#define MASTER_LIBRARY_LIBC (0 << MASTER_LIBRARY_DEPENDENCY_SHIFT)

#define MASTER_LIBRARY_RANK( libval ) \
	((((libval) & MASTER_LIBRARY_STATE_MASK) >> MASTER_LIBRARY_STATE_SHIFT) + \
	(((libval) & MASTER_LIBRARY_INCREMENT_MASK) >> MASTER_LIBRARY_INCREMENT_SHIFT) + \
	(((libval) & MASTER_LIBRARY_CHARNAME_MASK) >> MASTER_LIBRARY_CHARNAME_SHIFT) + \
	(((libval) & MASTER_LIBRARY_ARGS_MASK) >> MASTER_LIBRARY_ARGS_SHIFT) + \
	(((libval) & MASTER_LIBRARY_GRAPHS_MASK) >> MASTER_LIBRARY_GRAPHS_SHIFT) + \
	(((libval) & MASTER_LIBRARY_DEPENDENCY_MASK) >> MASTER_LIBRARY_DEPENDENCY_SHIFT))

/* #! MASTER Function Markers !# */

#define MASTER_MARKER_COMPRESSION
#define MASTER_MARKER_CRYPTOGRAPHY
#define MASTER_MARKER_MATH
#define MASTER_MARKER_PARSER
#define MASTER_MARKER_SORTER
#define MASTER_MARKER_SOLVER

#define MASTER_MARKER_CONSTANT_TIME
#define MASTER_MARKER_DOUBTFUL_CT
#define MASTER_MARKER_NO_CT

#define MASTER_MARKER_ONESHOT
#define MASTER_MARKER_FSM
#define MASTER_MARKER_CREATE
#define MASTER_MARKER_INIT
#define MASTER_MARKER_FLUSH
#define MASTER_MARKER_END
#define MASTER_MARKER_FREE
#define MASTER_MARKER_EXTRA_INFO

#define MASTER_MARKER_GENERATOR
#define MASTER_MARKER_GENERABLE( funcname )

#define MASTER_MARKER_ONLY_FOR( comment )

#define MASTER_MARKER_NOT_DOCUMENTED
#define MASTER_MARKER_DOCUMENTED( docpath )
#define MASTER_MARKER_NIH( docpath )

/* #! Next macros i will use only when at least someone asked !# */
#define MASTER_MARKER_WIKIPEDIA_SOURCE( wikipath )

#define MASTER_MARKER_AGENT
#define MASTER_MARKER_DISPATCHER
#define MASTER_MARKER_EMPLOYEE
#define MASTER_MARKER_PSYHOPATH
#define MASTER_MARKER_PATENTED
#define MASTER_MARKER_COPY( copy )
#define MASTER_MARKER_DEEPREADER
#define MASTER_MARKER_DEEPWRITER
#define MASTER_MARKER_ULP( value )
#define MASTER_MARKER_NAIVE
#define MASTER_MARKER_THREADHATE
#define MASTER_MARKER_FOREIGNER

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_CODE_STYLE_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_CODE_STYLE_INCLUDE_H !# */

/* #! be master~ !# */
