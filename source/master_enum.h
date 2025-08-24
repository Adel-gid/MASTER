
/*
 * Copyright (c) 2025 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_CODE_STYLE_INCLUDE_H__
#define __MASTER_CODE_STYLE_INCLUDE_H__

/* #! High priority !# */

/* #! MASTER Types !# */

typedef unsigned char UI1;
typedef unsigned short UI2;
typedef unsigned int UI4;

typedef signed char SI1;
typedef signed short SI2;
typedef signed int SI4;

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
		
	#elif !defined(MASTER_NO_DEPENDENCIES) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
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
	#elif !defined(MASTER_NO_DEPENDENCIES) && !defined(MASTER_IGNORE_ARCHITECTURE)
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
			#ifdef MASTER_NO_DEPENDENCIES
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
			#endif /* #! MASTER_NO_DEPENDENCIES !# */
		#endif /* #! MASTER_IGNORE_C89_STD_64_VARIABLES !# */
	#endif /* #! C / C++ check !# */
#endif /* #! MASTER_64_AVAILABLE !# */

#if MASTER_64_AVAILABLE == 1
	typedef unsigned long long int UI8;
	typedef signed long long int SI8;
#else
	typedef struct {
		UI4 lo;
		UI4 hi;
	} UI8;
	typedef struct {
		UI4 lo;
		SI4 hi;
	} SI8;
#endif /* #! MASTER_64_AVAILABLE !# */

/* #! compiler trash !# */

#define MASTER_UNSUPPORTING 0
#define MASTER_PARTIAL_SUPPORTING 5
#define MASTER_SUPPORTING 10
#define MASTER_SUPOORT_STATE( nivel ) (nivel)

#ifndef MASTER_COMPILER_SETTINGS
	#if !defined(MASTER_NO_DEPENDENCIES) && defined(MASTER_PREFER_USE_COMPILER_SETTING)
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

typedef enum {
	MASTER_NO_ERROR = 0,
	MASTER_ERROR,
	
	MASTER_FILE_NOT_FOUND,
	MASTER_FILE_CANT_CREATE,
	MASTER_FILE_READ_FAILURE,
	MASTER_FILE_WRITE_FAILURE,
	MASTER_FAILED_MALLOC,
	MASTER_FAILED_REALLOC,
	MASTER_GOT_NULL_ARGUMENT,
	
	MASTER_CSV_NOT_CLOSED_QUOTES,
	MASTER_CSV_EMPTY,
	
	MASTER_QUEUE_IS_EMPTY,
	
	MASTER_MAX_RETURN_CODE
} MASTER_return_code;

/* #! MASTER Assertion !# */

#define MASTER_IS_SUCCESS(code) ((code) == MASTER_NO_ERROR)
#define MASTER_IS_FAILURE(code) ((code) != MASTER_NO_ERROR)

#ifdef MASTER_ENABLE_ASSERTIONS
	#ifndef MASTER_FUNCTION_ASSERTION
		#error \
		With defined "MASTER_ENABLE_ASSERTIONS" function "MASTER_FUNCTION_ASSERTION" with arguments (expr, msg) must be defined.
	#endif /* MASTER_FUNCTION_ASSERTION */
	#define MASTER_ASSERT(expr, msg) MASTER_FUNCTION_ASSERTION((expr), (msg))
#else
	#define MASTER_ASSERT(expr, msg)
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
	
#elif defined(MASTER_NO_DEPENDENCIES)
	#ifndef MASTER_MALLOC
		#error \
		With defined "MASTER_NO_DEPENDENCIES" function "MASTER_MALLOC" must be defined.
	#endif /* MASTER_MALLOC */
	#ifndef MASTER_REALLOC
		#error \
		With defined "MASTER_NO_DEPENDENCIES" function "MASTER_REALLOC" must be defined.
	#endif /* MASTER_REALLOC */
	#ifndef MASTER_CALLOC
		#error \
		With defined "MASTER_NO_DEPENDENCIES" function "MASTER_CALLOC" must be defined.
	#endif /* MASTER_CALLOC */
	#ifndef MASTER_FREE
		#error \
		With defined "MASTER_NO_DEPENDENCIES" function "MASTER_FREE" must be defined.
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
	#define MASTER_MALLOC(__size) malloc(__size)
	#define MASTER_CALLOC(__count, __size) calloc(__count, __size)
	#define MASTER_REALLOC(__ptr, __size) realloc(__ptr, __size)
	#define MASTER_FREE(__ptr) free(__ptr)
	
#endif /* #! MASTER_MEMORY_SAFE !# */

/* #! MASTER Syntax !# */

#define otherwise else if
#define nul 0

/* #! MASTER Code Manipulations !# */

#define MASTER_REPEAT2( code ) do { code; code; } while (0)
#define MASTER_REPEAT3( code ) do { code; code; code; } while (0)
#define MASTER_REPEAT4( code ) do { code; code; code; code; } while (0)

/* #! MASTER Bits Manimulations !# */

#define MASTER_BITS_TO_BYTES( x ) (((x) + 7) >> 3)

/* #! MASTER Align !# */

#define MASTER_ALIGNPOW2( x, n ) ((((x) >> (n)) + !!((x) & ((1 << (n)) - 1))) << (n))
#define MASTER_ALIGN2( x ) MASTER_ALIGNPOW2( x, 1 )
#define MASTER_ALIGN4( x ) MASTER_ALIGNPOW2( x, 2 )
#define MASTER_ALIGN8( x ) MASTER_ALIGNPOW2( x, 3 )
#define MASTER_ALIGN16( x ) MASTER_ALIGNPOW2( x, 4 )
#define MASTER_ALIGN( x, n ) ((((x) / (n)) + !!((x) % (n))) * (n))

/* #! MASTER Simple Macroses !# */

#define MASTER_STRINGIFY( a ) #a
#define MASTER_MEMBER_SIZE( type, member ) sizeof(((const type * const)0)->member)
#define MASTER_MAX( a, b ) (((a) > (b)) ? (a) : (b))
#define MASTER_MIN( a, b ) (((a) < (b)) ? (a) : (b))
#define MASTER_CLAMP( a, _min, _max ) MASTER_MAX(_min, MASTER_MIN(_max, a))
#define MASTER_ABS( x ) (((x) < 0) ? (-(x)) : (x))
#define MASTER_SIGN( x ) (((x) < 0) ? (-1) : ((x) > 0) ? (+1) : (0))
#define MASTER_SQUARE(x) ((x)*(x))
#define MASTER_2BYTES_TO_INT( a, b ) (((a) << 8) | (b))
#define MASTER_4BYTES_TO_INT( a, b, c, d ) (((a) << 24) | ((b) << 16) | ((c) << 8) | (d))

#define MASTER_DIV_CEIL2( x ) (((x) + 1) >> 1)
#define MASTER_DIV_CEIL4( x ) (((x) + 3) >> 2)
#define MASTER_DIV_CEIL8( x ) (((x) + 7) >> 3)
#define MASTER_DIV_CEIL_POW2( x, n ) (((x) + ((1 << n) - 1)) >> (n))

#define MASTER_HOWMANY2( x ) MASTER_DIV_CEIL2( x )
#define MASTER_HOWMANY4( x ) MASTER_DIV_CEIL4( x )
#define MASTER_HOWMANY8( x ) MASTER_DIV_CEIL8( x )
#define MASTER_HOWMANY_POW2( x, n ) MASTER_DIV_CEIL_POW2( x, n )
#define MASTER_HOWMANY( x, n ) (((x) + ((n) - 1)) / (n))

/* #!! MASTER Pow Manipulations !!# */

#define MASTER_ISPOW2( x ) (!((x) & ((x) - 1)))
#define MASTER_ISPOW4( x ) (MASTER_ISPOW2(x) && ((x) & 0x55555555))
#define MASTER_ISPOW8( x ) (MASTER_ISPOW2(x) && ((x) & 0x49249249))
#define MASTER_ISPOW16( x ) (MASTER_ISPOW2(x) && ((x) & 0x11111111))

MASTER_PREFER_INLINE UI1
MASTER_SMEAR1( UI1 value ) {
	value |= value >> 4;
	value |= value >> 2;
	value |= value >> 1;
	return value;
}

MASTER_PREFER_INLINE UI2
MASTER_SMEAR2( UI2 value ) {
	value |= value >> 8;
	value |= value >> 4;
	value |= value >> 2;
	value |= value >> 1;
	return value;
}

MASTER_PREFER_INLINE UI4
MASTER_SMEAR4( UI4 value ) {
	value |= value >> 16;
	value |= value >> 8;
	value |= value >> 4;
	value |= value >> 2;
	value |= value >> 1;
	return value;
}

#if MASTER_64_AVAILABLE == 1
MASTER_PREFER_INLINE UI8
MASTER_SMEAR8( UI8 value ) {
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
MASTER_BITLEN1( UI1 value ) {
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, U);
	if (value > 0) bitcount += 1;
	return bitcount;
}

MASTER_PREFER_INLINE UI2
MASTER_BITLEN2( UI2 value ) {
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 8, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, U);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, U);
	if (value > 0) bitcount += 1;
	return bitcount;
}

MASTER_PREFER_INLINE UI4
MASTER_BITLEN4( UI4 value ) {
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
MASTER_BITLEN8( UI8 value ) {
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

#define MASTER_POW2FLOOR1( x ) ((MASTER_SMEAR1(x) >> 1) + 1)
#define MASTER_POW2FLOOR2( x ) ((MASTER_SMEAR2(x) >> 1) + 1)
#define MASTER_POW2FLOOR4( x ) ((MASTER_SMEAR4(x) >> 1) + 1)
#define MASTER_POW2CEIL1( x ) (MASTER_SMEAR1(x - 1) + 1)
#define MASTER_POW2CEIL2( x ) (MASTER_SMEAR2(x - 1) + 1)
#define MASTER_POW2CEIL4( x ) (MASTER_SMEAR4(x - 1) + 1)
#define MASTER_LOG2FLOOR1( x ) (MASTER_BITLEN1(x) - 1)
#define MASTER_LOG2FLOOR2( x ) (MASTER_BITLEN2(x) - 1)
#define MASTER_LOG2FLOOR4( x ) (MASTER_BITLEN4(x) - 1)
#define MASTER_LOG2CEIL1( x ) (MASTER_BITLEN1(x) - MASTER_ISPOW2(x))
#define MASTER_LOG2CEIL2( x ) (MASTER_BITLEN2(x) - MASTER_ISPOW2(x))
#define MASTER_LOG2CEIL4( x ) (MASTER_BITLEN4(x) - MASTER_ISPOW2(x))

#if MASTER_64_AVAILABLE == 1
#define MASTER_POW2FLOOR8( x ) ((MASTER_SMEAR8(x) >> 1) + 1)
#define MASTER_POW2CEIL8( x ) (MASTER_SMEAR8(x - 1) + 1)
#define MASTER_LOG2FLOOR8( x ) (MASTER_BITLEN8(x) - 1)
#define MASTER_LOG2CEIL8( x ) (MASTER_BITLEN8(x) - MASTER_ISPOW2(x))

#endif /* #! MASTER_64_AVAILABLE !# */

#ifdef MASTER_ROUND_FUNCS_INSTEAD_OF_MACROS
	#define MASTER_POW2ROUND1( x ) (((x) < (MASTER_POW2FLOOR1(x) | (MASTER_POW2FLOOR1(x) >> 1))) ? (MASTER_POW2FLOOR1(x)) : (MASTER_POW2CEIL1(x)))
	#define MASTER_POW2ROUND2( x ) (((x) < (MASTER_POW2FLOOR2(x) | (MASTER_POW2FLOOR2(x) >> 1))) ? (MASTER_POW2FLOOR2(x)) : (MASTER_POW2CEIL2(x)))
	#define MASTER_POW2ROUND4( x ) (((x) < (MASTER_POW2FLOOR4(x) | (MASTER_POW2FLOOR4(x) >> 1))) ? (MASTER_POW2FLOOR4(x)) : (MASTER_POW2CEIL4(x)))
	#define MASTER_LOG2ROUND1( x ) (((x) < (MASTER_POW2FLOOR1(x) | (MASTER_POW2FLOOR1(x) >> 1))) ? (MASTER_LOG2FLOOR1(x)) : (MASTER_LOG2CEIL1(x)))
	#define MASTER_LOG2ROUND2( x ) (((x) < (MASTER_POW2FLOOR2(x) | (MASTER_POW2FLOOR2(x) >> 1))) ? (MASTER_LOG2FLOOR2(x)) : (MASTER_LOG2CEIL2(x)))
	#define MASTER_LOG2ROUND4( x ) (((x) < (MASTER_POW2FLOOR4(x) | (MASTER_POW2FLOOR4(x) >> 1))) ? (MASTER_LOG2FLOOR4(x)) : (MASTER_LOG2CEIL4(x)))
	
	#if MASTER_64_AVAILABLE == 1
		#define MASTER_POW2ROUND8( x ) (((x) < (MASTER_POW2FLOOR8(x) | (MASTER_POW2FLOOR8(x) >> 1))) ? (MASTER_POW2FLOOR8(x)) : (MASTER_POW2CEIL8(x)))
		#define MASTER_LOG2ROUND8( x ) (((x) < (MASTER_POW2FLOOR8(x) | (MASTER_POW2FLOOR8(x) >> 1))) ? (MASTER_LOG2FLOOR8(x)) : (MASTER_LOG2CEIL8(x)))
		
	#endif /* #! MASTER_64_AVAILABLE !# */

#else
#define __MASTER_POW2ROUNDX_GENERATE_MACRO( suff ) \
	MASTER_PREFER_INLINE UI##suff \
	MASTER_POW2ROUND##suff( UI##suff x ) { \
		UI##suff fl = MASTER_POW2FLOOR##suff(x); \
		fl |= fl >> 1; \
		if (x < fl) return fl & (fl << 1); \
		return MASTER_POW2CEIL##suff(x); \
	}
#define __MASTER_LOG2ROUNDX_GENERATE_MACRO( suff, numsuff ) \
	MASTER_PREFER_INLINE UI##suff \
	MASTER_LOG2ROUND##suff( UI##suff x ) { \
		const UI1 bits = MASTER_LOG2FLOOR##suff(x); \
		UI##suff fl = 1##numsuff << bits; \
		if (x <= 1) return x - 1; \
		fl |= fl >> 1; \
		return bits + (x >= fl); \
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

MASTER_PREFER_INLINE const UI1
MASTER_LOG2MATHROUND1( UI1 value ) {
	if (value >= 0xB6) return 8;
	if (value >= 0x5B) return 7;
	if (value >= 0x2E) return 6;
	if (value >= 0x17) return 5;
	if (value >= 0xC) return 4;
	if (value >= 0x6) return 3;
	if (value >= 0x3) return 2;
	return value - 1;
}

MASTER_PREFER_INLINE const UI1
MASTER_LOG2MATHROUND2( UI2 value ) {
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

MASTER_PREFER_INLINE const UI1
MASTER_LOG2MATHROUND4( UI4 value ) {
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
MASTER_PREFER_INLINE const UI1
MASTER_LOG2MATHROUND8( UI8 value ) {
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

#define MASTER_POW2MATHROUND1( x ) (1 << MASTER_LOG2MATHROUND1(x))
#define MASTER_POW2MATHROUND2( x ) (1 << MASTER_LOG2MATHROUND2(x))
#define MASTER_POW2MATHROUND4( x ) (1 << MASTER_LOG2MATHROUND4(x))
#if MASTER_64_AVAILABLE == 1
	#define MASTER_POW2MATHROUND8( x ) (1L << MASTER_LOG2MATHROUND8(x))
#endif /* #! MASTER_64_AVAILABLE !# */

#define MASTER_ADD_OVERFLOW_UI1(a, b, carry) carry = ((a >= ((UI1)-1) - b) ? (1) : (0))
#define MASTER_ADD_OVERFLOW_UI2(a, b, carry) carry = ((a >= ((UI2)-1) - b) ? (1) : (0))
#define MASTER_ADD_OVERFLOW_UI4(a, b, carry) carry = ((a >= ((UI4)-1) - b) ? (1) : (0))

/* #! MASTER Shifts !# */

#define MASTER_RLLN(a, k, n) (((a) << (k)) | ((a) >> ((n) - (k))))
#define MASTER_RLRN(a, k, n) (((a) >> (k)) | ((a) << ((n) - (k))))
#define MASTER_RLL8(a, k) MASTER_RLLN(a, k, 8)
#define MASTER_RLL16(a, k) MASTER_RLLN(a, k, 16)
#define MASTER_RLL32(a, k) MASTER_RLLN(a, k, 32)
#define MASTER_RLL64(a, k) MASTER_RLLN(a, k, 64)
#define MASTER_RLR8(a, k) MASTER_RLRN(a, k, 8)
#define MASTER_RLR16(a, k) MASTER_RLRN(a, k, 16)
#define MASTER_RLR32(a, k) MASTER_RLRN(a, k, 32)
#define MASTER_RLR64(a, k) MASTER_RLRN(a, k, 64)
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
	#ifndef MASTER_NO_DEPENDENCIES
		#include <architecture_detect.h>
		#if MASTER_ARCHITECTURE_ENDIAN == MASTER_LITTLE_ENDIAN
			#define MASTER_ENDIANNESS MASTER_LITTLE_ENDIAN
		
		#elif MASTER_ARCHITECTURE_ENDIAN == MASTER_BIG_ENDIAN
			#define MASTER_ENDIANNESS MASTER_BIG_ENDIAN
		
		#elif MASTER_ARCHITECTURE_ENDIAN == MASTER_PDP_ENDIAN
			#define MASTER_ENDIANNESS MASTER_PDP_ENDIAN
			
		#endif * #! Architecture Endian !# */
	#endif /* #! MASTER_NO_DEPENDENCIES !# */
	
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

#define MASTER_BSWAP16( x ) (((x) >> 8) | ((x) << 8))
#define MASTER_BSWAP32( x ) ( \
	(((x) >> 24) & 0x000000FF) | \
	(((x) >>  8) & 0x0000FF00) | \
	(((x) <<  8) & 0x00FF0000) | \
	(((x) << 24) & 0xFF000000))
#define MASTER_BSWAP64( x ) ( \
	(((x) >> 56) & 0x00000000000000FF) | \
	(((x) >> 40) & 0x000000000000FF00) | \
	(((x) >> 24) & 0x0000000000FF0000) | \
	(((x) >>  8) & 0x00000000FF000000) | \
	(((x) <<  8) & 0x000000FF00000000) | \
	(((x) << 24) & 0x0000FF0000000000) | \
	(((x) << 40) & 0x00FF000000000000) | \
	(((x) << 56) & 0xFF00000000000000))
#define MASTER_BSWAP_GENERIC( x, size ) ( \
	(((size) == 1) ? (x) : ((size) == 2) ? (MASTER_BSWAP16(x)) : ((size) == 4) ? (MASTER_BSWAP32(x)) : (MASTER_BSWAP64(x))))

#define MASTER_IsLittleEndian() (MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN)
#define MASTER_IsBigEndian() (MASTER_ENDIANNESS == MASTER_BIG_ENDIAN)
#define MASTER_IsPDPEndian() (MASTER_ENDIANNESS == MASTER_PDP_ENDIAN)
#ifdef MASTER_UNKNOWN_ENDIANNESS
	#define MASTER_IsGenericEndian() (1)
#else
	#define MASTER_IsGenericEndian() (0)
#endif /* #! MASTER_UNKNOWN_ENDIANNESS !# */

#define MASTER_L2BE( x ) MASTER_BSWAP_GENERIC(x, sizeof(x))
#define MASTER_L2BE16( x ) MASTER_BSWAP16(x)
#define MASTER_L2BE32( x ) MASTER_BSWAP32(x)
#define MASTER_L2BE64( x ) MASTER_BSWAP64(x)
#define MASTER_L2PDPE16( x ) MASTER_BSWAP16(x)
#define MASTER_L2PDPE32( x ) ( \
	(((x) >> 16) & 0x0000FFFF) | \
	(((x) << 16) & 0xFFFF0000))
#define MASTER_L2PDP64( x ) ( \
	(((x) >> 48) & 0x000000000000FFFF) | \
	(((x) >> 16) & 0x00000000FFFF0000) | \
	(((x) << 16) & 0x0000FFFF00000000) | \
	(((x) << 48) & 0xFFFF000000000000))

#define MASTER_B2LE( x ) MASTER_BSWAP_GENERIC(x, sizeof(x))
#define MASTER_B2LE16( x ) MASTER_BSWAP16(x)
#define MASTER_B2LE32( x ) MASTER_BSWAP32(x)
#define MASTER_B2LE64( x ) MASTER_BSWAP64(x)
#define MASTER_B2PDPE16( x ) (x)
#define MASTER_B2PDPE32( x ) ( \
	(((x) >> 8) & 0x00FF00FF) | \
	(((x) << 8) & 0xFF00FF00))
#define MASTER_B2PDPE64( x ) ( \
	(((x) >> 8) & 0x00FF00FF00FF00FF) | \
	(((x) << 8) & 0xFF00FF00FF00FF00))

#define MASTER_PDP2LE16( x ) MASTER_BSWAP16(x)
#define MASTER_PDP2LE32( x ) ( \
	(((x) >> 16) & 0x0000FFFF) | \
	(((x) << 16) & 0xFFFF0000))
#define MASTER_PDP2LE64( x ) ( \
	(((x) >> 48) & 0x000000000000FFFF) | \
	(((x) >> 16) & 0x00000000FFFF0000) | \
	(((x) << 16) & 0x0000FFFF00000000) | \
	(((x) << 48) & 0xFFFF000000000000))
#define MASTER_PDP2BE16( x ) (x)
#define MASTER_PDP2BE32( x ) ( \
	(((x) >> 8) & 0x00FF00FF) | \
	(((x) << 8) & 0xFF00FF00))
#define MASTER_PDP2BE64( x ) ( \
	(((x) >> 8) & 0x00FF00FF00FF00FF) | \
	(((x) << 8) & 0xFF00FF00FF00FF00))

#define MASTER_ITERATE_L2H_LE( x ) ((x)++)
#define MASTER_ITERATE_H2L_LE( x ) ((x)--)
#define MASTER_ITERATE_L2H_BE( x ) ((x)--)
#define MASTER_ITERATE_H2L_BE( x ) ((x)++)
#define MASTER_ITERATE_L2H_PDP( x ) (((x) & 1) ? ((x) &= ~1) : ((x) += 3))
#define MASTER_ITERATE_H2L_PDP( x ) ((!((x) & 1)) ? ((x) |= 1) : ((x) -= 3))

#define MASTER_LELOW( _min, _max ) (_min)
#define MASTER_LEHIGH( _min, _max ) (_max)
#define MASTER_BELOW( _min, _max ) (_max)
#define MASTER_BEHIGH( _min, _max ) (_min)
#define MASTER_PDPELOW( _min, _max ) ((_min) + 1)
#define MASTER_PDPEHIGH( _min, _max ) ((_max) - 1)

#ifndef MASTER_UNKNOWN_ENDIANNESS
	#if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
		#define MASTER_TOLE(x) (x)
		#define MASTER_TOLE16(x) (x)
		#define MASTER_TOLE32(x) (x)
		#define MASTER_TOLE64(x) (x)
		
		#define MASTER_TOBE(x) MASTER_L2BE(x)
		#define MASTER_TOBE16(x) MASTER_L2BE16(x)
		#define MASTER_TOBE32(x) MASTER_L2BE32(x)
		#define MASTER_TOBE64(x) MASTER_L2BE64(x)
		
		#define MASTER_TOPDP16(x) MASTER_L2PDPE16(x)
		#define MASTER_TOPDP32(x) MASTEE_L2PDPE32(x)
		#define MASTER_TOPDP64(x) MASTEE_L2PDPE64(x)
		
		#define MASTER_FROMLE(x) (x)
		#define MASTER_FROMLE16(x) (x)
		#define MASTER_FROMLE32(x) (x)
		#define MASTER_FROMLE64(x) (x)
		
		#define MASTER_FROMBE(x) MASTER_B2LE(x)
		#define MASTER_FROMBE16(x) MASTER_B2LE16(x)
		#define MASTER_FROMBE32(x) MASTER_B2LE32(x)
		#define MASTER_FROMBE64(x) MASTER_B2LE64(x)
		
		#define MASTER_FROMPDP16(x) MASTER_PDP2LE16(x)
		#define MASTER_FROMPDP32(x) MASTEE_PDP2LE32(x)
		#define MASTER_FROMPDP64(x) MASTEE_PDP2LE64(x)
		
		#define MASTER_ITERATE_L2H( x ) MASTER_ITERATE_L2H_LE(x)
		#define MASTER_ITERATE_H2L( x ) MASTER_ITERATE_H2L_LE(x)
		#define MASTER_GLIBE( _min, _max ) MASTER_LELOW( _min, _max )
		#define MASTER_GHIBE( _min, _max ) MASTER_LEHIGH( _min, _max )
		
	#elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
		#define MASTER_TOLE(x) MASTER_B2LE(x)
		#define MASTER_TOLE16(x) MASTER_B2LE16(x)
		#define MASTER_TOLE32(x) MASTER_B2LE32(x)
		#define MASTER_TOLE64(x) MASTER_B2LE64(x)
		
		#define MASTER_TOBE(x) (x)
		#define MASTER_TOBE16(x) (x)
		#define MASTER_TOBE32(x) (x)
		#define MASTER_TOBE64(x) (x)
		
		#define MASTER_TOPDP16(x) MASTER_B2PDPE16(x)
		#define MASTER_TOPDP32(x) MASTEE_B2PDPE32(x)
		#define MASTER_TOPDP64(x) MASTEE_B2PDPE64(x)
		
		#define MASTER_FROMLE(x) MASTER_L2BE(x)
		#define MASTER_FROMLE16(x) MASTER_L2BE16(x)
		#define MASTER_FROMLE32(x) MASTER_L2BE32(x)
		#define MASTER_FROMLE64(x) MASTER_L2BE64(x)
		
		#define MASTER_FROMBE(x) (x)
		#define MASTER_FROMBE16(x) (x)
		#define MASTER_FROMBE32(x) (x)
		#define MASTER_FROMBE64(x) (x)
		
		#define MASTER_FROMPDP16(x) MASTER_PDP2BE16(x)
		#define MASTER_FROMPDP32(x) MASTEE_PDP2BE32(x)
		#define MASTER_FROMPDP64(x) MASTEE_PDP2BE64(x)
		
		#define MASTER_ITERATE_L2H( x ) MASTER_ITERATE_L2H_BE(x)
		#define MASTER_ITERATE_H2L( x ) MASTER_ITERATE_H2L_BE(x)
		#define MASTER_GLIBE( _min, _max ) MASTER_BELOW( _min, _max )
		#define MASTER_GHIBE( _min, _max ) MASTER_BEHIGH( _min, _max )
		
	#elif MASTER_ENDIANNESS == MASTER_PDP_ENDIAN
		/* #! PDP have maximum 32 bits. But in 64 bit endian will be 78563412 !# */
		#define MASTER_TOLE(x) ( \
			(sizeof(x) == 1) ? (x) : (sizeof(x) == 2) ? (MASTER_TOLE16(x)) : (sizeof(x) == 4) ? (MASTER_TOLE32(x)) : (MASTER_TOLE64(x)))
		#define MASTER_TOLE16(x) MASTER_PDP2LE16(x)
		#define MASTER_TOLE32(x) MASTER_PDP2LE32(x)
		#define MASTER_TOLE64(x) MASTER_PDP2LE64(x)
		
		#define MASTER_TOBE(x) ( \
			(sizeof(x) == 1) ? (x) : (sizeof(x) == 2) ? (MASTER_TOBE16(x)) : (sizeof(x) == 4) ? (MASTER_TOBE32(x)) : (MASTER_TOBE64(x)))
		#define MASTER_TOBE16(x) MASTER_PDP2BE16(x)
		#define MASTER_TOBE32(x) MASTER_PDP2BE32(x)
		#define MASTER_TOBE64(x) MASTER_PDP2BE64(x)
		
		#define MASTER_TOPDP16(x) (x)
		#define MASTER_TOPDP32(x) (x)
		#define MASTER_TOPDP64(x) (x)
		
		//#define MASTER_FROMLE(x)
		#define MASTER_FROMLE16(x) MASTER_L2PDPE16(x)
		#define MASTER_FROMLE32(x) MASTER_L2PDPE32(x)
		#define MASTER_FROMLE64(x) MASTER_L2PDPE64(x)
		
		//#define MASTER_FROMBE(x)
		#define MASTER_FROMBE16(x) MASTER_B2PDPE16(x)
		#define MASTER_FROMBE32(x) MASTER_B2PDPE32(x)
		#define MASTER_FROMBE64(x) MASTER_B2PDPE64(x)
		
		#define MASTER_FROMPDP16(x) (x)
		#define MASTER_FROMPDP32(x) (x)
		#define MASTER_FROMPDP64(x) (x)
		
		#define MASTER_ITERATE_L2H( x ) MASTER_ITERATE_L2H_PDPE(x)
		#define MASTER_ITERATE_H2L( x ) MASTER_ITERATE_H2L_PDPE(x)
		#define MASTER_GLIBE( _min, _max ) MASTER_PDPELOW( _min, _max )
		#define MASTER_GHIBE( _min, _max ) MASTER_PDPEHIGH( _min, _max )
		
	#endif /* MASTER_UNKNOWN_ENDIANNESS */
#else /* #! MASTER_UNKNOWN_ENDIAN - runtime check !# */
/* #! TODO : PDP !# */
	#define MASTER_TOLE(x) ( \
		(MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN) ? (x) : \
		MASTER_BSWAP_GENERIC(x, sizeof(x)) )
	#define MASTER_TOLE16(x) ( \
		(MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN) ? (x) : \
		MASTER_BSWAP16(x) )
	#define MASTER_TOLE32(x) ( \
		(MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN ? (x) : \
		MASTER_BSWAP32(x) )
	#define MASTER_TOLE64(x) ( \
		(MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN ? (x) : \
		MASTER_BSWAP64(x) )
	
	#define MASTER_TOBE(x) ( \
		(MASTER_ENDIANNESS == MASTER_BIG_ENDIAN) ? (x) : \
		MASTER_BSWAP_GENERIC(x, sizeof(x)) )
	#define MASTER_TOBE16(x) ( \
		(MASTER_ENDIANNESS == MASTER_BIG_ENDIAN) ? (x) : \
		MASTER_BSWAP16(x) )
	#define MASTER_TOBE32(x) ( \
		(MASTER_ENDIANNESS == MASTER_BIG_ENDIAN) ? (x) : \
		MASTER_BSWAP32(x) )
	#define MASTER_TOBE64(x) ( \
		(MASTER_ENDIANNESS == MASTER_BIG_ENDIAN) ? (x) : \
		MASTER_BSWAP64(x) )
	
	#define MASTER_TOPDP16(x) ( \
		(MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN) ? ( MASTER_BSWAP16(x) ) : \
		(MASTER_ENDIANNESS == MASTER_BIG_ENDIAN) ? ( (x) ) : \
		(x) )
	#define MASTER_TOPDP32(x) ( \
		(MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN) ? ( (((x) >> 8) & 0x00FF00FF) | (((x) << 8) & 0xFF00FF00) ) : \
		(MASTER_ENDIANNESS == MASTER_BIG_ENDIAN) ? ( (((x) >> 8) & 0x00FF00FF) | (((x) << 8) & 0xFF00FF00) ) : \
		(x) )
	
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

/* #! MASTER Integers Values !# */

#define MASTER_SI4_POSTFIX_C( x ) x##L
#define MASTER_UI4_POSTFIX_C( x ) x##UL

#define MASTER_SI1_MAX (SI1)0x7F
#define MASTER_SI1_MIN (SI1)0x80
#define MASTER_SI2_MAX (SI2)0x7FFF
#define MASTER_SI2_MIN (SI2)0x8000
#define MASTER_SI4_MAX (SI4)MASTER_SI4_POSTFIX_C(0x7FFFFFFF)
#define MASTER_SI4_MIN (SI4)MASTER_SI4_POSTFIX_C(0x80000000)

#define MASTER_UI1_MAX (UI1)0xFF
#define MASTER_UI1_MIN (UI1)0
#define MASTER_UI2_MAX (UI2)0xFFFF
#define MASTER_UI2_MIN (UI2)0
#define MASTER_UI4_MAX (UI4)MASTER_UI4_POSTFIX_C(0xFFFFFFFF)
#define MASTER_UI4_MIN (UI4)MASTER_UI4_POSTFIX_C(0)

#define MASTER_UI1_BITS (sizeof(UI1) << 3)
#define MASTER_UI2_BITS (sizeof(UI2) << 3)
#define MASTER_UI4_BITS (sizeof(UI4) << 3)

#define MASTER_SI1_BITS (sizeof(SI1) << 3)
#define MASTER_SI2_BITS (sizeof(SI2) << 3)
#define MASTER_SI4_BITS (sizeof(SI4) << 3)

#define MASTER_MAXINT_BITS (sizeof(MASTER_maxint) << 3)

#if MASTER_64_AVAILABLE == 1
	#define MASTER_SI8_POSTFIX_C( x ) x##LL
	#define MASTER_UI8_POSTFIX_C( x ) x##ULL
	#define MASTER_SI8_MAX (SI8)MASTER_SI8_POSTFIX_C(0x7FFFFFFFFFFFFFFF)
	#define MASTER_SI8_MIN (SI8)MASTER_SI8_POSTFIX_C(0x8000000000000000)
	#define MASTER_UI8_MAX (UI8)MASTER_UI8_POSTFIX_C(0xFFFFFFFFFFFFFFFF)
	#define MASTER_UI8_MIN (UI8)MASTER_UI8_POSTFIX_C(0)
	#define MASTER_UI8_BITS (sizeof(UI8) << 3)
	#define MASTER_SI8_BITS (sizeof(SI8) << 3)

#endif /* #! MASTER_64_AVAILABLE !# */

/* #! MASTER Saturation Functions !# */

#define MASTER_SaturateSI1( x ) (SI1)((x) < -128 ? -128 : (x) > 127 ? 127 : (x))
#define MASTER_SaturateSI2( x ) (SI2)((x) < -32768 ? -32768 : (x) > 32767 ? 32767 : (x))
#define MASTER_SaturateSI4( x ) (SI4)((x) < -2147483648 ? -2147483648 : (x) > 2147483647 ? 2147483647 : (x))
#define MASTER_SaturateUI1( x ) (UI1)((x) < 0 ? 0 : (x > 255) ? 255 : (x))
#define MASTER_SaturateUI2( x ) (UI2)((x) < 0 ? 0 : (x > 65535) ? 65535 : (x))
#define MASTER_SaturateUI4( x ) (UI1)((x) < 0 ? 0 : (x > 4294967295) ? 4294967295 : (x))

#define __MASTER_MACROS_DEFINE_AddSaturateSIx( type ) \
type \
MASTER_AddSaturate##type( const type a, const type b ) { \
	const type c = a + b; \
	if (a > 0 && b > 0 && c < 0) return MASTER_##type##_MAX; \
	if (a < 0 && b < 0 && c > 0) return MASTER_##type##_MIN; \
	return c; \
}

#define __MASTER_MACROS_DEFINE_AddSaturateUIx( type ) \
type \
MASTER_AddSaturate##type( const type a, const type b ) { \
	const type c = a + b; \
	if (c < a) return MASTER_##type##_MAX; \
	return c; \
}

#define __MASTER_MACROS_DEFINE_SubSaturateSIx( type ) \
type \
MASTER_SubSaturate##type( const type a, const type b ) { \
	const type c = a - b; \
	if (a >= 0 && b < 0 && c < 0) return MASTER_##type##_MAX; \
	if (a < 0 && b > 0 && c > 0) return MASTER_##type##_MIN; \
	return c; \
}

#define __MASTER_MACROS_DEFINE_SubSaturateUIx( type ) \
type \
MASTER_SubSaturate##type( const type a, const type b ) { \
	const type c = a - b; \
	if (c > a) return MASTER_##type##_MIN; \
	return c; \
}

#define __MASTER_MACROS_DEFINE_MulSaturateSIx( type ) \
type \
MASTER_MulSaturate##type( const type a, const type b ) { \
	const type c = a * b; \
	return (b != 0 && c / b != a) ? ( ((a > 0) == (b > 0)) ? MASTER_##type##_MAX : MASTER_##type##_MIN ) : c; \
}

#define __MASTER_MACROS_DEFINE_MulSaturateUIx( type ) \
type \
MASTER_MulSaturate##type( const type a, const type b ) { \
	const type c = a * b; \
	if (b != 0 && c / b != a) return MASTER_##type##_MAX; \
	return c; \
}

__MASTER_MACROS_DEFINE_AddSaturateSIx( SI1 )
__MASTER_MACROS_DEFINE_AddSaturateSIx( SI2 )
__MASTER_MACROS_DEFINE_AddSaturateSIx( SI4 )
#if MASTER_64_AVAILABLE == 1
	__MASTER_MACROS_DEFINE_AddSaturateSIx( SI8 )
#endif /* #! MASTER_64_AVAILABLE !# */

__MASTER_MACROS_DEFINE_SubSaturateSIx( SI1 )
__MASTER_MACROS_DEFINE_SubSaturateSIx( SI2 )
__MASTER_MACROS_DEFINE_SubSaturateSIx( SI4 )
#if MASTER_64_AVAILABLE == 1
	__MASTER_MACROS_DEFINE_SubSaturateSIx( SI8 )
#endif /* #! MASTER_64_AVAILABLE !# */

__MASTER_MACROS_DEFINE_MulSaturateSIx( SI1 )
__MASTER_MACROS_DEFINE_MulSaturateSIx( SI2 )
__MASTER_MACROS_DEFINE_MulSaturateSIx( SI4 )
#if MASTER_64_AVAILABLE == 1
	__MASTER_MACROS_DEFINE_MulSaturateSIx( SI8 )
#endif /* #! MASTER_64_AVAILABLE !# */

__MASTER_MACROS_DEFINE_AddSaturateUIx( UI1 )
__MASTER_MACROS_DEFINE_AddSaturateUIx( UI2 )
__MASTER_MACROS_DEFINE_AddSaturateUIx( UI4 )
#if MASTER_64_AVAILABLE == 1
	__MASTER_MACROS_DEFINE_AddSaturateUIx( UI8 )
#endif /* #! MASTER_64_AVAILABLE !# */

__MASTER_MACROS_DEFINE_SubSaturateUIx( UI1 )
__MASTER_MACROS_DEFINE_SubSaturateUIx( UI2 )
__MASTER_MACROS_DEFINE_SubSaturateUIx( UI4 )
#if MASTER_64_AVAILABLE == 1
	__MASTER_MACROS_DEFINE_SubSaturateUIx( UI8 )
#endif /* #! MASTER_64_AVAILABLE !# */

__MASTER_MACROS_DEFINE_MulSaturateUIx( UI1 )
__MASTER_MACROS_DEFINE_MulSaturateUIx( UI2 )
__MASTER_MACROS_DEFINE_MulSaturateUIx( UI4 )
#if MASTER_64_AVAILABLE == 1
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

/* #! MASTER Libraries States !# */

#define MASTER_LIBRARY_UNAVAILABLE 0
#define MASTER_LIBRARY_INDEV 1
#define MASTER_LIBRARY_TESTING 2
#define MASTER_LIBRARY_AVAILABLE 3
#define MASTER_LIBRARY_COMPLETED 4
#define MASTER_LIBRARY_DEPRECATED 5

/* #! MASTER Function Markers !# */

#define MASTER_MARKER_COMPRESSION
#define MASTER_MARKER_CRYPTOGRAPHY
#define MASTER_MARKER_MATH

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

#define MASTER_MARKER_GENERABLE

#define MASTER_MARKER_ONLY_FOR( comment )

#define MASTER_MARKER_NOT_DOCUMENTED
#define MASTER_MARKER_DOCUMENTED( docpath )

/* #! Next macros i will use only when at least someone asked !# */
#define MASTER_MARKER_WIKIPEDIA_SOURCE( wikipath )

#endif /* __MASTER_CODE_STYLE_INCLUDE_H__ */

/* #! be master~ !# */
