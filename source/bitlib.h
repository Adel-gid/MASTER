
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_BITLIB_INCLUDE_H__
#define __MASTER_BITLIB_INCLUDE_H__

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Bit_ReverseIncrement, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Bit_ReverseIncrementFrom, ( const UI4, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Bit_Mirror, ( const UI4, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Bit_Mirror1, ( const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_Bit_Mirror2, ( const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Bit_Mirror4, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Bit_CountOnes4, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Bit_IsParity4, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Bit_Smear1, ( const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_Bit_Smear2, ( const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Bit_Smear4, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Bit_Bitlen1, ( const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_Bit_Bitlen2, ( const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Bit_Bitlen4, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_BIT_POW2ROUND1, ( const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_BIT_POW2ROUND2, ( const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_BIT_POW2ROUND4, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_BIT_LOG2ROUND1, ( const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_BIT_LOG2ROUND2, ( const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_BIT_LOG2ROUND4, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_BIT_LOG2MATHROUND1, ( const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_BIT_LOG2MATHROUND2, ( const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_BIT_LOG2MATHROUND4, ( const UI4 ) );
#if MASTER_64_AVAILABLE == 1
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_Bit_Smear8, ( const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_Bit_Bitlen8, ( const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_BIT_POW2ROUND8, ( const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_BIT_LOG2ROUND8, ( const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_BIT_LOG2MATHROUND8, ( const UI8 ) );
#endif /* #! 64 Bits !# */

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_ReverseIncrement /* ! */,
	UI4,
	( const UI4, value )
) {
	UI4 iterator = 0x80000000;
	while (!(value & iterator) && iterator)
		iterator >>= 1;
	while (value & iterator)
		iterator >>= 1;
	return (iterator == 0) ? (0) : ((value & (iterator - 1)) + iterator);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_ReverseIncrementFrom /* ! */,
	UI4,
	( const UI4, value ),
	( const UI1, startbit )
) {
	UI4 iterator = 1 << startbit;
	while (value & iterator)
		iterator >>= 1;
	return (iterator == 0) ? (0) : ((value & (iterator - 1)) + iterator);
}

/* #! Mirror !# */

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_Mirror /* ! */,
	UI4,
	( UI4, phrase ),
	( UI1, width )
) {
	UI4 out = 0;
	for (; width > 0; width -= 1) {
		out <<= 1;
		out |= phrase & 1;
		phrase >>= 1;
	}
	return out;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_Mirror1 /* ! */,
	UI1,
	( UI1, symbol )
) {
	symbol = ((symbol & 0xAA) >> 1) | ((symbol & 0x55) << 1);
	symbol = ((symbol & 0xCC) >> 2) | ((symbol & 0x33) << 2);
	symbol = (symbol >> 4) | (symbol << 4);
	return symbol;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_Mirror2 /* ! */,
	UI2,
	( UI2, word )
) {
	word = ((word & 0xAAAA) >> 1) | ((word & 0x5555) << 1);
	word = ((word & 0xCCCC) >> 2) | ((word & 0x3333) << 2);
	word = ((word & 0xF0F0) >> 4) | ((word & 0x0F0F) << 4);
	word = (word >> 8) | (word << 8);
	return word;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_Mirror4 /* ! */,
	UI4,
	( UI4, phrase )
) {
	phrase = ((phrase & MASTER_UI4_POSTFIX_C(0xAAAAAAAA)) >> 1) | ((phrase & MASTER_UI4_POSTFIX_C(0x55555555)) << 1);
	phrase = ((phrase & MASTER_UI4_POSTFIX_C(0xCCCCCCCC)) >> 2) | ((phrase & MASTER_UI4_POSTFIX_C(0x33333333)) << 2);
	phrase = ((phrase & MASTER_UI4_POSTFIX_C(0xF0F0F0F0)) >> 4) | ((phrase & MASTER_UI4_POSTFIX_C(0x0F0F0F0F)) << 4);
	phrase = ((phrase & MASTER_UI4_POSTFIX_C(0xFF00FF00)) >> 8) | ((phrase & MASTER_UI4_POSTFIX_C(0x00FF00FF)) << 8);
	phrase = (phrase >> 16) | (phrase << 16);
	return phrase;
}

#ifdef MASTER_USE_OPTIMIZED_COUNTING_ALGORITHM
#	define MASTER_BIT_BITCOUNT2( value ) (value), (value) + 1, (value) + 1, (value) + 2
#	define MASTER_BIT_BITCOUNT4( value ) MASTER_BIT_BITCOUNT2(value), MASTER_BIT_BITCOUNT2((value) + 1), MASTER_BIT_BITCOUNT2((value) + 1), MASTER_BIT_BITCOUNT2((value) + 2)
#	define MASTER_BIT_BITCOUNT6( value ) MASTER_BIT_BITCOUNT4(value), MASTER_BIT_BITCOUNT4((value) + 1), MASTER_BIT_BITCOUNT4((value) + 1), MASTER_BIT_BITCOUNT4((value) + 2)
	const UI1 MASTER_Bit_BitsSetTable[256] = {
		MASTER_BIT_BITCOUNT6(0), MASTER_BIT_BITCOUNT6(1), MASTER_BIT_BITCOUNT6(1), MASTER_BIT_BITCOUNT6(2)
	};
	MASTER_DEFINE_FUNCTION1(
		MASTER_NO_FLAGS,
		MASTER_EMPTY_DESCRIPTION,
		/* ! */ MASTER_Bit_CountOnes4 /* ! */,
		UI4,
		( UI4, phrase )
	) {
		return MASTER_Bit_BitsSetTable[phrase & 0xFF] +
			   MASTER_Bit_BitsSetTable[(phrase >> 8) & 0xFF] +
			   MASTER_Bit_BitsSetTable[(phrase >> 16) & 0xFF] +
			   MASTER_Bit_BitsSetTable[phrase >> 24];
	}
#else
	MASTER_DEFINE_FUNCTION1(
		MASTER_NO_FLAGS,
		MASTER_EMPTY_DESCRIPTION,
		/* ! */ MASTER_Bit_CountOnes4 /* ! */,
		UI4,
		( UI4, phrase )
	) {
		phrase = phrase - ((phrase >> 1) & 0x55555555);
		phrase = (phrase & 0x33333333) + ((phrase >> 2) & 0x33333333);
		return ((phrase + ((phrase >> 4) & 0x0F0F0F0F)) * 0x01010101) >> 24;
		/* #!
		UI1 result = 0;
		for (; phrase > 0; phrase >>= 1)
			result += phrase & 1;
		return result;
		!# */
	}
#endif /* #! MASTER_BITLIB_USE_OPTIMIZED_COUNTING_ALGORITHM !# */
MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_IsParity4 /* ! */,
	UI1,
	( UI4, phrase )
) {
	phrase ^= phrase >> 16;
	phrase ^= phrase >> 8;
	phrase ^= phrase >> 4;
	return (0x6996 >> (phrase & 0xF)) & 1;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_Smear1 /* ! */,
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
	/* ! */ MASTER_Bit_Smear2 /* ! */,
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
	/* ! */ MASTER_Bit_Smear4 /* ! */,
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
		/* ! */ MASTER_Bit_Smear8 /* ! */,
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

#define __MASTER_BITLEN_MACROS_PROCESS( value, bitcount, bit_count, cast_type ) do { \
		if ((value) >= ((cast_type)1 << (bit_count))) { \
			(bitcount) += (bit_count); \
			(value) >>= (bit_count); \
		} \
	} while (0)

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_Bitlen1 /* ! */,
	MASTER_PREFER_INLINE UI1,
	( UI1, value )
) {
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, UI4);
	if (value > 0) bitcount += 1;
	return bitcount;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_Bitlen2 /* ! */,
	MASTER_PREFER_INLINE UI2,
	( UI2, value )
) {
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 8, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, UI4);
	if (value > 0) bitcount += 1;
	return bitcount;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Bit_Bitlen4 /* ! */,
	MASTER_PREFER_INLINE UI4,
	( UI4, value )
) {
	UI1 bitcount = 0;
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 16, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 8, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, UI4);
	__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, UI4);
	if (value > 0) bitcount += 1;
	return bitcount;
}

#if MASTER_64_AVAILABLE == 1
	MASTER_DEFINE_FUNCTION1(
		MASTER_NO_FLAGS,
		MASTER_EMPTY_DESCRIPTION,
		/* ! */ MASTER_Bit_Bitlen8 /* ! */,
		MASTER_PREFER_INLINE UI8,
		( UI8, value )
	) {
		UI1 bitcount = 0;
		__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 32, UI8);
		__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 16, UI4);
		__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 8, UI4);
		__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 4, UI4);
		__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 2, UI4);
		__MASTER_BITLEN_MACROS_PROCESS(value, bitcount, 1, UI4);
		if (value > 0) bitcount += 1;
		return bitcount;
	}
#endif /* #! MASTER_64_AVAILABLE !# */

#define MASTER_BIT_POW2FLOOR1( value ) ((MASTER_Bit_Smear1(value) >> 1) + 1)
#define MASTER_BIT_POW2FLOOR2( value ) ((MASTER_Bit_Smear2(value) >> 1) + 1)
#define MASTER_BIT_POW2FLOOR4( value ) ((MASTER_Bit_Smear4(value) >> 1) + 1)
#define MASTER_BIT_POW2CEIL1( value ) (MASTER_Bit_Smear1(value - 1) + 1)
#define MASTER_BIT_POW2CEIL2( value ) (MASTER_Bit_Smear2(value - 1) + 1)
#define MASTER_BIT_POW2CEIL4( value ) (MASTER_Bit_Smear4(value - 1) + 1)
#define MASTER_BIT_LOG2FLOOR1( value ) (MASTER_Bit_Bitlen1(value) - 1)
#define MASTER_BIT_LOG2FLOOR2( value ) (MASTER_Bit_Bitlen2(value) - 1)
#define MASTER_BIT_LOG2FLOOR4( value ) (MASTER_Bit_Bitlen4(value) - 1)
#define MASTER_BIT_LOG2CEIL1( value ) (MASTER_Bit_Bitlen1(value) - MASTER_ISPOW2(value))
#define MASTER_BIT_LOG2CEIL2( value ) (MASTER_Bit_Bitlen2(value) - MASTER_ISPOW2(value))
#define MASTER_BIT_LOG2CEIL4( value ) (MASTER_Bit_Bitlen4(value) - MASTER_ISPOW2(value))

#if MASTER_64_AVAILABLE == 1
#	define MASTER_BIT_POW2FLOOR8( value ) ((MASTER_Bit_Smear8(value) >> 1) + 1)
#	define MASTER_BIT_POW2CEIL8( value ) (MASTER_Bit_Smear8(value - 1) + 1)
#	define MASTER_BIT_LOG2FLOOR8( value ) (MASTER_Bit_Bitlen8(value) - 1)
#	define MASTER_BIT_LOG2CEIL8( value ) (MASTER_Bit_Bitlen8(value) - MASTER_ISPOW2(value))
#endif /* #! MASTER_64_AVAILABLE !# */

#ifdef MASTER_ROUND_FUNCS_INSTEAD_OF_MACROS
#	define MASTER_BIT_POW2ROUND1( value ) (((value) < (MASTER_BIT_POW2FLOOR1(value) | (MASTER_BIT_POW2FLOOR1(value) >> 1))) ? (MASTER_BIT_POW2FLOOR1(value)) : (MASTER_BIT_POW2CEIL1(value)))
#	define MASTER_BIT_POW2ROUND2( value ) (((value) < (MASTER_BIT_POW2FLOOR2(value) | (MASTER_BIT_POW2FLOOR2(value) >> 1))) ? (MASTER_BIT_POW2FLOOR2(value)) : (MASTER_BIT_POW2CEIL2(value)))
#	define MASTER_BIT_POW2ROUND4( value ) (((value) < (MASTER_BIT_POW2FLOOR4(value) | (MASTER_BIT_POW2FLOOR4(value) >> 1))) ? (MASTER_BIT_POW2FLOOR4(value)) : (MASTER_BIT_POW2CEIL4(value)))
#	define MASTER_BIT_LOG2ROUND1( value ) (((value) < (MASTER_BIT_POW2FLOOR1(value) | (MASTER_BIT_POW2FLOOR1(value) >> 1))) ? (MASTER_BIT_LOG2FLOOR1(value)) : (MASTER_BIT_LOG2CEIL1(value)))
#	define MASTER_BIT_LOG2ROUND2( value ) (((value) < (MASTER_BIT_POW2FLOOR2(value) | (MASTER_BIT_POW2FLOOR2(value) >> 1))) ? (MASTER_BIT_LOG2FLOOR2(value)) : (MASTER_BIT_LOG2CEIL2(value)))
#	define MASTER_BIT_LOG2ROUND4( value ) (((value) < (MASTER_BIT_POW2FLOOR4(value) | (MASTER_BIT_POW2FLOOR4(value) >> 1))) ? (MASTER_BIT_LOG2FLOOR4(value)) : (MASTER_BIT_LOG2CEIL4(value)))
#	if MASTER_64_AVAILABLE == 1
#		define MASTER_BIT_POW2ROUND8( value ) (((value) < (MASTER_BIT_POW2FLOOR8(value) | (MASTER_BIT_POW2FLOOR8(value) >> 1))) ? (MASTER_BIT_POW2FLOOR8(value)) : (MASTER_BIT_POW2CEIL8(value)))
#		define MASTER_BIT_LOG2ROUND8( value ) (((value) < (MASTER_BIT_POW2FLOOR8(value) | (MASTER_BIT_POW2FLOOR8(value) >> 1))) ? (MASTER_BIT_LOG2FLOOR8(value)) : (MASTER_BIT_LOG2CEIL8(value)))
#	endif /* #! MASTER_64_AVAILABLE !# */
#else
#	define __MASTER_BIT_POW2ROUNDX_GENERATE_MACRO( suffix ) \
		MASTER_DEFINE_FUNCTION1( \
			MASTER_NO_FLAGS, \
			MASTER_EMPTY_DESCRIPTION, \
			/* ! */ MASTER_BIT_POW2ROUND ## suffix /* ! */, \
			MASTER_PREFER_INLINE UI ## suffix, \
			( UI ## suffix, value ) \
		) { \
			UI ## suffix floored = MASTER_BIT_POW2FLOOR ## suffix(value); \
			floored |= floored >> 1; \
			if (value < floored) return floored & (floored << 1); \
			return MASTER_BIT_POW2CEIL ## suffix(value); \
		}
#	define __MASTER_BIT_LOG2ROUNDX_GENERATE_MACRO( suffix, numsuff ) \
		MASTER_DEFINE_FUNCTION1( \
			MASTER_NO_FLAGS, \
			MASTER_EMPTY_DESCRIPTION, \
			/* ! */ MASTER_BIT_LOG2ROUND ## suffix /* ! */, \
			MASTER_PREFER_INLINE UI ## suffix, \
			( UI ## suffix, value ) \
		) { \
			const UI1 bits = MASTER_BIT_LOG2FLOOR ## suffix(value); \
			UI ## suffix floored = 1 ## numsuff << bits; \
			if (value <= 1) return value - 1; \
			floored |= floored >> 1; \
			return bits + (value >= floored); \
		}
		__MASTER_BIT_POW2ROUNDX_GENERATE_MACRO( 1 )
		__MASTER_BIT_POW2ROUNDX_GENERATE_MACRO( 2 )
		__MASTER_BIT_POW2ROUNDX_GENERATE_MACRO( 4 )
		__MASTER_BIT_LOG2ROUNDX_GENERATE_MACRO( 1, U )
		__MASTER_BIT_LOG2ROUNDX_GENERATE_MACRO( 2, U )
		__MASTER_BIT_LOG2ROUNDX_GENERATE_MACRO( 4, U )
#		if MASTER_64_AVAILABLE == 1
			__MASTER_BIT_POW2ROUNDX_GENERATE_MACRO( 8 )
			__MASTER_BIT_LOG2ROUNDX_GENERATE_MACRO( 8, L )
#		endif /* #! MASTER_64_AVAILABLE !# */
#	undef __MASTER_BIT_POW2ROUNDX_GENERATE_MACRO
#	undef __MASTER_BIT_LOG2ROUNDX_GENERATE_MACRO
#endif /* #! MASTER_ROUND_FUNCS_INSTEAD_OF_MACROS !# */

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_BIT_LOG2MATHROUND1 /* ! */,
	MASTER_PREFER_INLINE UI1,
	( UI1, value )
) {
	if (value >= 0xB6) return 8;
	if (value >= 0x5B) return 7;
	if (value >= 0x2E) return 6;
	if (value >= 0x17) return 5;
	if (value >= 0xC) return 4;
	if (value >= 0x6) return 3;
	if (value >= 0x3) return 2;
	return value - 1;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_BIT_LOG2MATHROUND2 /* ! */,
	MASTER_PREFER_INLINE UI1,
	( UI2, value )
) {
	if (value >= 0xB505) return 16;
	if (value >= 0x5A83) return 15;
	if (value >= 0x2D42) return 14;
	if (value >= 0x16A1) return 13;
	if (value >= 0xB51) return 12;
	if (value >= 0x5A9) return 11;
	if (value >= 0x2D5) return 10;
	if (value >= 0x16B) return 9;
	return MASTER_BIT_LOG2MATHROUND1(value);
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_BIT_LOG2MATHROUND4 /* ! */,
	MASTER_PREFER_INLINE UI1,
	( UI4, value )
) {
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
	return MASTER_BIT_LOG2MATHROUND2(value);
}

#if MASTER_64_AVAILABLE == 1
	MASTER_DEFINE_FUNCTION1(
		MASTER_NO_FLAGS,
		MASTER_EMPTY_DESCRIPTION,
		/* ! */ MASTER_BIT_LOG2MATHROUND8 /* ! */,
		MASTER_PREFER_INLINE UI1,
		( UI8, value )
	) {
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
		return MASTER_BIT_LOG2MATHROUND4(value);
	}
#endif /* #! MASTER_64_AVAILABLE !# */

#define MASTER_BIT_POW2MATHROUND1( value ) (1 << MASTER_BIT_LOG2MATHROUND1(value))
#define MASTER_BIT_POW2MATHROUND2( value ) (1 << MASTER_BIT_LOG2MATHROUND2(value))
#define MASTER_BIT_POW2MATHROUND4( value ) (1 << MASTER_BIT_LOG2MATHROUND4(value))
#if MASTER_64_AVAILABLE == 1
#	define MASTER_BIT_POW2MATHROUND8( value ) (1L << MASTER_BIT_LOG2MATHROUND8(value))
#endif /* #! MASTER_64_AVAILABLE !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_BITLIB_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_BITLIB_INCLUDE_H__ !# */

/* #! be master !# */
