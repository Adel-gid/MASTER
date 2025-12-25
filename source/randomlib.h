
/*
 * Copyright (c) 2025 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_RANDOMLIB_INCLUDE_H__
#define __MASTER_RANDOMLIB_INCLUDE_H__

#include <master_enum.h>

/* #! Xorshift !# */

typedef struct {
	UI4 state;
} MASTER_Randomlib_xorshift32;

UI4
MASTER_Randomlib_xorshift32_Next( MASTER_Randomlib_xorshift32 * const xs32c, UI4 * const out ) {
	if (xs32c == nul) return 0;
	xs32c->state ^= xs32c->state << 13;
	xs32c->state ^= xs32c->state >> 17;
	xs32c->state ^= xs32c->state << 5;
	if (out != nul)
		*out = xs32c->state;
	return xs32c->state;
}

/* #! Jump 1.000, 1.000.000, 1.000.000.000 !# */

typedef struct {
	UI8 state;
} MASTER_Randomlib_xorshift64;

#include <string.h>

UI4
MASTER_Randomlib_xorshift64_Next( MASTER_Randomlib_xorshift64 * const xs64c, UI8 * const out ) {
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
		memcpy(out, xs64c->state, sizeof(UI8));
	return xs64c->state[0];
#else
	#error "User type of UI8, nor the array, is not supporting on the current time."
#endif /* #! MASTER_UI8_TYPE !# */
}

/* #! Jump 1.000, 1.000.000, 1.000.000.000, 1E+12, 1E+15, 1E+18 !# */

#endif /* #! __MASTER_RANDOMLIB_INCLUDE_H__ !# */

/* #! be master !# */
