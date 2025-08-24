
/*
 * Copyright (c) 2025 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 */

#ifndef __MASTER_MMX_REALIZATION_INCLUDE_H__
#define __MASTER_MMX_REALIZATION_INCLUDE_H__

#include <master_enum.h>
#include <simd_detect.h>

#if __MASTER_FUTURE_MMX == 1
	#include <mmintrin.h>
	typedef __m64 MASTER_MMX_m64;

#else
	typedef union {
		UI1 __s[8]; /* #! Symbols !# */
		UI2 __w[4]; /* #! Words !# */
		UI4 __p[2]; /* #! Phrases !# */
#if MASTER_64_AVAILABLE == 1
		UI8 __e; /* #! Sentence !# */
#endif /* #! MASTER_64_AVAILABLE !# */
	} MASTER_MMX_m64;

#endif /* #! __MASTER_FUTURE_MMX !# */

MASTER_MMX_m64
MASTER_MMX_mm_add_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_add_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_add_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_adds_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_adds_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_adds_pu16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_adds_pu8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_and_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_andnot_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_cmpeq_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_cmpeq_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_cmpeq_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_cmpgt_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_cmpgt_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_cmpgt_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
SI8
MASTER_MMX_mm_cvtm64_si64( MASTER_MMX_m64 a );
MASTER_MMX_m64
MASTER_MMX_mm_cvtsi32_si64( SI4 a );
MASTER_MMX_m64
MASTER_MMX_mm_cvtsi64_m64( SI8 a );
SI4
MASTER_MMX_mm_cvtsi64_si32( MASTER_MMX_m64 a );
void
MASTER_MMX_m_empty( void );
void
MASTER_MMX_mm_empty( void );
MASTER_MMX_m64
MASTER_MMX_m_from_int( SI4 a );
MASTER_MMX_m64
MASTER_MMX_m_from_int64( SI8 a );
MASTER_MMX_m64
MASTER_MMX_mm_madd_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_mulhi_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_mullo_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_or_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_packs_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_packs_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_packs_pu16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_packssdw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_packsswb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_packuswb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_paddb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_paddd( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_paddsb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_paddsw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_paddusb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_paddusw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_paddw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pand( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pandn( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pcmpeqb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pcmpeqd( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pcmpeqw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pcmpgtb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pcmpgtd( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pcmpgtw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pmaddwd( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pmulhw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pmullw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_por( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pslld( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_m_pslldi( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_m_psllq( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_m_psllqi( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_m_psllw( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_m_psllwi( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_m_psrad( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_m_psradi( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_m_psraw( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_m_psrawi( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_m_psrld( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_m_psrldi( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_m_psrlq( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_m_psrlqi( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_m_psrlw( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_m_psrlwi( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_m_psubb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_psubd( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_psubsb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_psubsw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_psubusb( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_psubusw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_psubw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_punpckhbw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_punpckhdq( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_punpckhwd( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_punpcklbw( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_punpckldq( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_punpcklwd( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_m_pxor( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_set_pi16( SI2 e3, SI2 e2, SI2 e1, SI2 e0 );
MASTER_MMX_m64
MASTER_MMX_mm_set_pi32( SI4 e1, SI4 e0 );
MASTER_MMX_m64
MASTER_MMX_mm_set_pi8( SI1 e7, SI1 e6, SI1 e5, SI1 e4, SI1 e3, SI1 e2, SI1 e1, SI1 e0 );
MASTER_MMX_m64
MASTER_MMX_mm_set1_pi16( SI2 a );
MASTER_MMX_m64
MASTER_MMX_mm_set1_pi32( SI4 a );
MASTER_MMX_m64
MASTER_MMX_mm_set1_pi8( SI1 a );
MASTER_MMX_m64
MASTER_MMX_mm_setr_pi16( SI2 e3, SI2 e2, SI2 e1, SI2 e0 );
MASTER_MMX_m64
MASTER_MMX_mm_setr_pi32( SI4 e1, SI4 e0 );
MASTER_MMX_m64
MASTER_MMX_mm_setr_pi8( SI1 e7, SI1 e6, SI1 e5, SI1 e4, SI1 e3, SI1 e2, SI1 e1, SI1 e0 );
MASTER_MMX_m64
MASTER_MMX_mm_setzero_si64( void );
MASTER_MMX_m64
MASTER_MMX_mm_sll_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_mm_sll_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_mm_sll_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_mm_slli_pi16( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_mm_slli_pi32( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_mm_slli_si64( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_mm_sra_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_mm_sra_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_mm_srai_pi16( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_mm_srai_pi32( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_mm_srl_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_mm_srl_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_mm_srl_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 count );
MASTER_MMX_m64
MASTER_MMX_mm_srli_pi16( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_mm_srli_pi32( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_mm_srli_si64( MASTER_MMX_m64 a, SI4 imm8 );
MASTER_MMX_m64
MASTER_MMX_mm_sub_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_sub_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_sub_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_subs_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_subs_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_subs_pu16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_subs_pu8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
SI4
MASTER_MMX_m_to_int( MASTER_MMX_m64 a );
SI8
MASTER_MMX_m_to_int64( MASTER_MMX_m64 a );
MASTER_MMX_m64
MASTER_MMX_mm_unpackhi_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_unpackhi_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_unpackhi_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_unpacklo_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_unpacklo_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_unpacklo_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b );
MASTER_MMX_m64
MASTER_MMX_mm_xor_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 b );

#if __MASTER_FUTURE_MMX == 1
	#define MASTER_MMX_mm_add_pi16      _mm_add_pi16
	#define MASTER_MMX_mm_add_pi32      _mm_add_pi32
	#define MASTER_MMX_mm_add_pi8       _mm_add_pi8
	#define MASTER_MMX_mm_adds_pi16     _mm_adds_pi16
	#define MASTER_MMX_mm_adds_pi8      _mm_adds_pi8
	#define MASTER_MMX_mm_adds_pu16     _mm_adds_pu16
	#define MASTER_MMX_mm_adds_pu8      _mm_adds_pu8
	#define MASTER_MMX_mm_and_si64      _mm_and_si64
	#define MASTER_MMX_mm_andnot_si64   _mm_andnot_si64
	#define MASTER_MMX_mm_cmpeq_pi16    _mm_cmpeq_pi16
	#define MASTER_MMX_mm_cmpeq_pi32    _mm_cmpeq_pi32
	#define MASTER_MMX_mm_cmpeq_pi8     _mm_cmpeq_pi8
	#define MASTER_MMX_mm_cmpgt_pi16    _mm_cmpgt_pi16
	#define MASTER_MMX_mm_cmpgt_pi32    _mm_cmpgt_pi32
	#define MASTER_MMX_mm_cmpgt_pi8     _mm_cmpgt_pi8
	#define MASTER_MMX_mm_cvtm64_si64   _mm_cvtm64_si64
	#define MASTER_MMX_mm_cvtsi32_si64  _mm_cvtsi32_si64
	#define MASTER_MMX_mm_cvtsi64_m64   _mm_cvtsi64_m64
	#define MASTER_MMX_mm_cvtsi64_si32  _mm_cvtsi64_si32
	#define MASTER_MMX_m_empty          _m_empty
	#define MASTER_MMX_mm_empty         _mm_empty
	#define MASTER_MMX_m_from_int       _m_from_int
	#define MASTER_MMX_m_from_int64     _m_from_int64
	#define MASTER_MMX_mm_madd_pi16     _mm_madd_pi16
	#define MASTER_MMX_mm_mulhi_pi16    _mm_mulhi_pi16
	#define MASTER_MMX_mm_mullo_pi16    _mm_mullo_pi16
	#define MASTER_MMX_mm_or_si64       _mm_or_si64
	#define MASTER_MMX_mm_packs_pi16    _mm_packs_pi16
	#define MASTER_MMX_mm_packs_pi32    _mm_packs_pi32
	#define MASTER_MMX_mm_packs_pu16    _mm_packs_pu16
	#define MASTER_MMX_m_packssdw       _m_packssdw
	#define MASTER_MMX_m_packsswb       _m_packsswb
	#define MASTER_MMX_m_packuswb       _m_packuswb
	#define MASTER_MMX_m_paddb          _m_paddb
	#define MASTER_MMX_m_paddd          _m_paddd
	#define MASTER_MMX_m_paddsb         _m_paddsb
	#define MASTER_MMX_m_paddsw         _m_paddsw
	#define MASTER_MMX_m_paddusb        _m_paddusb
	#define MASTER_MMX_m_paddusw        _m_paddusw
	#define MASTER_MMX_m_paddw          _m_paddw
	#define MASTER_MMX_m_pand           _m_pand
	#define MASTER_MMX_m_pandn          _m_pandn
	#define MASTER_MMX_m_pcmpeqb        _m_pcmpeqb
	#define MASTER_MMX_m_pcmpeqd        _m_pcmpeqd
	#define MASTER_MMX_m_pcmpeqw        _m_pcmpeqw
	#define MASTER_MMX_m_pcmpgtb        _m_pcmpgtb
	#define MASTER_MMX_m_pcmpgtd        _m_pcmpgtd
	#define MASTER_MMX_m_pcmpgtw        _m_pcmpgtw
	#define MASTER_MMX_m_pmaddwd        _m_pmaddwd
	#define MASTER_MMX_m_pmulhw         _m_pmulhw
	#define MASTER_MMX_m_pmullw         _m_pmullw
	#define MASTER_MMX_m_por            _m_por
	#define MASTER_MMX_m_pslld          _m_pslld
	#define MASTER_MMX_m_pslldi         _m_pslldi
	#define MASTER_MMX_m_psllq          _m_psllq
	#define MASTER_MMX_m_psllqi         _m_psllqi
	#define MASTER_MMX_m_psllw          _m_psllw
	#define MASTER_MMX_m_psllwi         _m_psllwi
	#define MASTER_MMX_m_psrad          _m_psrad
	#define MASTER_MMX_m_psradi         _m_psradi
	#define MASTER_MMX_m_psraw          _m_psraw
	#define MASTER_MMX_m_psrawi         _m_psrawi
	#define MASTER_MMX_m_psrld          _m_psrld
	#define MASTER_MMX_m_psrldi         _m_psrldi
	#define MASTER_MMX_m_psrlq          _m_psrlq
	#define MASTER_MMX_m_psrlqi         _m_psrlqi
	#define MASTER_MMX_m_psrlw          _m_psrlw
	#define MASTER_MMX_m_psrlwi         _m_psrlwi
	#define MASTER_MMX_m_psubb          _m_psubb
	#define MASTER_MMX_m_psubd          _m_psubd
	#define MASTER_MMX_m_psubsb         _m_psubsb
	#define MASTER_MMX_m_psubsw         _m_psubsw
	#define MASTER_MMX_m_psubusb        _m_psubusb
	#define MASTER_MMX_m_psubusw        _m_psubusw
	#define MASTER_MMX_m_psubw          _m_psubw
	#define MASTER_MMX_m_punpckhbw      _m_punpckhbw
	#define MASTER_MMX_m_punpckhdq      _m_punpckhdq
	#define MASTER_MMX_m_punpckhwd      _m_punpckhwd
	#define MASTER_MMX_m_punpcklbw      _m_punpcklbw
	#define MASTER_MMX_m_punpckldq      _m_punpckldq
	#define MASTER_MMX_m_punpcklwd      _m_punpcklwd
	#define MASTER_MMX_m_pxor           _m_pxor
	#define MASTER_MMX_mm_set_pi16      _mm_set_pi16
	#define MASTER_MMX_mm_set_pi32      _mm_set_pi32
	#define MASTER_MMX_mm_set_pi8       _mm_set_pi8
	#define MASTER_MMX_mm_set1_pi16     _mm_set1_pi16
	#define MASTER_MMX_mm_set1_pi32     _mm_set1_pi32
	#define MASTER_MMX_mm_set1_pi8      _mm_set1_pi8
	#define MASTER_MMX_mm_setr_pi16     _mm_setr_pi16
	#define MASTER_MMX_mm_setr_pi32     _mm_setr_pi32
	#define MASTER_MMX_mm_setr_pi8      _mm_setr_pi8
	#define MASTER_MMX_mm_setzero_si64  _mm_setzero_si64
	#define MASTER_MMX_mm_sll_pi16      _mm_sll_pi16
	#define MASTER_MMX_mm_sll_pi32      _mm_sll_pi32
	#define MASTER_MMX_mm_sll_si64      _mm_sll_si64
	#define MASTER_MMX_mm_slli_pi16     _mm_slli_pi16
	#define MASTER_MMX_mm_slli_pi32     _mm_slli_pi32
	#define MASTER_MMX_mm_slli_si64     _mm_slli_si64
	#define MASTER_MMX_mm_sra_pi16      _mm_sra_pi16
	#define MASTER_MMX_mm_sra_pi32      _mm_sra_pi32
	#define MASTER_MMX_mm_srai_pi16     _mm_srai_pi16
	#define MASTER_MMX_mm_srai_pi32     _mm_srai_pi32
	#define MASTER_MMX_mm_srl_pi16      _mm_srl_pi16
	#define MASTER_MMX_mm_srl_pi32      _mm_srl_pi32
	#define MASTER_MMX_mm_srl_si64      _mm_srl_si64
	#define MASTER_MMX_mm_srli_pi16     _mm_srli_pi16
	#define MASTER_MMX_mm_srli_pi32     _mm_srli_pi32
	#define MASTER_MMX_mm_srli_si64     _mm_srli_si64
	#define MASTER_MMX_mm_sub_pi16      _mm_sub_pi16
	#define MASTER_MMX_mm_sub_pi32      _mm_sub_pi32
	#define MASTER_MMX_mm_sub_pi8       _mm_sub_pi8
	#define MASTER_MMX_mm_subs_pi16     _mm_subs_pi16
	#define MASTER_MMX_mm_subs_pi8      _mm_subs_pi8
	#define MASTER_MMX_mm_subs_pu16     _mm_subs_pu16
	#define MASTER_MMX_mm_subs_pu8      _mm_subs_pu8
	#define MASTER_MMX_m_to_int         _m_to_int
	#define MASTER_MMX_m_to_int64       _m_to_int64
	#define MASTER_MMX_mm_unpackhi_pi16 _mm_unpackhi_pi16
	#define MASTER_MMX_mm_unpackhi_pi32 _mm_unpackhi_pi32
	#define MASTER_MMX_mm_unpackhi_pi8  _mm_unpackhi_pi8
	#define MASTER_MMX_mm_unpacklo_pi16 _mm_unpacklo_pi16
	#define MASTER_MMX_mm_unpacklo_pi32 _mm_unpacklo_pi32
	#define MASTER_MMX_mm_unpacklo_pi8  _mm_unpacklo_pi8
	#define MASTER_MMX_mm_xor_si64      _mm_xor_si64

#else

MASTER_MMX_m64
MASTER_MMX_mm_add_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__w[0] = a.__w[0] + b.__w[0];
	c.__w[1] = a.__w[1] + b.__w[1];
	c.__w[2] = a.__w[2] + b.__w[2];
	c.__w[3] = a.__w[3] + b.__w[3];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_add_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__p[0] = a.__p[0] + b.__p[0];
	c.__p[1] = a.__p[1] + b.__p[1];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_add_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1) c.__s[i] = a.__s[i] + b.__s[i];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_adds_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1) {
		c.__w[i] = a.__w[i] + b.__w[i];
		if (a.__w[i] > 0 && b.__w[i] > 0 && c.__w[i] < 0) c.__w[i] = 0x7FFF;
		otherwise (a.__w[i] < 0 && b.__w[i] < 0 && c.__w[i] > 0) c.__w[i] = 0x8000;
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_adds_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1) {
		c.__s[i] = a.__s[i] + b.__s[i];
		if (a.__s[i] > 0 && b.__s[i] > 0 && c.__s[i] < 0) c.__s[i] = 0x7F;
		otherwise (a.__s[i] < 0 && b.__s[i] < 0 && c.__s[i] > 0) c.__s[i] = 0x80;
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_adds_pu16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1) {
		c.__w[i] = a.__w[i] + b.__w[i];
		if (c.__w[i] < a.__w[i]) c.__w[i] = 0xFFFF;
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_adds_pu8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1) {
		c.__s[i] = a.__s[i] + b.__s[i];
		if (c.__s[i] < a.__s[i]) c.__s[i] = 0xFF;
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_and_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = a.__e & b.__e;
#else
	c.__p[0] = a.__p[0] & b.__p[0];
	c.__p[1] = a.__p[1] & b.__p[1];
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_andnot_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = (~a.__e) & b.__e;
#else
	c.__p[0] = (~a.__p[0]) & b.__p[0];
	c.__p[1] = (~a.__p[1]) & b.__p[1];
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_cmpeq_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = (a.__w[i] == b.__w[i]) ? 0xFFFF : 0;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_cmpeq_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__p[0] = (a.__p[0] == b.__p[0]) ? 0xFFFFFFFF : 0;
	c.__p[1] = (a.__p[1] == b.__p[1]) ? 0xFFFFFFFF : 0;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_cmpeq_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1)
		c.__s[i] = (a.__s[i] == b.__s[i]) ? 0xFF : 0;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_cmpgt_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = (a.__w[i] > b.__w[i]) ? 0xFFFF : 0;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_cmpgt_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__p[0] = (a.__p[0] > b.__p[0]) ? 0xFFFFFFFF : 0;
	c.__p[1] = (a.__p[1] > b.__p[1]) ? 0xFFFFFFFF : 0;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_cmpgt_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1)
		c.__s[i] = (a.__s[i] > b.__s[i]) ? 0xFF : 0;
	return c;
}

#if MASTER_64_AVAILABLE == 1
SI8
MASTER_MMX_mm_cvtm64_si64( MASTER_MMX_m64 a ) {
	return a.__e;
}
#endif /* #! 64 !# */

MASTER_MMX_m64
MASTER_MMX_mm_cvtsi32_si64( SI4 a ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = a;
#else
	c.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] = 0;
	c.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] = a;
#endif /* #! 64 !# */
	return c;
}

#if MASTER_64_AVAILABLE == 1
MASTER_MMX_m64
MASTER_MMX_mm_cvtsi64_m64( SI8 a ) {
	MASTER_MMX_m64 c;
	c.__e = a;
	return c;
}
#endif /* #! 64 !# */

SI4
MASTER_MMX_mm_cvtsi64_si32( MASTER_MMX_m64 a ) {
	return a.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
}

void
MASTER_MMX_m_empty( void ) {
	/* #! I not emulating FPU bug, so there is nothing !# */
}

void
MASTER_MMX_mm_empty( void ) {
	/* #! I not emulating FPU bug, so there is nothing !# */
}

MASTER_MMX_m64
MASTER_MMX_m_from_int( SI4 a ) {
	return MASTER_MMX_mm_cvtsi32_si64(a);
}

#if MASTER_64_AVAILABLE == 1
MASTER_MMX_m64
MASTER_MMX_m_from_int64( SI8 a ) {
	return MASTER_MMX_mm_cvtsi64_m64(a);
}
#endif /* #! 64 !# */

MASTER_MMX_m64
MASTER_MMX_mm_madd_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__p[0] = (SI4)a.__w[1] * (SI4)b.__w[1] + (SI4)a.__w[0] * (SI4)b.__w[0];
	c.__p[1] = (SI4)a.__w[3] * (SI4)b.__w[3] + (SI4)a.__w[2] * (SI4)b.__w[2];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_mulhi_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = ((SI4)a.__w[i] * (SI4)b.__w[i]) >> 16;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_mullo_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = ((SI4)a.__w[i] * (SI4)b.__w[i]) & 0xFFFF;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_or_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = a.__e | b.__e;
#else
	c.__p[0] = a.__p[0] | b.__p[0];
	c.__p[1] = a.__p[1] | b.__p[1];
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_packs_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	SI2 num;
	for (; i < 4; i += 1) {
		num = *(SI2 *)&a.__w[i];
		if (num < -128) num = -128;
		if (num > 127) num = 127;
		*(SI1 *)&c.__s[i] = num;
	}
	for (; i < 8; i += 1) {
		num = *(SI2 *)&b.__w[i - 4];
		if (num < -128) num = -128;
		if (num > 127) num = 127;
		*(SI1 *)&c.__s[i] = num;
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_packs_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	SI4 num;
	for (; i < 2; i += 1) {
		num = *(SI4 *)&a.__p[i];
		if (num < -32768) num = -32768;
		if (num > 32767) num = 32767;
		*(SI2 *)&c.__w[i] = num;
	}
	for (; i < 4; i += 1) {
		num = *(SI4 *)&b.__p[i - 2];
		if (num < -32768) num = -32768;
		if (num > 32767) num = 32767;
		*(SI2 *)&c.__w[i] = num;
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_packs_pu16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	UI2 num;
	for (; i < 4; i += 1) {
		num = a.__w[i];
		if (num > 0xFF) num = 0xFF;
		c.__s[i] = num;
	}
	for (; i < 8; i += 1) {
		num = b.__w[i - 4];
		if (num > 0xFF) num = 0xFF;
		c.__s[i] = num;
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_m_packssdw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_packs_pi32(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_packsswb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_packs_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_packuswb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_packs_pu16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_paddb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_add_pi8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_paddd( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_add_pi32(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_paddsb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_adds_pi8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_paddsw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_adds_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_paddusb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_adds_pu8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_paddusw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_adds_pu16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_paddw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_add_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pand( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_and_si64(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pandn( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_andnot_si64(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pcmpeqb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_cmpeq_pi8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pcmpeqd( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_cmpeq_pi32(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pcmpeqw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_cmpeq_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pcmpgtb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_cmpgt_pi8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pcmpgtd( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_cmpgt_pi32(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pcmpgtw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_cmpgt_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pmaddwd( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_madd_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pmulhw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_mulhi_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pmullw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_mullo_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_por( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_or_si64(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pslld( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	return MASTER_MMX_mm_sll_pi32(a, count);
}

MASTER_MMX_m64
MASTER_MMX_m_pslldi( MASTER_MMX_m64 a, SI4 imm8 ) {
	return MASTER_MMX_mm_slli_pi32(a, imm8);
}

MASTER_MMX_m64
MASTER_MMX_m_psllq( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	return MASTER_MMX_mm_sll_si64(a, count);
}

MASTER_MMX_m64
MASTER_MMX_m_psllqi( MASTER_MMX_m64 a, SI4 imm8 ) {
	return MASTER_MMX_mm_slli_si64(a, imm8);
}

MASTER_MMX_m64
MASTER_MMX_m_psllw( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	return MASTER_MMX_mm_sll_pi16(a, count);
}

MASTER_MMX_m64
MASTER_MMX_m_psllwi( MASTER_MMX_m64 a, SI4 imm8 ) {
	return MASTER_MMX_mm_slli_pi16(a, imm8);
}

MASTER_MMX_m64
MASTER_MMX_m_psrad( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	return MASTER_MMX_mm_sra_pi32(a, count);
}

MASTER_MMX_m64
MASTER_MMX_m_psradi( MASTER_MMX_m64 a, SI4 imm8 ) {
	return MASTER_MMX_mm_srai_pi32(a, imm8);
}

MASTER_MMX_m64
MASTER_MMX_m_psraw( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	return MASTER_MMX_mm_sra_pi16(a, count);
}

MASTER_MMX_m64
MASTER_MMX_m_psrawi( MASTER_MMX_m64 a, SI4 imm8 ) {
	return MASTER_MMX_mm_srai_pi16(a, imm8);
}

MASTER_MMX_m64
MASTER_MMX_m_psrld( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	return MASTER_MMX_mm_srl_pi32(a, count);
}

MASTER_MMX_m64
MASTER_MMX_m_psrldi( MASTER_MMX_m64 a, SI4 imm8 ) {
	return MASTER_MMX_mm_srli_pi32(a, imm8);
}

MASTER_MMX_m64
MASTER_MMX_m_psrlq( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	return MASTER_MMX_mm_srl_si64(a, count);
}

MASTER_MMX_m64
MASTER_MMX_m_psrlqi( MASTER_MMX_m64 a, SI4 imm8 ) {
	return MASTER_MMX_mm_srli_si64(a, imm8);
}

MASTER_MMX_m64
MASTER_MMX_m_psrlw( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	return MASTER_MMX_mm_srl_pi16(a, count);
}

MASTER_MMX_m64
MASTER_MMX_m_psrlwi( MASTER_MMX_m64 a, SI4 imm8 ) {
	return MASTER_MMX_mm_srli_pi16(a, imm8);
}

MASTER_MMX_m64
MASTER_MMX_m_psubb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_sub_pi8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_psubd( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_sub_pi32(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_psubsb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_subs_pi8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_psubsw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_subs_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_psubusb( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_subs_pu8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_psubusw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_subs_pu16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_psubw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_sub_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_punpckhbw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_unpackhi_pi8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_punpckhdq( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_unpackhi_pi32(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_punpckhwd( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_unpackhi_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_punpcklbw( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_unpacklo_pi8(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_punpckldq( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_unpacklo_pi32(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_punpcklwd( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_unpacklo_pi16(a, b);
}

MASTER_MMX_m64
MASTER_MMX_m_pxor( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	return MASTER_MMX_mm_xor_si64(a, b);
}

MASTER_MMX_m64
MASTER_MMX_mm_set_pi16( SI2 e3, SI2 e2, SI2 e1, SI2 e0 ) {
	MASTER_MMX_m64 c;
	c.__w[0] = e0;
	c.__w[1] = e1;
	c.__w[2] = e2;
	c.__w[3] = e3;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_set_pi32( SI4 e1, SI4 e0 ) {
	MASTER_MMX_m64 c;
	c.__p[0] = e0;
	c.__p[1] = e1;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_set_pi8( SI1 e7, SI1 e6, SI1 e5, SI1 e4, SI1 e3, SI1 e2, SI1 e1, SI1 e0 ) {
	MASTER_MMX_m64 c;
	c.__s[0] = e0;
	c.__s[1] = e1;
	c.__s[2] = e2;
	c.__s[3] = e3;
	c.__s[4] = e4;
	c.__s[5] = e5;
	c.__s[6] = e6;
	c.__s[7] = e7;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_set1_pi16( SI2 a ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1) c.__w[i] = a;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_set1_pi32( SI4 a ) {
	MASTER_MMX_m64 c;
	c.__p[0] = c.__p[1] = a;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_set1_pi8( SI1 a ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1) c.__s[i] = a;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_setr_pi16( SI2 e3, SI2 e2, SI2 e1, SI2 e0 ) {
	return MASTER_MMX_mm_set_pi16(e0, e1, e2, e3);
}

MASTER_MMX_m64
MASTER_MMX_mm_setr_pi32( SI4 e1, SI4 e0 ) {
	return MASTER_MMX_mm_set_pi32(e0, e1);
}

MASTER_MMX_m64
MASTER_MMX_mm_setr_pi8( SI1 e7, SI1 e6, SI1 e5, SI1 e4, SI1 e3, SI1 e2, SI1 e1, SI1 e0 ) {
	return MASTER_MMX_mm_set_pi8(e0, e1, e2, e3, e4, e5, e6, e7);
}

MASTER_MMX_m64
MASTER_MMX_mm_setzero_si64( void ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = 0;
#else
	c.__p[0] = c.__p[1] = 0;
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_sll_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	UI1 i = 0;
	if (count.__e > 15) return MASTER_MMX_mm_setzero_si64();
	for (; i < 4; i += 1)
		c.__w[i] = a.__w[i] << count.__e;
#else
	UI1 i = 0;
	if (count.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] > 0 || count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] > 15) return MASTER_MMX_mm_setzero_si64();
	for (; i < 4; i += 1)
		c.__w[i] = a.__w[i] << count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_sll_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	if (count.__e > 31) return MASTER_MMX_mm_setzero_si64();
	c.__p[0] = a.__p[0] << count.__e;
	c.__p[1] = a.__p[1] << count.__e;
#else
	if (count.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] > 0 || count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] > 31) return MASTER_MMX_mm_setzero_si64();
	c.__p[0] = a.__p[0] << count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
	c.__p[1] = a.__p[1] << count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_sll_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = a.__e << count.__e;
#else
	if (count.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] > 0 || count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] > 63) return MASTER_MMX_mm_setzero_si64();
	c.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] = (a.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] << count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN]) | (a.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] >> (32 - count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN]));
	c.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] = a.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] << count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_slli_pi16( MASTER_MMX_m64 a, SI4 imm8 ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1) c.__w[i] = a.__w[i] << imm8;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_slli_pi32( MASTER_MMX_m64 a, SI4 imm8 ) {
	MASTER_MMX_m64 c;
	c.__p[0] = a.__p[0] << imm8;
	c.__p[1] = a.__p[1] << imm8;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_slli_si64( MASTER_MMX_m64 a, SI4 imm8 ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = a.__e << imm8;
#else
	c.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] = (a.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] << imm8) | (a.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] >> (32 - imm8));
	c.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] = a.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] << imm8;
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_sra_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	const UI1 sh = (count.__e > 15) ? 16 : count.__e;
#else
	const UI1 sh = (count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] > 15 || count.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] > 0) ? 16 : count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
#endif /* #! 64 !# */
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = MASTER_SRA2(a.__w[i], sh);
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_sra_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	const UI1 sh = (count.__e > 31) ? 32 : count.__e;
#else
	const UI1 sh = (count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] > 31 || count.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] > 0) ? 32 : count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
#endif /* #! 64 !# */
	c.__p[0] = MASTER_SRA4(a.__p[0], sh);
	c.__p[1] = MASTER_SRA4(a.__p[1], sh);
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_srai_pi16( MASTER_MMX_m64 a, SI4 imm8 ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = MASTER_SRA2(a.__w[i], imm8);
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_srai_pi32( MASTER_MMX_m64 a, SI4 imm8 ) {
	MASTER_MMX_m64 c;
	c.__p[0] = MASTER_SRA4(a.__p[0], imm8);
	c.__p[1] = MASTER_SRA4(a.__p[1], imm8);
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_srl_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	const UI1 sh = (count.__e > 15) ? 16 : count.__e;
#else
	const UI1 sh = (count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] > 15 || count.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] > 0) ? 16 : count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
#endif /* #! 64 !# */
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = a.__w[i] >> sh;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_srl_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	const UI1 sh = (count.__e > 31) ? 32 : count.__e;
#else
	const UI1 sh = (count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] > 31 || count.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] > 0) ? 32 : count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN];
#endif /* #! 64 !# */
	c.__p[0] = a.__p[0] >> sh;
	c.__p[1] = a.__p[1] >> sh;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_srl_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 count ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = a.__e >> count.__e;
#else
	if (count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] > 63 || count.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] > 0) return MASTER_MMX_mm_setzero_si64();
	c.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] = (a.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] >> count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN]) | (a.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] << (32 - count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN]));
	c.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] = (a.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] >> count.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN]);
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_srli_pi16( MASTER_MMX_m64 a, SI4 imm8 ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = a.__w[i] >> imm8;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_srli_pi32( MASTER_MMX_m64 a, SI4 imm8 ) {
	MASTER_MMX_m64 c;
	c.__p[0] = a.__p[0] >> imm8;
	c.__p[1] = a.__p[1] >> imm8;
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_srli_si64( MASTER_MMX_m64 a, SI4 imm8 ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = a.__e >> imm8;
#else
	c.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] = (a.__p[MASTER_ENDIANNESS == MASTER_BIG_ENDIAN] >> imm8) | (a.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] << (32 - imm8));
	c.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] = (a.__p[MASTER_ENDIANNESS != MASTER_BIG_ENDIAN] >> imm8);
#endif /* #! 64 !# */
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_sub_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__w[0] = a.__w[0] - b.__w[0];
	c.__w[1] = a.__w[1] - b.__w[1];
	c.__w[2] = a.__w[2] - b.__w[2];
	c.__w[3] = a.__w[3] - b.__w[3];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_sub_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__p[0] = a.__p[0] - b.__p[0];
	c.__p[1] = a.__p[1] - b.__p[1];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_sub_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1) c.__s[i] = a.__s[i] - b.__s[i];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_subs_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = MASTER_SubSaturateSI2(a.__w[i], b.__w[i]);
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_subs_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1)
		c.__w[i] = MASTER_SubSaturateSI1(a.__w[i], b.__w[i]);
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_subs_pu16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1)
		c.__w[i] = MASTER_SubSaturateUI2(a.__w[i], b.__w[i]);
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_subs_pu8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 8; i += 1)
		c.__w[i] = MASTER_SubSaturateUI1(a.__w[i], b.__w[i]);
	return c;
}

SI4
MASTER_MMX_m_to_int( MASTER_MMX_m64 a ) {
	return MASTER_MMX_mm_cvtsi64_si32(a);
}

#if MASTER_64_AVAILABLE == 1
SI8
MASTER_MMX_m_to_int64( MASTER_MMX_m64 a ) {
	return MASTER_MMX_mm_cvtm64_si64(a);
}
#endif /* #! 64 !# */

MASTER_MMX_m64
MASTER_MMX_mm_unpackhi_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__w[0] = a.__w[2];
	c.__w[1] = b.__w[2];
	c.__w[2] = a.__w[3];
	c.__w[3] = b.__w[3];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_unpackhi_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__p[0] = a.__p[1];
	c.__p[1] = b.__p[1];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_unpackhi_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1) {
		c.__s[i << 1] = a.__s[4 | i];
		c.__s[(i << 1) | 1] = b.__s[4 | i];
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_unpacklo_pi16( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__w[0] = a.__w[0];
	c.__w[1] = b.__w[0];
	c.__w[2] = a.__w[1];
	c.__w[3] = b.__w[1];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_unpacklo_pi32( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	c.__p[0] = a.__p[0];
	c.__p[1] = b.__p[0];
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_unpacklo_pi8( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
	UI1 i = 0;
	for (; i < 4; i += 1) {
		c.__s[i << 1] = a.__s[i];
		c.__s[(i << 1) | 1] = b.__s[i];
	}
	return c;
}

MASTER_MMX_m64
MASTER_MMX_mm_xor_si64( MASTER_MMX_m64 a, MASTER_MMX_m64 b ) {
	MASTER_MMX_m64 c;
#if MASTER_64_AVAILABLE == 1
	c.__e = a.__e ^ b.__e;
#else
	c.__p[0] = a.__p[0] ^ b.__p[0];
	c.__p[1] = a.__p[1] ^ b.__p[1];
#endif /* #! 64 !# */
	return c;
}

#endif /* #! __MASTER_FUTURE_MMX !# */

#endif /* #! __MASTER_MMX_REALIZATION_INCLUDE_H__ !# */

/* #! be master~ !# */
