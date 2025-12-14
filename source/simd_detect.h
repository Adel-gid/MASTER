
/*
 * Copyright (c) 2025 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_SIMD_DETECT_INCLUDE_H__
#define __MASTER_SIMD_DETECT_INCLUDE_H__ (MASTER_LIBRARY_AVAILABLE + \
										  MASTER_LIBRARY_INCREMENTHATE + \
										  MASTER_LIBRARY_FiCViN + \
										  MASTER_LIBRARY_NO_FUNCTIONS + \
										  MASTER_LIBRARY_GRAPHSHATE + \
										  MASTER_LIBRARY_FREESTANDING)

#include <master_enum.h>

/* #! SIMD !# */

/* #! MMX !# */
#ifdef __MMX__
	#define __MASTER_FUTURE_MMX 1
#else
	#define __MASTER_FUTURE_MMX 0
#endif /* #! __MMX__ !# */

/* #! 3DNow! !# */
#if defined(__3dNOW__) || defined(__3dNOWEXT__)
	#define __MASTER_FUTURE_3DNOW 1
#else
	#define __MASTER_FUTURE_3DNOW 0
#endif /* #! 3DNow! !# */

/* #! SSE family !# */
#ifdef __SSE__
	#define __MASTER_FUTURE_SSE 1
#else
	#define __MASTER_FUTURE_SSE 0
#endif /* #! __SSE__ !# */

#ifdef __SSE2__
	#define __MASTER_FUTURE_SSE2 1
#else
	#define __MASTER_FUTURE_SSE2 0
#endif /* #! __SSE2__ !# */

#ifdef __SSE3__
	#define __MASTER_FUTURE_SSE3 1
#else
	#define __MASTER_FUTURE_SSE3 0
#endif /* #! __SSE3__ !# */

#ifdef __SSSE3__
	#define __MASTER_FUTURE_SSSE3 1
#else
	#define __MASTER_FUTURE_SSSE3 0
#endif /* #! __SSSE3__ !# */

#ifdef __SSE4_1__
	#define __MASTER_FUTURE_SSE4_1 1
#else
	#define __MASTER_FUTURE_SSE4_1 0
#endif /* #! __SSE4_1__ !# */

#ifdef __SSE4_2__
	#define __MASTER_FUTURE_SSE4_2 1
#else
	#define __MASTER_FUTURE_SSE4_2 0
#endif /* #! __SSE4_2__ !# */

#ifdef __POPCNT__
	#define __MASTER_FUTURE_POPCNT 1
#else
	#define __MASTER_FUTURE_POPCNT 0
#endif /* #! __POPCNT__ !# */

#ifdef __LZCNT__
	#define __MASTER_FUTURE_LZCNT 1
#else
	#define __MASTER_FUTURE_LZCNT 0
#endif /* #! __LZCNT__ !# */

/* #! AVX family !# */
#ifdef __AVX__
	#define __MASTER_FUTURE_AVX 1
#else
	#define __MASTER_FUTURE_AVX 0
#endif /* #! __AVX__ !# */

#ifdef __AVX2__
	#define __MASTER_FUTURE_AVX2 1
#else
	#define __MASTER_FUTURE_AVX2 0
#endif /* #! __AVX2__ !# */

#ifdef __AVX512F__
	#define __MASTER_FUTURE_AVX512F 1
#else
	#define __MASTER_FUTURE_AVX512F 0
#endif /* #! __AVX512F__ !# */

#ifdef __AVX512DQ__
	#define __MASTER_FUTURE_AVX512DQ 1
#else
	#define __MASTER_FUTURE_AVX512DQ 0
#endif /* #! __AVX512DQ__ !# */

#ifdef __AVX512IFMA__
	#define __MASTER_FUTURE_AVX512IFMA 1
#else
	#define __MASTER_FUTURE_AVX512IFMA 0
#endif /* #! __AVX512IFMA__ !# */

#ifdef __AVX512PF__
	#define __MASTER_FUTURE_AVX512PF 1
#else
	#define __MASTER_FUTURE_AVX512PF 0
#endif /* #! __AVX512PF__ !# */

#ifdef __AVX512ER__
	#define __MASTER_FUTURE_AVX512ER 1
#else
	#define __MASTER_FUTURE_AVX512ER 0
#endif /* #! __AVX512ER__ !# */

#ifdef __AVX512CD__
	#define __MASTER_FUTURE_AVX512CD 1
#else
	#define __MASTER_FUTURE_AVX512CD 0
#endif /* #! __AVX512CD__ !# */

#ifdef __AVX512BW__
	#define __MASTER_FUTURE_AVX512BW 1
#else
	#define __MASTER_FUTURE_AVX512BW 0
#endif /* #! __AVX512BW__ !# */

#ifdef __AVX512VL__
	#define __MASTER_FUTURE_AVX512VL 1
#else
	#define __MASTER_FUTURE_AVX512VL 0
#endif /* #! __AVX512VL__ !# */

#ifdef __AVX512VBMI__
	#define __MASTER_FUTURE_AVX512VBMI 1
#else
	#define __MASTER_FUTURE_AVX512VBMI 0
#endif /* #! __AVX512VBMI__ !# */

#ifdef __AVX512VNNI__
	#define __MASTER_FUTURE_AVX512VNNI 1
#else
	#define __MASTER_FUTURE_AVX512VNNI 0
#endif /* #! __AVX512VNNI__ !# */

#ifdef __AVX512BF16__
	#define __MASTER_FUTURE_AVX512BF16 1
#else
	#define __MASTER_FUTURE_AVX512BF16 0
#endif /* #! __AVX512BF16__ !# */

#ifdef __AVX512_VPOPCNTDQ__
	#define __MASTER_FUTURE_AVX512_VPOPCNTDQ 1
#else
	#define __MASTER_FUTURE_AVX512_VPOPCNTDQ 0
#endif /* #! __AVX512_VPOPCNTDQ__ !# */

#ifdef __AVX512_BITALG__
	#define __MASTER_FUTURE_AVX512_BITALG 1
#else
	#define __MASTER_FUTURE_AVX512_BITALG 0
#endif /* #! __AVX512_BITALG__ !# */

#ifdef __AVX512_VBMI2__
	#define __MASTER_FUTURE_AVX512_VBMI2 1
#else
	#define __MASTER_FUTURE_AVX512_VBMI2 0
#endif /* #! __AVX512_VBMI2__ !# */

#ifdef __AVX512_VPCLMULQDQ__
	#define __MASTER_FUTURE_AVX512_VPCLMULQDQ 1
#else
	#define __MASTER_FUTURE_AVX512_VPCLMULQDQ 0
#endif /* #! __AVX512_VPCLMULQDQ__ !# */

#ifdef __AVX512_GFNI__
	#define __MASTER_FUTURE_AVX512_GFNI 1
#else
	#define __MASTER_FUTURE_AVX512_GFNI 0
#endif /* #! __AVX512_GFNI__ !# */

#ifdef __AVX512_VAES__
	#define __MASTER_FUTURE_AVX512_VAES 1
#else
	#define __MASTER_FUTURE_AVX512_VAES 0
#endif /* #! __AVX512_VAES__ !# */

#ifdef __AVX512_FP16__
	#define __MASTER_FUTURE_AVX512_FP16 1
#else
	#define __MASTER_FUTURE_AVX512_FP16 0
#endif /* #! __AVX512_FP16__ !# */

#ifdef __AVX512_4VNNIW__
	#define __MASTER_FUTURE_AVX512_4VNNIW 1
#else
	#define __MASTER_FUTURE_AVX512_4VNNIW 0
#endif /* #! __AVX512_4VNNIW__ !# */

#ifdef __AVX512_4FMAPS__
	#define __MASTER_FUTURE_AVX512_4FMAPS 1
#else
	#define __MASTER_FUTURE_AVX512_4FMAPS 0
#endif /* #! __AVX512_4FMAPS__ !# */

/* #! FMA, F16C, XOP, TBM, BMI !# */
#ifdef __FMA__
	#define __MASTER_FUTURE_FMA 1
#else
	#define __MASTER_FUTURE_FMA 0
#endif /* #! __FMA__!# */

#ifdef __F16C__
	#define __MASTER_FUTURE_F16C 1
#else
	#define __MASTER_FUTURE_F16C 0
#endif /* #! __F16C__ !# */

#ifdef __XOP__
	#define __MASTER_FUTURE_XOP 1
#else
	#define __MASTER_FUTURE_XOP 0
#endif /* #! __XOP__ !# */

#ifdef __TBM__
	#define __MASTER_FUTURE_TBM 1
#else
	#define __MASTER_FUTURE_TBM 0
#endif /* #! __TBM__ !# */

#ifdef __BMI__
	#define __MASTER_FUTURE_BMI1 1
#else
	#define __MASTER_FUTURE_BMI1 0
#endif /* #! __BMI__ !# */

#ifdef __BMI2__
	#define __MASTER_FUTURE_BMI2 1
#else
	#define __MASTER_FUTURE_BMI2 0
#endif /* #! __BMI2__ !# */

/* #! AES-NI, PCLMUL, RDRAND, RDSEED !# */
#ifdef __AES__
	#define __MASTER_FUTURE_AESNI 1
#else
	#define __MASTER_FUTURE_AESNI 0
#endif /* #! __AES__ !# */

#ifdef __PCLMUL__
	#define __MASTER_FUTURE_PCLMUL 1
#else
	#define __MASTER_FUTURE_PCLMUL 0
#endif /* #! __PCLMUL__ !# */

#ifdef __RDRND__
	#define __MASTER_FUTURE_RDRAND 1
#else
	#define __MASTER_FUTURE_RDRAND 0
#endif /* #! __RDRND__ !# */

#ifdef __RDSEED__
	#define __MASTER_FUTURE_RDSEED 1
#else
	#define __MASTER_FUTURE_RDSEED 0
#endif /* #! __RDSEED__ !# */

/* #! ARM AArch32/AArch64 !# */
#if defined(__ARM_NEON) || defined(__ARM_NEON__)
	#define __MASTER_FUTURE_NEON 1
#else
	#define __MASTER_FUTURE_NEON 0
#endif /* #! __ARM_NEON__ !# */

#ifdef __ARM_FEATURE_CRYPTO
	#define __MASTER_FUTURE_ARM_CRYPTO 1
#else
	#define __MASTER_FUTURE_ARM_CRYPTO 0
#endif /* #! __ARM_FEATURE_CRYPTO !# */

#ifdef __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
	#define __MASTER_FUTURE_ARM_FP16 1
#else
	#define __MASTER_FUTURE_ARM_FP16 0
#endif /* #! __ARM_FEATURE_FP16_VECTOR_ARITHMETIC !# */

#ifdef __ARM_FEATURE_SVE
	#define __MASTER_FUTURE_SVE 1
#else
	#define __MASTER_FUTURE_SVE 0
#endif /* #! __ARM_FEATURE_SVE !# */

#ifdef __ARM_FEATURE_SVE2
	#define __MASTER_FUTURE_SVE2 1
#else
	#define __MASTER_FUTURE_SVE2 0
#endif /* #! __ARM_FEATURE_SVE2 !# */

/* #! PowerPC AltiVec/VMX !# */
#if defined(__ALTIVEC__) || defined(__VEC__)
	#define __MASTER_FUTURE_ALTIVEC 1
#else
	#define __MASTER_FUTURE_ALTIVEC 0
#endif /* #! PowerPC AltiVec/VMX !# */

/* #! MIPS MSA !# */
#if defined(__mips_msa) || defined(__MSA__)
	#define __MASTER_FUTURE_MSA 1
#else
	#define __MASTER_FUTURE_MSA 0
#endif /* #! MIPS MSA !# */

/* #! RISC-V Vector !# */
#ifdef __riscv_vector
	#define __MASTER_FUTURE_RISCV_VECTOR 1
#else
	#define __MASTER_FUTURE_RISCV_VECTOR 0
#endif /* #! __riscv_vector !# */

/* #! LoongArch SX/ASX !# */
#ifdef __loongarch_sx
	#define __MASTER_FUTURE_LOONGARCH_SX 1
#else
	#define __MASTER_FUTURE_LOONGARCH_SX 0
#endif /* #! __loongarch_sx !# */

#ifdef __loongarch_asx
	#define __MASTER_FUTURE_LOONGARCH_ASX 1
#else
	#define __MASTER_FUTURE_LOONGARCH_ASX 0
#endif /* #! __loongarch_asx !# */

/* #! Miscellaneous !# */
#ifdef __CMOV__
	#define __MASTER_FUTURE_CMOV 1
#else
	#define __MASTER_FUTURE_CMOV 0
#endif /* #! __CMOV__ !# */

#ifdef __PREFETCHW__
	#define __MASTER_FUTURE_PREFETCHW 1
#else
	#define __MASTER_FUTURE_PREFETCHW 0
#endif /* #! __PREFETCHW__ !# */

/* #! Intel AMX !# */
#ifdef __AMX_TILE__
	#define __MASTER_FUTURE_AMX_TILE 1
#else
	#define __MASTER_FUTURE_AMX_TILE 0
#endif /* #! __AMX_TILE__ !# */

#ifdef __AMX_INT8__
	#define __MASTER_FUTURE_AMX_INT8 1
#else
	#define __MASTER_FUTURE_AMX_INT8 0
#endif /* #! __AMX_INT8__ !# */

#ifdef __AMX_BF16__
	#define __MASTER_FUTURE_AMX_BF16 1
#else
	#define __MASTER_FUTURE_AMX_BF16 0
#endif /* #! __AMX_BF16__ !# */

/* #! SHA Extensions !# */
#ifdef __SHA__
	#define __MASTER_FUTURE_SHA 1
#else
	#define __MASTER_FUTURE_SHA 0
#endif /* #! __SHA__ !# */

/* #! Other ARM Extensions !# */
#ifdef __ARM_FEATURE_DOTPROD__
	#define __MASTER_FUTURE_ARM_DOTPROD 1
#else
	#define __MASTER_FUTURE_ARM_DOTPROD 0
#endif /* #! __ARM_FEATURE_DOTPROD__ !# */

#ifdef __ARM_FEATURE_SME__
	#define __MASTER_FUTURE_ARM_SME 1
#else
	#define __MASTER_FUTURE_ARM_SME 0
#endif /* #! __ARM_FEATURE_SME__ !# */

#ifdef __ARM_FEATURE_SVE_FP16_SCALAR_ARITHMETIC__
	#define __MASTER_FUTURE_ARM_SVE_FP16_SCALAR 1
#else
	#define __MASTER_FUTURE_ARM_SVE_FP16_SCALAR 0
#endif /* #! __ARM_FEATURE_SVE_FP16_SCALAR_ARITHMETIC__ !# */

#ifdef __ARM_FEATURE_SVE_BF16__
	#define __MASTER_FUTURE_ARM_SVE_BF16 1
#else
	#define __MASTER_FUTURE_ARM_SVE_BF16 0
#endif /* #! __ARM_FEATURE_SVE_BF16__ !# */

/* #! Available Libraries !# */

/* #! Android bionic !# */
#ifdef __BIONIC__
	#define __MASTER_FUTURE_BIONIC 1
#else
	#define __MASTER_FUTURE_BIONIC 0
#endif /* #! __BIONIC__ !# */

/* #! Extensions !# */

/* #! Compiler Builtins (GCC/Clang) !# */
#if defined(__GNUC__) || defined(__clang__)
	#define __MASTER_FUTURE_BUILTINS 1
#else
	#define __MASTER_FUTURE_BUILTINS 0
#endif /* #! gcc / clang !# */

/* #! Available Future Extensions !# */
const char * const
MASTER_AvailableFutureExtensions[] = {
#if __MASTER_FUTURE_MMX == 1
	"mmx",
#endif /* #! __MASTER_FUTURE_MMX !# */
#if __MASTER_FUTURE_3DNOW == 1
	"3dnow",
#endif /* #! __MASTER_FUTURE_3DNOW !# */
#if __MASTER_FUTURE_SSE == 1
	"sse",
#endif /* #! __MASTER_FUTURE_SSE !# */
#if __MASTER_FUTURE_SSE2 == 1
	"sse2",
#endif /* #! __MASTER_FUTURE_SSE2 !# */
#if __MASTER_FUTURE_SSE3 == 1
	"sse3",
#endif /* #! __MASTER_FUTURE_SSE3 !# */
#if __MASTER_FUTURE_SSSE3 == 1
	"ssse3",
#endif /* #! __MASTER_FUTURE_SSSE3 !# */
#if __MASTER_FUTURE_SSE4_1 == 1
	"sse4.1",
#endif /* #! __MASTER_FUTURE_SSE4_1 !# */
#if __MASTER_FUTURE_SSE4_2 == 1
	"sse4.2",
#endif /* #! __MASTER_FUTURE_SSE4_2 !# */
#if __MASTER_FUTURE_POPCNT == 1
	"popcnt",
#endif /* #! __MASTER_FUTURE_POPCNT !# */
#if __MASTER_FUTURE_LZCNT == 1
	"lzcnt",
#endif /* #! __MASTER_FUTURE_LZCNT !# */
#if __MASTER_FUTURE_AVX == 1
	"avx",
#endif /* #! __MASTER_FUTURE_AVX !# */
#if __MASTER_FUTURE_AVX2 == 1
	"avx2",
#endif /* #! __MASTER_FUTURE_AVX2 !# */
#if __MASTER_FUTURE_AVX512F == 1
	"avx512f",
#endif /* #! __MASTER_FUTURE_AVX512F !# */
#if __MASTER_FUTURE_AVX512DQ == 1
	"avx512dq",
#endif /* #! __MASTER_FUTURE_AVX512DQ !# */
#if __MASTER_FUTURE_AVX512IFMA == 1
	"avx512ifma",
#endif /* #! __MASTER_FUTURE_AVX512IFMA !# */
#if __MASTER_FUTURE_AVX512PF == 1
	"avx512pf",
#endif /* #! __MASTER_FUTURE_AVX512PF !# */
#if __MASTER_FUTURE_AVX512ER == 1
	"avx512er",
#endif /* #! __MASTER_FUTURE_AVX512ER !# */
#if __MASTER_FUTURE_AVX512CD == 1
	"avx512cd",
#endif /* #! __MASTER_FUTURE_AVX512CD !# */
#if __MASTER_FUTURE_AVX512BW == 1
	"avx512bw",
#endif /* #! __MASTER_FUTURE_AVX512BW !# */
#if __MASTER_FUTURE_AVX512VL == 1
	"avx512vl",
#endif /* #! __MASTER_FUTURE_AVX512VL !# */
#if __MASTER_FUTURE_AVX512VBMI == 1
	"avx512vbmi",
#endif /* #! __MASTER_FUTURE_AVX512VBMI !# */
#if __MASTER_FUTURE_AVX512VNNI == 1
	"avx512vnni",
#endif /* #! __MASTER_FUTURE_AVX512VNNI !# */
#if __MASTER_FUTURE_AVX512BF16 == 1
	"avx512bf16",
#endif /* #! __MASTER_FUTURE_AVX512BF16 !# */
#if __MASTER_FUTURE_AVX512_VPOPCNTDQ == 1
	"avx512_vpopcntdq",
#endif /* #! __MASTER_FUTURE_AVX512_VPOPCNTDQ !# */
#if __MASTER_FUTURE_AVX512_BITALG == 1
	"avx512_bitalg",
#endif /* #! __MASTER_FUTURE_AVX512_BITALG !# */
#if __MASTER_FUTURE_AVX512_VBMI2 == 1
	"avx512_vbmi2",
#endif /* #! __MASTER_FUTURE_AVX512_VBMI2 !# */
#if __MASTER_FUTURE_AVX512_VPCLMULQDQ == 1
	"avx512_vpclmulqdq",
#endif /* #! __MASTER_FUTURE_AVX512_VPCLMULQDQ !# */
#if __MASTER_FUTURE_AVX512_GFNI == 1
	"avx512_gfni",
#endif /* #! __MASTER_FUTURE_AVX512_GFNI !# */
#if __MASTER_FUTURE_AVX512_VAES == 1
	"avx512_vaes",
#endif /* #! __MASTER_FUTURE_AVX512_VAES !# */
#if __MASTER_FUTURE_AVX512_FP16 == 1
	"avx512_fp16",
#endif /* #! __MASTER_FUTURE_AVX512_FP16 !# */
#if __MASTER_FUTURE_AVX512_4VNNIW == 1
	"avx512_4vnniw",
#endif /* #! __MASTER_FUTURE_AVX512_4VNNIW !# */
#if __MASTER_FUTURE_AVX512_4FMAPS == 1
	"avx512_4fmaps",
#endif /* #! __MASTER_FUTURE_AVX512_4FMAPS !# */
#if __MASTER_FUTURE_FMA == 1
	"fma",
#endif /* #! __MASTER_FUTURE_FMA !# */
#if __MASTER_FUTURE_F16C == 1
	"f16c",
#endif /* #! __MASTER_FUTURE_F16C !# */
#if __MASTER_FUTURE_XOP == 1
	"xop",
#endif /* #! __MASTER_FUTURE_XOP !# */
#if __MASTER_FUTURE_TBM == 1
	"tbm",
#endif /* #! __MASTER_FUTURE_TBM !# */
#if __MASTER_FUTURE_BMI1 == 1
	"bmi1",
#endif /* #! __MASTER_FUTURE_BMI1 !# */
#if __MASTER_FUTURE_BMI2 == 1
	"bmi2",
#endif /* #! __MASTER_FUTURE_BMI2 !# */
#if __MASTER_FUTURE_AESNI == 1
	"aesni",
#endif /* #! __MASTER_FUTURE_AESNI !# */
#if __MASTER_FUTURE_PCLMUL == 1
	"pclmul",
#endif /* #! __MASTER_FUTURE_PCLMUL !# */
#if __MASTER_FUTURE_RDRAND == 1
	"rdrand",
#endif /* #! __MASTER_FUTURE_RDRAND !# */
#if __MASTER_FUTURE_RDSEED == 1
	"rdseed",
#endif /* #! __MASTER_FUTURE_RDSEED !# */
#if __MASTER_FUTURE_NEON == 1
	"neon",
#endif /* #! __MASTER_FUTURE_NEON !# */
#if __MASTER_FUTURE_ARM_CRYPTO == 1
	"arm_crypto",
#endif /* #! __MASTER_FUTURE_ARM_CRYPTO !# */
#if __MASTER_FUTURE_ARM_FP16 == 1
	"arm_fp16",
#endif /* #! __MASTER_FUTURE_ARM_FP16 !# */
#if __MASTER_FUTURE_SVE == 1
	"sve",
#endif /* #! __MASTER_FUTURE_SVE !# */
#if __MASTER_FUTURE_SVE2 == 1
	"sve2",
#endif /* #! __MASTER_FUTURE_SVE2 !# */
#if __MASTER_FUTURE_ALTIVEC == 1
	"altivec",
#endif /* #! __MASTER_FUTURE_ALTIVEC !# */
#if __MASTER_FUTURE_MSA == 1
	"msa",
#endif /* #! __MASTER_FUTURE_MSA !# */
#if __MASTER_FUTURE_RISCV_VECTOR == 1
	"riscv_vector",
#endif /* #! __MASTER_FUTURE_RISCV_VECTOR !# */
#if __MASTER_FUTURE_LOONGARCH_SX == 1
	"loongarch_sx",
#endif /* #! __MASTER_FUTURE_LOONGARCH_SX !# */
#if __MASTER_FUTURE_LOONGARCH_ASX == 1
	"loongarch_asx",
#endif /* #! __MASTER_FUTURE_LOONGARCH_ASX !# */
#if __MASTER_FUTURE_CMOV == 1
	"cmov",
#endif /* #! __MASTER_FUTURE_CMOV !# */
#if __MASTER_FUTURE_PREFETCHW == 1
	"prefetchw",
#endif /* #! __MASTER_FUTURE_PREFETCHW !# */
#if __MASTER_FUTURE_AMX_TILE == 1
	"amx_tile",
#endif /* #! __MASTER_FUTURE_AMX_TILE !# */
#if __MASTER_FUTURE_AMX_INT8 == 1
	"amx_int8",
#endif /* #! __MASTER_FUTURE_AMX_INT8 !# */
#if __MASTER_FUTURE_AMX_BF16 == 1
	"amx_bf16",
#endif /* #! __MASTER_FUTURE_AMX_BF16 !# */
#if __MASTER_FUTURE_SHA == 1
	"sha",
#endif /* #! __MASTER_FUTURE_SHA !# */
#if __MASTER_FUTURE_ARM_DOTPROD == 1
	"arm_dotprod",
#endif /* #! __MASTER_FUTURE_ARM_DOTPROD !# */
#if __MASTER_FUTURE_ARM_SME == 1
	"arm_sme",
#endif /* #! __MASTER_FUTURE_ARM_SME !# */
#if __MASTER_FUTURE_ARM_SVE_FP16_SCALAR == 1
	"arm_sve_fp16_scalar",
#endif /* #! __MASTER_FUTURE_ARM_SVE_FP16_SCALAR !# */
#if __MASTER_FUTURE_ARM_SVE_BF16 == 1
	"arm_sve_bf16",
#endif /* #! __MASTER_FUTURE_ARM_SVE_BF16 !# */
#if __MASTER_FUTURE_BUILTINS == 1
	"builtins",
#endif /* #! __MASTER_FUTURE_BUILTINS !# */
#if __MASTER_FUTURE_BIONIC == 1
	"bionic",
#endif /* #! __MASTER_FUTURE_BIONIC !# */
};

const UI2 MASTER_AvailableFutureExtensionsCount = sizeof(MASTER_AvailableFutureExtensions) / sizeof(MASTER_AvailableFutureExtensions[0]);

#endif /* #! __MASTER_SIMD_DETECT_INCLUDE_H__ !# */

/* #! be master~ !# */
