
/*
 * Copyright (c) 2025 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_CODE_STYLE_INCLUDE_H__
#define __MASTER_CODE_STYLE_INCLUDE_H__ (MASTER_LIBRARY_AVAILABLE + \
										 MASTER_LIBRARY_INCREMENTHATE + \
										 MASTER_LIBRARY_OCViN + \
										 MASTER_LIBRARY_STDARGS + \
										 MASTER_LIBRARY_GRAPHSHATE + \
										 MASTER_LIBRARY_LIBC)

/* #! High priority !# */

/* #! MASTER Generalization Of Macroses !# */

#ifdef MASTER_NO_DEPENDENCIES
	#define MASTER_NO_LIBC_DEPENDENCIES
	#define MASTER_NO_MASTER_DEPENDENCIES
#endif /* #! MASTER_NO_DEPENDENCIES !# */

#ifdef MASTER_NO_LIBC_DEPENDENCIES
	#define MASTER_NO_STRING_DEPENDENCY
	#define MASTER_NO_LIMITS_DEPENDENCY
#endif /* #! MASTER_NO_LIBC_DEPENDENCIES !# */

#ifdef MASTER_NO_MASTER_DEPENDENCIES
	#define MASTER_NO_ARCHITECTURE_DETECT_DEPENDENCY
	#define MASTER_NO_COMPILER_SETTINGS_DEPENDENCY
#endif /* #! MASTER_NO_MASTER_DEPENDENCIES !# */

/* #! MASTER Types !# */

#if !defined(__STDC_VERSION__) && !defined(MASTER_IGNORE_C89_STD_64_VARIABLES)
	#define __MASTER_PREFER_LONGLONG long
	#define __MASTER_PREFER_64 0
#else
	#define __MASTER_PREFER_LONGLONG long long
	#define __MASTER_PREFER_64 1
#endif /* #! C89 Long Long Check !# */

#ifndef MASTER_64_AVAILABLE
	#ifdef __cplusplus
		typedef unsigned long long MASTER_maxint;
		#define MASTER_64_AVAILABLE 1
	#elif !defined(MASTER_NO_LIMITS_DEPENDENCY) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		#include <limits.h>
		#if defined(ULLONG_MAX)
			typedef unsigned __MASTER_PREFER_LONGLONG MASTER_maxint;
			#define MASTER_64_AVAILABLE __MASTER_PREFER_64
		#elif defined(ULONG_MAX) && (ULONG_MAX >= 0xFFFFFFFFFFFFFFFFULL)
			typedef unsigned long MASTER_maxint;
			#define MASTER_64_AVAILABLE __MASTER_PREFER_64
		#else
			typedef unsigned long MASTER_maxint;
			#define MASTER_64_AVAILABLE 0
		#endif /* #! C version !# */
	#elif !defined(MASTER_NO_ARCHITECTURE_DETECT_DEPENDENCY) && !defined(MASTER_IGNORE_ARCHITECTURE)
		#include <architecture_detect.h>
		#if MASTER_ARCHITECTURE_CPU_WIDTH >= 64
			#if !defined(__STDC_VERSION__)
				typedef unsigned __MASTER_PREFER_LONGLONG MASTER_maxint;
			#else
				typedef unsigned __MASTER_PREFER_LONGLONG MASTER_maxint;
			#endif /* #! C89 !# */
			#define MASTER_64_AVAILABLE __MASTER_PREFER_64
		#elif MASTER_ARCHITECTURE_CPU_WIDTH >= 32
			typedef unsigned long MASTER_maxint;
			#define MASTER_64_AVAILABLE 0
		#else
			typedef unsigned short MASTER_maxint;
			#define MASTER_64_AVAILABLE 0
		#endif /* #! MASTER_ARCHITECTURE_CPU_WIDTH !# */
	#else
		#if !defined(MASTER_IGNORE_C89_STD_64_VARIABLES)
			typedef unsigned long MASTER_maxint;
			#define MASTER_64_AVAILABLE 0
		#else
			#ifdef MASTER_NO_LIMITS_DEPENDENCY
				typedef unsigned short MASTER_maxint;
				#define MASTER_64_AVAILABLE 0
			#else
				#include <limits.h>
				#if defined(ULONG_MAX) && (ULONG_MAX >= 0xFFFFFFFFFFFFFFFFULL)
					typedef unsigned __MASTER_PREFER_LONGLONG MASTER_maxint;
					#define MASTER_64_AVAILABLE __MASTER_PREFER_64
				#elif defined(ULONG_MAX) && (ULONG_MAX >= 0xFFFFFFFFUL)
					typedef unsigned long MASTER_maxint;
					#define MASTER_64_AVAILABLE 0
				#else
					typedef unsigned short MASTER_maxint;
					#define MASTER_64_AVAILABLE 0
				#endif /* #! Long variables check !# */
			#endif /* #! MASTER_NO_LIMITS_DEPENDENCY !# */
		#endif /* #! MASTER_IGNORE_C89_STD_64_VARIABLES !# */
	#endif /* #! C / C++ check !# */
#endif /* #! MASTER_64_AVAILABLE !# */

#if MASTER_64_AVAILABLE == 1
	#define MASTER_UI8_TYPE unsigned long long int
	#define MASTER_SI8_TYPE signed long long int
	
#endif /* #! MASTER_64_AVAILABLE !# */

typedef unsigned char UI1;
typedef unsigned short UI2;
typedef unsigned int UI4;

#ifdef MASTER_UI8_TYPE
	typedef MASTER_UI8_TYPE UI8;
	#define MASTER_UI8_ADD( a, b ) (UI8)(a) + (UI8)(b)
	#define MASTER_UI8_SUB( a, b ) (UI8)(a) - (UI8)(b)
	#define MASTER_UI8_MUL( a, b ) (UI8)(a) * (UI8)(b)
	#define MASTER_UI8_DIV( a, b ) (UI8)(a) / (UI8)(b)
	#define MASTER_UI8_MOD( a, b ) (UI8)(a) % (UI8)(b)
	#define MASTER_UI8_AND( a, b ) (UI8)(a) && (UI8)(b)
	#define MASTER_UI8_OR( a, b ) (UI8)(a) || (UI8)(b)
	#define MASTER_UI8_XOR( a, b ) (!!(UI8)(a)) ^ (!!(UI8)(b))
	#define MASTER_UI8_BAND( a, b ) (UI8)(a) & (UI8)(b)
	#define MASTER_UI8_BOR( a, b ) (UI8)(a) | (UI8)(b)
	#define MASTER_UI8_BXOR( a, b ) (UI8)(a) ^ (UI8)(b)
	#define MASTER_UI8_EQ( a, b ) (UI8)(a) == (UI8)(b)
	#define MASTER_UI8_NQ( a, b ) (UI8)(a) != (UI8)(b)
	#define MASTER_UI8_LS( a, b ) (UI8)(a) < (UI8)(b)
	#define MASTER_UI8_LE( a, b ) (UI8)(a) <= (UI8)(b)
	#define MASTER_UI8_GT( a, b ) (UI8)(a) > (UI8)(b)
	#define MASTER_UI8_GE( a, b ) (UI8)(a) >= (UI8)(b)
	#define MASTER_UI8_LSH( a, b ) (UI8)(a) << (UI8)(b)
	#define MASTER_UI8_RSH( a, b ) (UI8)(a) >> (UI8)(b)
	#define MASTER_UI8_SRA( a, b ) (UI8)(a) << (UI8)(b)
	#define MASTER_UI8_CLSH( a, b ) (UI8)(a) << (UI8)(b)
	#define MASTER_UI8_CLSH( a, b ) (UI8)(a) << (UI8)(b)
	#define MASTER_UI8_NEG( a ) (-(UI8)(a))
	#define MASTER_UI8_NOT( a ) (!(UI8)(a))
	#define MASTER_UI8_BNOT( a ) (~(UI8)(a))
	#define MASTER_UI8_EXI( a ) (!!(UI8)(a))
#else
	typedef UI4 UI8[2];
#endif /* #! UI8 Type !# */

#ifdef MASTER_UI16_TYPE
	typedef MASTER_UI16_TYPE UI16;
#else
	typedef UI4 UI16[4];
#endif /* #! UI16 Type !# */

#ifdef MASTER_UI32_TYPE
	typedef MASTER_UI32_TYPE UI32;
#else
	typedef UI4 UI32[8];
#endif /* #! UI32 Type !# */

#ifdef MASTER_UI64_TYPE
	typedef MASTER_UI64_TYPE UI64;
#else
	typedef UI4 UI64[16];
#endif /* #! UI64 Type !# */

#ifdef MASTER_UI128_TYPE
	typedef MASTER_UI128_TYPE UI128;
#else
	typedef UI4 UI128[32];
#endif /* #! UI128 Type !# */

typedef signed char SI1;
typedef signed short SI2;
typedef signed int SI4;

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

typedef UI4 OUI;
typedef SI4 OSI;
typedef UI4 UT;

#ifdef MASTER_YEAR_IN_BYTE
	#define MASTER_TO_YEARS( year_value ) (UI1)((year_value) - 2038)
	#define MASTER_GET_YEARS( year_value ) (2038 + (year_value))
	typedef SI1 MASTER_year;
#else
	#define MASTER_TO_YEARS( year_value ) (year_value)
	#define MASTER_GET_YEARS( year_value ) (year_value)
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

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199001L
	#define MASTER_CONSTANT( constant ) MASTER_UI4_POSTFIX_C( constant )
#else
	#define MASTER_CONSTANT( constant ) MASTER_UI8_POSTFIX_C( constant )
#endif /* #! C89 Variables !# */

#define MASTER_UI1_BITS (sizeof(UI1) << 3)
#define MASTER_UI2_BITS (sizeof(UI2) << 3)
#define MASTER_UI4_BITS (sizeof(UI4) << 3)
#define MASTER_UI8_BITS (sizeof(UI8) << 3)

#define MASTER_SI1_BITS (sizeof(SI1) << 3)
#define MASTER_SI2_BITS (sizeof(SI2) << 3)
#define MASTER_SI4_BITS (sizeof(SI4) << 3)
#define MASTER_SI8_BITS (sizeof(SI8) << 3)

#define MASTER_SI1_MIN (SI1)(MASTER_CONSTANT(1) << (MASTER_SI1_BITS - 1))
#define MASTER_SI1_MAX (SI1)(MASTER_SI1_MIN - 1)
#define MASTER_SI2_MIN (SI2)(MASTER_CONSTANT(1) << (MASTER_SI2_BITS - 1))
#define MASTER_SI2_MAX (SI2)(MASTER_SI2_MIN - 1)
#define MASTER_SI4_MIN (SI4)(MASTER_CONSTANT(1) << (MASTER_SI4_BITS - 1))
#define MASTER_SI4_MAX (SI4)((UI4)MASTER_SI4_MIN - MASTER_SI4_POSTFIX_C(1))

#define MASTER_UI1_MIN (UI1)0
#define MASTER_UI1_MAX (UI1)(MASTER_UI1_MIN - 1)
#define MASTER_UI2_MIN (UI2)0
#define MASTER_UI2_MAX (UI2)(MASTER_UI2_MIN - 1)
#define MASTER_UI4_MIN (UI4)MASTER_UI4_POSTFIX_C(0)
#define MASTER_UI4_MAX (UI4)(MASTER_UI4_MIN - MASTER_UI4_POSTFIX_C(1))

#define MASTER_OUI_BITS (sizeof(OUI) << 3)
#define MASTER_OSI_BITS (sizeof(OSI) << 3)
#define MASTER_UT_BITS (sizeof(UT) << 3)

#define MASTER_MAXINT_BITS (sizeof(MASTER_maxint) << 3)

#if MASTER_64_AVAILABLE == 1
	#define MASTER_SI8_MAX (SI8)MASTER_SI8_POSTFIX_C(0x7FFFFFFFFFFFFFFF)
	#define MASTER_SI8_MIN (SI8)MASTER_SI8_POSTFIX_C(0x8000000000000000)
	#define MASTER_UI8_MAX (UI8)MASTER_UI8_POSTFIX_C(0xFFFFFFFFFFFFFFFF)
	#define MASTER_UI8_MIN (UI8)MASTER_UI8_POSTFIX_C(0)
#endif /* #! MASTER_64_AVAILABLE !# */

/* #! compiler trash !# */

#define MASTER_UNSUPPORTING 0
#define MASTER_PARTIAL_SUPPORTING 5
#define MASTER_SUPPORTING 10
#define MASTER_SUPPORT_STATE( nivel ) (nivel)

#ifndef MASTER_COMPILER_SETTINGS
	#if !defined(MASTER_NO_COMPILER_SETTINGS_DEPENDENCY) && defined(MASTER_PREFER_USE_COMPILER_SETTING) && 0
		#include <compiler_settings.h>
	#else
		#define MASTER_PREFER_CONST
		#define MASTER_PREFER_INLINE
		#define MASTER_PREFER_STATIC
		#define MASTER_PREFER_EXTERN
		#define MASTER_PREFER_HOT
		#define MASTER_PREFER_COLD
		#define MASTER_PREFER_HIDDEN
		#define MASTER_PREFER_UNUSED
		#define MASTER_PREFER_DEPRECATED
		#define MASTER_COMPILER_SETTINGS 0
	#endif /* #! MASTER_PREFER_USE_COMPILER_SETTING !# */
#endif /* #! MASTER_COMPILER_SETTINGS !# */

#ifdef __cplusplus
	#define MASTER_C_STANDARD 0
#elif defined(__STDC__)
	#if defined(__STDC_VERSION__)
		#if __STDC_VERSION__ >= 202311L
			#define MASTER_C_STANDARD 2023
		#elif __STDC_VERSION__ >= 201710L
			#define MASTER_C_STANDARD 2017
		#elif __STDC_VERSION__ >= 201112L
			#define MASTER_C_STANDARD 2011
		#elif __STDC_VERSION__ >= 199901L
			#define MASTER_C_STANDARD 1999
		#else
			#define MASTER_C_STANDARD 1990
		#endif /* #! __STDC_VERSION__ !# */
	#else
		#define MASTER_C_STANDARD 1990
	#endif /* #! __STDC_VERSION__ !# */
#else
	#define MASTER_C_STANDARD 1978
#endif /* #! __STDC__ !# */

#define MASTER_PREFER_C89_SUPPORTED (MASTER_C_STANDARD >= 1990)
#define MASTER_PREFER_C99_SUPPORTED (MASTER_C_STANDARD >= 1999)
#define MASTER_PREFER_C11_SUPPORTED (MASTER_C_STANDARD >= 2011)
#define MASTER_PREFER_C17_SUPPORTED (MASTER_C_STANDARD >= 2017)
#define MASTER_PREFER_C23_SUPPORTED (MASTER_C_STANDARD >= 2023)

#ifdef __cplusplus
	#define MASTER_PREFER_CPP98_SUPPORTED (__cplusplus >= 199711L)
	#define MASTER_PREFER_CPP11_SUPPORTED (__cplusplus >= 201103L)
	#define MASTER_PREFER_CPP14_SUPPORTED (__cplusplus >= 201402L)
	#define MASTER_PREFER_CPP17_SUPPORTED (__cplusplus >= 201703L)
	#define MASTER_PREFER_CPP20_SUPPORTED (__cplusplus >= 202002L)
	#define MASTER_PREFER_CPP23_SUPPORTED (__cplusplus >= 202302L)
#else
	#define MASTER_PREFER_CPP98_SUPPORTED 0
	#define MASTER_PREFER_CPP11_SUPPORTED 0
	#define MASTER_PREFER_CPP14_SUPPORTED 0
	#define MASTER_PREFER_CPP17_SUPPORTED 0
	#define MASTER_PREFER_CPP20_SUPPORTED 0
	#define MASTER_PREFER_CPP23_SUPPORTED 0
#endif /* #! __cplusplus !# */

/* #! MASTER Errors !# */

#ifndef MASTER_MINIMALIZE_ERROR_CODES
	#define MASTER_ERROR_COMMENT( error_code, base_value ) error_code
#else
	#define MASTER_ERROR_COMMENT( error_code, base_value ) error_code = base_value
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
	#define MASTER_OPTIONAL_ERROR_CODE( error_code ) (error_code)
#else
	typedef void MASTER_optional_error;
	#define MASTER_OPTIONAL_ERROR_CODE( error_code ) 
#endif /* #! MASTER_DONT_USE_OPTIONAL_RET_CODE !# */

#define MASTER_IS_SUCCESS(code) ((code) == MASTER_NO_ERROR)
#define MASTER_IS_FAILURE(code) ((code) != MASTER_NO_ERROR)

/* #! MASTER Assertion !# */

#ifdef MASTER_ENABLE_ASSERTIONS
	#ifndef MASTER_ASSERT
		#error \
		With defined "MASTER_ENABLE_ASSERTIONS" function "MASTER_ASSERT" with arguments (expr) must be defined.
	#endif /* MASTER_FUNCTION_ASSERTION */
#else
	#define MASTER_ASSERT( expression )
#endif /* #! MASTER_ENABLE_ASSERTIONS !# */

/* #! MASTER Memory Functions !# */

#if !defined(MASTER_CUSTOM_MEMORY_FUNCTIONS) && ( \
	defined(MASTER_MALLOC) || defined(MASTER_REALLOC) || defined(MASTER_CALLOC) || defined(MASTER_FREE))
	#warning \
	"Some user memory functions are defined, but macro 'MASTER_CUSTOM_MEMORY_FUNCTIONS' is undefined. Defining 'MASTER_CUSTOM_MEMORY_FUNCTIONS'"
	#define MASTER_CUSTOM_MEMORY_FUNCTIONS
#endif /* #! Predefined Memory Functions Check !# */

#if defined(MASTER_CUSTOM_MEMORY_FUNCTIONS)
#ifndef MASTER_MALLOC
		#error \
		With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_MALLOC" must be defined.
	#endif /* MASTER_MALLOC */
	#ifndef MASTER_REALLOC
		#error \
		With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_REALLOC" must be defined.
	#endif /* MASTER_REALLOC */
	#ifndef MASTER_CALLOC
		#error \
		With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_CALLOC" must be defined.
	#endif /* MASTER_CALLOC */
	#ifndef MASTER_FREE
		#error \
		With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_FREE" must be defined.
	#endif /* MASTER_FREE */
#elif defined(MASTER_NO_STDLIB_DEPENDENCY)
	#ifndef MASTER_MALLOC
		#error \
		With no stdlib dependency function "MASTER_MALLOC" must be defined.
	#endif /* MASTER_MALLOC */
	#ifndef MASTER_REALLOC
		#error \
		With no stdlib dependency function "MASTER_REALLOC" must be defined.
	#endif /* MASTER_REALLOC */
	#ifndef MASTER_CALLOC
		#error \
		With no stdlib dependency function "MASTER_CALLOC" must be defined.
	#endif /* MASTER_CALLOC */
	#ifndef MASTER_FREE
		#error \
		With no stdlib dependency function "MASTER_FREE" must be defined.
	#endif /* MASTER_FREE */
#elif defined(MASTER_MEMORY_SAFE)
	#include <stdlib.h>
	#ifndef MASTER_FUNCTION_ON_FAILURE_MALLOC
		#error \
		With defined "MASTER_MEMORY_SAFE" function "MASTER_FUNCTION_ON_FAILURE_MALLOC" must be defined.
	#endif /* MASTER_FUNCTION_ON_FAILURE_MALLOC */
	#ifndef MASTER_FUNCTION_ON_FAILURE_CALLOC
		#error \
		With defined "MASTER_MEMORY_SAFE" function "MASTER_FUNCTION_ON_FAILURE_CALLOC" must be defined.
	#endif /* MASTER_FUNCTION_ON_FAILURE_CALLOC */
	#ifndef MASTER_FUNCTION_ON_FAILURE_REALLOC
		#error \
		With defined "MASTER_MEMORY_SAFE" function "MASTER_FUNCTION_ON_FAILURE_REALLOC" must be defined.
	#endif /* MASTER_FUNCTION_ON_FAILURE_REALLOC */
	#ifndef MASTER_FUNCTION_ON_NULL_IN_FREE
		#error \
		With defined "MASTER_MEMORY_SAFE" function "MASTER_FUNCTION_ON_NULL_IN_FREE" must be defined.
	#endif /* MASTER_FUNCTION_ON_NULL_IN_FREE */
	#define MASTER_MALLOC(__size) ({ \
		void * __ptr = malloc(__size); \
		if (__ptr == 0 && __size > 0) MASTER_FUNCTION_ON_FAILURE_MALLOC; \
		__ptr; })
	#define MASTER_CALLOC(__count, __size) ({ \
		void * __ptr = calloc(__count, __size); \
		if (__ptr == 0 && __size > 0) MASTER_FUNCTION_ON_FAILURE_CALLOC; \
		__ptr; })
	#define MASTER_REALLOC(__ptr, __size) ({ \
		void * __new_ptr = realloc(__ptr, __size); \
		if (__ptr == 0 && __size > 0) MASTER_FUNCTION_ON_FAILURE_REALLOC; \
		__new_ptr; })
	#define MASTER_FREE(__ptr) do { \
		if (__ptr == 0) MASTER_FUNCTION_ON_NULL_IN_FREE; \
		free(__ptr, __size); } while (0)
#else
	#include <stdlib.h>
	#define MASTER_MALLOC( __size ) malloc(__size)
	#define MASTER_CALLOC( __count, __size ) calloc(__count, __size)
	#define MASTER_REALLOC( __ptr, __size ) realloc(__ptr, __size)
	#define MASTER_FREE( __ptr ) free(__ptr)
#endif /* #! MASTER_MEMORY_SAFE !# */

/* #! MASTER Syntax !# */

#define otherwise else if
#define nul 0

/* #! MASTER Code Manipulations !# */

#define MASTER_REPEAT2( code ) do { code; code; } while (0)
#define MASTER_REPEAT3( code ) do { code; code; code; } while (0)
#define MASTER_REPEAT4( code ) do { code; code; code; code; } while (0)
#define MASTER_XMACRO_CREATE_ENUM( name, value, Unused3_ ) name = value,
#define MASTER_XMACRO_CASE_STRING( name, Unused2_, string ) case name: return string;
#define MASTER_XMACRO_CREATE_NAME_ARRAY( name, Unused2_, Unused3_ ) #name,
#define MASTER_XMACRO_CREATE_VALUE_DICTIONARY( name, value, Unused3_ ) #name " : " #value,
#define MASTER_XMACRO_CREATE_STRING_DICTIONARY( name, Unused2_, string ) #name " : " #string,
#define MASTER_ERRORRISE ;!@;
#define MASTER_NOTHING ;
#define MASTER_TO_BOOL( expression ) (!!(expressopm))

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
	#define __MASTER_CHECK_NUL_RETURN( pointer, retval ) MASTER_RETURN_IF_NUL(pointer, retval)
	#define __MASTER_CHECK_NUL_GOTO( pointer, retval ) MASTER_GOTO_IF_NUL(pointer, retval)
	#define __MASTER_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
#elif !defined(MASTER_DONT_CHECK_NUL_OPERANDS) && defined(MASTER_ASSERT_IF_NUL_OPERAND)
	#define __MASTER_CHECK_NUL_RETURN( pointer, retval ) MASTER_ASSERT_IF_NUL(pointer)
	#define __MASTER_CHECK_NUL_GOTO( pointer, retval ) MASTER_ASSERT_IF_NUL(pointer)
	#define __MASTER_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
#else
	#define __MASTER_CHECK_NUL_RETURN( pointer, retval )
	#define __MASTER_CHECK_NUL_GOTO( pointer, retval )
	#ifdef MASTER_ENABLE_ASSERTIONS
		#define __MASTER_CHECK_NUL_ASSERT( pointer )
	#else
		#define __MASTER_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
	#endif /* #! MASTER_ENABLE_ASSERTIONS !# */
#endif /* #! MASTER_DONT_CHECK_NUL_OPERANDS !# */

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

/* #! MASTER Argument List Macroses !# */

#define MASTER_KAIR_ARG( arg_type, argument ) argument
#define MASTER_KAIR_DECL( arg_type, argument ) arg_type argument
#define MASTER_KAIR_FORMAT0() ( void )
#define MASTER_KAIR_FORMAT1( arg ) ( MASTER_KAIR_ARG arg ) MASTER_KAIR_DECL arg;
#define MASTER_KAIR_FORMAT2( arg1, arg2 ) ( MASTER_KAIR_ARG arg1, MASTER_KAIR_ARG arg2 ) MASTER_KAIR_DECL arg1; MASTER_KAIR_DECL arg2;
#define MASTER_KAIR_FORMAT3( arg1, arg2, arg3 ) ( MASTER_KAIR_ARG arg1, MASTER_KAIR_ARG arg2, MASTER_KAIR_ARG arg3 ) MASTER_KAIR_DECL arg1; MASTER_KAIR_DECL arg2; MASTER_KAIR_DECL arg3;
#define MASTER_KAIR_FORMAT4( arg1, arg2, arg3, arg4 ) ( MASTER_KAIR_ARG arg1, MASTER_KAIR_ARG arg2, MASTER_KAIR_ARG arg3, MASTER_KAIR_ARG arg4 ) MASTER_KAIR_DECL arg1; MASTER_KAIR_DECL arg2; MASTER_KAIR_DECL arg3; MASTER_KAIR_DECL arg4;
#define MASTER_KAIR_FORMAT5( arg1, arg2, arg3, arg4, arg5 ) ( MASTER_KAIR_ARG arg1, MASTER_KAIR_ARG arg2, MASTER_KAIR_ARG arg3, MASTER_KAIR_ARG arg4, MASTER_KAIR_ARG arg5 ) MASTER_KAIR_DECL arg1; MASTER_KAIR_DECL arg2; MASTER_KAIR_DECL arg3; MASTER_KAIR_DECL arg4; MASTER_KAIR_DECL arg5;
#define MASTER_KAIR_FORMAT6( arg1, arg2, arg3, arg4, arg5, arg6 ) ( MASTER_KAIR_ARG arg1, MASTER_KAIR_ARG arg2, MASTER_KAIR_ARG arg3, MASTER_KAIR_ARG arg4, MASTER_KAIR_ARG arg5, MASTER_KAIR_ARG arg6 ) MASTER_KAIR_DECL arg1; MASTER_KAIR_DECL arg2; MASTER_KAIR_DECL arg3; MASTER_KAIR_DECL arg4; MASTER_KAIR_DECL arg5; MASTER_KAIR_DECL arg6;
#define MASTER_KAIR_FORMAT7( arg1, arg2, arg3, arg4, arg5, arg6, arg7 ) ( MASTER_KAIR_ARG arg1, MASTER_KAIR_ARG arg2, MASTER_KAIR_ARG arg3, MASTER_KAIR_ARG arg4, MASTER_KAIR_ARG arg5, MASTER_KAIR_ARG arg6, MASTER_KAIR_ARG arg7 ) MASTER_KAIR_DECL arg1; MASTER_KAIR_DECL arg2; MASTER_KAIR_DECL arg3; MASTER_KAIR_DECL arg4; MASTER_KAIR_DECL arg5; MASTER_KAIR_DECL arg6; MASTER_KAIR_DECL arg7;
#define MASTER_KAIR_FORMAT8( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 ) ( MASTER_KAIR_ARG arg1, MASTER_KAIR_ARG arg2, MASTER_KAIR_ARG arg3, MASTER_KAIR_ARG arg4, MASTER_KAIR_ARG arg5, MASTER_KAIR_ARG arg6, MASTER_KAIR_ARG arg7, MASTER_KAIR_ARG arg8 ) MASTER_KAIR_DECL arg1; MASTER_KAIR_DECL arg2; MASTER_KAIR_DECL arg3; MASTER_KAIR_DECL arg4; MASTER_KAIR_DECL arg5; MASTER_KAIR_DECL arg6; MASTER_KAIR_DECL arg7; MASTER_KAIR_DECL arg8;

#define MASTER_STD_DECL( arg_type, argument ) arg_type argument
#define MASTER_STD_FORMAT0() ( void )
#define MASTER_STD_FORMAT1( arg ) ( MASTER_STD_DECL arg )
#define MASTER_STD_FORMAT2( arg1, arg2 ) ( MASTER_STD_DECL arg1, MASTER_STD_DECL arg2 )
#define MASTER_STD_FORMAT3( arg1, arg2, arg3 ) ( MASTER_STD_DECL arg1, MASTER_STD_DECL arg2, MASTER_STD_DECL arg3 )
#define MASTER_STD_FORMAT4( arg1, arg2, arg3, arg4 ) ( MASTER_STD_DECL arg1, MASTER_STD_DECL arg2, MASTER_STD_DECL arg3, MASTER_STD_DECL arg4 )
#define MASTER_STD_FORMAT5( arg1, arg2, arg3, arg4, arg5 ) ( MASTER_STD_DECL arg1, MASTER_STD_DECL arg2, MASTER_STD_DECL arg3, MASTER_STD_DECL arg4, MASTER_STD_DECL arg5 )
#define MASTER_STD_FORMAT6( arg1, arg2, arg3, arg4, arg5, arg6 ) ( MASTER_STD_DECL arg1, MASTER_STD_DECL arg2, MASTER_STD_DECL arg3, MASTER_STD_DECL arg4, MASTER_STD_DECL arg5, MASTER_STD_DECL arg6 )
#define MASTER_STD_FORMAT7( arg1, arg2, arg3, arg4, arg5, arg6, arg7 ) ( MASTER_STD_DECL arg1, MASTER_STD_DECL arg2, MASTER_STD_DECL arg3, MASTER_STD_DECL arg4, MASTER_STD_DECL arg5, MASTER_STD_DECL arg6, MASTER_STD_DECL arg7 )
#define MASTER_STD_FORMAT8( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 ) ( MASTER_STD_DECL arg1, MASTER_STD_DECL arg2, MASTER_STD_DECL arg3, MASTER_STD_DECL arg4, MASTER_STD_DECL arg5, MASTER_STD_DECL arg6, MASTER_STD_DECL arg7, MASTER_STD_DECL arg8 )

#ifdef __cplusplus
	#define MASTER_ARGLIST_FORMAT0() MASTER_STD_FORMAT0()
	#define MASTER_ARGLIST_FORMAT1( arg ) MASTER_STD_FORMAT1(arg)
	#define MASTER_ARGLIST_FORMAT2( arg1, arg2 ) MASTER_STD_FORMAT2( arg1, arg2 )
	#define MASTER_ARGLIST_FORMAT3( arg1, arg2, arg3 ) MASTER_STD_FORMAT3( arg1, arg2, arg3 )
	#define MASTER_ARGLIST_FORMAT4( arg1, arg2, arg3, arg4 ) MASTER_STD_FORMAT4( arg1, arg2, arg3, arg4 )
	#define MASTER_ARGLIST_FORMAT5( arg1, arg2, arg3, arg4, arg5 ) MASTER_STD_FORMAT5( arg1, arg2, arg3, arg4, arg5 )
	#define MASTER_ARGLIST_FORMAT6( arg1, arg2, arg3, arg4, arg5, arg6 ) MASTER_STD_FORMAT6( arg1, arg2, arg3, arg4, arg5, arg6 )
	#define MASTER_ARGLIST_FORMAT7( arg1, arg2, arg3, arg4, arg5, arg6, arg7 ) MASTER_STD_FORMAT7( arg1, arg2, arg3, arg4, arg5, arg6, arg7 )
	#define MASTER_ARGLIST_FORMAT8( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 ) MASTER_STD_FORMAT8( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 )
#else
	#define MASTER_ARGLIST_FORMAT0() MASTER_KAIR_FORMAT0()
	#define MASTER_ARGLIST_FORMAT1( arg ) MASTER_KAIR_FORMAT1(arg)
	#define MASTER_ARGLIST_FORMAT2( arg1, arg2 ) MASTER_KAIR_FORMAT2( arg1, arg2 )
	#define MASTER_ARGLIST_FORMAT3( arg1, arg2, arg3 ) MASTER_KAIR_FORMAT3( arg1, arg2, arg3 )
	#define MASTER_ARGLIST_FORMAT4( arg1, arg2, arg3, arg4 ) MASTER_KAIR_FORMAT4( arg1, arg2, arg3, arg4 )
	#define MASTER_ARGLIST_FORMAT5( arg1, arg2, arg3, arg4, arg5 ) MASTER_KAIR_FORMAT5( arg1, arg2, arg3, arg4, arg5 )
	#define MASTER_ARGLIST_FORMAT6( arg1, arg2, arg3, arg4, arg5, arg6 ) MASTER_KAIR_FORMAT6( arg1, arg2, arg3, arg4, arg5, arg6 )
	#define MASTER_ARGLIST_FORMAT7( arg1, arg2, arg3, arg4, arg5, arg6, arg7 ) MASTER_KAIR_FORMAT7( arg1, arg2, arg3, arg4, arg5, arg6, arg7 )
	#define MASTER_ARGLIST_FORMAT8( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 ) MASTER_KAIR_FORMAT8( arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 )
#endif /* #! Detect Argument List Compability !# */

#define MASTER_DEFINE_FUNCTION0( flags, description, function_name, return_value_and_extras ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT0()
#define MASTER_DEFINE_FUNCTION1( flags, description, function_name, return_value_and_extras, arg ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT1(arg)
#define MASTER_DEFINE_FUNCTION2( flags, description, function_name, return_value_and_extras, arg1, arg2 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT2(arg1, arg2)
#define MASTER_DEFINE_FUNCTION3( flags, description, function_name, return_value_and_extras, arg1, arg2, arg3 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT3(arg1, arg2, arg3)
#define MASTER_DEFINE_FUNCTION4( flags, description, function_name, return_value_and_extras, arg1, arg2, arg3, arg4 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT4(arg1, arg2, arg3, arg4)
#define MASTER_DEFINE_FUNCTION5( flags, description, function_name, return_value_and_extras, arg1, arg2, arg3, arg4, arg5 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT5(arg1, arg2, arg3, arg4, arg5)
#define MASTER_DEFINE_FUNCTION6( flags, description, function_name, return_value_and_extras, arg1, arg2, arg3, arg4, arg5, arg6 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT6(arg1, arg2, arg3, arg4, arg5, arg6)
#define MASTER_DEFINE_FUNCTION7( flags, description, function_name, return_value_and_extras, arg1, arg2, arg3, arg4, arg5, arg6, arg7 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT7(arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define MASTER_DEFINE_FUNCTION8( flags, description, function_name, return_value_and_extras, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 ) return_value_and_extras function_name MASTER_ARGLIST_FORMAT8(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

#define MASTER_EMPTY_DESCRIPTION /* #! No description is provided !# */
#define MASTER_NO_FLAGS

/* #! MASTER Undefined Behaviour Runtime Checker && MASTER Some Operators !# */

#ifdef MASTER_RUNTIME_UB_CHECKS
	#define MASTER_MACRO_OPERATORS_UB_CALLBACK_DEFINE( bytes, bits_max ) \
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
	#define MASTER_RSH1( value, bits ) MASTER_RSH1_Callback(value, bits, MASTER_FILE, MASTER_LINE)
	#define MASTER_RSH2( value, bits ) MASTER_RSH2_Callback(value, bits, MASTER_FILE, MASTER_LINE)
	#define MASTER_RSH4( value, bits ) MASTER_RSH4_Callback(value, bits, MASTER_FILE, MASTER_LINE)
	#define MASTER_LSH1( value, bits ) MASTER_LSH1_Callback(value, bits, MASTER_FILE, MASTER_LINE)
	#define MASTER_LSH2( value, bits ) MASTER_LSH2_Callback(value, bits, MASTER_FILE, MASTER_LINE)
	#define MASTER_LSH4( value, bits ) MASTER_LSH4_Callback(value, bits, MASTER_FILE, MASTER_LINE)
#else
	#define MASTER_RSH1( value, bits ) (UI1)(((UI1)(value)) >> (bits))
	#define MASTER_RSH2( value, bits ) (UI2)(((UI2)(value)) >> (bits))
	#define MASTER_RSH4( value, bits ) (UI4)(((UI4)(value)) >> (bits))
	#define MASTER_LSH1( value, bits ) (UI1)(((UI1)(value)) << (bits))
	#define MASTER_LSH2( value, bits ) (UI2)(((UI2)(value)) << (bits))
	#define MASTER_LSH4( value, bits ) (UI4)(((UI4)(value)) << (bits))
#endif /* #! MASTER_RUNTIME_UB_CHECKS !# */

/* #! MASTER Align !# */

#define MASTER_ALIGNPOW2( value, bits ) ((((value) >> (bits)) + !!((value) & ((1 << (bits)) - 1))) << (bits))
#define MASTER_ALIGN2( value ) MASTER_ALIGNPOW2( value, 1 )
#define MASTER_ALIGN4( value ) MASTER_ALIGNPOW2( value, 2 )
#define MASTER_ALIGN8( value ) MASTER_ALIGNPOW2( value, 3 )
#define MASTER_ALIGN16( value ) MASTER_ALIGNPOW2( value, 4 )
#define MASTER_ALIGN( value, bits ) ((((value) / (bits)) + !!((value) % (bits))) * (bits))

/* #! MASTER String !# */

#ifndef MASTER_USE_LONG_STRING
	typedef char MASTER_char;
	#define MASTER_CHAR( character ) character
	#define MASTER_STRING( string ) string
#else
	typedef UI4 MASTER_char;
	#define MASTER_CHAR( character ) L##character
	#define MASTER_STRING( string ) L##string
#endif /* #! MASTER_USE_LONG_STRING !# */

#define MASTER_STRINGIFY( string ) #string
#define MASTER_CONCAT( string1, string2 ) string1##string2
#define MASTER_CONCAT3( string1, string2, string3 ) string1##string2##string3
#define MASTER_CONCAT4( string1, string2, string3, string4 ) string1##string2##string3##string4
#define MASTER_CONCAT_FALL( string1, string2 ) MASTER_CONCAT( string1, string2 )
#define MASTER_CONCAT3_FALL( string1, string2, string3 ) MASTER_CONCAT3( string1, string2, string3 )
#define MASTER_CONCAT4_FALL( string1, string2, string3, string4 ) MASTER_CONCAT4( string1, string2, string3, string4 )

/* #! MASTER Simple Macroses !# */

#define MASTER_MEMBER_SIZE( type, member ) sizeof(((const type * const)0)->member)
#define MASTER_MAX( value1, value2 ) (((value1) > (value2)) ? (value1) : (value2))
#define MASTER_MAX3( value1, value2, value3 ) MASTER_MAX(value1, MASTER_MAX(value2, value3))
#define MASTER_MAX4( value1, value2, value3, value4 ) MASTER_MAX(MASTER_MAX(value1, value2), MASTER_MAX(value3, value4))
#define MASTER_IMAX( value1, value2 ) (value1) = MASTER_MAX(value1, value2)
#define MASTER_IMAX3( value1, value2, value3 ) (value1) = MASTER_MAX3(value1, value2, value3)
#define MASTER_IMAX4( value1, value2, value3, value4 ) (value1) = MASTER_MAX4(value1, value2, value3, value4)
#define MASTER_MIN( value1, value2 ) (((value1) < (value2)) ? (value1) : (value2))
#define MASTER_MIN3( value1, value2, value3 ) MASTER_MIN(value1, MASTER_MIN(value2, value3))
#define MASTER_MIN4( value1, value2, value3, value4 ) MASTER_MIN(MASTER_MIN(value1, value2), MASTER_MIN(value3, value4))
#define MASTER_IMIN( value1, value2 ) (value1) = MASTER_MIN(value1, value2)
#define MASTER_IMIN3( value1, value2, value3 ) (value1) = MASTER_MIN3(value1, value2, value3)
#define MASTER_IMIN4( value1, value2, value3, value4 ) (value1) = MASTER_MIN4(value1, value2, value3, value4)
#define MASTER_CLAMP( value, min_value, max_value ) MASTER_MAX(min_value, MASTER_MIN(max_value, value))
#define MASTER_ABS( value ) (((value) < 0) ? (-(value)) : (value))
#define MASTER_SIGN( value ) (((value) < 0) ? (-1) : ((value) > 0) ? (+1) : (0))
#define MASTER_SQUARE( value ) ((value) * (value))
#define MASTER_2BYTES_TO_INT( a, b ) (((a) << 8) | (b))
#define MASTER_4BYTES_TO_INT( a, b, c, d ) (((a) << 24) | ((b) << 16) | ((c) << 8) | (d))

#define MASTER_DIV_CEIL2( value ) (((value) + 1) >> 1)
#define MASTER_DIV_CEIL4( value ) (((value) + 3) >> 2)
#define MASTER_DIV_CEIL8( value ) (((value) + 7) >> 3)
#define MASTER_DIV_CEIL16( value ) (((value) + 15) >> 4)
#define MASTER_DIV_CEIL_POW2( value, bits ) (((value) + ((1 << bits) - 1)) >> (bits))

#define MASTER_HOWMANY2( value ) MASTER_DIV_CEIL2( value )
#define MASTER_HOWMANY4( value ) MASTER_DIV_CEIL4( value )
#define MASTER_HOWMANY8( value ) MASTER_DIV_CEIL8( value )
#define MASTER_HOWMANY16( value ) MASTER_DIV_CEIL16( value )
#define MASTER_HOWMANY_POW2( value, bits ) MASTER_DIV_CEIL_POW2( value, bits )
#define MASTER_HOWMANY( value, bits ) (((value) + ((bits) - 1)) / (bits))
#define MASTER_BITS_TO_BYTES( value ) MASTER_DIV_CEIL8( value )

#define MASTER_PADDINGLEN( value, modulo, residue ) (((residue) - ((value) + 1) % (modulo) + (modulo)) % (modulo))
#define MASTER_PADDEDLEN( value, modulo, residue ) ((value) + 1 + MASTER_PADDINGLEN(value, modulo, residue))
#define MASTER_PADDINGLEN_POW2( value, log2modulo, residue ) ((((residue) - ((value) + 1)) & ((1 << (log2modulo)) - 1)))
#define MASTER_PADDEDLEN_POW2( value, log2modulo, residue ) ((value) + 1 + MASTER_PADDINGLEN_POW2(value, log2modulo, residue))

/* #! MASTER Some Functions !# */

#ifndef MASTER_NO_STRING_DEPENDENCY
	#include <string.h>
	
	#define MASTER_CPRCAT strcat
	#define MASTER_CPRCHR strchr
	#define MASTER_CPRCMP strcmp
	#define MASTER_CPRCOLL strcoll
	#define MASTER_CPRCPY strcpy
	#define MASTER_CPRCSPN strcspn
	#define MASTER_CPRERROR strerror
	#define MASTER_CPRLEN strlen
	#define MASTER_CPRNCAT strncat
	#define MASTER_CPRNCMP strncmp
	#define MASTER_CPRNCPY strncpy
	#define MASTER_CPRPBRK strpbrk
	#define MASTER_CPRRCHR strrchr
	#define MASTER_CPRSPN strspn
	#define MASTER_CPRCPR strstr
	#define MASTER_CPRTOK strtok
	#define MASTER_CPRXFRM strxfrm
	#define MASTER_MEMCHR memchr
	#define MASTER_MEMCMP memcmp
	#define MASTER_MEMCPY memcpy
	#define MASTER_MEMMOV memmove
	#define MASTER_MEMSET memset
#endif /* #! MASTER_NO_STRING_DEPENDENCY !# */

/* #! MASTER Power Manipulations !# */

#define MASTER_ISPOW2( value ) (!((value) & ((value) - 1)))
#define MASTER_ISPOW4( value ) (MASTER_ISPOW2(value) && ((value) & 0x55555555))
#define MASTER_ISPOW8( value ) (MASTER_ISPOW2(value) && ((value) & 0x49249249))
#define MASTER_ISPOW16( value ) (MASTER_ISPOW2(value) && ((value) & 0x11111111))

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_SMEAR1 /* ! */,
	MASTER_PREFER_INLINE UI1,
	( UI1, value )
) {
	value |= value >> 4;
	value |= value >> 2;
	value |= value >> 1;
	return value;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_SMEAR2 /* ! */,
	MASTER_PREFER_INLINE UI2,
	( UI2, value )
) {
	value |= value >> 8;
	value |= value >> 4;
	value |= value >> 2;
	value |= value >> 1;
	return value;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_SMEAR4 /* ! */,
	MASTER_PREFER_INLINE UI4,
	( UI4, value )
) {
	value |= value >> 16;
	value |= value >> 8;
	value |= value >> 4;
	value |= value >> 2;
	value |= value >> 1;
	return value;
}

#if MASTER_64_AVAILABLE == 1
MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_SMEAR8 /* ! */,
	MASTER_PREFER_INLINE UI8,
	( UI8, value )
) {
	value |= value >> 32;
	value |= value >> 16;
	value |= value >> 8;
	value |= value >> 4;
	value |= value >> 2;
	value |= value >> 1;
	return value;
}

#endif /* #! MASTER_64_AVAILABLE !# */

#define __MASTER_BITLEN_MACROS_PROCESS( value, bitcount, bits, suff ) do { \
		if ((value) >= (1##suff << bits)) { \
			(bitcount) += bits; \
			(value) >>= bits; \
		} \
	} while (0)

MASTER_PREFER_INLINE UI1
MASTER_BITLEN1( value )
	UI1 value;
{
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, U);
	if (value > 0) bitcount += 1;
	return bitcount;
}

MASTER_PREFER_INLINE UI2
MASTER_BITLEN2( value ) 
	UI2 value;
{
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 8, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, U);
	if (value > 0) bitcount += 1;
	return bitcount;
}

MASTER_PREFER_INLINE UI4
MASTER_BITLEN4( value )
	UI4 value;
{
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 16, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 8, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, U);
	if (value > 0) bitcount += 1;
	return bitcount;
}

#if MASTER_64_AVAILABLE == 1
MASTER_PREFER_INLINE UI8
MASTER_BITLEN8( value )
	UI8 value;
{
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 32, ULL);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 16, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 8, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, U);
	if (value > 0) bitcount += 1;
	return bitcount;
}

#endif /* #! MASTER_64_AVAILABLE !# */

#define MASTER_POW2FLOOR1( value ) ((MASTER_SMEAR1(value) >> 1) + 1)
#define MASTER_POW2FLOOR2( value ) ((MASTER_SMEAR2(value) >> 1) + 1)
#define MASTER_POW2FLOOR4( value ) ((MASTER_SMEAR4(value) >> 1) + 1)
#define MASTER_POW2CEIL1( value ) (MASTER_SMEAR1(value - 1) + 1)
#define MASTER_POW2CEIL2( value ) (MASTER_SMEAR2(value - 1) + 1)
#define MASTER_POW2CEIL4( value ) (MASTER_SMEAR4(value - 1) + 1)
#define MASTER_LOG2FLOOR1( value ) (MASTER_BITLEN1(value) - 1)
#define MASTER_LOG2FLOOR2( value ) (MASTER_BITLEN2(value) - 1)
#define MASTER_LOG2FLOOR4( value ) (MASTER_BITLEN4(value) - 1)
#define MASTER_LOG2CEIL1( value ) (MASTER_BITLEN1(value) - MASTER_ISPOW2(value))
#define MASTER_LOG2CEIL2( value ) (MASTER_BITLEN2(value) - MASTER_ISPOW2(value))
#define MASTER_LOG2CEIL4( value ) (MASTER_BITLEN4(value) - MASTER_ISPOW2(value))

#if MASTER_64_AVAILABLE == 1
	#define MASTER_POW2FLOOR8( value ) ((MASTER_SMEAR8(value) >> 1) + 1)
	#define MASTER_POW2CEIL8( value ) (MASTER_SMEAR8(value - 1) + 1)
	#define MASTER_LOG2FLOOR8( value ) (MASTER_BITLEN8(value) - 1)
	#define MASTER_LOG2CEIL8( value ) (MASTER_BITLEN8(value) - MASTER_ISPOW2(value))
#endif /* #! MASTER_64_AVAILABLE !# */

#ifdef MASTER_ROUND_FUNCS_INSTEAD_OF_MACROS
	#define MASTER_POW2ROUND1( value ) (((value) < (MASTER_POW2FLOOR1(value) | (MASTER_POW2FLOOR1(value) >> 1))) ? (MASTER_POW2FLOOR1(value)) : (MASTER_POW2CEIL1(value)))
	#define MASTER_POW2ROUND2( value ) (((value) < (MASTER_POW2FLOOR2(value) | (MASTER_POW2FLOOR2(value) >> 1))) ? (MASTER_POW2FLOOR2(value)) : (MASTER_POW2CEIL2(value)))
	#define MASTER_POW2ROUND4( value ) (((value) < (MASTER_POW2FLOOR4(value) | (MASTER_POW2FLOOR4(value) >> 1))) ? (MASTER_POW2FLOOR4(value)) : (MASTER_POW2CEIL4(value)))
	#define MASTER_LOG2ROUND1( value ) (((value) < (MASTER_POW2FLOOR1(value) | (MASTER_POW2FLOOR1(value) >> 1))) ? (MASTER_LOG2FLOOR1(value)) : (MASTER_LOG2CEIL1(value)))
	#define MASTER_LOG2ROUND2( value ) (((value) < (MASTER_POW2FLOOR2(value) | (MASTER_POW2FLOOR2(value) >> 1))) ? (MASTER_LOG2FLOOR2(value)) : (MASTER_LOG2CEIL2(value)))
	#define MASTER_LOG2ROUND4( value ) (((value) < (MASTER_POW2FLOOR4(value) | (MASTER_POW2FLOOR4(value) >> 1))) ? (MASTER_LOG2FLOOR4(value)) : (MASTER_LOG2CEIL4(value)))
	#if MASTER_64_AVAILABLE == 1
		#define MASTER_POW2ROUND8( value ) (((value) < (MASTER_POW2FLOOR8(value) | (MASTER_POW2FLOOR8(value) >> 1))) ? (MASTER_POW2FLOOR8(value)) : (MASTER_POW2CEIL8(value)))
		#define MASTER_LOG2ROUND8( value ) (((value) < (MASTER_POW2FLOOR8(value) | (MASTER_POW2FLOOR8(value) >> 1))) ? (MASTER_LOG2FLOOR8(value)) : (MASTER_LOG2CEIL8(value)))
	#endif /* #! MASTER_64_AVAILABLE !# */
#else
	#define __MASTER_POW2ROUNDX_GENERATE_MACRO( suff ) \
		MASTER_PREFER_INLINE UI##suff \
		MASTER_POW2ROUND##suff( value ) \
			UI##suff value; \
		{ \
			UI##suff floored = MASTER_POW2FLOOR##suff(value); \
			floored |= floored >> 1; \
			if (value < floored) return floored & (floored << 1); \
			return MASTER_POW2CEIL##suff(value); \
		}
	#define __MASTER_LOG2ROUNDX_GENERATE_MACRO( suff, numsuff ) \
		MASTER_PREFER_INLINE UI##suff \
		MASTER_LOG2ROUND##suff( value ) \
			UI##suff value; \
		{ \
			const UI1 bits = MASTER_LOG2FLOOR##suff(value); \
			UI##suff floored = 1##numsuff << bits; \
			if (value <= 1) return value - 1; \
			floored |= floored >> 1; \
			return bits + (value >= floored); \
		}
		__MASTER_POW2ROUNDX_GENERATE_MACRO( 1 )
		__MASTER_POW2ROUNDX_GENERATE_MACRO( 2 )
		__MASTER_POW2ROUNDX_GENERATE_MACRO( 4 )
		__MASTER_LOG2ROUNDX_GENERATE_MACRO( 1, U )
		__MASTER_LOG2ROUNDX_GENERATE_MACRO( 2, U )
		__MASTER_LOG2ROUNDX_GENERATE_MACRO( 4, U )
		#if MASTER_64_AVAILABLE == 1
			__MASTER_POW2ROUNDX_GENERATE_MACRO( 8 )
			__MASTER_LOG2ROUNDX_GENERATE_MACRO( 8, L )
		#endif /* #! MASTER_64_AVAILABLE !# */
	#undef __MASTER_POW2ROUNDX_GENERATE_MACRO
	#undef __MASTER_LOG2ROUNDX_GENERATE_MACRO
#endif /* #! MASTER_ROUND_FUNCS_INSTEAD_OF_MACROS !# */

MASTER_PREFER_INLINE UI1
MASTER_LOG2MATHROUND1( value )
	UI1 value;
{
	if (value >= 0xB6) return 8;
	if (value >= 0x5B) return 7;
	if (value >= 0x2E) return 6;
	if (value >= 0x17) return 5;
	if (value >= 0xC) return 4;
	if (value >= 0x6) return 3;
	if (value >= 0x3) return 2;
	return value - 1;
}

MASTER_PREFER_INLINE UI1
MASTER_LOG2MATHROUND2( value )
	UI2 value;
{
	if (value >= 0xB505) return 16;
	if (value >= 0x5A83) return 15;
	if (value >= 0x2D42) return 14;
	if (value >= 0x16A1) return 13;
	if (value >= 0xB51) return 12;
	if (value >= 0x5A9) return 11;
	if (value >= 0x2D5) return 10;
	if (value >= 0x16B) return 9;
	return MASTER_LOG2MATHROUND1(value);
}

MASTER_PREFER_INLINE UI1
MASTER_LOG2MATHROUND4( value )
	UI4 value;
{
	if (value >= 0xB504F334) return 32;
	if (value >= 0x5A82799A) return 31;
	if (value >= 0x2D413CCD) return 30;
	if (value >= 0x16A09E67) return 29;
	if (value >= 0xB504F34) return 28;
	if (value >= 0x5A8279A) return 27;
	if (value >= 0x2D413CD) return 26;
	if (value >= 0x16A09E7) return 25;
	if (value >= 0xB504F4) return 24;
	if (value >= 0x5A827A) return 23;
	if (value >= 0x2D413D) return 22;
	if (value >= 0x16A09F) return 21;
	if (value >= 0xB5050) return 20;
	if (value >= 0x5A828) return 19;
	if (value >= 0x2D414) return 18;
	if (value >= 0x16A0A) return 17;
	return MASTER_LOG2MATHROUND2(value);
}

#if MASTER_64_AVAILABLE == 1
MASTER_PREFER_INLINE UI1
MASTER_LOG2MATHROUND8( value )
	UI8 value;
{
	if (value >= 0xB504F333F9DDE401) return 64;
	if (value >= 0x5A827999FCEEF201) return 63;
	if (value >= 0x2D413CCCFE777901) return 62;
	if (value >= 0x16A09E667F3BBC81) return 61;
	if (value >= 0xB504F333F9DDE41) return 60;
	if (value >= 0x5A827999FCEEF21) return 59;
	if (value >= 0x2D413CCCFE77791) return 58;
	if (value >= 0x16A09E667F3BBC9) return 57;
	if (value >= 0xB504F333F9DDE5) return 56;
	if (value >= 0x5A827999FCEEF3) return 55;
	if (value >= 0x2D413CCCFE777A) return 54;
	if (value >= 0x16A09E667F3BBD) return 53;
	if (value >= 0xB504F333F9DDF) return 52;
	if (value >= 0x5A827999FCEF0) return 51;
	if (value >= 0x2D413CCCFE778) return 50;
	if (value >= 0x16A09E667F3BC) return 49;
	if (value >= 0xB504F333F9DE) return 48;
	if (value >= 0x5A827999FCEF) return 47;
	if (value >= 0x2D413CCCFE78) return 46;
	if (value >= 0x16A09E667F3C) return 45;
	if (value >= 0xB504F333F9E) return 44;
	if (value >= 0x5A827999FCF) return 43;
	if (value >= 0x2D413CCCFE8) return 42;
	if (value >= 0x16A09E667F4) return 41;
	if (value >= 0xB504F333FA) return 40;
	if (value >= 0x5A827999FD) return 39;
	if (value >= 0x2D413CCCFF) return 38;
	if (value >= 0x16A09E6680) return 37;
	if (value >= 0xB504F3340) return 36;
	if (value >= 0x5A82799A0) return 35;
	if (value >= 0x2D413CCD0) return 34;
	if (value >= 0x16A09E668) return 33;
	return MASTER_LOG2MATHROUND4(value);
}

#endif /* #! MASTER_64_AVAILABLE !# */

#define MASTER_POW2MATHROUND1( value ) (1 << MASTER_LOG2MATHROUND1(value))
#define MASTER_POW2MATHROUND2( value ) (1 << MASTER_LOG2MATHROUND2(value))
#define MASTER_POW2MATHROUND4( value ) (1 << MASTER_LOG2MATHROUND4(value))
#if MASTER_64_AVAILABLE == 1
	#define MASTER_POW2MATHROUND8( value ) (1L << MASTER_LOG2MATHROUND8(value))
#endif /* #! MASTER_64_AVAILABLE !# */

#define MASTER_ADD_OVERFLOW_UI1( a, b, carry ) carry = ((a >= ((UI1)-1) - b) ? (1) : (0))
#define MASTER_ADD_OVERFLOW_UI2( a, b, carry ) carry = ((a >= ((UI2)-1) - b) ? (1) : (0))
#define MASTER_ADD_OVERFLOW_UI4( a, b, carry ) carry = ((a >= ((UI4)-1) - b) ? (1) : (0))

/* #! MASTER Shifts !# */

#define MASTER_RLLN( a, k, n ) (((a) << (k)) | ((a) >> ((n) - (k))))
#define MASTER_RLRN( a, k, n ) (((a) >> (k)) | ((a) << ((n) - (k))))
#define MASTER_RLL8( a, k ) MASTER_RLLN(a, k, 8)
#define MASTER_RLL16( a, k ) MASTER_RLLN(a, k, 16)
#define MASTER_RLL32( a, k ) MASTER_RLLN(a, k, 32)
#define MASTER_RLL64( a, k ) MASTER_RLLN(a, k, 64)
#define MASTER_RLR8( a, k ) MASTER_RLRN(a, k, 8)
#define MASTER_RLR16( a, k ) MASTER_RLRN(a, k, 16)
#define MASTER_RLR32( a, k ) MASTER_RLRN(a, k, 32)
#define MASTER_RLR64( a, k ) MASTER_RLRN(a, k, 64)
#define MASTER_SRAGEN( x, k ) (((x) < 0) ? (~((~(x)) >> (k))) : ((x) >> (k)))
#define MASTER_SRA1( x, k ) (((x) >> (k)) | (((x) & 0x80) ? (~(0xFF  >> (k))) : 0))
#define MASTER_SRA2( x, k ) (((x) >> (k)) | (((x) & 0x8000) ? (~(0xFFFF  >> (k))) : 0))
#define MASTER_SRA4( x, k ) (((x) >> (k)) | (((x) & 0x80000000) ? (~(0xFFFFFFFF  >> (k))) : 0))
#define MASTER_SRA8( x, k ) (((x) >> (k)) | (((x) & 0x8000000000000000) ? (~(0xFFFFFFFFFFFFFFFF  >> (k))) : 0))

/* #! MASTER Endian !# */

#define MASTER_UNKNOWN_ENDIAN 0
#define MASTER_LITTLE_ENDIAN 1
#define MASTER_BIG_ENDIAN 2
#define MASTER_PDP_ENDIAN 4

#if (defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || (defined(__LITTLE_ENDIAN__) && __LITTLE_ENDIAN__ == 1)
	#define MASTER_ENDIANNESS MASTER_LITTLE_ENDIAN
#elif (defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || (defined(__BIG_ENDIAN__) && __BIG_ENDIAN__ == 1)
	#define MASTER_ENDIANNESS MASTER_BIG_ENDIAN
#elif (defined(__BYTE_ORDER__) && defined(__ORDER_PDP_ENDIAN__) && __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__) || (defined(__PDP_ENDIAN__) && __PDP_ENDIAN__ == 1)
	#define MASTER_ENDIANNESS MASTER_PDP_ENDIAN
#else
	#ifndef MASTER_NO_ARCHITECTURE_DETECT_DEPENDENCY
		#include <architecture_detect.h>
		#if MASTER_ARCHITECTURE_ENDIAN == MASTER_LITTLE_ENDIAN
			#define MASTER_ENDIANNESS MASTER_LITTLE_ENDIAN
		#elif MASTER_ARCHITECTURE_ENDIAN == MASTER_BIG_ENDIAN
			#define MASTER_ENDIANNESS MASTER_BIG_ENDIAN
		#elif MASTER_ARCHITECTURE_ENDIAN == MASTER_PDP_ENDIAN
			#define MASTER_ENDIANNESS MASTER_PDP_ENDIAN
		#endif * #! Architecture Endian !# */
	#endif /* #! MASTER_NO_ARCHITECTURE_DETECT_DEPENDENCY !# */
	#ifndef MASTER_ENDIANNESS
		UI1 MASTER_ENDIANNESS = 0;
		void
		MASTER_getEndianness( void ) {
			const UI4 value = 0x01020304;
			const UI1 * bytes = (const UI1 *)&value;

			if (bytes[0] == 0x04) MASTER_ENDIANNESS = MASTER_LITTLE_ENDIAN;
			otherwise (bytes[0] == 0x01)
				MASTER_ENDIANNESS = MASTER_BIG_ENDIAN;
			otherwise (bytes[0] == 0x03)
				MASTER_ENDIANNESS = MASTER_PDP_ENDIAN;
			else MASTER_ENDIANNESS = MASTER_UNKNOWN_ENDIAN;
		}
		#warning \
		"Unknown endianness. Using generic. Please, use function MASTER_getEndianness() in begin in main."
		#define MASTER_ENDIANNESS MASTER_getEndianness()
		#define MASTER_UNKNOWN_ENDIANNESS
	
	#endif /* #! MASTER_ENDIANNESS !# */
	
#endif /* #! ENDIANNESS !# */

#define MASTER_BSWAP16( value ) (((value) >> 8) | ((value) << 8))
#define MASTER_BSWAP32( value ) ( \
	(((value) >> 24) & 0x000000FF) | \
	(((value) >>  8) & 0x0000FF00) | \
	(((value) <<  8) & 0x00FF0000) | \
	(((value) << 24) & 0xFF000000))
#define MASTER_BSWAP64( value ) ( \
	(((value) >> 56) & 0x00000000000000FF) | \
	(((value) >> 40) & 0x000000000000FF00) | \
	(((value) >> 24) & 0x0000000000FF0000) | \
	(((value) >>  8) & 0x00000000FF000000) | \
	(((value) <<  8) & 0x000000FF00000000) | \
	(((value) << 24) & 0x0000FF0000000000) | \
	(((value) << 40) & 0x00FF000000000000) | \
	(((value) << 56) & 0xFF00000000000000))
#define MASTER_BSWAP_GENERIC( value, size ) ( \
	(((size) == 1) ? (value) : ((size) == 2) ? (MASTER_BSWAP16(value)) : ((size) == 4) ? (MASTER_BSWAP32(value)) : (MASTER_BSWAP64(value))))

#define MASTER_IS_LE() (MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN)
#define MASTER_IS_BE() (MASTER_ENDIANNESS == MASTER_BIG_ENDIAN)
#define MASTER_IS_PDP() (MASTER_ENDIANNESS == MASTER_PDP_ENDIAN)
#ifdef MASTER_UNKNOWN_ENDIANNESS
	#define MASTER_IS_GENE() (1)
#else
	#define MASTER_IS_GENE() (0)
#endif /* #! MASTER_UNKNOWN_ENDIANNESS !# */

#define MASTER_L2BE( value ) MASTER_BSWAP_GENERIC(value, sizeof(value))
#define MASTER_L2BE16( value ) MASTER_BSWAP16(value)
#define MASTER_L2BE32( value ) MASTER_BSWAP32(value)
#define MASTER_L2BE64( value ) MASTER_BSWAP64(value)
#define MASTER_L2PDPE16( value ) MASTER_BSWAP16(value)
#define MASTER_L2PDPE32( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_L2PDP64( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))

#define MASTER_B2LE( value ) MASTER_BSWAP_GENERIC(value, sizeof(value))
#define MASTER_B2LE16( value ) MASTER_BSWAP16(value)
#define MASTER_B2LE32( value ) MASTER_BSWAP32(value)
#define MASTER_B2LE64( value ) MASTER_BSWAP64(value)
#define MASTER_B2PDPE16( value ) (value)
#define MASTER_B2PDPE32( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_B2PDPE64( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))

#define MASTER_PDP2LE16( value ) MASTER_BSWAP16(value)
#define MASTER_PDP2LE32( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_PDP2LE64( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_PDP2BE16( value ) (value)
#define MASTER_PDP2BE32( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_PDP2BE64( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))

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

#ifndef MASTER_UNKNOWN_ENDIANNESS
	#if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
		#define MASTER_TOLE( value ) (value)
		#define MASTER_TOLE16( value ) (value)
		#define MASTER_TOLE32( value ) (value)
		#define MASTER_TOLE64( value ) (value)
		
		#define MASTER_TOBE( value ) MASTER_L2BE(value)
		#define MASTER_TOBE16( value ) MASTER_L2BE16(value)
		#define MASTER_TOBE32( value ) MASTER_L2BE32(value)
		#define MASTER_TOBE64( value ) MASTER_L2BE64(value)
		
		#define MASTER_TOPDP16( value ) MASTER_L2PDPE16(value)
		#define MASTER_TOPDP32( value ) MASTER_L2PDPE32(value)
		#define MASTER_TOPDP64( value ) MASTER_L2PDPE64(value)
		
		#define MASTER_FROMLE( value ) (value)
		#define MASTER_FROMLE16( value ) (value)
		#define MASTER_FROMLE32( value ) (value)
		#define MASTER_FROMLE64( value ) (value)
		
		#define MASTER_FROMBE( value ) MASTER_B2LE(value)
		#define MASTER_FROMBE16( value ) MASTER_B2LE16(value)
		#define MASTER_FROMBE32( value ) MASTER_B2LE32(value)
		#define MASTER_FROMBE64( value ) MASTER_B2LE64(value)
		
		#define MASTER_FROMPDP16( value ) MASTER_PDP2LE16(value)
		#define MASTER_FROMPDP32( value ) MASTER_PDP2LE32(value)
		#define MASTER_FROMPDP64( value ) MASTER_PDP2LE64(value)
		
		#define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_LE(value)
		#define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_LE(value)
		#define MASTER_GLIBE( min_value, max_value ) MASTER_LELOW( min_value, max_value )
		#define MASTER_GHIBE( min_value, max_value ) MASTER_LEHIGH( min_value, max_value )
		
	#elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
		#define MASTER_TOLE( value ) MASTER_B2LE(value)
		#define MASTER_TOLE16( value ) MASTER_B2LE16(value)
		#define MASTER_TOLE32( value ) MASTER_B2LE32(value)
		#define MASTER_TOLE64( value ) MASTER_B2LE64(value)
		
		#define MASTER_TOBE( value ) (value)
		#define MASTER_TOBE16( value ) (value)
		#define MASTER_TOBE32( value ) (value)
		#define MASTER_TOBE64( value ) (value)
		
		#define MASTER_TOPDP16( value ) MASTER_B2PDPE16(value)
		#define MASTER_TOPDP32( value ) MASTER_B2PDPE32(value)
		#define MASTER_TOPDP64( value ) MASTER_B2PDPE64(value)
		
		#define MASTER_FROMLE( value ) MASTER_L2BE(value)
		#define MASTER_FROMLE16( value ) MASTER_L2BE16(value)
		#define MASTER_FROMLE32( value ) MASTER_L2BE32(value)
		#define MASTER_FROMLE64( value ) MASTER_L2BE64(value)
		
		#define MASTER_FROMBE( value ) (value)
		#define MASTER_FROMBE16( value ) (value)
		#define MASTER_FROMBE32( value ) (value)
		#define MASTER_FROMBE64( value ) (value)
		
		#define MASTER_FROMPDP16( value ) MASTER_PDP2BE16(value)
		#define MASTER_FROMPDP32( value ) MASTER_PDP2BE32(value)
		#define MASTER_FROMPDP64( value ) MASTER_PDP2BE64(value)
		
		#define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_BE(value)
		#define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_BE(value)
		#define MASTER_GLIBE( min_value, max_value ) MASTER_BELOW( min_value, max_value )
		#define MASTER_GHIBE( min_value, max_value ) MASTER_BEHIGH( min_value, max_value )
		
	#elif MASTER_ENDIANNESS == MASTER_PDP_ENDIAN
		/* #! PDP have maximum 32 bits. But in 64 bit endian will be 78563412 !# */
		#define MASTER_TOLE( value ) ( \
			(sizeof(value) == 1) ? (value) : (sizeof(value) == 2) ? (MASTER_TOLE16(value)) : (sizeof(value) == 4) ? (MASTER_TOLE32(value)) : (MASTER_TOLE64(value)))
		#define MASTER_TOLE16( value ) MASTER_PDP2LE16(value)
		#define MASTER_TOLE32( value ) MASTER_PDP2LE32(value)
		#define MASTER_TOLE64( value ) MASTER_PDP2LE64(value)
		
		#define MASTER_TOBE( value ) ( \
			(sizeof(value) == 1) ? (value) : (sizeof(value) == 2) ? (MASTER_TOBE16(value)) : (sizeof(value) == 4) ? (MASTER_TOBE32(value)) : (MASTER_TOBE64(value)))
		#define MASTER_TOBE16( value ) MASTER_PDP2BE16(value)
		#define MASTER_TOBE32( value ) MASTER_PDP2BE32(value)
		#define MASTER_TOBE64( value ) MASTER_PDP2BE64(value)
		
		#define MASTER_TOPDP16( value ) (value)
		#define MASTER_TOPDP32( value ) (value)
		#define MASTER_TOPDP64( value ) (value)
		
		//#define MASTER_FROMLE( value )
		#define MASTER_FROMLE16( value ) MASTER_L2PDPE16(value)
		#define MASTER_FROMLE32( value ) MASTER_L2PDPE32(value)
		#define MASTER_FROMLE64( value ) MASTER_L2PDPE64(value)
		
		//#define MASTER_FROMBE( value )
		#define MASTER_FROMBE16( value ) MASTER_B2PDPE16(value)
		#define MASTER_FROMBE32( value ) MASTER_B2PDPE32(value)
		#define MASTER_FROMBE64( value ) MASTER_B2PDPE64(value)
		
		#define MASTER_FROMPDP16( value ) (value)
		#define MASTER_FROMPDP32( value ) (value)
		#define MASTER_FROMPDP64( value ) (value)
		
		#define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_PDPE(value)
		#define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_PDPE(value)
		#define MASTER_GLIBE( min_value, max_value ) MASTER_PDPELOW( min_value, max_value )
		#define MASTER_GHIBE( min_value, max_value ) MASTER_PDPEHIGH( min_value, max_value )
		
	#endif /* MASTER_UNKNOWN_ENDIANNESS */
#else /* #! MASTER_UNKNOWN_ENDIAN - runtime check !# */
/* #! TODO !# */
	
#endif /* ENDIANNESS */

#define __MASTER_MACROS_DEFINE_ALL_TYPES( define_macros ) \
define_macros( SI1, c ); \
define_macros( UI1, uc ); \
define_macros( SI2, s ); \
define_macros( UI2, us ); \
define_macros( SI4, i ); \
define_macros( UI4, ui ); \
define_macros( SI8, li ); \
define_macros( UI8, uli ); \
define_macros( float, f ); \
define_macros( double, d ); \
define_macros( long double, ld ); \

/* #! MASTER Saturation Functions !# */

#define MASTER_SaturateSI1( value ) (SI1)MASTER_CLAMP(value, MASTER_SI1_MIN, MASTER_SI1_MAX)
#define MASTER_SaturateSI2( value ) (SI2)MASTER_CLAMP(value, MASTER_SI2_MIN, MASTER_SI2_MAX)
#define MASTER_SaturateSI4( value ) (SI4)MASTER_CLAMP(value, MASTER_SI4_MIN, MASTER_SI4_MAX)
#define MASTER_SaturateUI1( value ) (UI1)MASTER_CLAMP(value, MASTER_UI1_MIN, MASTER_UI1_MAX)
#define MASTER_SaturateUI2( value ) (UI2)MASTER_CLAMP(value, MASTER_UI2_MIN, MASTER_UI2_MAX)
#define MASTER_SaturateUI4( value ) (UI4)MASTER_CLAMP(value, MASTER_UI4_MIN, MASTER_UI4_MAX)

#define __MASTER_MACROS_DEFINE_AddSaturateSIx( type ) \
type \
MASTER_AddSaturate##type( a, b ) \
	const type a; \
	const type b; \
{ \
	const type c = a + b; \
	if (a > 0 && b > 0 && c < 0) return MASTER_##type##_MAX; \
	if (a < 0 && b < 0 && c > 0) return MASTER_##type##_MIN; \
	return c; \
}

#define __MASTER_MACROS_DEFINE_AddSaturateUIx( type ) \
type \
MASTER_AddSaturate##type( a, b ) \
	const type a; \
	const type b; \
{ \
	const type c = a + b; \
	if (c < a) return MASTER_##type##_MAX; \
	return c; \
}

#define __MASTER_MACROS_DEFINE_SubSaturateSIx( type ) \
type \
MASTER_SubSaturate##type( a, b ) \
	const type a; \
	const type b; \
{ \
	const type c = a - b; \
	if (a >= 0 && b < 0 && c < 0) return MASTER_##type##_MAX; \
	if (a < 0 && b > 0 && c > 0) return MASTER_##type##_MIN; \
	return c; \
}

#define __MASTER_MACROS_DEFINE_SubSaturateUIx( type ) \
type \
MASTER_SubSaturate##type( a, b ) \
	const type a; \
	const type b; \
{ \
	const type c = a - b; \
	if (c > a) return MASTER_##type##_MIN; \
	return c; \
}

#define __MASTER_MACROS_DEFINE_MulSaturateSIx( type ) \
type \
MASTER_MulSaturate##type( a, b ) \
	const type a; \
	const type b; \
{ \
	const type c = a * b; \
	return (b != 0 && c / b != a) ? ( ((a > 0) == (b > 0)) ? MASTER_##type##_MAX : MASTER_##type##_MIN ) : c; \
}

#define __MASTER_MACROS_DEFINE_MulSaturateUIx( type ) \
type \
MASTER_MulSaturate##type( a, b ) \
	const type a; \
	const type b; \
{ \
	const type c = a * b; \
	if (b != 0 && c / b != a) return MASTER_##type##_MAX; \
	return c; \
}

__MASTER_MACROS_DEFINE_AddSaturateSIx( SI1 )
__MASTER_MACROS_DEFINE_SubSaturateSIx( SI1 )
__MASTER_MACROS_DEFINE_MulSaturateSIx( SI1 )
__MASTER_MACROS_DEFINE_AddSaturateSIx( SI2 )
__MASTER_MACROS_DEFINE_SubSaturateSIx( SI2 )
__MASTER_MACROS_DEFINE_MulSaturateSIx( SI2 )
__MASTER_MACROS_DEFINE_AddSaturateSIx( SI4 )
__MASTER_MACROS_DEFINE_SubSaturateSIx( SI4 )
__MASTER_MACROS_DEFINE_MulSaturateSIx( SI4 )
#if MASTER_64_AVAILABLE == 1
	__MASTER_MACROS_DEFINE_AddSaturateSIx( SI8 )
	__MASTER_MACROS_DEFINE_SubSaturateSIx( SI8 )
	__MASTER_MACROS_DEFINE_MulSaturateSIx( SI8 )
#endif /* #! MASTER_64_AVAILABLE !# */

__MASTER_MACROS_DEFINE_AddSaturateUIx( UI1 )
__MASTER_MACROS_DEFINE_SubSaturateUIx( UI1 )
__MASTER_MACROS_DEFINE_MulSaturateUIx( UI1 )
__MASTER_MACROS_DEFINE_AddSaturateUIx( UI2 )
__MASTER_MACROS_DEFINE_SubSaturateUIx( UI2 )
__MASTER_MACROS_DEFINE_MulSaturateUIx( UI2 )
__MASTER_MACROS_DEFINE_AddSaturateUIx( UI4 )
__MASTER_MACROS_DEFINE_SubSaturateUIx( UI4 )
__MASTER_MACROS_DEFINE_MulSaturateUIx( UI4 )
#if MASTER_64_AVAILABLE == 1
	__MASTER_MACROS_DEFINE_AddSaturateUIx( UI8 )
	__MASTER_MACROS_DEFINE_SubSaturateUIx( UI8 )
	__MASTER_MACROS_DEFINE_MulSaturateUIx( UI8 )
#endif /* #! MASTER_64_AVAILABLE !# */

#undef __MASTER_MACROS_DEFINE_AddSaturateUIx
#undef __MASTER_MACROS_DEFINE_AddSaturateSIx
#undef __MASTER_MACROS_DEFINE_SubSaturateUIx
#undef __MASTER_MACROS_DEFINE_SubSaturateSIx
#undef __MASTER_MACROS_DEFINE_MulSaturateUIx
#undef __MASTER_MACROS_DEFINE_MulSaturateSIx

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

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_CODE_STYLE_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_CODE_STYLE_INCLUDE_H__ !# */

/* #! be master~ !# */
