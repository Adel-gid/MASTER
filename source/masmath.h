
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_MASMATH_H
#define MASTER_zzz_MASMATH_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#define MASTER_PI 3.14159265358973238462643383279502884197169399375105820974944

#define MASTER_MATH_CAS( value ) (MASTER_MATH_COS(value) + MASTER_MATH_SIN(value))

MASTER_EXTERN_FUNCTION( MASTER_MARKER_NAIVE, void, MASTER_Math_DCT_I, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );
MASTER_EXTERN_FUNCTION( MASTER_MARKER_NAIVE, void, MASTER_Math_DCT_II, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );
MASTER_EXTERN_FUNCTION( MASTER_MARKER_NAIVE, void, MASTER_Math_DCT_III, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );
MASTER_EXTERN_FUNCTION( MASTER_MARKER_NAIVE, void, MASTER_Math_DCT_IV, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );
MASTER_EXTERN_FUNCTION( MASTER_MARKER_NAIVE, void, MASTER_Math_DHT, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );

MASTER_DEFINE_FUNCTION3(
	MASTER_MARKER_NAIVE,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Math_DCT_I /* ! */,
	void,
	( const UF * const MASTER_PREFER_RESTRICT, floatData ),
	( const MASTER_maxint, length ),
	( UF * const MASTER_PREFER_RESTRICT, outputData )
) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (/* #! Inited above !# */; index < length; index += 1) {
		result = 0.5 * (floatData[0] + floatData[length - 1] * (UF)MASTER_PARITYSIGN(index));
		for (jndex = 1; jndex < length - 1; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_COS(MASTER_PI / (UF)(length - 1) * (UF)index * (UF)jndex);
		outputData[index] = result;
	}
}

MASTER_DEFINE_FUNCTION3(
	MASTER_MARKER_NAIVE,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Math_DCT_II /* ! */,
	void,
	( const UF * const MASTER_PREFER_RESTRICT, floatData ),
	( const MASTER_maxint, length ),
	( UF * const MASTER_PREFER_RESTRICT, outputData )
) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (/* #! Inited above !# */; index < length; index += 1) {
		result = 0;
		for (jndex = 0; jndex < length; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_COS(MASTER_PI / (UF)length * (UF)index * ((UF)jndex + 0.5));
		outputData[index] = result;
	}
}

MASTER_DEFINE_FUNCTION3(
	MASTER_MARKER_NAIVE,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Math_DCT_III /* ! */,
	void,
	( const UF * const MASTER_PREFER_RESTRICT, floatData ),
	( const MASTER_maxint, length ),
	( UF * const MASTER_PREFER_RESTRICT, outputData )
) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (/* #! Inited above !# */; index < length; index += 1) {
		result = 0.5 * floatData[0];
		for (jndex = 1; jndex < length; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_COS(MASTER_PI / (UF)length * ((UF)index + 0.5) * (UF)jndex);
		outputData[index] = result;
	}
}

MASTER_DEFINE_FUNCTION3(
	MASTER_MARKER_NAIVE,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Math_DCT_IV /* ! */,
	void,
	( const UF * const MASTER_PREFER_RESTRICT, floatData ),
	( const MASTER_maxint, length ),
	( UF * const MASTER_PREFER_RESTRICT, outputData )
) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (/* #! Inited above !# */; index < length; index += 1) {
		result = 0;
		for (jndex = 0; jndex < length; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_COS(MASTER_PI / (UF)length * ((UF)index + 0.5) * ((UF)jndex + 0.5));
		outputData[index] = result;
	}
}

MASTER_DEFINE_FUNCTION3(
	MASTER_MARKER_NAIVE,
	MASTER_EMPTY_DESCRIPTION,
	/* ! */ MASTER_Math_DHT /* ! */,
	void,
	( const UF * const MASTER_PREFER_RESTRICT, floatData ),
	( const MASTER_maxint, length ),
	( UF * const MASTER_PREFER_RESTRICT, outputData )
) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (/* #! Inited above !# */; index < length; index += 1) {
		result = 0;
		for (jndex = 0; jndex < length; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_CAS(2.0 * MASTER_PI / (UF)length * (UF)index * (UF)jndex);
		outputData[index] = result;
	}
}

MASTER_END_DECLARATIONS

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zzz_MASMATH_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zzz_MASMATH_H !# */

/* #! be master~ !# */
