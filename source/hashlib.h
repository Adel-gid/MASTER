
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_HASHLIB_INCLUDE_H
#define MASTER_zRIVATE_HASHLIB_INCLUDE_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#define MASTER_OPERATION_XOR3( value1, value2, value3 ) ((value1) ^ (value2) ^ (value3))
#define MASTER_OPERATION_1XB2ON3E( value1, value2, value3 ) ((value1) ^ ((value2) | (~(value3))))
#define MASTER_OPERATION_2XB1ON3E( value1, value2, value3 ) ((value2) ^ ((value1) | (~(value3))))
#define MASTER_OPERATION_3XB1ON2E( value1, value2, value3 ) ((value3) ^ ((value1) | (~(value2))))

#define MASTER_OPERATION_CHOICE_STANDARD( value1, value2, value3 ) (((value1) & (value2)) | ((~(value1)) & (value3)))
#define MASTER_OPERATION_CHOICE_OPTIMIZED( value1, value2, value3 ) ((value3) ^ ((value1) & ((value2) ^ (value3))))
#define MASTER_OPERATION_MAJORITAR_STANDARD( value1, value2, value3 ) (((value1) & (value2)) ^ ((value1) & (value3)) ^ ((value2) & (value3)))
#define MASTER_OPERATION_MAJORITAR_OPTIMIZED( value1, value2, value3 ) ((((value1) | (value2)) & (value3)) | ((value1) & (value2)))

#ifdef MASTER_HASHLIB_USE_STANDARD_MACROSES
#	define MASTER_OPERATION_CHOICE MASTER_OPERATION_CHOICE_STANDARD
#	define MASTER_OPERATION_MAJORITAR MASTER_OPERATION_MAJORITAR_STANDARD
#else
#	define MASTER_OPERATION_CHOICE MASTER_OPERATION_CHOICE_OPTIMIZED
#	define MASTER_OPERATION_MAJORITAR MASTER_OPERATION_MAJORITAR_OPTIMIZED
#endif /* #! MASTER_HASHLIB_OPTIMIZE_MACROSES !# */

#ifdef MASTER_HASHLIB_EXTERN_ONLY
#	define MASTER_HASHLIB_MD2_IMPLEMENT 0
#	define MASTER_HASHLIB_MD4_IMPLEMENT 0
#	define MASTER_HASHLIB_MD5_IMPLEMENT 0
#	define MASTER_HASHLIB_SHA1_IMPLEMENT 0
#	define MASTER_HASHLIB_RIPEMD128_IMPLEMENT 0
#	define MASTER_HASHLIB_RIPEMD160_IMPLEMENT 0
#	define MASTER_HASHLIB_RIPEMD256_IMPLEMENT 0
#	define MASTER_HASHLIB_RIPEMD320_IMPLEMENT 0
#	define MASTER_HASHLIB_MURMURHASH2A_IMPLEMENT 0
#	define MASTER_HASHLIB_API_IMPLEMENT 0
#else
#	define MASTER_HASHLIB_API_IMPLEMENT 1
#	if defined(MASTER_HASHLIB_MD2_USE) || \
	   defined(MASTER_HASHLIB_MD4_USE) || \
	   defined(MASTER_HASHLIB_MD5_USE) || \
	   defined(MASTER_HASHLIB_SHA1_USE) || \
	   defined(MASTER_HASHLIB_RIPEMD128_USE) || \
	   defined(MASTER_HASHLIB_RIPEMD160_USE) || \
	   defined(MASTER_HASHLIB_RIPEMD256_USE) || \
	   defined(MASTER_HASHLIB_RIPEMD320_USE) || \
	   defined(MASTER_HASHLIB_MURMURHASH2A_USE)
#		define MASTER_HASHLIB_WHITELIST_MODE 1
#	else
#		define MASTER_HASHLIB_WHITELIST_MODE 0
#	endif /* #! Whitelist Setting !# */
#	ifdef MASTER_HASHLIB_MD2_EXTERN
#		define MASTER_HASHLIB_MD2_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_MD2_USE
#			warning "MD2 is defined to USE, but also defined to EXTERN. MD2 will NOT be compiled."
#		endif /* #! MD2 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_MD2_USE
#			define MASTER_HASHLIB_MD2_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_MD2_IMPLEMENT 0
#		endif /* #! MD2 Use !# */
#	else
#		define MASTER_HASHLIB_MD2_IMPLEMENT 1
#	endif /* #! MD2 !# */
#	ifdef MASTER_HASHLIB_MD4_EXTERN
#		define MASTER_HASHLIB_MD4_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_MD4_USE
#			warning "MD4 is defined to USE, but also defined to EXTERN. MD4 will NOT be compiled."
#		endif /* #! MD4 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_MD4_USE
#			define MASTER_HASHLIB_MD4_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_MD4_IMPLEMENT 0
#		endif /* #! MD4 Use !# */
#	else
#		define MASTER_HASHLIB_MD4_IMPLEMENT 1
#	endif /* #! MD4 !# */
#	ifdef MASTER_HASHLIB_MD5_EXTERN
#		define MASTER_HASHLIB_MD5_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_MD5_USE
#			warning "MD5 is defined to USE, but also defined to EXTERN. MD5 will NOT be compiled."
#		endif /* #! MD5 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_MD5_USE
#			define MASTER_HASHLIB_MD5_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_MD5_IMPLEMENT 0
#		endif /* #! MD5 Use !# */
#	else
#		define MASTER_HASHLIB_MD5_IMPLEMENT 1
#	endif /* #! MD5 !# */
#	ifdef MASTER_HASHLIB_SHA1_EXTERN
#		define MASTER_HASHLIB_SHA1_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_SHA1_USE
#			warning "SHA-1 is defined to USE, but also defined to EXTERN. SHA-1 will NOT be compiled."
#		endif /* #! SHA-1 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_SHA1_USE
#			define MASTER_HASHLIB_SHA1_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_SHA1_IMPLEMENT 0
#		endif /* #! SHA-1 Use !# */
#	else
#		define MASTER_HASHLIB_SHA1_IMPLEMENT 1
#	endif /* #! SHA-1 !# */
#	ifdef MASTER_HASHLIB_RIPEMD128_EXTERN
#		define MASTER_HASHLIB_RIPEMD128_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_RIPEMD128_USE
#			warning "RIPEMD128 is defined to USE, but also defined to EXTERN. RIPEMD128 will NOT be compiled."
#		endif /* #! RIPEMD128 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_RIPEMD128_USE
#			define MASTER_HASHLIB_RIPEMD128_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_RIPEMD128_IMPLEMENT 0
#		endif /* #! RIPEMD128 Use !# */
#	else
#		define MASTER_HASHLIB_RIPEMD128_IMPLEMENT 1
#	endif /* #! RIPEMD128 !# */
#	ifdef MASTER_HASHLIB_RIPEMD160_EXTERN
#		define MASTER_HASHLIB_RIPEMD160_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_RIPEMD160_USE
#			warning "RIPEMD160 is defined to USE, but also defined to EXTERN. RIPEMD160 will NOT be compiled."
#		endif /* #! RIPEMD160 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_RIPEMD160_USE
#			define MASTER_HASHLIB_RIPEMD160_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_RIPEMD160_IMPLEMENT 0
#		endif /* #! RIPEMD160 Use !# */
#	else
#		define MASTER_HASHLIB_RIPEMD160_IMPLEMENT 1
#	endif /* #! RIPEMD160 !# */
#	ifdef MASTER_HASHLIB_RIPEMD256_EXTERN
#		define MASTER_HASHLIB_RIPEMD256_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_RIPEMD256_USE
#			warning "RIPEMD256 is defined to USE, but also defined to EXTERN. RIPEMD256 will NOT be compiled."
#		endif /* #! RIPEMD256 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_RIPEMD256_USE
#			define MASTER_HASHLIB_RIPEMD256_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_RIPEMD256_IMPLEMENT 0
#		endif /* #! RIPEMD256 Use !# */
#	else
#		define MASTER_HASHLIB_RIPEMD256_IMPLEMENT 1
#	endif /* #! RIPEMD256 !# */
#	ifdef MASTER_HASHLIB_RIPEMD320_EXTERN
#		define MASTER_HASHLIB_RIPEMD320_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_RIPEMD320_USE
#			warning "RIPEMD320 is defined to USE, but also defined to EXTERN. RIPEMD320 will NOT be compiled."
#		endif /* #! RIPEMD320 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_RIPEMD320_USE
#			define MASTER_HASHLIB_RIPEMD320_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_RIPEMD320_IMPLEMENT 0
#		endif /* #! RIPEMD320 Use !# */
#	else
#		define MASTER_HASHLIB_RIPEMD320_IMPLEMENT 1
#	endif /* #! RIPEMD320 !# */
#	ifdef MASTER_HASHLIB_MURMURHASH2A_EXTERN
#		define MASTER_HASHLIB_MURMURHASH2A_IMPLEMENT 0
#		ifdef MASTER_HASHLIB_MURMURHASH2A_USE
#			warning "MurmurHash2A is defined to USE, but also defined to EXTERN. MurmurHash2A will NOT be compiled."
#		endif /* #! MurmurHash2A Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_MURMURHASH2A_USE
#			define MASTER_HASHLIB_MURMURHASH2A_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_MURMURHASH2A_IMPLEMENT 0
#		endif /* #! MurmurHash2A Use !# */
#	else
#		define MASTER_HASHLIB_MURMURHASH2A_IMPLEMENT 1
#	endif /* #! MurmurHash2A !# */
#	undef MASTER_HASHLIB_WHITELIST_MODE
#endif /* #! MASTER_HASHLIB_EXTERN_ONLY !# */

typedef enum {
	MASTER_HASHLIB_MD2_ID = 0,
	MASTER_HASHLIB_MD4_ID = 1,
	MASTER_HASHLIB_MD5_ID = 2,
	MASTER_HASHLIB_SHA1_ID = 3,
	MASTER_HASHLIB_RIPEMD128_ID = 4,
	MASTER_HASHLIB_RIPEMD160_ID = 5,
	MASTER_HASHLIB_RIPEMD256_ID = 6,
	MASTER_HASHLIB_RIPEMD320_ID = 7,
	MASTER_HASHLIB_MURMURHASH2A_ID = 8,
	MASTER_HASHLIB_MIN_ID = MASTER_HASHLIB_MD2_ID,
	MASTER_HASHLIB_MAX_ID = MASTER_HASHLIB_MURMURHASH2A_ID
} MASTER_Hashlib_Algorithms;

#define MASTER_HASHLIB_MD2_DIGEST_SIZE 128
#define MASTER_HASHLIB_MD4_DIGEST_SIZE 128
#define MASTER_HASHLIB_MD5_DIGEST_SIZE 128
#define MASTER_HASHLIB_SHA1_DIGEST_SIZE 160
#define MASTER_HASHLIB_RIPEMD128_DIGEST_SIZE 128
#define MASTER_HASHLIB_RIPEMD160_DIGEST_SIZE 160
#define MASTER_HASHLIB_RIPEMD256_DIGEST_SIZE 256
#define MASTER_HASHLIB_RIPEMD320_DIGEST_SIZE 320
#define MASTER_HASHLIB_MURMURHASH2A_DIGEST_SIZE 32
#define MASTER_HASHLIB_MIN_DIGEST_SIZE 32
#define MASTER_HASHLIB_MAX_DIGEST_SIZE 320

#define MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( macrofunc ) \
	macrofunc( MD2, MD2, md2c ) \
	macrofunc( MD4, MD4, md4c ) \
	macrofunc( MD5, MD5, md5c ) \
	macrofunc( SHA1, SHA1, sha1c ) \
	macrofunc( RIPEMD128, RIPEMD128, ripemd128c ) \
	macrofunc( RIPEMD160, RIPEMD160, ripemd160c ) \
	macrofunc( RIPEMD256, RIPEMD256, ripemd256c ) \
	macrofunc( RIPEMD320, RIPEMD320, ripemd320c ) \
	macrofunc( MURMURHASH2A, MurmurHash2A, murmurhash2a )

/* #! MD2 !# */

typedef struct {
	UI1 state[16];
	UI1 checksum[16];
	UI1 buffer[16];
	UI1 counter;
} MASTER_Hashlib_MD2_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_MD2_Context, MASTER_Hashlib_MD2_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD2_Init, ( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_MD2_Flush MASTER_Hashlib_MD2_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD2_Update, ( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD2_Finish, ( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD2_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

MASTER_PREFER_EXTERN const UI1 MASTER_Hashlib_MD2_Table1[256];

#if MASTER_HASHLIB_MD2_IMPLEMENT == 1

void
MASTER_Hashlib_MD2_Init( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT md2c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	for (; index < 16; index += 1) {
		md2c->state[index] = 0;
		md2c->checksum[index] = 0;
		md2c->buffer[index] = 0;
	}
	md2c->counter = 0;
}

MASTER_Hashlib_MD2_Context
MASTER_Hashlib_MD2_Create( void ) {
	MASTER_Hashlib_MD2_Context md2c;
	MASTER_Hashlib_MD2_Init(&md2c);
	return md2c;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_MD2_Process( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT md2c, const UI1 * const MASTER_PREFER_RESTRICT inData ) {
	UI1 chunk[48];
	UI1 timevar = 0;
	UI1 index = 0;
	UI1 jndex;
	for (; index < 16; index += 1) {
		chunk[index] = md2c->state[index];
		chunk[index | 16] = inData[index];
		chunk[index | 32] = chunk[index] ^ chunk[index | 16];
	}
	for (index = 0; index < 18; index += 1) {
		for (jndex = 0; jndex < 48; jndex += 1)
			timevar = (chunk[jndex] ^= MASTER_Hashlib_MD2_Table1[timevar]);
		timevar += index;
	}
	for (index = 0; index < 16; index += 1)
		md2c->state[index] = chunk[index];
	timevar = md2c->checksum[15];
	for (index = 0; index < 16; index += 1)
		timevar = (md2c->checksum[index] ^= MASTER_Hashlib_MD2_Table1[inData[index] ^ timevar]);
}

void
MASTER_Hashlib_MD2_Update( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT md2c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	UI1 toRead;
	MASTER_zRIVATE_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	if (md2c->counter > 0) {
		toRead = 16 - md2c->counter;
		if (len < toRead) {
			MASTER_MEMCPY(md2c->buffer + md2c->counter, (const UI1 *)bytes, len);
			md2c->counter += len;
			return;
		}
		MASTER_MEMCPY(md2c->buffer + md2c->counter, (const UI1 *)bytes, toRead);
		MASTER_Hashlib_MD2_Process(md2c, md2c->buffer);
		md2c->counter = 0;
		bytes = (const UI1 *)bytes + toRead;
		len -= toRead;
	}
	while (len >= 16) {
		MASTER_Hashlib_MD2_Process(md2c, (const UI1 *)bytes);
		bytes = (const UI1 *)bytes + 16;
		len -= 16;
	}
	if (len > 0) {
		MASTER_MEMCPY(md2c->buffer, (const UI1 *)bytes, len);
		md2c->counter = len;
	}
}

void
MASTER_Hashlib_MD2_Finish( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT md2c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 estlen;
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	estlen = 16 - md2c->counter;
	for (index = 16 - estlen; index < 16; index += 1)
		md2c->buffer[index] = estlen;
	MASTER_Hashlib_MD2_Process(md2c, md2c->buffer);
	for (index = 0; index < 16; index += 1)
		md2c->buffer[index] = md2c->checksum[index];
	MASTER_Hashlib_MD2_Process(md2c, md2c->buffer);
	for (index = 0; index < 16; index += 1)
		output[index] = md2c->state[index];
}

void
MASTER_Hashlib_MD2_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_MD2_Context md2c = MASTER_Hashlib_MD2_Create();
	MASTER_Hashlib_MD2_Update(&md2c, bytes, len);
	MASTER_Hashlib_MD2_Finish(&md2c, output);
}

const UI1 MASTER_Hashlib_MD2_Table1[256] = {
	41, 46, 67, 201, 162, 216, 124, 1, 61, 54, 84, 161, 236, 240, 6, 19,
	98, 167, 5, 243, 192, 199, 115, 140, 152, 147, 43, 217, 188, 76, 130, 202,
	30, 155, 87, 60, 253, 212, 224, 22, 103, 66, 111, 24, 138, 23, 229, 18,
	190, 78, 196, 214, 218, 158, 222, 73, 160, 251, 245, 142, 187, 47, 238, 122,
	169, 104, 121, 145, 21, 178, 7, 63, 148, 194, 16, 137, 11, 34, 95, 33,
	128, 127, 93, 154, 90, 144, 50, 39, 53, 62, 204, 231, 191, 247, 151, 3,
	255, 25, 48, 179, 72, 165, 181, 209, 215, 94, 146, 42, 172, 86, 170, 198,
	79, 184, 56, 210, 150, 164, 125, 182, 118, 252, 107, 226, 156, 116, 4, 241,
	69, 157, 112, 89, 100, 113, 135, 32, 134, 91, 207, 101, 230, 45, 168, 2,
	27, 96, 37, 173, 174, 176, 185, 246, 28, 70, 97, 105, 52, 64, 126, 15,
	85, 71, 163, 35, 221, 81, 175, 58, 195, 92, 249, 206, 186, 197, 234, 38,
	44, 83, 13, 110, 133, 40, 132, 9, 211, 223, 205, 244, 65, 129, 77, 82,
	106, 220, 55, 200, 108, 193, 171, 250, 36, 225, 123, 8, 12, 189, 177, 74,
	120, 136, 149, 139, 227, 99, 232, 109, 233, 203, 213, 254, 59, 0, 29, 57,
	242, 239, 183, 14, 102, 88, 208, 228, 166, 119, 114, 248, 235, 117, 75, 10,
	49, 68, 80, 180, 143, 237, 31, 26, 219, 153, 141, 51, 159, 17, 131, 20
};

#endif /* #! MD2 !# */

/* #! MD4 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[4];
} MASTER_Hashlib_MD4_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_MD4_Context, MASTER_Hashlib_MD4_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD4_Init, ( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_MD4_Flush MASTER_Hashlib_MD4_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD4_Update, ( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD4_Finish, ( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD4_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_HASHLIB_MD4_IMPLEMENT == 1

#define MASTER_HASHLIB_MD4_FUNC1( alpha, beta, gamma, zeta, epsilon, teta ) (alpha) = MASTER_RLL4((alpha) + (epsilon) + MASTER_OPERATION_CHOICE(beta, gamma, zeta), teta)
#define MASTER_HASHLIB_MD4_FUNC2( alpha, beta, gamma, zeta, epsilon, teta ) (alpha) = MASTER_RLL4((alpha) + (epsilon) + 0x5A827999 + MASTER_OPERATION_MAJORITAR(beta, gamma, zeta), teta)
#define MASTER_HASHLIB_MD4_FUNC3( alpha, beta, gamma, zeta, epsilon, teta ) (alpha) = MASTER_RLL4((alpha) + (epsilon) + 0x6ED9EBA1 + MASTER_OPERATION_XOR3(beta, gamma, zeta), teta)

void
MASTER_Hashlib_MD4_Init( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT md4c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( md4c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		md4c->buffer[index] = 0;
	md4c->count[0] = md4c->count[1] = 0;
	md4c->state[0] = 0x67452301;
	md4c->state[1] = 0xEFCDAB89;
	md4c->state[2] = 0x98BADCFE;
	md4c->state[3] = 0x10325476;
}

MASTER_Hashlib_MD4_Context
MASTER_Hashlib_MD4_Create( void ) {
	MASTER_Hashlib_MD4_Context md4c;
	MASTER_Hashlib_MD4_Init(&md4c);
	return md4c;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_MD4_Process( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT md4c, const UI1 * const MASTER_PREFER_RESTRICT inData ) {
	UI4 chunk[16];
	UI4 wordA = md4c->state[0];
	UI4 wordB = md4c->state[1];
	UI4 wordC = md4c->state[2];
	UI4 wordD = md4c->state[3];
	UI1 index = 0;
#if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
	MASTER_MEMCPY(chunk, inData, 64);
#elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
	MASTER_MEMCPY(chunk, inData, 64);
	for (; index < 16; index += 1)
		chunk[index] = MASTER_BSWAP4(chunk[index]);
#else
	for (; index < 16; index += 1)
		chunk[index] = (inData[3 | (index << 2)] << 24) | (inData[2 | (index << 2)] << 16) | (inData[1 | (index << 2)] << 8) | inData[index << 2];
#endif /* #! Endian !# */
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD4_FUNC1( wordA, wordB, wordC, wordD, chunk[index << 2], 3);
		MASTER_HASHLIB_MD4_FUNC1( wordD, wordA, wordB, wordC, chunk[(index << 2) | 1], 7);
		MASTER_HASHLIB_MD4_FUNC1( wordC, wordD, wordA, wordB, chunk[(index << 2) | 2], 11);
		MASTER_HASHLIB_MD4_FUNC1( wordB, wordC, wordD, wordA, chunk[(index << 2) | 3], 19);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD4_FUNC2( wordA, wordB, wordC, wordD, chunk[index], 3);
		MASTER_HASHLIB_MD4_FUNC2( wordD, wordA, wordB, wordC, chunk[index | 4], 5);
		MASTER_HASHLIB_MD4_FUNC2( wordC, wordD, wordA, wordB, chunk[index | 8], 9);
		MASTER_HASHLIB_MD4_FUNC2( wordB, wordC, wordD, wordA, chunk[index | 12], 13);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD4_FUNC3( wordA, wordB, wordC, wordD, chunk[((index & 1) << 1) | ((index & 2) >> 1)], 3);
		MASTER_HASHLIB_MD4_FUNC3( wordD, wordA, wordB, wordC, chunk[(((index & 1) << 1) | ((index & 2) >> 1)) | 8], 9);
		MASTER_HASHLIB_MD4_FUNC3( wordC, wordD, wordA, wordB, chunk[(((index & 1) << 1) | ((index & 2) >> 1)) | 4], 11);
		MASTER_HASHLIB_MD4_FUNC3( wordB, wordC, wordD, wordA, chunk[(((index & 1) << 1) | ((index & 2) >> 1)) | 12], 15);
	}
	md4c->state[0] += wordA;
	md4c->state[1] += wordB;
	md4c->state[2] += wordC;
	md4c->state[3] += wordD;
}

#define MASTER_Hashlib_MerkleDamgard_Update( mdc, bytes, len, process ) do { \
		UI1 toRead; \
		MASTER_zRIVATE_CHECK_NUL_RETURN( mdc, MASTER_NOTHING ); \
		MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING ); \
		if (mdc->count[0] & 0x3F) { \
			toRead = 64 - (mdc->count[0] & 0x3F); \
			if (len < toRead) { \
				MASTER_MEMCPY(mdc->buffer + (mdc->count[0] & 0x3F), (const UI1 *)bytes, len); \
				mdc->count[0] += len; \
				if (mdc->count[0] < len) \
					mdc->count[1] += 1; \
				return; \
			} \
			MASTER_MEMCPY(mdc->buffer + (mdc->count[0] & 0x3F), (const UI1 *)bytes, toRead); \
			process(mdc, mdc->buffer); \
			mdc->count[0] += toRead; \
			if (mdc->count[0] < toRead) \
				mdc->count[1] += 1; \
			bytes = (const UI1 *)bytes + toRead; \
			len -= toRead; \
		} \
		while (len >= 64) { \
			process(mdc, (const UI1 *)bytes); \
			mdc->count[0] += 64; \
			if (mdc->count[0] < 64) \
				mdc->count[1] += 1; \
			bytes = (const UI1 *)bytes + 64; \
			len -= 64; \
		} \
		if (len > 0) { \
			MASTER_MEMCPY(mdc->buffer, (const UI1 *)bytes, len); \
			mdc->count[0] += len; \
			if (mdc->count[0] < len) \
				mdc->count[1] += 1; \
		} \
	} while (0)

void
MASTER_Hashlib_MD4_Update( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT md4c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	MASTER_Hashlib_MerkleDamgard_Update(md4c, bytes, len, MASTER_Hashlib_MD4_Process);
}

void
MASTER_Hashlib_MD4_Finish( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT md4c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( md4c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = md4c->count[0] & 0x3F;
	md4c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			md4c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			md4c->buffer[index] = 0;
		MASTER_Hashlib_MD4_Process(md4c, md4c->buffer);
		for (index = 0; index < 56; index += 1)
			md4c->buffer[index] = 0;
	}
	md4c->buffer[56] = md4c->count[0] << 3;
	md4c->buffer[57] = md4c->count[0] >> 5;
	md4c->buffer[58] = md4c->count[0] >> 13;
	md4c->buffer[59] = md4c->count[0] >> 21;
	md4c->buffer[60] = (md4c->count[0] >> 29) | (md4c->count[1] << 3);
	md4c->buffer[61] = md4c->count[1] >> 5;
	md4c->buffer[62] = md4c->count[1] >> 13;
	md4c->buffer[63] = md4c->count[1] >> 21;
	MASTER_Hashlib_MD4_Process(md4c, md4c->buffer);
	for (index = 0; index < 4; index += 1) {
		output[index] = md4c->state[0] >> (index << 3);
		output[index | 4] = md4c->state[1] >> (index << 3);
		output[index | 8] = md4c->state[2] >> (index << 3);
		output[index | 12] = md4c->state[3] >> (index << 3);
	}
}

void
MASTER_Hashlib_MD4_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_MD4_Context md4c;
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	md4c = MASTER_Hashlib_MD4_Create();
	MASTER_Hashlib_MD4_Update(&md4c, bytes, len);
	MASTER_Hashlib_MD4_Finish(&md4c, output);
}

#endif /* #! MD4 !# */

/* #! MD5 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[4];
} MASTER_Hashlib_MD5_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_MD5_Context, MASTER_Hashlib_MD5_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD5_Init, ( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_MD5_Flush MASTER_Hashlib_MD5_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD5_Update, ( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD5_Finish, ( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MD5_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

MASTER_PREFER_EXTERN const UI4 MASTER_Hashlib_MD5_Table1[64];

#if MASTER_HASHLIB_MD5_IMPLEMENT == 1

#define MASTER_HASHLIB_MD5_FUNC1( a, b, c, d, x, s, ac ) do { \
		(a) += MASTER_OPERATION_CHOICE(b, c, d) + (x) + (UI4)(ac); \
		(a) = MASTER_RLL4(a, s); \
		(a) += (b); \
	} while (0)
#define MASTER_HASHLIB_MD5_FUNC2( a, b, c, d, x, s, ac ) do { \
		(a) += MASTER_OPERATION_CHOICE(d, b, c) + (x) + (UI4)(ac); \
		(a) = MASTER_RLL4(a, s); \
		(a) += (b); \
	} while (0)
#define MASTER_HASHLIB_MD5_FUNC3( a, b, c, d, x, s, ac ) do { \
		(a) += MASTER_OPERATION_XOR3(b, c, d) + (x) + (UI4)(ac); \
		(a) = MASTER_RLL4(a, s); \
		(a) += (b); \
	} while (0)
#define MASTER_HASHLIB_MD5_FUNC4( a, b, c, d, x, s, ac ) do { \
		(a) += MASTER_OPERATION_2XB1ON3E(b, c, d) + (x) + (UI4)(ac); \
		(a) = MASTER_RLL4(a, s); \
		(a) += (b); \
	} while (0)

void
MASTER_Hashlib_MD5_Init( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT md5c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( md5c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		md5c->buffer[index] = 0;
	md5c->count[0] = md5c->count[1] = 0;
	md5c->state[0] = 0x67452301;
	md5c->state[1] = 0xEFCDAB89;
	md5c->state[2] = 0x98BADCFE;
	md5c->state[3] = 0x10325476;
}

MASTER_Hashlib_MD5_Context
MASTER_Hashlib_MD5_Create( void ) {
	MASTER_Hashlib_MD5_Context md5c;
	MASTER_Hashlib_MD5_Init(&md5c);
	return md5c;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_MD5_Process( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT md5c, const UI1 * const MASTER_PREFER_RESTRICT inData ) {
	UI4 chunk[16];
	UI4 wordA = md5c->state[0];
	UI4 wordB = md5c->state[1];
	UI4 wordC = md5c->state[2];
	UI4 wordD = md5c->state[3];
	UI1 index = 0;
#if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
	MASTER_MEMCPY(chunk, inData, 64);
#elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
	MASTER_MEMCPY(chunk, inData, 64);
	for (; index < 16; index += 1)
		chunk[index] = MASTER_BSWAP4(chunk[index]);
#else
	for (; index < 16; index += 1)
		chunk[index] = (inData[3 | (index << 2)] << 24) | (inData[2 | (index << 2)] << 16) | (inData[1 | (index << 2)] << 8) | inData[index << 2];
#endif /* #! Endian !# */
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD5_FUNC1( wordA, wordB, wordC, wordD, chunk[index << 2], 7, MASTER_Hashlib_MD5_Table1[index << 2]);
		MASTER_HASHLIB_MD5_FUNC1( wordD, wordA, wordB, wordC, chunk[(index << 2) | 1], 12, MASTER_Hashlib_MD5_Table1[(index << 2) | 1]);
		MASTER_HASHLIB_MD5_FUNC1( wordC, wordD, wordA, wordB, chunk[(index << 2) | 2], 17, MASTER_Hashlib_MD5_Table1[(index << 2) | 2]);
		MASTER_HASHLIB_MD5_FUNC1( wordB, wordC, wordD, wordA, chunk[(index << 2) | 3], 22, MASTER_Hashlib_MD5_Table1[(index << 2) | 3]);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD5_FUNC2( wordA, wordB, wordC, wordD, chunk[1 | (index << 2)], 5, MASTER_Hashlib_MD5_Table1[(index << 2) | 16]);
		MASTER_HASHLIB_MD5_FUNC2( wordD, wordA, wordB, wordC, chunk[(6 + (index << 2)) & 0xF], 9, MASTER_Hashlib_MD5_Table1[(index << 2) | 17]);
		MASTER_HASHLIB_MD5_FUNC2( wordC, wordD, wordA, wordB, chunk[(11 + (index << 2)) & 0xF], 14, MASTER_Hashlib_MD5_Table1[(index << 2) | 18]);
		MASTER_HASHLIB_MD5_FUNC2( wordB, wordC, wordD, wordA, chunk[index << 2], 20, MASTER_Hashlib_MD5_Table1[(index << 2) | 19]);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD5_FUNC3( wordA, wordB, wordC, wordD, chunk[(5 + index * 12) & 0xF], 4, MASTER_Hashlib_MD5_Table1[(index << 2) | 32]);
		MASTER_HASHLIB_MD5_FUNC3( wordD, wordA, wordB, wordC, chunk[(8 + index * 12) & 0xF], 11, MASTER_Hashlib_MD5_Table1[(index << 2) | 33]);
		MASTER_HASHLIB_MD5_FUNC3( wordC, wordD, wordA, wordB, chunk[(11 + index * 12) & 0xF], 16, MASTER_Hashlib_MD5_Table1[(index << 2) | 34]);
		MASTER_HASHLIB_MD5_FUNC3( wordB, wordC, wordD, wordA, chunk[(14 + index * 12) & 0xF], 23, MASTER_Hashlib_MD5_Table1[(index << 2) | 35]);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD5_FUNC4( wordA, wordB, wordC, wordD, chunk[(index * 12) & 0xF], 6, MASTER_Hashlib_MD5_Table1[(index << 2) | 48]);
		MASTER_HASHLIB_MD5_FUNC4( wordD, wordA, wordB, wordC, chunk[(7 + index * 12) & 0xF], 10, MASTER_Hashlib_MD5_Table1[(index << 2) | 49]);
		MASTER_HASHLIB_MD5_FUNC4( wordC, wordD, wordA, wordB, chunk[(14 + index * 12) & 0xF], 15, MASTER_Hashlib_MD5_Table1[(index << 2) | 50]);
		MASTER_HASHLIB_MD5_FUNC4( wordB, wordC, wordD, wordA, chunk[(5 + index * 12) & 0xF], 21, MASTER_Hashlib_MD5_Table1[(index << 2) | 51]);
	}
	md5c->state[0] += wordA;
	md5c->state[1] += wordB;
	md5c->state[2] += wordC;
	md5c->state[3] += wordD;
}

void
MASTER_Hashlib_MD5_Update( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT md5c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	MASTER_Hashlib_MerkleDamgard_Update(md5c, bytes, len, MASTER_Hashlib_MD5_Process);
	/*
	while (len > 0) {
		md5c->buffer[md5c->count[0] & 0x3F] = *(const UI1 *)bytes;
		md5c->count[0] += 1;
		if (md5c->count[0] == 0)
			md5c->count[1] += 1;
		if ((md5c->count[0] & 0x3F) == 0)
			MASTER_Hashlib_MD5_Process(md5c);
		bytes = (const UI1 *)bytes + 1;
		len -= 1;
	}
	*/
}

void
MASTER_Hashlib_MD5_Finish( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT md5c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( md5c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = md5c->count[0] & 0x3F;
	md5c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			md5c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			md5c->buffer[index] = 0;
		MASTER_Hashlib_MD5_Process(md5c, md5c->buffer);
		for (index = 0; index < 56; index += 1)
			md5c->buffer[index] = 0;
	}
	md5c->buffer[56] = md5c->count[0] << 3;
	md5c->buffer[57] = md5c->count[0] >> 5;
	md5c->buffer[58] = md5c->count[0] >> 13;
	md5c->buffer[59] = md5c->count[0] >> 21;
	md5c->buffer[60] = (md5c->count[0] >> 29) | (md5c->count[1] << 3);
	md5c->buffer[61] = md5c->count[1] >> 5;
	md5c->buffer[62] = md5c->count[1] >> 13;
	md5c->buffer[63] = md5c->count[1] >> 21;
	MASTER_Hashlib_MD5_Process(md5c, md5c->buffer);
	for (index = 0; index < 4; index += 1) {
		output[index] = md5c->state[0] >> (index << 3);
		output[index | 4] = md5c->state[1] >> (index << 3);
		output[index | 8] = md5c->state[2] >> (index << 3);
		output[index | 12] = md5c->state[3] >> (index << 3);
	}
}

void
MASTER_Hashlib_MD5_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_MD5_Context md5c;
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	md5c = MASTER_Hashlib_MD5_Create();
	MASTER_Hashlib_MD5_Update(&md5c, bytes, len);
	MASTER_Hashlib_MD5_Finish(&md5c, output);
}

const UI4 MASTER_Hashlib_MD5_Table1[64] = {
	0xD76AA478, 0xE8C7B756, 0x242070DB, 0xC1BDCEEE, 0xF57C0FAF, 0x4787C62A, 0xA8304613, 0xFD469501,
	0x698098D8, 0x8B44F7AF, 0xFFFF5BB1, 0x895CD7BE, 0x6B901122, 0xFD987193, 0xA679438E, 0x49B40821,
	0xF61E2562, 0xC040B340, 0x265E5A51, 0xE9B6C7AA, 0xD62F105D, 0x2441453, 0xD8A1E681, 0xE7D3FBC8,
	0x21E1CDE6, 0xC33707D6, 0xF4D50D87, 0x455A14ED, 0xA9E3E905, 0xFCEFA3F8, 0x676F02D9, 0x8D2A4C8A,
	0xFFFA3942, 0x8771F681, 0x6D9D6122, 0xFDE5380C, 0xA4BEEA44, 0x4BDECFA9, 0xF6BB4B60, 0xBEBFBC70,
	0x289B7EC6, 0xEAA127FA, 0xD4EF3085, 0x4881D05, 0xD9D4D039, 0xE6DB99E5, 0x1FA27CF8, 0xC4AC5665,
	0xF4292244, 0x432AFF97, 0xAB9423A7, 0xFC93A039, 0x655B59C3, 0x8F0CCC92, 0xFFEFF47D, 0x85845DD1,
	0x6FA87E4F, 0xFE2CE6E0, 0xA3014314, 0x4E0811A1, 0xF7537E82, 0xBD3AF235, 0x2AD7D2BB, 0xEB86D391
};

#endif /* #! MD5 !# */

/* #! SHA-1 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[5];
} MASTER_Hashlib_SHA1_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_SHA1_Context, MASTER_Hashlib_SHA1_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA1_Init, ( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_SHA1_Flush MASTER_Hashlib_SHA1_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA1_Update, ( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA1_Finish, ( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA1_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

MASTER_PREFER_EXTERN const UI4 MASTER_Hashlib_SHA1_Table1[4];

#if MASTER_HASHLIB_SHA1_IMPLEMENT == 1

void
MASTER_Hashlib_SHA1_Init( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT sha1c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( sha1c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		sha1c->buffer[index] = 0;
	sha1c->count[0] = sha1c->count[1] = 0;
	sha1c->state[0] = 0x67452301;
	sha1c->state[1] = 0xEFCDAB89;
	sha1c->state[2] = 0x98BADCFE;
	sha1c->state[3] = 0x10325476;
	sha1c->state[4] = 0xC3D2E1F0;
}

MASTER_Hashlib_SHA1_Context
MASTER_Hashlib_SHA1_Create( void ) {
	MASTER_Hashlib_SHA1_Context sha1c;
	MASTER_Hashlib_SHA1_Init(&sha1c);
	return sha1c;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_SHA1_Process( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT sha1c, const UI1 * const MASTER_PREFER_RESTRICT inData ) {
	UI4 chunk[80];
	UI4 wordA = sha1c->state[0];
	UI4 wordB = sha1c->state[1];
	UI4 wordC = sha1c->state[2];
	UI4 wordD = sha1c->state[3];
	UI4 wordE = sha1c->state[4];
	UI4 timevar;
#if MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
	UI1 index = 16;
	MASTER_MEMCPY(chunk, inData, 64);
#elif MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
	UI1 index = 0;
	MASTER_MEMCPY(chunk, inData, 64);
	for (; index < 16; index += 1)
		chunk[index] = MASTER_BSWAP4(chunk[index]);
#else
	UI1 index = 0;
	for (; index < 16; index += 1)
		chunk[index] = (inData[index << 2] << 24) | (inData[1 | (index << 2)] << 16) | (inData[2 | (index << 2)] << 8) | inData[3 | (index << 2)];
#endif /* #! Endian !# */
	for (; index < 80; index += 1)
		chunk[index] = MASTER_RLL4(chunk[index - 3] ^ chunk[index - 8] ^ chunk[index - 14] ^ chunk[index - 16], 1);
	for (index = 0; index < 20; index += 1) {
		timevar = MASTER_RLL4(wordA, 5) + ((wordB & wordC) | ((~wordB) & wordD)) + wordE + chunk[index] + MASTER_Hashlib_SHA1_Table1[0];
		wordE = wordD;
		wordD = wordC;
		wordC = MASTER_RLL4(wordB, 30);
		wordB = wordA;
		wordA = timevar;
	}
	for (; index < 40; index += 1) {
		timevar = MASTER_RLL4(wordA, 5) + (wordB ^ wordC ^ wordD) + wordE + chunk[index] + MASTER_Hashlib_SHA1_Table1[1];
		wordE = wordD;
		wordD = wordC;
		wordC = MASTER_RLL4(wordB, 30);
		wordB = wordA;
		wordA = timevar;
	}
	for (; index < 60; index += 1) {
		timevar = MASTER_RLL4(wordA, 5) + ((wordB & wordC) | (wordB & wordD) | (wordC & wordD)) + wordE + chunk[index] + MASTER_Hashlib_SHA1_Table1[2];
		wordE = wordD;
		wordD = wordC;
		wordC = MASTER_RLL4(wordB, 30);
		wordB = wordA;
		wordA = timevar;
	}
	for (; index < 80; index += 1) {
		timevar = MASTER_RLL4(wordA, 5) + (wordB ^ wordC ^ wordD) + wordE + chunk[index] + MASTER_Hashlib_SHA1_Table1[3];
		wordE = wordD;
		wordD = wordC;
		wordC = MASTER_RLL4(wordB, 30);
		wordB = wordA;
		wordA = timevar;
	}
	sha1c->state[0] += wordA;
	sha1c->state[1] += wordB;
	sha1c->state[2] += wordC;
	sha1c->state[3] += wordD;
	sha1c->state[4] += wordE;
}

void
MASTER_Hashlib_SHA1_Update( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT sha1c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	MASTER_Hashlib_MerkleDamgard_Update(sha1c, bytes, len, MASTER_Hashlib_SHA1_Process);
}

void
MASTER_Hashlib_SHA1_Finish( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT sha1c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( sha1c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = sha1c->count[0] & 0x3F;
	sha1c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			sha1c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			sha1c->buffer[index] = 0;
		MASTER_Hashlib_SHA1_Process(sha1c, sha1c->buffer);
		for (index = 0; index < 56; index += 1)
			sha1c->buffer[index] = 0;
	}
	sha1c->buffer[63] = sha1c->count[0] << 3;
	sha1c->buffer[62] = sha1c->count[0] >> 5;
	sha1c->buffer[61] = sha1c->count[0] >> 13;
	sha1c->buffer[60] = sha1c->count[0] >> 21;
	sha1c->buffer[59] = (sha1c->count[0] >> 29) | (sha1c->count[1] << 3);
	sha1c->buffer[58] = sha1c->count[1] >> 5;
	sha1c->buffer[57] = sha1c->count[1] >> 13;
	sha1c->buffer[56] = sha1c->count[1] >> 21;
	MASTER_Hashlib_SHA1_Process(sha1c, sha1c->buffer);
	for (index = 0; index < 4; index += 1) {
		output[index] = sha1c->state[0] >> ((3 - index) << 3);
		output[index | 4] = sha1c->state[1] >> ((3 - index) << 3);
		output[index | 8] = sha1c->state[2] >> ((3 - index) << 3);
		output[index | 12] = sha1c->state[3] >> ((3 - index) << 3);
		output[index | 16] = sha1c->state[4] >> ((3 - index) << 3);
	}
}

void
MASTER_Hashlib_SHA1_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_SHA1_Context sha1c;
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	sha1c = MASTER_Hashlib_SHA1_Create();
	MASTER_Hashlib_SHA1_Update(&sha1c, bytes, len);
	MASTER_Hashlib_SHA1_Finish(&sha1c, output);
}

const UI4 MASTER_Hashlib_SHA1_Table1[4] = {
	0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6
};

#endif /* #! SHA1 !# */

/* #! RIPEMD-128 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[4];
} MASTER_Hashlib_RIPEMD128_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_RIPEMD128_Context, MASTER_Hashlib_RIPEMD128_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD128_Init, ( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_RIPEMD128_Flush MASTER_Hashlib_RIPEMD128_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD128_Update, ( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT, const void *, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD128_Finish, ( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD128_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

MASTER_PREFER_EXTERN const UI4 MASTER_Hashlib_RIPEMD128_Table1[8];
MASTER_PREFER_EXTERN const UI1 MASTER_Hashlib_RIPEMD128_Table2[128];
MASTER_PREFER_EXTERN const UI1 MASTER_Hashlib_RIPEMD128_Table3[128];

#if MASTER_HASHLIB_RIPEMD128_IMPLEMENT == 1

#define MASTER_HASHLIB_RIPEMD128_FUNC1_1( word1, word2, word3, word4, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_XOR3(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD128_Table1[0], shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD128_FUNC2_1( word1, word2, word3, word4, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD128_Table1[1], shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD128_FUNC3_1( word1, word2, word3, word4, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_3XB1ON2E(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD128_Table1[2], shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD128_FUNC4_1( word1, word2, word3, word4, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word4, word2, word3) + (plate) + MASTER_Hashlib_RIPEMD128_Table1[3], shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD128_FUNC1_2( word1, word2, word3, word4, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word4, word2, word3) + (plate) + MASTER_Hashlib_RIPEMD128_Table1[4], shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD128_FUNC2_2( word1, word2, word3, word4, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_3XB1ON2E(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD128_Table1[5], shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD128_FUNC3_2( word1, word2, word3, word4, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD128_Table1[6], shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD128_FUNC4_2( word1, word2, word3, word4, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_XOR3(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD128_Table1[7], shift); \
	} while (0)

void
MASTER_Hashlib_RIPEMD128_Init( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT ripemd128c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( ripemd128c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		ripemd128c->buffer[index] = 0;
	ripemd128c->count[0] = ripemd128c->count[1] = 0;
	ripemd128c->state[0] = 0x67452301;
	ripemd128c->state[1] = 0xEFCDAB89;
	ripemd128c->state[2] = 0x98BADCFE;
	ripemd128c->state[3] = 0x10325476;
}

MASTER_Hashlib_RIPEMD128_Context
MASTER_Hashlib_RIPEMD128_Create( void ) {
	MASTER_Hashlib_RIPEMD128_Context ripemd128c;
	MASTER_Hashlib_RIPEMD128_Init(&ripemd128c);
	return ripemd128c;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_RIPEMD128_Process( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT ripemd128c, const UI1 * const inData ) {
	UI4 chunk[16];
	UI4 wordA1 = ripemd128c->state[0];
	UI4 wordB1 = ripemd128c->state[1];
	UI4 wordC1 = ripemd128c->state[2];
	UI4 wordD1 = ripemd128c->state[3];
	UI4 wordA2 = wordA1;
	UI4 wordB2 = wordB1;
	UI4 wordC2 = wordC1;
	UI4 wordD2 = wordD1;
#if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
	MASTER_MEMCPY(chunk, inData, 64);
#elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
	UI1 index = 0;
	MASTER_MEMCPY(chunk, inData, 64);
	for (; index < 16; index += 1)
		chunk[index] = MASTER_BSWAP4(chunk[index]);
#else
	UI1 index = 0;
	for (; index < 16; index += 1)
		chunk[index] = (inData[3 | (index << 2)] << 24) | (inData[2 | (index << 2)] << 16) | (inData[1 | (index << 2)] << 8) | inData[index << 2];
#endif /* #! Endian !# */
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordA1, wordB1, wordC1, wordD1, chunk[0], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordD1, wordA1, wordB1, wordC1, chunk[1], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordC1, wordD1, wordA1, wordB1, chunk[2], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordB1, wordC1, wordD1, wordA1, chunk[3], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordA1, wordB1, wordC1, wordD1, chunk[4], 5);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordD1, wordA1, wordB1, wordC1, chunk[5], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordC1, wordD1, wordA1, wordB1, chunk[6], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordB1, wordC1, wordD1, wordA1, chunk[7], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordA1, wordB1, wordC1, wordD1, chunk[8], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordD1, wordA1, wordB1, wordC1, chunk[9], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordC1, wordD1, wordA1, wordB1, chunk[10], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordB1, wordC1, wordD1, wordA1, chunk[11], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordA1, wordB1, wordC1, wordD1, chunk[12], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordD1, wordA1, wordB1, wordC1, chunk[13], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordC1, wordD1, wordA1, wordB1, chunk[14], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC1_1(wordB1, wordC1, wordD1, wordA1, chunk[15], 8);

	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordA1, wordB1, wordC1, wordD1, chunk[7], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordD1, wordA1, wordB1, wordC1, chunk[4], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordC1, wordD1, wordA1, wordB1, chunk[13], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordB1, wordC1, wordD1, wordA1, chunk[1], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordA1, wordB1, wordC1, wordD1, chunk[10], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordD1, wordA1, wordB1, wordC1, chunk[6], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordC1, wordD1, wordA1, wordB1, chunk[15], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordB1, wordC1, wordD1, wordA1, chunk[3], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordA1, wordB1, wordC1, wordD1, chunk[12], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordD1, wordA1, wordB1, wordC1, chunk[0], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordC1, wordD1, wordA1, wordB1, chunk[9], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordB1, wordC1, wordD1, wordA1, chunk[5], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordA1, wordB1, wordC1, wordD1, chunk[2], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordD1, wordA1, wordB1, wordC1, chunk[14], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordC1, wordD1, wordA1, wordB1, chunk[11], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC2_1(wordB1, wordC1, wordD1, wordA1, chunk[8], 12);

	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordA1, wordB1, wordC1, wordD1, chunk[3], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordD1, wordA1, wordB1, wordC1, chunk[10], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordC1, wordD1, wordA1, wordB1, chunk[14], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordB1, wordC1, wordD1, wordA1, chunk[4], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordA1, wordB1, wordC1, wordD1, chunk[9], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordD1, wordA1, wordB1, wordC1, chunk[15], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordC1, wordD1, wordA1, wordB1, chunk[8], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordB1, wordC1, wordD1, wordA1, chunk[1], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordA1, wordB1, wordC1, wordD1, chunk[2], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordD1, wordA1, wordB1, wordC1, chunk[7], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordC1, wordD1, wordA1, wordB1, chunk[0], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordB1, wordC1, wordD1, wordA1, chunk[6], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordA1, wordB1, wordC1, wordD1, chunk[13], 5);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordD1, wordA1, wordB1, wordC1, chunk[11], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordC1, wordD1, wordA1, wordB1, chunk[5], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC3_1(wordB1, wordC1, wordD1, wordA1, chunk[12], 5);

	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordA1, wordB1, wordC1, wordD1, chunk[1], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordD1, wordA1, wordB1, wordC1, chunk[9], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordC1, wordD1, wordA1, wordB1, chunk[11], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordB1, wordC1, wordD1, wordA1, chunk[10], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordA1, wordB1, wordC1, wordD1, chunk[0], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordD1, wordA1, wordB1, wordC1, chunk[8], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordC1, wordD1, wordA1, wordB1, chunk[12], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordB1, wordC1, wordD1, wordA1, chunk[4], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordA1, wordB1, wordC1, wordD1, chunk[13], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordD1, wordA1, wordB1, wordC1, chunk[3], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordC1, wordD1, wordA1, wordB1, chunk[7], 5);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordB1, wordC1, wordD1, wordA1, chunk[15], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordA1, wordB1, wordC1, wordD1, chunk[14], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordD1, wordA1, wordB1, wordC1, chunk[5], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordC1, wordD1, wordA1, wordB1, chunk[6], 5);
	MASTER_HASHLIB_RIPEMD128_FUNC4_1(wordB1, wordC1, wordD1, wordA1, chunk[2], 12);

	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordA2, wordB2, wordC2, wordD2, chunk[5], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordD2, wordA2, wordB2, wordC2, chunk[14], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordC2, wordD2, wordA2, wordB2, chunk[7], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordB2, wordC2, wordD2, wordA2, chunk[0], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordA2, wordB2, wordC2, wordD2, chunk[9], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordD2, wordA2, wordB2, wordC2, chunk[2], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordC2, wordD2, wordA2, wordB2, chunk[11], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordB2, wordC2, wordD2, wordA2, chunk[4], 5);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordA2, wordB2, wordC2, wordD2, chunk[13], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordD2, wordA2, wordB2, wordC2, chunk[6], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordC2, wordD2, wordA2, wordB2, chunk[15], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordB2, wordC2, wordD2, wordA2, chunk[8], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordA2, wordB2, wordC2, wordD2, chunk[1], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordD2, wordA2, wordB2, wordC2, chunk[10], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordC2, wordD2, wordA2, wordB2, chunk[3], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC1_2(wordB2, wordC2, wordD2, wordA2, chunk[12], 6);

	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordA2, wordB2, wordC2, wordD2, chunk[6], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordD2, wordA2, wordB2, wordC2, chunk[11], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordC2, wordD2, wordA2, wordB2, chunk[3], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordB2, wordC2, wordD2, wordA2, chunk[7], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordA2, wordB2, wordC2, wordD2, chunk[0], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordD2, wordA2, wordB2, wordC2, chunk[13], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordC2, wordD2, wordA2, wordB2, chunk[5], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordB2, wordC2, wordD2, wordA2, chunk[10], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordA2, wordB2, wordC2, wordD2, chunk[14], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordD2, wordA2, wordB2, wordC2, chunk[15], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordC2, wordD2, wordA2, wordB2, chunk[8], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordB2, wordC2, wordD2, wordA2, chunk[12], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordA2, wordB2, wordC2, wordD2, chunk[4], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordD2, wordA2, wordB2, wordC2, chunk[9], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordC2, wordD2, wordA2, wordB2, chunk[1], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC2_2(wordB2, wordC2, wordD2, wordA2, chunk[2], 11);

	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordA2, wordB2, wordC2, wordD2, chunk[15], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordD2, wordA2, wordB2, wordC2, chunk[5], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordC2, wordD2, wordA2, wordB2, chunk[1], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordB2, wordC2, wordD2, wordA2, chunk[3], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordA2, wordB2, wordC2, wordD2, chunk[7], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordD2, wordA2, wordB2, wordC2, chunk[14], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordC2, wordD2, wordA2, wordB2, chunk[6], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordB2, wordC2, wordD2, wordA2, chunk[9], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordA2, wordB2, wordC2, wordD2, chunk[11], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordD2, wordA2, wordB2, wordC2, chunk[8], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordC2, wordD2, wordA2, wordB2, chunk[12], 5);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordB2, wordC2, wordD2, wordA2, chunk[2], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordA2, wordB2, wordC2, wordD2, chunk[10], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordD2, wordA2, wordB2, wordC2, chunk[0], 13);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordC2, wordD2, wordA2, wordB2, chunk[4], 7);
	MASTER_HASHLIB_RIPEMD128_FUNC3_2(wordB2, wordC2, wordD2, wordA2, chunk[13], 5);

	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordA2, wordB2, wordC2, wordD2, chunk[8], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordD2, wordA2, wordB2, wordC2, chunk[6], 5);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordC2, wordD2, wordA2, wordB2, chunk[4], 8);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordB2, wordC2, wordD2, wordA2, chunk[1], 11);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordA2, wordB2, wordC2, wordD2, chunk[3], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordD2, wordA2, wordB2, wordC2, chunk[11], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordC2, wordD2, wordA2, wordB2, chunk[15], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordB2, wordC2, wordD2, wordA2, chunk[0], 14);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordA2, wordB2, wordC2, wordD2, chunk[5], 6);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordD2, wordA2, wordB2, wordC2, chunk[12], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordC2, wordD2, wordA2, wordB2, chunk[2], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordB2, wordC2, wordD2, wordA2, chunk[13], 9);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordA2, wordB2, wordC2, wordD2, chunk[9], 12);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordD2, wordA2, wordB2, wordC2, chunk[7], 5);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordC2, wordD2, wordA2, wordB2, chunk[10], 15);
	MASTER_HASHLIB_RIPEMD128_FUNC4_2(wordB2, wordC2, wordD2, wordA2, chunk[14], 8);
	wordD2 += wordC1 + ripemd128c->state[1];
	ripemd128c->state[1] = ripemd128c->state[2] + wordD1 + wordA2;
	ripemd128c->state[2] = ripemd128c->state[3] + wordA1 + wordB2;
	ripemd128c->state[3] = ripemd128c->state[0] + wordB1 + wordC2;
	ripemd128c->state[0] = wordD2;
}

void
MASTER_Hashlib_RIPEMD128_Update( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT ripemd128c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	MASTER_Hashlib_MerkleDamgard_Update(ripemd128c, bytes, len, MASTER_Hashlib_RIPEMD128_Process);
}

void
MASTER_Hashlib_RIPEMD128_Finish( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT ripemd128c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( ripemd128c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = ripemd128c->count[0] & 0x3F;
	ripemd128c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			ripemd128c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			ripemd128c->buffer[index] = 0;
		MASTER_Hashlib_RIPEMD128_Process(ripemd128c, ripemd128c->buffer);
		for (index = 0; index < 56; index += 1)
			ripemd128c->buffer[index] = 0;
	}
	ripemd128c->buffer[56] = ripemd128c->count[0] << 3;
	ripemd128c->buffer[57] = ripemd128c->count[0] >> 5;
	ripemd128c->buffer[58] = ripemd128c->count[0] >> 13;
	ripemd128c->buffer[59] = ripemd128c->count[0] >> 21;
	ripemd128c->buffer[60] = (ripemd128c->count[0] >> 29) | (ripemd128c->count[1] << 3);
	ripemd128c->buffer[61] = ripemd128c->count[1] >> 5;
	ripemd128c->buffer[62] = ripemd128c->count[1] >> 13;
	ripemd128c->buffer[63] = ripemd128c->count[1] >> 21;
	MASTER_Hashlib_RIPEMD128_Process(ripemd128c, ripemd128c->buffer);
	for (index = 0; index < 4; index += 1) {
		output[index] = ripemd128c->state[0] >> (index << 3);
		output[index | 4] = ripemd128c->state[1] >> (index << 3);
		output[index | 8] = ripemd128c->state[2] >> (index << 3);
		output[index | 12] = ripemd128c->state[3] >> (index << 3);
	}
}

void
MASTER_Hashlib_RIPEMD128_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_RIPEMD128_Context ripemd128c;
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	ripemd128c = MASTER_Hashlib_RIPEMD128_Create();
	MASTER_Hashlib_RIPEMD128_Update(&ripemd128c, bytes, len);
	MASTER_Hashlib_RIPEMD128_Finish(&ripemd128c, output);
}

const UI4 MASTER_Hashlib_RIPEMD128_Table1[8] = {
	0x00000000, 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC,
	0x50A28BE6, 0x5C4DD124, 0x6D703EF3, 0x00000000
};

#endif /* #! RIPEMD128 !# */

/* #! RIPEMD-160 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[5];
} MASTER_Hashlib_RIPEMD160_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_RIPEMD160_Context, MASTER_Hashlib_RIPEMD160_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD160_Init, ( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_RIPEMD160_Flush MASTER_Hashlib_RIPEMD160_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD160_Update, ( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD160_Finish, ( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD160_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

MASTER_PREFER_EXTERN const UI4 MASTER_Hashlib_RIPEMD160_Table1[10];

#if MASTER_HASHLIB_RIPEMD160_IMPLEMENT == 1

#define MASTER_HASHLIB_RIPEMD160_FUNC1_1( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_XOR3(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[0], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC2_1( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[1], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC3_1( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_3XB1ON2E(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[2], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC4_1( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word4, word2, word3) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[3], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC5_1( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_1XB2ON3E(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[4], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC1_2( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_1XB2ON3E(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[5], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC2_2( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word4, word2, word3) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[6], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC3_2( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_3XB1ON2E(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[7], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC4_2( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[8], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD160_FUNC5_2( word1, word2, word3, word4, word5, plate, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_XOR3(word2, word3, word4) + (plate) + MASTER_Hashlib_RIPEMD160_Table1[9], shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

void
MASTER_Hashlib_RIPEMD160_Init( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT ripemd160c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( ripemd160c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		ripemd160c->buffer[index] = 0;
	ripemd160c->count[0] = ripemd160c->count[1] = 0;
	ripemd160c->state[0] = 0x67452301;
	ripemd160c->state[1] = 0xEFCDAB89;
	ripemd160c->state[2] = 0x98BADCFE;
	ripemd160c->state[3] = 0x10325476;
	ripemd160c->state[4] = 0xC3D2E1F0;
}

MASTER_Hashlib_RIPEMD160_Context
MASTER_Hashlib_RIPEMD160_Create( void ) {
	MASTER_Hashlib_RIPEMD160_Context ripemd160c;
	MASTER_Hashlib_RIPEMD160_Init(&ripemd160c);
	return ripemd160c;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_RIPEMD160_Process( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT ripemd160c, const UI1 * const MASTER_PREFER_RESTRICT inData ) {
	UI4 chunk[16];
	UI4 wordA1 = ripemd160c->state[0];
	UI4 wordB1 = ripemd160c->state[1];
	UI4 wordC1 = ripemd160c->state[2];
	UI4 wordD1 = ripemd160c->state[3];
	UI4 wordE1 = ripemd160c->state[4];
	UI4 wordA2 = wordA1;
	UI4 wordB2 = wordB1;
	UI4 wordC2 = wordC1;
	UI4 wordD2 = wordD1;
	UI4 wordE2 = wordE1;
#if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
	MASTER_MEMCPY(chunk, inData, 64);
#elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
	UI1 index = 0;
	MASTER_MEMCPY(chunk, inData, 64);
	for (; index < 16; index += 1)
		chunk[index] = MASTER_BSWAP4(chunk[index]);
#else
	UI1 index = 0;
	for (; index < 16; index += 1)
		chunk[index] = (inData[3 | (index << 2)] << 24) | (inData[2 | (index << 2)] << 16) | (inData[1 | (index << 2)] << 8) | inData[index << 2];
#endif /* #! Endian !# */
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[0], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[1], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[2], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[3], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[4], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[5], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[6], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[7], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[8], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[9], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[10], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[11], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[12], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[13], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[14], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC1_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[15], 8);

	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[7], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[4], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[13], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[1], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[10], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[6], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[15], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[3], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[12], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[0], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[9], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[5], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[2], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[14], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[11], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC2_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[8], 12);

	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[3], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[10], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[14], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[4], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[9], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[15], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[8], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[1], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[2], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[7], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[0], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[6], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[13], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[11], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[5], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC3_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[12], 5);

	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[1], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[9], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[11], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[10], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[0], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[8], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[12], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[4], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[13], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[3], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[7], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[15], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[14], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[5], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[6], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC4_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[2], 12);

	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[4], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[0], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[5], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[9], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[7], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[12], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[2], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[10], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[14], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[1], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[3], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[8], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[11], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[6], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[15], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC5_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[13], 6);

	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[5], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[14], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[7], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[0], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[9], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[2], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[11], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[4], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[13], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[6], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[15], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[8], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[1], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[10], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[3], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC1_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[12], 6);

	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[6], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[11], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[3], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[7], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[0], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[13], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[5], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[10], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[14], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[15], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[8], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[12], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[4], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[9], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[1], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC2_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[2], 11);

	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[15], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[5], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[1], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[3], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[7], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[14], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[6], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[9], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[11], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[8], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[12], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[2], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[10], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[0], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[4], 7);
	MASTER_HASHLIB_RIPEMD160_FUNC3_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[13], 5);

	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[8], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[6], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[4], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[1], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[3], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[11], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[15], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[0], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[5], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[12], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[2], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[13], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[9], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[7], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[10], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC4_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[14], 8);

	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[12], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[15], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[10], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[4], 9);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[1], 12);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[5], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[8], 14);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[7], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[6], 8);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[2], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[13], 6);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[14], 5);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[0], 15);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[3], 13);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[9], 11);
	MASTER_HASHLIB_RIPEMD160_FUNC5_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[11], 11);

	wordD2 += wordC1 + ripemd160c->state[1];
	ripemd160c->state[1] = ripemd160c->state[2] + wordD1 + wordE2;
	ripemd160c->state[2] = ripemd160c->state[3] + wordE1 + wordA2;
	ripemd160c->state[3] = ripemd160c->state[4] + wordA1 + wordB2;
	ripemd160c->state[4] = ripemd160c->state[0] + wordB1 + wordC2;
	ripemd160c->state[0] = wordD2;
}

void
MASTER_Hashlib_RIPEMD160_Update( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT ripemd160c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	MASTER_Hashlib_MerkleDamgard_Update(ripemd160c, bytes, len, MASTER_Hashlib_RIPEMD160_Process);
}

void
MASTER_Hashlib_RIPEMD160_Finish( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT ripemd160c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( ripemd160c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = ripemd160c->count[0] & 0x3F;
	ripemd160c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			ripemd160c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			ripemd160c->buffer[index] = 0;
		MASTER_Hashlib_RIPEMD160_Process(ripemd160c, ripemd160c->buffer);
		for (index = 0; index < 56; index += 1)
			ripemd160c->buffer[index] = 0;
	}
	ripemd160c->buffer[56] = ripemd160c->count[0] << 3;
	ripemd160c->buffer[57] = ripemd160c->count[0] >> 5;
	ripemd160c->buffer[58] = ripemd160c->count[0] >> 13;
	ripemd160c->buffer[59] = ripemd160c->count[0] >> 21;
	ripemd160c->buffer[60] = (ripemd160c->count[0] >> 29) | (ripemd160c->count[1] << 3);
	ripemd160c->buffer[61] = ripemd160c->count[1] >> 5;
	ripemd160c->buffer[62] = ripemd160c->count[1] >> 13;
	ripemd160c->buffer[63] = ripemd160c->count[1] >> 21;
	MASTER_Hashlib_RIPEMD160_Process(ripemd160c, ripemd160c->buffer);
	for (index = 0; index < 4; index += 1) {
		output[index] = ripemd160c->state[0] >> (index << 3);
		output[index | 4] = ripemd160c->state[1] >> (index << 3);
		output[index | 8] = ripemd160c->state[2] >> (index << 3);
		output[index | 12] = ripemd160c->state[3] >> (index << 3);
		output[index | 16] = ripemd160c->state[4] >> (index << 3);
	}
}

void
MASTER_Hashlib_RIPEMD160_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_RIPEMD160_Context ripemd160c;
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	ripemd160c = MASTER_Hashlib_RIPEMD160_Create();
	MASTER_Hashlib_RIPEMD160_Update(&ripemd160c, bytes, len);
	MASTER_Hashlib_RIPEMD160_Finish(&ripemd160c, output);
}

const UI4 MASTER_Hashlib_RIPEMD160_Table1[10] = {
	0x00000000, 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xA953FD4E,
	0x50A28BE6, 0x5C4DD124, 0x6D703EF3, 0x7A6D76E9, 0x00000000
};

#endif /* #! RIPEMD160 !# */

/* #! RIPEMD-256 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[8];
} MASTER_Hashlib_RIPEMD256_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_RIPEMD256_Context, MASTER_Hashlib_RIPEMD256_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD256_Init, ( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_RIPEMD256_Flush MASTER_Hashlib_RIPEMD256_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD256_Update, ( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD256_Finish, ( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD256_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_HASHLIB_RIPEMD256_IMPLEMENT == 1

#define MASTER_HASHLIB_RIPEMD256_FUNC1_1( word1, word2, word3, word4, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_XOR3(word2, word3, word4) + (plate) + (constant), shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD256_FUNC2_1( word1, word2, word3, word4, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word2, word3, word4) + (plate) + (constant), shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD256_FUNC3_1( word1, word2, word3, word4, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_3XB1ON2E(word2, word3, word4) + (plate) + (constant), shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD256_FUNC4_1( word1, word2, word3, word4, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word4, word2, word3) + (plate) + (constant), shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD256_FUNC1_2( word1, word2, word3, word4, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word4, word2, word3) + (plate) + (constant), shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD256_FUNC2_2( word1, word2, word3, word4, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_3XB1ON2E(word2, word3, word4) + (plate) + (constant), shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD256_FUNC3_2( word1, word2, word3, word4, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word2, word3, word4) + (plate) + (constant), shift); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD256_FUNC4_2( word1, word2, word3, word4, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_XOR3(word2, word3, word4) + (plate) + (constant), shift); \
	} while (0)

void
MASTER_Hashlib_RIPEMD256_Init( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT ripemd256c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( ripemd256c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		ripemd256c->buffer[index] = 0;
	ripemd256c->count[0] = ripemd256c->count[1] = 0;
	ripemd256c->state[0] = 0x67452301;
	ripemd256c->state[1] = 0xEFCDAB89;
	ripemd256c->state[2] = 0x98BADCFE;
	ripemd256c->state[3] = 0x10325476;
	ripemd256c->state[4] = 0x76543210;
	ripemd256c->state[5] = 0xFEDCBA98;
	ripemd256c->state[6] = 0x89ABCDEF;
	ripemd256c->state[7] = 0x01234567;
}

MASTER_Hashlib_RIPEMD256_Context
MASTER_Hashlib_RIPEMD256_Create( void ) {
	MASTER_Hashlib_RIPEMD256_Context ripemd256c;
	MASTER_Hashlib_RIPEMD256_Init(&ripemd256c);
	return ripemd256c;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_RIPEMD256_Process( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT ripemd256c, const UI1 * const MASTER_PREFER_RESTRICT inData ) {
	UI4 chunk[16];
	UI4 wordA1 = ripemd256c->state[0];
	UI4 wordB1 = ripemd256c->state[1];
	UI4 wordC1 = ripemd256c->state[2];
	UI4 wordD1 = ripemd256c->state[3];
	UI4 wordA2 = ripemd256c->state[4];
	UI4 wordB2 = ripemd256c->state[5];
	UI4 wordC2 = ripemd256c->state[6];
	UI4 wordD2 = ripemd256c->state[7];
#if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
	MASTER_MEMCPY(chunk, inData, 64);
#elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
	UI1 index = 0;
	MASTER_MEMCPY(chunk, inData, 64);
	for (; index < 16; index += 1)
		chunk[index] = MASTER_BSWAP4(chunk[index]);
#else
	UI1 index = 0;
	for (; index < 16; index += 1)
		chunk[index] = (inData[3 | (index << 2)] << 24) | (inData[2 | (index << 2)] << 16) | (inData[1 | (index << 2)] << 8) | inData[index << 2];
#endif /* #! Endian !# */
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordA1, wordB1, wordC1, wordD1, chunk[0], 0x00000000, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordD1, wordA1, wordB1, wordC1, chunk[1], 0x00000000, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordC1, wordD1, wordA1, wordB1, chunk[2], 0x00000000, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordB1, wordC1, wordD1, wordA1, chunk[3], 0x00000000, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordA1, wordB1, wordC1, wordD1, chunk[4], 0x00000000, 5);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordD1, wordA1, wordB1, wordC1, chunk[5], 0x00000000, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordC1, wordD1, wordA1, wordB1, chunk[6], 0x00000000, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordB1, wordC1, wordD1, wordA1, chunk[7], 0x00000000, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordA1, wordB1, wordC1, wordD1, chunk[8], 0x00000000, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordD1, wordA1, wordB1, wordC1, chunk[9], 0x00000000, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordC1, wordD1, wordA1, wordB1, chunk[10], 0x00000000, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordB1, wordC1, wordD1, wordA1, chunk[11], 0x00000000, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordA1, wordB1, wordC1, wordD1, chunk[12], 0x00000000, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordD1, wordA1, wordB1, wordC1, chunk[13], 0x00000000, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordC1, wordD1, wordA1, wordB1, chunk[14], 0x00000000, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC1_1(wordB1, wordC1, wordD1, wordA1, chunk[15], 0x00000000, 8);

	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordA2, wordB2, wordC2, wordD2, chunk[5], 0x50A28BE6, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordD2, wordA2, wordB2, wordC2, chunk[14], 0x50A28BE6, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordC2, wordD2, wordA2, wordB2, chunk[7], 0x50A28BE6, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordB2, wordC2, wordD2, wordA2, chunk[0], 0x50A28BE6, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordA2, wordB2, wordC2, wordD2, chunk[9], 0x50A28BE6, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordD2, wordA2, wordB2, wordC2, chunk[2], 0x50A28BE6, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordC2, wordD2, wordA2, wordB2, chunk[11], 0x50A28BE6, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordB2, wordC2, wordD2, wordA2, chunk[4], 0x50A28BE6, 5);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordA2, wordB2, wordC2, wordD2, chunk[13], 0x50A28BE6, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordD2, wordA2, wordB2, wordC2, chunk[6], 0x50A28BE6, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordC2, wordD2, wordA2, wordB2, chunk[15], 0x50A28BE6, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordB2, wordC2, wordD2, wordA2, chunk[8], 0x50A28BE6, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordA2, wordB2, wordC2, wordD2, chunk[1], 0x50A28BE6, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordD2, wordA2, wordB2, wordC2, chunk[10], 0x50A28BE6, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordC2, wordD2, wordA2, wordB2, chunk[3], 0x50A28BE6, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC1_2(wordB2, wordC2, wordD2, wordA2, chunk[12], 0x50A28BE6, 6);

	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordA2, wordB1, wordC1, wordD1, chunk[7], 0x5A827999, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordD1, wordA2, wordB1, wordC1, chunk[4], 0x5A827999, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordC1, wordD1, wordA2, wordB1, chunk[13], 0x5A827999, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordB1, wordC1, wordD1, wordA2, chunk[1], 0x5A827999, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordA2, wordB1, wordC1, wordD1, chunk[10], 0x5A827999, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordD1, wordA2, wordB1, wordC1, chunk[6], 0x5A827999, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordC1, wordD1, wordA2, wordB1, chunk[15], 0x5A827999, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordB1, wordC1, wordD1, wordA2, chunk[3], 0x5A827999, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordA2, wordB1, wordC1, wordD1, chunk[12], 0x5A827999, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordD1, wordA2, wordB1, wordC1, chunk[0], 0x5A827999, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordC1, wordD1, wordA2, wordB1, chunk[9], 0x5A827999, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordB1, wordC1, wordD1, wordA2, chunk[5], 0x5A827999, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordA2, wordB1, wordC1, wordD1, chunk[2], 0x5A827999, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordD1, wordA2, wordB1, wordC1, chunk[14], 0x5A827999, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordC1, wordD1, wordA2, wordB1, chunk[11], 0x5A827999, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC2_1(wordB1, wordC1, wordD1, wordA2, chunk[8], 0x5A827999, 12);

	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordA1, wordB2, wordC2, wordD2, chunk[6], 0x5C4DD124, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordD2, wordA1, wordB2, wordC2, chunk[11], 0x5C4DD124, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordC2, wordD2, wordA1, wordB2, chunk[3], 0x5C4DD124, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordB2, wordC2, wordD2, wordA1, chunk[7], 0x5C4DD124, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordA1, wordB2, wordC2, wordD2, chunk[0], 0x5C4DD124, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordD2, wordA1, wordB2, wordC2, chunk[13], 0x5C4DD124, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordC2, wordD2, wordA1, wordB2, chunk[5], 0x5C4DD124, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordB2, wordC2, wordD2, wordA1, chunk[10], 0x5C4DD124, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordA1, wordB2, wordC2, wordD2, chunk[14], 0x5C4DD124, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordD2, wordA1, wordB2, wordC2, chunk[15], 0x5C4DD124, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordC2, wordD2, wordA1, wordB2, chunk[8], 0x5C4DD124, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordB2, wordC2, wordD2, wordA1, chunk[12], 0x5C4DD124, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordA1, wordB2, wordC2, wordD2, chunk[4], 0x5C4DD124, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordD2, wordA1, wordB2, wordC2, chunk[9], 0x5C4DD124, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordC2, wordD2, wordA1, wordB2, chunk[1], 0x5C4DD124, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC2_2(wordB2, wordC2, wordD2, wordA1, chunk[2], 0x5C4DD124, 11);

	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordA2, wordB2, wordC1, wordD1, chunk[3], 0x6ED9EBA1, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordD1, wordA2, wordB2, wordC1, chunk[10], 0x6ED9EBA1, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordC1, wordD1, wordA2, wordB2, chunk[14], 0x6ED9EBA1, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordB2, wordC1, wordD1, wordA2, chunk[4], 0x6ED9EBA1, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordA2, wordB2, wordC1, wordD1, chunk[9], 0x6ED9EBA1, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordD1, wordA2, wordB2, wordC1, chunk[15], 0x6ED9EBA1, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordC1, wordD1, wordA2, wordB2, chunk[8], 0x6ED9EBA1, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordB2, wordC1, wordD1, wordA2, chunk[1], 0x6ED9EBA1, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordA2, wordB2, wordC1, wordD1, chunk[2], 0x6ED9EBA1, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordD1, wordA2, wordB2, wordC1, chunk[7], 0x6ED9EBA1, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordC1, wordD1, wordA2, wordB2, chunk[0], 0x6ED9EBA1, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordB2, wordC1, wordD1, wordA2, chunk[6], 0x6ED9EBA1, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordA2, wordB2, wordC1, wordD1, chunk[13], 0x6ED9EBA1, 5);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordD1, wordA2, wordB2, wordC1, chunk[11], 0x6ED9EBA1, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordC1, wordD1, wordA2, wordB2, chunk[5], 0x6ED9EBA1, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC3_1(wordB2, wordC1, wordD1, wordA2, chunk[12], 0x6ED9EBA1, 5);

	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordA1, wordB1, wordC2, wordD2, chunk[15], 0x6D703EF3, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordD2, wordA1, wordB1, wordC2, chunk[5], 0x6D703EF3, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordC2, wordD2, wordA1, wordB1, chunk[1], 0x6D703EF3, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordB1, wordC2, wordD2, wordA1, chunk[3], 0x6D703EF3, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordA1, wordB1, wordC2, wordD2, chunk[7], 0x6D703EF3, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordD2, wordA1, wordB1, wordC2, chunk[14], 0x6D703EF3, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordC2, wordD2, wordA1, wordB1, chunk[6], 0x6D703EF3, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordB1, wordC2, wordD2, wordA1, chunk[9], 0x6D703EF3, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordA1, wordB1, wordC2, wordD2, chunk[11], 0x6D703EF3, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordD2, wordA1, wordB1, wordC2, chunk[8], 0x6D703EF3, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordC2, wordD2, wordA1, wordB1, chunk[12], 0x6D703EF3, 5);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordB1, wordC2, wordD2, wordA1, chunk[2], 0x6D703EF3, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordA1, wordB1, wordC2, wordD2, chunk[10], 0x6D703EF3, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordD2, wordA1, wordB1, wordC2, chunk[0], 0x6D703EF3, 13);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordC2, wordD2, wordA1, wordB1, chunk[4], 0x6D703EF3, 7);
	MASTER_HASHLIB_RIPEMD256_FUNC3_2(wordB1, wordC2, wordD2, wordA1, chunk[13], 0x6D703EF3, 5);

	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordA2, wordB2, wordC2, wordD1, chunk[1], 0x8F1BBCDC, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordD1, wordA2, wordB2, wordC2, chunk[9], 0x8F1BBCDC, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordC2, wordD1, wordA2, wordB2, chunk[11], 0x8F1BBCDC, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordB2, wordC2, wordD1, wordA2, chunk[10], 0x8F1BBCDC, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordA2, wordB2, wordC2, wordD1, chunk[0], 0x8F1BBCDC, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordD1, wordA2, wordB2, wordC2, chunk[8], 0x8F1BBCDC, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordC2, wordD1, wordA2, wordB2, chunk[12], 0x8F1BBCDC, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordB2, wordC2, wordD1, wordA2, chunk[4], 0x8F1BBCDC, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordA2, wordB2, wordC2, wordD1, chunk[13], 0x8F1BBCDC, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordD1, wordA2, wordB2, wordC2, chunk[3], 0x8F1BBCDC, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordC2, wordD1, wordA2, wordB2, chunk[7], 0x8F1BBCDC, 5);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordB2, wordC2, wordD1, wordA2, chunk[15], 0x8F1BBCDC, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordA2, wordB2, wordC2, wordD1, chunk[14], 0x8F1BBCDC, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordD1, wordA2, wordB2, wordC2, chunk[5], 0x8F1BBCDC, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordC2, wordD1, wordA2, wordB2, chunk[6], 0x8F1BBCDC, 5);
	MASTER_HASHLIB_RIPEMD256_FUNC4_1(wordB2, wordC2, wordD1, wordA2, chunk[2], 0x8F1BBCDC, 12);

	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordA1, wordB1, wordC1, wordD2, chunk[8], 0x00000000, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordD2, wordA1, wordB1, wordC1, chunk[6], 0x00000000, 5);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordC1, wordD2, wordA1, wordB1, chunk[4], 0x00000000, 8);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordB1, wordC1, wordD2, wordA1, chunk[1], 0x00000000, 11);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordA1, wordB1, wordC1, wordD2, chunk[3], 0x00000000, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordD2, wordA1, wordB1, wordC1, chunk[11], 0x00000000, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordC1, wordD2, wordA1, wordB1, chunk[15], 0x00000000, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordB1, wordC1, wordD2, wordA1, chunk[0], 0x00000000, 14);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordA1, wordB1, wordC1, wordD2, chunk[5], 0x00000000, 6);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordD2, wordA1, wordB1, wordC1, chunk[12], 0x00000000, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordC1, wordD2, wordA1, wordB1, chunk[2], 0x00000000, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordB1, wordC1, wordD2, wordA1, chunk[13], 0x00000000, 9);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordA1, wordB1, wordC1, wordD2, chunk[9], 0x00000000, 12);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordD2, wordA1, wordB1, wordC1, chunk[7], 0x00000000, 5);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordC1, wordD2, wordA1, wordB1, chunk[10], 0x00000000, 15);
	MASTER_HASHLIB_RIPEMD256_FUNC4_2(wordB1, wordC1, wordD2, wordA1, chunk[14], 0x00000000, 8);

	ripemd256c->state[0] += wordA2;
	ripemd256c->state[1] += wordB2;
	ripemd256c->state[2] += wordC2;
	ripemd256c->state[3] += wordD2;
	ripemd256c->state[4] += wordA1;
	ripemd256c->state[5] += wordB1;
	ripemd256c->state[6] += wordC1;
	ripemd256c->state[7] += wordD1;
}

void
MASTER_Hashlib_RIPEMD256_Update( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT ripemd256c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	MASTER_Hashlib_MerkleDamgard_Update(ripemd256c, bytes, len, MASTER_Hashlib_RIPEMD256_Process);
}

void
MASTER_Hashlib_RIPEMD256_Finish( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT ripemd256c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( ripemd256c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = ripemd256c->count[0] & 0x3F;
	ripemd256c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			ripemd256c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			ripemd256c->buffer[index] = 0;
		MASTER_Hashlib_RIPEMD256_Process(ripemd256c, ripemd256c->buffer);
		for (index = 0; index < 56; index += 1)
			ripemd256c->buffer[index] = 0;
	}
	ripemd256c->buffer[56] = ripemd256c->count[0] << 3;
	ripemd256c->buffer[57] = ripemd256c->count[0] >> 5;
	ripemd256c->buffer[58] = ripemd256c->count[0] >> 13;
	ripemd256c->buffer[59] = ripemd256c->count[0] >> 21;
	ripemd256c->buffer[60] = (ripemd256c->count[0] >> 29) | (ripemd256c->count[1] << 3);
	ripemd256c->buffer[61] = ripemd256c->count[1] >> 5;
	ripemd256c->buffer[62] = ripemd256c->count[1] >> 13;
	ripemd256c->buffer[63] = ripemd256c->count[1] >> 21;
	MASTER_Hashlib_RIPEMD256_Process(ripemd256c, ripemd256c->buffer);
	for (index = 0; index < 4; index += 1) {
		output[index] = ripemd256c->state[0] >> (index << 3);
		output[index | 4] = ripemd256c->state[1] >> (index << 3);
		output[index | 8] = ripemd256c->state[2] >> (index << 3);
		output[index | 12] = ripemd256c->state[3] >> (index << 3);
		output[index | 16] = ripemd256c->state[4] >> (index << 3);
		output[index | 20] = ripemd256c->state[5] >> (index << 3);
		output[index | 24] = ripemd256c->state[6] >> (index << 3);
		output[index | 28] = ripemd256c->state[7] >> (index << 3);
	}
}

void
MASTER_Hashlib_RIPEMD256_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_RIPEMD256_Context ripemd256c;
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	ripemd256c = MASTER_Hashlib_RIPEMD256_Create();
	MASTER_Hashlib_RIPEMD256_Update(&ripemd256c, bytes, len);
	MASTER_Hashlib_RIPEMD256_Finish(&ripemd256c, output);
}

#endif /* #! RIPEMD256 !# */

/* #! RIPEMD-320 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[10];
} MASTER_Hashlib_RIPEMD320_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_RIPEMD320_Context, MASTER_Hashlib_RIPEMD320_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD320_Init, ( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_RIPEMD320_Flush MASTER_Hashlib_RIPEMD320_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD320_Update, ( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD320_Finish, ( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_RIPEMD320_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_HASHLIB_RIPEMD320_IMPLEMENT == 1

#define MASTER_HASHLIB_RIPEMD320_FUNC1_1( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_XOR3(word2, word3, word4) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC2_1( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word2, word3, word4) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC3_1( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_3XB1ON2E(word2, word3, word4) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC4_1( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word4, word2, word3) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC5_1( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_1XB2ON3E(word2, word3, word4) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC1_2( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_1XB2ON3E(word2, word3, word4) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC2_2( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word4, word2, word3) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC3_2( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_3XB1ON2E(word2, word3, word4) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC4_2( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_CHOICE(word2, word3, word4) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

#define MASTER_HASHLIB_RIPEMD320_FUNC5_2( word1, word2, word3, word4, word5, plate, constant, shift ) do { \
		(word1) = MASTER_RLL4((word1) + MASTER_OPERATION_XOR3(word2, word3, word4) + (plate) + (constant), shift) + (word5); \
		(word3) = MASTER_RLL4(word3, 10); \
	} while (0)

void
MASTER_Hashlib_RIPEMD320_Init( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT ripemd320c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( ripemd320c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		ripemd320c->buffer[index] = 0;
	ripemd320c->count[0] = ripemd320c->count[1] = 0;
	ripemd320c->state[0] = 0x67452301;
	ripemd320c->state[1] = 0xEFCDAB89;
	ripemd320c->state[2] = 0x98BADCFE;
	ripemd320c->state[3] = 0x10325476;
	ripemd320c->state[4] = 0xC3D2E1F0;
	ripemd320c->state[5] = 0x76543210;
	ripemd320c->state[6] = 0xFEDCBA98;
	ripemd320c->state[7] = 0x89ABCDEF;
	ripemd320c->state[8] = 0x01234567;
	ripemd320c->state[9] = 0x3C2D1E0F;
}

MASTER_Hashlib_RIPEMD320_Context
MASTER_Hashlib_RIPEMD320_Create( void ) {
	MASTER_Hashlib_RIPEMD320_Context ripemd320c;
	MASTER_Hashlib_RIPEMD320_Init(&ripemd320c);
	return ripemd320c;
}

#define MASTER_NUMBER_SWAP( value1, value2 ) do { \
		(value1) ^= (value2); \
		(value2) ^= (value1); \
		(value1) ^= (value2); \
	} while (0)

MASTER_PREFER_STATIC void
MASTER_Hashlib_RIPEMD320_Process( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT ripemd320c, const UI1 * const MASTER_PREFER_RESTRICT inData ) {
	UI4 chunk[16];
	UI4 wordA1 = ripemd320c->state[0];
	UI4 wordB1 = ripemd320c->state[1];
	UI4 wordC1 = ripemd320c->state[2];
	UI4 wordD1 = ripemd320c->state[3];
	UI4 wordE1 = ripemd320c->state[4];
	UI4 wordA2 = ripemd320c->state[5];
	UI4 wordB2 = ripemd320c->state[6];
	UI4 wordC2 = ripemd320c->state[7];
	UI4 wordD2 = ripemd320c->state[8];
	UI4 wordE2 = ripemd320c->state[9];
#if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
	MASTER_MEMCPY(chunk, inData, 64);
#elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
	UI1 index = 0;
	MASTER_MEMCPY(chunk, inData, 64);
	for (; index < 16; index += 1)
		chunk[index] = MASTER_BSWAP4(chunk[index]);
#else
	UI1 index = 0;
	for (; index < 16; index += 1)
		chunk[index] = (inData[3 | (index << 2)] << 24) | (inData[2 | (index << 2)] << 16) | (inData[1 | (index << 2)] << 8) | inData[index << 2];
#endif /* #! Endian !# */
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[0], 0x00000000, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[1], 0x00000000, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[2], 0x00000000, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[3], 0x00000000, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[4], 0x00000000, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[5], 0x00000000, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[6], 0x00000000, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[7], 0x00000000, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[8], 0x00000000, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[9], 0x00000000, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[10], 0x00000000, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[11], 0x00000000, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[12], 0x00000000, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[13], 0x00000000, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[14], 0x00000000, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC1_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[15], 0x00000000, 8);

	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[5], 0x50A28BE6, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[14], 0x50A28BE6, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[7], 0x50A28BE6, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[0], 0x50A28BE6, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[9], 0x50A28BE6, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[2], 0x50A28BE6, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[11], 0x50A28BE6, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[4], 0x50A28BE6, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[13], 0x50A28BE6, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[6], 0x50A28BE6, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[15], 0x50A28BE6, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[8], 0x50A28BE6, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[1], 0x50A28BE6, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[10], 0x50A28BE6, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[3], 0x50A28BE6, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC1_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[12], 0x50A28BE6, 6);

	MASTER_NUMBER_SWAP(wordA1, wordA2);

	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[7], 0x5A827999, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[4], 0x5A827999, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[13], 0x5A827999, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[1], 0x5A827999, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[10], 0x5A827999, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[6], 0x5A827999, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[15], 0x5A827999, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[3], 0x5A827999, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[12], 0x5A827999, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[0], 0x5A827999, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[9], 0x5A827999, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[5], 0x5A827999, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[2], 0x5A827999, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[14], 0x5A827999, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[11], 0x5A827999, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC2_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[8], 0x5A827999, 12);

	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[6], 0x5C4DD124, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[11], 0x5C4DD124, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[3], 0x5C4DD124, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[7], 0x5C4DD124, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[0], 0x5C4DD124, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[13], 0x5C4DD124, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[5], 0x5C4DD124, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[10], 0x5C4DD124, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[14], 0x5C4DD124, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[15], 0x5C4DD124, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[8], 0x5C4DD124, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[12], 0x5C4DD124, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[4], 0x5C4DD124, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[9], 0x5C4DD124, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[1], 0x5C4DD124, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC2_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[2], 0x5C4DD124, 11);

	MASTER_NUMBER_SWAP(wordB1, wordB2);

	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[3], 0x6ED9EBA1, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[10], 0x6ED9EBA1, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[14], 0x6ED9EBA1, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[4], 0x6ED9EBA1, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[9], 0x6ED9EBA1, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[15], 0x6ED9EBA1, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[8], 0x6ED9EBA1, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[1], 0x6ED9EBA1, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[2], 0x6ED9EBA1, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[7], 0x6ED9EBA1, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[0], 0x6ED9EBA1, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[6], 0x6ED9EBA1, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[13], 0x6ED9EBA1, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[11], 0x6ED9EBA1, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[5], 0x6ED9EBA1, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC3_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[12], 0x6ED9EBA1, 5);

	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[15], 0x6D703EF3, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[5], 0x6D703EF3, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[1], 0x6D703EF3, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[3], 0x6D703EF3, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[7], 0x6D703EF3, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[14], 0x6D703EF3, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[6], 0x6D703EF3, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[9], 0x6D703EF3, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[11], 0x6D703EF3, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[8], 0x6D703EF3, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[12], 0x6D703EF3, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[2], 0x6D703EF3, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[10], 0x6D703EF3, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[0], 0x6D703EF3, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[4], 0x6D703EF3, 7);
	MASTER_HASHLIB_RIPEMD320_FUNC3_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[13], 0x6D703EF3, 5);

	MASTER_NUMBER_SWAP(wordC1, wordC2);

	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[1], 0x8F1BBCDC, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[9], 0x8F1BBCDC, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[11], 0x8F1BBCDC, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[10], 0x8F1BBCDC, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[0], 0x8F1BBCDC, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[8], 0x8F1BBCDC, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[12], 0x8F1BBCDC, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[4], 0x8F1BBCDC, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[13], 0x8F1BBCDC, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[3], 0x8F1BBCDC, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[7], 0x8F1BBCDC, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[15], 0x8F1BBCDC, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[14], 0x8F1BBCDC, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[5], 0x8F1BBCDC, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[6], 0x8F1BBCDC, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC4_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[2], 0x8F1BBCDC, 12);

	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[8], 0x7A6D76E9, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[6], 0x7A6D76E9, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[4], 0x7A6D76E9, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[1], 0x7A6D76E9, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[3], 0x7A6D76E9, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[11], 0x7A6D76E9, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[15], 0x7A6D76E9, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[0], 0x7A6D76E9, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[5], 0x7A6D76E9, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[12], 0x7A6D76E9, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[2], 0x7A6D76E9, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[13], 0x7A6D76E9, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[9], 0x7A6D76E9, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[7], 0x7A6D76E9, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[10], 0x7A6D76E9, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC4_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[14], 0x7A6D76E9, 8);

	MASTER_NUMBER_SWAP(wordD1, wordD2);

	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[4], 0xA953FD4E, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[0], 0xA953FD4E, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[5], 0xA953FD4E, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[9], 0xA953FD4E, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[7], 0xA953FD4E, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[12], 0xA953FD4E, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[2], 0xA953FD4E, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[10], 0xA953FD4E, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[14], 0xA953FD4E, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[1], 0xA953FD4E, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[3], 0xA953FD4E, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordA1, wordB1, wordC1, wordD1, wordE1, chunk[8], 0xA953FD4E, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordE1, wordA1, wordB1, wordC1, wordD1, chunk[11], 0xA953FD4E, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordD1, wordE1, wordA1, wordB1, wordC1, chunk[6], 0xA953FD4E, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordC1, wordD1, wordE1, wordA1, wordB1, chunk[15], 0xA953FD4E, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC5_1(wordB1, wordC1, wordD1, wordE1, wordA1, chunk[13], 0xA953FD4E, 6);

	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[12], 0x00000000, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[15], 0x00000000, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[10], 0x00000000, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[4], 0x00000000, 9);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[1], 0x00000000, 12);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[5], 0x00000000, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[8], 0x00000000, 14);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[7], 0x00000000, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[6], 0x00000000, 8);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[2], 0x00000000, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[13], 0x00000000, 6);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordA2, wordB2, wordC2, wordD2, wordE2, chunk[14], 0x00000000, 5);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordE2, wordA2, wordB2, wordC2, wordD2, chunk[0], 0x00000000, 15);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordD2, wordE2, wordA2, wordB2, wordC2, chunk[3], 0x00000000, 13);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordC2, wordD2, wordE2, wordA2, wordB2, chunk[9], 0x00000000, 11);
	MASTER_HASHLIB_RIPEMD320_FUNC5_2(wordB2, wordC2, wordD2, wordE2, wordA2, chunk[11], 0x00000000, 11);

	MASTER_NUMBER_SWAP(wordE1, wordE2);
	ripemd320c->state[0] += wordA1;
	ripemd320c->state[1] += wordB1;
	ripemd320c->state[2] += wordC1;
	ripemd320c->state[3] += wordD1;
	ripemd320c->state[4] += wordE1;
	ripemd320c->state[5] += wordA2;
	ripemd320c->state[6] += wordB2;
	ripemd320c->state[7] += wordC2;
	ripemd320c->state[8] += wordD2;
	ripemd320c->state[9] += wordE2;
}

void
MASTER_Hashlib_RIPEMD320_Update( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT ripemd320c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	MASTER_Hashlib_MerkleDamgard_Update(ripemd320c, bytes, len, MASTER_Hashlib_RIPEMD320_Process);
}

void
MASTER_Hashlib_RIPEMD320_Finish( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT ripemd320c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( ripemd320c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = ripemd320c->count[0] & 0x3F;
	ripemd320c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			ripemd320c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			ripemd320c->buffer[index] = 0;
		MASTER_Hashlib_RIPEMD320_Process(ripemd320c, ripemd320c->buffer);
		for (index = 0; index < 56; index += 1)
			ripemd320c->buffer[index] = 0;
	}
	ripemd320c->buffer[56] = ripemd320c->count[0] << 3;
	ripemd320c->buffer[57] = ripemd320c->count[0] >> 5;
	ripemd320c->buffer[58] = ripemd320c->count[0] >> 13;
	ripemd320c->buffer[59] = ripemd320c->count[0] >> 21;
	ripemd320c->buffer[60] = (ripemd320c->count[0] >> 29) | (ripemd320c->count[1] << 3);
	ripemd320c->buffer[61] = ripemd320c->count[1] >> 5;
	ripemd320c->buffer[62] = ripemd320c->count[1] >> 13;
	ripemd320c->buffer[63] = ripemd320c->count[1] >> 21;
	MASTER_Hashlib_RIPEMD320_Process(ripemd320c, ripemd320c->buffer);
	for (index = 0; index < 4; index += 1) {
		output[index] = ripemd320c->state[0] >> (index << 3);
		output[index | 4] = ripemd320c->state[1] >> (index << 3);
		output[index | 8] = ripemd320c->state[2] >> (index << 3);
		output[index | 12] = ripemd320c->state[3] >> (index << 3);
		output[index | 16] = ripemd320c->state[4] >> (index << 3);
		output[index | 20] = ripemd320c->state[5] >> (index << 3);
		output[index | 24] = ripemd320c->state[6] >> (index << 3);
		output[index | 28] = ripemd320c->state[7] >> (index << 3);
		output[index | 32] = ripemd320c->state[8] >> (index << 3);
		output[index | 36] = ripemd320c->state[9] >> (index << 3);
	}
}

void
MASTER_Hashlib_RIPEMD320_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_RIPEMD320_Context ripemd320c;
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	ripemd320c = MASTER_Hashlib_RIPEMD320_Create();
	MASTER_Hashlib_RIPEMD320_Update(&ripemd320c, bytes, len);
	MASTER_Hashlib_RIPEMD320_Finish(&ripemd320c, output);
}

#endif /* #! RIPEMD320 !# */

/* #! MurmurHash2A !# */

typedef struct {
	UI4 hash_value;
	SI4 length;
	UI1 buffer[4];
	UI1 bufferPtr;
} MASTER_Hashlib_MurmurHash2A_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MurmurHash2A_Init, ( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_MurmurHash2A_Context, MASTER_Hashlib_MurmurHash2A_Create, ( void ) );
#define MASTER_Hashlib_MurmurHash2A_Flush MASTER_Hashlib_MurmurHash2A_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MurmurHash2A_Update, ( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT, const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MurmurHash2A_Finish, ( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_MurmurHash2A_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_HASHLIB_MURMURHASH2A_IMPLEMENT == 1

#define MASTER_ALGOLIB_MURMURHASH2A_MIX( hash_value, helder ) do { \
		(helder) *= 0x5BD1E995; \
		(helder) ^= (helder) >> 24; \
		(helder) *= 0x5BD1E995; \
		(hash_value) *= 0x5BD1E995; \
		(hash_value) ^= (helder); \
	} while (0)

void
MASTER_Hashlib_MurmurHash2A_Init( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT mmh2ac ) {
	const UI4 seed_value = 0;
	if (mmh2ac == nul) return;
	MASTER_MEMSET(mmh2ac->buffer, 0, 4);
	mmh2ac->length = 0;
	mmh2ac->bufferPtr = 0;
	mmh2ac->hash_value = seed_value;
}

MASTER_Hashlib_MurmurHash2A_Context
MASTER_Hashlib_MurmurHash2A_Create( void ) {
	MASTER_Hashlib_MurmurHash2A_Context mmh2ac;
	MASTER_Hashlib_MurmurHash2A_Init(&mmh2ac);
	return mmh2ac;
}

void
MASTER_Hashlib_MurmurHash2A_Update( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT mmh2ac, const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length ) {
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	UI4 helder;
	UI1 toRead;
	if (mmh2ac == nul || bytes == nul) return;
	mmh2ac->length += length;
	if (mmh2ac->bufferPtr > 0) {
		toRead = 4 - mmh2ac->bufferPtr;
		if (length < toRead) {
			MASTER_MEMCPY(mmh2ac->buffer + mmh2ac->bufferPtr, bytes, length);
			mmh2ac->bufferPtr += length;
			return;
		}
		MASTER_MEMCPY(mmh2ac->buffer + mmh2ac->bufferPtr, ui1_data, toRead);
		helder = MASTER_TOLE4(*(const UI4 *)ui1_data);
		MASTER_ALGOLIB_MURMURHASH2A_MIX(mmh2ac->hash_value, helder);
		mmh2ac->bufferPtr = 0;
		ui1_data += toRead;
		estimated -= toRead;
	}
	while (estimated >= 4) {
		helder = MASTER_TOLE4(*(const UI4 *)ui1_data);
		MASTER_ALGOLIB_MURMURHASH2A_MIX(mmh2ac->hash_value, helder);
		ui1_data += 4;
		estimated -= 4;
	}
	if (estimated > 0) {
		MASTER_MEMCPY(mmh2ac->buffer, ui1_data, estimated);
		mmh2ac->bufferPtr = estimated;
	}
}

void
MASTER_Hashlib_MurmurHash2A_Finish( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT mmh2ac, UI1 * const MASTER_PREFER_RESTRICT out ) {
	UI4 helder = 0;
	if (mmh2ac == nul || out == nul) return;
	if (mmh2ac->bufferPtr >= 3)
		helder |= mmh2ac->buffer[2] << 16;
	if (mmh2ac->bufferPtr >= 2)
		helder |= mmh2ac->buffer[1] << 8;
	if (mmh2ac->bufferPtr >= 1)
		helder |= mmh2ac->buffer[0];
	MASTER_ALGOLIB_MURMURHASH2A_MIX(mmh2ac->hash_value, helder);
	MASTER_ALGOLIB_MURMURHASH2A_MIX(mmh2ac->hash_value, mmh2ac->length);
	mmh2ac->hash_value ^= mmh2ac->hash_value >> 13;
	mmh2ac->hash_value *= 0x5BD1E995;
	mmh2ac->hash_value ^= mmh2ac->hash_value >> 15;
	*(UI4 *)out = mmh2ac->hash_value;
}

void
MASTER_Hashlib_MurmurHash2A_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint length, UI1 * const MASTER_PREFER_RESTRICT out ) {
	MASTER_Hashlib_MurmurHash2A_Context mmh2ac;
	if (bytes == nul || out == nul) return;
	mmh2ac = MASTER_Hashlib_MurmurHash2A_Create();
	MASTER_Hashlib_MurmurHash2A_Update(&mmh2ac, bytes, length);
	MASTER_Hashlib_MurmurHash2A_Finish(&mmh2ac, out);
}

#endif /* #! MurmurHash2A !# */

/*
// <HASHNAME>

typedef struct {

} MASTER_Hashlib_<HASHBIG>_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_<HASHBIG>_Context, MASTER_Hashlib_<HASHBIG>_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_<HASHBIG>_Init, ( MASTER_Hashlib_<HASHBIG>_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_<HASHBIG>_Flush MASTER_Hashlib_<HASHBIG>_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_PREFER_STATIC void, MASTER_Hashlib_<HASHBIG>_Process, ( MASTER_Hashlib_<HASHBIG>_Context * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_<HASHBIG>_Update, ( MASTER_Hashlib_<HASHBIG>_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ), );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_<HASHBIG>_Finish, ( MASTER_Hashlib_<HASHBIG>_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_<HASHBIG>_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

const UI4 MASTER_Hashlib_<HASHBIG>_Table1[4];

#if MASTER_HASHLIB_<HASHBIG>_IMPLEMENT == 1

void
MASTER_Hashlib_<HASHBIG>_Init( MASTER_Hashlib_<HASHBIG>_Context * const MASTER_PREFER_RESTRICT <hashlow>c ) {
	UI1 index = 0;
	MASTER_zRIVATE_CHECK_NUL_RETURN( <hashlow>c, MASTER_NOTHING );

}

MASTER_Hashlib_<HASHBIG>_Context
MASTER_Hashlib_<HASHBIG>_Create( void ) {
	MASTER_Hashlib_<HASHBIG>_Context <hashlow>c;
	MASTER_Hashlib_<HASHBIG>_Init(&<hashlow>c);
	return <hashlow>c;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_<HASHBIG>_Process( MASTER_Hashlib_<HASHBIG>_Context * const MASTER_PREFER_RESTRICT <hashlow>c ) {

}

void
MASTER_Hashlib_<HASHBIG>_Update( MASTER_Hashlib_<HASHBIG>_Context * const MASTER_PREFER_RESTRICT <hashlow>c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	MASTER_zRIVATE_CHECK_NUL_RETURN( <hashlow>c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );

}

void
MASTER_Hashlib_<HASHBIG>_Finish( MASTER_Hashlib_<HASHBIG>_Context * const MASTER_PREFER_RESTRICT <hashlow>c, UI1 * const MASTER_PREFER_RESTRICT output ) {
	UI1 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( <hashlow>c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );

}

void
MASTER_Hashlib_<HASHBIG>_Calculate( const void * const bytes MASTER_PREFER_RESTRICT, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	MASTER_Hashlib_<HASHBIG>_Context <hashlow>c;
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	<hashlow>c = MASTER_Hashlib_<HASHBIG>_Create();
	MASTER_Hashlib_<HASHBIG>_Update(&<hashlow>c, bytes, len);
	MASTER_Hashlib_<HASHBIG>_Finish(&<hashlow>c, output);
}

#endif // <HASHBIG>
*/

/* #! API !# */

typedef struct {
	MASTER_Hashlib_Algorithms id;
	union {
#define MASTER_HASHLIB_API_CREATE_HANDLER_STRUCTURE( macro_name, algorithm_name, member ) \
	MASTER_Hashlib_## algorithm_name ##_Context member;

		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_STRUCTURE )
	} context;
} MASTER_Hashlib_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_Context, MASTER_Hashlib_Create, ( const MASTER_Hashlib_Algorithms ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_Init, ( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT, const MASTER_Hashlib_Algorithms ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_Flush, ( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_Update, ( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT, const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_Finish, ( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_Calculate, ( const MASTER_Hashlib_Algorithms, const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, const char *, MASTER_Hashlib_GetAlgorithmName, ( const MASTER_Hashlib_Algorithms ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_maxint, MASTER_Hashlib_GetAlgorithmOutputSize, ( const MASTER_Hashlib_Algorithms ) );

#if MASTER_HASHLIB_API_IMPLEMENT == 1

MASTER_Hashlib_Context
MASTER_Hashlib_Create( const MASTER_Hashlib_Algorithms id ) {
	MASTER_Hashlib_Context hash;
	hash.id = id;
	switch (hash.id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_CREATE( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			hash.context.member = MASTER_Hashlib_## algorithm_name ##_Create(); \
		break;

		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_CREATE )
	}
	return hash;
}

void
MASTER_Hashlib_Init( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT hash, const MASTER_Hashlib_Algorithms id ) {
	hash->id = id;
	switch (hash->id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_INIT( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Init(&(hash->context.member)); \
		break;

		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_INIT )
	}
}

void
MASTER_Hashlib_Flush( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT hash ) {
	switch (hash->id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_FLUSH( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Flush(&(hash->context.member)); \
		break;

		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_FLUSH )
	}
}

void
MASTER_Hashlib_Update( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT hash, const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len ) {
	switch (hash->id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_UPDATE( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Update(&(hash->context.member), bytes, len); \
		break;

		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_UPDATE )
	}
}

void
MASTER_Hashlib_Finish( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT hash, UI1 * const MASTER_PREFER_RESTRICT output ) {
	switch (hash->id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_FINISH( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Finish(&(hash->context.member), output); \
		break;

		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_FINISH )
	}
}

void
MASTER_Hashlib_Calculate( const MASTER_Hashlib_Algorithms id, const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT output ) {
	switch (id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_CALCULATE( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Calculate(bytes, len, output); \
		break;

		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_CALCULATE )
	}
}

const char *
MASTER_Hashlib_GetAlgorithmName( const MASTER_Hashlib_Algorithms id ) {
	switch (id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_GETALGORITHMNAME( macro_name, algorithm_name, __not_used_1__ ) \
		case MASTER_HASHLIB_## macro_name ##_ID : return (const char *)#algorithm_name;
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_GETALGORITHMNAME )
		default : return (const char *)"Unknown";
	}
}

MASTER_maxint
MASTER_Hashlib_GetAlgorithmOutputSize( const MASTER_Hashlib_Algorithms id ) {
	switch (id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_GETALGORITHMOUTPUTSIZE( macro_name, algorithm_name, __not_used_1__ ) \
		case MASTER_HASHLIB_## macro_name ##_ID : return MASTER_HASHLIB_## macro_name ##_DIGEST_SIZE;

		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_GETALGORITHMOUTPUTSIZE )
		default : return 0;
	}
}

#endif /* #! API !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_HASHLIB_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_HASHLIB_INCLUDE_H !# */

/* #! be master~ !# */

/*
#include <stdio.h>
#include <string.h>

void
drunked_walk( const UI1 * bytes, MASTER_maxint len, char output[9][18] ) {
	const char symbols[] = " .o+=*BOX@%&#/^";
	const UI1 symbol_count = sizeof(symbols) / sizeof(symbols[0]);
	SI1 x = 8;
	SI1 y = 4;
	UI1 index;
	UI1 jndex;
	for (index = 0; index < 9; index += 1) {
		for (jndex = 0; jndex < 17; jndex += 1)
			output[index][jndex] = ' ';
		output[index][jndex] = 0;
	}
	while (len > 0) {
		for (index = 0; index < 4; index += 1) {
			jndex = (*bytes >> (index << 1)) & 0x3;
			switch (jndex) {
				case 0:
					x = MASTER_MAX(0, x - 1);
					y = MASTER_MAX(0, y - 1);
				break;
				case 1:
					x = MASTER_MIN(16, x + 1);
					y = MASTER_MAX(0, y - 1);
				break;
				case 2:
					x = MASTER_MAX(0, x - 1);
					y = MASTER_MIN(8, y + 1);
				break;
				case 3:
					x = MASTER_MIN(16, x + 1);
					y = MASTER_MIN(8, y + 1);
				break;
			}
			for (jndex = 0; jndex < symbol_count - 1; jndex += 1)
				if (output[y][x] == symbols[jndex]) {
					output[y][x] = symbols[jndex + 1];
					break;
				}
		}
		len -= 1;
		bytes += 1;
	}
	output[4][8] = 'S';
	output[y][x] = 'E';
}

#define CMDWIDTH 80
#define DRUNKENWALK

int
main(int argc, char** argv) {
	MASTER_Hashlib_Context hash;
	UI1 sum[MASTER_HASHLIB_MAX_DIGEST_SIZE >> 3];
#ifndef NODRUNKENWALK
	UI1 algoused = 0;
	char * dwnames[MASTER_HASHLIB_MAX_ID + 1];
	char dw[MASTER_HASHLIB_MAX_ID + 1][9][18];
	UI1 curdw;
	UI1 dwptr = 0;
	UI1 dwlim = CMDWIDTH / 19;
#endif
	UI1 id;
	UI1 index;
	UI1 jndex;
	UI4 len;
	UI1 ptrlen;
	UI2 size;
	char * ptr;
	if (argc == 1) {
		printf("Usage :\n * %s <some string>\n * * Output : rows with format <algo name> : <[0-9a-f]+ checksum>\n * %s <any argument> -N\n * * Output : list of available algorithms with format <algo1>, <algo2>, ... <algoN>", argv[0], argv[0]);
		return 0;
	}
	if (argc == 3) {
		if (strcmp(argv[2], "-N") == 0) {
			printf("Available algorithms :\n");
			for (id = MASTER_HASHLIB_MIN_ID; id <= MASTER_HASHLIB_MAX_ID; id += 1) {
				printf("%s", MASTER_Hashlib_GetAlgorithmName(id));
				if (id != MASTER_HASHLIB_MAX_ID) printf(", ");
			}
			return 0;
		}
	}
	len = strlen(argv[1]);
	printf("Got '%s' (%d)\n", argv[1], len);
	for (id = MASTER_HASHLIB_MIN_ID; id <= MASTER_HASHLIB_MAX_ID; id += 1, algoused += 1) {
		size = (MASTER_Hashlib_GetAlgorithmOutputSize(id) & 0xFFFF) >> 3;
		ptr = MASTER_Hashlib_GetAlgorithmName(id);

		for (index = 0; index < size; index += 1)
			sum[index] = 0;
		MASTER_Hashlib_Calculate(id, argv[1], len, sum);
		printf("%s : ", ptr);
		for (index = 0; index < size; index += 1)
			printf("%02x", sum[index]);
		putchar('\n');
#ifndef NODRUNKENWALK
		for (index = 0; index < 9; index += 1) {
			for (jndex = 0; jndex < 17; jndex += 1)
				dw[dwptr][index][jndex] = ' ';
			dw[dwptr][index][jndex] = '\0';
		}
		drunked_walk(sum, size, dw[dwptr]);
		dwnames[dwptr] = ptr;
		dwptr += 1;
#endif
	}
#ifndef NODRUNKENWALK
	if (dwlim > 0)
	for (curdw = 0; curdw < algoused; curdw += dwlim) {
		for (index = curdw; index < MASTER_MIN(algoused, curdw + dwlim); index += 1) {
			ptr = dwnames[index];
			ptrlen = strlen(ptr);
			putchar('+');
			for (jndex = 0; jndex < (17 >> 1) - 1 - (ptrlen >> 1) - 1; jndex += 1)
				putchar('-');
			printf("[ %s ]", ptr);
			jndex += 4 + ptrlen;
			for (; jndex < 17; jndex += 1)
				putchar('-');
			putchar('+');
			for (jndex = 0; jndex < (CMDWIDTH % 19) / (dwlim); jndex += 1)
				putchar(' ');
		}
		putchar('\n');
		for (dwptr = 0; dwptr < 9; dwptr += 1) {
			for (index = curdw; index < MASTER_MIN(algoused, curdw + dwlim); index += 1) {
				printf("|%17s|", dw[index][dwptr]);
				for (jndex = 0; jndex < (CMDWIDTH % 19) / (dwlim); jndex += 1)
					putchar(' ');
			}
			putchar('\n');
		}
		for (index = curdw; index < MASTER_MIN(algoused, curdw + dwlim); index += 1) {
			printf("+-----------------+");
			for (jndex = 0; jndex < (CMDWIDTH % 19) / (dwlim); jndex += 1)
				putchar(' ');
		}
		putchar('\n');
	}
#endif
	return 0;
}
*/
