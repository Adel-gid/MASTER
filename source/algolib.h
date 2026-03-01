
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_ALGOLIB_H
#define MASTER_zzz_ALGOLIB_H

#include <master_enum.h>
#include <abstract.h>
#include <bitlib.h>

MASTER_BEGIN_DECLARATIONS

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_CheckBrackets, ( const char * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_IsPrime, ( const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_FloorSqrt, ( const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, OSI, MASTER_Algolib_RoundSqrt, ( const OSI ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_CalculateSpan, ( const UI4 * const, UI4 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_maxint, MASTER_Algolib_DJB2, ( const UI1 *, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_maxint, MASTER_Algolib_SDBM, ( const UI1 *, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash1, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash1_Aligned, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
#if MASTER_64_AVAILABLE
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_Algolib_MurmurHash64A, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_Algolib_MurmurHash64B, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI8 ) );
#endif /* #! 64 Bits !# */
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash2, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash2A, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Algolib_MurmurHash2_Aligned,( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_MurmurHash3x32o4, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4, void * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_MurmurHash3x32o16, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4, void * const MASTER_PREFER_RESTRICT ) );
#if MASTER_64_AVAILABLE == 1
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_MurmurHash3x64o16, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, const UI4, void * const MASTER_PREFER_RESTRICT ) );
#endif /* #! 64 Bits !# */
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_Algolib_FindMissingPositive, ( SI4 * const, const UI4 ) );

/* #! Check Algorithms !# */

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_CheckBrackets /* ! */,
	UI1,
	( const char * const, string )
) {
	UI4 index = 0;
	char bracket;
	MASTER_ByteStack bstack;
	MASTER_ByteStack_Init(&bstack, 32);
	for (/* #! Inited above !# */; string[index] != 0; index += 1) {
		if (MASTER_ASCII_IS_OPEN_BRACKET(string[index])) {
			if (MASTER_ByteStack_AddByte(&bstack, (UI1)string[index]) == MASTER_ERROR) goto failure;
		} otherwise (MASTER_ASCII_IS_CLOSE_BRACKET(string[index])) {
			bracket = (char)MASTER_ByteStack_PeekByte(&bstack, 0);
			if ((bracket == '(' && string[index] != ')') ||
				(bracket == '[' && string[index] != ']') ||
				(bracket == '{' && string[index] != '}') ||
				bracket == 0)
				goto failure;
			MASTER_ByteStack_PopByte(&bstack);
		}
	}
	if (MASTER_ByteStack_IsEmpty(&bstack) == 0)
		goto failure;
	MASTER_ByteStack_Free(&bstack);
	return 1;
failure :
	MASTER_ByteStack_Free(&bstack);
	return 0;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_IsPrime /* ! */,
	UI1,
	( const SI4, value )
) {
	SI4 iterat = 5;
	SI4 limit;
	if (value <= 1) return 0;
	if (value <= 3) return 1;
	if ((value & 1) == 0 || value % 3 == 0) return 0;
	limit = MASTER_Algolib_FloorSqrt(value);
	for (/* #! Inited above !# */; iterat <= limit; iterat += 6)
		if (value % iterat == 0 || value % (iterat + 2) == 0) return 0;
	return 1;
}

/* #! Some Algorithms !# */

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_FloorSqrt /* ! */,
	OSI,
	( const OSI, value )
) {
	OSI estimate = value;
	OSI quotient;
	if (value <= 0) return 0;
	while (estimate > value / estimate) {
		quotient = value / estimate;
		estimate = (estimate >> 1) + (quotient >> 1) + (((estimate & 1) + (quotient & 1)) >> 1);
	}
	return estimate;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_RoundSqrt /* ! */,
	OSI,
	( const OSI, value )
) {
	OSI estimate = value;
	if (value < 0) return -1;
	while (estimate > value / estimate)
		estimate = (estimate + value / estimate) >> 1;
	return estimate + (MASTER_SQUARE(estimate + 1) - value < value - MASTER_SQUARE(estimate));
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_CalculateSpan /* ! */,
	UI1,
	( const UI4 * const, array ),
	( UI4 * const, output ),
	( const UI4, length )
) {
	UI4 * mstack;
	UI4 mstackPos = 0;
	UI4 index = 0;
	if (array == nul || output == nul || length == 0) return MASTER_ERROR;
	mstack = (UI4 *)MASTER_MALLOC(length * sizeof(UI4));
	for (/* #! Inited above !# */; index < length; index += 1) {
		while (mstackPos > 0 && array[mstack[mstackPos - 1]] <= array[index]) {
			mstackPos -= 1;
			mstack[mstackPos] = 0;
		}
		if (mstackPos == 0) output[index] = index + 1;
		else output[index] = index - mstack[mstackPos - 1];
		mstack[mstackPos] = index;
		mstackPos += 1;
	}
	MASTER_FREE(mstack);
	return MASTER_NO_ERROR;
}

/* #! OneShot Hash Functions !# */

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DJB2 /* ! */,
	MASTER_maxint,
	( const UI1 *, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_maxint hashValue = 5381;
	while (length > 0) {
		hashValue = hashValue * 33 + *bytes; /* #! or ^ !# */
		bytes += 1;
		length -= 1;
	}
	return hashValue;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_SDBM /* ! */,
	MASTER_maxint,
	( const UI1 *, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_maxint hashValue = 0;
	while (length > 0) {
		hashValue = hashValue * 65599 + *bytes;
		bytes += 1;
		length -= 1;
	}
	return hashValue;
}

/* #! TODO : FSM !# */
MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash1 /* ! */,
	UI4,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI4, seedValue )
) {
	UI4 hashValue = seedValue ^ ((UI4)length * 0xC6A4A793);
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	while (estimated >= 4) {
		hashValue += MASTER_UNPACK_LE4(ui1_data);
		hashValue *= 0xC6A4A793;
		hashValue ^= hashValue >> 16;
		ui1_data += 4;
		estimated -= 4;
	}
	if (estimated >= 3)
		hashValue += ui1_data[2] << 16;
	if (estimated >= 2)
		hashValue += ui1_data[1] << 8;
	if (estimated >= 1) {
		hashValue += ui1_data[0];
		hashValue *= 0xC6A4A793;
		hashValue ^= hashValue >> 16;
	}
	hashValue *= 0xC6A4A793;
	hashValue ^= hashValue >> 10;
	hashValue *= 0xC6A4A793;
	hashValue ^= hashValue >> 17;
	return hashValue;
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash1_Aligned /* ! */,
	UI4,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI4, seedValue )
) {
	union {
		const void * MASTER_PREFER_RESTRICT bytes;
		MASTER_maxint value;
	} bytesUnion;
	UI4 hashValue = seedValue ^ ((UI4)length * 0xC6A4A793);
	UI1 align;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	bytesUnion.bytes = bytes;
	align = bytesUnion.value & 3;
	if (align > 0 && length >= 4) {
		const UI1 shiftLeft = (UI1)(4 - align) << 3;
		const UI1 shiftRight = align << 3;
		UI4 helder;
		UI4 tempValue = 0;
		UI1 pack;
		if (align <= 1)
			tempValue |= ui1_data[2] << 16;
		if (align <= 2)
			tempValue |= ui1_data[1] << 8;
		if (align <= 3)
			tempValue |= ui1_data[0];
		tempValue <<= align << 3;
		ui1_data += 4 - align;
		estimated -= 4 - align;
		while (estimated >= 4) {
			helder = MASTER_UNPACK_LE4(ui1_data);
			tempValue = (tempValue >> shiftRight) | (helder << shiftLeft);
			hashValue += tempValue;
			hashValue *= 0xC6A4A793;
			hashValue ^= hashValue >> 16;
			tempValue = helder;
			ui1_data += 4;
			estimated -= 4;
		}
		pack = MASTER_MIN((UI1)estimated, align);
		helder = 0;
		if (pack >= 3)
			helder |= ui1_data[2] << 16;
		if (pack >= 2)
			helder |= ui1_data[1] << 8;
		if (pack >= 1)
			helder |= ui1_data[0];
		hashValue += (tempValue >> shiftRight) | (helder << shiftLeft);
		hashValue *= 0xC6A4A793;
		hashValue ^= hashValue >> 16;
		ui1_data += pack;
		estimated -= pack;
	} else
		while (estimated >= 4) {
			hashValue += MASTER_UNPACK_LE4(ui1_data);
			hashValue *= 0xC6A4A793;
			hashValue ^= hashValue >> 16;
			ui1_data += 4;
			estimated -= 4;
		}
	if (estimated >= 3)
		hashValue += ui1_data[2] << 16;
	if (estimated >= 2)
		hashValue += ui1_data[1] << 8;
	if (estimated >= 1) {
		hashValue += ui1_data[0];
		hashValue *= 0xC6A4A793;
		hashValue ^= hashValue >> 16;
	}
	hashValue *= 0xC6A4A793;
	hashValue ^= hashValue >> 10;
	hashValue *= 0xC6A4A793;
	hashValue ^= hashValue >> 17;
	return hashValue;
}

#if MASTER_64_AVAILABLE
/* #! TODO : FSM !# */
MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash64A /* ! */,
	UI8,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI8, seedValue )
) {
	UI8 hashValue = (length * 0xC6A4A7935BD1E995) ^ seedValue;
	UI8 helder;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	while (estimated >= 8) {
		helder = MASTER_UNPACK_LE8(ui1_data);
		helder *= 0xC6A4A7935BD1E995;
		helder ^= helder >> 47;
		helder *= 0xC6A4A7935BD1E995;
		hashValue ^= helder;
		hashValue *= 0xC6A4A7935BD1E995;
		ui1_data += 8;
		estimated -= 8;
	}
	if (estimated >= 7)
		hashValue ^= ((UI8)ui1_data[6]) << 48;
	if (estimated >= 6)
		hashValue ^= ((UI8)ui1_data[5]) << 40;
	if (estimated >= 5)
		hashValue ^= ((UI8)ui1_data[4]) << 32;
	if (estimated >= 4)
		hashValue ^= ((UI8)ui1_data[3]) << 24;
	if (estimated >= 3)
		hashValue ^= ((UI8)ui1_data[2]) << 16;
	if (estimated >= 2)
		hashValue ^= ((UI8)ui1_data[1]) << 8;
	if (estimated >= 1) {
		hashValue ^= ((UI8)ui1_data[0]);
		hashValue *= 0xC6A4A7935BD1E995;
	}
	hashValue ^= hashValue >> 47;
	hashValue *= 0xC6A4A7935BD1E995;
	hashValue ^= hashValue >> 47;
	return hashValue;
}

/* #! TODO : FSM !# */
MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash64B /* ! */,
	UI8,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI8, seedValue )
) {
	UI4 hashValue1 = (UI4)((SI4)seedValue ^ (SI4)length);
	UI4 hashValue2 = (UI4)(seedValue >> 32);
	UI4 helder1;
	UI4 helder2;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	while (estimated >= 8) {
		helder1 = MASTER_UNPACK_LE4(ui1_data);
		helder2 = MASTER_UNPACK_LE4(ui1_data + 4);
		helder1 *= 0x5BD1E995;
		helder2 *= 0x5BD1E995;
		helder1 ^= helder1 >> 24;
		helder2 ^= helder2 >> 24;
		helder1 *= 0x5BD1E995;
		helder2 *= 0x5BD1E995;
		hashValue1 *= 0x5BD1E995;
		hashValue2 *= 0x5BD1E995;
		hashValue1 ^= helder1;
		hashValue2 ^= helder2;
		ui1_data += 8;
		estimated -= 8;
	}
	if (estimated >= 4) {
		helder1 = MASTER_UNPACK_LE4(ui1_data);
		helder1 *= 0x5BD1E995;
		helder1 ^= helder1 >> 24;
		helder1 *= 0x5BD1E995;
		hashValue1 *= 0x5BD1E995;
		hashValue1 ^= helder1;
		ui1_data += 4;
		estimated &= 3;
	}
	if (estimated >= 3)
		hashValue2 ^= ui1_data[2] << 16;
	if (estimated >= 2)
		hashValue2 ^= ui1_data[1] << 8;
	if (estimated >= 1) {
		hashValue2 ^= ui1_data[0];
		hashValue2 *= 0x5BD1E995;
	}
	hashValue1 ^= hashValue2 >> 18;
	hashValue1 *= 0x5BD1E995;
	hashValue2 ^= hashValue1 >> 22;
	hashValue2 *= 0x5BD1E995;
	hashValue1 ^= hashValue2 >> 17;
	hashValue1 *= 0x5BD1E995;
	hashValue2 ^= hashValue1 >> 19;
	hashValue2 *= 0x5BD1E995;
	return ((UI8)hashValue1 << 32) | hashValue2;
}
#endif /* #! 64 Bits !# */

#define MASTER_ALGOLIB_MURMURHASH2A_MIX( hashValue, helder ) do { \
		(helder) *= 0x5BD1E995; \
		(helder) ^= (helder) >> 24; \
		(helder) *= 0x5BD1E995; \
		(hashValue) *= 0x5BD1E995; \
		(hashValue) ^= (UI4)(helder); \
	} while (0)

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash2 /* ! */,
	UI4,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI4, seedValue )
) {
	UI4 hashValue = (UI4)length ^ seedValue;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	UI4 helder;
	while (estimated >= 4) {
		helder = MASTER_UNPACK_LE4(ui1_data);
		MASTER_ALGOLIB_MURMURHASH2A_MIX(hashValue, helder);
		ui1_data += 4;
		estimated -= 4;
	}
	if (estimated >= 3)
		hashValue ^= ui1_data[2] << 16;
	if (estimated >= 2)
		hashValue ^= ui1_data[1] << 8;
	if (estimated >= 1) {
		hashValue ^= ui1_data[0];
		hashValue *= 0x5BD1E995;
	}
	hashValue ^= hashValue >> 13;
	hashValue *= 0x5BD1E995;
	hashValue ^= hashValue >> 15;
	return hashValue;
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash2A /* ! */,
	UI4,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI4, seedValue )
) {
	UI4 hashValue = seedValue;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	union {
		UI4 unsign;
		SI4 sign;
	} helder;
	if (bytes == nul) return 0;
	while (estimated >= 4) {
		helder.unsign = MASTER_UNPACK_LE4(ui1_data);
		MASTER_ALGOLIB_MURMURHASH2A_MIX(hashValue, helder.unsign);
		ui1_data += 4;
		estimated -= 4;
	}
	helder.unsign = 0;
	if (estimated >= 3)
		helder.unsign |= ui1_data[2] << 16;
	if (estimated >= 2)
		helder.unsign |= ui1_data[1] << 8;
	if (estimated >= 1)
		helder.unsign |= ui1_data[0];
	MASTER_ALGOLIB_MURMURHASH2A_MIX(hashValue, helder.unsign);
	helder.sign = (SI4)length;
	MASTER_ALGOLIB_MURMURHASH2A_MIX(hashValue, helder.sign);
	hashValue ^= hashValue >> 13;
	hashValue *= 0x5BD1E995;
	hashValue ^= hashValue >> 15;
	return hashValue;
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash2_Aligned /* ! */,
	UI4,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI4, seedValue )
) {
	union {
		const void * MASTER_PREFER_RESTRICT bytes;
		MASTER_maxint value;
	} bytesUnion;
	UI4 hashValue = (UI4)length ^ seedValue;
	UI4 helder;
	UI1 align;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul) return 0;
	bytesUnion.bytes = bytes;
	align = bytesUnion.value & 3;
	if (align > 0 && length >= 4) {
		const UI1 shiftLeft = (UI1)(4 - align) << 3;
		const UI1 shiftRight = align << 3;
		UI4 tempValue = 0;
		if (align <= 1)
			tempValue |= ui1_data[2] << 16;
		if (align <= 2)
			tempValue |= ui1_data[1] << 8;
		if (align <= 3)
			tempValue |= ui1_data[0];
		tempValue <<= align << 3;
		ui1_data += 4 - align;
		estimated -= 4 - align;
		while (estimated >= 4) {
			helder = MASTER_UNPACK_LE4(ui1_data);
			tempValue = (tempValue >> shiftRight) | (helder << shiftLeft);
			MASTER_ALGOLIB_MURMURHASH2A_MIX(hashValue, tempValue);
			tempValue = helder;
			ui1_data += 4;
			estimated -= 4;
		}
		helder = 0;
		if (estimated >= align) {
			if (align >= 3)
				helder |= ui1_data[2] << 16;
			if (align >= 2)
				helder |= ui1_data[1] << 8;
			if (align >= 1)
				helder |= ui1_data[0];

			helder = (tempValue >> shiftRight) | (helder << shiftLeft);
			MASTER_ALGOLIB_MURMURHASH2A_MIX(hashValue, helder);

			ui1_data += align;
			estimated -= align;

			if (estimated >= 3)
				hashValue ^= ui1_data[2] << 16;
			if (estimated >= 2)
				hashValue ^= ui1_data[1] << 8;
			if (estimated >= 1) {
				hashValue ^= ui1_data[0];
				hashValue *= 0x5BD1E995;
			}
		} else {
			if (estimated >= 3)
				helder |= ui1_data[2] << 16;
			if (estimated >= 2)
				helder |= ui1_data[1] << 8;
			if (estimated >= 1)
				helder |= ui1_data[0];
			hashValue ^= (tempValue >> shiftRight) | (helder << shiftLeft);
			hashValue *= 0x5BD1E995;
		}
	} else {
		while (estimated >= 4) {
			helder = MASTER_UNPACK_LE4(ui1_data);
			MASTER_ALGOLIB_MURMURHASH2A_MIX(hashValue, helder);
			ui1_data += 4;
			estimated -= 4;
		}
		if (estimated >= 3)
			hashValue ^= ui1_data[2] << 16;
		if (estimated >= 2)
			hashValue ^= ui1_data[1] << 8;
		if (estimated >= 1) {
			hashValue ^= ui1_data[0];
			hashValue *= 0x5BD1E995;
		}
	}
	hashValue ^= hashValue >> 13;
	hashValue *= 0x5BD1E995;
	hashValue ^= hashValue >> 15;
	return hashValue;
}

#define MASTER_ALGOLIB_MURMURHASH3_MIX32( hashValue ) do { \
		(hashValue) ^= (hashValue) >> 16; \
		(hashValue) *= 0x85EBCA6B; \
		(hashValue) ^= (hashValue) >> 13; \
		(hashValue) *= 0xC2B2AE35; \
		(hashValue) ^= (hashValue) >> 16; \
	} while (0)

#define MASTER_ALGOLIB_MURMURHASH3_MIX64( hashValue ) do { \
		(hashValue) ^= (hashValue) >> 33; \
		(hashValue) *= 0xFF51AFD7ED558CCD; \
		(hashValue) ^= (hashValue) >> 33; \
		(hashValue) *= 0xC4CEB9FE1A85EC53; \
		(hashValue) ^= (hashValue) >> 33; \
	} while (0)

/* #! TODO : FSM !# */
MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash3x32o4 /* ! */,
	void,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI4, seedValue ),
	( void * const MASTER_PREFER_RESTRICT, output )
) {
	UI4 hashValue = seedValue;
	UI4 helder;
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul || output == nul) return;
	while (estimated >= 4) {
		helder = MASTER_UNPACK_LE4(ui1_data);
		helder *= 0xCC9E2D51;
		helder = MASTER_RLL4(helder, 15);
		helder *= 0x1B873593;
		hashValue ^= helder;
		hashValue = MASTER_RLL4(hashValue, 13);
		hashValue = hashValue * 5 + 0xE6546B64;
		ui1_data += 4;
		estimated -= 4;
	}
	helder = 0;
	if (estimated >= 3)
		helder |= ui1_data[2] << 16;
	if (estimated >= 2)
		helder |= ui1_data[1] << 8;
	if (estimated >= 1) {
		helder |= ui1_data[0];
		helder *= 0xCC9E2D51;
		helder = MASTER_RLL4(helder, 15);
		helder *= 0x1B873593;
		hashValue ^= helder;
	}
	hashValue ^= (UI4)length;
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hashValue);
	*(UI4 *)output = hashValue;
}

/* #! TODO : FSM !# */
MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash3x32o16 /* ! */,
	void,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI4, seedValue ),
	( void * const MASTER_PREFER_RESTRICT, output )
) {
	UI4 hashValues[4];
	UI4 helders[4];
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul || output == nul) return;
	hashValues[0] = hashValues[1] = hashValues[2] = hashValues[3] = seedValue;
	while (estimated >= 16) {
		helders[0] = MASTER_UNPACK_LE4(ui1_data);
		helders[1] = MASTER_UNPACK_LE4((ui1_data + 4));
		helders[2] = MASTER_UNPACK_LE4((ui1_data + 8));
		helders[3] = MASTER_UNPACK_LE4((ui1_data + 12));
		helders[0] *= 0x239B961B;
		helders[0] = MASTER_RLL4(helders[0], 15);
		helders[0] *= 0xAB0E9789;
		hashValues[0] ^= helders[0];
		hashValues[0] = MASTER_RLL4(hashValues[0], 19);
		hashValues[0] += hashValues[1];
		hashValues[0] = hashValues[0] * 5 + 0x561CCD1B;
		helders[1] *= 0xAB0E9789;
		helders[1] = MASTER_RLL4(helders[1], 16);
		helders[1] *= 0x38B34AE5;
		hashValues[1] ^= helders[1];
		hashValues[1] = MASTER_RLL4(hashValues[1], 17);
		hashValues[1] += hashValues[2];
		hashValues[1] = hashValues[1] * 5 + 0x0BCAA747;
		helders[2] *= 0x38B34AE5;
		helders[2] = MASTER_RLL4(helders[2], 17);
		helders[2] *= 0xA1E38B93;
		hashValues[2] ^= helders[2];
		hashValues[2] = MASTER_RLL4(hashValues[2], 15);
		hashValues[2] += hashValues[3];
		hashValues[2] = hashValues[2] * 5 + 0x96CD1C35;
		helders[3] *= 0xA1E38B93;
		helders[3] = MASTER_RLL4(helders[3], 18);
		helders[3] *= 0x239B961B;
		hashValues[3] ^= helders[3];
		hashValues[3] = MASTER_RLL4(hashValues[3], 13);
		hashValues[3] += hashValues[0];
		hashValues[3] = hashValues[3] * 5 + 0x32AC3B17;
		ui1_data += 16;
		estimated -= 16;
	}
	MASTER_MEMSET(helders, 0, 4 * sizeof(UI4));
	if (estimated >= 15)
		helders[3] |= ui1_data[14] << 16;
	if (estimated >= 14)
		helders[3] |= ui1_data[13] << 8;
	if (estimated >= 13) {
		helders[3] |= ui1_data[12];
		helders[3] *= 0xA1E38B93;
		helders[3] = MASTER_RLL4(helders[3], 18);
		helders[3] *= 0x239B961B;
		hashValues[3] ^= helders[3];
	}
	if (estimated >= 9) {
		if (estimated >= 12)
			helders[2] = MASTER_UNPACK_LE4((ui1_data + 8));
		else {
			if (estimated >= 11)
				helders[2] |= ui1_data[10] << 16;
			if (estimated >= 10)
				helders[2] |= ui1_data[9] << 8;
			helders[2] |= ui1_data[8];
		}
		helders[2] *= 0x38B34AE5;
		helders[2] = MASTER_RLL4(helders[2], 17);
		helders[2] *= 0xA1E38B93;
		hashValues[2] ^= helders[2];
	}
	if (estimated >= 5) {
		if (estimated >= 8)
			helders[1] = MASTER_UNPACK_LE4((ui1_data + 4));
		else {
			if (estimated >= 7)
				helders[1] |= ui1_data[6] << 16;
			if (estimated >= 6)
				helders[1] |= ui1_data[5] << 8;
			helders[1] |= ui1_data[4];
		}
		helders[1] *= 0xAB0E9789;
		helders[1] = MASTER_RLL4(helders[1], 16);
		helders[1] *= 0x38B34AE5;
		hashValues[1] ^= helders[1];
	}
	if (estimated >= 1) {
		if (estimated >= 4)
			helders[0] = MASTER_UNPACK_LE4(ui1_data);
		else {
			if (estimated >= 3)
				helders[0] |= ui1_data[2] << 16;
			if (estimated >= 2)
				helders[0] |= ui1_data[1] << 8;
			helders[0] |= ui1_data[0];
		}
		helders[0] *= 0x239B961B;
		helders[0] = MASTER_RLL4(helders[0], 15);
		helders[0] *= 0xAB0E9789;
		hashValues[0] ^= helders[0];
	}
	hashValues[0] ^= (UI4)length;
	hashValues[1] ^= (UI4)length;
	hashValues[2] ^= (UI4)length;
	hashValues[3] ^= (UI4)length;
	hashValues[0] += hashValues[1] + hashValues[2] + hashValues[3];
	hashValues[1] += hashValues[0];
	hashValues[2] += hashValues[0];
	hashValues[3] += hashValues[0];
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hashValues[0]);
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hashValues[1]);
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hashValues[2]);
	MASTER_ALGOLIB_MURMURHASH3_MIX32(hashValues[3]);
	hashValues[0] += hashValues[1] + hashValues[2] + hashValues[3];
	hashValues[1] += hashValues[0];
	hashValues[2] += hashValues[0];
	hashValues[3] += hashValues[0];
	((UI4 *)output)[0] = hashValues[0];
	((UI4 *)output)[1] = hashValues[1];
	((UI4 *)output)[2] = hashValues[2];
	((UI4 *)output)[3] = hashValues[3];
}

#if MASTER_64_AVAILABLE == 1
/* #! TODO : FSM !# */
MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_MurmurHash3x64o16 /* ! */,
	void,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( const UI4, seedValue ),
	( void * const MASTER_PREFER_RESTRICT, output )
) {
	UI8 hashValues[2];
	UI8 helders[2];
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	if (bytes == nul || output == nul) return;
	hashValues[0] = hashValues[1] = seedValue;
	while (estimated >= 16) {
		helders[0] = MASTER_UNPACK_LE8(ui1_data);
		helders[1] = MASTER_UNPACK_LE8((ui1_data + 8));
		helders[0] *= 0x87C37B91114253D5;
		helders[0] = MASTER_RLL8(helders[0], 31);
		helders[0] *= 0x4CF5AD432745937F;
		hashValues[0] ^= helders[0];
		hashValues[0] = MASTER_RLL8(hashValues[0], 27);
		hashValues[0] += hashValues[1];
		hashValues[0] = hashValues[0] * 5 + 0x52DCE729;
		helders[1] *= 0x4CF5AD432745937F;
		helders[1] = MASTER_RLL8(helders[1], 33);
		helders[1] *= 0x87C37B91114253D5;
		hashValues[1] ^= helders[1];
		hashValues[1] = MASTER_RLL8(hashValues[1], 31);
		hashValues[1] += hashValues[0];
		hashValues[1] = hashValues[1] * 5 + 0x38495AB5;
		ui1_data += 16;
		estimated -= 16;
	}
	MASTER_MEMSET(helders, 0, 2 * sizeof(UI8));
	if (estimated >= 15)
		helders[1] |= (UI8)ui1_data[14] << 48;
	if (estimated >= 14)
		helders[1] |= (UI8)ui1_data[13] << 40;
	if (estimated >= 13)
		helders[1] |= (UI8)ui1_data[12] << 32;
	if (estimated >= 12)
		helders[1] |= (UI8)ui1_data[11] << 24;
	if (estimated >= 11)
		helders[1] |= (UI8)ui1_data[10] << 16;
	if (estimated >= 10)
		helders[1] |= (UI8)ui1_data[9] << 8;
	if (estimated >= 9) {
		helders[1] |= (UI8)ui1_data[8];
		helders[1] *= 0x4CF5AD432745937F;
		helders[1] = MASTER_RLL8(helders[1], 33);
		helders[1] *= 0x87C37B91114253D5;
		hashValues[1] ^= helders[1];
	}
	if (estimated >= 1) {
		if (estimated >= 8)
			helders[0] = MASTER_UNPACK_LE8(ui1_data);
		else {
			if (estimated >= 7)
				helders[0] |= (UI8)ui1_data[6] << 48;
			if (estimated >= 6)
				helders[0] |= (UI8)ui1_data[5] << 40;
			if (estimated >= 5)
				helders[0] |= (UI8)ui1_data[4] << 32;
			if (estimated >= 4)
				helders[0] |= (UI8)ui1_data[3] << 24;
			if (estimated >= 3)
				helders[0] |= (UI8)ui1_data[2] << 16;
			if (estimated >= 2)
				helders[0] |= (UI8)ui1_data[1] << 8;
			helders[0] |= (UI8)ui1_data[0];
		}
		helders[0] *= 0x87C37B91114253D5;
		helders[0] = MASTER_RLL8(helders[0], 31);
		helders[0] *= 0x4CF5AD432745937F;
		hashValues[0] ^= helders[0];
	}
	hashValues[0] ^= (UI4)length;
	hashValues[1] ^= (UI4)length;
	hashValues[0] += hashValues[1];
	hashValues[1] += hashValues[0];
	MASTER_ALGOLIB_MURMURHASH3_MIX64(hashValues[0]);
	MASTER_ALGOLIB_MURMURHASH3_MIX64(hashValues[1]);
	hashValues[0] += hashValues[1];
	hashValues[1] += hashValues[0];
	((UI8 *)output)[0] = hashValues[0];
	((UI8 *)output)[1] = hashValues[1];
}
#endif /* #! 64 Bits !# */

/* #! Dancing Links !# */

typedef struct MASTER_Algolib_Cell MASTER_Algolib_Cell;

struct MASTER_Algolib_Cell {
	MASTER_Algolib_Cell * upCell;
	MASTER_Algolib_Cell * leftCell;
	MASTER_Algolib_Cell * downCell;
	MASTER_Algolib_Cell * rightCell;
	UI4 rowColId;
	union {
		MASTER_Algolib_Cell * headerCell; /* #! Row & other !# */
		UI4 onesCount; /* #! Column !# */
	} extra;
};

typedef struct {
	MASTER_Algolib_Cell** columnTable;
	MASTER_Algolib_Cell** rowTable;
	UI4 columnCount;
	UI4 rowCount;
	UI4 columnCapacity;
	UI4 rowCapacity;
	struct MASTER_Algolib_Cell * rootCell;
} MASTER_Algolib_DLX;

typedef void(*MASTER_Algolib_DLX_FoundType)( void );
typedef void(*MASTER_Algolib_DLX_StuckedType)( const UI4 );
typedef void(*MASTER_Algolib_DLX_TryingType)( const UI4, const UI4, const UI4 );
typedef void(*MASTER_Algolib_DLX_UndoType)( const UI4, const UI4, const UI4 );

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Algolib_Cell *, MASTER_Algolib_Cell_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DLX_Init, ( MASTER_Algolib_DLX * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Algolib_DLX, MASTER_Algolib_DLX_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DLX_AddRow, ( MASTER_Algolib_DLX * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DLX_AddColumn, ( MASTER_Algolib_DLX * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_Cell_FreeRow, ( MASTER_Algolib_Cell * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DLX_Free, ( MASTER_Algolib_DLX * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DLX_Set, ( MASTER_Algolib_DLX * const, const UI4, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Algolib_Cell *, MASTER_Algolib_DLX_PickColumn, ( MASTER_Algolib_DLX * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DLX_Cover, ( MASTER_Algolib_Cell * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DLX_Uncover, ( MASTER_Algolib_Cell * const ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Algolib_DLX_Solve, ( MASTER_Algolib_DLX * const, const MASTER_Algolib_DLX_FoundType, const MASTER_Algolib_DLX_StuckedType, const MASTER_Algolib_DLX_TryingType, const MASTER_Algolib_DLX_UndoType ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_DLX_MakeOptional, ( MASTER_Algolib_DLX * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_DLX_PickRow, ( MASTER_Algolib_DLX * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Algolib_DLX_RemoveRow, ( MASTER_Algolib_DLX * const, const UI4 ) );

#define MASTER_ALGOLIB_CELL_DELETE_VERTI( curCell ) do { \
		(curCell)->upCell->downCell = (curCell)->downCell; \
		(curCell)->downCell->upCell = (curCell)->upCell; \
	} while (0)

#define MASTER_ALGOLIB_CELL_DELETE_HORIZ( curCell ) do { \
		(curCell)->leftCell->rightCell = (curCell)->rightCell; \
		(curCell)->rightCell->leftCell = (curCell)->leftCell; \
	} while (0)

#define MASTER_ALGOLIB_CELL_DELETE( curCell ) do { \
		MASTER_ALGOLIB_CELL_DELETE_VERTI(curCell); \
		MASTER_ALGOLIB_CELL_DELETE_HORIZ(curCell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_REINSTATE_VERTI( curCell ) do { \
		(curCell)->upCell->downCell = (curCell)->downCell->upCell = (curCell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_REINSTATE_HORIZ( curCell ) do { \
		(curCell)->leftCell->rightCell = (curCell)->rightCell->leftCell = (curCell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_REINSTATE( curCell ) do { \
		MASTER_ALGOLIB_CELL_REINSTATE_VERTI(curCell); \
		MASTER_ALGOLIB_CELL_REINSTATE_HORIZ(curCell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_LINK_SELF_VERTI( curCell) do { \
		(curCell)->upCell = (curCell)->downCell = (curCell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_LINK_SELF_HORIZ( curCell) do { \
		(curCell)->leftCell = (curCell)->rightCell = (curCell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_LINK_SELF( curCell ) do { \
		MASTER_ALGOLIB_CELL_LINK_SELF_VERTI(curCell); \
		MASTER_ALGOLIB_CELL_LINK_SELF_HORIZ(curCell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_INSERT_LEFT( curCell, newCell ) do { \
		(newCell)->leftCell = (curCell)->leftCell; \
		(newCell)->rightCell = (curCell); \
		(curCell)->leftCell = (curCell)->leftCell->rightCell = (newCell); \
	} while (0)

#define MASTER_ALGOLIB_CELL_INSERT_UP( curCell, newCell ) do { \
		(newCell)->upCell = (curCell)->upCell; \
		(newCell)->downCell = (curCell); \
		(curCell)->upCell = (curCell)->upCell->downCell = (newCell); \
	} while (0)

MASTER_DEFINE_FUNCTION0(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_Cell_Create /* ! */,
	MASTER_Algolib_Cell *
) {
	MASTER_Algolib_Cell * curCell = (MASTER_Algolib_Cell *)MASTER_MALLOC(sizeof(MASTER_Algolib_Cell));
	MASTER_ALGOLIB_CELL_LINK_SELF(curCell);
	return curCell;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_Init /* ! */,
	void,
	( MASTER_Algolib_DLX * const, dancingLinks )
) {
	if (dancingLinks == nul) return;
	dancingLinks->columnCount = 0;
	dancingLinks->rowCount = 0;
	dancingLinks->columnCapacity = 8;
	dancingLinks->rowCapacity = 8;
	dancingLinks->columnTable = (MASTER_Algolib_Cell**)MASTER_MALLOC(sizeof(MASTER_Algolib_Cell *) * dancingLinks->columnCapacity);
	dancingLinks->rowTable = (MASTER_Algolib_Cell**)MASTER_MALLOC(sizeof(MASTER_Algolib_Cell *) * dancingLinks->rowCapacity);
	dancingLinks->rootCell = MASTER_Algolib_Cell_Create();
}

MASTER_DEFINE_FUNCTION0(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_Create /* ! */,
	MASTER_Algolib_DLX
) {
	MASTER_Algolib_DLX dancingLinks;
	MASTER_Algolib_DLX_Init(&dancingLinks);
	return dancingLinks;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_AddRow /* ! */,
	void,
	( MASTER_Algolib_DLX * const, dancingLinks )
) {
	if (dancingLinks == nul) return;
	if (dancingLinks->rowCount >= dancingLinks->rowCapacity) {
		dancingLinks->rowCapacity <<= 1;
		dancingLinks->rowTable = (MASTER_Algolib_Cell**)MASTER_REALLOC(dancingLinks->rowTable, sizeof(MASTER_Algolib_Cell *) * dancingLinks->rowCapacity);
	}
	dancingLinks->rowTable[dancingLinks->rowCount] = nul;
	dancingLinks->rowCount += 1;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_AddColumn /* ! */,
	void,
	( MASTER_Algolib_DLX * const, dancingLinks )
) {
	MASTER_Algolib_Cell * columnCell;
	if (dancingLinks == nul) return;
	columnCell = MASTER_Algolib_Cell_Create();
	MASTER_ALGOLIB_CELL_LINK_SELF(columnCell);
	columnCell->rowColId = dancingLinks->columnCount;
	columnCell->extra.onesCount = 0;
	MASTER_ALGOLIB_CELL_INSERT_LEFT(dancingLinks->rootCell, columnCell);
	if (dancingLinks->columnCount >= dancingLinks->columnCapacity) {
		dancingLinks->columnCapacity <<= 1;
		dancingLinks->columnTable = (MASTER_Algolib_Cell**)MASTER_REALLOC(dancingLinks->columnTable, sizeof(MASTER_Algolib_Cell *) * dancingLinks->columnCapacity);
	}
	dancingLinks->columnTable[dancingLinks->columnCount] = columnCell;
	dancingLinks->columnCount += 1;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_Cell_FreeRow /* ! */,
	void,
	( MASTER_Algolib_Cell * const, curCell )
) {
	MASTER_Algolib_Cell * nextCell;
	MASTER_Algolib_Cell * iterat;
	if (curCell == nul) return;
	iterat = curCell->rightCell;
	while (iterat != curCell) {
		nextCell = iterat->rightCell;
		MASTER_FREE(iterat);
		iterat = nextCell;
	}
	MASTER_FREE(curCell);
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_Free /* ! */,
	void,
	( MASTER_Algolib_DLX * const, dancingLinks )
) {
	UI4 index = 0;
	if (dancingLinks == nul) return;
	for (/* #! Inited above !# */; index < dancingLinks->rowCount; index += 1)
		MASTER_Algolib_Cell_FreeRow(dancingLinks->rowTable[index]);
	for (index = 0; index < dancingLinks->columnCount; index += 1)
		MASTER_FREE(dancingLinks->columnTable[index]);
	MASTER_FREE(dancingLinks->columnTable);
	MASTER_FREE(dancingLinks->rowTable);
	MASTER_FREE(dancingLinks->rootCell);
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_Set /* ! */,
	void,
	( MASTER_Algolib_DLX * const, dancingLinks ),
	( const UI4, rowId ),
	( const UI4, columnId )
) {
	MASTER_Algolib_Cell * columnCell;
	MASTER_Algolib_Cell * rowCell;
	MASTER_Algolib_Cell * newCell;
	MASTER_Algolib_Cell * iterat;
	if (dancingLinks == nul) return;
	while (dancingLinks->columnCount <= columnId)
		MASTER_Algolib_DLX_AddColumn(dancingLinks);
	while (dancingLinks->rowCount <= rowId)
		MASTER_Algolib_DLX_AddRow(dancingLinks);
	columnCell = dancingLinks->columnTable[columnId];
	rowCell = dancingLinks->rowTable[rowId];
	if (rowCell == nul) {
		newCell = MASTER_Algolib_Cell_Create();
		newCell->rowColId = rowId;
		newCell->extra.headerCell = columnCell;
		columnCell->extra.onesCount += 1;
		dancingLinks->rowTable[rowId] = newCell;
	} else {
		iterat = rowCell->rightCell;
		while (iterat != rowCell) {
			if (iterat->extra.headerCell->rowColId == columnId) return;
			iterat = iterat->rightCell;
		}
		newCell = MASTER_Algolib_Cell_Create();
		newCell->rowColId = rowId;
		newCell->extra.headerCell = columnCell;
		columnCell->extra.onesCount += 1;
		MASTER_ALGOLIB_CELL_INSERT_LEFT(rowCell, newCell);
	}
	MASTER_ALGOLIB_CELL_INSERT_UP(columnCell, newCell);
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_PickColumn /* ! */,
	MASTER_Algolib_Cell *,
	( MASTER_Algolib_DLX * const, dancingLinks )
) {
	MASTER_Algolib_Cell * columnCell = nul;
	MASTER_Algolib_Cell * iterat;
	UI4 minOnes = MASTER_UI4_MAX;
	if (dancingLinks == nul) return nul;
	iterat = dancingLinks->rootCell->rightCell;
	while (iterat != dancingLinks->rootCell) {
		if (minOnes > iterat->extra.onesCount) {
			minOnes = iterat->extra.onesCount;
			columnCell = iterat;
		}
		iterat = iterat->rightCell;
	}
	return columnCell;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_Cover /* ! */,
	void,
	( MASTER_Algolib_Cell * const, columnCell )
) {
	MASTER_Algolib_Cell * iterat;
	MASTER_Algolib_Cell * jterat;
	if (columnCell == nul) return;
	MASTER_ALGOLIB_CELL_DELETE_HORIZ(columnCell);
	iterat = columnCell->downCell;
	while (iterat != columnCell) {
		jterat = iterat->rightCell;
		while (jterat != iterat) {
			MASTER_ALGOLIB_CELL_DELETE_VERTI(jterat);
			jterat->extra.headerCell->extra.onesCount -= 1;
			jterat = jterat->rightCell;
		}
		iterat = iterat->downCell;
	}
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_Uncover /* ! */,
	void,
	( MASTER_Algolib_Cell * const, columnCell )
) {
	MASTER_Algolib_Cell * iterat;
	MASTER_Algolib_Cell * jterat;
	if (columnCell == nul) return;
	iterat = columnCell->upCell;
	while (iterat != columnCell) {
		jterat = iterat->leftCell;
		while (jterat != iterat) {
			MASTER_ALGOLIB_CELL_REINSTATE_VERTI(jterat);
			jterat->extra.headerCell->extra.onesCount += 1;
			jterat = jterat->leftCell;
		}
		iterat = iterat->upCell;
	}
	MASTER_ALGOLIB_CELL_REINSTATE_HORIZ(columnCell);
}

MASTER_DEFINE_FUNCTION5(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_Solve /* ! */,
	void,
	( MASTER_Algolib_DLX * const, dancingLinks ),
	( const MASTER_Algolib_DLX_FoundType, foundFunc ),
	( const MASTER_Algolib_DLX_StuckedType, stuckedFunc ),
	( const MASTER_Algolib_DLX_TryingType, tryingFunc ),
	( const MASTER_Algolib_DLX_UndoType, undoFunc )
) {
	MASTER_Algolib_Cell * columnCell;
	MASTER_Algolib_Cell * rowCell;
	MASTER_Algolib_Cell * iterat;
	if (dancingLinks == nul) return;
	if (dancingLinks->rootCell->rightCell == dancingLinks->rootCell) {
		if (foundFunc != nul)
			foundFunc();
		return;
	}
	columnCell = MASTER_Algolib_DLX_PickColumn(dancingLinks);
	if (columnCell == nul || columnCell->extra.onesCount == 0) {
		if (stuckedFunc != nul)
			stuckedFunc(columnCell->rowColId);
		return;
	}
	MASTER_Algolib_DLX_Cover(columnCell);
	rowCell = columnCell->downCell;
	while (rowCell != columnCell) {
		if (tryingFunc != nul)
			tryingFunc(columnCell->rowColId, columnCell->extra.onesCount, rowCell->rowColId);
		iterat = rowCell->rightCell;
		while (iterat != rowCell) {
			MASTER_Algolib_DLX_Cover(iterat->extra.headerCell);
			iterat = iterat->rightCell;
		}
		MASTER_Algolib_DLX_Solve(dancingLinks, foundFunc, stuckedFunc, tryingFunc, undoFunc);
		if (undoFunc != nul)
			undoFunc(columnCell->rowColId, columnCell->extra.onesCount, rowCell->rowColId);
		iterat = rowCell->rightCell;
		while (iterat != rowCell) {
			MASTER_Algolib_DLX_Uncover(iterat->extra.headerCell);
			iterat = iterat->rightCell;
		}
		rowCell = rowCell->downCell;
	}
	MASTER_Algolib_DLX_Uncover(columnCell);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_MakeOptional /* ! */,
	UI1,
	( MASTER_Algolib_DLX * const, dancingLinks ),
	( const UI4, columnId )
) {
	if (dancingLinks == nul || columnId >= dancingLinks->columnCount)
		return MASTER_ERROR;
	/* #! Prevent undeletion by self linking !# */
	MASTER_ALGOLIB_CELL_DELETE_HORIZ(dancingLinks->columnTable[columnId]);
	MASTER_ALGOLIB_CELL_LINK_SELF_HORIZ(dancingLinks->columnTable[columnId]);
	return MASTER_NO_ERROR;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_PickRow /* ! */,
	UI1,
	( MASTER_Algolib_DLX * const, dancingLinks ),
	( const UI4, rowId )
) {
	MASTER_Algolib_Cell * iterat;
	if (dancingLinks == nul || rowId >= dancingLinks->rowCount)
		return MASTER_ERROR;
	if (dancingLinks->rowTable[rowId] == nul)
		return MASTER_ERROR;
	MASTER_Algolib_DLX_Cover(dancingLinks->rowTable[rowId]->extra.headerCell);
	iterat = dancingLinks->rowTable[rowId]->rightCell;
	while (iterat != dancingLinks->rowTable[rowId]) {
		MASTER_Algolib_DLX_Cover(iterat->extra.headerCell);
		iterat = iterat->rightCell;
	}
	return MASTER_NO_ERROR;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Algolib_DLX_RemoveRow /* ! */,
	UI1,
	( MASTER_Algolib_DLX * const, dancingLinks ),
	( const UI4, rowId )
) {
	MASTER_Algolib_Cell * iterat;
	if (dancingLinks == nul || rowId >= dancingLinks->rowCount)
		return MASTER_ERROR;
	if (dancingLinks->rowTable[rowId] == nul)
		return MASTER_ERROR;
	MASTER_ALGOLIB_CELL_DELETE_VERTI(dancingLinks->rowTable[rowId]);
	dancingLinks->rowTable[rowId]->extra.headerCell->extra.onesCount -= 1;
	iterat = dancingLinks->rowTable[rowId]->rightCell;
	while (iterat != dancingLinks->rowTable[rowId]) {
		MASTER_ALGOLIB_CELL_DELETE_VERTI(iterat);
		iterat->extra.headerCell->extra.onesCount -= 1;
		iterat = iterat->rightCell;
	}
	return MASTER_NO_ERROR;
}

MASTER_END_DECLARATIONS

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zzz_ALGOLIB_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_ALGOLIB_H !# */

/* #! be master !# */
