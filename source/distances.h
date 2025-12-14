
/*
 * Copyright (c) 2025 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_DISTANCES_INCLUDE_H__
#define __MASTER_DISTANCES_INCLUDE_H__ (MASTER_LIBRARY_TESTING + \
										MASTER_LIBRARY_INCREMENTHATE + \
										MASTER_LIBRARY_FiCViN + \
										MASTER_LIBRARY_KAIRARGS + \
										MASTER_LIBRARY_GRAPHSHATE + \
										MASTER_LIBRARY_FREESTANDING)

#include <master_enum.h>

MASTER_PREFER_EXTERN UI4 MASTER_Distance_HammingRaw( const UI1 * const, const UI4, const UI1 * const, const UI4 );
MASTER_PREFER_EXTERN MASTER_PREFER_INLINE UI4 MASTER_Distance_Hamming( const char * const, const char * const );
MASTER_PREFER_EXTERN UI4 MASTER_Distance_BitHammingRaw( const UI1 * const, const UI4, const UI1 * const, const UI4 );
MASTER_PREFER_EXTERN MASTER_PREFER_INLINE UI4 MASTER_Distance_BitHamming( const char * const, const char * const );
MASTER_PREFER_EXTERN MASTER_PREFER_STATIC UI4 MASTER_Distance_Levenshtein_( const UI1 * const, const UI4, const UI1 * const, const UI4 );
MASTER_PREFER_EXTERN UI4 MASTER_Distance_LevenshteinRaw( const UI1 * const, const UI4, const UI1 * const, const UI4 );
MASTER_PREFER_EXTERN MASTER_PREFER_INLINE UI4 MASTER_Distance_Levenshtein( const char * const, const char * const );

UI4
MASTER_Distance_HammingRaw( bytes1, length1, bytes2, length2 )
	const UI1 * const bytes1;
	const UI4 length1;
	const UI1 * const bytes2;
	const UI4 length2;
{
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

MASTER_PREFER_INLINE UI4
MASTER_Distance_Hamming( string1, string2 )
	const char * const string1;
	const char * const string2;
{
	return MASTER_Distance_HammingRaw((UI1 *)string1, MASTER_CPRLEN(string1), (UI1 *)string2, MASTER_CPRLEN(string2));
}

MASTER_PREFER_INLINE UI1
MASTER_CountOnes( UI4 number ) {
	UI1 res = 0;
	while (number > 0) {
		if (number & 1) res += 1;
		number >>= 1;
	}
	return res;
}

UI4
MASTER_Distance_BitHammingRaw( bytes1, length1, bytes2, length2 )
	const UI1 * const bytes1;
	const UI4 length1;
	const UI1 * const bytes2;
	const UI4 length2;
{
	UI4 score = 0;
	UI4 index = 0;
	if (bytes1 == nul || length1 == 0) return length2;
	if (bytes2 == nul || length2 == 0) return length1;
	if (length1 != length2) return -1;
	for (; index < length1; index += 1)
		score += MASTER_CountOnes(bytes1[index] ^ bytes2[index]);
	return score;
}

MASTER_PREFER_INLINE UI4
MASTER_Distance_BitHamming( string1, string2 )
	const char * const string1;
	const char * const string2;
{
	return MASTER_Distance_BitHammingRaw((UI1 *)string1, MASTER_CPRLEN(string1), (UI1 *)string2, MASTER_CPRLEN(string2));
}

MASTER_PREFER_STATIC UI4
MASTER_Distance_Levenshtein_( bytes1, length1, bytes2, length2 )
	const UI1 * const bytes1;
	const UI4 length1;
	const UI1 * const bytes2;
	const UI4 length2;
{
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
	upperRaw = MASTER_MALLOC((length1 + 1) * sizeof(UI4));
	lowerRaw = MASTER_MALLOC((length1 + 1) * sizeof(UI4));
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

UI4
MASTER_Distance_LevenshteinRaw( bytes1, length1, bytes2, length2 )
	const UI1 * const bytes1;
	const UI4 length1;
	const UI1 * const bytes2;
	const UI4 length2;
{
	if (length1 < length2)
		return MASTER_Distance_Levenshtein_(bytes1, length1, bytes2, length2);
	return MASTER_Distance_Levenshtein_(bytes2, length2, bytes1, length1);
}

MASTER_PREFER_INLINE UI4
MASTER_Distance_Levenshtein( string1, string2 )
	const char * const string1;
	const char * const string2;
{
	return MASTER_Distance_LevenshteinRaw((UI1 *)string1, MASTER_CPRLEN(string1), (UI1 *)string2, MASTER_CPRLEN(string2));
}

#endif /* #! __MASTER_DISTANCES_INCLUDE_H__ !# */

/* #! be master~ !# */
