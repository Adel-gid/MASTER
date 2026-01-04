
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_CHECKSUM_INCLUDE_H__
#define __MASTER_CHECKSUM_INCLUDE_H__

#include <master_enum.h>

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

#define MASTER_CHECKSUM_ADLER32_ID 0
#define MASTER_CHECKSUM_MIN_ID MASTER_CHECKSUM_ADLER32_ID
#define MASTER_CHECKSUM_MAX_ID MASTER_CHECKSUM_ADLER32_ID

#define MASTER_CHECKSUM_ADLER32_DIGEST_SIZE 32
#define MASTER_CHECKSUM_MIN_DIGEST_SIZE 32
#define MASTER_CHECKSUM_MAX_DIGEST_SIZE 32

#define MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( macrofunc ) \
	macrofunc( ADLER32, Adler32, adler32 )

/* #! Adler32 !# */

typedef struct {
	UI4 checksum;
} MASTER_Checksum_Adler32_Context;

MASTER_PREFER_EXTERN MASTER_Checksum_Adler32_Context
MASTER_Checksum_Adler32_Create( void );
MASTER_PREFER_EXTERN void
MASTER_Checksum_Adler32_Init( MASTER_Checksum_Adler32_Context * const );
#define MASTER_Checksum_Adler32_Flush MASTER_Checksum_Adler32_Init
MASTER_PREFER_EXTERN void
MASTER_Checksum_Adler32_Update( MASTER_Checksum_Adler32_Context * const, const void *, MASTER_maxint );
MASTER_PREFER_EXTERN UI4
MASTER_Checksum_Adler32_Finish( MASTER_Checksum_Adler32_Context * const, UI1 * const );
MASTER_PREFER_EXTERN UI4
MASTER_Checksum_Adler32_Calculate( const void * const, const MASTER_maxint, UI1 * const );
MASTER_PREFER_EXTERN UI1
MASTER_Checksum_Adler32_Combine( MASTER_Checksum_Adler32_Context * const, const MASTER_Checksum_Adler32_Context * const, const MASTER_Checksum_Adler32_Context * const, const UI4 );

#if MASTER_CHECKSUM_ADLER32_IMPLEMENT == 1

MASTER_Checksum_Adler32_Context
MASTER_Checksum_Adler32_Create( void ) {
	MASTER_Checksum_Adler32_Context adler32c;
	adler32c.checksum = 1;
	return adler32c;
}

void
MASTER_Checksum_Adler32_Init( MASTER_Checksum_Adler32_Context * const adler32c ) {
	__MASTER_CHECK_NUL_RETURN( adler32c, MASTER_NOTHING );
	adler32c->checksum = 1;
}

/* #! Naive !# */
void
MASTER_Checksum_Adler32_Update( MASTER_Checksum_Adler32_Context * const adler32c, const void * bytes, MASTER_maxint len ) {
	UI4 part1;
	UI4 part2;
	MASTER_maxint index = 0;
	__MASTER_CHECK_NUL_RETURN( adler32c, MASTER_NOTHING );
	__MASTER_CHECK_NUL_RETURN( bytes, MASTER_NOTHING );
	part1 = adler32c->checksum & 0xFFFF;
	part2 = (adler32c->checksum >> 16) & 0xFFFF;
	for (; index < len; index += 1) {
		part1 = (part1 + ((UI1 *)bytes)[index]) % 65521;
		part2 = (part1 + part2) % 65521;
	}
	adler32c->checksum = (part2 << 16) | part1;
}

UI4
MASTER_Checksum_Adler32_Finish( MASTER_Checksum_Adler32_Context * const adler32c, UI1 * const out ) {
	UI1 index = 0;
	if (out != nul)
		for (; index < 4; index += 1)
			out[index] = (adler32c->checksum >> (24 - (index << 3))) & 0xFF;
	return adler32c->checksum;
}

UI4
MASTER_Checksum_Adler32_Calculate( const void * const bytes, const MASTER_maxint len, UI1 * const out ) {
	MASTER_Checksum_Adler32_Context adler32c = MASTER_Checksum_Adler32_Create();
	MASTER_Checksum_Adler32_Update(&adler32c, bytes, len);
	return MASTER_Checksum_Adler32_Finish(&adler32c, out);
}

UI1
MASTER_Checksum_Adler32_Combine( MASTER_Checksum_Adler32_Context * const adler32cout, const MASTER_Checksum_Adler32_Context * const adler32c1, const MASTER_Checksum_Adler32_Context * const adler32c2, const UI4 length2 ) {
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
	UI1 id;
	union {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_STRUCTURE( macro_name, algorithm_name, member ) \
	MASTER_Checksum_## algorithm_name ##_Context member;
	
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_STRUCTURE )
	} context;
} MASTER_Checksum_Context;

MASTER_PREFER_EXTERN MASTER_Checksum_Context
MASTER_Checksum_Create( const UI1 );
MASTER_PREFER_EXTERN void
MASTER_Checksum_Init( MASTER_Checksum_Context * const, const UI1 );
MASTER_PREFER_EXTERN void
MASTER_Checksum_Flush( MASTER_Checksum_Context * const );
MASTER_PREFER_EXTERN void
MASTER_Checksum_Update( MASTER_Checksum_Context * const, const void * const, const MASTER_maxint );
MASTER_PREFER_EXTERN UI4
MASTER_Checksum_Finish( MASTER_Checksum_Context * const, UI1 * const );
MASTER_PREFER_EXTERN UI4
MASTER_Checksum_Calculate( const UI1, const void * const, const MASTER_maxint, UI1 * const );
MASTER_PREFER_EXTERN const char *
MASTER_Checksum_GetAlgorithmName( const UI1 );
MASTER_PREFER_EXTERN MASTER_maxint
MASTER_Checksum_GetAlgorithmOutputSize( const UI1 );

#if MASTER_CHECKSUM_API_IMPLEMENT == 1

MASTER_Checksum_Context
MASTER_Checksum_Create( const UI1 id ) {
	MASTER_Checksum_Context checksum;
	checksum.id = id;
	switch (checksum.id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_CREATE( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			checksum.context.member = MASTER_Checksum_## algorithm_name ##_Create(); \
		break;
		
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_CREATE )
	};
	return checksum;
}

void
MASTER_Checksum_Init( MASTER_Checksum_Context * const checksum, const UI1 id ) {
	checksum->id = id;
	switch (checksum->id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_INIT( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			MASTER_Checksum_## algorithm_name ##_Init(&(checksum->context.member)); \
		break;
		
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_INIT )
	};
}

void
MASTER_Checksum_Flush( MASTER_Checksum_Context * const checksum ) {
	switch (checksum->id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_FLUSH( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			MASTER_Checksum_## algorithm_name ##_Flush(&(checksum->context.member)); \
		break;
		
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_FLUSH )
	};
}

void
MASTER_Checksum_Update( MASTER_Checksum_Context * const checksum, const void * const bytes, const MASTER_maxint len ) {
	switch (checksum->id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_UPDATE( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			MASTER_Checksum_## algorithm_name ##_Update(&(checksum->context.member), bytes, len); \
		break;
		
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_UPDATE )
	};
}

UI4
MASTER_Checksum_Finish( MASTER_Checksum_Context * const checksum, UI1 * const out ) {
	switch (checksum->id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_FINISH( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			return MASTER_Checksum_## algorithm_name ##_Finish(&(checksum->context.member), out);
		
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_FINISH )
	};
	return MASTER_UI4_MAX;
}

UI4
MASTER_Checksum_Calculate( const UI1 id, const void * const bytes, const MASTER_maxint len, UI1 * const out ) {
	switch (id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_CALCULATE( macro_name, algorithm_name, member ) \
		case MASTER_CHECKSUM_## macro_name ##_ID: \
			return MASTER_Checksum_## algorithm_name ##_Calculate(bytes, len, out);
		
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_CALCULATE )
	};
	return MASTER_UI4_MAX;
}

const char *
MASTER_Checksum_GetAlgorithmName( const UI1 id ) {
	switch (id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_GETALGORITHMNAME( macro_name, algorithm_name, __not_used_1__ ) \
		case MASTER_CHECKSUM_## macro_name ##_ID : return (const char *)#algorithm_name;
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_GETALGORITHMNAME )
		default : return (const char *)"Unknown";
	}
}

MASTER_maxint
MASTER_Checksum_GetAlgorithmOutputSize( const UI1 id ) {
	switch (id) {
#define MASTER_CHECKSUM_API_CREATE_HANDLER_GETALGORITHMOUTPUTSIZE( macro_name, algorithm_name, __not_used_1__ ) \
		case MASTER_CHECKSUM_## macro_name ##_ID : return MASTER_CHECKSUM_## macro_name ##_DIGEST_SIZE;
		
		MASTER_CHECKSUM_XMACRO_FOR_DEFINING_ALGORITHMS( MASTER_CHECKSUM_API_CREATE_HANDLER_GETALGORITHMOUTPUTSIZE )
		default : return 0;
	}
}

#endif /* #! API !# */

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_CHECKSUM_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_HASHLIB_INCLUDE_H__ !# */

/* #! be master !# */
