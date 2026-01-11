
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_ABSTRACT_INCLUDE_H__
#define __MASTER_ABSTRACT_INCLUDE_H__

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

/* #! Bit Stream !# */

typedef struct {
	const UI1 * data;
	UI4 available;
	UI4 value;
	UI1 value_bits;
} MASTER_BitStream;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_BitStream_Grant, ( MASTER_BitStream * const, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_BitStream_Peek, ( MASTER_BitStream * const, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_BitStream_Flush, ( MASTER_BitStream * const, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_BitStream_ByteAlign, ( MASTER_BitStream * const ) );

UI1
MASTER_BitStream_Grant( MASTER_BitStream * const stream, const UI1 bits ) {
	if (stream == nul || stream->data == nul || bits > 32) return 0;
	while (stream->value_bits < bits && stream->available > 0) {
		stream->value |= *(stream->data) << stream->value_bits;
		stream->value_bits += 8;
		stream->data += 1;
		stream->available -= 1;
	}
	return stream->value_bits >= bits;
}

UI4
MASTER_BitStream_Peek( MASTER_BitStream * const stream, const UI1 bits ) {
	if (stream == nul || stream->data == nul || bits > 32) return 0;
	return (bits == 32) ? (stream->value) : (stream->value & ((1 << bits) - 1));
}

void
MASTER_BitStream_Flush( MASTER_BitStream * const stream, const UI1 bits ) {
	if (stream == nul || stream->data == nul) return;
	if (bits >= 32) stream->value = 0;
	else stream->value >>= bits;
	if ((SI1)(stream->value_bits -= bits) < 0)
		stream->value_bits = 0;
}

void
MASTER_BitStream_ByteAlign( MASTER_BitStream * const stream ) {
	if (stream == nul || stream->data == nul) return;
	stream->value >>= stream->value_bits & 7;
	stream->value_bits &= ~7;
}

/* #! Byte Stack !# */

typedef struct {
	UI1 * byte_buffer;
	UI4 buffer_capacity;
	UI4 buffer_position;
} MASTER_ByteStack;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_ByteStack_Init, ( MASTER_ByteStack * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_ByteStack, MASTER_ByteStack_Create, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_ByteStack_Flush, ( MASTER_ByteStack * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_ByteStack_Free, ( MASTER_ByteStack * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_ByteStack_AddByte, ( MASTER_ByteStack * const, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_ByteStack_PopByte, ( MASTER_ByteStack * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_ByteStack_PopBytes, ( MASTER_ByteStack * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_ByteStack_PeekByte, ( MASTER_ByteStack * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_ByteStack_IsEmpty, ( MASTER_ByteStack * const ) );

void
MASTER_ByteStack_Init( MASTER_ByteStack * const bstack, const UI4 capacity ) {
	if (bstack == nul) return;
	bstack->byte_buffer = (UI1 *)MASTER_MALLOC(capacity);
	bstack->buffer_capacity = capacity;
	bstack->buffer_position = 0;
}

MASTER_ByteStack
MASTER_ByteStack_Create( const UI4 capacity ) {
	MASTER_ByteStack bstack;
	MASTER_ByteStack_Init(&bstack, capacity);
	return bstack;
}

void
MASTER_ByteStack_Flush( MASTER_ByteStack * const bstack ) {
	if (bstack == nul) return;
	bstack->buffer_position = 0;
}

void
MASTER_ByteStack_Free( MASTER_ByteStack * const bstack ) {
	if (bstack == nul) return;
	MASTER_FREE(bstack->byte_buffer);
}

UI1
MASTER_ByteStack_AddByte( MASTER_ByteStack * const bstack, const UI1 value ) {
	if (bstack == nul) return MASTER_ERROR;
	if (bstack->buffer_position >= bstack->buffer_capacity) {
		bstack->buffer_capacity <<= 1;
		bstack->byte_buffer = (UI1 *)MASTER_REALLOC(bstack->byte_buffer, bstack->buffer_capacity);
	}
	bstack->byte_buffer[bstack->buffer_position] = value;
	bstack->buffer_position += 1;
	return MASTER_NO_ERROR;
}

UI1
MASTER_ByteStack_PopByte( MASTER_ByteStack * const bstack ) {
	if (bstack == nul || bstack->buffer_position == 0) return MASTER_ERROR;
	bstack->buffer_position -= 1;
	return MASTER_NO_ERROR;
}

UI1
MASTER_ByteStack_PopBytes( MASTER_ByteStack * const bstack, const UI4 count ) {
	if (bstack == nul || bstack->buffer_position < count) return MASTER_ERROR;
	bstack->buffer_position -= count;
	return MASTER_NO_ERROR;
}

UI1
MASTER_ByteStack_PeekByte( MASTER_ByteStack * const bstack, const UI4 offset ) {
	if (bstack == nul || offset + 1 > bstack->buffer_position) return 0;
	return bstack->byte_buffer[bstack->buffer_position - offset - 1];
}

UI1
MASTER_ByteStack_IsEmpty( MASTER_ByteStack * const bstack ) {
	if (bstack == nul) return 0;
	return bstack->buffer_position == 0;
}

/* #! Monotonic Stack !# */

#define MASTER_MONOTONICSTACK_DECREASING 0
#define MASTER_MONOTONICSTACK_INCREASING 1

typedef struct {
	void * buffer;
	UI4 buffer_capacity;
	UI4 buffer_element_size;
	UI4 buffer_position;
	UI1 monotone_type;
} MASTER_MonotonicStack;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_MonotonicStack_Init, ( MASTER_MonotonicStack * const, const UI4, const UI4, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_MonotonicStack, MASTER_MonotonicStack_Create, ( const UI4, const UI4, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_MonotonicStack_Flush, ( MASTER_MonotonicStack * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_MonotonicStack_Free, ( MASTER_MonotonicStack * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_MonotonicStack_Pop, ( MASTER_MonotonicStack * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_MonotonicStack_Insert, ( MASTER_MonotonicStack * const, const void * ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_MonotonicStack_Peek, ( MASTER_MonotonicStack * const, const UI4, void * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_MonotonicStack_IsEmpty, ( MASTER_MonotonicStack * const ) );

void
MASTER_MonotonicStack_Init( MASTER_MonotonicStack * const mstack, const UI4 capacity, const UI4 element_size, const UI1 monotone_type ) {
	if (mstack == nul) return;
	mstack->buffer = (UT *)MASTER_MALLOC(capacity * element_size);
	mstack->buffer_capacity = capacity;
	mstack->buffer_element_size = element_size;
	mstack->buffer_position = 0;
	mstack->monotone_type = monotone_type;
}

MASTER_MonotonicStack
MASTER_MonotonicStack_Create( const UI4 capacity, const UI4 element_size, const UI1 monotone_type ) {
	MASTER_MonotonicStack mstack;
	mstack.buffer = nul;
	MASTER_MonotonicStack_Init(&mstack, capacity, element_size, monotone_type);
	return mstack;
}

void
MASTER_MonotonicStack_Flush( MASTER_MonotonicStack * const mstack ) {
	if (mstack == nul) return;
	mstack->buffer_position = 0;
}

void
MASTER_MonotonicStack_Free( MASTER_MonotonicStack * const mstack ) {
	if (mstack == nul) return;
	MASTER_FREE(mstack->buffer);
}

UI1
MASTER_MonotonicStack_Pop( MASTER_MonotonicStack * const mstack ) {
	if (mstack == nul || mstack->buffer_position == 0) return MASTER_ERROR;
	mstack->buffer_position -= 1;
	return MASTER_NO_ERROR;
}

UI1
MASTER_MonotonicStack_Insert( MASTER_MonotonicStack * const mstack, const void * value ) {
	if (mstack == nul) return MASTER_ERROR;
	/* #! Unoptimized !# */
	while (mstack->buffer_position > 0 && 
		   MASTER_MEMCMP((UI1 *)mstack->buffer + (mstack->buffer_position - 1) * mstack->buffer_element_size, (const UI1 *)value, mstack->buffer_element_size) *
		   ((mstack->monotone_type == MASTER_MONOTONICSTACK_INCREASING) ? (-1) : (+1)) <= 0)
		mstack->buffer_position -= 1;
	if (mstack->buffer_position >= mstack->buffer_capacity) {
		mstack->buffer_capacity <<= 1;
		mstack->buffer = (UT *)MASTER_REALLOC(mstack->buffer, mstack->buffer_capacity * mstack->buffer_element_size);
	}
	MASTER_MEMCPY((UI1 *)mstack->buffer + mstack->buffer_position * mstack->buffer_element_size, (const UI1 *)value, mstack->buffer_element_size);
	mstack->buffer_position += 1;
	return MASTER_NO_ERROR;
}

UI1
MASTER_MonotonicStack_Peek( MASTER_MonotonicStack * const mstack, const UI4 offset, void * const output_value ) {
	if (mstack == nul || offset + 1 > mstack->buffer_position) return MASTER_ERROR;
	MASTER_MEMCPY((UI1 *)output_value, (UI1 *)mstack->buffer + (mstack->buffer_position - offset - 1) * mstack->buffer_element_size, mstack->buffer_element_size);
	return MASTER_NO_ERROR;
}

UI1
MASTER_MonotonicStack_IsEmpty( MASTER_MonotonicStack * const mstack ) {
	if (mstack == nul) return 0;
	return mstack->buffer_position == 0;
}

/* #! Ring Buffer !# */

typedef struct {
	UI1 * pointer;
	UI4 size;
	UI4 source;
} MASTER_RingBuffer;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuffer_Flush, ( MASTER_RingBuffer * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuffer_Init, ( MASTER_RingBuffer * const, UI1 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_RingBuffer, MASTER_RingBuffer_Create, ( UI1 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuffer_AddByte, ( MASTER_RingBuffer * const, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuffer_AddBytes, ( MASTER_RingBuffer * const, const UI1 * bytes, UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuffer_FlushByte, ( MASTER_RingBuffer * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuffer_FlushBytes, ( MASTER_RingBuffer * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuffer_CopyBytes, ( MASTER_RingBuffer * const, UI1 *, UI4, UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuf_CopyAndUpdateBytes, ( MASTER_RingBuffer * const, UI1 *, const UI4, UI4 ) );

void
MASTER_RingBuffer_Flush( MASTER_RingBuffer * const ringbuf ) {
	if (ringbuf == nul) return;
	ringbuf->pointer = nul;
	ringbuf->size = 0;
	ringbuf->source = 0;
}

void
MASTER_RingBuffer_Init( MASTER_RingBuffer * const ringbuf, UI1 * const pointer, const UI4 size ) {
	if (ringbuf == nul) return;
	ringbuf->pointer = pointer;
	ringbuf->size = size;
	ringbuf->source = 0;
}

MASTER_RingBuffer
MASTER_RingBuffer_Create( UI1 * const pointer, const UI4 size ) {
	MASTER_RingBuffer ringbuf;
	MASTER_RingBuffer_Init(&ringbuf, pointer, size);
	return ringbuf;
}

void
MASTER_RingBuffer_AddByte( MASTER_RingBuffer * const ringbuf, const UI1 byte ) {
	if (ringbuf == nul || ringbuf->pointer == nul) return;
	ringbuf->pointer[ringbuf->source] = byte;
	ringbuf->source = (ringbuf->source + 1) % ringbuf->size;
}

/* #! Unoptimized !# */
void
MASTER_RingBuffer_AddBytes( MASTER_RingBuffer * const ringbuf, const UI1 * bytes, UI4 length ) {
	UI4 range;
	UI4 end_pos;
	if (ringbuf == nul || ringbuf->pointer == nul) return;
	while (length > 0) {
		range = MASTER_MIN(ringbuf->size, length);
		
		end_pos = (ringbuf->source + range) % ringbuf->size;
		
		if (ringbuf->source + range > ringbuf->size) {
			MASTER_MEMCPY(ringbuf->pointer + ringbuf->source, bytes, ringbuf->size - ringbuf->source);
			MASTER_MEMCPY(ringbuf->pointer, bytes + ringbuf->size - ringbuf->source, end_pos);
		} else MASTER_MEMCPY(ringbuf->pointer + ringbuf->source, bytes, range);
		
		length -= range;
		bytes += range;
		ringbuf->source = end_pos;
	}
}

void
MASTER_RingBuffer_FlushByte( MASTER_RingBuffer * const ringbuf ) {
	if (ringbuf == nul || ringbuf->pointer == nul) return;
	ringbuf->source = (ringbuf->source + ringbuf->size - 1) % ringbuf->size;
	ringbuf->pointer[ringbuf->source] = 0;
}

/* #! Hyper unoptimized !# */
void
MASTER_RingBuffer_FlushBytes( MASTER_RingBuffer * const ringbuf, const UI4 count ) {
	UI4 index = 0;
	if (ringbuf == nul || ringbuf->pointer == nul) return;
	for (; index < count; index += 1)
		MASTER_RingBuffer_FlushByte(ringbuf);
}

void
MASTER_RingBuffer_CopyBytes( MASTER_RingBuffer * const ringbuf, UI1 * output, UI4 offset, UI4 length ) {
	UI4 range;
	UI4 begin_pos;
	UI4 end_pos;
	if (ringbuf == nul || ringbuf->pointer == nul) return;
	offset %= ringbuf->size;
	begin_pos = (ringbuf->source + ringbuf->size - offset) % ringbuf->size;
	while (length >= ringbuf->size) {
		MASTER_MEMCPY(output, ringbuf->pointer + begin_pos, ringbuf->size - begin_pos);
		MASTER_MEMCPY(output + ringbuf->size - begin_pos, ringbuf->pointer, ringbuf->source);
		length -= ringbuf->size;
		output += ringbuf->size;
	}
	while (length > 0) {
		range = MASTER_MIN(length, offset);
		
		end_pos = (begin_pos + range) % ringbuf->size;
		if (begin_pos + range > ringbuf->size) {
			MASTER_MEMCPY(output, ringbuf->pointer + begin_pos, ringbuf->size - begin_pos);
			MASTER_MEMCPY(output + ringbuf->size - begin_pos, ringbuf->pointer, end_pos);
		} else MASTER_MEMCPY(output, ringbuf->pointer + begin_pos, range);
		
		length -= range;
		output += range;
	}
}

void
MASTER_RingBuf_CopyAndUpdateBytes( MASTER_RingBuffer * const ringbuf, UI1 * output, const UI4 offset, UI4 length ) {
	if (ringbuf == nul || ringbuf->pointer == nul) return;
	MASTER_RingBuffer_CopyBytes(ringbuf, output, offset, length);
	MASTER_RingBuffer_AddBytes(ringbuf, output, length);
}

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_ABSTRACT_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_ABSTRACT_INCLUDE_H__ !# */

/* #! be master~ !# */
