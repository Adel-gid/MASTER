
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_MASMATH_INCLUDE_H
#define MASTER_zRIVATE_MASMATH_INCLUDE_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

#define MASTER_PI 3.14159265358973238462643383279502884197169399375105820974944

#ifdef MASTER_LIBRARY_HAVE_MATH_H
#	include <math.h>
#	define MASTER_MATH_ABS abs
#	define MASTER_MATH_LABS labs
#	define MASTER_MATH_LLABS llabs
#	define MASTER_MATH_FABS fabs
#	define MASTER_MATH_DIV div
#	define MASTER_MATH_LDIV ldiv
#	define MASTER_MATH_LLDIV lldiv
#	define MASTER_MATH_FMOD fmod
#	define MASTER_MATH_REMAINDER remainder
#	define MASTER_MATH_REMQUO remquo
#	define MASTER_MATH_FMA fma
#	define MASTER_MATH_FMAX fmax
#	define MASTER_MATH_FMIN fmin
#	define MASTER_MATH_FDIM fdim
#	define MASTER_MATH_NAN nan
#	define MASTER_MATH_NANF nanf
#	define MASTER_MATH_NANL nanl
#	define MASTER_MATH_EXP exp
#	define MASTER_MATH_EXP2 exp2
#	define MASTER_MATH_EXPM1 expm1
#	define MASTER_MATH_LOG log
#	define MASTER_MATH_LOG2 log2
#	define MASTER_MATH_LOG10 log10
#	define MASTER_MATH_LOG1P log1p
#	define MASTER_MATH_ILOGB ilogb
#	define MASTER_MATH_LOGB logb
#	define MASTER_MATH_SQRT sqrt
#	define MASTER_MATH_CBRT cbrt
#	define MASTER_MATH_HYPOT hypot
#	define MASTER_MATH_POW pow
#	define MASTER_MATH_SIN sin
#	define MASTER_MATH_COS cos
#	define MASTER_MATH_TAN tan
#	define MASTER_MATH_ASIN asin
#	define MASTER_MATH_ACOS acos
#	define MASTER_MATH_ATAN atan
#	define MASTER_MATH_ATAN2 atan2
#	define MASTER_MATH_SINH sinh
#	define MASTER_MATH_COSH cosh
#	define MASTER_MATH_TANH tanh
#	define MASTER_MATH_ASINH asinh
#	define MASTER_MATH_ACOSH acosh
#	define MASTER_MATH_ATANH atanh
#	define MASTER_MATH_ERF erf
#	define MASTER_MATH_ERFC erfc
#	define MASTER_MATH_LGAMMA lgamma
#	define MASTER_MATH_TGAMMA tgamma
#	define MASTER_MATH_CEIL ceil
#	define MASTER_MATH_FLOOR floor
#	define MASTER_MATH_TRUNC trunc
#	define MASTER_MATH_ROUND round
#	define MASTER_MATH_LROUND lround
#	define MASTER_MATH_LLROUND llround
#	define MASTER_MATH_NEARBYINT nearbyint
#	define MASTER_MATH_RINT rint
#	define MASTER_MATH_LRINT lrint
#	define MASTER_MATH_LLRINT llrint
#	define MASTER_MATH_FREXP frexp
#	define MASTER_MATH_LDEXP ldexp
#	define MASTER_MATH_MODF modf
#	define MASTER_MATH_SCALBN scalbn
#	define MASTER_MATH_SCALBLN scalbln
#	define MASTER_MATH_NEXTAFTER nextafter
#	define MASTER_MATH_NEXTTOWARD nexttoward
#	define MASTER_MATH_COPYSIGN copysign
#	define MASTER_MATH_FPCLASSIFY fpclassify
#	define MASTER_MATH_ISFINITE isfinite
#	define MASTER_MATH_ISINF isinf
#	define MASTER_MATH_ISNAN isnan
#	define MASTER_MATH_ISNORMAL isnormal
#	define MASTER_MATH_SIGNBIT signbit
#else
#	error "math.h must be provided. Library does not have his own implementation"
#endif /* #! math.h !# */

#define MASTER_MATH_CAS( value ) (MASTER_MATH_COS(value) + MASTER_MATH_SIN(value))

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Math_DCT_I, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Math_DCT_II, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Math_DCT_III, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Math_DCT_IV, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, void, MASTER_Math_DHT, (const UF * const MASTER_PREFER_RESTRICT, const MASTER_maxint, UF * const MASTER_PREFER_RESTRICT) );

MASTER_MARKER_NAIVE void
MASTER_Math_DCT_I( const UF * const MASTER_PREFER_RESTRICT floatData, const MASTER_maxint length, UF * const MASTER_PREFER_RESTRICT outputData ) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (; index < length; index += 1) {
		result = 0.5 * (floatData[0] + floatData[length - 1] * MASTER_PARITYSIGN(index));
		for (jndex = 1; jndex < length - 1; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_COS(MASTER_PI / (UF)(length - 1) * (UF)index * (UF)jndex);
		outputData[index] = result;
	}
}

MASTER_MARKER_NAIVE void
MASTER_Math_DCT_II( const UF * const MASTER_PREFER_RESTRICT floatData, const MASTER_maxint length, UF * const MASTER_PREFER_RESTRICT outputData ) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (; index < length; index += 1) {
		result = 0;
		for (jndex = 0; jndex < length; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_COS(MASTER_PI / (UF)length * (UF)index * ((UF)jndex + 0.5));
		outputData[index] = result;
	}
}

MASTER_MARKER_NAIVE void
MASTER_Math_DCT_III( const UF * const MASTER_PREFER_RESTRICT floatData, const MASTER_maxint length, UF * const MASTER_PREFER_RESTRICT outputData ) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (; index < length; index += 1) {
		result = 0.5 * floatData[0];
		for (jndex = 1; jndex < length; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_COS(MASTER_PI / (UF)length * ((UF)index + 0.5) * (UF)jndex);
		outputData[index] = result;
	}
}

MASTER_MARKER_NAIVE void
MASTER_Math_DCT_IV( const UF * const MASTER_PREFER_RESTRICT floatData, const MASTER_maxint length, UF * const MASTER_PREFER_RESTRICT outputData ) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (; index < length; index += 1) {
		result = 0;
		for (jndex = 0; jndex < length; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_COS(MASTER_PI / (UF)length * ((UF)index + 0.5) * ((UF)jndex + 0.5));
		outputData[index] = result;
	}
}

MASTER_MARKER_NAIVE void
MASTER_Math_DHT( const UF * const MASTER_PREFER_RESTRICT floatData, const MASTER_maxint length, UF * const MASTER_PREFER_RESTRICT outputData ) {
	MASTER_maxint index = 0;
	MASTER_maxint jndex;
	UF result;
	if (MASTER_PREFER_UNLIKELY(floatData == nul || outputData == 0)) return;
	for (; index < length; index += 1) {
		result = 0;
		for (jndex = 0; jndex < length; jndex += 1)
			result += floatData[jndex] * MASTER_MATH_CAS(2.0 * MASTER_PI / (UF)length * (UF)index * (UF)jndex);
		outputData[index] = result;
	}
}

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_MASMATH_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_MASMATH_INCLUDE_H !# */

/* #! be master~ !# */
