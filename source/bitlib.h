
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_BITLIB_INCLUDE_H__
#define __MASTER_BITLIB_INCLUDE_H__

#include <master_enum.h>

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

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_BITLIB_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_BITLIB_INCLUDE_H__ !# */

/* #! be master !# */
