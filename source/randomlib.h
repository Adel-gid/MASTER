
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_RANDOMLIB_INCLUDE_H__
#define __MASTER_RANDOMLIB_INCLUDE_H__

#include <master_enum.h>

#ifdef MASTER_RANDOMLIB_EXTERN_ONLY
#	define MASTER_RANDOMLIB_XORSHIFT32_IMPLEMENT 0
#	define MASTER_RANDOMLIB_XORSHIFT64_IMPLEMENT 0
#	define MASTER_RANDOMLIB_XORSHIFT128_IMPLEMENT 0
#else
#	if defined(MASTER_RANDOMLIB_XORSHIFT32_USE) || \
	   defined(MASTER_RANDOMLIB_XORSHIFT64_USE) || \
	   defined(MASTER_RANDOMLIB_XORSHIFT128_USE)
#		define MASTER_RANDOMLIB_WHITELIST_MODE 1
#	else
#		define MASTER_RANDOMLIB_WHITELIST_MODE 0
#	endif /* #! Whitelist Setting !# */
#	ifdef MASTER_RANDOMLIB_XORSHIFT32_EXTERN
#		define MASTER_RANDOMLIB_XORSHIFT32_IMPLEMENT 0
#		ifdef MASTER_RANDOMLIB_XORSHIFT32_USE
#			warning "xorshift32 is defined to USE, but also defined to EXTERN. xorshift32 will NOT be compiled."
#		endif /* #! xorshift32 Conflict of Use & Extern !# */
#	elif MASTER_RANDOMLIB_WHITELIST_MODE == 1
#		ifdef MASTER_RANDOMLIB_XORSHIFT32_USE
#			define MASTER_RANDOMLIB_XORSHIFT32_IMPLEMENT 1
#		else
#			define MASTER_RANDOMLIB_XORSHIFT32_IMPLEMENT 0
#		endif /* #! xorshift32 Use !# */
#	else
#		define MASTER_RANDOMLIB_XORSHIFT32_IMPLEMENT 1
#	endif /* #! xorshift32 !# */
#	ifdef MASTER_RANDOMLIB_XORSHIFT64_EXTERN
#		define MASTER_RANDOMLIB_XORSHIFT64_IMPLEMENT 0
#		ifdef MASTER_RANDOMLIB_XORSHIFT64_USE
#			warning "xorshift64 is defined to USE, but also defined to EXTERN. xorshift64 will NOT be compiled."
#		endif /* #! xorshift64 Conflict of Use & Extern !# */
#	elif MASTER_RANDOMLIB_WHITELIST_MODE == 1
#		ifdef MASTER_RANDOMLIB_XORSHIFT64_USE
#			define MASTER_RANDOMLIB_XORSHIFT64_IMPLEMENT 1
#		else
#			define MASTER_RANDOMLIB_XORSHIFT64_IMPLEMENT 0
#		endif /* #! xorshift64 Use !# */
#	else
#		define MASTER_RANDOMLIB_XORSHIFT64_IMPLEMENT 1
#	endif /* #! xorshift64 !# */
#	ifdef MASTER_RANDOMLIB_XORSHIFT128_EXTERN
#		define MASTER_RANDOMLIB_XORSHIFT128_IMPLEMENT 0
#		ifdef MASTER_RANDOMLIB_XORSHIFT128_USE
#			warning "xorshift128 is defined to USE, but also defined to EXTERN. xorshift128 will NOT be compiled."
#		endif /* #! xorshift128 Conflict of Use & Extern !# */
#	elif MASTER_RANDOMLIB_WHITELIST_MODE == 1
#		ifdef MASTER_RANDOMLIB_XORSHIFT128_USE
#			define MASTER_RANDOMLIB_XORSHIFT128_IMPLEMENT 1
#		else
#			define MASTER_RANDOMLIB_XORSHIFT128_IMPLEMENT 0
#		endif /* #! xorshift128 Use !# */
#	else
#		define MASTER_RANDOMLIB_XORSHIFT128_IMPLEMENT 1
#	endif /* #! xorshift128 !# */
#	undef MASTER_RANDOMLIB_WHITELIST_MODE
#endif /* #! MASTER_RANDOMLIB_EXTERN_ONLY !# */

/* #! Xorshift !# */

typedef struct {
	UI4 state;
} MASTER_Randomlib_xorshift32;

MASTER_PREFER_EXTERN UI4
MASTER_Randomlib_xorshift32_Next( MASTER_Randomlib_xorshift32 * const, UI4 * const );

#if MASTER_RANDOMLIB_XORSHIFT32_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Randomlib_xorshift32_Next /* ! */,
	UI4,
	( MASTER_Randomlib_xorshift32 * const, xs32c ),
	( UI4 * const, out )
) {
	if (xs32c == nul) return 0;
	xs32c->state ^= xs32c->state << 13;
	xs32c->state ^= xs32c->state >> 17;
	xs32c->state ^= xs32c->state << 5;
	if (out != nul)
		*out = xs32c->state;
	return xs32c->state;
}

/* #! Jump 1.000, 1.000.000, 1.000.000.000 !# */

#endif /* #! xorshift32 !# */

typedef struct {
	UI8 state;
} MASTER_Randomlib_xorshift64;

MASTER_PREFER_EXTERN UI4
MASTER_Randomlib_xorshift64_Next( MASTER_Randomlib_xorshift64 * const, UI8 * const );

#if MASTER_RANDOMLIB_XORSHIFT64_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Randomlib_xorshift64_Next /* ! */,
	UI4,
	( MASTER_Randomlib_xorshift64 * const, xs64c ),
	( UI8 * const, out )
) {
	if (xs64c == nul) return 0;
#ifdef MASTER_UI8_TYPE
	xs64c->state ^= xs64c->state << 13;
	xs64c->state ^= xs64c->state >> 7;
	xs64c->state ^= xs64c->state << 17;
	if (out != nul)
		*out = xs64c->state;
	return xs64c->state & 0xFFFFFFFF;
#elif MASTER_UI8_ARRAY_TYPE == 1
	xs64c->state[1] ^= (xs64c->state[1] << 13) | (xs64c->state[0] >> (32 - 13));
	xs64c->state[0] ^= xs64c->state[0] << 13;
	xs64c->state[0] ^= (xs64c->state[0] >> 7) | (xs64c->state[1] << (32 - 7));
	xs64c->state[1] ^= xs64c->state[1] >> 7;
	xs64c->state[1] ^= (xs64c->state[1] << 17) | (xs64c->state[0] >> (32 - 17));
	xs64c->state[0] ^= xs64c->state[0] << 17;
	if (out != nul)
		MASTER_MEMCPY((UI1 *)out, (UI1 *)xs64c->state, sizeof(UI8));
	return xs64c->state[0];
#else
#	error "User type of UI8, nor the array, is not supporting on the current time."
#endif /* #! MASTER_UI8_TYPE !# */
}

/* #! Jump 1.000, 1.000.000, 1.000.000.000, 1E+12, 1E+15, 1E+18 !# */

#endif /* #! xorshift64 !# */

typedef struct {
	UI4 state[4];
} MASTER_Randomlib_xorshift128;

MASTER_PREFER_EXTERN UI4
MASTER_Randomlib_xorshift128_Next( MASTER_Randomlib_xorshift128 * const, UI4 * const );

#if MASTER_RANDOMLIB_XORSHIFT128_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Randomlib_xorshift128_Next /* ! */,
	UI4,
	( MASTER_Randomlib_xorshift128 * const, xs128c ),
	( UI4 * const, out )
) {
	UI4 value1;
	UI4 value2;
	if (xs128c == nul) return 0;
	value1 = xs128c->state[3];
	value2 = xs128c->state[0];
	xs128c->state[3] = xs128c->state[2];
	xs128c->state[2] = xs128c->state[1];
	xs128c->state[1] = value2;
	value1 ^= value1 << 11;
	value1 ^= value1 >> 8;
	xs128c->state[0] = value1 ^ value2 ^ (value2 >> 19);
	if (out != nul)
		*out = xs128c->state[0];
	return xs128c->state[0];
}

/* #! Jump 1.000, 1.000.000, 1.000.000.000, 1E+12, 1E+15, 1E+18, 1E+21, 1E+24, 1E+27, 1E+30, 1E+33, 1E+36 !# */

#endif /* #! xorshift128 !# */

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_RANDOMLIB_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_RANDOMLIB_INCLUDE_H__ !# */

/* #! be master !# */
