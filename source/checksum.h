
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_CHECKSUM_H
#define MASTER_zzz_CHECKSUM_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#ifdef MASTER_CHECKSUM_EXTERN_ONLY
#	define MASTER_CHECKSUM_ADLER32_IMPLEMENT 0
#	define MASTER_CHECKSUM_API_IMPLEMENT 0
#else
#	define MASTER_CHECKSUM_API_IMPLEMENT 1
#	if defined(MASTER_CHECKSUM_ADLER32_USE)
#		define MASTER_CHECKSUM_WHITELIST_MODE 1
#	else
#		define MASTER_CHECKSUM_WHITELIST_MODE 0
#	endif /* #! Whitelist Setting !# */
#	ifdef MASTER_CHECKSUM_ADLER32_EXTERN
#		define MASTER_CHECKSUM_ADLER32_IMPLEMENT 0
#		if defined(MASTER_CHECKSUM_ADLER32_USE) && MASTER_COMPILER_WARNING_AVAIL == 1
 #			warning "Adler32 is defined to USE, but also defined to EXTERN. Adler32 will NOT be compiled."
#		endif /* #! Adler32 Conflict of Use & Extern !# */
#	elif MASTER_CHECKSUM_WHITELIST_MODE == 1
#		ifdef MASTER_CHECKSUM_ADLER32_USE
#			define MASTER_CHECKSUM_ADLER32_IMPLEMENT 1
#		else
#			define MASTER_CHECKSUM_ADLER32_IMPLEMENT 0
#		endif /* #! Adler32 Use !# */
#	else
#		define MASTER_CHECKSUM_ADLER32_IMPLEMENT 1
#	endif /* #! Adler32 !# */
#	undef MASTER_CHECKSUM_WHITELIST_MODE
#endif /* #! MASTER_CHECKSUM_EXTERN_ONLY !# */

typedef enum {
	MASTER_CHECKSUM_ADLER32_ID = 0,
	MASTER_CHECKSUM_MIN_ID = MASTER_CHECKSUM_ADLER32_ID,
	MASTER_CHECKSUM_MAX_ID = MASTER_CHECKSUM_ADLER32_ID
} MASTER_Checksum_Algorithms;

#define MASTER_CHECKSUM_ADLER32_DIGEST_SIZE 32
#define MASTER_CHECKSUM_MIN_DIGEST_SIZE 32
#define MASTER_CHECKSUM_MAX_DIGEST_SIZE 32

#define MASTER_zzz_CHECKSUM_XMAC_DEFALGO( macrofunc ) \
	macrofunc( ADLER32, Adler32, adler32 )

/* #! Adler32 !# */

typedef struct {
	UI4 checksum;
} MASTER_Checksum_Adler32_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Checksum_Adler32_Context, MASTER_Checksum_Adler32_Create, ( void ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Checksum_Adler32_Init, ( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT ) );
#define MASTER_Checksum_Adler32_Flush MASTER_Checksum_Adler32_Init
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Checksum_Adler32_Update, ( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, const void * MASTER_PREFER_RESTRICT, MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Checksum_Adler32_Finish, ( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Checksum_Adler32_Calculate, ( const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_Checksum_Adler32_Combine, ( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, const MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, const MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, const UI4 ) );

#if MASTER_CHECKSUM_ADLER32_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION0(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Adler32_Create /* ! */,
	MASTER_Checksum_Adler32_Context
) {
	MASTER_Checksum_Adler32_Context adler32c;
	adler32c.checksum = 1;
	return adler32c;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Adler32_Init /* ! */,
	void,
	( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, adler32c )
) {
	MASTER_zzz_CHECK_NUL_RETURN( adler32c, MASTER_NOTHING );
	adler32c->checksum = 1;
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Adler32_Update /* ! */,
	void,
	( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, adler32c ),
	( const void * MASTER_PREFER_RESTRICT, bytes ),
	( MASTER_maxint, length )
) {
	UI4 part1;
	UI4 part2;
	UI4 index;
	MASTER_zzz_CHECK_NUL_RETURN( adler32c, MASTER_NOTHING );
	MASTER_zzz_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	part1 = adler32c->checksum & 0xFFFF;
	part2 = (adler32c->checksum >> 16) & 0xFFFF;
	while (length > 0) {
		index = 5552;
		/* #! Uncomment next if modulo on your architecture is expensive !# */
		/* #!
		index = 5801 - (part1 >> 8);
		!# */
		if (length < index)
			index = (UI4)length;
		length -= index;
		while (index > 0) {
			part1 += *((const UI1 *)bytes);
			part2 += part1;
			bytes = (const UI1 *)bytes + 1;
			index -= 1;
		}
		part1 %= 65521;
		part2 %= 65521;
	}
	adler32c->checksum = (part2 << 16) | part1;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Adler32_Finish /* ! */,
	UI4,
	( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, adler32c ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	UI1 index = 0;
	if (output != nul)
		for (/* #! Inited above !# */; index < 4; index += 1)
			output[index] = (adler32c->checksum >> (24 - (index << 3))) & 0xFF;
	return adler32c->checksum;
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Adler32_Calculate /* ! */,
	UI4,
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	MASTER_Checksum_Adler32_Context adler32c;
	MASTER_zzz_CHECK_NUL_RETURN( bytes, 0 );
	MASTER_zzz_CHECK_NUL_RETURN( output, 0 );
	adler32c = MASTER_Checksum_Adler32_Create();
	MASTER_Checksum_Adler32_Update(&adler32c, bytes, length);
	return MASTER_Checksum_Adler32_Finish(&adler32c, output);
}

MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Adler32_Combine /* ! */,
	UI1,
	( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, adler32cout ),
	( const MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, adler32c1 ),
	( const MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT, adler32c2 ),
	( const UI4, length2 )
) {
	UI4 state1;
	UI4 state2;
	if (adler32cout == nul || adler32c1 == nul || adler32c2 == nul) return MASTER_ERROR;
	state1 = (adler32c1->checksum & 0xFFFF) + (adler32c2->checksum & 0xFFFF) - 1;
	state2 = ((adler32c1->checksum >> 16) & 0xFFFF) + ((adler32c2->checksum >> 16) & 0xFFFF) + 65521 + ((adler32c1->checksum & 0xFFFF) - 1) * (length2 % 65521);
	adler32cout->checksum = ((state2 % 65521) << 16) | (state1 % 65521);
	return MASTER_NO_ERROR;
}

#endif /* #! Adler32 !# */

/* #! API !# */

typedef struct {
	MASTER_Checksum_Algorithms id;
	union {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_STRUCTURE( macroName, algorithmName, member ) \
	MASTER_Checksum_## algorithmName ##_Context member;

		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_CHECKSUM_API_CREATE_HANDLER_STRUCTURE )
	} context;
} MASTER_Checksum_Context;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_Checksum_Context, MASTER_Checksum_Create, ( const MASTER_Checksum_Algorithms ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Checksum_Init, ( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT, const MASTER_Checksum_Algorithms ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Checksum_Flush, ( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Checksum_Update, ( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT, const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Checksum_Finish, ( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Checksum_Calculate, ( const MASTER_Checksum_Algorithms, const void * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UI1 * const MASTER_PREFER_RESTRICT ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, const char *, MASTER_Checksum_GetAlgorithmName, ( const MASTER_Checksum_Algorithms ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_maxint, MASTER_Checksum_GetAlgorithmOutputSize, ( const MASTER_Checksum_Algorithms ) );

#if MASTER_CHECKSUM_API_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Create /* ! */,
	MASTER_Checksum_Context,
	( const MASTER_Checksum_Algorithms, id )
) {
	MASTER_Checksum_Context checksum;
	checksum.id = id;
	switch (checksum.id) {
#define MASTER_zzz_CHECKSUM_API_CREATE( macroName, algorithmName, member ) \
		case MASTER_CHECKSUM_## macroName ##_ID: \
			checksum.context.member = MASTER_Checksum_## algorithmName ##_Create(); \
		break;

		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_zzz_CHECKSUM_API_CREATE )
	}
	return checksum;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Init /* ! */,
	void,
	( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT, checksum ),
	( const MASTER_Checksum_Algorithms, id )
) {
	checksum->id = id;
	switch (checksum->id) {
#define MASTER_zzz_CHECKSUM_API_INIT( macroName, algorithmName, member ) \
		case MASTER_CHECKSUM_## macroName ##_ID: \
			MASTER_Checksum_## algorithmName ##_Init(&(checksum->context.member)); \
		break;

		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_zzz_CHECKSUM_API_INIT )
	}
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Flush /* ! */,
	void,
	( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT, checksum )
) {
	switch (checksum->id) {
#define MASTER_zzz_CHECKSUM_API_FLUSH( macroName, algorithmName, member ) \
		case MASTER_CHECKSUM_## macroName ##_ID: \
			MASTER_Checksum_## algorithmName ##_Flush(&(checksum->context.member)); \
		break;

		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_zzz_CHECKSUM_API_FLUSH )
	}
}

MASTER_DEFINE_FUNCTION3(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Update /* ! */,
	void,
	( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT, checksum ),
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length )
) {
	switch (checksum->id) {
#define MASTER_zzz_CHECKSUM_API_UPDATE( macroName, algorithmName, member ) \
		case MASTER_CHECKSUM_## macroName ##_ID: \
			MASTER_Checksum_## algorithmName ##_Update(&(checksum->context.member), bytes, length); \
		break;

		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_zzz_CHECKSUM_API_UPDATE )
	}
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Finish /* ! */,
	UI4,
	( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT, checksum ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	switch (checksum->id) {
#define MASTER_zzz_CHECKSUM_API_FINISH( macroName, algorithmName, member ) \
		case MASTER_CHECKSUM_## macroName ##_ID: \
			return MASTER_Checksum_## algorithmName ##_Finish(&(checksum->context.member), output);

		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_zzz_CHECKSUM_API_FINISH )
	}
	return MASTER_UI4_MAX;
}

MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_Calculate /* ! */,
	UI4,
	( const MASTER_Checksum_Algorithms, id ),
	( const void * const MASTER_PREFER_RESTRICT, bytes ),
	( const MASTER_maxint, length ),
	( UI1 * const MASTER_PREFER_RESTRICT, output )
) {
	switch (id) {
#define MASTER_zzz_CHECKSUM_API_CALC( macroName, algorithmName, member ) \
		case MASTER_CHECKSUM_## macroName ##_ID: \
			return MASTER_Checksum_## algorithmName ##_Calculate(bytes, length, output);

		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_zzz_CHECKSUM_API_CALC )
	}
	return MASTER_UI4_MAX;
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_GetAlgorithmName /* ! */,
	const char *,
	( const MASTER_Checksum_Algorithms, id )
) {
	switch (id) {
#define MASTER_zzz_CHECKSUM_API_ALGONAME( macroName, algorithmName, __not_used_1__ ) \
		case MASTER_CHECKSUM_## macroName ##_ID : return (const char *)#algorithmName;
		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_zzz_CHECKSUM_API_ALGONAME )
		default : return (const char *)"Unknown";
	}
}

MASTER_DEFINE_FUNCTION1(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Checksum_GetAlgorithmOutputSize /* ! */,
	MASTER_maxint,
	( const MASTER_Checksum_Algorithms, id )
) {
	switch (id) {
#define MASTER_zzz_CHECKSUM_API_ALGOSIZE( macroName, algorithmName, __not_used_1__ ) \
		case MASTER_CHECKSUM_## macroName ##_ID : return MASTER_CHECKSUM_## macroName ##_DIGEST_SIZE;

		MASTER_zzz_CHECKSUM_XMAC_DEFALGO( MASTER_zzz_CHECKSUM_API_ALGOSIZE )
		default : return 0;
	}
}

#endif /* #! API !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zzz_CHECKSUM_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_HASHLIB_H !# */

/* #! be master !# */
