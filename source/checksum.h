
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_CHECKSUM_INCLUDE_H
#define MASTER_zRIVATE_CHECKSUM_INCLUDE_H

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
#		ifdef MASTER_CHECKSUM_ADLER32_USE
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

#define MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( macrofunc ) \
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

MASTER_Checksum_Adler32_Context
MASTER_Checksum_Adler32_Create( void ) {
	MASTER_Checksum_Adler32_Context adler32c;
	adler32c.checksum = 1;
	return adler32c;
}

void
MASTER_Checksum_Adler32_Init( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT adler32c ) {
	MASTER_zRIVATE_CHECK_NUL_RETURN( adler32c, MASTER_NOTHING );
	adler32c->checksum = 1;
}

void
MASTER_Checksum_Adler32_Update( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT adler32c, const void * MASTER_PREFER_RESTRICT bytes, MASTER_maxint len ) {
	UI4 part1;
	UI4 part2;
	UI4 index;
	MASTER_zRIVATE_CHECK_NUL_RETURN( adler32c, MASTER_NOTHING );
	MASTER_zRIVATE_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	part1 = adler32c->checksum & 0xFFFF;
	part2 = (adler32c->checksum >> 16) & 0xFFFF;
	while (len > 0) {
		index = 5552;
		/* #! Uncomment next if module on your architecture is expensive !# */
		/* #!
		index = 5801 - (part1 >> 8);
		!# */
		if (len < index)
			index = len;
		len -= index;
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

UI4
MASTER_Checksum_Adler32_Finish( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT adler32c, UI1 * const MASTER_PREFER_RESTRICT out ) {
	UI1 index = 0;
	if (out != nul)
		for (; index < 4; index += 1)
			out[index] = (adler32c->checksum >> (24 - (index << 3))) & 0xFF;
	return adler32c->checksum;
}

UI4
MASTER_Checksum_Adler32_Calculate( const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT out ) {
	MASTER_Checksum_Adler32_Context adler32c = MASTER_Checksum_Adler32_Create();
	MASTER_Checksum_Adler32_Update(&adler32c, bytes, len);
	return MASTER_Checksum_Adler32_Finish(&adler32c, out);
}

UI1
MASTER_Checksum_Adler32_Combine( MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT adler32cout, const MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT adler32c1, const MASTER_Checksum_Adler32_Context * const MASTER_PREFER_RESTRICT adler32c2, const UI4 length2 ) {
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
#define MASTER_CHECKSUM_API_CREATE_HANDLER_STRUCTURE( macro_name, algorithm_name, member ) \
	MASTER_Checksum_## algorithm_name ##_Context member;

		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_STRUCTURE )
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

MASTER_Checksum_Context
MASTER_Checksum_Create( const MASTER_Checksum_Algorithms id ) {
	MASTER_Checksum_Context checksum;
	checksum.id = id;
	switch (checksum.id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_CREATE( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			checksum.context.member = MASTER_Checksum_## algorithm_name ##_Create(); \
		break;

		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_CREATE )
	}
	return checksum;
}

void
MASTER_Checksum_Init( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT checksum, const MASTER_Checksum_Algorithms id ) {
	checksum->id = id;
	switch (checksum->id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_INIT( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			MASTER_Checksum_## algorithm_name ##_Init(&(checksum->context.member)); \
		break;

		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_INIT )
	}
}

void
MASTER_Checksum_Flush( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT checksum ) {
	switch (checksum->id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_FLUSH( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			MASTER_Checksum_## algorithm_name ##_Flush(&(checksum->context.member)); \
		break;

		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_FLUSH )
	}
}

void
MASTER_Checksum_Update( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT checksum, const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len ) {
	switch (checksum->id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_UPDATE( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			MASTER_Checksum_## algorithm_name ##_Update(&(checksum->context.member), bytes, len); \
		break;

		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_UPDATE )
	}
}

UI4
MASTER_Checksum_Finish( MASTER_Checksum_Context * const MASTER_PREFER_RESTRICT checksum, UI1 * const MASTER_PREFER_RESTRICT out ) {
	switch (checksum->id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_FINISH( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			return MASTER_Checksum_## algorithm_name ##_Finish(&(checksum->context.member), out);

		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_FINISH )
	}
	return MASTER_UI4_MAX;
}

UI4
MASTER_Checksum_Calculate( const MASTER_Checksum_Algorithms id, const void * const MASTER_PREFER_RESTRICT bytes, const MASTER_maxint len, UI1 * const MASTER_PREFER_RESTRICT out ) {
	switch (id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_CALCULATE( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			return MASTER_Checksum_## algorithm_name ##_Calculate(bytes, len, out);

		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_CALCULATE )
	}
	return MASTER_UI4_MAX;
}

const char *
MASTER_Checksum_GetAlgorithmName( const MASTER_Checksum_Algorithms id ) {
	switch (id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_GETALGORITHMNAME( macro_name, algorithm_name, __not_used_1__ ) \
		case MASTER_CHECKSUM_## macro_name ##_ID : return (const char *)#algorithm_name;
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_GETALGORITHMNAME )
		default : return (const char *)"Unknown";
	}
}

MASTER_maxint
MASTER_Checksum_GetAlgorithmOutputSize( const MASTER_Checksum_Algorithms id ) {
	switch (id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_GETALGORITHMOUTPUTSIZE( macro_name, algorithm_name, __not_used_1__ ) \
		case MASTER_CHECKSUM_## macro_name ##_ID : return MASTER_CHECKSUM_## macro_name ##_DIGEST_SIZE;

		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_GETALGORITHMOUTPUTSIZE )
		default : return 0;
	}
}

#endif /* #! API !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_CHECKSUM_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_HASHLIB_INCLUDE_H !# */

/* #! be master !# */
