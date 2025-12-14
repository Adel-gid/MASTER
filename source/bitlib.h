
/*
 * Copyright (c) 2025 Adel'gid Aragami
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

/* #! FSM !# */

typedef struct {
	const UI1 *data;
	UI4 available;
	UI4 value;
	UI1 value_bits;
} MASTER_BitStream;

UI1
MASTER_BitStream_Grant( MASTER_BitStream * const stream, UI1 bits ) {
	if (!stream || !stream->data || bits > 32) return 0;
	while (stream->value_bits < bits && stream->available > 0) {
		stream->value |= *(stream->data) << stream->value_bits;
		stream->value_bits += 8;
		stream->data += 1;
		stream->available -= 1;
	}
	return stream->value_bits >= bits;
}

UI4
MASTER_BitStream_Peek( MASTER_BitStream * const stream, UI1 bits ) {
	if (!stream || !stream->data || bits > 32) return 0;
	return (bits == 32) ? (stream->value) : (stream->value & ((1 << bits) - 1));
}

void
MASTER_BitStream_Flush( MASTER_BitStream * const stream, UI1 bits ) {
	if (!stream || !stream->data) return;
	if (bits >= 32) stream->value = 0;
	else stream->value >>= bits;
	if ((SI1)(stream->value_bits -= bits) < 0)
		stream->value_bits = 0;
}

void
MASTER_BitStream_ByteAlign( MASTER_BitStream * const stream ) {
	if (!stream || !stream->data)
		return;
	stream->value >>= stream->value_bits & 7;
	stream->value_bits &= ~7;
}

#endif /* #! __MASTER_BITLIB_INCLUDE_H__ !# */

/* #! be master !# */
