
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_ABSTRACT_INCLUDE_H__
#define __MASTER_ABSTRACT_INCLUDE_H__

#include <master_enum.h>

/* #! Byte Stack !# */


typedef struct {
	UI1 * byte_buffer;
	UI4 buffer_capacity;
	UI4 buffer_position;
} MASTER_ByteStack;

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

/* #! Ring Buffer !# */

typedef struct {
	UI1 * pointer;
	UI4 size;
	UI4 source;
} MASTER_RingBuffer;

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


#endif /* #! __MASTER_ABSTRACT_INCLUDE_H__ !# */

/* #! be master~ !# */
