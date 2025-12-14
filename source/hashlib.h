
/*
 * Copyright (c) 2025 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_HASHLIB_INCLUDE_H__
#define __MASTER_HASHLIB_INCLUDE_H__ (MASTER_LIBRARY_TESTING + \
									  MASTER_LIBRARY_INCREMENTHATE + \
									  MASTER_LIBRARY_OCViN + \
									  MASTER_LIBRARY_STDARGS + \
									  MASTER_LIBRARY_GRAPHSHATE + \
									  MASTER_LIBRARY_FREESTANDING)

#include <master_enum.h>

#ifdef MASTER_HASHLIB_EXTERN_ONLY
	#define MASTER_HASHLIB_MD2_EXTERN_ONLY
	#define MASTER_HASHLIB_MD4_EXTERN_ONLY
	#define MASTER_HASHLIB_MD5_EXTERN_ONLY
	#define MASTER_HASHLIB_SHA1_EXTERN_ONLY
#endif /* #! MASTER_HASHLIB_EXTERN_ONLY !# */

#define MASTER_HASHLIB_MD2_ID 0
#define MASTER_HASHLIB_MD4_ID 1
#define MASTER_HASHLIB_MD5_ID 2
#define MASTER_HASHLIB_SHA1_ID 3
#define MASTER_HASHLIB_MIN_ID MASTER_HASHLIB_MD2_ID
#define MASTER_HASHLIB_MAX_ID MASTER_HASHLIB_SHA1_ID

#define MASTER_HASHLIB_MD2_DIGEST_SIZE 128
#define MASTER_HASHLIB_MD4_DIGEST_SIZE 128
#define MASTER_HASHLIB_MD5_DIGEST_SIZE 128
#define MASTER_HASHLIB_SHA1_DIGEST_SIZE 160
#define MASTER_HASHLIB_MIN_DIGEST_SIZE 128
#define MASTER_HASHLIB_MAX_DIGEST_SIZE 160

#define MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( macrofunc ) \
	macrofunc( MD2, MD2, md2c ) \
	macrofunc( MD4, MD4, md4c ) \
	macrofunc( MD5, MD5, md5c ) \
	macrofunc( SHA1, SHA1, sha1c )

/* #! MD2 !# */

typedef struct {
	UI1 state[16];
	UI1 checksum[16];
	UI1 buffer[16];
	UI1 counter;
} MASTER_Hashlib_MD2_Context;

MASTER_PREFER_EXTERN MASTER_Hashlib_MD2_Context
MASTER_Hashlib_MD2_Create( void );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD2_Init( MASTER_Hashlib_MD2_Context * const md2c );
#define MASTER_Hashlib_MD2_Flush MASTER_Hashlib_MD2_Init
MASTER_PREFER_EXTERN MASTER_PREFER_STATIC void
MASTER_Hashlib_MD2_Process( MASTER_Hashlib_MD2_Context * const md2c );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD2_Update( MASTER_Hashlib_MD2_Context * const md2c, const void * bytes, MASTER_maxint len );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD2_Finish( MASTER_Hashlib_MD2_Context * const md2c, UI1 out[MASTER_HASHLIB_MD2_DIGEST_SIZE] );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD2_Calculate( const void * const bytes, const MASTER_maxint len, UI1 out[MASTER_HASHLIB_MD2_DIGEST_SIZE] );

const UI1 MASTER_Hashlib_MD2_Table1[256];

#ifndef MASTER_HASHLIB_MD2_EXTERN_ONLY

MASTER_Hashlib_MD2_Context
MASTER_Hashlib_MD2_Create( void ) {
	MASTER_Hashlib_MD2_Context md2c;
	UI1 index = 0;
	for (; index < 16; index += 1) {
		md2c.state[index] = 0;
		md2c.checksum[index] = 0;
		md2c.buffer[index] = 0;
	}
	md2c.counter = 0;
	return md2c;
}

void
MASTER_Hashlib_MD2_Init( MASTER_Hashlib_MD2_Context * const md2c ) {
	UI1 index = 0;
	__MASTER_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	for (; index < 16; index += 1) {
		md2c->state[index] = 0;
		md2c->checksum[index] = 0;
		md2c->buffer[index] = 0;
	}
	md2c->counter = 0;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_MD2_Process( MASTER_Hashlib_MD2_Context * const md2c ) {
	UI1 chunk[48];
	UI1 timevar = 0;
	UI1 index = 0;
	UI1 jndex;
	for (; index < 16; index += 1) {
		chunk[index] = md2c->state[index];
		chunk[index | 16] = md2c->buffer[index];
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
		timevar = (md2c->checksum[index] ^= MASTER_Hashlib_MD2_Table1[md2c->buffer[index] ^ timevar]);
}

void
MASTER_Hashlib_MD2_Update( MASTER_Hashlib_MD2_Context * const md2c, const void * bytes, MASTER_maxint len ) {
	__MASTER_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	while (len > 0) {
		md2c->buffer[md2c->counter] = *(UI1 *)bytes;
		md2c->counter += 1;
		if (md2c->counter == 16) {
			MASTER_Hashlib_MD2_Process(md2c);
			md2c->counter = 0;
		}
		bytes = (UI1 *)bytes + 1;
		len -= 1;
	}
}

void
MASTER_Hashlib_MD2_Finish( MASTER_Hashlib_MD2_Context * const md2c, UI1 out[MASTER_HASHLIB_MD2_DIGEST_SIZE] ) {
	UI1 estlen;
	UI1 index;
	__MASTER_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( out, MASTER_NOTHING );
	estlen = 16 - md2c->counter;
	for (index = 16 - estlen; index < 16; index += 1)
		md2c->buffer[index] = estlen;
	MASTER_Hashlib_MD2_Process(md2c);
	for (index = 0; index < 16; index += 1)
		md2c->buffer[index] = md2c->checksum[index];
	MASTER_Hashlib_MD2_Process(md2c);
	for (index = 0; index < 16; index += 1)
		out[index] = md2c->state[index];
}

void
MASTER_Hashlib_MD2_Calculate( const void * const bytes, const MASTER_maxint len, UI1 out[MASTER_HASHLIB_MD2_DIGEST_SIZE] ) {
	MASTER_Hashlib_MD2_Context md2c = MASTER_Hashlib_MD2_Create();
	MASTER_Hashlib_MD2_Update(&md2c, bytes, len);
	MASTER_Hashlib_MD2_Finish(&md2c, out);
}

#endif /* #! MASTER_HASHLIB_MD2_EXTERN_ONLY !# */

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

/* #! MD4 !# */

typedef struct {
	UI1 buffer[64];
	UI4 state[4];
	UI4 count[2];
} MASTER_Hashlib_MD4_Context;

MASTER_PREFER_EXTERN MASTER_Hashlib_MD4_Context
MASTER_Hashlib_MD4_Create( void );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD4_Init( MASTER_Hashlib_MD4_Context * const md4c );
#define MASTER_Hashlib_MD4_Flush MASTER_Hashlib_MD4_Init
MASTER_PREFER_EXTERN MASTER_PREFER_STATIC void
MASTER_Hashlib_MD4_Process( MASTER_Hashlib_MD4_Context * const md4c );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD4_Update( MASTER_Hashlib_MD4_Context * const md4c, const void * bytes, MASTER_maxint len );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD4_Finish( MASTER_Hashlib_MD4_Context * const md4c, UI1 out[MASTER_HASHLIB_MD4_DIGEST_SIZE] );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD4_Calculate( const void * const bytes, const MASTER_maxint len, UI1 out[MASTER_HASHLIB_MD4_DIGEST_SIZE] );

#ifndef MASTER_HASHLIB_MD4_EXTERN_ONLY

#define MASTER_HASHLIB_MD4_FUNC1( alpha, beta, gamma ) (((alpha) & (beta)) | (~(alpha) & (gamma)))
#define MASTER_HASHLIB_MD4_FUNC2( alpha, beta, gamma ) (((alpha) & (beta)) | ((alpha) & (gamma)) | ((beta) & (gamma)))
#define MASTER_HASHLIB_MD4_FUNC3( alpha, beta, gamma ) ((alpha) ^ (beta) ^ (gamma))
#define MASTER_HASHLIB_MD4_FUNC4( alpha, beta, gamma, zeta, epsilon, teta ) (alpha) = MASTER_RLL32((alpha) + (epsilon) + MASTER_HASHLIB_MD4_FUNC1(beta, gamma, zeta), teta)
#define MASTER_HASHLIB_MD4_FUNC5( alpha, beta, gamma, zeta, epsilon, teta ) (alpha) = MASTER_RLL32((alpha) + (epsilon) + 0x5A827999 + MASTER_HASHLIB_MD4_FUNC2(beta, gamma, zeta), teta)
#define MASTER_HASHLIB_MD4_FUNC6( alpha, beta, gamma, zeta, epsilon, teta ) (alpha) = MASTER_RLL32((alpha) + (epsilon) + 0x6ED9EBA1 + MASTER_HASHLIB_MD4_FUNC3(beta, gamma, zeta), teta)

MASTER_Hashlib_MD4_Context
MASTER_Hashlib_MD4_Create( void ) {
	MASTER_Hashlib_MD4_Context md4c;
	UI1 index = 0;
	for (; index < 64; index += 1)
		md4c.buffer[index] = 0;
	md4c.count[0] = md4c.count[1] = 0;
	md4c.state[0] = 0x67452301;
	md4c.state[1] = 0xEFCDAB89;
	md4c.state[2] = 0x98BADCFE;
	md4c.state[3] = 0x10325476;
	return md4c;
}

void
MASTER_Hashlib_MD4_Init( MASTER_Hashlib_MD4_Context * const md4c ) {
	UI1 index = 0;
	__MASTER_CHECK_NUL_RETURN( md4c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		md4c->buffer[index] = 0;
	md4c->count[0] = md4c->count[1] = 0;
	md4c->state[0] = 0x67452301;
	md4c->state[1] = 0xEFCDAB89;
	md4c->state[2] = 0x98BADCFE;
	md4c->state[3] = 0x10325476;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_MD4_Process( MASTER_Hashlib_MD4_Context * const md4c ) {
	UI4 chunk[16];
	UI4 wordA = md4c->state[0];
	UI4 wordB = md4c->state[1];
	UI4 wordC = md4c->state[2];
	UI4 wordD = md4c->state[3];
	UI1 index = 0;
	for (; index < 16; index += 1) 
		chunk[index] = (md4c->buffer[3 | (index << 2)] << 24) | (md4c->buffer[2 | (index << 2)] << 16) | (md4c->buffer[1 | (index << 2)] << 8) | md4c->buffer[index << 2];
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD4_FUNC4( wordA, wordB, wordC, wordD, chunk[index << 2], 3);
		MASTER_HASHLIB_MD4_FUNC4( wordD, wordA, wordB, wordC, chunk[(index << 2) | 1], 7);
		MASTER_HASHLIB_MD4_FUNC4( wordC, wordD, wordA, wordB, chunk[(index << 2) | 2], 11);
		MASTER_HASHLIB_MD4_FUNC4( wordB, wordC, wordD, wordA, chunk[(index << 2) | 3], 19);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD4_FUNC5( wordA, wordB, wordC, wordD, chunk[index], 3);
		MASTER_HASHLIB_MD4_FUNC5( wordD, wordA, wordB, wordC, chunk[index | 4], 5);
		MASTER_HASHLIB_MD4_FUNC5( wordC, wordD, wordA, wordB, chunk[index | 8], 9);
		MASTER_HASHLIB_MD4_FUNC5( wordB, wordC, wordD, wordA, chunk[index | 12], 13);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD4_FUNC6( wordA, wordB, wordC, wordD, chunk[((index & 1) << 1) | ((index & 2) >> 1)], 3);
		MASTER_HASHLIB_MD4_FUNC6( wordD, wordA, wordB, wordC, chunk[(((index & 1) << 1) | ((index & 2) >> 1)) | 8], 9);
		MASTER_HASHLIB_MD4_FUNC6( wordC, wordD, wordA, wordB, chunk[(((index & 1) << 1) | ((index & 2) >> 1)) | 4], 11);
		MASTER_HASHLIB_MD4_FUNC6( wordB, wordC, wordD, wordA, chunk[(((index & 1) << 1) | ((index & 2) >> 1)) | 12], 15);
	}
	md4c->state[0] += wordA;
	md4c->state[1] += wordB;
	md4c->state[2] += wordC;
	md4c->state[3] += wordD;
}

void
MASTER_Hashlib_MD4_Update( MASTER_Hashlib_MD4_Context * const md4c, const void * bytes, MASTER_maxint len ) {
	__MASTER_CHECK_NUL_RETURN( md4c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	while (len > 0) {
		md4c->buffer[md4c->count[0] & 0x3F] = *(UI1 *)bytes;
		md4c->count[0] += 1;
		if (md4c->count[0] == 0)
			md4c->count[1] += 1;
		if ((md4c->count[0] & 0x3F) == 0)
			MASTER_Hashlib_MD4_Process(md4c);
		bytes = (UI1 *)bytes + 1;
		len -= 1;
	}
}

void
MASTER_Hashlib_MD4_Finish( MASTER_Hashlib_MD4_Context * const md4c, UI1 out[MASTER_HASHLIB_MD4_DIGEST_SIZE] ) {
	UI1 index;
	__MASTER_CHECK_NUL_RETURN( md4c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( out, MASTER_NOTHING );
	index = md4c->count[0] & 0x3F;
	md4c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			md4c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			md4c->buffer[index] = 0;
		MASTER_Hashlib_MD4_Process(md4c);
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
	MASTER_Hashlib_MD4_Process(md4c);
	for (index = 0; index < 4; index += 1) {
		out[index] = md4c->state[0] >> (index << 3);
		out[index | 4] = md4c->state[1] >> (index << 3);
		out[index | 8] = md4c->state[2] >> (index << 3);
		out[index | 12] = md4c->state[3] >> (index << 3);
	}
}

void
MASTER_Hashlib_MD4_Calculate( const void * const bytes, const MASTER_maxint len, UI1 out[MASTER_HASHLIB_MD4_DIGEST_SIZE] ) {
	MASTER_Hashlib_MD4_Context md4c;
	__MASTER_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( out, MASTER_NOTHING );
	md4c = MASTER_Hashlib_MD4_Create();
	MASTER_Hashlib_MD4_Update(&md4c, bytes, len);
	MASTER_Hashlib_MD4_Finish(&md4c, out);
}

#endif /* #! MASTER_HASHLIB_MD4_EXTERN_ONLY !# */

/* #! MD5 !# */

typedef struct {
	UI1 buffer[64];
	UI4 state[4];
	UI4 count[2];
} MASTER_Hashlib_MD5_Context;

MASTER_PREFER_EXTERN MASTER_Hashlib_MD5_Context
MASTER_Hashlib_MD5_Create( void );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD5_Init( MASTER_Hashlib_MD5_Context * const md5c );
#define MASTER_Hashlib_MD5_Flush MASTER_Hashlib_MD5_Init
MASTER_PREFER_EXTERN MASTER_PREFER_STATIC void
MASTER_Hashlib_MD5_Process( MASTER_Hashlib_MD5_Context * const md5c );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD5_Update( MASTER_Hashlib_MD5_Context * const md5c, const void * bytes, MASTER_maxint len );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD5_Finish( MASTER_Hashlib_MD5_Context * const md5c, UI1 out[MASTER_HASHLIB_MD5_DIGEST_SIZE] );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_MD5_Calculate( const void * const bytes, const MASTER_maxint len, UI1 out[MASTER_HASHLIB_MD5_DIGEST_SIZE] );

const UI4 MASTER_Hashlib_MD5_Table1[64];

#ifndef MASTER_HASHLIB_MD5_EXTERN_ONLY

#define MASTER_HASHLIB_MD5_FUNC1( alpha, beta, gamma ) (((alpha) & (beta)) | (~(alpha) & (gamma)))
#define MASTER_HASHLIB_MD5_FUNC2( alpha, beta, gamma ) (((alpha) & (gamma)) | ((beta) & ~(gamma)))
#define MASTER_HASHLIB_MD5_FUNC3( alpha, beta, gamma ) ((alpha) ^ (beta) ^ (gamma))
#define MASTER_HASHLIB_MD5_FUNC4( alpha, beta, gamma ) ((beta) ^ ((alpha) | ~(gamma)))
#define MASTER_HASHLIB_MD5_FUNC5( a, b, c, d, x, s, ac ) \
	(a) += MASTER_HASHLIB_MD5_FUNC1(b, c, d) + (x) + (UI4)(ac); \
	(a) = MASTER_RLL32(a, s); \
	(a) += (b)
#define MASTER_HASHLIB_MD5_FUNC6( a, b, c, d, x, s, ac ) \
	(a) += MASTER_HASHLIB_MD5_FUNC2(b, c, d) + (x) + (UI4)(ac); \
	(a) = MASTER_RLL32(a, s); \
	(a) += (b)
#define MASTER_HASHLIB_MD5_FUNC7( a, b, c, d, x, s, ac ) \
	(a) += MASTER_HASHLIB_MD5_FUNC3(b, c, d) + (x) + (UI4)(ac); \
	(a) = MASTER_RLL32(a, s); \
	(a) += (b)
#define MASTER_HASHLIB_MD5_FUNC8( a, b, c, d, x, s, ac ) \
	(a) += MASTER_HASHLIB_MD5_FUNC4(b, c, d) + (x) + (UI4)(ac); \
	(a) = MASTER_RLL32(a, s); \
	(a) += (b)

MASTER_Hashlib_MD5_Context
MASTER_Hashlib_MD5_Create( void ) {
	MASTER_Hashlib_MD5_Context md5c;
	UI1 index = 0;
	for (; index < 64; index += 1)
		md5c.buffer[index] = 0;
	md5c.count[0] = md5c.count[1] = 0;
	md5c.state[0] = 0x67452301;
	md5c.state[1] = 0xEFCDAB89;
	md5c.state[2] = 0x98BADCFE;
	md5c.state[3] = 0x10325476;
	return md5c;
}

void
MASTER_Hashlib_MD5_Init( MASTER_Hashlib_MD5_Context * const md5c ) {
	UI1 index = 0;
	__MASTER_CHECK_NUL_RETURN( md5c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		md5c->buffer[index] = 0;
	md5c->count[0] = md5c->count[1] = 0;
	md5c->state[0] = 0x67452301;
	md5c->state[1] = 0xEFCDAB89;
	md5c->state[2] = 0x98BADCFE;
	md5c->state[3] = 0x10325476;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_MD5_Process( MASTER_Hashlib_MD5_Context * const md5c ) {
	UI4 chunk[16];
	UI4 wordA = md5c->state[0];
	UI4 wordB = md5c->state[1];
	UI4 wordC = md5c->state[2];
	UI4 wordD = md5c->state[3];
	UI1 index = 0;
	for (; index < 16; index += 1) 
		chunk[index] = (md5c->buffer[3 | (index << 2)] << 24) | (md5c->buffer[2 | (index << 2)] << 16) | (md5c->buffer[1 | (index << 2)] << 8) | md5c->buffer[index << 2];
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD5_FUNC5( wordA, wordB, wordC, wordD, chunk[index << 2], 7, MASTER_Hashlib_MD5_Table1[index << 2]);
		MASTER_HASHLIB_MD5_FUNC5( wordD, wordA, wordB, wordC, chunk[(index << 2) | 1], 12, MASTER_Hashlib_MD5_Table1[(index << 2) | 1]);
		MASTER_HASHLIB_MD5_FUNC5( wordC, wordD, wordA, wordB, chunk[(index << 2) | 2], 17, MASTER_Hashlib_MD5_Table1[(index << 2) | 2]);
		MASTER_HASHLIB_MD5_FUNC5( wordB, wordC, wordD, wordA, chunk[(index << 2) | 3], 22, MASTER_Hashlib_MD5_Table1[(index << 2) | 3]);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD5_FUNC6( wordA, wordB, wordC, wordD, chunk[1 | (index << 2)], 5, MASTER_Hashlib_MD5_Table1[(index << 2) | 16]);
		MASTER_HASHLIB_MD5_FUNC6( wordD, wordA, wordB, wordC, chunk[(6 + (index << 2)) & 0xF], 9, MASTER_Hashlib_MD5_Table1[(index << 2) | 17]);
		MASTER_HASHLIB_MD5_FUNC6( wordC, wordD, wordA, wordB, chunk[(11 + (index << 2)) & 0xF], 14, MASTER_Hashlib_MD5_Table1[(index << 2) | 18]);
		MASTER_HASHLIB_MD5_FUNC6( wordB, wordC, wordD, wordA, chunk[index << 2], 20, MASTER_Hashlib_MD5_Table1[(index << 2) | 19]);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD5_FUNC7( wordA, wordB, wordC, wordD, chunk[(5 + index * 12) & 0xF], 4, MASTER_Hashlib_MD5_Table1[(index << 2) | 32]);
		MASTER_HASHLIB_MD5_FUNC7( wordD, wordA, wordB, wordC, chunk[(8 + index * 12) & 0xF], 11, MASTER_Hashlib_MD5_Table1[(index << 2) | 33]);
		MASTER_HASHLIB_MD5_FUNC7( wordC, wordD, wordA, wordB, chunk[(11 + index * 12) & 0xF], 16, MASTER_Hashlib_MD5_Table1[(index << 2) | 34]);
		MASTER_HASHLIB_MD5_FUNC7( wordB, wordC, wordD, wordA, chunk[(14 + index * 12) & 0xF], 23, MASTER_Hashlib_MD5_Table1[(index << 2) | 35]);
	}
	for (index = 0; index < 4; index += 1) {
		MASTER_HASHLIB_MD5_FUNC8( wordA, wordB, wordC, wordD, chunk[(index * 12) & 0xF], 6, MASTER_Hashlib_MD5_Table1[(index << 2) | 48]);
		MASTER_HASHLIB_MD5_FUNC8( wordD, wordA, wordB, wordC, chunk[(7 + index * 12) & 0xF], 10, MASTER_Hashlib_MD5_Table1[(index << 2) | 49]);
		MASTER_HASHLIB_MD5_FUNC8( wordC, wordD, wordA, wordB, chunk[(14 + index * 12) & 0xF], 15, MASTER_Hashlib_MD5_Table1[(index << 2) | 50]);
		MASTER_HASHLIB_MD5_FUNC8( wordB, wordC, wordD, wordA, chunk[(5 + index * 12) & 0xF], 21, MASTER_Hashlib_MD5_Table1[(index << 2) | 51]);
	}
	md5c->state[0] += wordA;
	md5c->state[1] += wordB;
	md5c->state[2] += wordC;
	md5c->state[3] += wordD;
}

void
MASTER_Hashlib_MD5_Update( MASTER_Hashlib_MD5_Context * const md5c, const void * bytes, MASTER_maxint len ) {
	__MASTER_CHECK_NUL_RETURN( md5c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	while (len > 0) {
		md5c->buffer[md5c->count[0] & 0x3F] = *(UI1 *)bytes;
		md5c->count[0] += 1;
		if (md5c->count[0] == 0)
			md5c->count[1] += 1;
		if ((md5c->count[0] & 0x3F) == 0)
			MASTER_Hashlib_MD5_Process(md5c);
		bytes = (UI1 *)bytes + 1;
		len -= 1;
	}
}

void
MASTER_Hashlib_MD5_Finish( MASTER_Hashlib_MD5_Context * const md5c, UI1 out[MASTER_HASHLIB_MD5_DIGEST_SIZE] ) {
	UI1 index;
	__MASTER_CHECK_NUL_RETURN( md5c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( out, MASTER_NOTHING );
	index = md5c->count[0] & 0x3F;
	md5c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			md5c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			md5c->buffer[index] = 0;
		MASTER_Hashlib_MD5_Process(md5c);
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
	MASTER_Hashlib_MD5_Process(md5c);
	for (index = 0; index < 4; index += 1) {
		out[index] = md5c->state[0] >> (index << 3);
		out[index | 4] = md5c->state[1] >> (index << 3);
		out[index | 8] = md5c->state[2] >> (index << 3);
		out[index | 12] = md5c->state[3] >> (index << 3);
	}
}

void
MASTER_Hashlib_MD5_Calculate( const void * const bytes, const MASTER_maxint len, UI1 out[MASTER_HASHLIB_MD5_DIGEST_SIZE] ) {
	MASTER_Hashlib_MD5_Context md5c;
	__MASTER_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( out, MASTER_NOTHING );
	md5c = MASTER_Hashlib_MD5_Create();
	MASTER_Hashlib_MD5_Update(&md5c, bytes, len);
	MASTER_Hashlib_MD5_Finish(&md5c, out);
}

#endif /* #! MASTER_HASHLIB_MD5_EXTERN_ONLY !# */

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

/* #! SHA-1 !# */

typedef struct {
	UI1 buffer[64];
	UI4 state[5];
	UI4 count[2];
} MASTER_Hashlib_SHA1_Context;

MASTER_PREFER_EXTERN MASTER_Hashlib_SHA1_Context
MASTER_Hashlib_SHA1_Create( void );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_SHA1_Init( MASTER_Hashlib_SHA1_Context * const sha1c );
#define MASTER_Hashlib_SHA1_Flush MASTER_Hashlib_SHA1_Init
MASTER_PREFER_EXTERN MASTER_PREFER_STATIC void
MASTER_Hashlib_SHA1_Process( MASTER_Hashlib_SHA1_Context * const sha1c );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_SHA1_Update( MASTER_Hashlib_SHA1_Context * const sha1c, const void * bytes, MASTER_maxint len );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_SHA1_Finish( MASTER_Hashlib_SHA1_Context * const sha1c, UI1 out[MASTER_HASHLIB_SHA1_DIGEST_SIZE] );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_SHA1_Calculate( const void * const bytes, const MASTER_maxint len, UI1 out[MASTER_HASHLIB_SHA1_DIGEST_SIZE] );

const UI4 MASTER_Hashlib_SHA1_Table1[4];

#ifndef MASTER_HASHLIB_SHA1_EXTERN_ONLY

MASTER_Hashlib_SHA1_Context
MASTER_Hashlib_SHA1_Create( void ) {
	MASTER_Hashlib_SHA1_Context sha1c;
	UI1 index = 0;
	for (; index < 64; index += 1)
		sha1c.buffer[index] = 0;
	sha1c.count[0] = sha1c.count[1] = 0;
	sha1c.state[0] = 0x67452301;
	sha1c.state[1] = 0xEFCDAB89;
	sha1c.state[2] = 0x98BADCFE;
	sha1c.state[3] = 0x10325476;
	sha1c.state[4] = 0xC3D2E1F0;
	return sha1c;
}

void
MASTER_Hashlib_SHA1_Init( MASTER_Hashlib_SHA1_Context * const sha1c ) {
	UI1 index = 0;
	__MASTER_CHECK_NUL_RETURN( sha1c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		sha1c->buffer[index] = 0;
	sha1c->count[0] = sha1c->count[1] = 0;
	sha1c->state[0] = 0x67452301;
	sha1c->state[1] = 0xEFCDAB89;
	sha1c->state[2] = 0x98BADCFE;
	sha1c->state[3] = 0x10325476;
	sha1c->state[4] = 0xC3D2E1F0;
}

MASTER_PREFER_STATIC void
MASTER_Hashlib_SHA1_Process( MASTER_Hashlib_SHA1_Context * const sha1c ) {
	UI4 chunk[80];
	UI4 wordA = sha1c->state[0];
	UI4 wordB = sha1c->state[1];
	UI4 wordC = sha1c->state[2];
	UI4 wordD = sha1c->state[3];
	UI4 wordE = sha1c->state[4];
	UI4 timevar;
	UI1 index = 0;
	for (; index < 16; index += 1) 
		chunk[index] = (sha1c->buffer[index << 2] << 24) | (sha1c->buffer[1 | (index << 2)] << 16) | (sha1c->buffer[2 | (index << 2)] << 8) | sha1c->buffer[3 | (index << 2)];
	for (; index < 80; index += 1)
		chunk[index] = MASTER_RLL32(chunk[index - 3] ^ chunk[index - 8] ^ chunk[index - 14] ^ chunk[index - 16], 1);
	for (index = 0; index < 20; index += 1) {
		timevar = MASTER_RLL32(wordA, 5) + ((wordB & wordC) | ((~wordB) & wordD)) + wordE + chunk[index] + MASTER_Hashlib_SHA1_Table1[0];
		wordE = wordD;
		wordD = wordC;
		wordC = MASTER_RLL32(wordB, 30);
		wordB = wordA;
		wordA = timevar;
	}
	for (; index < 40; index += 1) {
		timevar = MASTER_RLL32(wordA, 5) + (wordB ^ wordC ^ wordD) + wordE + chunk[index] + MASTER_Hashlib_SHA1_Table1[1];
		wordE = wordD;
		wordD = wordC;
		wordC = MASTER_RLL32(wordB, 30);
		wordB = wordA;
		wordA = timevar;
	}
	for (; index < 60; index += 1) {
		timevar = MASTER_RLL32(wordA, 5) + ((wordB & wordC) | (wordB & wordD) | (wordC & wordD)) + wordE + chunk[index] + MASTER_Hashlib_SHA1_Table1[2];
		wordE = wordD;
		wordD = wordC;
		wordC = MASTER_RLL32(wordB, 30);
		wordB = wordA;
		wordA = timevar;
	}
	for (; index < 80; index += 1) {
		timevar = MASTER_RLL32(wordA, 5) + (wordB ^ wordC ^ wordD) + wordE + chunk[index] + MASTER_Hashlib_SHA1_Table1[3];
		wordE = wordD;
		wordD = wordC;
		wordC = MASTER_RLL32(wordB, 30);
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
MASTER_Hashlib_SHA1_Update( MASTER_Hashlib_SHA1_Context * const sha1c, const void * bytes, MASTER_maxint len ) {
	__MASTER_CHECK_NUL_RETURN( sha1c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	while (len > 0) {
		sha1c->buffer[sha1c->count[0] & 0x3F] = *(UI1 *)bytes;
		sha1c->count[0] += 1;
		if (sha1c->count[0] == 0)
			sha1c->count[1] += 1;
		if ((sha1c->count[0] & 0x3F) == 0)
			MASTER_Hashlib_SHA1_Process(sha1c);
		bytes = (UI1 *)bytes + 1;
		len -= 1;
	}
}

void
MASTER_Hashlib_SHA1_Finish( MASTER_Hashlib_SHA1_Context * const sha1c, UI1 out[MASTER_HASHLIB_SHA1_DIGEST_SIZE] ) {
	UI1 index;
	__MASTER_CHECK_NUL_RETURN( sha1c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( out, MASTER_NOTHING );
	index = sha1c->count[0] & 0x3F;
	sha1c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			sha1c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			sha1c->buffer[index] = 0;
		MASTER_Hashlib_SHA1_Process(sha1c);
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
	MASTER_Hashlib_SHA1_Process(sha1c);
	for (index = 0; index < 4; index += 1) {
		out[index] = sha1c->state[0] >> ((3 - index) << 3);
		out[index | 4] = sha1c->state[1] >> ((3 - index) << 3);
		out[index | 8] = sha1c->state[2] >> ((3 - index) << 3);
		out[index | 12] = sha1c->state[3] >> ((3 - index) << 3);
		out[index | 16] = sha1c->state[4] >> ((3 - index) << 3);
	}
}

void
MASTER_Hashlib_SHA1_Calculate( const void * const bytes, const MASTER_maxint len, UI1 out[MASTER_HASHLIB_SHA1_DIGEST_SIZE] ) {
	MASTER_Hashlib_SHA1_Context sha1c;
	__MASTER_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( out, MASTER_NOTHING );
	sha1c = MASTER_Hashlib_SHA1_Create();
	MASTER_Hashlib_SHA1_Update(&sha1c, bytes, len);
	MASTER_Hashlib_SHA1_Finish(&sha1c, out);
}

#endif /* #! MASTER_HASHLIB_SHA1_EXTERN_ONLY !# */

const UI4 MASTER_Hashlib_SHA1_Table1[4] = {
	0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6
};

/* #! API !# */

typedef struct {
	UI1 id;
	union {
#define MASTER_HASHLIB_API_CREATE_HANDLER_STRUCTURE( macro_name, algorithm_name, member ) \
	MASTER_Hashlib_## algorithm_name ##_Context member;
	
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_STRUCTURE )
	} context;
} MASTER_Hashlib_Context;

MASTER_PREFER_EXTERN MASTER_Hashlib_Context
MASTER_Hashlib_Create( const UI1 id );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_Init( MASTER_Hashlib_Context * const hash, const UI1 id );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_Flush( MASTER_Hashlib_Context * const hash );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_Update( MASTER_Hashlib_Context * const hash, const void * const bytes, const MASTER_maxint len );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_Finish( MASTER_Hashlib_Context * const hash, UI1 * const out );
MASTER_PREFER_EXTERN void
MASTER_Hashlib_Calculate( const UI1 id, const void * const bytes, const MASTER_maxint len, UI1 * const out );
MASTER_PREFER_EXTERN char *
MASTER_Hashlib_GetAlgorithmName( const UI1 id );
MASTER_PREFER_EXTERN MASTER_maxint
MASTER_Hashlib_GetAlgorithmOutputSize( const UI1 id );

#ifndef MASTER_HASHLIB_API_EXTERN_ONLY

MASTER_Hashlib_Context
MASTER_Hashlib_Create( const UI1 id ) {
	MASTER_Hashlib_Context hash;
	hash.id = id;
	switch (hash.id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_CREATE( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			hash.context.member = MASTER_Hashlib_## algorithm_name ##_Create(); \
		break;
		
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_CREATE )
	};
	return hash;
}

void
MASTER_Hashlib_Init( MASTER_Hashlib_Context * const hash, const UI1 id ) {
	hash->id = id;
	switch (hash->id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_INIT( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Init(&(hash->context.member)); \
		break;
		
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_INIT )
	};
}

void
MASTER_Hashlib_Flush( MASTER_Hashlib_Context * const hash ) {
	switch (hash->id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_FLUSH( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Flush(&(hash->context.member)); \
		break;
		
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_FLUSH )
	};
}

void
MASTER_Hashlib_Update( MASTER_Hashlib_Context * const hash, const void * const bytes, const MASTER_maxint len ) {
	switch (hash->id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_UPDATE( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Update(&(hash->context.member), bytes, len); \
		break;
		
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_UPDATE )
	};
}

void
MASTER_Hashlib_Finish( MASTER_Hashlib_Context * const hash, UI1 * const out ) {
	switch (hash->id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_FINISH( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Finish(&(hash->context.member), out); \
		break;
		
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_FINISH )
	};
}

void
MASTER_Hashlib_Calculate( const UI1 id, const void * const bytes, const MASTER_maxint len, UI1 * const out ) {
	switch (id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_CALCULATE( macro_name, algorithm_name, member ) \
		case MASTER_HASHLIB_## macro_name ##_ID: \
			MASTER_Hashlib_## algorithm_name ##_Calculate(bytes, len, out); \
		break;
		
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_CALCULATE )
	};
}

char *
MASTER_Hashlib_GetAlgorithmName( const UI1 id ) {
	switch (id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_GETALGORITHMNAME( macro_name, algorithm_name, __not_used_1__ ) \
		case MASTER_HASHLIB_## macro_name ##_ID : return #algorithm_name;
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_GETALGORITHMNAME )
		default : return "Unknown";
	}
}

MASTER_maxint
MASTER_Hashlib_GetAlgorithmOutputSize( const UI1 id ) {
	switch (id) {
#define MASTER_HASHLIB_API_CREATE_HANDLER_GETALGORITHMOUTPUTSIZE( macro_name, algorithm_name, __not_used_1__ ) \
		case MASTER_HASHLIB_## macro_name ##_ID : return MASTER_HASHLIB_## macro_name ##_DIGEST_SIZE;
		
		MASTER_HASHLIB_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_HASHLIB_API_CREATE_HANDLER_GETALGORITHMOUTPUTSIZE )
		default : return 0;
	}
}

#endif /* #! MASTER_HASHLIB_API_EXTERN_ONLY !# */

#endif /* #! __MASTER_HASHLIB_INCLUDE_H__ !# */
/*
// #include <stdio.h>
// #include <string.h>

// void
// drunked_walk( const UI1 * bytes, MASTER_maxint len, char out[9][18] ) {
	// const char symbols[] = " .o+=*BOX@%&#/^";
	// const UI1 symbol_count = sizeof(symbols) / sizeof(symbols[0]);
	// SI1 x = 8;
	// SI1 y = 4;
	// UI1 index;
	// UI1 jndex;
	// for (index = 0; index < 9; index += 1) {
		// for (jndex = 0; jndex < 17; jndex += 1)
			// out[index][jndex] = ' ';
		// out[index][jndex] = 0;
	// }
	// while (len > 0) {
		// for (index = 0; index < 4; index += 1) {
			// jndex = (*bytes >> (index << 1)) & 0x3;
			// switch (jndex) {
				// case 0:
					// x = MASTER_MAX(0, x - 1);
					// y = MASTER_MAX(0, y - 1);
				// break;
				// case 1:
					// x = MASTER_MIN(16, x + 1);
					// y = MASTER_MAX(0, y - 1);
				// break;
				// case 2:
					// x = MASTER_MAX(0, x - 1);
					// y = MASTER_MIN(8, y + 1);
				// break;
				// case 3:
					// x = MASTER_MIN(16, x + 1);
					// y = MASTER_MIN(8, y + 1);
				// break;
			// }
			// for (jndex = 0; jndex < symbol_count - 1; jndex += 1)
				// if (out[y][x] == symbols[jndex]) {
					// out[y][x] = symbols[jndex + 1];
					// break;
				// }
		// }
		// len -= 1;
		// bytes += 1;
	// }
	// out[4][8] = 'S';
	// out[y][x] = 'E';
// }

// #define CMDWIDTH 80
// #define DRUNKENWALK

// int
// main(int argc, char** argv) {
	// MASTER_Hashlib_Context hash;
	// UI1 sum[MASTER_HASHLIB_MAX_DIGEST_SIZE];
// #ifndef NODRUNKENWALK
	// UI1 algoused = 0;
	// char * dwnames[MASTER_HASHLIB_MAX_ID + 1];
	// char dw[MASTER_HASHLIB_MAX_ID + 1][9][18];
	// UI1 curdw;
	// UI1 dwptr = 0;
	// UI1 dwlim = CMDWIDTH / 19;
// #endif
	// UI1 id;
	// UI1 index;
	// UI1 jndex;
	// UI4 len;
	// UI1 ptrlen;
	// UI2 size;
	// char * ptr;
	// if (argc == 1) {
		// printf("Usage :\n * %s <some string>\n * * Output : rows with format <algo name> : <[0-9a-f]+ checksum>\n * %s <any argument> -N\n * * Output : list of available algorithms with format <algo1>, <algo2>, ... <algoN>", argv[0], argv[0]);
		// return 0;
	// }
	// if (argc == 3) {
		// if (strcmp(argv[2], "-N") == 0) {
			// printf("Available algorithms :\n");
			// for (id = MASTER_HASHLIB_MIN_ID; id <= MASTER_HASHLIB_MAX_ID; id += 1) {
				// printf("%s", MASTER_Hashlib_GetAlgorithmName(id));
				// if (id != MASTER_HASHLIB_MAX_ID) printf(", ");
			// }
			// return 0;
		// }
	// }
	// len = strlen(argv[1]);
	// printf("Got '%s' (%d)\n", argv[1], len);
	// for (id = MASTER_HASHLIB_MIN_ID; id <= MASTER_HASHLIB_MAX_ID; id += 1, algoused += 1) {
		// size = (MASTER_Hashlib_GetAlgorithmOutputSize(id) & 0xFFFF) >> 3;
		// ptr = MASTER_Hashlib_GetAlgorithmName(id);
		
		// for (index = 0; index < size; index += 1)
			// sum[index] = 0;
		// MASTER_Hashlib_Calculate(id, argv[1], len, sum);
		// printf("%s : ", ptr);
		// for (index = 0; index < size; index += 1)
			// printf("%02x", sum[index]);
		// putchar('\n');
// #ifndef NODRUNKENWALK
		// for (index = 0; index < 9; index += 1) {
			// for (jndex = 0; jndex < 17; jndex += 1)
				// dw[dwptr][index][jndex] = ' ';
			// dw[dwptr][index][jndex] = '\0';
		// }
		// drunked_walk(sum, size, dw[dwptr]);
		// dwnames[dwptr] = ptr;
		// dwptr += 1;
// #endif
	// }
// #ifndef NODRUNKENWALK
	// if (dwlim > 0)
	// for (curdw = 0; curdw < algoused; curdw += dwlim) {
		// for (index = curdw; index < MASTER_MIN(algoused, curdw + dwlim); index += 1) {
			// ptr = dwnames[index];
			// ptrlen = strlen(ptr);
			// putchar('+');
			// for (jndex = 0; jndex < (17 >> 1) - 1 - (ptrlen >> 1) - 1; jndex += 1)
				// putchar('-');
			// printf("[ %s ]", ptr);
			// jndex += 4 + ptrlen;
			// for (; jndex < 17; jndex += 1)
				// putchar('-');
			// putchar('+');
			// for (jndex = 0; jndex < (CMDWIDTH % 19) / (dwlim); jndex += 1)
				// putchar(' ');
		// }
		// putchar('\n');
		// for (dwptr = 0; dwptr < 9; dwptr += 1) {
			// for (index = curdw; index < MASTER_MIN(algoused, curdw + dwlim); index += 1) {
				// printf("|%17s|", dw[index][dwptr]);
				// for (jndex = 0; jndex < (CMDWIDTH % 19) / (dwlim); jndex += 1)
					// putchar(' ');
			// }
			// putchar('\n');
		// }
		// for (index = curdw; index < MASTER_MIN(algoused, curdw + dwlim); index += 1) {
			// printf("+-----------------+");
			// for (jndex = 0; jndex < (CMDWIDTH % 19) / (dwlim); jndex += 1)
				// putchar(' ');
		// }
		// putchar('\n');
	// }
// #endif
	// return 0;
// }
*/
