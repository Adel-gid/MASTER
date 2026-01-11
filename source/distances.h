
/*
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_DISTANCES_INCLUDE_H__
#define __MASTER_DISTANCES_INCLUDE_H__

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#ifdef MASTER_DISTANCES_EXTERN_ONLY
#	define MASTER_DISTANCES_HAMMING_IMPLEMENT 0
#	define MASTER_DISTANCES_BITHAMMING_IMPLEMENT 0
#	define MASTER_DISTANCES_LEVENSHTEIN_IMPLEMENT 0
#else
#	if defined(MASTER_DISTANCES_HAMMING_USE) || \
	   defined(MASTER_DISTANCES_BITHAMMING_USE) || \
	   defined(MASTER_DISTANCES_LEVENSHTEIN_USE)
#		define MASTER_DISTANCES_WHITELIST_MODE 1
#	else
#		define MASTER_DISTANCES_WHITELIST_MODE 0
#	endif /* #! Whitelist Setting !# */
#	ifdef MASTER_DISTANCES_HAMMING_EXTERN
#		define MASTER_DISTANCES_HAMMING_IMPLEMENT 0
#		ifdef MASTER_DISTANCES_HAMMING_USE
#			warning "Hamming is defined to USE, but also defined to EXTERN. Hamming will NOT be compiled."
#		endif /* #! Hamming Conflict of Use & Extern !# */
#	elif MASTER_DISTANCES_WHITELIST_MODE == 1
#		ifdef MASTER_DISTANCES_HAMMING_USE
#			define MASTER_DISTANCES_HAMMING_IMPLEMENT 1
#		else
#			define MASTER_DISTANCES_HAMMING_IMPLEMENT 0
#		endif /* #! Hamming Use !# */
#	else
#		define MASTER_DISTANCES_HAMMING_IMPLEMENT 1
#	endif /* #! Hamming !# */
#	ifdef MASTER_DISTANCES_BITHAMMING_EXTERN
#		define MASTER_DISTANCES_BITHAMMING_IMPLEMENT 0
#		ifdef MASTER_DISTANCES_BITHAMMING_USE
#			warning "BitHamming is defined to USE, but also defined to EXTERN. BitHamming will NOT be compiled."
#		endif /* #! BitHamming Conflict of Use & Extern !# */
#	elif MASTER_DISTANCES_WHITELIST_MODE == 1
#		ifdef MASTER_DISTANCES_BITHAMMING_USE
#			define MASTER_DISTANCES_BITHAMMING_IMPLEMENT 1
#		else
#			define MASTER_DISTANCES_BITHAMMING_IMPLEMENT 0
#		endif /* #! BitHamming Use !# */
#	else
#		define MASTER_DISTANCES_BITHAMMING_IMPLEMENT 1
#	endif /* #! BitHamming !# */
#	ifdef MASTER_DISTANCES_LEVENSHTEIN_EXTERN
#		define MASTER_DISTANCES_LEVENSHTEIN_IMPLEMENT 0
#		ifdef MASTER_DISTANCES_LEVENSHTEIN_USE
#			warning "Levenshtein is defined to USE, but also defined to EXTERN. Levenshtein will NOT be compiled."
#		endif /* #! Levenshtein Conflict of Use & Extern !# */
#	elif MASTER_DISTANCES_WHITELIST_MODE == 1
#		ifdef MASTER_DISTANCES_LEVENSHTEIN_USE
#			define MASTER_DISTANCES_LEVENSHTEIN_IMPLEMENT 1
#		else
#			define MASTER_DISTANCES_LEVENSHTEIN_IMPLEMENT 0
#		endif /* #! Levenshtein Use !# */
#	else
#		define MASTER_DISTANCES_LEVENSHTEIN_IMPLEMENT 1
#	endif /* #! Levenshtein !# */
#	undef MASTER_DISTANCES_WHITELIST_MODE
#endif /* #! MASTER_DISTANCES_EXTERN_ONLY !# */

/* #! Hamming !# */

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Distance_HammingRaw, ( const UI1 * const, const UI4, const UI1 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_PREFER_INLINE UI4, MASTER_Distance_Hamming, ( const char * const, const char * const ) );

#if MASTER_DISTANCES_HAMMING_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Distance_HammingRaw /* ! */,
	UI4,
	( const UI1 * const, bytes1 ),
	( const UI4, length1 ),
	( const UI1 * const, bytes2 ),
	( const UI4, length2 )
) {
	UI4 score = 0;
	UI4 index = 0;
	if (bytes1 == nul || length1 == 0) return length2;
	if (bytes2 == nul || length2 == 0) return length1;
	if (length1 != length2) return -1;
	for (; index < length1; index += 1)
		if (bytes1[index] != bytes2[index])
			score += 1;
	return score;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Distance_Hamming /* ! */,
	UI4,
	( const char * const, string1 ),
	( const char * const, string2 )
) {
	return MASTER_Distance_HammingRaw((const UI1 *)string1, MASTER_CPRLEN(string1), (const UI1 *)string2, MASTER_CPRLEN(string2));
}

#endif /* #! Hamming !# */

MASTER_PREFER_STATIC MASTER_PREFER_INLINE UI1
MASTER_CountOnes( UI4 number ) {
	UI1 res = 0;
	while (number > 0) {
		if (number & 1) res += 1;
		number >>= 1;
	}
	return res;
}

/* #! Bit Hamming !# */

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_Distance_BitHammingRaw, ( const UI1 * const, const UI4, const UI1 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_PREFER_INLINE UI4, MASTER_Distance_BitHamming, ( const char * const, const char * const ) );

#if MASTER_DISTANCES_BITHAMMING_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Distance_BitHammingRaw /* ! */,
	UI4,
	( const UI1 * const, bytes1 ),
	( const UI4, length1 ),
	( const UI1 * const, bytes2 ),
	( const UI4, length2 )
) {
	UI4 score = 0;
	UI4 index = 0;
	if (bytes1 == nul || length1 == 0) return length2;
	if (bytes2 == nul || length2 == 0) return length1;
	if (length1 != length2) return -1;
	for (; index < length1; index += 1)
		score += MASTER_CountOnes(bytes1[index] ^ bytes2[index]);
	return score;
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Distance_BitHamming /* ! */,
	UI4,
	( const char * const, string1 ),
	( const char * const, string2 )
) {
	return MASTER_Distance_BitHammingRaw((const UI1 *)string1, MASTER_CPRLEN(string1), (const UI1 *)string2, MASTER_CPRLEN(string2));
}

#endif /* #! Bit Hamming !# */

/* #! Levenshtein !# */

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4,  MASTER_Distance_LevenshteinRaw, ( const UI1 * const, const UI4, const UI1 * const, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, MASTER_PREFER_INLINE UI4, MASTER_Distance_Levenshtein, ( const char * const, const char * const ) );

#if MASTER_DISTANCES_LEVENSHTEIN_IMPLEMENT == 1

MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Distance_Levenshtein_ /* ! */,
	MASTER_PREFER_STATIC UI4,
	( const UI1 * const, bytes1 ),
	( const UI4, length1 ),
	( const UI1 * const, bytes2 ),
	( const UI4, length2 )
) {
	/* #! length1 <= length2 !# */
	UI4 * upperRaw;
	UI4 * lowerRaw;
	UI4 * tempRaw;
	UI4 score1;
	UI4 score2;
	UI4 score3;
	UI4 index;
	UI4 jndex;
	if (bytes1 == nul || length1 == 0) return length2;
	if (bytes2 == nul || length2 == 0) return length1;
	upperRaw = (UI4 *)MASTER_MALLOC((length1 + 1) * sizeof(UI4));
	lowerRaw = (UI4 *)MASTER_MALLOC((length1 + 1) * sizeof(UI4));
	for (index = 0; index <= length1; index += 1)
		upperRaw[index] = index;
	for (index = 0; index < length2; index += 1) {
		lowerRaw[0] = index + 1;
		for (jndex = 0; jndex < length1; jndex += 1) {
			if (bytes1[jndex] == bytes2[index]) {
				lowerRaw[1 + jndex] = upperRaw[jndex];
				continue;
			}
			score1 = upperRaw[1 + jndex];
			score2 = lowerRaw[jndex];
			score3 = upperRaw[jndex];
			lowerRaw[1 + jndex] = 1 + MASTER_MIN(score1, MASTER_MIN(score2, score3));
		}
		tempRaw = upperRaw;
		upperRaw = lowerRaw;
		lowerRaw = tempRaw;
	}
	score1 = upperRaw[length1];
	MASTER_FREE(upperRaw);
	MASTER_FREE(lowerRaw);
	return score1;
}

MASTER_DEFINE_FUNCTION4(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Distance_LevenshteinRaw /* ! */,
	UI4,
	( const UI1 * const, bytes1 ),
	( const UI4, length1 ),
	( const UI1 * const, bytes2 ),
	( const UI4, length2 )
) {
	if (length1 < length2)
		return MASTER_Distance_Levenshtein_(bytes1, length1, bytes2, length2);
	return MASTER_Distance_Levenshtein_(bytes2, length2, bytes1, length1);
}

MASTER_DEFINE_FUNCTION2(
	MASTER_NO_FLAGS,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Distance_Levenshtein /* ! */,
	UI4,
	( const char * const, string1 ),
	( const char * const, string2 )
) {
	return MASTER_Distance_LevenshteinRaw((const UI1 *)string1, MASTER_CPRLEN(string1), (const UI1 *)string2, MASTER_CPRLEN(string2));
}

#endif /* #! Levenshtein !# */

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 __MASTER_DISTANCES_INCLUDE_H_LAST_LINE__ = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! __MASTER_DISTANCES_INCLUDE_H__ !# */

/* #! be master~ !# */
