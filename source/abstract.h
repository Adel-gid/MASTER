
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_ABSTRACT_INCLUDE_H
#define MASTER_zRIVATE_ABSTRACT_INCLUDE_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#ifdef MASTER_ABSTRACT_EXTERN_ONLY
#	define MASTER_ABSTRACT_BIT_STREAM_IMPLEMENT 0
#	define MASTER_ABSTRACT_BYTE_STACK_IMPLEMENT 0
#	define MASTER_ABSTRACT_MONOTONIC_STACK_IMPLEMENT 0
#	define MASTER_ABSTRACT_RING_BUFFER_IMPLEMENT 0
#	define MASTER_ABSTRACT_BIMAP_IMPLEMENT 0
#else
#	if defined(MASTER_ABSTRACT_BIT_STREAM_USE) || \
	   defined(MASTER_ABSTRACT_BYTE_STACK_USE) || \
	   defined(MASTER_ABSTRACT_MONOTONIC_STACK_USE) || \
	   defined(MASTER_ABSTRACT_RING_BUFFER_USE) || \
	   defined(MASTER_ABSTRACT_BIMAP_USE)
#		define MASTER_ABSTRACT_WHITELIST_MODE 1
#	else
#		define MASTER_ABSTRACT_WHITELIST_MODE 0
#	endif /* #! Whitelist Setting !# */
#	ifdef MASTER_ABSTRACT_BIT_STREAM_EXTERN
#		define MASTER_ABSTRACT_BIT_STREAM_IMPLEMENT 0
#		ifdef MASTER_ABSTRACT_BIT_STREAM_USE
#			warning "Bit Stream is defined to USE, but also defined to EXTERN. Bit Stream will NOT be compiled."
#		endif /* #! Bit Stream Conflict of Use & Extern !# */
#	elif MASTER_ABSTRACT_WHITELIST_MODE == 1
#		ifdef MASTER_ABSTRACT_BIT_STREAM_USE
#			define MASTER_ABSTRACT_BIT_STREAM_IMPLEMENT 1
#		else
#			define MASTER_ABSTRACT_BIT_STREAM_IMPLEMENT 0
#		endif /* #! Bit Stream Use !# */
#	else
#		define MASTER_ABSTRACT_BIT_STREAM_IMPLEMENT 1
#	endif /* #! Bit Stream !# */
#	ifdef MASTER_ABSTRACT_BYTE_STACK_EXTERN
#		define MASTER_ABSTRACT_BYTE_STACK_IMPLEMENT 0
#		ifdef MASTER_ABSTRACT_BYTE_STACK_USE
#			warning "Byte Stack is defined to USE, but also defined to EXTERN. Byte Stack will NOT be compiled."
#		endif /* #! Byte Stack Conflict of Use & Extern !# */
#	elif MASTER_ABSTRACT_WHITELIST_MODE == 1
#		ifdef MASTER_ABSTRACT_BYTE_STACK_USE
#			define MASTER_ABSTRACT_BYTE_STACK_IMPLEMENT 1
#		else
#			define MASTER_ABSTRACT_BYTE_STACK_IMPLEMENT 0
#		endif /* #! Byte Stack Use !# */
#	else
#		define MASTER_ABSTRACT_BYTE_STACK_IMPLEMENT 1
#	endif /* #! Byte Stack !# */
#	ifdef MASTER_ABSTRACT_MONOTONIC_STACK_EXTERN
#		define MASTER_ABSTRACT_MONOTONIC_STACK_IMPLEMENT 0
#		ifdef MASTER_ABSTRACT_MONOTONIC_STACK_USE
#			warning "Monotonic Stack is defined to USE, but also defined to EXTERN. Monotonic Stack will NOT be compiled."
#		endif /* #! Monotonic Stack Conflict of Use & Extern !# */
#	elif MASTER_ABSTRACT_WHITELIST_MODE == 1
#		ifdef MASTER_ABSTRACT_MONOTONIC_STACK_USE
#			define MASTER_ABSTRACT_MONOTONIC_STACK_IMPLEMENT 1
#		else
#			define MASTER_ABSTRACT_MONOTONIC_STACK_IMPLEMENT 0
#		endif /* #! Monotonic Stack Use !# */
#	else
#		define MASTER_ABSTRACT_MONOTONIC_STACK_IMPLEMENT 1
#	endif /* #! Monotonic Stack !# */
#	ifdef MASTER_ABSTRACT_RING_BUFFER_EXTERN
#		define MASTER_ABSTRACT_RING_BUFFER_IMPLEMENT 0
#		ifdef MASTER_ABSTRACT_RING_BUFFER_USE
#			warning "Ring Buffer is defined to USE, but also defined to EXTERN. Ring Buffer will NOT be compiled."
#		endif /* #! Ring Buffer Conflict of Use & Extern !# */
#	elif MASTER_ABSTRACT_WHITELIST_MODE == 1
#		ifdef MASTER_ABSTRACT_RING_BUFFER_USE
#			define MASTER_ABSTRACT_RING_BUFFER_IMPLEMENT 1
#		else
#			define MASTER_ABSTRACT_RING_BUFFER_IMPLEMENT 0
#		endif /* #! Ring Buffer Use !# */
#	else
#		define MASTER_ABSTRACT_RING_BUFFER_IMPLEMENT 1
#	endif /* #! Ring Buffer !# */
#	ifdef MASTER_ABSTRACT_BIMAP_EXTERN
#		define MASTER_ABSTRACT_BIMAP_IMPLEMENT 0
#		ifdef MASTER_ABSTRACT_BIMAP_USE
#			warning "BiMap is defined to USE, but also defined to EXTERN. BiMap will NOT be compiled."
#		endif /* #! BiMap Conflict of Use & Extern !# */
#	elif MASTER_ABSTRACT_WHITELIST_MODE == 1
#		ifdef MASTER_ABSTRACT_BIMAP_USE
#			define MASTER_ABSTRACT_BIMAP_IMPLEMENT 1
#		else
#			define MASTER_ABSTRACT_BIMAP_IMPLEMENT 0
#		endif /* #! BiMap Use !# */
#	else
#		define MASTER_ABSTRACT_BIMAP_IMPLEMENT 1
#	endif /* #! BiMap !# */
#	undef MASTER_ABSTRACT_WHITELIST_MODE
#endif /* #! MASTER_ABSTRACT_EXTERN_ONLY !# */

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

#if MASTER_ABSTRACT_BIT_STREAM_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_BitStream_Grant /* ! */,
	UI1,
	( MASTER_BitStream * const, stream ),
	( const UI1, bits )
) {
	if (stream == nul || stream->data == nul || bits > 32) return 0;
	while (stream->value_bits < bits && stream->available > 0) {
		stream->value |= *(stream->data) << stream->value_bits;
		stream->value_bits += 8;
		stream->data += 1;
		stream->available -= 1;
	}
	return stream->value_bits >= bits;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_BitStream_Peek /* ! */,
	UI4,
	( MASTER_BitStream * const, stream ),
	( const UI1, bits )
) {
	if (stream == nul || stream->data == nul || bits > 32) return 0;
	return (bits == 32) ? (stream->value) : (stream->value & ((1 << bits) - 1));
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_BitStream_Flush /* ! */,
	void,
	( MASTER_BitStream * const, stream ),
	( const UI1, bits )
) {
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

#endif /* #! Bit Stream !# */

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

#if MASTER_ABSTRACT_BYTE_STACK_IMPLEMENT == 1

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

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_ByteStack_AddByte /* ! */,
	UI1,
	( MASTER_ByteStack * const, bstack ),
	( const UI1, value )
) {
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

#endif /* #! Byte Stack !# */

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

#if MASTER_ABSTRACT_MONOTONIC_STACK_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_MonotonicStack_Init /* ! */,
	void,
	( MASTER_MonotonicStack * const, mstack ),
	( const UI4, capacity ),
	( const UI4, element_size ),
	( const UI1, monotone_type )
) {
	if (mstack == nul) return;
	mstack->buffer = (UT *)MASTER_MALLOC(capacity * element_size);
	mstack->buffer_capacity = capacity;
	mstack->buffer_element_size = element_size;
	mstack->buffer_position = 0;
	mstack->monotone_type = monotone_type;
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_MonotonicStack_Create /* ! */,
	MASTER_MonotonicStack,
	( const UI4, capacity ),
	( const UI4, element_size ),
	( const UI1, monotone_type )
) {
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

#endif /* #! Monotonic Stack !# */

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
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_RingBuffer_CopyAndUpdateBytes, ( MASTER_RingBuffer * const, UI1 *, const UI4, UI4 ) );

#if MASTER_ABSTRACT_RING_BUFFER_IMPLEMENT == 1

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

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_RingBuffer_AddByte /* ! */,
	void,
	( MASTER_RingBuffer * const, ringbuf ),
	( const UI1, byte )
) {
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
MASTER_RingBuffer_CopyAndUpdateBytes( MASTER_RingBuffer * const ringbuf, UI1 * output, const UI4 offset, UI4 length ) {
	if (ringbuf == nul || ringbuf->pointer == nul) return;
	MASTER_RingBuffer_CopyBytes(ringbuf, output, offset, length);
	MASTER_RingBuffer_AddBytes(ringbuf, output, length);
}

#endif /* #! Ring Buffer !# */

typedef struct {
	void * value;
	void * pointer;
} MASTER_BiMapElement;

typedef struct {
	MASTER_BiMapElement * elements;
	UI4 size;
	UI4 capacity;
	SI4 (*compareKeys)( const void * const, const void * const );
	SI4 (*compareValues)( const void * const, const void * const );
	void (*freeKey)( const void * const );
	void (*freeValue)( const void * const );
} MASTER_BiMap;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_BiMap_Init, ( MASTER_BiMap * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_BiMap, MASTER_BiMap_Create, ( const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_BiMap_Flush, ( MASTER_BiMap * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_BiMap_Free, ( MASTER_BiMap * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_BiMap_Add, ( MASTER_BiMap * const, void * const, void * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void *, MASTER_BiMap_SearchByKey, ( const MASTER_BiMap * const, const void * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void *, MASTER_BiMap_SearchByValue, ( const MASTER_BiMap * const, const void * const ) );

#if MASTER_ABSTRACT_BIMAP_IMPLEMENT == 1

void
MASTER_BiMap_Init( MASTER_BiMap * const bimap, const UI4 size ) {
	if (bimap == nul) return;
	bimap->elements = (MASTER_BiMapElement *)MASTER_CALLOC(size << 1, sizeof(MASTER_BiMapElement));
	bimap->capacity = size;
	bimap->size = 0;
	bimap->compareKeys = bimap->compareValues = nul;
}

MASTER_BiMap
MASTER_BiMap_Create( const UI4 size ) {
	MASTER_BiMap bimap;
	MASTER_BiMap_Init(&bimap, size);
	return bimap;
}

void
MASTER_BiMap_Flush( MASTER_BiMap * const bimap ) {
	if (bimap == nul) return;
	bimap->size = 0;
}

void
MASTER_BiMap_Free( MASTER_BiMap * const bimap ) {
	UI4 index = 0;
	if (bimap == nul) return;
	if (bimap->freeKey != nul || bimap->compareValues)
		for (; index < bimap->size; index += 1) {
			if (bimap->freeKey != nul)
				bimap->freeKey(bimap->elements[index << 1].value);
			if (bimap->freeValue != nul)
				bimap->freeValue(bimap->elements[(index << 1) | 1].value);
		}
	MASTER_FREE(bimap->elements);
}

void
MASTER_BiMap_Add( MASTER_BiMap * const bimap, void * const key, void * const value ) {
	SI4 compare;
	UI4 left;
	UI4 right;
	UI4 middle;
	UI4 keyptr;
	if (bimap == nul || key == nul || value == nul) return;
	if (bimap->size >= bimap->capacity)
		bimap->elements = (MASTER_BiMapElement *)MASTER_REALLOC(bimap->elements, (bimap->capacity <<= 1) * sizeof(MASTER_BiMapElement));
	left = 0;
	right = bimap->size;
	if (bimap->size == 0) goto putkey;
	while (left < right) {
		middle = left + ((right - left) >> 1);
		compare = (bimap->compareKeys != nul) ? (bimap->compareKeys(bimap->elements[middle << 1].value, key)) : (SI4)(*(const UI4 *)bimap->elements[middle << 1].value - *(const UI4 *)key);
		if (compare < 0) left = middle + 1;
		otherwise (compare > 0) right = middle;
		else goto entervalue;
	}
	if (left < bimap->size && ((bimap->compareKeys != nul) ? (bimap->compareKeys(bimap->elements[left << 1].value, key) == 0) : (SI4)(*(const UI4 *)bimap->elements[left << 1].value == *(const UI4 *)key)))
		goto entervalue;
	right = bimap->size;
	while (right > left) {
		bimap->elements[right << 1] = bimap->elements[(right - 1) << 1];
		right -= 1;
	}
	putkey :
	bimap->elements[left << 1].value = key;
	keyptr = left << 1;
	entervalue :
	left = 0;
	right = bimap->size;
	if (bimap->size == 0) goto putvalue;
	while (left < right) {
		middle = left + ((right - left) >> 1);
		compare = (bimap->compareValues != nul) ? (bimap->compareValues(bimap->elements[(middle << 1) | 1].value, value)) : (SI4)(*(const UI4 *)bimap->elements[(middle << 1) | 1].value - *(const UI4 *)value);
		if (compare < 0) left = middle + 1;
		otherwise (compare > 0) right = middle;
		else break;
	}
	right = bimap->size;
	while (right > left) {
		bimap->elements[(right << 1) | 1] = bimap->elements[((right - 1) << 1) | 1];
		right -= 1;
	}
	putvalue :
	bimap->elements[(left << 1) | 1].value = value;
	bimap->elements[keyptr].pointer = bimap->elements[(left << 1) | 1].value;
	bimap->elements[(left << 1) | 1].pointer = bimap->elements[keyptr].value;
	bimap->size += 1;
}

void *
MASTER_BiMap_SearchByKey( const MASTER_BiMap * const bimap, const void * const key ) {
	SI4 compare;
	UI4 left;
	UI4 right;
	UI4 middle;
	if (bimap == nul || key == nul) return nul;
	left = 0;
	right = bimap->size;
	while (left < right) {
		middle = left + ((right - left) >> 1);
		compare = (bimap->compareKeys != nul) ? (bimap->compareKeys(bimap->elements[middle << 1].value, key)) : (SI4)(*(const UI4 *)bimap->elements[middle << 1].value - *(const UI4 *)key);
		if (compare < 0) left = middle + 1;
		otherwise (compare > 0) right = middle;
		else return bimap->elements[middle << 1].pointer;
	}
	if (left < bimap->size && ((bimap->compareKeys != nul) ? (bimap->compareKeys(bimap->elements[left << 1].value, key) == 0) : (SI4)(*(const UI4 *)bimap->elements[left << 1].value == *(const UI4 *)key)))
		return bimap->elements[left << 1].pointer;
	return nul;
}

void *
MASTER_BiMap_SearchByValue( const MASTER_BiMap * const bimap, const void * const value ) {
	SI4 compare;
	UI4 left;
	UI4 right;
	UI4 middle;
	if (bimap == nul || value == nul) return nul;
	left = 0;
	right = bimap->size;
	while (left < right) {
		middle = left + ((right - left) >> 1);
		compare = (bimap->compareValues != nul) ? (bimap->compareValues(bimap->elements[(middle << 1) | 1].value, value)) : (SI4)(*(const UI4 *)bimap->elements[(middle << 1) | 1].value - *(const UI4 *)value);
		if (compare < 0) left = middle + 1;
		otherwise (compare > 0) right = middle;
		else return bimap->elements[(middle << 1) | 1].pointer;
	}
	if (left < bimap->size && ((bimap->compareKeys != nul) ? (bimap->compareKeys(bimap->elements[(left << 1) | 1].value, value) == 0) : (SI4)(*(const UI4 *)bimap->elements[(left << 1) | 1].value == *(const UI4 *)value)))
		return bimap->elements[(left << 1) | 1].pointer;
	return nul;
}

#endif /* #! BiMap !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_ABSTRACT_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_ABSTRACT_INCLUDE_H !# */

/* #! be master~ !# */
