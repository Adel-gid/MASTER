
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_HASHLIB_H
#define MASTER_zzz_HASHLIB_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#define MASTER_OPERATION_XOR3( value1, value2, value3 ) ((value1) ^ (value2) ^ (value3))
#define MASTER_OPERATION_1XB2ON3E( value1, value2, value3 ) ((value1) ^ ((value2) | (~(value3))))
#define MASTER_OPERATION_2XB1ON3E( value1, value2, value3 ) ((value2) ^ ((value1) | (~(value3))))
#define MASTER_OPERATION_3XB1ON2E( value1, value2, value3 ) ((value3) ^ ((value1) | (~(value2))))

/* #! Optimized version of (((value1) & (value2)) | ((~(value1)) & (value3))) !# */
#define MASTER_OPERATION_CHOICE( value1, value2, value3 ) ((value3) ^ ((value1) & ((value2) ^ (value3))))
/* #! Optimized version of (((value1) & (value2)) ^ ((value1) & (value3)) ^ ((value2) & (value3))) !# */
#define MASTER_OPERATION_MAJORITAR( value1, value2, value3 ) ((((value1) | (value2)) & (value3)) | ((value1) & (value2)))

#ifdef MASTER_HASHLIB_EXTERN_ONLY
#	define MASTER_HASHLIB_MD2_IMPLEMENT 0
#	define MASTER_HASHLIB_MD4_IMPLEMENT 0
#	define MASTER_HASHLIB_MD5_IMPLEMENT 0
#	define MASTER_HASHLIB_SHA1_IMPLEMENT 0
#	define MASTER_HASHLIB_SHA2_224_IMPLEMENT 0
#	define MASTER_HASHLIB_SHA2_256_IMPLEMENT 0
#	define MASTER_HASHLIB_SHA2_384_IMPLEMENT 0
#	define MASTER_HASHLIB_SHA2_512_IMPLEMENT 0
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
	   defined(MASTER_HASHLIB_SHA2_224_USE) || \
	   defined(MASTER_HASHLIB_SHA2_256_USE) || \
	   defined(MASTER_HASHLIB_SHA2_384_USE) || \
	   defined(MASTER_HASHLIB_SHA2_512_USE) || \
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
#		if defined(MASTER_HASHLIB_MD2_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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
#		if defined(MASTER_HASHLIB_MD4_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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
#		if defined(MASTER_HASHLIB_MD5_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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
#		if defined(MASTER_HASHLIB_SHA1_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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
#	ifdef MASTER_HASHLIB_SHA2_224_EXTERN
#		define MASTER_HASHLIB_SHA2_224_IMPLEMENT 0
#		if defined(MASTER_HASHLIB_SHA2_224_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
 #			warning "SHA-2/224 is defined to USE, but also defined to EXTERN. SHA-2/224 will NOT be compiled."
#		endif /* #! SHA-2/224 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_SHA2_224_USE
#			define MASTER_HASHLIB_SHA2_224_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_SHA2_224_IMPLEMENT 0
#		endif /* #! SHA-2/224 Use !# */
#	else
#		define MASTER_HASHLIB_SHA2_224_IMPLEMENT 1
#	endif /* #! SHA-2/224 !# */
#	ifdef MASTER_HASHLIB_SHA2_256_EXTERN
#		define MASTER_HASHLIB_SHA2_256_IMPLEMENT 0
#		if defined(MASTER_HASHLIB_SHA2_256_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
 #			warning "SHA-2/256 is defined to USE, but also defined to EXTERN. SHA-2/256 will NOT be compiled."
#		endif /* #! SHA-2/256 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_SHA2_256_USE
#			define MASTER_HASHLIB_SHA2_256_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_SHA2_256_IMPLEMENT 0
#		endif /* #! SHA-2/256 Use !# */
#	else
#		define MASTER_HASHLIB_SHA2_256_IMPLEMENT 1
#	endif /* #! SHA-2/256 !# */
#	ifdef MASTER_HASHLIB_SHA2_384_EXTERN
#		define MASTER_HASHLIB_SHA2_384_IMPLEMENT 0
#		if defined(MASTER_HASHLIB_SHA2_384_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
 #			warning "SHA-2/384 is defined to USE, but also defined to EXTERN. SHA-2/384 will NOT be compiled."
#		endif /* #! SHA-2/384 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_SHA2_384_USE
#			define MASTER_HASHLIB_SHA2_384_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_SHA2_384_IMPLEMENT 0
#		endif /* #! SHA-2/384 Use !# */
#	else
#		define MASTER_HASHLIB_SHA2_384_IMPLEMENT 1
#	endif /* #! SHA-2/384 !# */
#	ifdef MASTER_HASHLIB_SHA2_512_EXTERN
#		define MASTER_HASHLIB_SHA2_512_IMPLEMENT 0
#		if defined(MASTER_HASHLIB_SHA2_512_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
 #			warning "SHA-2/512 is defined to USE, but also defined to EXTERN. SHA-2/512 will NOT be compiled."
#		endif /* #! SHA-2/512 Conflict of Use & Extern !# */
#	elif MASTER_HASHLIB_WHITELIST_MODE == 1
#		ifdef MASTER_HASHLIB_SHA2_512_USE
#			define MASTER_HASHLIB_SHA2_512_IMPLEMENT 1
#		else
#			define MASTER_HASHLIB_SHA2_512_IMPLEMENT 0
#		endif /* #! SHA-2/512 Use !# */
#	else
#		define MASTER_HASHLIB_SHA2_512_IMPLEMENT 1
#	endif /* #! SHA-2/512 !# */
#	ifdef MASTER_HASHLIB_RIPEMD128_EXTERN
#		define MASTER_HASHLIB_RIPEMD128_IMPLEMENT 0
#		if defined(MASTER_HASHLIB_RIPEMD128_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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
#		if defined(MASTER_HASHLIB_RIPEMD160_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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
#		if defined(MASTER_HASHLIB_RIPEMD256_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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
#		if defined(MASTER_HASHLIB_RIPEMD320_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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
#		if defined(MASTER_HASHLIB_MURMURHASH2A_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
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

#ifndef MASTER_UI8_TYPE
#	undef MASTER_HASHLIB_SHA2_384_IMPLEMENT
#	undef MASTER_HASHLIB_SHA2_512_IMPLEMENT
#	define MASTER_HASHLIB_SHA2_384_IMPLEMENT 0
#	define MASTER_HASHLIB_SHA2_512_IMPLEMENT 0
#endif /* #! 64 Bits !# */

typedef enum {
	MASTER_HASHLIB_MD2_ID = 0,
	MASTER_HASHLIB_MD4_ID = 1,
	MASTER_HASHLIB_MD5_ID = 2,
	MASTER_HASHLIB_SHA1_ID = 3,
	MASTER_HASHLIB_SHA2_224_ID = 4,
	MASTER_HASHLIB_SHA2_256_ID = 5,
#ifdef MASTER_UI8_TYPE
	MASTER_HASHLIB_SHA2_384_ID = 6,
	MASTER_HASHLIB_SHA2_512_ID = 7,
#endif /* #! 64 Bits !# */
	MASTER_HASHLIB_RIPEMD128_ID = 8,
	MASTER_HASHLIB_RIPEMD160_ID = 9,
	MASTER_HASHLIB_RIPEMD256_ID = 10,
	MASTER_HASHLIB_RIPEMD320_ID = 11,
	MASTER_HASHLIB_MURMURHASH2A_ID = 12,
	MASTER_HASHLIB_MIN_ID = MASTER_HASHLIB_MD2_ID,
	MASTER_HASHLIB_MAX_ID = MASTER_HASHLIB_MURMURHASH2A_ID
} MASTER_Hashlib_Algorithms;

#define MASTER_HASHLIB_MD2_DIGEST_SIZE 128
#define MASTER_HASHLIB_MD4_DIGEST_SIZE 128
#define MASTER_HASHLIB_MD5_DIGEST_SIZE 128
#define MASTER_HASHLIB_SHA1_DIGEST_SIZE 160
#define MASTER_HASHLIB_SHA2_224_DIGEST_SIZE 224
#define MASTER_HASHLIB_SHA2_256_DIGEST_SIZE 256
#ifdef MASTER_UI8_TYPE
#	define MASTER_HASHLIB_SHA2_384_DIGEST_SIZE 384
#	define MASTER_HASHLIB_SHA2_512_DIGEST_SIZE 512
#endif /* #! 64 Bits !# */
#define MASTER_HASHLIB_RIPEMD128_DIGEST_SIZE 128
#define MASTER_HASHLIB_RIPEMD160_DIGEST_SIZE 160
#define MASTER_HASHLIB_RIPEMD256_DIGEST_SIZE 256
#define MASTER_HASHLIB_RIPEMD320_DIGEST_SIZE 320
#define MASTER_HASHLIB_MURMURHASH2A_DIGEST_SIZE 32
#define MASTER_HASHLIB_MIN_DIGEST_SIZE 32
#ifdef MASTER_UI8_TYPE
#	define MASTER_HASHLIB_MAX_DIGEST_SIZE 512
#else
#	define MASTER_HASHLIB_MAX_DIGEST_SIZE 320
#endif /* #! 64 Bits !# */

#ifdef MASTER_UI8_TYPE
#	define MASTER_zzz_HASHLIB_XMAC_DEFALGO( macrofunc ) \
	macrofunc( MD2, MD2, md2c ) \
	macrofunc( MD4, MD4, md4c ) \
	macrofunc( MD5, MD5, md5c ) \
	macrofunc( SHA1, SHA1, sha1c ) \
	macrofunc( SHA2_224, SHA2_224, sha2_224c ) \
	macrofunc( SHA2_256, SHA2_256, sha2_256c ) \
	macrofunc( SHA2_384, SHA2_384, sha2_384c ) \
	macrofunc( SHA2_512, SHA2_512, sha2_512c ) \
	macrofunc( RIPEMD128, RIPEMD128, ripemd128c ) \
	macrofunc( RIPEMD160, RIPEMD160, ripemd160c ) \
	macrofunc( RIPEMD256, RIPEMD256, ripemd256c ) \
	macrofunc( RIPEMD320, RIPEMD320, ripemd320c ) \
	macrofunc( MURMURHASH2A, MurmurHash2A, murmurhash2a )
#else
#	define MASTER_zzz_HASHLIB_XMAC_DEFALGO( macrofunc ) \
	macrofunc( MD2, MD2, md2c ) \
	macrofunc( MD4, MD4, md4c ) \
	macrofunc( MD5, MD5, md5c ) \
	macrofunc( SHA1, SHA1, sha1c ) \
	macrofunc( SHA2_224, SHA2_224, sha2_224c ) \
	macrofunc( SHA2_256, SHA2_256, sha2_256c ) \
	macrofunc( RIPEMD128, RIPEMD128, ripemd128c ) \
	macrofunc( RIPEMD160, RIPEMD160, ripemd160c ) \
	macrofunc( RIPEMD256, RIPEMD256, ripemd256c ) \
	macrofunc( RIPEMD320, RIPEMD320, ripemd320c ) \
	macrofunc( MURMURHASH2A, MurmurHash2A, murmurhash2a )
#endif /* #! 64 Bits !# */

#define MASTER_zzz_HASHLIB_CREATE_STUB( algorithm ) \
MASTER_DEFINE_FUNCTION0( \
	MASTER_NO_FLAGS, \
	MASTER_EMPTY_DESCRIPTION, \
	/* ! */ MASTER_Hashlib_ ## algorithm ## _Create /* ! */, \
	MASTER_Hashlib_ ## algorithm ## _Context \
) { \
	MASTER_Hashlib_ ## algorithm ## _Context context; \
	MASTER_Hashlib_ ## algorithm ## _Init(&context); \
	return context; \
}

#define MASTER_zzz_HASHLIB_CALC_STUB( algorithm ) \
MASTER_DEFINE_FUNCTION3( \
	MASTER_NO_FLAGS, \
	MASTER_EMPTY_DESCRIPTION, \
	/* ! */ MASTER_Hashlib_ ## algorithm ## _Calculate /* ! */, \
	void, \
	( const void * const MASTER_PREFER_RESTRICT, bytes ), \
	( const MASTER_maxint, length ), \
	( UI1 * const MASTER_PREFER_RESTRICT, output ) \
) { \
	MASTER_Hashlib_ ## algorithm ## _Context algorithm ## c; \
	MASTER_zzz_CHECK_NUL_RETURN( bytes, MASTER_NOTHING ); \
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING ); \
	algorithm ## c = MASTER_Hashlib_ ## algorithm ## _Create(); \
	MASTER_Hashlib_ ## algorithm ## _Update(&algorithm ## c, bytes, length); \
	MASTER_Hashlib_ ## algorithm ## _Finish(&algorithm ## c, output); \
}

#define MASTER_zzz_HASHLIB_MERKLED_UPD( mdc, bytes, length, process ) do { \
		const UI4 bufferLength = sizeof((mdc)->buffer); \
		const UI4 bufferMask = sizeof((mdc)->buffer) - 1; \
		UI1 toRead; \
		MASTER_zzz_CHECK_NUL_RETURN( mdc, MASTER_NOTHING ); \
		MASTER_zzz_CHECK_NUL_RETURN( bytes, MASTER_NOTHING ); \
		if ((mdc)->count[0] & bufferMask) { \
			toRead = bufferLength - ((mdc)->count[0] & bufferMask); \
			if (length < toRead) { \
				MASTER_MEMCPY((mdc)->buffer + ((mdc)->count[0] & bufferMask), (const UI1 *)bytes, length); \
				(mdc)->count[0] += (UI4)length; \
				if ((mdc)->count[0] < (UI4)length) \
					(mdc)->count[1] += 1; \
				return; \
			} \
			MASTER_MEMCPY((mdc)->buffer + ((mdc)->count[0] & bufferMask), (const UI1 *)bytes, toRead); \
			process(mdc, (mdc)->buffer); \
			(mdc)->count[0] += toRead; \
			if ((mdc)->count[0] < toRead) \
				(mdc)->count[1] += 1; \
			bytes = (const UI1 *)bytes + toRead; \
			length -= toRead; \
		} \
		while (length >= bufferLength) { \
			process(mdc, (const UI1 *)bytes); \
			(mdc)->count[0] += bufferLength; \
			if ((mdc)->count[0] < bufferLength) \
				(mdc)->count[1] += 1; \
			bytes = (const UI1 *)bytes + bufferLength; \
			length -= bufferLength; \
		} \
		if (length > 0) { \
			MASTER_MEMCPY((mdc)->buffer, (const UI1 *)bytes, length); \
			(mdc)->count[0] += (UI4)length; \
			if ((mdc)->count[0] < (UI4)length) \
				(mdc)->count[1] += 1; \
		} \
	} while (0)

#define MASTER_zzz_HASHLIB_MERKLED_CN1( context, offset ) \
	(context)->buffer[offset] = (UI1)((context)->count[0] << 3); \
	(context)->buffer[(offset) + 1] = (UI1)((context)->count[0] >> 5); \
	(context)->buffer[(offset) + 2] = (UI1)((context)->count[0] >> 13); \
	(context)->buffer[(offset) + 3] = (UI1)((context)->count[0] >> 21); \
	(context)->buffer[(offset) + 4] = (UI1)(((context)->count[0] >> 29) | ((context)->count[1] << 3)); \
	(context)->buffer[(offset) + 5] = (UI1)((context)->count[1] >> 5); \
	(context)->buffer[(offset) + 6] = (UI1)((context)->count[1] >> 13); \
	(context)->buffer[(offset) + 7] = (UI1)((context)->count[1] >> 21)

#define MASTER_zzz_HASHLIB_MERKLED_CN2( context, offset ) \
	(context)->buffer[(offset) + 7] = (UI1)((context)->count[0] << 3); \
	(context)->buffer[(offset) + 6] = (UI1)((context)->count[0] >> 5); \
	(context)->buffer[(offset) + 5] = (UI1)((context)->count[0] >> 13); \
	(context)->buffer[(offset) + 4] = (UI1)((context)->count[0] >> 21); \
	(context)->buffer[(offset) + 3] = (UI1)(((context)->count[0] >> 29) | ((context)->count[1] << 3)); \
	(context)->buffer[(offset) + 2] = (UI1)((context)->count[1] >> 5); \
	(context)->buffer[(offset) + 1] = (UI1)((context)->count[1] >> 13); \
	(context)->buffer[offset] = (UI1)((context)->count[1] >> 21)

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

#if MASTER_HASHLIB_MD2_IMPLEMENT == 1

MASTER_PREFER_STATIC const UI1 MASTER_Hashlib_MD2_Table1[256] = {
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

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD2_Init /* ! */,
	void,
	( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT, md2c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	for (; index < 16; index += 1) {
		md2c->state[index] = 0;
		md2c->checksum[index] = 0;
		md2c->buffer[index] = 0;
	}
	md2c->counter = 0;
}

MASTER_zzz_HASHLIB_CREATE_STUB( MD2 )

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD2_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT, md2c ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
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

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD2_Update /* ! */,
	void,
	( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT, md2c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	UI1 toRead;
	MASTER_zzz_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	if (md2c->counter > 0) {
		toRead = 16 - md2c->counter;
		if (length < toRead) {
			MASTER_MEMCPY(md2c->buffer + md2c->counter, (const UI1 *)bytes, length);
			md2c->counter += (UI1)length;
			return;
		}
		MASTER_MEMCPY(md2c->buffer + md2c->counter, (const UI1 *)bytes, toRead);
		MASTER_Hashlib_MD2_Process(md2c, md2c->buffer);
		md2c->counter = 0;
		bytes = (const UI1 *)bytes + toRead;
		length -= toRead;
	}
	while (length >= 16) {
		MASTER_Hashlib_MD2_Process(md2c, (const UI1 *)bytes);
		bytes = (const UI1 *)bytes + 16;
		length -= 16;
	}
	if (length > 0) {
		MASTER_MEMCPY(md2c->buffer, (const UI1 *)bytes, length);
		md2c->counter = (UI1)length;
	}
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD2_Finish /* ! */,
	void,
	( MASTER_Hashlib_MD2_Context * const MASTER_PREFER_RESTRICT, md2c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 estlen;
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( md2c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
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

MASTER_zzz_HASHLIB_CALC_STUB( MD2 )

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

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD4_Init /* ! */,
	void,
	( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT, md4c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( md4c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		md4c->buffer[index] = 0;
	md4c->count[0] = md4c->count[1] = 0;
	MASTER_SET_ARRAY4(md4c->state, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476);
}

MASTER_zzz_HASHLIB_CREATE_STUB( MD4 )

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD4_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT, md4c ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
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

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD4_Update /* ! */,
	void,
	( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT, md4c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(md4c, bytes, length, MASTER_Hashlib_MD4_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD4_Finish /* ! */,
	void,
	( MASTER_Hashlib_MD4_Context * const MASTER_PREFER_RESTRICT, md4c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( md4c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
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
	MASTER_zzz_HASHLIB_MERKLED_CN1(md4c, 56);
	MASTER_Hashlib_MD4_Process(md4c, md4c->buffer);
	for (index = 0; index < 4; index += 1)
		MASTER_PACK_LE4(output + (index << 2), md4c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( MD4 )

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

#if MASTER_HASHLIB_MD5_IMPLEMENT == 1

MASTER_PREFER_STATIC const UI4 MASTER_Hashlib_MD5_Table1[64] = {
	0xD76AA478, 0xE8C7B756, 0x242070DB, 0xC1BDCEEE, 0xF57C0FAF, 0x4787C62A, 0xA8304613, 0xFD469501,
	0x698098D8, 0x8B44F7AF, 0xFFFF5BB1, 0x895CD7BE, 0x6B901122, 0xFD987193, 0xA679438E, 0x49B40821,
	0xF61E2562, 0xC040B340, 0x265E5A51, 0xE9B6C7AA, 0xD62F105D, 0x2441453, 0xD8A1E681, 0xE7D3FBC8,
	0x21E1CDE6, 0xC33707D6, 0xF4D50D87, 0x455A14ED, 0xA9E3E905, 0xFCEFA3F8, 0x676F02D9, 0x8D2A4C8A,
	0xFFFA3942, 0x8771F681, 0x6D9D6122, 0xFDE5380C, 0xA4BEEA44, 0x4BDECFA9, 0xF6BB4B60, 0xBEBFBC70,
	0x289B7EC6, 0xEAA127FA, 0xD4EF3085, 0x4881D05, 0xD9D4D039, 0xE6DB99E5, 0x1FA27CF8, 0xC4AC5665,
	0xF4292244, 0x432AFF97, 0xAB9423A7, 0xFC93A039, 0x655B59C3, 0x8F0CCC92, 0xFFEFF47D, 0x85845DD1,
	0x6FA87E4F, 0xFE2CE6E0, 0xA3014314, 0x4E0811A1, 0xF7537E82, 0xBD3AF235, 0x2AD7D2BB, 0xEB86D391
};

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

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD5_Init /* ! */,
	void,
	( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT, md5c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( md5c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		md5c->buffer[index] = 0;
	md5c->count[0] = md5c->count[1] = 0;
	MASTER_SET_ARRAY4(md5c->state, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476);
}

MASTER_zzz_HASHLIB_CREATE_STUB( MD5 )

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD5_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT, md5c ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
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

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD5_Update /* ! */,
	void,
	( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT, md5c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(md5c, bytes, length, MASTER_Hashlib_MD5_Process);
	/*
	while (length > 0) {
		md5c->buffer[md5c->count[0] & 0x3F] = *(const UI1 *)bytes;
		md5c->count[0] += 1;
		if (md5c->count[0] == 0)
			md5c->count[1] += 1;
		if ((md5c->count[0] & 0x3F) == 0)
			MASTER_Hashlib_MD5_Process(md5c);
		bytes = (const UI1 *)bytes + 1;
		length -= 1;
	}
	*/
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MD5_Finish /* ! */,
	void,
	( MASTER_Hashlib_MD5_Context * const MASTER_PREFER_RESTRICT, md5c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( md5c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
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
	MASTER_zzz_HASHLIB_MERKLED_CN1(md5c, 56);
	MASTER_Hashlib_MD5_Process(md5c, md5c->buffer);
	for (index = 0; index < 4; index += 1)
		MASTER_PACK_LE4(output + (index << 2), md5c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( MD5 )

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

#if MASTER_HASHLIB_SHA1_IMPLEMENT == 1

MASTER_PREFER_STATIC const UI4 MASTER_Hashlib_SHA1_Table1[4] = {
	0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6
};

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA1_Init /* ! */,
	void,
	( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT, sha1c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( sha1c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		sha1c->buffer[index] = 0;
	sha1c->count[0] = sha1c->count[1] = 0;
	MASTER_SET_ARRAY5(sha1c->state, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0);
}

MASTER_zzz_HASHLIB_CREATE_STUB( SHA1 )

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA1_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT, sha1c ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
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

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA1_Update /* ! */,
	void,
	( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT, sha1c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(sha1c, bytes, length, MASTER_Hashlib_SHA1_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA1_Finish /* ! */,
	void,
	( MASTER_Hashlib_SHA1_Context * const MASTER_PREFER_RESTRICT, sha1c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( sha1c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
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
	MASTER_zzz_HASHLIB_MERKLED_CN2(sha1c, 56);
	MASTER_Hashlib_SHA1_Process(sha1c, sha1c->buffer);
	for (index = 0; index < 5; index += 1)
		MASTER_PACK_BE4(output + (index << 2), sha1c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( SHA1 )

#endif /* #! SHA1 !# */

/* #! SHA-2 Help Functions !# */

#if MASTER_HASHLIB_SHA2_224_IMPLEMENT == 1 || MASTER_HASHLIB_SHA2_256_IMPLEMENT == 1

#define MASTER_HASHLIB_SHA2_X32_FUNC0( value ) \
	(MASTER_RLR4(value, 2) ^ MASTER_RLR4(value, 13) ^ MASTER_RLR4(value, 22))

#define MASTER_HASHLIB_SHA2_X32_FUNC1( value ) \
	(MASTER_RLR4(value, 6) ^ MASTER_RLR4(value, 11) ^ MASTER_RLR4(value, 25))

#define MASTER_HASHLIB_SHA2_X32_FUNC2( value ) \
	(MASTER_RLR4(value, 7) ^ MASTER_RLR4(value, 18) ^ ((value) >> 3))

#define MASTER_HASHLIB_SHA2_X32_FUNC3( value ) \
	(MASTER_RLR4(value, 17) ^ MASTER_RLR4(value, 19) ^ ((value) >> 10))

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[8];
} * MASTER_PREFER_RESTRICT MASTER_zzz_HASHLIB_SHA2_224_256_Process_Context;

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_224_256_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( void * const MASTER_PREFER_RESTRICT, sha2cptr ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
	MASTER_zzz_HASHLIB_SHA2_224_256_Process_Context sha2c = (MASTER_zzz_HASHLIB_SHA2_224_256_Process_Context)sha2cptr;
	MASTER_PREFER_STATIC const UI4 table[64] = {
		0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
		0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
		0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
		0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
		0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
		0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
		0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
		0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
		0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
		0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
		0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
		0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
		0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
		0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
		0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
		0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
	};
	UI4 chunk[64];
	UI4 wordA = sha2c->state[0];
	UI4 wordB = sha2c->state[1];
	UI4 wordC = sha2c->state[2];
	UI4 wordD = sha2c->state[3];
	UI4 wordE = sha2c->state[4];
	UI4 wordF = sha2c->state[5];
	UI4 wordG = sha2c->state[6];
	UI4 wordH = sha2c->state[7];
	UI4 timevar1;
	UI4 timevar2;
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
	for (; index < 64; index += 1)
		chunk[index] = MASTER_HASHLIB_SHA2_X32_FUNC3(chunk[index - 2]) + chunk[index - 7] + MASTER_HASHLIB_SHA2_X32_FUNC2(chunk[index - 15]) + chunk[index - 16];
	for (index = 0; index < 64; index += 1) {
		timevar1 = wordH + MASTER_HASHLIB_SHA2_X32_FUNC1(wordE) + MASTER_OPERATION_CHOICE(wordE, wordF, wordG) + table[index] + chunk[index];
		timevar2 = MASTER_HASHLIB_SHA2_X32_FUNC0(wordA) + MASTER_OPERATION_MAJORITAR(wordA, wordB, wordC);
		wordH = wordG;
		wordG = wordF;
		wordF = wordE;
		wordE = wordD + timevar1;
		wordD = wordC;
		wordC = wordB;
		wordB = wordA;
		wordA = timevar1 + timevar2;
	}
	sha2c->state[0] += wordA;
	sha2c->state[1] += wordB;
	sha2c->state[2] += wordC;
	sha2c->state[3] += wordD;
	sha2c->state[4] += wordE;
	sha2c->state[5] += wordF;
	sha2c->state[6] += wordG;
	sha2c->state[7] += wordH;
}

#endif /* #! For SHA-2-224 & SHA-2-256 !# */

#if MASTER_HASHLIB_SHA2_384_IMPLEMENT == 1 || MASTER_HASHLIB_SHA2_512_IMPLEMENT == 1

#define MASTER_HASHLIB_SHA2_X64_FUNC0( value ) \
	(MASTER_RLR8(value, 28) ^ MASTER_RLR8(value, 34) ^ MASTER_RLR8(value, 39))

#define MASTER_HASHLIB_SHA2_X64_FUNC1( value ) \
	(MASTER_RLR8(value, 14) ^ MASTER_RLR8(value, 18) ^ MASTER_RLR8(value, 41))

#define MASTER_HASHLIB_SHA2_X64_FUNC2( value ) \
	(MASTER_RLR8(value, 1) ^ MASTER_RLR8(value, 8) ^ ((value) >> 7))

#define MASTER_HASHLIB_SHA2_X64_FUNC3( value ) \
	(MASTER_RLR8(value, 19) ^ MASTER_RLR8(value, 61) ^ ((value) >> 6))

typedef struct {
	UI1 buffer[128];
	UI4 count[2];
	UI8 state[8];
} * MASTER_PREFER_RESTRICT MASTER_zzz_HASHLIB_SHA2_384_512_Process_Context;

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_384_512_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( void * const MASTER_PREFER_RESTRICT, sha2cptr ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
	MASTER_zzz_HASHLIB_SHA2_384_512_Process_Context sha2c = (MASTER_zzz_HASHLIB_SHA2_384_512_Process_Context)sha2cptr;
	MASTER_PREFER_STATIC const UI8 table[80] = {
		0x428A2F98D728AE22, 0x7137449123EF65CD, 0xB5C0FBCFEC4D3B2F, 0xE9B5DBA58189DBBC,
		0x3956C25BF348B538, 0x59F111F1B605D019, 0x923F82A4AF194F9B, 0xAB1C5ED5DA6D8118,
		0xD807AA98A3030242, 0x12835B0145706FBE, 0x243185BE4EE4B28C, 0x550C7DC3D5FFB4E2,
		0x72BE5D74F27B896F, 0x80DEB1FE3B1696B1, 0x9BDC06A725C71235, 0xC19BF174CF692694,
		0xE49B69C19EF14AD2, 0xEFBE4786384F25E3, 0x0FC19DC68B8CD5B5, 0x240CA1CC77AC9C65,
		0x2DE92C6F592B0275, 0x4A7484AA6EA6E483, 0x5CB0A9DCBD41FBD4, 0x76F988DA831153B5,
		0x983E5152EE66DFAB, 0xA831C66D2DB43210, 0xB00327C898FB213F, 0xBF597FC7BEEF0EE4,
		0xC6E00BF33DA88FC2, 0xD5A79147930AA725, 0x06CA6351E003826F, 0x142929670A0E6E70,
		0x27B70A8546D22FFC, 0x2E1B21385C26C926, 0x4D2C6DFC5AC42AED, 0x53380D139D95B3DF,
		0x650A73548BAF63DE, 0x766A0ABB3C77B2A8, 0x81C2C92E47EDAEE6, 0x92722C851482353B,
		0xA2BFE8A14CF10364, 0xA81A664BBC423001, 0xC24B8B70D0F89791, 0xC76C51A30654BE30,
		0xD192E819D6EF5218, 0xD69906245565A910, 0xF40E35855771202A, 0x106AA07032BBD1B8,
		0x19A4C116B8D2D0C8, 0x1E376C085141AB53, 0x2748774CDF8EEB99, 0x34B0BCB5E19B48A8,
		0x391C0CB3C5C95A63, 0x4ED8AA4AE3418ACB, 0x5B9CCA4F7763E373, 0x682E6FF3D6B2B8A3,
		0x748F82EE5DEFB2FC, 0x78A5636F43172F60, 0x84C87814A1F0AB72, 0x8CC702081A6439EC,
		0x90BEFFFA23631E28, 0xA4506CEBDE82BDE9, 0xBEF9A3F7B2C67915, 0xC67178F2E372532B,
		0xCA273ECEEA26619C, 0xD186B8C721C0C207, 0xEADA7DD6CDE0EB1E, 0xF57D4F7FEE6ED178,
		0x06F067AA72176FBA, 0x0A637DC5A2C898A6, 0x113F9804BEF90DAE, 0x1B710B35131C471B,
		0x28DB77F523047D84, 0x32CAAB7B40C72493, 0x3C9EBE0A15C9BEBC, 0x431D67C49C100D4C,
		0x4CC5D4BECB3E42B6, 0x597F299CFC657E2A, 0x5FCB6FAB3AD6FAEC, 0x6C44198C4A475817
	};
	UI8 chunk[80];
	UI8 wordA = sha2c->state[0];
	UI8 wordB = sha2c->state[1];
	UI8 wordC = sha2c->state[2];
	UI8 wordD = sha2c->state[3];
	UI8 wordE = sha2c->state[4];
	UI8 wordF = sha2c->state[5];
	UI8 wordG = sha2c->state[6];
	UI8 wordH = sha2c->state[7];
	UI8 timevar1;
	UI8 timevar2;
#if MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
	UI1 index = 16;
	MASTER_MEMCPY(chunk, inData, 128);
#elif MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
	UI1 index = 0;
	MASTER_MEMCPY(chunk, inData, 128);
	for (; index < 16; index += 1)
		chunk[index] = MASTER_BSWAP8(chunk[index]);
#else
	UI1 index = 0;
	for (; index < 16; index += 1)
		chunk[index] = ((UI8)inData[index << 3] << 56) |
						((UI8)inData[(index << 3) | 1] << 48) |
						((UI8)inData[(index << 3) | 2] << 40) |
						((UI8)inData[(index << 3) | 3] << 32) |
						((UI8)inData[(index << 3) | 4] << 24) |
						((UI8)inData[(index << 3) | 5] << 16) |
						((UI8)inData[(index << 3) | 6] << 8) |
						((UI8)inData[(index << 3) | 7]);
#endif /* #! Endian !# */
	for (; index < 80; index += 1)
		chunk[index] = MASTER_HASHLIB_SHA2_X64_FUNC3(chunk[index - 2]) + chunk[index - 7] + MASTER_HASHLIB_SHA2_X64_FUNC2(chunk[index - 15]) + chunk[index - 16];
	for (index = 0; index < 80; index += 1) {
		timevar1 = wordH + MASTER_HASHLIB_SHA2_X64_FUNC1(wordE) + MASTER_OPERATION_CHOICE(wordE, wordF, wordG) + table[index] + chunk[index];
		timevar2 = MASTER_HASHLIB_SHA2_X64_FUNC0(wordA) + MASTER_OPERATION_MAJORITAR(wordA, wordB, wordC);
		wordH = wordG;
		wordG = wordF;
		wordF = wordE;
		wordE = wordD + timevar1;
		wordD = wordC;
		wordC = wordB;
		wordB = wordA;
		wordA = timevar1 + timevar2;
	}
	sha2c->state[0] += wordA;
	sha2c->state[1] += wordB;
	sha2c->state[2] += wordC;
	sha2c->state[3] += wordD;
	sha2c->state[4] += wordE;
	sha2c->state[5] += wordF;
	sha2c->state[6] += wordG;
	sha2c->state[7] += wordH;
}

#endif /* #! For SHA-2-384 & SHA-2-512 !# */

/* #! SHA-2-224 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[8];
} MASTER_Hashlib_SHA2_224_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_SHA2_224_Context, MASTER_Hashlib_SHA2_224_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_224_Init, ( MASTER_Hashlib_SHA2_224_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_SHA2_224_Flush MASTER_Hashlib_SHA2_224_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_224_Update, ( MASTER_Hashlib_SHA2_224_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_224_Finish, ( MASTER_Hashlib_SHA2_224_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_224_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_HASHLIB_SHA2_224_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_224_Init /* ! */,
	void,
	( MASTER_Hashlib_SHA2_224_Context * const MASTER_PREFER_RESTRICT, sha2_224c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( sha2_224c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		sha2_224c->buffer[index] = 0;
	sha2_224c->count[0] = sha2_224c->count[1] = 0;
	MASTER_SET_ARRAY8(sha2_224c->state, 0xC1059ED8, 0x367CD507, 0x3070DD17, 0xF70E5939, 0xFFC00B31, 0x68581511, 0x64F98FA7, 0xBEFA4FA4);
}

MASTER_zzz_HASHLIB_CREATE_STUB( SHA2_224 )

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_224_Update /* ! */,
	void,
	( MASTER_Hashlib_SHA2_224_Context * const MASTER_PREFER_RESTRICT, sha2_224c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(sha2_224c, bytes, length, MASTER_Hashlib_SHA2_224_256_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_224_Finish /* ! */,
	void,
	( MASTER_Hashlib_SHA2_224_Context * const MASTER_PREFER_RESTRICT, sha2_224c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( sha2_224c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = sha2_224c->count[0] & 0x3F;
	sha2_224c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			sha2_224c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			sha2_224c->buffer[index] = 0;
		MASTER_Hashlib_SHA2_224_256_Process(sha2_224c, sha2_224c->buffer);
		for (index = 0; index < 56; index += 1)
			sha2_224c->buffer[index] = 0;
	}
	MASTER_zzz_HASHLIB_MERKLED_CN2(sha2_224c, 56);
	MASTER_Hashlib_SHA2_224_256_Process(sha2_224c, sha2_224c->buffer);
	for (index = 0; index < 7; index += 1)
		MASTER_PACK_BE4(output + (index << 2), sha2_224c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( SHA2_224 )

#endif /* #! SHA-2-224 !# */

/* #! SHA-2-256 !# */

typedef struct {
	UI1 buffer[64];
	UI4 count[2];
	UI4 state[8];
} MASTER_Hashlib_SHA2_256_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_SHA2_256_Context, MASTER_Hashlib_SHA2_256_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_256_Init, ( MASTER_Hashlib_SHA2_256_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_SHA2_256_Flush MASTER_Hashlib_SHA2_256_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_256_Update, ( MASTER_Hashlib_SHA2_256_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_256_Finish, ( MASTER_Hashlib_SHA2_256_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_256_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_HASHLIB_SHA2_256_IMPLEMENT == 1

#define MASTER_HASHLIB_SHA2_256_FUNC0( value ) \
	MASTER_RLR4(value, 2) ^ MASTER_RLR4(value, 13) ^ MASTER_RLR4(value, 22)

#define MASTER_HASHLIB_SHA2_256_FUNC1( value ) \
	MASTER_RLR4(value, 6) ^ MASTER_RLR4(value, 11) ^ MASTER_RLR4(value, 25)

#define MASTER_HASHLIB_SHA2_256_FUNC2( value ) \
	MASTER_RLR4(value, 7) ^ MASTER_RLR4(value, 18) ^ ((value) >> 3)

#define MASTER_HASHLIB_SHA2_256_FUNC3( value ) \
	MASTER_RLR4(value, 17) ^ MASTER_RLR4(value, 19) ^ ((value) >> 10)

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_256_Init /* ! */,
	void,
	( MASTER_Hashlib_SHA2_256_Context * const MASTER_PREFER_RESTRICT, sha2_256c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( sha2_256c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		sha2_256c->buffer[index] = 0;
	sha2_256c->count[0] = sha2_256c->count[1] = 0;
	MASTER_SET_ARRAY8(sha2_256c->state, 0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A, 0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19);
}

MASTER_zzz_HASHLIB_CREATE_STUB( SHA2_256 )

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_256_Update /* ! */,
	void,
	( MASTER_Hashlib_SHA2_256_Context * const MASTER_PREFER_RESTRICT, sha2_256c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(sha2_256c, bytes, length, MASTER_Hashlib_SHA2_224_256_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_256_Finish /* ! */,
	void,
	( MASTER_Hashlib_SHA2_256_Context * const MASTER_PREFER_RESTRICT, sha2_256c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( sha2_256c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = sha2_256c->count[0] & 0x3F;
	sha2_256c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 56; index += 1)
			sha2_256c->buffer[index] = 0;
	} else {
		for (index += 1; index < 64; index += 1)
			sha2_256c->buffer[index] = 0;
		MASTER_Hashlib_SHA2_224_256_Process(sha2_256c, sha2_256c->buffer);
		for (index = 0; index < 56; index += 1)
			sha2_256c->buffer[index] = 0;
	}
	MASTER_zzz_HASHLIB_MERKLED_CN2(sha2_256c, 56);
	MASTER_Hashlib_SHA2_224_256_Process(sha2_256c, sha2_256c->buffer);
	for (index = 0; index < 8; index += 1)
		MASTER_PACK_BE4(output + (index << 2), sha2_256c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( SHA2_256 )

#endif /* #! SHA-2-256 !# */

/* #! SHA-2-384 !# */

typedef struct {
	UI1 buffer[128];
	UI4 count[2];
	UI8 state[8];
} MASTER_Hashlib_SHA2_384_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_SHA2_384_Context, MASTER_Hashlib_SHA2_384_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_384_Init, ( MASTER_Hashlib_SHA2_384_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_SHA2_384_Flush MASTER_Hashlib_SHA2_384_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_384_Update, ( MASTER_Hashlib_SHA2_384_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_384_Finish, ( MASTER_Hashlib_SHA2_384_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_384_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_HASHLIB_SHA2_384_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_384_Init /* ! */,
	void,
	( MASTER_Hashlib_SHA2_384_Context * const MASTER_PREFER_RESTRICT, sha2_384c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( sha2_384c, MASTER_NOTHING );
	for (; index < 128; index += 1)
		sha2_384c->buffer[index] = 0;
	sha2_384c->count[0] = sha2_384c->count[1] = 0;
	MASTER_SET_ARRAY8(sha2_384c->state, 0xCBBB9D5DC1059ED8, 0x629A292A367CD507, 0x9159015A3070DD17, 0x152FECD8F70E5939, 0x67332667FFC00B31, 0x8EB44A8768581511, 0xDB0C2E0D64F98FA7, 0x47B5481DBEFA4FA4);
}

MASTER_zzz_HASHLIB_CREATE_STUB( SHA2_384 )

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_384_Update /* ! */,
	void,
	( MASTER_Hashlib_SHA2_384_Context * const MASTER_PREFER_RESTRICT, sha2_384c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(sha2_384c, bytes, length, MASTER_Hashlib_SHA2_384_512_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_384_Finish /* ! */,
	void,
	( MASTER_Hashlib_SHA2_384_Context * const MASTER_PREFER_RESTRICT, sha2_384c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( sha2_384c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = sha2_384c->count[0] & 0x3F;
	sha2_384c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 120; index += 1)
			sha2_384c->buffer[index] = 0;
	} else {
		for (index += 1; index < 128; index += 1)
			sha2_384c->buffer[index] = 0;
		MASTER_Hashlib_SHA2_384_512_Process(sha2_384c, sha2_384c->buffer);
		for (index = 0; index < 120; index += 1)
			sha2_384c->buffer[index] = 0;
	}
	MASTER_zzz_HASHLIB_MERKLED_CN2(sha2_384c, 120);
	MASTER_Hashlib_SHA2_384_512_Process(sha2_384c, sha2_384c->buffer);
	for (index = 0; index < 6; index += 1)
		MASTER_PACK_BE8(output + (index << 3), sha2_384c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( SHA2_384 )

#endif /* #! SHA-2-384 !# */

/* #! SHA-2-512 !# */

typedef struct {
	UI1 buffer[128];
	UI4 count[2];
	UI8 state[8];
} MASTER_Hashlib_SHA2_512_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Hashlib_SHA2_512_Context, MASTER_Hashlib_SHA2_512_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_512_Init, ( MASTER_Hashlib_SHA2_512_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Hashlib_SHA2_512_Flush MASTER_Hashlib_SHA2_512_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_512_Update, ( MASTER_Hashlib_SHA2_512_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_512_Finish, ( MASTER_Hashlib_SHA2_512_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Hashlib_SHA2_512_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_HASHLIB_SHA2_512_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_512_Init /* ! */,
	void,
	( MASTER_Hashlib_SHA2_512_Context * const MASTER_PREFER_RESTRICT, sha2_512c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( sha2_512c, MASTER_NOTHING );
	for (; index < 128; index += 1)
		sha2_512c->buffer[index] = 0;
	sha2_512c->count[0] = sha2_512c->count[1] = 0;
	MASTER_SET_ARRAY8(sha2_512c->state, 0x6A09E667F3BCC908, 0xBB67AE8584CAA73B, 0x3C6EF372FE94F82B, 0xA54FF53A5F1D36F1, 0x510E527FADE682D1, 0x9B05688C2B3E6C1F, 0x1F83D9ABFB41BD6B, 0x5BE0CD19137E2179);
}

MASTER_zzz_HASHLIB_CREATE_STUB( SHA2_512 )

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_512_Update /* ! */,
	void,
	( MASTER_Hashlib_SHA2_512_Context * const MASTER_PREFER_RESTRICT, sha2_512c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(sha2_512c, bytes, length, MASTER_Hashlib_SHA2_384_512_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_SHA2_512_Finish /* ! */,
	void,
	( MASTER_Hashlib_SHA2_512_Context * const MASTER_PREFER_RESTRICT, sha2_512c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( sha2_512c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
	index = sha2_512c->count[0] & 0x3F;
	sha2_512c->buffer[index] = 0x80;
	if (index < 56) {
		for (index += 1; index < 120; index += 1)
			sha2_512c->buffer[index] = 0;
	} else {
		for (index += 1; index < 128; index += 1)
			sha2_512c->buffer[index] = 0;
		MASTER_Hashlib_SHA2_384_512_Process(sha2_512c, sha2_512c->buffer);
		for (index = 0; index < 120; index += 1)
			sha2_512c->buffer[index] = 0;
	}
	MASTER_zzz_HASHLIB_MERKLED_CN2(sha2_512c, 120);
	MASTER_Hashlib_SHA2_384_512_Process(sha2_512c, sha2_512c->buffer);
	for (index = 0; index < 8; index += 1)
		MASTER_PACK_BE8(output + (index << 3), sha2_512c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( SHA2_512 )

#endif /* #! SHA-2-512 !# */

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

#if MASTER_HASHLIB_RIPEMD128_IMPLEMENT == 1

MASTER_PREFER_STATIC const UI4 MASTER_Hashlib_RIPEMD128_Table1[8] = {
	0x00000000, 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC,
	0x50A28BE6, 0x5C4DD124, 0x6D703EF3, 0x00000000
};

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

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD128_Init /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT, ripemd128c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( ripemd128c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		ripemd128c->buffer[index] = 0;
	ripemd128c->count[0] = ripemd128c->count[1] = 0;
	MASTER_SET_ARRAY4(ripemd128c->state, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476);
}

MASTER_zzz_HASHLIB_CREATE_STUB( RIPEMD128 )

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD128_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT, ripemd128c ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
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

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD128_Update /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT, ripemd128c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(ripemd128c, bytes, length, MASTER_Hashlib_RIPEMD128_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD128_Finish /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD128_Context * const MASTER_PREFER_RESTRICT, ripemd128c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( ripemd128c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
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
	MASTER_zzz_HASHLIB_MERKLED_CN1(ripemd128c, 56);
	MASTER_Hashlib_RIPEMD128_Process(ripemd128c, ripemd128c->buffer);
	for (index = 0; index < 4; index += 1)
		MASTER_PACK_LE4(output + (index << 2), ripemd128c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( RIPEMD128 )

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

#if MASTER_HASHLIB_RIPEMD160_IMPLEMENT == 1

MASTER_PREFER_STATIC const UI4 MASTER_Hashlib_RIPEMD160_Table1[10] = {
	0x00000000, 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xA953FD4E,
	0x50A28BE6, 0x5C4DD124, 0x6D703EF3, 0x7A6D76E9, 0x00000000
};

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

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD160_Init /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT, ripemd160c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( ripemd160c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		ripemd160c->buffer[index] = 0;
	ripemd160c->count[0] = ripemd160c->count[1] = 0;
	MASTER_SET_ARRAY5(ripemd160c->state, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0);
}

MASTER_zzz_HASHLIB_CREATE_STUB( RIPEMD160 )

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD160_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT, ripemd160c ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
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

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD160_Update /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT, ripemd160c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(ripemd160c, bytes, length, MASTER_Hashlib_RIPEMD160_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD160_Finish /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD160_Context * const MASTER_PREFER_RESTRICT, ripemd160c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( ripemd160c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
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
	MASTER_zzz_HASHLIB_MERKLED_CN1(ripemd160c, 56);
	MASTER_Hashlib_RIPEMD160_Process(ripemd160c, ripemd160c->buffer);
	for (index = 0; index < 5; index += 1)
		MASTER_PACK_LE4(output + (index << 2), ripemd160c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( RIPEMD160 )

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

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD256_Init /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT, ripemd256c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( ripemd256c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		ripemd256c->buffer[index] = 0;
	ripemd256c->count[0] = ripemd256c->count[1] = 0;
	MASTER_SET_ARRAY8(ripemd256c->state, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0x76543210, 0xFEDCBA98, 0x89ABCDEF, 0x01234567);
}

MASTER_zzz_HASHLIB_CREATE_STUB( RIPEMD256 )

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD256_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT, ripemd256c ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
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

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD256_Update /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT, ripemd256c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(ripemd256c, bytes, length, MASTER_Hashlib_RIPEMD256_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD256_Finish /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD256_Context * const MASTER_PREFER_RESTRICT, ripemd256c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( ripemd256c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
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
	MASTER_zzz_HASHLIB_MERKLED_CN1(ripemd256c, 56);
	MASTER_Hashlib_RIPEMD256_Process(ripemd256c, ripemd256c->buffer);
	for (index = 0; index < 8; index += 1)
		MASTER_PACK_LE4(output + (index << 2), ripemd256c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( RIPEMD256 )

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

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD320_Init /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT, ripemd320c )
) {
	UI1 index = 0;
	MASTER_zzz_CHECK_NUL_RETURN( ripemd320c, MASTER_NOTHING );
	for (; index < 64; index += 1)
		ripemd320c->buffer[index] = 0;
	ripemd320c->count[0] = ripemd320c->count[1] = 0;
	MASTER_SET_ARRAY10(ripemd320c->state, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0, 0x76543210, 0xFEDCBA98, 0x89ABCDEF, 0x01234567, 0x3C2D1E0F);
}

MASTER_zzz_HASHLIB_CREATE_STUB( RIPEMD320 )

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD320_Process /* ! */,
		MASTER_PREFER_STATIC
	void,
	( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT, ripemd320c ),
	( const UI1 * const MASTER_PREFER_RESTRICT, inData )
) {
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

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD320_Update /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT, ripemd320c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	MASTER_zzz_HASHLIB_MERKLED_UPD(ripemd320c, bytes, length, MASTER_Hashlib_RIPEMD320_Process);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_RIPEMD320_Finish /* ! */,
	void,
	( MASTER_Hashlib_RIPEMD320_Context * const MASTER_PREFER_RESTRICT, ripemd320c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index;
	MASTER_zzz_CHECK_NUL_RETURN( ripemd320c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( output, MASTER_NOTHING );
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
	MASTER_zzz_HASHLIB_MERKLED_CN1(ripemd320c, 56);
	MASTER_Hashlib_RIPEMD320_Process(ripemd320c, ripemd320c->buffer);
	for (index = 0; index < 10; index += 1)
		MASTER_PACK_LE4(output + (index << 2), ripemd320c->state[index]);
}

MASTER_zzz_HASHLIB_CALC_STUB( RIPEMD320 )

#endif /* #! RIPEMD320 !# */

/* #! MurmurHash2A !# */

typedef struct {
	UI4 hashValue;
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

#define MASTER_ALGOLIB_MURMURHASH2A_MIX( hashValue, helder ) do { \
		(helder) *= 0x5BD1E995; \
		(helder) ^= (helder) >> 24; \
		(helder) *= 0x5BD1E995; \
		(hashValue) *= 0x5BD1E995; \
		(hashValue) ^= (UI4)(helder); \
	} while (0)

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MurmurHash2A_Init /* ! */,
	void,
	( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT, mmh2ac )
) {
	const UI4 seedValue = 0;
	if (mmh2ac == nul) return;
	MASTER_MEMSET(mmh2ac->buffer, 0, 4);
	mmh2ac->length = 0;
	mmh2ac->bufferPtr = 0;
	mmh2ac->hashValue = seedValue;
}

MASTER_zzz_HASHLIB_CREATE_STUB( MurmurHash2A )

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MurmurHash2A_Update /* ! */,
	void,
	( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT, mmh2ac ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	const UI1 * ui1_data = (const UI1 *)bytes;
	MASTER_maxint estimated = length;
	UI4 helder;
	UI1 toRead;
	if (mmh2ac == nul || bytes == nul) return;
	mmh2ac->length += (SI4)length;
	if (mmh2ac->bufferPtr > 0) {
		toRead = 4 - mmh2ac->bufferPtr;
		if (length < toRead) {
			MASTER_MEMCPY(mmh2ac->buffer + mmh2ac->bufferPtr, bytes, length);
			mmh2ac->bufferPtr += (UI1)length;
			return;
		}
		MASTER_MEMCPY(mmh2ac->buffer + mmh2ac->bufferPtr, ui1_data, toRead);
		helder = MASTER_UNPACK_LE4(ui1_data);
		MASTER_ALGOLIB_MURMURHASH2A_MIX(mmh2ac->hashValue, helder);
		mmh2ac->bufferPtr = 0;
		ui1_data += toRead;
		estimated -= toRead;
	}
	while (estimated >= 4) {
		helder = MASTER_UNPACK_LE4(ui1_data);
		MASTER_ALGOLIB_MURMURHASH2A_MIX(mmh2ac->hashValue, helder);
		ui1_data += 4;
		estimated -= 4;
	}
	if (estimated > 0) {
		MASTER_MEMCPY(mmh2ac->buffer, ui1_data, estimated);
		mmh2ac->bufferPtr = (UI1)estimated;
	}
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_MurmurHash2A_Finish /* ! */,
	void,
	( MASTER_Hashlib_MurmurHash2A_Context * const MASTER_PREFER_RESTRICT, mmh2ac ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI4 helder = 0;
	if (mmh2ac == nul || output == nul) return;
	if (mmh2ac->bufferPtr >= 3)
		helder |= mmh2ac->buffer[2] << 16;
	if (mmh2ac->bufferPtr >= 2)
		helder |= mmh2ac->buffer[1] << 8;
	if (mmh2ac->bufferPtr >= 1)
		helder |= mmh2ac->buffer[0];
	MASTER_ALGOLIB_MURMURHASH2A_MIX(mmh2ac->hashValue, helder);
	MASTER_ALGOLIB_MURMURHASH2A_MIX(mmh2ac->hashValue, mmh2ac->length);
	mmh2ac->hashValue ^= mmh2ac->hashValue >> 13;
	mmh2ac->hashValue *= 0x5BD1E995;
	mmh2ac->hashValue ^= mmh2ac->hashValue >> 15;
	*(UI4 *)output = mmh2ac->hashValue;
}

MASTER_zzz_HASHLIB_CALC_STUB( MurmurHash2A )

#endif /* #! MurmurHash2A !# */

/* #! API !# */

typedef struct {
	MASTER_Hashlib_Algorithms id;
	union {
#define MASTER_zzz_HASHLIB_API_STRUCT( macroName, algorithmName, member ) \
	MASTER_Hashlib_## algorithmName ##_Context member;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_STRUCT )
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

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_Create /* ! */,
	MASTER_Hashlib_Context,
	( const MASTER_Hashlib_Algorithms, id )
) {
	MASTER_Hashlib_Context hash;
	hash.id = id;
	switch (hash.id) {
#define MASTER_zzz_HASHLIB_API_CREATE( macroName, algorithmName, member ) \
		case MASTER_HASHLIB_## macroName ##_ID: \
			hash.context.member = MASTER_Hashlib_## algorithmName ##_Create(); \
		break;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_CREATE )
	}
	return hash;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_Init /* ! */,
	void,
	( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT, hash ),
	( const MASTER_Hashlib_Algorithms, id )
) {
	hash->id = id;
	switch (hash->id) {
#define MASTER_zzz_HASHLIB_API_INIT( macroName, algorithmName, member ) \
		case MASTER_HASHLIB_## macroName ##_ID: \
			MASTER_Hashlib_## algorithmName ##_Init(&(hash->context.member)); \
		break;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_INIT )
	}
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_Flush /* ! */,
	void,
	( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT, hash )
) {
	switch (hash->id) {
#define MASTER_zzz_HASHLIB_API_FLUSH( macroName, algorithmName, member ) \
		case MASTER_HASHLIB_## macroName ##_ID: \
			MASTER_Hashlib_## algorithmName ##_Flush(&(hash->context.member)); \
		break;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_FLUSH )
	}
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_Update /* ! */,
	void,
	( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT, hash ),
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length )
) {
	switch (hash->id) {
#define MASTER_zzz_HASHLIB_API_UPDATE( macroName, algorithmName, member ) \
		case MASTER_HASHLIB_## macroName ##_ID: \
			MASTER_Hashlib_## algorithmName ##_Update(&(hash->context.member), bytes, length); \
		break;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_UPDATE )
	}
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_Finish /* ! */,
	void,
	( MASTER_Hashlib_Context * const MASTER_PREFER_RESTRICT, hash ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	switch (hash->id) {
#define MASTER_zzz_HASHLIB_API_FINISH( macroName, algorithmName, member ) \
		case MASTER_HASHLIB_## macroName ##_ID: \
			MASTER_Hashlib_## algorithmName ##_Finish(&(hash->context.member), output); \
		break;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_FINISH )
	}
}

MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_Calculate /* ! */,
	void,
	( const MASTER_Hashlib_Algorithms, id ),
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	switch (id) {
#define MASTER_zzz_HASHLIB_API_CALC( macroName, algorithmName, member ) \
		case MASTER_HASHLIB_## macroName ##_ID: \
			MASTER_Hashlib_## algorithmName ##_Calculate(bytes, length, output); \
		break;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_CALC )
	}
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_GetAlgorithmName /* ! */,
	const char *,
	( const MASTER_Hashlib_Algorithms, id )
) {
	switch (id) {
#define MASTER_zzz_HASHLIB_API_ALGONAME( macroName, algorithmName, __not_used_1__ ) \
		case MASTER_HASHLIB_## macroName ##_ID : return (const char *)#algorithmName;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_ALGONAME )
		default : return (const char *)"Unknown";
	}
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Hashlib_GetAlgorithmOutputSize /* ! */,
	MASTER_maxint,
	( const MASTER_Hashlib_Algorithms, id )
) {
	switch (id) {
#define MASTER_zzz_HASHLIB_API_ALGOSIZE( macroName, algorithmName, __not_used_1__ ) \
		case MASTER_HASHLIB_## macroName ##_ID : return MASTER_HASHLIB_## macroName ##_DIGEST_SIZE;

		MASTER_zzz_HASHLIB_XMAC_DEFALGO( MASTER_zzz_HASHLIB_API_ALGOSIZE )
		default : return 0;
	}
}

#endif /* #! API !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zzz_HASHLIB_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_HASHLIB_H !# */

/* #! be master~ !# */

/*
#include <stdio.h>
#include <string.h>

void
drunked_walk( const UI1 * bytes, MASTER_maxint length, char output[9][18] ) {
	const char symbols[] = " .o+=*BOX@%&#/^";
	const UI1 symbolCount = sizeof(symbols) / sizeof(symbols[0]);
	SI1 x = 8;
	SI1 y = 4;
	UI1 index;
	UI1 jndex;
	for (index = 0; index < 9; index += 1) {
		for (jndex = 0; jndex < 17; jndex += 1)
			output[index][jndex] = ' ';
		output[index][jndex] = 0;
	}
	while (length > 0) {
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
			for (jndex = 0; jndex < symbolCount - 1; jndex += 1)
				if (output[y][x] == symbols[jndex]) {
					output[y][x] = symbols[jndex + 1];
					break;
				}
		}
		length -= 1;
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
	UI4 length;
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
	length = strlen(argv[1]);
	printf("Got '%s' (%d)\n", argv[1], length);
	for (id = MASTER_HASHLIB_MIN_ID; id <= MASTER_HASHLIB_MAX_ID; id += 1, algoused += 1) {
		size = (MASTER_Hashlib_GetAlgorithmOutputSize(id) & 0xFFFF) >> 3;
		ptr = MASTER_Hashlib_GetAlgorithmName(id);

		for (index = 0; index < size; index += 1)
			sum[index] = 0;
		MASTER_Hashlib_Calculate(id, argv[1], length, sum);
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
