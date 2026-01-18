
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zRIVATE_SIMD_DETECT_INCLUDE_H
#define MASTER_zRIVATE_SIMD_DETECT_INCLUDE_H

#include <master_enum.h>

MASTER_BEGIN_DECLARATIONS

/* #! SIMD !# */

/* #! MMX !# */
#ifdef __MMX__
#	define MASTER_FUTURE_MMX 1
#else
#	define MASTER_FUTURE_MMX 0
#endif /* #! __MMX__ !# */

/* #! 3DNow! !# */
#if defined(__3dNOW__) || defined(__3DNOW__) || defined(__3dNOWEXT__)
#	define MASTER_FUTURE_3DNOW 1
#else
#	define MASTER_FUTURE_3DNOW 0
#endif /* #! 3DNow! !# */

/* #! SSE family !# */
#ifdef __SSE__
#	define MASTER_FUTURE_SSE 1
#else
#	define MASTER_FUTURE_SSE 0
#endif /* #! __SSE__ !# */

#if defined(__SSE2__) || defined (_M_AMD64) || (defined(_M_IX86_FP) && _M_IX86_FP + 0 >= 2)
#	define MASTER_FUTURE_SSE2 1
#else
#	define MASTER_FUTURE_SSE2 0
#endif /* #! __SSE2__ !# */

#ifdef __SSE3__
#	define MASTER_FUTURE_SSE3 1
#else
#	define MASTER_FUTURE_SSE3 0
#endif /* #! __SSE3__ !# */

#ifdef __SSSE3__
#	define MASTER_FUTURE_SSSE3 1
#else
#	define MASTER_FUTURE_SSSE3 0
#endif /* #! __SSSE3__ !# */

#ifdef __SSE4_1__
#	define MASTER_FUTURE_SSE4_1 1
#else
#	define MASTER_FUTURE_SSE4_1 0
#endif /* #! __SSE4_1__ !# */

#ifdef __SSE4_2__
#	define MASTER_FUTURE_SSE4_2 1
#else
#	define MASTER_FUTURE_SSE4_2 0
#endif /* #! __SSE4_2__ !# */

#ifdef __POPCNT__
#	define MASTER_FUTURE_POPCNT 1
#else
#	define MASTER_FUTURE_POPCNT 0
#endif /* #! __POPCNT__ !# */

#ifdef __LZCNT__
#	define MASTER_FUTURE_LZCNT 1
#else
#	define MASTER_FUTURE_LZCNT 0
#endif /* #! __LZCNT__ !# */

/* #! AVX family !# */
#ifdef __AVX__
#	define MASTER_FUTURE_AVX 1
#else
#	define MASTER_FUTURE_AVX 0
#endif /* #! __AVX__ !# */

#ifdef __AVXVNNI__
#	define MASTER_FUTURE_AVX_VNNI 1
#else
#	define MASTER_FUTURE_AVX_VNNI 0
#endif /* #! __AVXVNNI__ !# */

#ifdef __AVX2__
#	define MASTER_FUTURE_AVX2 1
#else
#	define MASTER_FUTURE_AVX2 0
#endif /* #! __AVX2__ !# */

#ifdef __AVX512F__
#	define MASTER_FUTURE_AVX512F 1
#else
#	define MASTER_FUTURE_AVX512F 0
#endif /* #! __AVX512F__ !# */

#ifdef __AVX512DQ__
#	define MASTER_FUTURE_AVX512DQ 1
#else
#	define MASTER_FUTURE_AVX512DQ 0
#endif /* #! __AVX512DQ__ !# */

#ifdef __AVX512IFMA__
#	define MASTER_FUTURE_AVX512IFMA 1
#else
#	define MASTER_FUTURE_AVX512IFMA 0
#endif /* #! __AVX512IFMA__ !# */

#ifdef __AVX512PF__
#	define MASTER_FUTURE_AVX512PF 1
#else
#	define MASTER_FUTURE_AVX512PF 0
#endif /* #! __AVX512PF__ !# */

#ifdef __AVX512ER__
#	define MASTER_FUTURE_AVX512ER 1
#else
#	define MASTER_FUTURE_AVX512ER 0
#endif /* #! __AVX512ER__ !# */

#ifdef __AVX512CD__
#	define MASTER_FUTURE_AVX512CD 1
#else
#	define MASTER_FUTURE_AVX512CD 0
#endif /* #! __AVX512CD__ !# */

#ifdef __AVX512BW__
#	define MASTER_FUTURE_AVX512BW 1
#else
#	define MASTER_FUTURE_AVX512BW 0
#endif /* #! __AVX512BW__ !# */

#ifdef __AVX512VL__
#	define MASTER_FUTURE_AVX512VL 1
#else
#	define MASTER_FUTURE_AVX512VL 0
#endif /* #! __AVX512VL__ !# */

#ifdef __AVX512VBMI__
#	define MASTER_FUTURE_AVX512VBMI 1
#else
#	define MASTER_FUTURE_AVX512VBMI 0
#endif /* #! __AVX512VBMI__ !# */

#ifdef __AVX512VNNI__
#	define MASTER_FUTURE_AVX512VNNI 1
#else
#	define MASTER_FUTURE_AVX512VNNI 0
#endif /* #! __AVX512VNNI__ !# */

#ifdef __AVX512BF16__
#	define MASTER_FUTURE_AVX512BF16 1
#else
#	define MASTER_FUTURE_AVX512BF16 0
#endif /* #! __AVX512BF16__ !# */

#ifdef __AVX512_VPOPCNTDQ__
#	define MASTER_FUTURE_AVX512_VPOPCNTDQ 1
#else
#	define MASTER_FUTURE_AVX512_VPOPCNTDQ 0
#endif /* #! __AVX512_VPOPCNTDQ__ !# */

#ifdef __AVX512_BITALG__
#	define MASTER_FUTURE_AVX512_BITALG 1
#else
#	define MASTER_FUTURE_AVX512_BITALG 0
#endif /* #! __AVX512_BITALG__ !# */

#ifdef __AVX512_VBMI2__
#	define MASTER_FUTURE_AVX512_VBMI2 1
#else
#	define MASTER_FUTURE_AVX512_VBMI2 0
#endif /* #! __AVX512_VBMI2__ !# */

#ifdef __AVX512_VPCLMULQDQ__
#	define MASTER_FUTURE_AVX512_VPCLMULQDQ 1
#else
#	define MASTER_FUTURE_AVX512_VPCLMULQDQ 0
#endif /* #! __AVX512_VPCLMULQDQ__ !# */

#ifdef __AVX512_GFNI__
#	define MASTER_FUTURE_AVX512_GFNI 1
#else
#	define MASTER_FUTURE_AVX512_GFNI 0
#endif /* #! __AVX512_GFNI__ !# */

#ifdef __AVX512_VAES__
#	define MASTER_FUTURE_AVX512_VAES 1
#else
#	define MASTER_FUTURE_AVX512_VAES 0
#endif /* #! __AVX512_VAES__ !# */

#ifdef __AVX512_FP16__
#	define MASTER_FUTURE_AVX512_FP16 1
#else
#	define MASTER_FUTURE_AVX512_FP16 0
#endif /* #! __AVX512_FP16__ !# */

#ifdef __AVX512_4VNNIW__
#	define MASTER_FUTURE_AVX512_4VNNIW 1
#else
#	define MASTER_FUTURE_AVX512_4VNNIW 0
#endif /* #! __AVX512_4VNNIW__ !# */

#ifdef __AVX512_4FMAPS__
#	define MASTER_FUTURE_AVX512_4FMAPS 1
#else
#	define MASTER_FUTURE_AVX512_4FMAPS 0
#endif /* #! __AVX512_4FMAPS__ !# */

#ifdef __AVX512VP2INTERSECT__
#	define MASTER_FUTURE_AVX512_VP2INTERSECT 1
#else
#	define MASTER_FUTURE_AVX512_VP2INTERSECT 0
#endif /* #! __AVX512VP2INTERSECT__ !# */

/* #! FMA, F16C, XOP, TBM, BMI !# */
#ifdef __FMA__
#	define MASTER_FUTURE_FMA 1
#else
#	define MASTER_FUTURE_FMA 0
#endif /* #! __FMA__!# */

#ifdef __FMA4__
#	define MASTER_FUTURE_FMA4 1
#else
#	define MASTER_FUTURE_FMA4 0
#endif /* #! __FMA__!# */

#ifdef __F16C__
#	define MASTER_FUTURE_F16C 1
#else
#	define MASTER_FUTURE_F16C 0
#endif /* #! __F16C__ !# */

#ifdef __XOP__
#	define MASTER_FUTURE_XOP 1
#else
#	define MASTER_FUTURE_XOP 0
#endif /* #! __XOP__ !# */

#ifdef __TBM__
#	define MASTER_FUTURE_TBM 1
#else
#	define MASTER_FUTURE_TBM 0
#endif /* #! __TBM__ !# */

#if defined(__BMI__) || defined(__BMI1__)
#	define MASTER_FUTURE_BMI1 1
#else
#	define MASTER_FUTURE_BMI1 0
#endif /* #! __BMI__ !# */

#ifdef __BMI2__
#	define MASTER_FUTURE_BMI2 1
#else
#	define MASTER_FUTURE_BMI2 0
#endif /* #! __BMI2__ !# */

#ifdef __MOVBE__
#	define MASTER_FUTURE_MOVBE 1
#else
#	define MASTER_FUTURE_MOVBE 0
#endif /* #! __MOVBE__ !# */

#ifdef __ADX__
#	define MASTER_FUTURE_ADX 1
#else
#	define MASTER_FUTURE_ADX 0
#endif /* #! __ADX__ !# */

/* #! AES-NI, PCLMUL, RDRAND, RDSEED !# */
#ifdef __AES__
#	define MASTER_FUTURE_AESNI 1
#else
#	define MASTER_FUTURE_AESNI 0
#endif /* #! __AES__ !# */

#ifdef __PCLMUL__
#	define MASTER_FUTURE_PCLMUL 1
#else
#	define MASTER_FUTURE_PCLMUL 0
#endif /* #! __PCLMUL__ !# */

#ifdef __RDRND__
#	define MASTER_FUTURE_RDRAND 1
#else
#	define MASTER_FUTURE_RDRAND 0
#endif /* #! __RDRND__ !# */

#ifdef __RDSEED__
#	define MASTER_FUTURE_RDSEED 1
#else
#	define MASTER_FUTURE_RDSEED 0
#endif /* #! __RDSEED__ !# */

/* #! ARM AArch32/AArch64 !# */
#if defined(__ARM_NEON) || defined(__ARM_NEON__)
#	define MASTER_FUTURE_NEON 1
#else
#	define MASTER_FUTURE_NEON 0
#endif /* #! __ARM_NEON__ !# */

#ifdef __ARM_FEATURE_CRYPTO
#	define MASTER_FUTURE_ARM_CRYPTO 1
#else
#	define MASTER_FUTURE_ARM_CRYPTO 0
#endif /* #! __ARM_FEATURE_CRYPTO !# */

#ifdef __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
#	define MASTER_FUTURE_ARM_FP16 1
#else
#	define MASTER_FUTURE_ARM_FP16 0
#endif /* #! __ARM_FEATURE_FP16_VECTOR_ARITHMETIC !# */

#ifdef __ARM_FEATURE_SVE
#	define MASTER_FUTURE_SVE 1
#else
#	define MASTER_FUTURE_SVE 0
#endif /* #! __ARM_FEATURE_SVE !# */

#ifdef __ARM_FEATURE_SVE2
#	define MASTER_FUTURE_SVE2 1
#else
#	define MASTER_FUTURE_SVE2 0
#endif /* #! __ARM_FEATURE_SVE2 !# */

/* #! PowerPC AltiVec/VMX !# */
#if defined(__ALTIVEC__) || defined(__VEC__)
#	define MASTER_FUTURE_ALTIVEC 1
#else
#	define MASTER_FUTURE_ALTIVEC 0
#endif /* #! PowerPC AltiVec/VMX !# */

/* #! MIPS MSA !# */
#if defined(__mips_msa) || defined(__MSA__)
#	define MASTER_FUTURE_MSA 1
#else
#	define MASTER_FUTURE_MSA 0
#endif /* #! MIPS MSA !# */

/* #! RISC-V Vector !# */
#ifdef __riscv_vector
#	define MASTER_FUTURE_RISCV_VECTOR 1
#else
#	define MASTER_FUTURE_RISCV_VECTOR 0
#endif /* #! __riscv_vector !# */

/* #! LoongArch SX/ASX !# */
#ifdef __loongarch_sx
#	define MASTER_FUTURE_LOONGARCH_SX 1
#else
#	define MASTER_FUTURE_LOONGARCH_SX 0
#endif /* #! __loongarch_sx !# */

#ifdef __loongarch_asx
#	define MASTER_FUTURE_LOONGARCH_ASX 1
#else
#	define MASTER_FUTURE_LOONGARCH_ASX 0
#endif /* #! __loongarch_asx !# */

/* #! Miscellaneous !# */
#ifdef __CMOV__
#	define MASTER_FUTURE_CMOV 1
#else
#	define MASTER_FUTURE_CMOV 0
#endif /* #! __CMOV__ !# */

#ifdef __PREFETCHW__
#	define MASTER_FUTURE_PREFETCHW 1
#else
#	define MASTER_FUTURE_PREFETCHW 0
#endif /* #! __PREFETCHW__ !# */

#ifdef __SHSTK__
#	define MASTER_FUTURE_CET_SS 1
#else
#	define MASTER_FUTURE_CET_SS 0
#endif /* #! __SHSTK__ !# */

#ifdef __SERIALIZE__
#	define MASTER_FUTURE_SERIALIZE 1
#else
#	define MASTER_FUTURE_SERIALIZE 0
#endif /* #! __SERIALIZE__ !# */

#ifdef __WAITPKG__
#	define MASTER_FUTURE_WAITPKG 1
#else
#	define MASTER_FUTURE_WAITPKG 0
#endif /* #! __WAITPKG__ !# */

/* #! Intel AMX !# */
#ifdef __AMX_TILE__
#	define MASTER_FUTURE_AMX_TILE 1
#else
#	define MASTER_FUTURE_AMX_TILE 0
#endif /* #! __AMX_TILE__ !# */

#ifdef __AMX_INT8__
#	define MASTER_FUTURE_AMX_INT8 1
#else
#	define MASTER_FUTURE_AMX_INT8 0
#endif /* #! __AMX_INT8__ !# */

#ifdef __AMX_BF16__
#	define MASTER_FUTURE_AMX_BF16 1
#else
#	define MASTER_FUTURE_AMX_BF16 0
#endif /* #! __AMX_BF16__ !# */

/* #! SHA Extensions !# */
#ifdef __SHA__
#	define MASTER_FUTURE_SHA 1
#else
#	define MASTER_FUTURE_SHA 0
#endif /* #! __SHA__ !# */

/* #! Cache & Memory instructions !# */
#ifdef __CLFLUSHOPT__
#	define MASTER_FUTURE_CLFLUSHOPT 1
#else
#	define MASTER_FUTURE_CLFLUSHOPT 0
#endif /* #! __CLFLUSHOPT__ !# */

#ifdef __CLWB__
#	define MASTER_FUTURE_CLWB 1
#else
#	define MASTER_FUTURE_CLWB 0
#endif /* #! __CLWB__ !# */

#ifdef __CLZERO__
#	define MASTER_FUTURE_CLZERO 1
#else
#	define MASTER_FUTURE_CLZERO 0
#endif /* #! __CLZERO__ !# */

/* #! Other ARM Extensions !# */
#ifdef __ARM_FEATURE_DOTPROD__
#	define MASTER_FUTURE_ARM_DOTPROD 1
#else
#	define MASTER_FUTURE_ARM_DOTPROD 0
#endif /* #! __ARM_FEATURE_DOTPROD__ !# */

#ifdef __ARM_FEATURE_SME__
#	define MASTER_FUTURE_ARM_SME 1
#else
#	define MASTER_FUTURE_ARM_SME 0
#endif /* #! __ARM_FEATURE_SME__ !# */

#ifdef __ARM_FEATURE_SVE_FP16_SCALAR_ARITHMETIC__
#	define MASTER_FUTURE_ARM_SVE_FP16_SCALAR 1
#else
#	define MASTER_FUTURE_ARM_SVE_FP16_SCALAR 0
#endif /* #! __ARM_FEATURE_SVE_FP16_SCALAR_ARITHMETIC__ !# */

#ifdef __ARM_FEATURE_SVE_BF16__
#	define MASTER_FUTURE_ARM_SVE_BF16 1
#else
#	define MASTER_FUTURE_ARM_SVE_BF16 0
#endif /* #! __ARM_FEATURE_SVE_BF16__ !# */

/* #! Available Libraries !# */

/* #! Android bionic !# */
#ifdef __BIONIC__
#	define MASTER_FUTURE_BIONIC 1
#else
#	define MASTER_FUTURE_BIONIC 0
#endif /* #! __BIONIC__ !# */

/* #! Extensions !# */

/* #! Compiler Builtins (GCC/Clang) !# */
#if defined(__GNUC__) || defined(__clang__)
#	define MASTER_FUTURE_BUILTINS 1
#else
#	define MASTER_FUTURE_BUILTINS 0
#endif /* #! gcc / clang !# */

/* #! Available Future Extensions !# */
const char * const
MASTER_AvailableFutureExtensions[] = {
#if MASTER_FUTURE_3DNOW == 1
	"3dnow",
#endif /* #! 3DNOW !# */
#if MASTER_FUTURE_ADX == 1
	"adx",
#endif /* #! ADX !# */
#if MASTER_FUTURE_AESNI == 1
	"aesni",
#endif /* #! AESNI !# */
#if MASTER_FUTURE_ALTIVEC == 1
	"altivec",
#endif /* #! ALTIVEC !# */
#if MASTER_FUTURE_AMX_BF16 == 1
	"amx bf16",
#endif /* #! AMX BF16 !# */
#if MASTER_FUTURE_AMX_INT8 == 1
	"amx int8",
#endif /* #! AMX INT8 !# */
#if MASTER_FUTURE_AMX_TILE == 1
	"amx tile",
#endif /* #! AMX TILE !# */
#if MASTER_FUTURE_ARM_CRYPTO == 1
	"arm crypto",
#endif /* #! ARM CRYPTO !# */
#if MASTER_FUTURE_ARM_DOTPROD == 1
	"arm dotprod",
#endif /* #! ARM DOTPROD !# */
#if MASTER_FUTURE_ARM_FP16 == 1
	"arm fp16",
#endif /* #! ARM FP16 !# */
#if MASTER_FUTURE_ARM_SME == 1
	"arm sme",
#endif /* #! ARM SME !# */
#if MASTER_FUTURE_ARM_SVE_BF16 == 1
	"arm sve bf16",
#endif /* #! ARM SVE BF16 !# */
#if MASTER_FUTURE_ARM_SVE_FP16_SCALAR == 1
	"arm sve fp16 scalar",
#endif /* #! ARM SVE FP16 SCALAR !# */
#if MASTER_FUTURE_AVX == 1
	"avx",
#endif /* #! AVX !# */
#if MASTER_FUTURE_AVX2 == 1
	"avx2",
#endif /* #! AVX2 !# */
#if MASTER_FUTURE_AVX512BF16 == 1
	"avx512bf16",
#endif /* #! AVX512BF16 !# */
#if MASTER_FUTURE_AVX512BW == 1
	"avx512bw",
#endif /* #! AVX512BW !# */
#if MASTER_FUTURE_AVX512CD == 1
	"avx512cd",
#endif /* #! AVX512CD !# */
#if MASTER_FUTURE_AVX512DQ == 1
	"avx512dq",
#endif /* #! AVX512DQ !# */
#if MASTER_FUTURE_AVX512ER == 1
	"avx512er",
#endif /* #! AVX512ER !# */
#if MASTER_FUTURE_AVX512F == 1
	"avx512f",
#endif /* #! AVX512F !# */
#if MASTER_FUTURE_AVX512IFMA == 1
	"avx512ifma",
#endif /* #! AVX512IFMA !# */
#if MASTER_FUTURE_AVX512PF == 1
	"avx512pf",
#endif /* #! AVX512PF !# */
#if MASTER_FUTURE_AVX512VBMI == 1
	"avx512vbmi",
#endif /* #! AVX512VBMI !# */
#if MASTER_FUTURE_AVX512VL == 1
	"avx512vl",
#endif /* #! AVX512VL !# */
#if MASTER_FUTURE_AVX512VNNI == 1
	"avx512vnni",
#endif /* #! AVX512VNNI !# */
#if MASTER_FUTURE_AVX512_4FMAPS == 1
	"avx512 4fmaps",
#endif /* #! AVX512 4FMAPS !# */
#if MASTER_FUTURE_AVX512_4VNNIW == 1
	"avx512 4vnniw",
#endif /* #! AVX512 4VNNIW !# */
#if MASTER_FUTURE_AVX512_BITALG == 1
	"avx512 bitalg",
#endif /* #! AVX512 BITALG !# */
#if MASTER_FUTURE_AVX512_FP16 == 1
	"avx512 fp16",
#endif /* #! AVX512 FP16 !# */
#if MASTER_FUTURE_AVX512_GFNI == 1
	"avx512 gfni",
#endif /* #! AVX512 GFNI !# */
#if MASTER_FUTURE_AVX512_VAES == 1
	"avx512 vaes",
#endif /* #! AVX512 VAES !# */
#if MASTER_FUTURE_AVX512_VBMI2 == 1
	"avx512 vbmi2",
#endif /* #! AVX512 VBMI2 !# */
#if MASTER_FUTURE_AVX512_VP2INTERSECT == 1
	"avx512 vp2intersect",
#endif /* #! AVX512 VP2INTERSECT !# */
#if MASTER_FUTURE_AVX512_VPCLMULQDQ == 1
	"avx512 vpclmulqdq",
#endif /* #! AVX512 VPCLMULQDQ !# */
#if MASTER_FUTURE_AVX512_VPOPCNTDQ == 1
	"avx512 vpopcntdq",
#endif /* #! AVX512 VPOPCNTDQ !# */
#if MASTER_FUTURE_AVX_VNNI == 1
	"avx vnni",
#endif /* #! AVX VNNI !# */
#if MASTER_FUTURE_BIONIC == 1
	"bionic",
#endif /* #! BIONIC !# */
#if MASTER_FUTURE_BMI1 == 1
	"bmi1",
#endif /* #! BMI1 !# */
#if MASTER_FUTURE_BMI2 == 1
	"bmi2",
#endif /* #! BMI2 !# */
#if MASTER_FUTURE_CET_SS == 1
	"cet ss",
#endif /* #! CET SS !# */
#if MASTER_FUTURE_CLFLUSHOPT == 1
	"clflushopt",
#endif /* #! CLFLUSHOPT !# */
#if MASTER_FUTURE_CLWB == 1
	"clwb",
#endif /* #! CLWB !# */
#if MASTER_FUTURE_CLZERO == 1
	"clzero",
#endif /* #! CLZERO !# */
#if MASTER_FUTURE_CMOV == 1
	"cmov",
#endif /* #! CMOV !# */
#if MASTER_FUTURE_F16C == 1
	"f16c",
#endif /* #! F16C !# */
#if MASTER_FUTURE_FMA == 1
	"fma",
#endif /* #! FMA !# */
#if MASTER_FUTURE_FMA4 == 1
	"fma4",
#endif /* #! FMA4 !# */
#if MASTER_FUTURE_LOONGARCH_ASX == 1
	"loongarch asx",
#endif /* #! LOONGARCH ASX !# */
#if MASTER_FUTURE_LOONGARCH_SX == 1
	"loongarch sx",
#endif /* #! LOONGARCH SX !# */
#if MASTER_FUTURE_LZCNT == 1
	"lzcnt",
#endif /* #! LZCNT !# */
#if MASTER_FUTURE_MMX == 1
	"mmx",
#endif /* #! MMX !# */
#if MASTER_FUTURE_MOVBE == 1
	"movbe",
#endif /* #! MOVBE !# */
#if MASTER_FUTURE_MSA == 1
	"msa",
#endif /* #! MSA !# */
#if MASTER_FUTURE_NEON == 1
	"neon",
#endif /* #! NEON !# */
#if MASTER_FUTURE_PCLMUL == 1
	"pclmul",
#endif /* #! PCLMUL !# */
#if MASTER_FUTURE_POPCNT == 1
	"popcnt",
#endif /* #! POPCNT !# */
#if MASTER_FUTURE_PREFETCHW == 1
	"prefetchw",
#endif /* #! PREFETCHW !# */
#if MASTER_FUTURE_RDRAND == 1
	"rdrand",
#endif /* #! RDRAND !# */
#if MASTER_FUTURE_RDSEED == 1
	"rdseed",
#endif /* #! RDSEED !# */
#if MASTER_FUTURE_RISCV_VECTOR == 1
	"riscv vector",
#endif /* #! RISCV VECTOR !# */
#if MASTER_FUTURE_SERIALIZE == 1
	"serialize",
#endif /* #! SERIALIZE !# */
#if MASTER_FUTURE_SHA == 1
	"sha",
#endif /* #! SHA !# */
#if MASTER_FUTURE_SSE == 1
	"sse",
#endif /* #! SSE !# */
#if MASTER_FUTURE_SSE2 == 1
	"sse2",
#endif /* #! SSE2 !# */
#if MASTER_FUTURE_SSE3 == 1
	"sse3",
#endif /* #! SSE3 !# */
#if MASTER_FUTURE_SSE4_1 == 1
	"sse4 1",
#endif /* #! SSE4 1 !# */
#if MASTER_FUTURE_SSE4_2 == 1
	"sse4 2",
#endif /* #! SSE4 2 !# */
#if MASTER_FUTURE_SSSE3 == 1
	"ssse3",
#endif /* #! SSSE3 !# */
#if MASTER_FUTURE_SVE == 1
	"sve",
#endif /* #! SVE !# */
#if MASTER_FUTURE_SVE2 == 1
	"sve2",
#endif /* #! SVE2 !# */
#if MASTER_FUTURE_TBM == 1
	"tbm",
#endif /* #! TBM !# */
#if MASTER_FUTURE_WAITPKG == 1
	"waitpkg",
#endif /* #! WAITPKG !# */
#if MASTER_FUTURE_XOP == 1
	"xop",
#endif /* #! XOP !# */
};

const UI2 MASTER_AvailableFutureExtensionsCount = sizeof(MASTER_AvailableFutureExtensions) / sizeof(MASTER_AvailableFutureExtensions[0]);

MASTER_END_DECLARATIONS

#ifdef MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zRIVATE_SIMD_DETECT_INCLUDE_H_LAST_LINE = MASTER_LINE + 6;
#endif /* #! MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS !# */

#endif /* #! MASTER_zRIVATE_SIMD_DETECT_INCLUDE_H !# */

/* #! be master~ !# */
