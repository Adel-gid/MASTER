
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_RANDOMLIB_INCLUDE_H
#define MASTER_zRIVATE_RANDOMLIB_INCLUDE_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#ifdef MASTER_RANDOMLIB_EXTERN_ONLY
#	define MASTER_RANDOMLIB_MIDDLE_SQUARES_IMPLEMENT 0
#	define MASTER_RANDOMLIB_LEHMER_IMPLEMENT 0
#	define MASTER_RANDOMLIB_LCG_IMPLEMENT 0
#	define MASTER_RANDOMLIB_XORSHIFT32_IMPLEMENT 0
#	define MASTER_RANDOMLIB_XORSHIFT64_IMPLEMENT 0
#	define MASTER_RANDOMLIB_XORSHIFT128_IMPLEMENT 0
#	define MASTER_RANDOMLIB_MT19937_IMPLEMENT 0
#	define MASTER_RANDOMLIB_WELL_FAMILY_IMPLEMENT 0
#else
#	if defined(MASTER_RANDOMLIB_MIDDLE_SQUARES_USE) || \
	   defined(MASTER_RANDOMLIB_LEHMER_USE) || \
	   defined(MASTER_RANDOMLIB_LCG_USE) || \
	   defined(MASTER_RANDOMLIB_XORSHIFT32_USE) || \
	   defined(MASTER_RANDOMLIB_XORSHIFT64_USE) || \
	   defined(MASTER_RANDOMLIB_XORSHIFT128_USE) || \
	   defined(MASTER_RANDOMLIB_MT19937_USE) || \
	   defined(MASTER_RANDOMLIB_WELL_FAMILY_USE)
#		define MASTER_RANDOMLIB_WHITELIST_MODE 1
#	else
#		define MASTER_RANDOMLIB_WHITELIST_MODE 0
#	endif /* #! Whitelist Setting !# */
#	ifdef MASTER_RANDOMLIB_MIDDLE_SQUARES_EXTERN
#		define MASTER_RANDOMLIB_MIDDLE_SQUARES_IMPLEMENT 0
#		ifdef MASTER_RANDOMLIB_MIDDLE_SQUARES_USE
#			warning "Middle Squares is defined to USE, but also defined to EXTERN. Middle Squares will NOT be compiled."
#		endif /* #! Middle Squares Conflict of Use & Extern !# */
#	elif MASTER_RANDOMLIB_WHITELIST_MODE == 1
#		ifdef MASTER_RANDOMLIB_MIDDLE_SQUARES_USE
#			define MASTER_RANDOMLIB_MIDDLE_SQUARES_IMPLEMENT 1
#		else
#			define MASTER_RANDOMLIB_MIDDLE_SQUARES_IMPLEMENT 0
#		endif /* #! Middle Squares Use !# */
#	else
#		define MASTER_RANDOMLIB_MIDDLE_SQUARES_IMPLEMENT 1
#	endif /* #! Middle Squares !# */
#	ifdef MASTER_RANDOMLIB_LEHMER_EXTERN
#		define MASTER_RANDOMLIB_LEHMER_IMPLEMENT 0
#		ifdef MASTER_RANDOMLIB_LEHMER_USE
#			warning "Lehmer is defined to USE, but also defined to EXTERN. Lehmer will NOT be compiled."
#		endif /* #! Lehmer Conflict of Use & Extern !# */
#	elif MASTER_RANDOMLIB_WHITELIST_MODE == 1
#		ifdef MASTER_RANDOMLIB_LEHMER_USE
#			define MASTER_RANDOMLIB_LEHMER_IMPLEMENT 1
#		else
#			define MASTER_RANDOMLIB_LEHMER_IMPLEMENT 0
#		endif /* #! Lehmer Use !# */
#	else
#		define MASTER_RANDOMLIB_LEHMER_IMPLEMENT 1
#	endif /* #! Lehmer !# */
#	ifdef MASTER_RANDOMLIB_LCG_EXTERN
#		define MASTER_RANDOMLIB_LCG_IMPLEMENT 0
#		ifdef MASTER_RANDOMLIB_LCG_USE
#			warning "LCG is defined to USE, but also defined to EXTERN. LCG will NOT be compiled."
#		endif /* #! LCG Conflict of Use & Extern !# */
#	elif MASTER_RANDOMLIB_WHITELIST_MODE == 1
#		ifdef MASTER_RANDOMLIB_LCG_USE
#			define MASTER_RANDOMLIB_LCG_IMPLEMENT 1
#		else
#			define MASTER_RANDOMLIB_LCG_IMPLEMENT 0
#		endif /* #! LCG Use !# */
#	else
#		define MASTER_RANDOMLIB_LCG_IMPLEMENT 1
#	endif /* #! LCG !# */
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
#	ifdef MASTER_RANDOMLIB_MT19937_EXTERN
#		define MASTER_RANDOMLIB_MT19937_IMPLEMENT 0
#		ifdef MASTER_RANDOMLIB_MT19937_USE
#			warning "MT19937 is defined to USE, but also defined to EXTERN. MT19937 will NOT be compiled."
#		endif /* #! MT19937 Conflict of Use & Extern !# */
#	elif MASTER_RANDOMLIB_WHITELIST_MODE == 1
#		ifdef MASTER_RANDOMLIB_MT19937_USE
#			define MASTER_RANDOMLIB_MT19937_IMPLEMENT 1
#		else
#			define MASTER_RANDOMLIB_MT19937_IMPLEMENT 0
#		endif /* #! MT19937 Use !# */
#	else
#		define MASTER_RANDOMLIB_MT19937_IMPLEMENT 1
#	endif /* #! MT19937 !# */
#	ifdef MASTER_RANDOMLIB_WELL_FAMILY_EXTERN
#		define MASTER_RANDOMLIB_WELL_FAMILY_IMPLEMENT 0
#		ifdef MASTER_RANDOMLIB_WELL_FAMILY_USE
#			warning "WELL family is defined to USE, but also defined to EXTERN. WELL family will NOT be compiled."
#		endif /* #! WELL family Conflict of Use & Extern !# */
#	elif MASTER_RANDOMLIB_WHITELIST_MODE == 1
#		ifdef MASTER_RANDOMLIB_WELL_FAMILY_USE
#			define MASTER_RANDOMLIB_WELL_FAMILY_IMPLEMENT 1
#		else
#			define MASTER_RANDOMLIB_WELL_FAMILY_IMPLEMENT 0
#		endif /* #! WELL family Use !# */
#	else
#		define MASTER_RANDOMLIB_WELL_FAMILY_IMPLEMENT 1
#	endif /* #! WELL family !# */
#	undef MASTER_RANDOMLIB_WHITELIST_MODE
#endif /* #! MASTER_RANDOMLIB_EXTERN_ONLY !# */

/* #! Middle Squares !# */

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Randomlib_MiddleSquares, ( UI4 * const, SI1 ) );

#if MASTER_RANDOMLIB_MIDDLE_SQUARES_IMPLEMENT == 1

UI4
MASTER_Randomlib_MiddleSquares( UI4 * const seedValue, SI1 digits ) {
	const UI4 value = (seedValue == nul) ? (0) : (*seedValue);
	UI4 output = 0;
	UI4 mask = 10;
	while (digits > 2) {
		digits -= 2;
		mask *= 10;
	}
	output = (((value / mask) * (value / mask)) % mask) * mask +
			 ((value / mask) * (value % mask) * 2 +
			 (((value % mask) * (value % mask)) / mask) % mask);
	if (mask < MASTER_UI4_MAX / mask)
		output %= mask * mask;
	if (seedValue != nul) *seedValue = output;
	return output;
}

#endif /* #! Middle Squares !# */

/* #! Lehmer !# */

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Randomlib_Lehmer, ( UI4 * const, const UI4, const UI4 ) );

#if MASTER_RANDOMLIB_LEHMER_IMPLEMENT == 1

UI4
MASTER_Randomlib_Lehmer( UI4 * const seedValue, const UI4 mulValue, const UI4 modulo ) {
	union {
		UI4 ui4analog;
		SI4 si4analog;
	} value;
	const UI4 remainder = modulo % mulValue;
	const UI4 quotient = modulo / mulValue;
	value.ui4analog = (seedValue == nul) ? (0) : (*seedValue);
	if ((value.si4analog = (SI4)(mulValue * (value.ui4analog % quotient)) - (SI4)(remainder * (value.ui4analog / quotient))) < 0) value.si4analog += modulo;
	if (seedValue != nul) *seedValue = value.ui4analog;
	return value.ui4analog;
}

#endif /* #! Lehmer !# */

#define MASTER_Randomlib_Lehmer1( seedValue ) MASTER_Randomlib_Lehmer(seedValue, 16807, (1 << 31) - 1)
#define MASTER_Randomlib_Lehmer2( seedValue ) MASTER_Randomlib_Lehmer(seedValue, 48271, (1 << 31) - 1)

/* #! LCG !# */

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Randomlib_LCG, ( UI4 * const, const UI4, const UI4, const UI4 ) );
#if MASTER_64_AVAILABLE == 1
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_Randomlib_LCG8, ( UI8 * const, const UI8, const UI8, const UI8 ) );
#endif /* #! 64 Bits !# */

#if MASTER_RANDOMLIB_LCG_IMPLEMENT == 1

UI4
MASTER_Randomlib_LCG( UI4 * const seedValue, const UI4 mulValue, const UI4 addValue, const UI4 modulo ) {
	UI4 value = (seedValue == nul) ? (0) : (*seedValue);
	value = (value * mulValue + addValue) % modulo;
	if (seedValue != nul) *seedValue = value;
	return value;
}

#if MASTER_64_AVAILABLE == 1
	UI8
	MASTER_Randomlib_LCG8( UI8 * const seedValue, const UI8 mulValue, const UI8 addValue, const UI8 modulo ) {
		UI8 value = (seedValue == nul) ? (0) : (*seedValue);
		value = (value * mulValue + addValue) % modulo;
		if (seedValue != nul) *seedValue = value;
		return value;
	}
#endif /* #! 64 Bits !# */

#endif /* #! LCG !# */

/* #! Xorshift !# */

typedef struct {
	UI4 state;
} MASTER_Randomlib_xorshift32;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Randomlib_xorshift32_Next, ( MASTER_Randomlib_xorshift32 * const MASTER_PREFER_RESTRICT, UI4 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_RANDOMLIB_XORSHIFT32_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Randomlib_xorshift32_Next /* ! */,
	UI4,
	( MASTER_Randomlib_xorshift32 * const MASTER_PREFER_RESTRICT, xs32c ),
	( UI4 * const MASTER_PREFER_RESTRICT, out )
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

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Randomlib_xorshift64_Next, ( MASTER_Randomlib_xorshift64 * const MASTER_PREFER_RESTRICT, UI8 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_RANDOMLIB_XORSHIFT64_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Randomlib_xorshift64_Next /* ! */,
	UI4,
	( MASTER_Randomlib_xorshift64 * const MASTER_PREFER_RESTRICT, xs64c ),
	( UI8 * const MASTER_PREFER_RESTRICT, out )
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

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Randomlib_xorshift128_Next, ( MASTER_Randomlib_xorshift128 * const MASTER_PREFER_RESTRICT, UI4 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_RANDOMLIB_XORSHIFT128_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Randomlib_xorshift128_Next /* ! */,
	UI4,
	( MASTER_Randomlib_xorshift128 * const MASTER_PREFER_RESTRICT, xs128c ),
	( UI4 * const MASTER_PREFER_RESTRICT, out )
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

/* #! Mersenne Twister 19937 !# */

#define MASTER_RANDOMLIB_MT19937_NUMBERS 624
#define MASTER_RANDOMLIB_MT19937_OFFSET 397

typedef struct {
	UI4 state[MASTER_RANDOMLIB_MT19937_NUMBERS];
	UI2 index; /* #! =MASTER_RANDOMLIB_MT19937_NUMBERS !# */
} MASTER_Randomlib_MT19937;

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Randomlib_MT19937_Next, ( MASTER_Randomlib_MT19937 * const MASTER_PREFER_RESTRICT, UI4 * const MASTER_PREFER_RESTRICT ) );

#if MASTER_RANDOMLIB_MT19937_IMPLEMENT == 1

MASTER_PREFER_STATIC void
MASTER_Randomlib_MT19937_Twist( MASTER_Randomlib_MT19937 * const MASTER_PREFER_RESTRICT mt19937c ) {
	UI2 index = 0;
	UI4 value;
	UI4 xValue;
#define MASTER_RANDOMLIB_MT19937_TWIST_ROUND( curindex, nextindex, offindex ) do { \
		value = (mt19937c->state[curindex] & 0x80000000) | (mt19937c->state[nextindex] & 0x7FFFFFFF); \
		xValue = value >> 1; \
		if (value & 1) xValue ^= 0x9908B0DF; \
		mt19937c->state[curindex] = mt19937c->state[offindex] ^ xValue; \
	} while (0)
#ifdef MASTER_RANDOMLIB_MT19937_PREFER_OPTIMIZED
	for (; index < MASTER_RANDOMLIB_MT19937_NUMBERS - MASTER_RANDOMLIB_MT19937_OFFSET; index += 1) {
		MASTER_RANDOMLIB_MT19937_TWIST_ROUND(index, index + 1, index + MASTER_RANDOMLIB_MT19937_OFFSET);
	}
	for (; index < MASTER_RANDOMLIB_MT19937_NUMBERS - 1; index += 1) {
		MASTER_RANDOMLIB_MT19937_TWIST_ROUND(index, index + 1, index + (MASTER_RANDOMLIB_MT19937_OFFSET - MASTER_RANDOMLIB_MT19937_NUMBERS));
	}
	MASTER_RANDOMLIB_MT19937_TWIST_ROUND(MASTER_RANDOMLIB_MT19937_NUMBERS - 1, 0, MASTER_RANDOMLIB_MT19937_OFFSET - 1);
#else
	for (; index < MASTER_RANDOMLIB_MT19937_NUMBERS; index += 1) {
		MASTER_RANDOMLIB_MT19937_TWIST_ROUND(index, (index + 1) % MASTER_RANDOMLIB_MT19937_NUMBERS, (index + MASTER_RANDOMLIB_MT19937_OFFSET) % MASTER_RANDOMLIB_MT19937_NUMBERS);
	}
#endif /* #! MASTER_RANDOMLIB_MT19937_PREFER_OPTIMIZED !# */
	mt19937c->index = 0;
#undef MASTER_RANDOMLIB_MT19937_TWIST_ROUND
}

UI4
MASTER_Randomlib_MT19937_Next( MASTER_Randomlib_MT19937 * const MASTER_PREFER_RESTRICT mt19937c, UI4 * const MASTER_PREFER_RESTRICT output ) {
	UI4 value;
	if (mt19937c == nul) return 0;
	if (mt19937c->index >= MASTER_RANDOMLIB_MT19937_NUMBERS)
		MASTER_Randomlib_MT19937_Twist(mt19937c);
	value = mt19937c->state[mt19937c->index];
	mt19937c->index += 1;
	value ^= value >> 11;
	value ^= (value << 7) & 0x9D2C5680;
	value ^= (value << 15) & 0xEFC60000;
	value ^= value >> 18;
	if (output != nul) *output = value;
	return value;
}

#endif /* #! MT19937 !# */

/* #! WELL !# */

#define MASTER_RANDOMLIB_WELL_M0( value, word_bits ) 0
#define MASTER_RANDOMLIB_WELL_M1( value, word_bits ) (value)
#define MASTER_RANDOMLIB_WELL_M2( value, t_value, word_bits ) (((SI4)(t_value) >= 0) ? ((value) >> (SI4)(t_value)) : ((value) << MASTER_ABS((SI4)(t_value))))
#define MASTER_RANDOMLIB_WELL_M3( value, t_value, word_bits ) ((value) ^ (((SI4)(t_value) >= 0) ? ((value) >> (SI4)(t_value)) : ((value) << -(SI4)(t_value))))
#define MASTER_RANDOMLIB_WELL_M4( value, a_value, word_bits ) (((value) >> 1) ^ ((((value) >> ((word_bits) - 1)) & 1) == 1) ? (a_value) : (0))
#define MASTER_RANDOMLIB_WELL_M5( value, t_value, b_value, word_bits ) ((value) ^ ((((SI4)(t_value) >= 0) ? ((value) << (SI4)(t_value)) : ((value) >> -(SI4)(t_value))) & (b_value)))
#define MASTER_RANDOMLIB_WELL_M6( value, r_value, s_value, t_value, a_value, word_bits ) (((((value) << (r_value)) ^ ((value) >> ((word_bits) - (r_value)))) & (~(1 << (s_value)))) ^ (((((value) >> (t_value)) & 1) == 1) ? (a_value) : (0)))

#define MASTER_RANDOMLIB_WELL_FALL_M0( arg_list ) MASTER_RANDOMLIB_WELL_M0 arg_list
#define MASTER_RANDOMLIB_WELL_FALL_M1( arg_list ) MASTER_RANDOMLIB_WELL_M1 arg_list
#define MASTER_RANDOMLIB_WELL_FALL_M2( arg_list ) MASTER_RANDOMLIB_WELL_M2 arg_list
#define MASTER_RANDOMLIB_WELL_FALL_M3( arg_list ) MASTER_RANDOMLIB_WELL_M3 arg_list
#define MASTER_RANDOMLIB_WELL_FALL_M4( arg_list ) MASTER_RANDOMLIB_WELL_M4 arg_list
#define MASTER_RANDOMLIB_WELL_FALL_M5( arg_list ) MASTER_RANDOMLIB_WELL_M5 arg_list
#define MASTER_RANDOMLIB_WELL_FALL_M6( arg_list ) MASTER_RANDOMLIB_WELL_M6 arg_list

#define MASTER_RANDOMLIB_WELL_FALL_FALL_M0() MASTER_RANDOMLIB_WELL_FALL_M0
#define MASTER_RANDOMLIB_WELL_FALL_FALL_M1() MASTER_RANDOMLIB_WELL_FALL_M1
#define MASTER_RANDOMLIB_WELL_FALL_FALL_M2( t_value ) MASTER_RANDOMLIB_WELL_FALL_M2
#define MASTER_RANDOMLIB_WELL_FALL_FALL_M3( t_value ) MASTER_RANDOMLIB_WELL_FALL_M3
#define MASTER_RANDOMLIB_WELL_FALL_FALL_M4( a_value ) MASTER_RANDOMLIB_WELL_FALL_M4
#define MASTER_RANDOMLIB_WELL_FALL_FALL_M5( t_value, b_value ) MASTER_RANDOMLIB_WELL_FALL_M5
#define MASTER_RANDOMLIB_WELL_FALL_FALL_M6( r_value, s_value, t_value, a_value ) MASTER_RANDOMLIB_WELL_FALL_M6

#define MASTER_RANDOMLIB_WELL_UNARG_M0 MASTER_UNARG_END0
#define MASTER_RANDOMLIB_WELL_UNARG_M1 MASTER_UNARG_END0
#define MASTER_RANDOMLIB_WELL_UNARG_M2 MASTER_UNARG_END1
#define MASTER_RANDOMLIB_WELL_UNARG_M3 MASTER_UNARG_END1
#define MASTER_RANDOMLIB_WELL_UNARG_M4 MASTER_UNARG_END1
#define MASTER_RANDOMLIB_WELL_UNARG_M5 MASTER_UNARG_END2
#define MASTER_RANDOMLIB_WELL_UNARG_M6 MASTER_UNARG_END4

#define MASTER_RANDOMLIB_CREATE_WELL_PACKAGE( upper_name, lower_name, bit_count, word_bits, member1, member2, member3, b_constant, c_constant, func0, func1, func2, func3, func4, func5, func6, func7 ) \
typedef struct { \
	MASTER_ ## word_bits ## BIT_NUMBER state[bit_count / word_bits + !!(bit_count % word_bits)]; \
	UI4 index; /* #! =0 !# */ \
} MASTER_Randomlib_WELL ## upper_name; \
\
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_ ## word_bits ## BIT_NUMBER, MASTER_Randomlib_WELL ## upper_name ## _Next, ( MASTER_Randomlib_WELL ## upper_name * MASTER_PREFER_RESTRICT const, MASTER_ ## word_bits ## BIT_NUMBER * MASTER_PREFER_RESTRICT const ) ); \
\
MASTER_ ## word_bits ## BIT_NUMBER \
MASTER_Randomlib_WELL ## upper_name ## _Next( MASTER_Randomlib_WELL ## upper_name * const MASTER_PREFER_RESTRICT well ## lower_name ## c, MASTER_ ## word_bits ## BIT_NUMBER * const MASTER_PREFER_RESTRICT output ) { \
	UI4 z_state[5]; \
	UI4 v_state[5]; \
	UI4 index[5]; \
	UI4 result; \
	v_state[0] = well ## lower_name ## c->state[index[0] = well ## lower_name ## c->index]; \
	v_state[1] = well ## lower_name ## c->state[index[1] = (well ## lower_name ## c->index + (member1)) % (bit_count / word_bits + !!(bit_count % word_bits))]; \
	v_state[2] = well ## lower_name ## c->state[index[2] = (well ## lower_name ## c->index + (member2)) % (bit_count / word_bits + !!(bit_count % word_bits))]; \
	v_state[3] = well ## lower_name ## c->state[index[3] = (well ## lower_name ## c->index + (member3)) % (bit_count / word_bits + !!(bit_count % word_bits))]; \
	v_state[4] = well ## lower_name ## c->state[index[4] = (well ## lower_name ## c->index + (bit_count / word_bits + !!(bit_count % word_bits)) - 1) % (bit_count / word_bits + !!(bit_count % word_bits))]; \
	if ((bit_count) % (word_bits) == 0) \
		z_state[0] = v_state[4]; \
	else \
		z_state[0] = (v_state[4] & ((~0) >> MASTER_WRAP((word_bits) - ((bit_count) % (word_bits)), word_bits))) | (well ## lower_name ## c->state[(well ## lower_name ## c->index + (bit_count / word_bits + !!(bit_count % word_bits)) - 2) % (bit_count / word_bits + !!(bit_count % word_bits))] & (~((~0) >> MASTER_WRAP((word_bits) - ((bit_count) % (word_bits)), word_bits)))); \
	z_state[1] = MASTER_RANDOMLIB_WELL_FALL_FALL_ ## func0( (v_state[0] MASTER_RANDOMLIB_WELL_UNARG_ ## func0, word_bits) ) ^ MASTER_RANDOMLIB_WELL_FALL_FALL_ ## func1( (v_state[1] MASTER_RANDOMLIB_WELL_UNARG_ ## func1, word_bits) ); \
	z_state[2] = MASTER_RANDOMLIB_WELL_FALL_FALL_ ## func2( (v_state[2] MASTER_RANDOMLIB_WELL_UNARG_ ## func2, word_bits) ) ^ MASTER_RANDOMLIB_WELL_FALL_FALL_ ## func3( (v_state[3] MASTER_RANDOMLIB_WELL_UNARG_ ## func3, word_bits) ); \
	z_state[3] = z_state[1] ^ z_state[2]; \
	z_state[4] = MASTER_RANDOMLIB_WELL_FALL_FALL_ ## func4( (z_state[0] MASTER_RANDOMLIB_WELL_UNARG_ ## func4, word_bits) ) ^ MASTER_RANDOMLIB_WELL_FALL_FALL_ ## func5( (z_state[1] MASTER_RANDOMLIB_WELL_UNARG_ ## func5, word_bits) ) ^ MASTER_RANDOMLIB_WELL_FALL_FALL_ ## func6( (z_state[2] MASTER_RANDOMLIB_WELL_UNARG_ ## func6, word_bits) ) ^ MASTER_RANDOMLIB_WELL_FALL_FALL_ ## func7( (z_state[3] MASTER_RANDOMLIB_WELL_UNARG_ ## func7, word_bits) ); \
	well ## lower_name ## c->state[index[0]] = z_state[3]; \
	well ## lower_name ## c->state[index[4]] = z_state[4] & (((bit_count) % (word_bits) == 0) ? (~0) : ((~0) >> ((word_bits) - ((bit_count) % (word_bits))))); \
	well ## lower_name ## c->index = index[4]; \
	result = well ## lower_name ## c->state[well ## lower_name ## c->index]; \
	if ((b_constant) != 0 && (c_constant) != 0) { \
		result ^= (result << 7) & (b_constant); \
		result ^= (result << 15) & (c_constant); \
	} \
	if (output != nul) \
		*output = result; \
	return result; \
}

#define MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( upper_name, lower_name, bit_count, word_bits, member1, member2, member3, func0, func1, func2, func3, func4, func5, func6, func7 ) MASTER_RANDOMLIB_CREATE_WELL_PACKAGE(upper_name, lower_name, bit_count, word_bits, member1, member2, member3, 0, 0, func0, func1, func2, func3, func4, func5, func6, func7)

#if MASTER_RANDOMLIB_WELL_FAMILY_IMPLEMENT == 1

const UI4
MASTER_Randomlib_WELL_AConstants[7] = {
	0xDA442D24, 0xD3E43FFD, 0x8BDCB91E, 0x86A9D87E,
	0xA8C296D1, 0x5D6B45CC, 0xB729FCEC
};

MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 512A, 512a, 512, 32,
	13, 9, 5,
	M3(-16), M3(-15), M3(11),  M0(),
	M3(-2),  M3(-18), M3(-28), M5(-5, 0xDA442D24) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 521A, 521a, 521, 32,
	13, 11, 10,
	M3(-13), M3(-15), M1(), M2(-21),
	M3(-13), M2(1),   M0(), M3(11) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 521B, 521b, 521, 32,
	11, 10, 7,
	M3(-21), M3(6),   M0(),   M3(-13),
	M3(13),  M2(-10), M2(-5), M3(13) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 607A, 607a, 607, 32,
	16, 15, 14,
	M3(19), M3(11), M3(-14), M1(),
	M3(18), M1(),   M0(),	M3(-5) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 607B, 607b, 607, 32,
	16, 8, 13,
	M3(-18), M3(-14), M0(),   M3(18),
	M3(-24), M3(5),   M3(-1), M0() )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 800A, 800a, 800, 32,
	14, 18, 16,
	M1(),   M3(-15), M3(10), M3(-11),
	M3(16), M2(20),  M1(),   M3(-28) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 800B, 800b, 800, 32,
	9, 4, 22,
	M3(-29), M2(-14), M1(),									M2(19),
	M1(),	M3(10),  M4(MASTER_Randomlib_WELL_AConstants[1]), M3(-25) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 1024A, 1024a, 1024, 32,
	3, 24, 10,
	M1(),	M3(8),  M3(-19), M3(-14),
	M3(-11), M3(-7), M3(-13), M0() )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 1024B, 1024b, 1024, 32,
	22, 25, 26,
	M3(-21), M3(17),  M4(MASTER_Randomlib_WELL_AConstants[2]), M3(15),
	M3(-14), M3(-21), M1(),									M0() )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 19937A, 19937a, 19937, 32,
	70, 179, 449,
	M3(-25), M3(27), M2(9),   M3(1),
	M1(),	M3(-9), M3(-21), M3(21) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 19937B, 19937b, 19937, 32,
	203, 613, 123,
	M3(7),   M1(),	M3(12), M3(-10),
	M3(-19), M2(-11), M3(4),  M3(-10) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE( 19937C, 19937c, 19937, 32,
	70, 179, 449,
	0xE46E1700, 0x9B868000,
	M3(-25), M3(27), M2(9),   M3(1),
	M1(),	M3(-9), M3(-21), M3(21) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 21701A, 21701a, 21701, 32,
	151, 327, 84,
	M1(),   M3(-26), M3(19),											  M0(),
	M3(27), M3(-11), M6(15, 10, 27, MASTER_Randomlib_WELL_AConstants[3]), M3(-16) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 23209A, 23209a, 23209, 32,
	667, 43, 462,
	M3(28), M1(),	M3(18),  M3(3),
	M3(21), M3(-17), M3(-28), M3(-1) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 23209B, 23209b, 23209, 32,
	610, 175, 662,
	M4(MASTER_Randomlib_WELL_AConstants[4]), M1(), M6(15, 30, 15, MASTER_Randomlib_WELL_AConstants[5]), M3(-24),
	M3(-26), M1(), M0(), M3(16) )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE_NO_TAMPERING( 44497A, 44497a, 44497, 32,
	23, 481, 229,
	M3(-24), M3(30), M3(-10), M2(-26),
	M1(),	M3(20), M6(9, 14, 5, MASTER_Randomlib_WELL_AConstants[6]), M1() )
MASTER_RANDOMLIB_CREATE_WELL_PACKAGE( 44497B, 44497b, 44497, 32,
	23, 481, 229,
	0x93DD1400, 0xFA118000,
	M3(-24), M3(30), M3(-10), M2(-26),
	M1(),	M3(20), M6(9, 14, 5, MASTER_Randomlib_WELL_AConstants[6]), M1() )

#endif /* #! WELL !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_RANDOMLIB_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_RANDOMLIB_INCLUDE_H !# */

/* #! be master !# */
