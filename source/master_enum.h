
/* #!
 * Copyright (c) 2026 Adel'gid Aragami
 *
 * Licensed under the BSD 2-Clause License.
 * See the LICENSE file in the project root for more details.
 *
 * Source : https://github.com/Adel-gid/MASTER
 !# */

#ifndef MASTER_zzz_CODE_STYLE_H
#define MASTER_zzz_CODE_STYLE_H

#define MASTER_VERSION (((11) << 18) | ((1) << 14) | (2026))

/* #! MASTER Check Identifier Length !# */

#define MASTER_IDENTIFIER_LENGTH_CHECK3234363840424446485052545658606264z

/* #! If limit identifier length is 0, then the Devil only will stop the compilation !# */
#if defined(M) | /* #! 1 !# */ \
	defined(MA) | /* #! 2 !# */ \
	defined(MAS) | /* #! 3 !# */ \
	defined(MAST) | /* #! 4 !# */ \
	defined(MASTE) | /* #! 5 !# */ \
	defined(MASTER) | /* #! 6 !# */ \
	defined(MASTER_) | /* #! 7 !# */ \
	defined(MASTER_I) | /* #! 8 !# */ \
	defined(MASTER_ID) | /* #! 9 !# */ \
	defined(MASTER_IDE) | /* #! 10 !# */ \
	defined(MASTER_IDEN) | /* #! 11 !# */ \
	defined(MASTER_IDENT) | /* #! 12 !# */ \
	defined(MASTER_IDENTI) | /* #! 13 !# */ \
	defined(MASTER_IDENTIF) | /* #! 14 !# */ \
	defined(MASTER_IDENTIFI) | /* #! 15 !# */ \
	defined(MASTER_IDENTIFIE) | /* #! 16 !# */ \
	defined(MASTER_IDENTIFIER) | /* #! 17 !# */ \
	defined(MASTER_IDENTIFIER_) | /* #! 18 !# */ \
	defined(MASTER_IDENTIFIER_L) | /* #! 19 !# */ \
	defined(MASTER_IDENTIFIER_LE) | /* #! 20 !# */ \
	defined(MASTER_IDENTIFIER_LEN) | /* #! 21 !# */ \
	defined(MASTER_IDENTIFIER_LENG) | /* #! 22 !# */ \
	defined(MASTER_IDENTIFIER_LENGT) /* #! 23 !# */
#	if defined(__STDC__)
 #		error "Library can not be compiled with limit identifier length less than 24. Please, increase length limit."
#	else
		;!@; "Library can not be compiled with limit identifier length less than 24. Please, increase length limit."
#	endif /* #! Error !# */
#endif /* #! LIL < 24 !# */
#ifdef MASTER_IDENTIFIER_LENGTH
#	define MASTER_IDL 24
#elif defined(MASTER_IDENTIFIER_LENGTH_)
#	define MASTER_IDL 25
#elif defined(MASTER_IDENTIFIER_LENGTH_C)
#	define MASTER_IDL 26
#elif defined(MASTER_IDENTIFIER_LENGTH_CH)
#	define MASTER_IDL 27
#elif defined(MASTER_IDENTIFIER_LENGTH_CHE)
#	define MASTER_IDL 28
#elif defined(MASTER_IDENTIFIER_LENGTH_CHEC)
#	define MASTER_IDL 29
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK)
#	define MASTER_IDL 30
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3)
#	define MASTER_IDL 31
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32)
#	define MASTER_IDL 32
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323)
#	define MASTER_IDL 33
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234)
#	define MASTER_IDL 34
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343)
#	define MASTER_IDL 35
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436)
#	define MASTER_IDL 36
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363)
#	define MASTER_IDL 37
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638)
#	define MASTER_IDL 38
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384)
#	define MASTER_IDL 39
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840)
#	define MASTER_IDL 40
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638404)
#	define MASTER_IDL 41
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384042)
#	define MASTER_IDL 42
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840424)
#	define MASTER_IDL 43
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638404244)
#	define MASTER_IDL 44
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384042444)
#	define MASTER_IDL 45
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840424446)
#	define MASTER_IDL 46
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638404244464)
#	define MASTER_IDL 47
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384042444648)
#	define MASTER_IDL 48
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840424446485)
#	define MASTER_IDL 49
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638404244464850)
#	define MASTER_IDL 50
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384042444648505)
#	define MASTER_IDL 51
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840424446485052)
#	define MASTER_IDL 52
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638404244464850525)
#	define MASTER_IDL 53
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384042444648505254)
#	define MASTER_IDL 54
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840424446485052545)
#	define MASTER_IDL 55
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638404244464850525456)
#	define MASTER_IDL 56
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384042444648505254565)
#	define MASTER_IDL 57
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840424446485052545658)
#	define MASTER_IDL 58
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638404244464850525456586)
#	define MASTER_IDL 59
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384042444648505254565860)
#	define MASTER_IDL 60
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840424446485052545658606)
#	define MASTER_IDL 61
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK32343638404244464850525456586062)
#	define MASTER_IDL 62
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK323436384042444648505254565860626)
#	define MASTER_IDL 63
#elif defined(MASTER_IDENTIFIER_LENGTH_CHECK3234363840424446485052545658606264)
#	define MASTER_IDL 64
#else
#	define MASTER_IDL -1
#endif /* #! Identifier Length !# */

/* #! MASTER Syntax !# */

#define otherwise else if
#define nul 0

/* #! Declarator !# */

#ifdef __cplusplus
#	define MASTER_BEGIN_DECLARATIONS extern "C" {
#	define MASTER_END_DECLARATIONS }
#else
#	define MASTER_BEGIN_DECLARATIONS
#	define MASTER_END_DECLARATIONS
#endif /* #! C++ !# */

/* #! MASTER Predefined Macroses !# */

/* #!! K&R !!# */
#define MASTER_LINE __LINE__
#define MASTER_FILE __FILE__

/* #!! C89 !!# */
#define MASTER_DATE __DATE__
#define MASTER_TIME __TIME__

/* #!! C99 !!# */
#define MASTER_FUNC __func__

#if defined(__STDC__) || defined(__cplusplus)
#	define MASTER_PREPROC_CONCAT_AVAILABLE 1
#else
#	define MASTER_PREPROC_CONCAT_AVAILABLE 0
#endif /* #! K&R C !# */

#if MASTER_PREPROC_CONCAT_AVAILABLE
#	define MASTER_STRINGIFY( string ) #string
#	define MASTER_CONCAT( string1, string2 ) string1 ## string2
#	define MASTER_CONCAT3( string1, string2, string3 ) string1 ## string2 ## string3
#	define MASTER_CONCAT4( string1, string2, string3, string4 ) string1 ## string2 ## string3 ## string4
#else
#	define MASTER_STRINGIFY( string ) "string"
#	define MASTER_CONCAT( string1, string2 ) string1/**/string2
#	define MASTER_CONCAT3( string1, string2, string3 ) string1/**/string2/**/string3
#	define MASTER_CONCAT4( string1, string2, string3, string4 ) string1/**/string2/**/string3/**/string4
#endif /* #! K&R C !# */
#define MASTER_STRINGIFY_FALL( string ) MASTER_STRINGIFY(string)
#define MASTER_CONCAT_FALL( string1, string2 ) MASTER_CONCAT( string1, string2 )
#define MASTER_CONCAT3_FALL( string1, string2, string3 ) MASTER_CONCAT3( string1, string2, string3 )
#define MASTER_CONCAT4_FALL( string1, string2, string3, string4 ) MASTER_CONCAT4( string1, string2, string3, string4 )

/* #! MASTER String !# */

/* #! TODO : Use !# */
#ifndef MASTER_USE_LONG_STRING
	typedef char MASTER_char;
#	define MASTER_CHAR( character ) character
#	define MASTER_STRING( string ) string
#else
	typedef UI4 MASTER_char;
#	if MASTER_PREPROC_CONCAT_AVAILABLE
#		define MASTER_CHAR( character ) L ## character
#		define MASTER_STRING( string ) L ## string
#	else
#		define MASTER_CHAR( character ) L/**/character
#		define MASTER_STRING( string ) L/**/string
#	endif /* #! K&R C !# */
#endif /* #! Short / Long Strings !# */

/* #! MASTER Type Postfixes !# */

#if MASTER_PREPROC_CONCAT_AVAILABLE
#	define MASTER_L_POSTFIX_C( value ) value ## L
#	define MASTER_LL_POSTFIX_C( value ) value ## LL
#	define MASTER_UL_POSTFIX_C( value ) value ## UL
#	define MASTER_ULL_POSTFIX_C( value ) value ## ULL
#	define MASTER_SI4_POSTFIX_C( value ) value ## L
#	define MASTER_UI4_POSTFIX_C( value ) value ## UL
#	define MASTER_SI8_POSTFIX_C( value ) value ## LL
#	define MASTER_UI8_POSTFIX_C( value ) value ## ULL
#else
	/* #! In traditional compilers UL, ULL and LL prefix didn't exists - only L !# */
#	define MASTER_L_POSTFIX_C( value ) value/**/L
#	define MASTER_LL_POSTFIX_C( value ) value/**/L
#	define MASTER_UL_POSTFIX_C( value ) value/**/L
#	define MASTER_ULL_POSTFIX_C( value ) value/**/L
#	define MASTER_SI4_POSTFIX_C( value ) value/**/L
#	define MASTER_UI4_POSTFIX_C( value ) value/**/L
#	define MASTER_SI8_POSTFIX_C( value ) value/**/L
#	define MASTER_UI8_POSTFIX_C( value ) value/**/L
#endif /* #! K&R C !# */
#define MASTER_zzz_OP 0 +
#define MASTER_zzz_OP0L 0
#define MASTER_L_POSTFIX_S( value ) MASTER_CONCAT(MASTER_zzz_OP value, 0L)

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ + 0 < 199001L
#	define MASTER_CONSTANT( constant ) (UI4)constant
#else
#	define MASTER_CONSTANT( constant ) (UI8)constant
#endif /* #! C89 Variables !# */

/* #! MASTER Special !# */

#define MASTER_ERRORRISE ;!@;

/* #! MASTER Has* !# */

#if defined(__has_include) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_INCLUDE( includeFile ) __has_include(includeFile)
#	define MASTER_COMPILER_CAN_INCLUDE( includeFile ) MASTER_COMPILER_HAS_INCLUDE(includeFile)
#else
#	define MASTER_COMPILER_HAS_INCLUDE( includeFile ) (0)
#	define MASTER_COMPILER_CAN_INCLUDE( includeFile ) (1)
#endif /* #! Has include !# */
#if defined(__has_attribute) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_ATTRIBUTE( attribute ) __has_attribute(attribute)
#else
#	define MASTER_COMPILER_HAS_ATTRIBUTE( attribute ) (0)
#endif /* #! Has attribute !# */
#if defined(__has_builtin) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_BUILTIN( builtinMethod ) __has_builtin(builtinMethod)
#else
#	define MASTER_COMPILER_HAS_BUILTIN( builtinMethod ) (0)
#endif /* #! Has builtin !# */
#if ((defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 202311L) || defined(__has_c_attribute)) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_C_ATTRIBUTE( attribute ) __has_c_attribute(attribute)
#else
#	define MASTER_COMPILER_HAS_C_ATTRIBUTE( attribute ) (0)
#endif /* #! Has C attribute !# */
#if (defined(__cplusplus) || defined(__has_cpp_attribute)) && !defined(MASTER_NO_COMPILER_FEATURES)
#	define MASTER_COMPILER_HAS_CPP_ATTRIBUTE( attribute ) __has_cpp_attribute(attribute)
#else
#	define MASTER_COMPILER_HAS_CPP_ATTRIBUTE( attribute ) (0)
#endif /* #! Has C++ attribute !# */

/* #! MASTER Code Manipulations !# */

#define MASTER_UNBRACKET( arglist ) arglist
#define MASTER_REPEAT2( code ) code code
#define MASTER_REPEAT3( code ) code code code
#define MASTER_REPEAT4( code ) code code code code
#define MASTER_REPEAT5( code ) code code code code code
#define MASTER_COMMA_REPEAT2( code ) code, code
#define MASTER_COMMA_REPEAT3( code ) code, code, code
#define MASTER_COMMA_REPEAT4( code ) code, code, code, code
#define MASTER_COMMA_REPEAT5( code ) code, code, code, code, code
#define MASTER_CODE_REPEAT2( code ) code; code
#define MASTER_CODE_REPEAT3( code ) code; code; code
#define MASTER_CODE_REPEAT4( code ) code; code; code; code
#define MASTER_CODE_REPEAT5( code ) code; code; code; code; code
#define MASTER_DO_CODE_REPEAT2( code ) do { MASTER_REPEAT2(code); } while (0)
#define MASTER_DO_CODE_REPEAT3( code ) do { MASTER_REPEAT3(code); } while (0)
#define MASTER_DO_CODE_REPEAT4( code ) do { MASTER_REPEAT4(code); } while (0)
#define MASTER_DO_CODE_REPEAT5( code ) do { MASTER_REPEAT5(code); } while (0)
#define MASTER_XMACRO_CREATE_ENUM( variable, value, Unused3_ ) variable = value,
#define MASTER_XMACRO_CASE_STRING( variable, Unused2_, string ) case variable : return string;
#define MASTER_XMACRO_CREATE_NAME_ARRAY( variable, Unused2_, Unused3_ ) MASTER_STRINGIFY_FALL(variable),
#define MASTER_XMACRO_CREATE_VALUE_DICTIONARY( variable, value, Unused3_ ) MASTER_STRINGIFY_FALL(variable) " : " MASTER_STRINGIFY_FALL(value),
#define MASTER_XMACRO_CREATE_STRING_DICTIONARY( variable, Unused2_, string ) MASTER_STRINGIFY_FALL(variable) " : " MASTER_STRINGIFY_FALL(string),
#define MASTER_NOTHING ;
#define MASTER_CASE_SET( caseValue, valueToSet, setValue ) case (caseValue) : (valueToSet) = (setValue); break;
#define MASTER_TO_BOOL( expression ) (!!(expression))
#define MASTER_STATIC_ASSERT( expression ) (void)(sizeof(char [1 - 2 * !(expression)]))
#define MASTER_UNARG_BEGIN0()
#define MASTER_UNARG_BEGIN1( argument1 ) argument1,
#define MASTER_UNARG_BEGIN2( argument1, argument2 ) argument1, argument2,
#define MASTER_UNARG_BEGIN3( argument1, argument2, argument3 ) argument1, argument2, argument3,
#define MASTER_UNARG_BEGIN4( argument1, argument2, argument3, argument4 ) argument1, argument2, argument3, argument4,
#define MASTER_UNARG_BEGIN5( argument1, argument2, argument3, argument4, argument5 ) argument1, argument2, argument3, argument4, argument5,
#define MASTER_UNARG_BEGIN6( argument1, argument2, argument3, argument4, argument5, argument6 ) argument1, argument2, argument3, argument4, argument5, argument6,
#define MASTER_UNARG_BEGIN7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) argument1, argument2, argument3, argument4, argument5, argument6, argument7,
#define MASTER_UNARG_BEGIN8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8,
#define MASTER_UNARG_END0()
#define MASTER_UNARG_END1( argument1 ) , argument1
#define MASTER_UNARG_END2( argument1, argument2 ) , argument1, argument2
#define MASTER_UNARG_END3( argument1, argument2, argument3 ) , argument1, argument2, argument3
#define MASTER_UNARG_END4( argument1, argument2, argument3, argument4 ) , argument1, argument2, argument3, argument4
#define MASTER_UNARG_END5( argument1, argument2, argument3, argument4, argument5 ) , argument1, argument2, argument3, argument4, argument5
#define MASTER_UNARG_END6( argument1, argument2, argument3, argument4, argument5, argument6 ) , argument1, argument2, argument3, argument4, argument5, argument6
#define MASTER_UNARG_END7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) , argument1, argument2, argument3, argument4, argument5, argument6, argument7
#define MASTER_UNARG_END8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) , argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8
#define MASTER_CALL_FUNCTION2( function, argList1, argList2 ) function argList1 function argList2
#define MASTER_CALL_FUNCTION3( function, argList1, argList2, argList3 ) function argList1 function argList2 function argList3
#define MASTER_CALL_FUNCTION4( function, argList1, argList2, argList3, argList4 ) function argList1 function argList2 function argList3 function argList4
#define MASTER_CALL_FUNCTION5( function, argList1, argList2, argList3, argList4, argList5 ) function argList1 function argList2 function argList3 function argList4 function argList5
#define MASTER_CALL_FUNCTION6( function, argList1, argList2, argList3, argList4, argList5, argList6 ) function argList1 function argList2 function argList3 function argList4 function argList5 function argList6
#define MASTER_CALL_FUNCTION7( function, argList1, argList2, argList3, argList4, argList5, argList6, argList7 ) function argList1 function argList2 function argList3 function argList4 function argList5 function argList6 function argList7
#define MASTER_CALL_FUNCTION8( function, argList1, argList2, argList3, argList4, argList5, argList6, argList7, argList8 ) function argList1 function argList2 function argList3 function argList4 function argList5 function argList6 function argList7 function argList8

/* #! MASTER Argument List Macroses !# */

#define MASTER_KAIR_ARG( argumentType, argument ) argument
#define MASTER_KAIR_DECL( argumentType, argument ) argumentType argument
#define MASTER_KAIR_EXTERN_ARGS_LIST( arguments ) ()
#define MASTER_KAIR_FORMAT0() ()
#define MASTER_KAIR_FORMAT1( argument ) ( MASTER_KAIR_ARG argument ) MASTER_KAIR_DECL argument;
#define MASTER_KAIR_FORMAT2( argument1, argument2 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2;
#define MASTER_KAIR_FORMAT3( argument1, argument2, argument3 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3;
#define MASTER_KAIR_FORMAT4( argument1, argument2, argument3, argument4 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4;
#define MASTER_KAIR_FORMAT5( argument1, argument2, argument3, argument4, argument5 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4, MASTER_KAIR_ARG argument5 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4; MASTER_KAIR_DECL argument5;
#define MASTER_KAIR_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4, MASTER_KAIR_ARG argument5, MASTER_KAIR_ARG argument6 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4; MASTER_KAIR_DECL argument5; MASTER_KAIR_DECL argument6;
#define MASTER_KAIR_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4, MASTER_KAIR_ARG argument5, MASTER_KAIR_ARG argument6, MASTER_KAIR_ARG argument7 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4; MASTER_KAIR_DECL argument5; MASTER_KAIR_DECL argument6; MASTER_KAIR_DECL argument7;
#define MASTER_KAIR_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) ( MASTER_KAIR_ARG argument1, MASTER_KAIR_ARG argument2, MASTER_KAIR_ARG argument3, MASTER_KAIR_ARG argument4, MASTER_KAIR_ARG argument5, MASTER_KAIR_ARG argument6, MASTER_KAIR_ARG argument7, MASTER_KAIR_ARG argument8 ) MASTER_KAIR_DECL argument1; MASTER_KAIR_DECL argument2; MASTER_KAIR_DECL argument3; MASTER_KAIR_DECL argument4; MASTER_KAIR_DECL argument5; MASTER_KAIR_DECL argument6; MASTER_KAIR_DECL argument7; MASTER_KAIR_DECL argument8;

#define MASTER_STD_DECL( argumentType, argument ) argumentType argument
#define MASTER_STD_EXTERN_ARGS_LIST( arguments ) arguments
#define MASTER_STD_FORMAT0() ( void )
#define MASTER_STD_FORMAT1( argument ) ( MASTER_STD_DECL argument )
#define MASTER_STD_FORMAT2( argument1, argument2 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2 )
#define MASTER_STD_FORMAT3( argument1, argument2, argument3 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3 )
#define MASTER_STD_FORMAT4( argument1, argument2, argument3, argument4 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4 )
#define MASTER_STD_FORMAT5( argument1, argument2, argument3, argument4, argument5 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4, MASTER_STD_DECL argument5 )
#define MASTER_STD_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4, MASTER_STD_DECL argument5, MASTER_STD_DECL argument6 )
#define MASTER_STD_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4, MASTER_STD_DECL argument5, MASTER_STD_DECL argument6, MASTER_STD_DECL argument7 )
#define MASTER_STD_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) ( MASTER_STD_DECL argument1, MASTER_STD_DECL argument2, MASTER_STD_DECL argument3, MASTER_STD_DECL argument4, MASTER_STD_DECL argument5, MASTER_STD_DECL argument6, MASTER_STD_DECL argument7, MASTER_STD_DECL argument8 )

#if defined(__cplusplus) || (defined(__STDC__) && !defined(MASTER_TRADITIONAL_COMPILE))
	/* #! Modern compilers need prototypes !# */
#	ifdef MASTER_CHECK_IF_FUNCTION_IS_EXTERNED_BUT_NOT_IMPLEMENTED
#		define MASTER_EXTERN_FUNCTION( flags, returnValueAndExtras, functionName, arguments ) MASTER_PREFER_EXTERN returnValueAndExtras functionName MASTER_STD_EXTERN_ARGS_LIST(arguments); \
	returnValueAndExtras (*MASTER_CONCAT_FALL(functionName, _Pointer))MASTER_STD_EXTERN_ARGS_LIST(arguments) = functionName
#	else
#		define MASTER_EXTERN_FUNCTION( flags, returnValueAndExtras, functionName, arguments ) MASTER_PREFER_EXTERN returnValueAndExtras functionName MASTER_STD_EXTERN_ARGS_LIST(arguments)
#	endif /* #! Extension : Function is externed but not implemented !# */
#	define MASTER_ARGLIST_FORMAT0() MASTER_STD_FORMAT0()
#	define MASTER_ARGLIST_FORMAT1( argument ) MASTER_STD_FORMAT1(argument)
#	define MASTER_ARGLIST_FORMAT2( argument1, argument2 ) MASTER_STD_FORMAT2( argument1, argument2 )
#	define MASTER_ARGLIST_FORMAT3( argument1, argument2, argument3 ) MASTER_STD_FORMAT3( argument1, argument2, argument3 )
#	define MASTER_ARGLIST_FORMAT4( argument1, argument2, argument3, argument4 ) MASTER_STD_FORMAT4( argument1, argument2, argument3, argument4 )
#	define MASTER_ARGLIST_FORMAT5( argument1, argument2, argument3, argument4, argument5 ) MASTER_STD_FORMAT5( argument1, argument2, argument3, argument4, argument5 )
#	define MASTER_ARGLIST_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 ) MASTER_STD_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 )
#	define MASTER_ARGLIST_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) MASTER_STD_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 )
#	define MASTER_ARGLIST_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) MASTER_STD_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 )
#	define MASTER_zzz_PREFER_RO_ARG( argumentIndex ) MASTER_PREFER_RO_ARG(argumentIndex)
#	define MASTER_zzz_PREFER_WO_ARG( argumentIndex ) MASTER_PREFER_WO_ARG(argumentIndex)
#	define MASTER_zzz_PREFER_RW_ARG( argumentIndex ) MASTER_PREFER_WW_ARG(argumentIndex)
#	define MASTER_zzz_PREFER_ROS_ARG( argumentIndex, argumentSize ) MASTER_PREFER_ROS_ARG(argumentIndex, argumentSize)
#	define MASTER_zzz_PREFER_WOS_ARG( argumentIndex, argumentSize ) MASTER_PREFER_WOS_ARG(argumentIndex, argumentSize)
#	define MASTER_zzz_PREFER_RWS_ARG( argumentIndex, argumentSize ) MASTER_PREFER_RWS_ARG(argumentIndex, argumentSize)
#	define MASTER_zzz_PREFER_NRW_ARG( argumentIndex ) MASTER_PREFER_NRW_ARG(argumentIndex)
#else
	/* #! Traditional compilers need only declarations !# */
#	ifdef MASTER_CHECK_IF_FUNCTION_IS_EXTERNED_BUT_NOT_IMPLEMENTED
#		define MASTER_EXTERN_FUNCTION( flags, returnValueAndExtras, functionName, arguments ) MASTER_PREFER_EXTERN returnValueAndExtras functionName MASTER_KAIR_EXTERN_ARGS_LIST(arguments); \
	return returnValueAndExtras (*MASTER_CONCAT_FALL(functionName, _Pointer))MASTER_KAIR_EXTERN_ARGS_LIST(arguments) = functionName
#	else
#		define MASTER_EXTERN_FUNCTION( flags, returnValueAndExtras, functionName, arguments ) MASTER_PREFER_EXTERN returnValueAndExtras functionName MASTER_KAIR_EXTERN_ARGS_LIST(arguments)
#	endif /* #! Extension : Function is externed but not implemented !# */
#	define MASTER_ARGLIST_FORMAT0() MASTER_KAIR_FORMAT0()
#	define MASTER_ARGLIST_FORMAT1( argument ) MASTER_KAIR_FORMAT1(argument)
#	define MASTER_ARGLIST_FORMAT2( argument1, argument2 ) MASTER_KAIR_FORMAT2( argument1, argument2 )
#	define MASTER_ARGLIST_FORMAT3( argument1, argument2, argument3 ) MASTER_KAIR_FORMAT3( argument1, argument2, argument3 )
#	define MASTER_ARGLIST_FORMAT4( argument1, argument2, argument3, argument4 ) MASTER_KAIR_FORMAT4( argument1, argument2, argument3, argument4 )
#	define MASTER_ARGLIST_FORMAT5( argument1, argument2, argument3, argument4, argument5 ) MASTER_KAIR_FORMAT5( argument1, argument2, argument3, argument4, argument5 )
#	define MASTER_ARGLIST_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 ) MASTER_KAIR_FORMAT6( argument1, argument2, argument3, argument4, argument5, argument6 )
#	define MASTER_ARGLIST_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) MASTER_KAIR_FORMAT7( argument1, argument2, argument3, argument4, argument5, argument6, argument7 )
#	define MASTER_ARGLIST_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) MASTER_KAIR_FORMAT8( argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 )
#	define MASTER_zzz_PREFER_RO_ARG( argumentIndex ) /* #! Empty !# */
#	define MASTER_zzz_PREFER_WO_ARG( argumentIndex ) /* #! Empty !# */
#	define MASTER_zzz_PREFER_RW_ARG( argumentIndex ) /* #! Empty !# */
#	define MASTER_zzz_PREFER_ROS_ARG( argumentIndex, argumentSize ) /* #! Empty !# */
#	define MASTER_zzz_PREFER_WOS_ARG( argumentIndex, argumentSize ) /* #! Empty !# */
#	define MASTER_zzz_PREFER_RWS_ARG( argumentIndex, argumentSize ) /* #! Empty !# */
#	define MASTER_zzz_PREFER_NRW_ARG( argumentIndex ) /* #! Empty !# */
#endif /* #! Detect Argument List Compability for C & C++ !# */

#define MASTER_DEFINE_FUNCTION0( flags, description, functionName, returnValueAndExtras ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT0()
#define MASTER_DEFINE_FUNCTION1( flags, description, functionName, returnValueAndExtras, argument ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT1(argument)
#define MASTER_DEFINE_FUNCTION2( flags, description, functionName, returnValueAndExtras, argument1, argument2 ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT2(argument1, argument2)
#define MASTER_DEFINE_FUNCTION3( flags, description, functionName, returnValueAndExtras, argument1, argument2, argument3 ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT3(argument1, argument2, argument3)
#define MASTER_DEFINE_FUNCTION4( flags, description, functionName, returnValueAndExtras, argument1, argument2, argument3, argument4 ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT4(argument1, argument2, argument3, argument4)
#define MASTER_DEFINE_FUNCTION5( flags, description, functionName, returnValueAndExtras, argument1, argument2, argument3, argument4, argument5 ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT5(argument1, argument2, argument3, argument4, argument5)
#define MASTER_DEFINE_FUNCTION6( flags, description, functionName, returnValueAndExtras, argument1, argument2, argument3, argument4, argument5, argument6 ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT6(argument1, argument2, argument3, argument4, argument5, argument6)
#define MASTER_DEFINE_FUNCTION7( flags, description, functionName, returnValueAndExtras, argument1, argument2, argument3, argument4, argument5, argument6, argument7 ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT7(argument1, argument2, argument3, argument4, argument5, argument6, argument7)
#define MASTER_DEFINE_FUNCTION8( flags, description, functionName, returnValueAndExtras, argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8 ) returnValueAndExtras functionName MASTER_ARGLIST_FORMAT8(argument1, argument2, argument3, argument4, argument5, argument6, argument7, argument8)

#define MASTER_EMPTY_DESCRIPTION /* #! No description is provided !# */
#define MASTER_NO_FLAGS

#define MASTER_PREFER_EXTERN extern

#include <architecture_detect.h>
#include <compiler_detect.h>
#include <simd_detect.h>
#include <operating_system_detect.h>

#include <library.h>

MASTER_BEGIN_DECLARATIONS

/* #! compiler trash !# */

#define MASTER_UNKNOWN (-1)
#define MASTER_UNSUPPORTING (0)
#define MASTER_PARTIAL_SUPPORTING (5)
#define MASTER_SUPPORTING (10)
#define MASTER_SUPPORT_STATE( nivel ) (nivel)

#ifndef MASTER_COMPILER_C89_AVAILABLE
#	define MASTER_COMPILER_C89_AVAILABLE MASTER_UNKNOWN
#endif /* #! C89 support !# */
#ifndef MASTER_COMPILER_C95_AVAILABLE
#	define MASTER_COMPILER_C95_AVAILABLE MASTER_UNKNOWN
#endif /* #! C95 support !# */
#ifndef MASTER_COMPILER_C99_AVAILABLE
#	define MASTER_COMPILER_C99_AVAILABLE MASTER_UNKNOWN
#endif /* #! C99 support !# */
#ifndef MASTER_COMPILER_C11_AVAILABLE
#	define MASTER_COMPILER_C11_AVAILABLE MASTER_UNKNOWN
#endif /* #! C11 support !# */
#ifndef MASTER_COMPILER_C17_AVAILABLE
#	define MASTER_COMPILER_C17_AVAILABLE MASTER_UNKNOWN
#endif /* #! C17 support !# */
#ifndef MASTER_COMPILER_C23_AVAILABLE
#	define MASTER_COMPILER_C23_AVAILABLE MASTER_UNKNOWN
#endif /* #! C23 support !# */
#ifndef MASTER_COMPILER_C29_AVAILABLE
#	define MASTER_COMPILER_C29_AVAILABLE MASTER_UNKNOWN
#endif /* #! C29 support !# */
#ifndef MASTER_COMPILER_CPP98_AVAILABLE
#	define MASTER_COMPILER_CPP98_AVAILABLE MASTER_UNKNOWN
#endif /* #! C++98 support !# */
#ifndef MASTER_COMPILER_CPP03_AVAILABLE
#	define MASTER_COMPILER_CPP03_AVAILABLE MASTER_UNKNOWN
#endif /* #! C++03 support !# */
#ifndef MASTER_COMPILER_CPP11_AVAILABLE
#	define MASTER_COMPILER_CPP11_AVAILABLE MASTER_UNKNOWN
#endif /* #! C++11 support !# */
#ifndef MASTER_COMPILER_CPP14_AVAILABLE
#	define MASTER_COMPILER_CPP14_AVAILABLE MASTER_UNKNOWN
#endif /* #! C++14 support !# */
#ifndef MASTER_COMPILER_CPP17_AVAILABLE
#	define MASTER_COMPILER_CPP17_AVAILABLE MASTER_UNKNOWN
#endif /* #! C++17 support !# */
#ifndef MASTER_COMPILER_CPP20_AVAILABLE
#	define MASTER_COMPILER_CPP20_AVAILABLE MASTER_UNKNOWN
#endif /* #! C++20 support !# */
#ifndef MASTER_COMPILER_CPP23_AVAILABLE
#	define MASTER_COMPILER_CPP23_AVAILABLE MASTER_UNKNOWN
#endif /* #! C++23 support !# */
#ifndef MASTER_COMPILER_CPP26_AVAILABLE
#	define MASTER_COMPILER_CPP26_AVAILABLE MASTER_UNKNOWN
#endif /* #! C++26 support !# */
#ifndef MASTER_COMPILER_GNU_AVAILABLE
#	define MASTER_COMPILER_GNU_AVAILABLE MASTER_UNKNOWN
#endif /* #! GNU extension support !# */
#ifndef MASTER_COMPILER_GNUPP_AVAILABLE
#	define MASTER_COMPILER_GNUPP_AVAILABLE MASTER_UNKNOWN
#endif /* #! GNU++ extension support !# */
#ifndef MASTER_COMPILER_TRIGRAPH_AVAILABLE
#	define MASTER_COMPILER_TRIGRAPH_AVAILABLE MASTER_UNKNOWN
#endif /* #! Trigraph support !# */
#ifndef MASTER_COMPILER_COM_COMPILE_AVAILABLE
#	define MASTER_COMPILER_COM_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! COM compile support !# */
#ifndef MASTER_COMPILER_EXE_COMPILE_AVAILABLE
#	define MASTER_COMPILER_EXE_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! EXE compile support !# */
#ifndef MASTER_COMPILER_ELF_COMPILE_AVAILABLE
#	define MASTER_COMPILER_ELF_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! ELF compile support !# */
#ifndef MASTER_COMPILER_BIN_COMPILE_AVAILABLE
#	define MASTER_COMPILER_BIN_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! BIN compile support !# */
#ifndef MASTER_COMPILER_PE_COMPILE_AVAILABLE
#	define MASTER_COMPILER_PE_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! PE compile support !# */
#ifndef MASTER_COMPILER_MACH_O_COMPILE_AVAILABLE
#	define MASTER_COMPILER_MACH_O_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! MACH-O compile support !# */
#ifndef MASTER_COMPILER_COFF_COMPILE_AVAILABLE
#	define MASTER_COMPILER_COFF_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! COFF compile support !# */
#ifndef MASTER_COMPILER_XCOFF_COMPILE_AVAILABLE
#	define MASTER_COMPILER_XCOFF_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! XCOFF compile support !# */
#ifndef MASTER_COMPILER_SHARED_LIB_COMPILE_AVAILABLE
#	define MASTER_COMPILER_SHARED_LIB_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! Shared Lib compile support !# */
#ifndef MASTER_COMPILER_OBJ_COMPILE_AVAILABLE
#	define MASTER_COMPILER_OBJ_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! OBJ compile support !# */
#ifndef MASTER_COMPILER_ASM_COMPILE_AVAILABLE
#	define MASTER_COMPILER_ASM_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! ASM compile support !# */
#ifndef MASTER_COMPILER_PREPROC_COMPILE_AVAILABLE
#	define MASTER_COMPILER_PREPROC_COMPILE_AVAILABLE MASTER_UNKNOWN
#endif /* #! Preprocessing support !# */
#ifndef MASTER_COMPILER_COMPILE_TYPE
#	define MASTER_COMPILER_COMPILE_TYPE 0
#endif /* #! Compile type !# */
#ifndef MASTER_COMPILER_ARCH64_COMPILE_AVAILABLE
#	define MASTER_COMPILER_ARCH64_COMPILE_AVAILABLE 0
#endif /* #! Aarch64 compile support !# */
#ifndef MASTER_COMPILER_ARM_COMPILE_AVAILABLE
#	define MASTER_COMPILER_ARM_COMPILE_AVAILABLE 0
#endif /* #! ARM compile support !# */
#ifndef MASTER_COMPILER_THUMB_COMPILE_AVAILABLE
#	define MASTER_COMPILER_THUMB_COMPILE_AVAILABLE 0
#endif /* #! THUMB compile support !# */
#ifndef MASTER_COMPILER_MIPS_COMPILE_AVAILABLE
#	define MASTER_COMPILER_MIPS_COMPILE_AVAILABLE 0
#endif /* #! MIPS compile support !# */
#ifndef MASTER_COMPILER_PPC_COMPILE_AVAILABLE
#	define MASTER_COMPILER_PPC_COMPILE_AVAILABLE 0
#endif /* #! PPC compile support !# */
#ifndef MASTER_COMPILER_PPC64_COMPILE_AVAILABLE
#	define MASTER_COMPILER_PPC64_COMPILE_AVAILABLE 0
#endif /* #! PPC64 compile support !# */
#ifndef MASTER_COMPILER_MIPS64_COMPILE_AVAILABLE
#	define MASTER_COMPILER_MIPS64_COMPILE_AVAILABLE 0
#endif /* #! MIPS64 compile support !# */
#ifndef MASTER_COMPILER_X86_64_COMPILE_AVAILABLE
#	define MASTER_COMPILER_X86_64_COMPILE_AVAILABLE 0
#endif /* #! X86-64 compile support !# */
#ifndef MASTER_COMPILER_I386_COMPILE_AVAILABLE
#	define MASTER_COMPILER_I386_COMPILE_AVAILABLE 0
#endif /* #! I386 compile support !# */
#ifndef MASTER_COMPILER_X16_COMPILE_AVAILABLE
#	define MASTER_COMPILER_X16_COMPILE_AVAILABLE 0
#endif /* #! X16 compile support !# */
/* #! TODO : SIZES !# */
#ifndef MASTER_COMPILER_HAS_SIGNED_INT_8
#	define MASTER_COMPILER_HAS_SIGNED_INT_8 0
#endif /* #! Has SI8 !# */
#ifndef MASTER_COMPILER_HAS_SIGNED_INT_16
#	define MASTER_COMPILER_HAS_SIGNED_INT_16 0
#endif /* #! Has SI16 !# */
#ifndef MASTER_COMPILER_HAS_SIGNED_INT_32
#	define MASTER_COMPILER_HAS_SIGNED_INT_32 0
#endif /* #! Has SI32 !# */
#ifndef MASTER_COMPILER_HAS_SIGNED_INT_64
#	define MASTER_COMPILER_HAS_SIGNED_INT_64 0
#endif /* #! Has SI64 !# */
#ifndef MASTER_COMPILER_HAS_SIGNED_INT_128
#	define MASTER_COMPILER_HAS_SIGNED_INT_128 0
#endif /* #! Has SI128 !# */
#ifndef MASTER_COMPILER_HAS_UNSIGNED_INT_8
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_8 0
#endif /* #! Has UI8 !# */
#ifndef MASTER_COMPILER_HAS_UNSIGNED_INT_16
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_16 0
#endif /* #! Has UI16 !# */
#ifndef MASTER_COMPILER_HAS_UNSIGNED_INT_32
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_32 0
#endif /* #! Has UI32 !# */
#ifndef MASTER_COMPILER_HAS_UNSIGNED_INT_64
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_64 0
#endif /* #! Has UI64 !# */
#ifndef MASTER_COMPILER_HAS_UNSIGNED_INT_128
#	define MASTER_COMPILER_HAS_UNSIGNED_INT_128 0
#endif /* #! Has UI128 !# */
#ifndef MASTER_zzz_COMPILER_FEATURES_LOADED
#	define MASTER_COMPILER_SIZEOF_POINTER sizeof(void *)
#	define MASTER_COMPILER_SIZEOF_CHAR sizeof(char)
#	define MASTER_COMPILER_SIZEOF_SHORT sizeof(short)
#	define MASTER_COMPILER_SIZEOF_INT sizeof(int)
#	define MASTER_COMPILER_SIZEOF_LONG sizeof(long)
#	define MASTER_COMPILER_SIZEOF_LONG_LONG sizeof(long long)
#	define MASTER_COMPILER_SIZEOF_SIZE_T sizeof(size_t)
#	define MASTER_COMPILER_BYTE_ALIGN_UNDER_QUESTION
#	define MASTER_zzz_COMPILER_FEATURES_LOADED 0
#endif /* #! Warning Available !# */
#ifndef MASTER_PREFER_OPTIMIZE
#	define MASTER_PREFER_OPTIMIZE
#endif /* #! Flag : optimize !# */
#ifndef MASTER_PREFER_NOOPTIMIZE
#	define MASTER_PREFER_NOOPTIMIZE
#endif /* #! Flag : no optimize !# */
#ifndef MASTER_PREFER_NOINLINE
#	define MASTER_PREFER_NOINLINE
#endif /* #! Flag : no inline !# */
#ifndef MASTER_PREFER_INLINE
#	if MASTER_PREFER_CPP_SUPPORTED || MASTER_PREFER_C99_SUPPORTED
#		define MASTER_PREFER_INLINE inline
#	else
#		define MASTER_PREFER_INLINE
#	endif /* #! C++ / C99+ !# */
#endif /* #! Flag : inline !# */
#ifndef MASTER_PREFER_FORCE_INLINE
#	define MASTER_PREFER_FORCE_INLINE
#endif /* #! Flag : force inline !# */
#ifndef MASTER_PREFER_STATIC
#	define MASTER_PREFER_STATIC static
#endif /* #! Flag : static !# */
#ifndef MASTER_PREFER_ASM_VOLATILE
#	define MASTER_PREFER_ASM_VOLATILE __asm__
#endif /* #! Flag : volatile asm !# */
#ifndef MASTER_PREFER_NONNULL
#	define MASTER_PREFER_NONNULL
#endif /* #! Flag : non null !# */
#ifndef MASTER_PREFER_NONNULL_ARG
#	define MASTER_PREFER_NONNULL_ARG( argument )
#endif /* #! Flag : non null argument !# */
#ifndef MASTER_PREFER_RETURN_REQUIRED
#	define MASTER_PREFER_RETURN_REQUIRED
#endif /* #! Flag : return required !# */
#ifndef MASTER_PREFER_RO_ARG
#	define MASTER_PREFER_RO_ARG( argumentIndex )
#endif /* #! Flag : read only argument !# */
#ifndef MASTER_PREFER_WO_ARG
#	define MASTER_PREFER_WO_ARG( argumentIndex )
#endif /* #! Flag : write only argument !# */
#ifndef MASTER_PREFER_RW_ARG
#	define MASTER_PREFER_RW_ARG( argumentIndex )
#endif /* #! Flag : read-write argument !# */
#ifndef MASTER_PREFER_ROS_ARG
#	define MASTER_PREFER_ROS_ARG( argumentIndex, argumentSize )
#endif /* #! Flag : read only argument with size !# */
#ifndef MASTER_PREFER_WOS_ARG
#	define MASTER_PREFER_WOS_ARG( argumentIndex, argumentSize )
#endif /* #! Flag : write only argument with size !# */
#ifndef MASTER_PREFER_RWS_ARG
#	define MASTER_PREFER_RWS_ARG( argumentIndex, argumentSize )
#endif /* #! Flag : read-write argument with size !# */
#ifndef MASTER_PREFER_NRW_ARG
#	define MASTER_PREFER_NRW_ARG( argumentIndex )
#endif /* #! Flag : none argument !# */
#ifndef MASTER_PREFER_WARN
#	define MASTER_PREFER_WARN( message )
#endif /* #! Flag : warn !# */
#ifndef MASTER_PREFER_ERROR
#	define MASTER_PREFER_ERROR( message )
#endif /* #! Flag : error !# */
#ifndef MASTER_PREFER_OUTDATED
#	if MASTER_PREFER_CPP_SUPPORTED || MASTER_PREFER_C17_SUPPORTED
#		define MASTER_PREFER_OUTDATED [[deprecated]]
#	else
#		define MASTER_PREFER_OUTDATED
#	endif /* #! C++ / C17+ !# */
#endif /* #! Flag : outdated !# */
#ifndef MASTER_PREFER_UNUSED
#	if MASTER_PREFER_CPP_SUPPORTED || MASTER_PREFER_C23_SUPPORTED
#		define MASTER_PREFER_UNUSED [[maybe_unused]]
#	else
#		define MASTER_PREFER_UNUSED
#	endif /* #! C++ / C23+ !# */
#endif /* #! Flag : unused !# */
#ifndef MASTER_PREFER_UNSAFE
#	define MASTER_PREFER_UNSAFE
#endif /* #! Flag : unsafe !# */
#ifndef MASTER_PREFER_NO_RETURN
#	define MASTER_PREFER_NO_RETURN
#endif /* #! Flag : no return from function !# */
#ifndef MASTER_PREFER_WEAK
#	define MASTER_PREFER_WEAK
#endif /* #! Flag : weak symbol !# */
#ifndef MASTER_PREFER_LIKELY
#	define MASTER_PREFER_LIKELY( expression ) (expression)
#endif /* #! Flag : likely !# */
#ifndef MASTER_PREFER_UNLIKELY
#	define MASTER_PREFER_UNLIKELY( expression ) (expression)
#endif /* #! Flag : unlikely !# */
#ifndef MASTER_PREFER_UNREACHABLE
#	define MASTER_PREFER_UNREACHABLE
#endif /* #! Flag : unreachable !# */
#ifndef MASTER_PREFER_FALLTHROUGH
#	define MASTER_PREFER_FALLTHROUGH
#endif /* #! Flag : fallthrough !# */
#ifndef MASTER_PREFER_HOT
#	define MASTER_PREFER_HOT
#endif /* #! Flag : hot !# */
#ifndef MASTER_PREFER_COLD
#	define MASTER_PREFER_COLD
#endif /* #! Flag : cold !# */
#ifndef MASTER_PREFER_FAR
#	define MASTER_PREFER_FAR
#endif /* #! Flag : far pointer !# */
#ifndef MASTER_PREFER_NEAR
#	define MASTER_PREFER_NEAR
#endif /* #! Flag : near pointer !# */
#ifndef MASTER_PREFER_INTERRUPT
#	define MASTER_PREFER_INTERRUPT
#endif /* #! Flag : interrupt !# */
#ifndef MASTER_PREFER_SEGMENT
#	define MASTER_PREFER_SEGMENT
#endif /* #! Flag : segment !# */
#ifndef MASTER_PREFER_PACKED
#	define MASTER_PREFER_PACKED
#endif /* #! Flag : packed !# */
#ifndef MASTER_PREFER_INLINEOUS
#	define MASTER_PREFER_INLINEOUS
#endif /* #! Flag : inlineous !# */
#ifndef MASTER_PREFER_TYPEOF
#	define MASTER_PREFER_TYPEOF( expression )
#endif /* #! Flag : type of !# */
#ifndef MASTER_PREFER_STATIC_ASSERT
#	define MASTER_PREFER_STATIC_ASSERT( expression, message )
#endif /* #! Flag : static assert !# */
#ifndef MASTER_PREFER_CONSTRUCTOR
#	define MASTER_PREFER_CONSTRUCTOR
#endif /* #! Flag : constructor !# */
#ifndef MASTER_PREFER_DESTRUCTOR
#	define MASTER_PREFER_DESTRUCTOR
#endif /* #! Flag : destructor !# */
#ifndef MASTER_PREFER_FUNCTION_NAKED
#	define MASTER_PREFER_FUNCTION_NAKED
#endif /* #! Flag : naked function !# */
#ifndef MASTER_PREFER_FUNCTION_MALLOC
#	define MASTER_PREFER_FUNCTION_MALLOC
#endif /* #! Flag : malloc function !# */
#ifndef MASTER_PREFER_FUNCTION_PURE
#	define MASTER_PREFER_FUNCTION_PURE
#endif /* #! Flag : pure function !# */
#ifndef MASTER_PREFER_FUNCTION_CONST
#	define MASTER_PREFER_FUNCTION_CONST
#endif /* #! Flag : const function !# */
#ifndef MASTER_PREFER_ALIGNAS
#	if MASTER_PREFER_C11_SUPPORTED
#		define MASTER_PREFER_ALIGNAS( alignValue ) _Alignas(alignValue)
#	elif MASTER_PREFER_CPP11_SUPPORTED
#		define MASTER_PREFER_ALIGNAS( alignValue ) alignas(alignValue)
#	else
#		define MASTER_PREFER_ALIGNAS( alignValue )
#	endif /* #! C11+ / C++11+ !# */
#endif /* #! Flas : align as !# */
#ifndef MASTER_PREFER_IMPORT
#	define MASTER_PREFER_IMPORT
#endif /* #! Flag : import !# */
#ifndef MASTER_PREFER_EXPORT
#	define MASTER_PREFER_EXPORT
#endif /* #! Flag : export !# */
#ifndef MASTER_PREFER_VISIBLE
#	define MASTER_PREFER_VISIBLE
#endif /* #! Flag : visible !# */
#ifndef MASTER_PREFER_HIDDEN
#	define MASTER_PREFER_HIDDEN
#endif /* #! Flag : hidden !# */
#ifndef MASTER_PREFER_MAY_ALIAS
#	define MASTER_PREFER_MAY_ALIAS
#endif /* #! Flag : may alias !# */
#ifndef MASTER_PREFER_PREFETCH
#	define MASTER_PREFER_PREFETCH( pointer ) ((void)(pointer))
#endif /* #! Flag : prefetch !# */
#ifndef MASTER_PREFER_PUSH_POP_AVAILABLE
#	define MASTER_PREFER_PUSH_POP_AVAILABLE (0)
#endif /* #! Flag : push pop support !# */
#ifndef MASTER_PREFER_RESTRICT
#	if MASTER_PREFER_C99_SUPPORTED
#		define MASTER_PREFER_RESTRICT restrict
#	else
#		define MASTER_PREFER_RESTRICT
#	endif /* #! C99+ !# */
#endif /* #! Flag : restrict !# */
#ifndef MASTER_COMPILER_WARNING_AVAIL
#	if MASTER_PREFER_CPP23_SUPPORTED || MASTER_PREFER_C23_SUPPORTED
#		define MASTER_COMPILER_WARNING_AVAIL 1
#	else
#		define MASTER_COMPILER_WARNING_AVAIL 0
#	endif /* #! C++23+ || C23+ !# */
#endif /* #! Flag : warning support !# */

#ifdef MASTER_NO_RESTRICTIONS
#	undef MASTER_PREFER_RESTRICT
#	define MASTER_PREFER_RESTRICT
#endif /* #! Turn off restrictions !# */

#define MASTER_PREFER_DEPRECATED MASTER_PREFER_OUTDATED

/* #! MASTER Minimal Package !# */

#if MASTER_LIBRARY_HAVE_STDINT_H == 1
	typedef uint8_t UI1;
	typedef uint16_t UI2;
	typedef uint32_t UI4;
	typedef int8_t SI1;
	typedef int16_t SI2;
	typedef int32_t SI4;
#else
#	ifndef MASTER_zzz_COMPILER_FEATURES_LOADED
#		if MASTER_COMPILER_WARNING_AVAIL == 1
 #			warning "Can't set types because not found configuration file. Library will use 'char' for UI1/SI1, 'short' for UI2/SI2, 'int' for UI4/SI4."
#		endif /* #! Warning !# */
		typedef unsigned char UI1;
		typedef unsigned short UI2;
		typedef unsigned int UI4;
		typedef signed char SI1;
		typedef signed short SI2;
		typedef signed int SI4;
#	else
#		if MASTER_COMPILER_SIZEOF_CHAR == 1
			typedef unsigned char UI1;
			typedef signed char SI1;
#		elif MASTER_COMPILER_SIZEOF_SHORT == 1
			typedef unsigned short UI1;
			typedef signed short SI1;
#		elif MASTER_COMPILER_SIZEOF_INT == 1
			typedef unsigned int UI1;
			typedef signed int SI1;
#		elif MASTER_COMPILER_SIZEOF_LONG == 1
			typedef unsigned long UI1;
			typedef signed long SI1;
#		else
#			if MASTER_PREFER_C89_SUPPORTED
 #				error "Can't set for type UI1 and SI1 a type that have 1 byte size in it."
#			else
				MASTER_ERRORRISE "Can't set for type UI1 a type that have 1 byte size in it."
#			endif /* #! C89+ !# */
#		endif /* #! Symbol !# */
#		if MASTER_COMPILER_SIZEOF_CHAR == 2
			typedef unsigned char UI2;
			typedef signed char SI2;
#		elif MASTER_COMPILER_SIZEOF_SHORT == 2
			typedef unsigned short UI2;
			typedef signed short SI2;
#		elif MASTER_COMPILER_SIZEOF_INT == 2
			typedef unsigned int UI2;
			typedef signed int SI2;
#		elif MASTER_COMPILER_SIZEOF_LONG == 2
			typedef unsigned long UI2;
			typedef signed long SI2;
#		else
#			if MASTER_PREFER_C89_SUPPORTED
 #				error "Can't set for type UI2 and SI2 a type that have 2 byte size in it."
#			else
				MASTER_ERRORRISE "Can't set for type UI2 and SI2 a type that have 2 byte size in it."
#			endif /* #! C89+ !# */
#		endif /* #! Word !# */
#		if MASTER_COMPILER_SIZEOF_CHAR == 4
			typedef unsigned char UI4;
			typedef signed char SI4;
#		elif MASTER_COMPILER_SIZEOF_SHORT == 4
			typedef unsigned short UI4;
			typedef signed short SI4;
#		elif MASTER_COMPILER_SIZEOF_INT == 4
			typedef unsigned int UI4;
			typedef signed int SI4;
#		elif MASTER_COMPILER_SIZEOF_LONG == 4
			typedef unsigned long UI4;
			typedef signed long SI4;
#		else
#			if MASTER_PREFER_C89_SUPPORTED
 #				error "Can't set for type UI4 and SI4 a type that have 4 byte size in it."
#			else
				MASTER_ERRORRISE "Can't set for type UI4 and SI4 a type that have 4 byte size in it."
#			endif /* #! C89+ !# */
#		endif /* #! Phrase !# */
#	endif /* #! Compiler Features !# */
#endif /* #! stdint.h !# */

typedef UI4 OUI; /* #! Unknown type but prefers unsigned int !# */
typedef SI4 OSI; /* #! Unknown type but prefers signed int !# */
typedef double UF; /* #! Unknown type but prefers float !# */
typedef UI4 UT; /* #! Unknown type !# */

#define MASTER_8BIT_NUMBER UI1
#define MASTER_16BIT_NUMBER UI2
#define MASTER_32BIT_NUMBER UI4
#define MASTER_64BIT_NUMBER UI8

/* #! MASTER Preprocessor Concatenation !# */

#if MASTER_PREPROC_CONCAT_AVAILABLE
#	define MASTER_TYPE_MAX_VALUE( variableType ) MASTER_ ## variableType ## _MAX
#	define MASTER_TYPE_MIN_VALUE( variableType ) MASTER_ ## variableType ## _MIN
#	define MASTER_BIT_NUMBER( bitValue ) MASTER_ ## bitValue ## BIT_NUMBER
#	define MASTER_SIGNED_TYPE( bytesCount ) SI ## bytesCount
#	define MASTER_UNSIGNED_TYPE( bytesCount ) UI ## bytesCount
#else
#	define MASTER_TYPE_MAX_VALUE( variableType ) MASTER_/**/variableType/**/_MAX
#	define MASTER_TYPE_MIN_VALUE( variableType ) MASTER_/**/variableType/**/_MIN
#	define MASTER_BIT_NUMBER( bitValue ) MASTER_/**/bitValue/**/BIT_NUMBER
#	define MASTER_SIGNED_TYPE( bytesCount ) SI/**/bytesCount
#	define MASTER_UNSIGNED_TYPE( bytesCount ) UI/**/bytesCount
#endif /* #! K&R C !# */

/*
#if defined(_MSC_VER)
#	define MASTER_PREFER_INLINE __inline
#else
#	define MASTER_PREFER_INLINE
#endif
#if defined(__GNUC__) || defined(__clang__)
#	define MASTER_PREFER_FORCE_INLINE __inline__ __attribute__((__always_inline__))
#	define MASTER_PREFER_NO_INLINE __attribute__((__noinline__))
#elif defined(_MSC_VER)
#	define MASTER_PREFER_FORCE_INLINE __forceinline
#	define MASTER_PREFER_NO_INLINE __declspec(noinline)
#else
#	define MASTER_PREFER_FORCE_INLINE MASTER_PREFER_INLINE
#	define MASTER_PREFER_NO_INLINE
#endif
#define MASTER_PREFER_STATIC static
#if ((defined(sum) || defined(__sun))) && defined(__cplusplus)
#	define MASTER_PREFER_RESTRICT
#elif defined(__clang__) || \
	  (defined(_MSC_VER) && (_MSC_VER + 0 >= 1400)) || \
	  (defined(__INTEL_COMPILER) && (__INTEL_COMPILER + 0 >= 1300))
#	define MASTER_PREFER_RESTRICT __restrict
#else
#	define MASTER_PREFER_RESTRICT
#endif
#if defined(__GNUC__)
#	define MASTER_PREFER_UNUSED __attribute__((__unused__))
#elif defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 202311L)
#	define MASTER_PREFER_UNUSED [[maybe_unused]]
#else
#	define MASTER_PREFER_UNUSED
#endif
#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 201710L)
#	define MASTER_PREFER_OUTDATED [[deprecated]]
#else
#	define MASTER_PREFER_OUTDATED
#endif
#if defined(_WIN32) && defined(_MSC_VER)
#	define MASTER_PREFER_EXPORT __declspec(dllexport)
#else
#	define MASTER_PREFER_EXPORT
#endif
#if defined(_WIN32) && defined(_MSC_VER)
#	define MASTER_PREFER_IMPORT __declspec(dllimport)
#else
#	define MASTER_PREFER_IMPORT
#endif
#if MASTER_COMPILER_HAS_C_ATTRIBUTE(fallthrough) || MASTER_COMPILER_HAS_CPP_ATTRIBUTE(fallthrough)
#	define MASTER_PREFER_FALLTHROUGH [[fallthrough]]
#elif MASTER_COMPILER_HAS_ATTRIBUTE(__fallthrough__)
#	define MASTER_PREFER_FALLTHROUGH __attribute__((__fallthrough__))
#else
#	define MASTER_PREFER_FALLTHROUGH
#endif
#if MASTER_COMPILER_HAS_ATTRIBUTE(noescape)
#	define MASTER_PREFER_NOESCAPE __attribute__((__noescape__))
#else
#	define MASTER_PREFER_NOESCAPE
#endif
#if MASTER_COMPILER_HAS_BUILTIN(__builtin_unreachable)
#	define MASTER_PREFER_UNREACHABLE __builtin_unreachable()
#elif defined(_MSC_VER)
#	define MASTER_PREFER_UNREACHABLE __assume(0)
#else
#	define MASTER_PREFER_UNREACHABLE
#endif
#if MASTER_COMPILER_HAS_BUILTIN(__builtin_assume)
#	define MASTER_PREFER_ASSUME( expression ) __builtin_assume(expression)
#else
#	define MASTER_PREFER_ASSUME( expression ) if (!(expression)) { MASTER_PREFER_UNREACHABLE; }
#endif
#if (defined(__GNUC__) && __GNUC__ + 0 >= 3) || (defined(__INTEL_COMPILER) && __INTEL_COMPILER + 0 >= 800) || defined(__clang__)
#	define MASTER_PREFER_LIKELY( expression ) __builtin_expect(expression, 1)
#	define MASTER_PREFER_UNLIKELY( expression ) __builtin_expect(expression, 0)
#else
#	define MASTER_PREFER_LIKELY( expression )
#	define MASTER_PREFER_UNLIKELY( expression )
#endif
#if defined(__GNUC__) || defined(__clang__)
#	define MASTER_PREFER_MAY_ALIAS __attribute__((__may_alias__))
#else
#	define MASTER_PREFER_MAY_ALIAS
#endif
#if defined(__GNUC__) && (__GNUC__ + 0 >= 4 || (__GNUC__ + 0 == 3 && __GNUC_MINOR__ + 0 >= 1))
#	define MASTER_PREFER_PREFETCH( pointer ) __builtin_prefetch(pointer, 0, 3)
#else
#	define MASTER_PREFER_PREFETCH( pointer ) ((void)(pointer))
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ + 0 >= 201112L
#	define MASTER_PREFER_ALIGNAS( alignValue ) _Alignas(alignValue)
#	define MASTER_PREFER_MEMBER_ALIGN( alignValue, variableType ) variableType MASTER_PREFER_ALIGNAS(alignValue)
#	define MASTER_PREFER_VARIABLE_ALIGN( alignValue, variableType, variable_name ) variableType MASTER_PREFER_ALIGNAS(alignValue) variable_name
#elif defined(__cplusplus) && __cplusplus + 0 >= 201103L
#	define MASTER_PREFER_ALIGNAS( alignValue ) alignas(alignValue)
#	define MASTER_PREFER_MEMBER_ALIGN( alignValue, variableType ) variableType MASTER_PREFER_ALIGNAS(alignValue)
#	define MASTER_PREFER_VARIABLE_ALIGN( alignValue, variableType, variable_name ) variableType MASTER_PREFER_ALIGNAS(alignValue) variable_name
#elif defined(__GNUC__)
#	define MASTER_PREFER_ALIGNAS( alignValue ) __attribute__((aligned(alignValue)))
#	define MASTER_PREFER_MEMBER_ALIGN( alignValue, variableType ) MASTER_PREFER_ALIGNAS(alignValue) variableType

#	define MASTER_PREFER_VARIABLE_ALIGN( alignValue, variableType, variable_name ) MASTER_PREFER_ALIGNAS(alignValue) variableType variable_name
#elif defined(_MSC_VER)
#	define MASTER_PREFER_ALIGNAS( alignValue ) __declspec(align(alignValue))
#	define MASTER_PREFER_MEMBER_ALIGN( alignValue, variableType ) variableType MASTER_PREFER_ALIGNAS(alignValue)
#	define MASTER_PREFER_VARIABLE_ALIGN( alignValue, variableType, variable_name ) variableType MASTER_PREFER_ALIGNAS(alignValue) variable_name
#else
#	define MASTER_PREFER_ALIGNAS( alignValue )
#	define MASTER_PREFER_MEMBER_ALIGN( alignValue, variableType ) variableType
#	define MASTER_PREFER_VARIABLE_ALIGN( alignValue, variableType, variable_name ) variableType variable_name
#endif
#if defined(__GNUC__) || defined(__clang__)
#	define MASTER_COMPILER_PREFER_GUARD( variable ) __asm__ ("":"+r"(variable))
#else
#	define MASTER_COMPILER_PREFER_GUARD( variable )
#endif
#if defined(__clang__) && defined(__ARM_ARCH) && !defined(__wasm__)
#	define MASTER_COMPILER_PREFER_GUARD_NEON( variable ) __asm__ ("":"+w"(variable))
#else
#	define MASTER_COMPILER_PREFER_GUARD_NEON( variable )
#endif
*/

/* #! MASTER Types !# */

#if (!defined(__STDC_VERSION__) && !defined(MASTER_IGNORE_C89_STD_64_VARIABLES))
#	define MASTER_zzz_PREFER_LONGLONG long
#	define MASTER_zzz_PREFER_64 0
#else
#	define MASTER_zzz_PREFER_LONGLONG long long
#	define MASTER_zzz_PREFER_64 1
#endif /* #! C89 Long Long Check !# */

#ifndef MASTER_64_AVAILABLE
#	ifdef __cplusplus
#		if __cplusplus + 0 >= 201103L
			typedef unsigned long long MASTER_maxint;
#			define MASTER_64_AVAILABLE 1
#		else
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		endif /* #! C++98 Check !# */
#	elif MASTER_LIBRARY_HAVE_STDINT_H == 1
		typedef size_t MASTER_maxint;
#		if MASTER_zzz_PREFER_64 == 1
#			define MASTER_64_AVAILABLE 1
#		else
#			define MASTER_64_AVAILABLE 0
#		endif /* #! Prefer 64 Bits !# */
#	elif MASTER_LIBRARY_HAVE_LIMITS_H == 1
#		if defined(ULLONG_MAX)
			typedef unsigned MASTER_zzz_PREFER_LONGLONG MASTER_maxint;
#			define MASTER_64_AVAILABLE MASTER_zzz_PREFER_64
#		elif defined(ULONG_MAX) && (ULONG_MAX + 0 >= 0xFFFFFFFFFFFFFFFFULL)
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE MASTER_zzz_PREFER_64
#		else
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		endif /* #! C version !# */
#	elif !defined(MASTER_IGNORE_ARCHITECTURE)
#		if MASTER_ARCHITECTURE_CPU_WIDTH >= 64
#			if !defined(__STDC_VERSION__)
				typedef unsigned MASTER_zzz_PREFER_LONGLONG MASTER_maxint;
#			else
				typedef unsigned MASTER_zzz_PREFER_LONGLONG MASTER_maxint;
#			endif /* #! C89 !# */
#			define MASTER_64_AVAILABLE MASTER_zzz_PREFER_64
#		elif MASTER_ARCHITECTURE_CPU_WIDTH >= 32
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		else
			typedef unsigned short MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		endif /* #! MASTER_ARCHITECTURE_CPU_WIDTH !# */
#	else
#		if !defined(MASTER_IGNORE_C89_STD_64_VARIABLES)
			typedef unsigned long MASTER_maxint;
#			define MASTER_64_AVAILABLE 0
#		else
#			if MASTER_LIBRARY_HAVE_LIMITS_H == 0
				typedef unsigned short MASTER_maxint;
#				define MASTER_64_AVAILABLE 0
#			else
#				if defined(ULONG_MAX) && (ULONG_MAX + 0 >= 0xFFFFFFFFFFFFFFFFULL)
					typedef unsigned MASTER_zzz_PREFER_LONGLONG MASTER_maxint;
#					define MASTER_64_AVAILABLE MASTER_zzz_PREFER_64
#				elif defined(ULONG_MAX) && (ULONG_MAX + 0 >= 0xFFFFFFFFUL)
					typedef unsigned long MASTER_maxint;
#					define MASTER_64_AVAILABLE 0
#				else
					typedef unsigned short MASTER_maxint;
#					define MASTER_64_AVAILABLE 0
#				endif /* #! Long variables check !# */
#			endif /* #! limits.h !# */
#		endif /* #! MASTER_IGNORE_C89_STD_64_VARIABLES !# */
#	endif /* #! C / C++ check !# */
#endif /* #! MASTER_64_AVAILABLE !# */

#if MASTER_64_AVAILABLE == 1
#	if MASTER_LIBRARY_HAVE_STDINT_H != 0
#		define MASTER_UI8_TYPE uint64_t
#		define MASTER_SI8_TYPE int64_t
#	else
#		define MASTER_UI8_TYPE unsigned long long int
#		define MASTER_SI8_TYPE signed long long int
#	endif /* #! stdint.h !# */
	typedef MASTER_SI8_TYPE MASTER_signed_maxint;
	typedef MASTER_UI8_TYPE MASTER_unsigned_maxint;
#	define MASTER_SIGNED_MAXINT_MIN MASTER_SI8_MIN
#	define MASTER_SIGNED_MAXINT_MAX MASTER_SI8_MAX
#	define MASTER_UNSIGNED_MAXINT_MIN MASTER_UI8_MIN
#	define MASTER_UNSIGNED_MAXINT_MAX MASTER_UI8_MAX
#else
	typedef SI4 MASTER_signed_maxint;
	typedef UI4 MASTER_unsigned_maxint;
#	define MASTER_SIGNED_MAXINT_MIN MASTER_SI4_MIN
#	define MASTER_SIGNED_MAXINT_MAX MASTER_SI4_MAX
#	define MASTER_UNSIGNED_MAXINT_MIN MASTER_UI4_MIN
#	define MASTER_UNSIGNED_MAXINT_MAX MASTER_UI4_MAX
#endif /* #! MASTER_64_AVAILABLE !# */

#ifdef MASTER_UI8_TYPE
	typedef MASTER_UI8_TYPE UI8;
#else
#	define MASTER_UI8_ARRAY_TYPE 1
	typedef UI4 UI8[2];
#endif /* #! UI8 Type !# */

#ifdef MASTER_UI16_TYPE
	typedef MASTER_UI16_TYPE UI16;
#else
#	define MASTER_UI16_ARRAY_TYPE 1
	typedef UI4 UI16[4];
#endif /* #! UI16 Type !# */

#ifdef MASTER_UI32_TYPE
	typedef MASTER_UI32_TYPE UI32;
#else
#	define MASTER_UI32_ARRAY_TYPE 1
	typedef UI4 UI32[8];
#endif /* #! UI32 Type !# */

#ifdef MASTER_UI64_TYPE
	typedef MASTER_UI64_TYPE UI64;
#else
#	define MASTER_UI64_ARRAY_TYPE 1
	typedef UI4 UI64[16];
#endif /* #! UI64 Type !# */

#ifdef MASTER_UI128_TYPE
	typedef MASTER_UI128_TYPE UI128;
#else
#	define MASTER_UI128_ARRAY_TYPE 1
	typedef UI4 UI128[32];
#endif /* #! UI128 Type !# */

#ifdef MASTER_SI8_TYPE
	typedef MASTER_SI8_TYPE SI8;
#endif /* #! SI8 Type !# */

#ifdef MASTER_SI16_TYPE
	typedef MASTER_SI16_TYPE SI16;
#endif /* #! SI16 Type !# */

#ifdef MASTER_SI32_TYPE
	typedef MASTER_SI32_TYPE SI32;
#endif /* #! SI32 Type !# */

#ifdef MASTER_SI64_TYPE
	typedef MASTER_SI64_TYPE SI64;
#endif /* #! SI64 Type !# */

#ifdef MASTER_SI128_TYPE
	typedef MASTER_SI128_TYPE SI128;
#endif /* #! SI128 Type !# */

#ifdef MASTER_YEAR_IN_BYTE
#	define MASTER_TO_YEARS( yearValue ) (UI1)((yearValue) - 2038)
#	define MASTER_GET_YEARS( yearValue ) (2038 + (yearValue))
	typedef SI1 MASTER_year;
#else
#	define MASTER_TO_YEARS( yearValue ) (yearValue)
#	define MASTER_GET_YEARS( yearValue ) (yearValue)
	typedef UI2 MASTER_year;
#endif /* #! MASTER_YEAR_IN_BYTE !# */

/* #! MASTER Integers Values !# */

#define MASTER_UI1_BITS (sizeof(UI1) << 3)
#define MASTER_UI2_BITS (sizeof(UI2) << 3)
#define MASTER_UI4_BITS (sizeof(UI4) << 3)
#define MASTER_UI8_BITS (sizeof(UI8) << 3)
#define MASTER_UI16_BITS (sizeof(UI16) << 3)
#define MASTER_UI32_BITS (sizeof(UI32) << 3)
#define MASTER_UI64_BITS (sizeof(UI64) << 3)
#define MASTER_UI128_BITS (sizeof(UI128) << 3)

#define MASTER_SI1_BITS (sizeof(SI1) << 3)
#define MASTER_SI2_BITS (sizeof(SI2) << 3)
#define MASTER_SI4_BITS (sizeof(SI4) << 3)
#define MASTER_SI8_BITS (sizeof(SI8) << 3)
#define MASTER_SI16_BITS (sizeof(SI16) << 3)
#define MASTER_SI32_BITS (sizeof(SI32) << 3)
#define MASTER_SI64_BITS (sizeof(SI64) << 3)
#define MASTER_SI128_BITS (sizeof(SI128) << 3)

#define MASTER_SI1_MIN (SI1)((SI1)1 << (MASTER_SI1_BITS - 1))
#define MASTER_SI1_MAX (SI1)((UI1)MASTER_SI1_MIN - (UI1)1)
#define MASTER_SI2_MIN (SI2)((SI2)1 << (MASTER_SI2_BITS - 1))
#define MASTER_SI2_MAX (SI2)((UI2)MASTER_SI2_MIN - (UI2)1)
#define MASTER_SI4_MIN (SI4)((SI4)1 << (MASTER_SI4_BITS - (SI4)1))
#define MASTER_SI4_MAX (SI4)((UI4)MASTER_SI4_MIN - (UI4)1)
#ifdef MASTER_SI8_TYPE
#	define MASTER_SI8_MIN (SI8)((SI8)1 << (MASTER_SI8_BITS - 1))
#	define MASTER_SI8_MAX (SI8)((UI8)MASTER_SI4_MIN - (SI8)1)
#endif /* #! SI8 !# */

#define MASTER_UI1_MIN (UI1)0
#define MASTER_UI1_MAX (UI1)(MASTER_UI1_MIN - 1)
#define MASTER_UI2_MIN (UI2)0
#define MASTER_UI2_MAX (UI2)(MASTER_UI2_MIN - 1)
#define MASTER_UI4_MIN (UI4)0
#define MASTER_UI4_MAX (UI4)(MASTER_UI4_MIN - (UI4)1)
#ifdef MASTER_UI8_TYPE
#	define MASTER_UI8_MIN (UI8)MASTER_CONSTANT(0)
#	define MASTER_UI8_MAX (UI8)(MASTER_UI8_MIN - (UI8)1)
#endif /* #! UI8 !# */

#define MASTER_OUI_BITS (sizeof(OUI) << 3)
#define MASTER_OSI_BITS (sizeof(OSI) << 3)
#define MASTER_UT_BITS (sizeof(UT) << 3)

#define MASTER_MAXINT_BITS (sizeof(MASTER_maxint) << 3)

/* #! MASTER Errors !# */

#ifndef MASTER_MINIMALIZE_ERROR_CODES
#	define MASTER_ERROR_COMMENT( error_code, baseValue ) error_code
#else
#	define MASTER_ERROR_COMMENT( error_code, baseValue ) error_code = baseValue
#endif /* #! MASTER_MINIMALIZE_RETURN_CODES !# */

typedef enum {
	MASTER_NO_ERROR = 0,
	MASTER_ERROR = 1
} MASTER_error;

const char * const MASTER_error_codes[] = {
	"No error",
	"Error",
#ifndef MASTER_MINIMALIZE_ERROR_CODES
#endif /* #! MASTER_MINIMALIZE_RETURN_CODES !# */
};

#ifndef MASTER_DONT_USE_OPTIONAL_ERROR_CODES
	typedef MASTER_error MASTER_optional_error;
#	define MASTER_OPTIONAL_ERROR_CODE( error_code ) (error_code)
#else
	typedef void MASTER_optional_error;
#	define MASTER_OPTIONAL_ERROR_CODE( error_code )
#endif /* #! MASTER_DONT_USE_OPTIONAL_RET_CODE !# */

#define MASTER_IS_SUCCESS(code) ((code) == MASTER_NO_ERROR)
#define MASTER_IS_FAILURE(code) ((code) != MASTER_NO_ERROR)

/* #! MASTER Assertion !# */

#ifdef MASTER_ENABLE_ASSERTIONS
#	ifndef MASTER_ASSERT
#		if MASTER_PREFER_C89_SUPPORTED
 #			error "With defined "MASTER_ENABLE_ASSERTIONS" function "MASTER_ASSERT" with arguments (expr) must be defined."
#		else
			MASTER_ERRORRISE "With defined "MASTER_ENABLE_ASSERTIONS" function "MASTER_ASSERT" with arguments (expr) must be defined."
#		endif /* #! C89+ !# */
#	endif /* #! MASTER_FUNCTION_ASSERTION !# */
#else
#	define MASTER_ASSERT( expression )
#endif /* #! MASTER_ENABLE_ASSERTIONS !# */

/* #! MASTER Memory Functions !# */

#if !defined(MASTER_CUSTOM_MEMORY_FUNCTIONS) && ( \
	defined(MASTER_MALLOC) || defined(MASTER_REALLOC) || defined(MASTER_CALLOC) || defined(MASTER_FREE))
#	if MASTER_COMPILER_WARNING_AVAIL == 1
 #		warning "Some user memory functions are defined, but macro 'MASTER_CUSTOM_MEMORY_FUNCTIONS' is undefined. Defining 'MASTER_CUSTOM_MEMORY_FUNCTIONS'"
#	endif /* #! Warning !# */
#	define MASTER_CUSTOM_MEMORY_FUNCTIONS
#endif /* #! Predefined Memory Functions Check !# */

#if defined(MASTER_CUSTOM_MEMORY_FUNCTIONS)
#	ifndef MASTER_MALLOC
#		if MASTER_PREFER_C89_SUPPORTED
 #			error "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_MALLOC" must be defined."
#		else
			MASTER_ERRORRISE "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_MALLOC" must be defined."
#		endif /* #! C89+ !# */
#	endif /* #! MASTER_MALLOC !# */
#	ifndef MASTER_REALLOC
#		if MASTER_PREFER_C89_SUPPORTED
 #			error "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_REALLOC" must be defined."
#		else
			MASTER_ERRORRISE "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_REALLOC" must be defined."
#		endif /* #! C89+ !# */
#	endif /* #! MASTER_REALLOC !# */
#	ifndef MASTER_CALLOC
#		if MASTER_PREFER_C89_SUPPORTED
 #			error "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_CALLOC" must be defined."
#		else
			MASTER_ERRORRISE "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_CALLOC" must be defined."
#		endif /* #! C89+ !# */
#	endif /* #! MASTER_CALLOC !# */
#	ifndef MASTER_FREE
#		if MASTER_PREFER_C89_SUPPORTED
 #			error "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_FREE" must be defined."
#		else
			MASTER_ERRORRISE "With defined "MASTER_CUSTOM_MEMORY_FUNCTIONS" function "MASTER_FREE" must be defined."
#		endif /* #! C89+ !# */
#	endif /* #! MASTER_FREE !# */
#elif defined(MASTER_LIBRARY_HAVE_STDLIB_H) || defined(MASTER_LIBRARY_HAVE_CSTDLIB)
#	define MASTER_MALLOC( __size ) malloc(__size)
#	define MASTER_CALLOC( __count, __size ) calloc(__count, __size)
#	define MASTER_REALLOC( __ptr, __size ) realloc(__ptr, __size)
#	define MASTER_FREE( __ptr ) free(__ptr)
#else
#	if MASTER_PREFER_C89_SUPPORTED
 #		error "Not provided user allocation functions and not found system libraries that provides it."
#	else
		MASTER_ERRORRISE "Not provided user allocation functions and not found system libraries that provides it."
#	endif /* #! C89+ !# */
#endif /* #! MASTER_MEMORY_SAFE !# */

/* #! MASTER Checks !# */

#define MASTER_RETURN_IF_NUL( pointer, retval ) do { \
		if ((pointer) == 0) return retval; \
	} while (0)
#define MASTER_GOTO_IF_NUL( pointer, label ) do { \
		if ((pointer) == 0) goto label; \
	} while (0)
#define MASTER_ASSERT_IF_NUL( pointer ) do { \
		MASTER_ASSERT((pointer) != 0); \
	} while (0)

#if !defined(MASTER_DONT_CHECK_NUL_OPERANDS) && !defined(MASTER_ASSERT_IF_NUL_OPERAND)
#	define MASTER_zzz_CHECK_NUL_RETURN( pointer, retval ) MASTER_RETURN_IF_NUL(pointer, retval)
#	define MASTER_zzz_CHECK_NUL_GOTO( pointer, retval ) MASTER_GOTO_IF_NUL(pointer, retval)
#	define MASTER_zzz_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
#elif !defined(MASTER_DONT_CHECK_NUL_OPERANDS) && defined(MASTER_ASSERT_IF_NUL_OPERAND)
#	define MASTER_zzz_CHECK_NUL_RETURN( pointer, retval ) MASTER_ASSERT_IF_NUL(pointer)
#	define MASTER_zzz_CHECK_NUL_GOTO( pointer, retval ) MASTER_ASSERT_IF_NUL(pointer)
#	define MASTER_zzz_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
#else
#	define MASTER_zzz_CHECK_NUL_RETURN( pointer, retval )
#	define MASTER_zzz_CHECK_NUL_GOTO( pointer, retval )
#	ifdef MASTER_ENABLE_ASSERTIONS
#		define MASTER_zzz_CHECK_NUL_ASSERT( pointer )
#	else
#		define MASTER_zzz_CHECK_NUL_ASSERT( pointer ) MASTER_ASSERT_IF_NUL(pointer)
#	endif /* #! MASTER_ENABLE_ASSERTIONS !# */
#endif /* #! MASTER_DONT_CHECK_NUL_OPERANDS !# */

/* #! MASTER Align !# */

#define MASTER_ALIGNPOW2( value, bitCount ) ((((value) >> (bitCount)) + !!((value) & ((1 << (bitCount)) - 1))) << (bitCount))
#define MASTER_ALIGN2( value ) MASTER_ALIGNPOW2( value, 1 )
#define MASTER_ALIGN4( value ) MASTER_ALIGNPOW2( value, 2 )
#define MASTER_ALIGN8( value ) MASTER_ALIGNPOW2( value, 3 )
#define MASTER_ALIGN16( value ) MASTER_ALIGNPOW2( value, 4 )
#define MASTER_ALIGN( value, bitCount ) ((((value) / (bitCount)) + !!((value) % (bitCount))) * (bitCount))

/* #! MASTER Simple Macroses !# */

#define MASTER_MEMBER_SIZE( structure, member ) sizeof(((const structure * const)0)->member)
#define MASTER_MAX_BRANCHLESS( value1, value2 ) ((value2) ^ (((value1) ^ (value2)) & (-((value1) < (value2)))))
/* #! MASTER_SI<N>_MIN <= value1 - value2 <= MASTER_SI<N>_MAX !# */
#define MASTER_MAX_QUICK( value1, value2 ) ((value2) + (((value1) - (value2)) & (((value1) - (value2)) >> (sizeof(value1) * 8 - 1))))
#define MASTER_MAX( value1, value2 ) (((value1) > (value2)) ? (value1) : (value2))
#define MASTER_MAX3( value1, value2, value3 ) MASTER_MAX(value1, MASTER_MAX(value2, value3))
#define MASTER_MAX4( value1, value2, value3, value4 ) MASTER_MAX(MASTER_MAX(value1, value2), MASTER_MAX(value3, value4))
#define MASTER_IMAX( value1, value2 ) (value1) = MASTER_MAX(value1, value2)
#define MASTER_IMAX3( value1, value2, value3 ) (value1) = MASTER_MAX3(value1, value2, value3)
#define MASTER_IMAX4( value1, value2, value3, value4 ) (value1) = MASTER_MAX4(value1, value2, value3, value4)
#define MASTER_MIN_BRANCHLESS( value1, value2 ) ((value1) ^ (((value1) ^ (value2)) & (-((value1) < (value2)))))
/* #! MASTER_SI<N>_MIN <= value1 - value2 <= MASTER_SI<N>_MAX !# */
#define MASTER_MIN_QUICK( value1, value2 ) ((value1) - (((value1) - (value2)) & (((value1) - (value2)) >> (sizeof(value1) * 8 - 1))))
#define MASTER_MIN( value1, value2 ) (((value1) < (value2)) ? (value1) : (value2))
#define MASTER_MIN3( value1, value2, value3 ) MASTER_MIN(value1, MASTER_MIN(value2, value3))
#define MASTER_MIN4( value1, value2, value3, value4 ) MASTER_MIN(MASTER_MIN(value1, value2), MASTER_MIN(value3, value4))
#define MASTER_IMIN( value1, value2 ) (value1) = MASTER_MIN(value1, value2)
#define MASTER_IMIN3( value1, value2, value3 ) (value1) = MASTER_MIN3(value1, value2, value3)
#define MASTER_IMIN4( value1, value2, value3, value4 ) (value1) = MASTER_MIN4(value1, value2, value3, value4)
#define MASTER_CLAMP( value, minValue, maxValue ) MASTER_MAX(minValue, MASTER_MIN(maxValue, value))
#define MASTER_ICLAMP( value, minValue, maxValue ) (value) = MASTER_CLAMP(value, minValue, maxValue)
#define MASTER_ABS( value ) (((value) < 0) ? (-(value)) : (value))
#define MASTER_ABS_BRANCHLESS( value ) (((value) + ((value) >> (sizeof(value) * 8 - 1))) - ((value) >> (sizeof(value) * 8 - 1)))
#define MASTER_SIGN( value ) ((value > 0) - (value < 0))
#define MASTER_PARITYSIGN( value ) (1 | (-((value) & 1)))
#define MASTER_INVPARITYSIGN( value ) ((((value) & 1) << 1) - 1)
#define MASTER_OPPOSITE_SIGNS( value1, value2 ) (((value1) ^ (value2)) < 0)
#define MASTER_SQUARE( value ) ((value) * (value))
#define MASTER_2BYTES_TO_INT( value1, value2 ) (((value1) << 8) | (value2))
#define MASTER_4BYTES_TO_INT( value1, value2, value3, value4 ) (((value1) << 24) | ((value2) << 16) | ((value3) << 8) | (value4))
/* #! TODO : sign extending !# */
#define MASTER_STATE_BITS( value, bit_maask, to_set ) (value) ^= ((-(to_set)) ^ (value)) & (bit_mask)
#define MASTER_MERGE_BITS( value1, value2, bit_mask ) ((value1) ^ (((value1) ^ (value2)) & (bit_mask)))
#define MASTER_ISINRANGE_CC( value, lowValue, highValue ) ((lowValue) <= (value) && (value) <= (highValue))
#define MASTER_ISINRANGE_CO( value, lowValue, highValue ) ((lowValue) <= (value) && (value) < (highValue))
#define MASTER_ISINRANGE_OC( value, lowValue, highValue ) ((lowValue) < (value) && (value) <= (highValue))
#define MASTER_ISINRANGE_OO( value, lowValue, highValue ) ((lowValue) < (value) && (value) < (highValue))
#define MASTER_ISINRANGE( value, lowValue, highValue ) MASTER_ISINRANGE_CC(value, lowValue, highValue)
#define MASTER_WRAP( number, limit ) (((number) >= (limit)) ? (0) : (number))

#define MASTER_SET_ARRAY2( array, value1, value2 ) (array)[0] = (value1), (array)[1] = (value2)
#define MASTER_SET_ARRAY3( array, value1, value2, value3 ) (array)[0] = (value1), (array)[1] = (value2), (array)[2] = (value3)
#define MASTER_SET_ARRAY4( array, value1, value2, value3, value4 ) (array)[0] = (value1), (array)[1] = (value2), (array)[2] = (value3), (array)[3] = (value4)
#define MASTER_SET_ARRAY5( array, value1, value2, value3, value4, value5 ) (array)[0] = (value1), (array)[1] = (value2), (array)[2] = (value3), (array)[3] = (value4), (array)[4] = (value5)
#define MASTER_SET_ARRAY6( array, value1, value2, value3, value4, value5, value6 ) (array)[0] = (value1), (array)[1] = (value2), (array)[2] = (value3), (array)[3] = (value4), (array)[4] = (value5), (array)[5] = (value6)
#define MASTER_SET_ARRAY7( array, value1, value2, value3, value4, value5, value6, value7 ) (array)[0] = (value1), (array)[1] = (value2), (array)[2] = (value3), (array)[3] = (value4), (array)[4] = (value5), (array)[5] = (value6), (array)[6] = (value7)
#define MASTER_SET_ARRAY8( array, value1, value2, value3, value4, value5, value6, value7, value8 ) (array)[0] = (value1), (array)[1] = (value2), (array)[2] = (value3), (array)[3] = (value4), (array)[4] = (value5), (array)[5] = (value6), (array)[6] = (value7), (array)[7] = (value8)
#define MASTER_SET_ARRAY9( array, value1, value2, value3, value4, value5, value6, value7, value8, value9 ) (array)[0] = (value1), (array)[1] = (value2), (array)[2] = (value3), (array)[3] = (value4), (array)[4] = (value5), (array)[5] = (value6), (array)[6] = (value7), (array)[7] = (value8), (array)[8] = (value9)
#define MASTER_SET_ARRAY10( array, value1, value2, value3, value4, value5, value6, value7, value8, value9, value10 ) (array)[0] = (value1), (array)[1] = (value2), (array)[2] = (value3), (array)[3] = (value4), (array)[4] = (value5), (array)[5] = (value6), (array)[6] = (value7), (array)[7] = (value8), (array)[8] = (value9), (array)[9] = (value10)

#ifndef MASTER_UNSAFE_HOWMANY
#	define MASTER_DIV_CEIL2( value ) (((value) >> 1) + !!((value) & 1))
#	define MASTER_DIV_CEIL4( value ) (((value) >> 2) + !!((value) & 3))
#	define MASTER_DIV_CEIL8( value ) (((value) >> 3) + !!((value) & 7))
#	define MASTER_DIV_CEIL16( value ) (((value) >> 4) + !!((value) & 15))
#	define MASTER_DIV_CEIL_POW2( value, bitCount ) (((value) >> bitCount) + !!((value) & ((1 << (bitCount)) - 1)))
#	define MASTER_HOWMANY( value, subvalue ) (((value) / (subvalue)) + !!((value) % (subvalue)))
#else
	/* #! Value can be overflowed after plus and there will be information loses !# */
#	define MASTER_DIV_CEIL2( value ) (((value) + 1) >> 1)
#	define MASTER_DIV_CEIL4( value ) (((value) + 3) >> 2)
#	define MASTER_DIV_CEIL8( value ) (((value) + 7) >> 3)
#	define MASTER_DIV_CEIL16( value ) (((value) + 15) >> 4)
#	define MASTER_DIV_CEIL_POW2( value, bitCount ) (((value) + ((1 << (bitCount)) - 1)) >> (bitCount))
#	define MASTER_HOWMANY( value, subvalue ) (((value) + ((subvalue) - 1)) / (subvalue))
#endif /* #! Safe / Unsafe Howmany !# */

#define MASTER_HOWMANY2( value ) MASTER_DIV_CEIL2( value )
#define MASTER_HOWMANY4( value ) MASTER_DIV_CEIL4( value )
#define MASTER_HOWMANY8( value ) MASTER_DIV_CEIL8( value )
#define MASTER_HOWMANY16( value ) MASTER_DIV_CEIL16( value )
#define MASTER_HOWMANY_POW2( value, bitCount ) MASTER_DIV_CEIL_POW2( value, bitCount )
#define MASTER_BITS_TO_BYTES( value ) MASTER_DIV_CEIL8( value )

#define MASTER_PADDINGLEN( value, modulo, residue ) (((residue) - ((value) + 1) % (modulo) + (modulo)) % (modulo))
#define MASTER_PADDEDLEN( value, modulo, residue ) ((value) + 1 + MASTER_PADDINGLEN(value, modulo, residue))
#define MASTER_PADDINGLEN_POW2( value, log2modulo, residue ) ((((residue) - ((value) + 1)) & ((1 << (log2modulo)) - 1)))
#define MASTER_PADDEDLEN_POW2( value, log2modulo, residue ) ((value) + 1 + MASTER_PADDINGLEN_POW2(value, log2modulo, residue))

#define MASTER_NUMBER_SWAP( value1, value2 ) do { \
		(value1) ^= (value2); \
		(value2) ^= (value1); \
		(value1) ^= (value2); \
	} while (0)

/* #! MASTER Library Functions Or Custom Analogs !# */

#if MASTER_LIBRARY_HAVE_STRING_H == 1
#	define MASTER_CPRCAT strcat
#	define MASTER_CPRCHR strchr
#	define MASTER_CPRCMP strcmp
#	define MASTER_CPRCOLL strcoll
#	define MASTER_CPRCPY strcpy
#	define MASTER_CPRCSPN strcspn
#	define MASTER_CPRERROR strerror
#	define MASTER_CPRLEN strlen
#	define MASTER_CPRNCAT strncat
#	define MASTER_CPRNCMP strncmp
#	define MASTER_CPRNCPY strncpy
#	define MASTER_CPRPBRK strpbrk
#	define MASTER_CPRRCHR strrchr
#	define MASTER_CPRSPN strspn
#	define MASTER_CPRCPR strstr
#	define MASTER_CPRTOK strtok
#	define MASTER_CPRXFRM strxfrm
#	define MASTER_MEMCHR memchr
#	define MASTER_MEMCMP memcmp
#	define MASTER_MEMCPY memcpy
#	define MASTER_MEMMOV memmove
#	define MASTER_MEMSET memset
#	define MASTER_CPRDUP strdup
#	define MASTER_CPRCPY_S strcpy_s
#	define MASTER_MEMPCPY mempcpy
#	define MASTER_MEMCCPY memccpy
#	define MASTER_CPRERROR_R strerror_r
#	define MASTER_CPRLCPY strlcpy
#	define MASTER_CPRTOK_R strtok_r
#	define MASTER_CPRSIGNAL strsignal
#elif !defined(MASTER_STRING_DEFINED_FUNCTIONS_PARTIONLY)
#	if MASTER_PREFER_C89_SUPPORTED
 #		error "Custom string.h functions are not supporting yet."
#	else
		MASTER_ERRORRISE "Custom string.h functions are not supporting yet."
#	endif /* #! C89+ !# */
#endif /* #! string.h !# */

#if MASTER_LIBRARY_HAVE_MATH_H == 1
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
#	define MASTER_MATH_J0 j0
#	define MASTER_MATH_J1 j1
#	define MASTER_MATH_JN jn
#	define MASTER_MATH_SCALB scalb
#	define MASTER_MATH_Y0 y0
#	define MASTER_MATH_Y1 y1
#	define MASTER_MATH_YN yn
#else
#	if MASTER_PREFER_C89_SUPPORTED
 #		error "Custom math.h functions are not supporting yet."
#	else
		MASTER_ERRORRISE "Custom math.h functions are not supporting yet."
#	endif /* #! C89+ !# */
#endif /* #! math.h !# */

/* #! MASTER Power Manipulations !# */

#define MASTER_ISPOW2( value ) ((value) > 0 && !((value) & ((value) - 1)))
#if MASTER_64_AVAILABLE == 1
#	define MASTER_ISPOW4( value ) (MASTER_ISPOW2(value) && ((value) & (UI8)0x5555555555555555))
#	define MASTER_ISPOW8( value ) (MASTER_ISPOW2(value) && ((value) & (UI8)0x9249249249249249))
#	define MASTER_ISPOW16( value ) (MASTER_ISPOW2(value) && ((value) & (UI8)0x1111111111111111))
#else
#	define MASTER_ISPOW4( value ) (MASTER_ISPOW2(value) && ((value) & (UI4)0x55555555))
#	define MASTER_ISPOW8( value ) (MASTER_ISPOW2(value) && ((value) & (UI4)0x49249249))
#	define MASTER_ISPOW16( value ) (MASTER_ISPOW2(value) && ((value) & (UI4)0x11111111))
#endif /* #! 64 Bits !# */

/* #! MASTER Overflow Macroses !# */

#define MASTER_ADD_OVERFLOW_UI1( value1, value2, carry ) (carry) = (((value1) >= ((UI1)-1) - (value2)) ? (1) : (0))
#define MASTER_ADD_OVERFLOW_UI2( value1, value2, carry ) (carry) = (((value1) >= ((UI2)-1) - (value2)) ? (1) : (0))
#define MASTER_ADD_OVERFLOW_UI4( value1, value2, carry ) (carry) = (((value1) >= ((UI4)-1) - (value2)) ? (1) : (0))
#if MASTER_64_AVAILABLE == 1
#	define MASTER_ADD_OVERFLOW_UI8( value1, value2, carry ) (carry) = (((value1) >= ((UI8)-1) - (value2)) ? (1) : (0))
#endif /* #! 64 Bits !# */

/* #! MASTER Shifts !# */

#define MASTER_RLLN( value, shift, bitCount ) (((value) << (shift)) | ((value) >> ((bitCount) - (shift))))
#define MASTER_RLRN( value, shift, bitCount ) (((value) >> (shift)) | ((value) << ((bitCount) - (shift))))

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateleft8)
#	define MASTER_RLL1( value, shift ) __builtin_rotateleft8(value, shift)
#else
#	define MASTER_RLL1( value, shift ) MASTER_RLLN(value, shift, 8)
#endif /* #! Rotate left 1 byte !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateleft16)
#	define MASTER_RLL2( value, shift ) __builtin_rotateleft16(value, shift)
#else
#	define MASTER_RLL2( value, shift ) MASTER_RLLN(value, shift, 16)
#endif /* #! Rotate left 2 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateleft32)
#	define MASTER_RLL4( value, shift ) __builtin_rotateleft32(value, shift)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_stdc_rotate_left)
#	define MASTER_RLL4( value, shift ) __builtin_stdc_rotate_left(value, shift)
#elif defined(_MSC_VER)
#	define MASTER_RLL4( value, shift ) _rotl(value, shift)
#else
#	define MASTER_RLL4( value, shift ) MASTER_RLLN(value, shift, 32)
#endif /* #! Rotate left 4 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateleft64)
#	define MASTER_RLL8( value, shift ) __builtin_rotateleft64(value, shift)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_stdc_rotate_left)
#	define MASTER_RLL8( value, shift ) __builtin_stdc_rotate_left(value, shift)
#elif defined(_MSC_VER)
#	define MASTER_RLL8( value, shift ) _rotl64(value, shift)
#else
#	define MASTER_RLL8( value, shift ) MASTER_RLLN(value, shift, 64)
#endif /* #! Rotate left 8 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateright8)
#	define MASTER_RLR1( value, shift ) __builtin_rotateright8(value, shift)
#else
#	define MASTER_RLR1( value, shift ) MASTER_RLRN(value, shift, 8)
#endif /* #! Rotate right 1 byte !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateright16)
#	define MASTER_RLR2( value, shift ) __builtin_rotateright16(value, shift)
#else
#	define MASTER_RLR2( value, shift ) MASTER_RLRN(value, shift, 16)
#endif /* #! Rotate right 2 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateright32)
#	define MASTER_RLR4( value, shift ) __builtin_rotateright32(value, shift)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_stdc_rotate_right)
#	define MASTER_RLR4( value, shift ) __builtin_stdc_rotate_right(value, shift)
#elif defined(_MSC_VER)
#	define MASTER_RLR4( value, shift ) _rotr(value, shift)
#else
#	define MASTER_RLR4( value, shift ) MASTER_RLRN(value, shift, 32)
#endif /* #! Rotate right 4 bytes !# */

#if MASTER_COMPILER_HAS_BUILTIN(__builtin_rotateright64)
#	define MASTER_RLR8( value, shift ) __builtin_rotateright64(value, shift)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_stdc_rotate_right)
#	define MASTER_RLR8( value, shift ) __builtin_stdc_rotate_right(value, shift)
#elif defined(_MSC_VER)
#	define MASTER_RLR8( value, shift ) _rotr64(value, shift)
#else
#	define MASTER_RLR8( value, shift ) MASTER_RLRN(value, shift, 64)
#endif /* #! Rotate right 8 bytes !# */

/* #! add (((value) < 0) ? (-1 - ((-1 - (value)) >> (shift))) : ((value) >> (shift))) ? !# */
#define MASTER_SRAGEN( value, shift ) (((value) < 0) ? (~((~(value)) >> (shift))) : ((value) >> (shift)))
#define MASTER_SRA1( value, shift ) (((value) >> (shift)) | (((value) & (UI1)0x80) ? (~((UI1)0xFF >> (shift))) : (0)))
#define MASTER_SRA2( value, shift ) (((value) >> (shift)) | (((value) & (UI2)0x8000) ? (~((UI2)0xFFFF >> (shift))) : (0)))
#define MASTER_SRA4( value, shift ) (((value) >> (shift)) | (((value) & (UI4)0x80000000) ? (~((UI2)0xFFFFFFFF >> (shift))) : (0)))
#define MASTER_SRA8( value, shift ) (((value) >> (shift)) | (((value) & (UI8)0x8000000000000000) ? (~((UI8)0xFFFFFFFFFFFFFFFF >> (shift))) : (0)))

/* #! MASTER Endian !# */

#define MASTER_LITTLE_ENDIAN_ORDER (0x04030201)
#define MASTER_BIG_ENDIAN_ORDER (0x01020304)
#define MASTER_NUXI_ENDIAN_ORDER (0x03040102)
#define MASTER_PDP_ENDIAN_ORDER (0x02010403)

#define MASTER_UNKNOWN_ENDIAN (0)
#define MASTER_LITTLE_ENDIAN (1)
#define MASTER_BIG_ENDIAN (2)
#define MASTER_NUXI_ENDIAN (4)
#define MASTER_PDP_ENDIAN (8)

#if defined(MASTER_ENDIANNESS) && \
	MASTER_ENDIANNESS != MASTER_LITTLE_ENDIAN && \
	MASTER_ENDIANNESS != MASTER_BIG_ENDIAN && \
	MASTER_ENDIANNESS != MASTER_NUXI_ENDIAN && \
	MASTER_ENDIANNESS != MASTER_PDP_ENDIAN
#	undef MASTER_ENDIANNESS
#endif /* #! Predefined Macro - Check to compatible value !# */

#ifndef MASTER_ENDIANNESS
#	if (defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && __BYTE_ORDER__ + 0 == __ORDER_LITTLE_ENDIAN__ + 0) || (defined(__LITTLE_ENDIAN__) && __LITTLE_ENDIAN__ + 0 == 1)
#		define MASTER_ENDIANNESS MASTER_LITTLE_ENDIAN
#	elif (defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ + 0 == __ORDER_BIG_ENDIAN__ + 0) || (defined(__BIG_ENDIAN__) && __BIG_ENDIAN__ + 0 == 1)
#		define MASTER_ENDIANNESS MASTER_BIG_ENDIAN
#	elif (defined(__BYTE_ORDER__) && defined(__ORDER_NUXI_ENDIAN__) && __BYTE_ORDER__ + 0 == __ORDER_NUXI_ENDIAN__ + 0) || (defined(__NUXI_ENDIAN__) && __NUXI_ENDIAN__ + 0 == 1)
#		define MASTER_ENDIANNESS MASTER_NUXI_ENDIAN
#	elif (defined(__BYTE_ORDER__) && defined(__ORDER_PDP_ENDIAN__) && __BYTE_ORDER__ + 0 == __ORDER_PDP_ENDIAN__ + 0) || (defined(__PDP_ENDIAN__) && __PDP_ENDIAN__ + 0 == 1)
#		define MASTER_ENDIANNESS MASTER_PDP_ENDIAN
#	else
#		if MASTER_ARCHITECTURE_ENDIAN == MASTER_LITTLE_ENDIAN
#			define MASTER_ENDIANNESS MASTER_LITTLE_ENDIAN
#		elif MASTER_ARCHITECTURE_ENDIAN == MASTER_BIG_ENDIAN
#			define MASTER_ENDIANNESS MASTER_BIG_ENDIAN
#		elif MASTER_ARCHITECTURE_ENDIAN == MASTER_NUXI_ENDIAN
#			define MASTER_ENDIANNESS MASTER_NUXI_ENDIAN
#		elif MASTER_ARCHITECTURE_ENDIAN == MASTER_PDP_ENDIAN
#			define MASTER_ENDIANNESS MASTER_PDP_ENDIAN
#		endif /* #! Architecture Endian !# */
#		ifndef MASTER_ENDIANNESS
			UI1 MASTER_ENDIANNESS = 0;
			void
			MASTER_getEndianness( void ) {
				union {
					UI4 ui4Value;
					UI1 ui1Value[4];
				} number;
				number.ui1Value[0] = 0x01;
				number.ui1Value[1] = 0x02;
				number.ui1Value[2] = 0x03;
				number.ui1Value[3] = 0x04;
				if (number.ui4Value == MASTER_BIG_ENDIAN_ORDER)
					MASTER_ENDIANNESS = MASTER_BIG_ENDIAN;
				otherwise (number.ui4Value == MASTER_LITTLE_ENDIAN_ORDER)
					MASTER_ENDIANNESS = MASTER_LITTLE_ENDIAN;
				otherwise (number.ui4Value == MASTER_NUXI_ENDIAN_ORDER)
					MASTER_ENDIANNESS = MASTER_NUXI_ENDIAN;
				otherwise (number.ui4Value == MASTER_PDP_ENDIAN_ORDER)
					MASTER_ENDIANNESS = MASTER_PDP_ENDIAN;
				else
					MASTER_ENDIANNESS = MASTER_UNKNOWN_ENDIAN;
			}
#			if MASTER_COMPILER_WARNING_AVAIL == 1
 #				warning "Unknown endianness. Using generic. Please, use function MASTER_getEndianness() in begin in main."
#			endif /* #! Warning !# */
#			define MASTER_ENDIANNESS MASTER_getEndianness()
#			define MASTER_UNKNOWN_ENDIANNESS
#		endif /* #! MASTER_ENDIANNESS !# */
#	endif /* #! ENDIANNESS !# */
#endif /* #! Endian !# */

#if defined(_MSC_VER)
#	define MASTER_BSWAP2( value ) _byteswap_ushort(value)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_bswap16)
#	define MASTER_BSWAP2( value ) __builtin_bswap16(value)
#else
#	define MASTER_BSWAP2( value ) (((value) >> 8) | ((value) << 8))
#endif /* #! Byte swap 2 bytes !# */

#if defined(_MSC_VER)
#	define MASTER_BSWAP4( value ) _byteswap_ulong(value)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_bswap32)
#	define MASTER_BSWAP4( value ) __builtin_bswap32(value)
#else
#	define MASTER_BSWAP4( value ) ( \
	(((value) >> 24) & 0x000000FF) | \
	(((value) >> 8) & 0x0000FF00) | \
	(((value) << 8) & 0x00FF0000) | \
	(((value) << 24) & 0xFF000000))
#endif /* #! Byte swap 4 bytes !# */

#if defined(_MSC_VER)
#	define MASTER_BSWAP8( value ) _byteswap_ulong(value)
#elif MASTER_COMPILER_HAS_BUILTIN(__builtin_bswap64)
#	define MASTER_BSWAP8( value ) __builtin_bswap64(value)
#else
#	define MASTER_BSWAP8( value ) ( \
	(((value) >> 56) & 0x00000000000000FF) | \
	(((value) >> 40) & 0x000000000000FF00) | \
	(((value) >> 24) & 0x0000000000FF0000) | \
	(((value) >> 8) & 0x00000000FF000000) | \
	(((value) << 8) & 0x000000FF00000000) | \
	(((value) << 24) & 0x0000FF0000000000) | \
	(((value) << 40) & 0x00FF000000000000) | \
	(((value) << 56) & 0xFF00000000000000))
#endif /* #! Byte swap 8 bytes !# */
#define MASTER_BSWAP_GENERIC( value, byteCount ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_BSWAP2(value)) : ((byteCount) == 4) ? (MASTER_BSWAP4(value)) : (MASTER_BSWAP8(value)))

#define MASTER_IS_LE() (MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN)
#define MASTER_IS_BE() (MASTER_ENDIANNESS == MASTER_BIG_ENDIAN)
#define MASTER_IS_NUXI() (MASTER_ENDIANNESS == MASTER_NUXI_ENDIAN)
#define MASTER_IS_PDP() (MASTER_ENDIANNESS == MASTER_PDP_ENDIAN)
#ifdef MASTER_UNKNOWN_ENDIANNESS
#	define MASTER_IS_GENE() (1)
#else
#	define MASTER_IS_GENE() (0)
#endif /* #! MASTER_UNKNOWN_ENDIANNESS !# */

#define MASTER_L2LE2( value ) (value)
#define MASTER_L2LE4( value ) (value)
#define MASTER_L2LE8( value ) (value)
#define MASTER_L2BE2( value ) MASTER_BSWAP2(value)
#define MASTER_L2BE4( value ) MASTER_BSWAP4(value)
#define MASTER_L2BE8( value ) MASTER_BSWAP8(value)
#define MASTER_L2NUXI2( value ) (value)
#define MASTER_L2NUXI4( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_L2NUXI8( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))
#define MASTER_L2PDPE2( value ) MASTER_BSWAP2(value)
#define MASTER_L2PDPE4( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_L2PDPE8( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_L2LE( value ) (value)
#define MASTER_L2BE( value ) MASTER_BSWAP_GENERIC(value, sizeof(value))
#define MASTER_L2NUXI( value, byteCount ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_L2NUXI2(value)) : ((byteCount) == 4) ? (MASTER_L2NUXI4(value)) : (MASTER_L2NUXI8(value)))
#define MASTER_L2PDPE( value, byteCount ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_L2PDPE2(value)) : ((byteCount) == 4) ? (MASTER_L2PDPE4(value)) : (MASTER_L2PDP64(value)))

#define MASTER_B2LE2( value ) MASTER_BSWAP2(value)
#define MASTER_B2LE4( value ) MASTER_BSWAP4(value)
#define MASTER_B2LE8( value ) MASTER_BSWAP8(value)
#define MASTER_B2BE2( value ) (value)
#define MASTER_B2BE4( value ) (value)
#define MASTER_B2BE8( value ) (value)
#define MASTER_B2NUXI2( value ) MASTER_BSWAP2(value)
#define MASTER_B2NUXI4( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_B2NUXI8( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_B2PDPE2( value ) (value)
#define MASTER_B2PDPE4( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_B2PDPE8( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))
#define MASTER_B2LE( value ) MASTER_BSWAP_GENERIC(value, sizeof(value))
#define MASTER_B2BE( value ) (value)
#define MASTER_B2NUXI( value, byteCount ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_B2NUXI2(value)) : ((byteCount) == 4) ? (MASTER_B2NUXI4(value)) : (MASTER_B2NUXI8(value)))
#define MASTER_B2PDPE( value, byteCount ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_B2PDPE2(value)) : ((byteCount) == 4) ? (MASTER_B2PDPE4(value)) : (MASTER_B2PDP64(value)))

#define MASTER_NUXI2LE2( value ) (value)
#define MASTER_NUXI2LE4( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_NUXI2LE8( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))
#define MASTER_NUXI2BE2( value ) MASTER_BSWAP2(value)
#define MASTER_NUXI2BE4( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_NUXI2BE8( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_NUXI2NUXI2( value ) (value)
#define MASTER_NUXI2NUXI4( value ) (value)
#define MASTER_NUXI2NUXI8( value ) (value)
#define MASTER_NUXI2PDPE2( value ) MASTER_BSWAP2(value)
#define MASTER_NUXI2PDPE4( value ) MASTER_BSWAP4(value)
#define MASTER_NUXI2PDPE8( value ) MASTER_BSWAP8(value)
#define MASTER_NUXI2LE( value ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_NUXI2LE2(value)) : ((byteCount) == 4) ? (MASTER_NUXI2LE4(value)) : (MASTER_NUXI2LE8(value)))
#define MASTER_NUXI2BE( value ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_NUXI2BE2(value)) : ((byteCount) == 4) ? (MASTER_NUXI2BE4(value)) : (MASTER_NUXI2BE8(value)))
#define MASTER_NUXI2NUXI( value ) (value)
#define MASTER_NUXI2PDPE( value, byteCount ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_NUXI2PDPE2(value)) : ((byteCount) == 4) ? (MASTER_NUXI2PDPE4(value)) : (MASTER_NUXI2PDPE8(value)))

#define MASTER_PDP2LE2( value ) MASTER_BSWAP2(value)
#define MASTER_PDP2LE4( value ) ( \
	(((value) >> 16) & 0x0000FFFF) | \
	(((value) << 16) & 0xFFFF0000))
#define MASTER_PDP2LE8( value ) ( \
	(((value) >> 48) & 0x000000000000FFFF) | \
	(((value) >> 16) & 0x00000000FFFF0000) | \
	(((value) << 16) & 0x0000FFFF00000000) | \
	(((value) << 48) & 0xFFFF000000000000))
#define MASTER_PDP2BE2( value ) (value)
#define MASTER_PDP2BE4( value ) ( \
	(((value) >> 8) & 0x00FF00FF) | \
	(((value) << 8) & 0xFF00FF00))
#define MASTER_PDP2BE8( value ) ( \
	(((value) >> 8) & 0x00FF00FF00FF00FF) | \
	(((value) << 8) & 0xFF00FF00FF00FF00))
#define MASTER_PDP2NUXI2( value ) MASTER_BSWAP2(value)
#define MASTER_PDP2NUXI4( value ) MASTER_BSWAP4(value)
#define MASTER_PDP2NUXI8( value ) MASTER_BSWAP8(value)
#define MASTER_PDP2PDPE2( value ) (value)
#define MASTER_PDP2PDPE4( value ) (value)
#define MASTER_PDP2PDPE8( value ) (value)
#define MASTER_PDP2LE( value ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_PDP2LE2(value)) : ((byteCount) == 4) ? (MASTER_PDP2LE4(value)) : (MASTER_PDP2LE8(value)))
#define MASTER_PDP2BE( value ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_PDP2BE2(value)) : ((byteCount) == 4) ? (MASTER_PDP2BE4(value)) : (MASTER_PDP2BE8(value)))
#define MASTER_PDP2NUXI( value, byteCount ) ( \
	((byteCount) == 1) ? (value) : ((byteCount) == 2) ? (MASTER_PDP2NUXI2(value)) : ((byteCount) == 4) ? (MASTER_PDP2NUXI4(value)) : (MASTER_PDP2NUXI8(value)))
#define MASTER_PDP2PDPE( value, byteCount ) (value)

#define MASTER_FUNC_ENDIAN( endian_little_func, endian_big_func, endian_nuxi_func, endian_pdp_func ) ( \
	(MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN) ? (endian_little_func) : \
	(MASTER_ENDIANNESS == MASTER_BIG_ENDIAN) ? (endian_big_func) : \
	(MASTER_ENDIANNESS == MASTER_NUXI_ENDIAN) ? (endian_nuxi_func) : (endian_pdp_func))

#define MASTER_ITERATE_L2H_LE( value ) ((value) += 1)
#define MASTER_ITERATE_H2L_LE( value ) ((value) -= 1)
#define MASTER_ITERATE_L2H_BE( value ) ((value) -= 1)
#define MASTER_ITERATE_H2L_BE( value ) ((value) += 1)
#define MASTER_ITERATE_L2H_PDP( value ) (((value) & 1) ? ((value) &= ~1) : ((value) += 3))
#define MASTER_ITERATE_H2L_PDP( value ) ((!((value) & 1)) ? ((value) |= 1) : ((value) -= 3))

#define MASTER_LELOW( minValue, maxValue ) (minValue)
#define MASTER_LEHIGH( minValue, maxValue ) (maxValue)
#define MASTER_BELOW( minValue, maxValue ) (maxValue)
#define MASTER_BEHIGH( minValue, maxValue ) (minValue)
#define MASTER_PDPELOW( minValue, maxValue ) ((minValue) + 1)
#define MASTER_PDPEHIGH( minValue, maxValue ) ((maxValue) - 1)

/* ENTER TODO */

#ifndef MASTER_UNKNOWN_ENDIANNESS
#	if MASTER_ENDIANNESS == MASTER_LITTLE_ENDIAN
#		define MASTER_TOLE( value ) (value)
#		define MASTER_TOLE2( value ) (value)
#		define MASTER_TOLE4( value ) (value)
#		define MASTER_TOLE8( value ) (value)
#		define MASTER_TOBE( value ) MASTER_L2BE(value)
#		define MASTER_TOBE2( value ) MASTER_L2BE2(value)
#		define MASTER_TOBE4( value ) MASTER_L2BE4(value)
#		define MASTER_TOBE8( value ) MASTER_L2BE8(value)
#		define MASTER_TONUXI( value ) MASTER_L2NUXI(value)
#		define MASTER_TONUXI2( value ) MASTER_L2NUXI2(value)
#		define MASTER_TONUXI4( value ) MASTER_L2NUXI4(value)
#		define MASTER_TONUXI8( value ) MASTER_L2NUXI8(value)
#		define MASTER_TOPDPE( value ) MASTER_L2PDPE(value)
#		define MASTER_TOPDPE2( value ) MASTER_L2PDPE2(value)
#		define MASTER_TOPDPE4( value ) MASTER_L2PDPE4(value)
#		define MASTER_TOPDPE8( value ) MASTER_L2PDPE8(value)
#		define MASTER_FROMLE( value ) (value)
#		define MASTER_FROMLE2( value ) (value)
#		define MASTER_FROMLE4( value ) (value)
#		define MASTER_FROMLE8( value ) (value)
#		define MASTER_FROMBE( value ) MASTER_B2LE(value)
#		define MASTER_FROMBE2( value ) MASTER_B2LE2(value)
#		define MASTER_FROMBE4( value ) MASTER_B2LE4(value)
#		define MASTER_FROMBE8( value ) MASTER_B2LE8(value)
#		define MASTER_FROMNUXI( value ) MASTER_NUXI2LE(value)
#		define MASTER_FROMNUXI2( value ) MASTER_NUXI2LE2(value)
#		define MASTER_FROMNUXI4( value ) MASTER_NUXI2LE4(value)
#		define MASTER_FROMNUXI8( value ) MASTER_NUXI2LE8(value)
#		define MASTER_FROMPDPE( value ) MASTER_PDP2LE(value)
#		define MASTER_FROMPDPE2( value ) MASTER_PDP2LE2(value)
#		define MASTER_FROMPDPE4( value ) MASTER_PDP2LE4(value)
#		define MASTER_FROMPDPE8( value ) MASTER_PDP2LE8(value)
#		define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_LE(value)
#		define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_LE(value)
#		define MASTER_GLIBE( minValue, maxValue ) MASTER_LELOW( minValue, maxValue )
#		define MASTER_GHIBE( minValue, maxValue ) MASTER_LEHIGH( minValue, maxValue )
#	elif MASTER_ENDIANNESS == MASTER_BIG_ENDIAN
#		define MASTER_TOLE( value ) MASTER_B2LE(value)
#		define MASTER_TOLE2( value ) MASTER_B2LE2(value)
#		define MASTER_TOLE4( value ) MASTER_B2LE4(value)
#		define MASTER_TOLE8( value ) MASTER_B2LE8(value)
#		define MASTER_TOBE( value ) (value)
#		define MASTER_TOBE2( value ) (value)
#		define MASTER_TOBE4( value ) (value)
#		define MASTER_TOBE8( value ) (value)
#		define MASTER_TONUXI( value ) MASTER_B2NUXI(value)
#		define MASTER_TONUXI2( value ) MASTER_B2NUXI2(value)
#		define MASTER_TONUXI4( value ) MASTER_B2NUXI4(value)
#		define MASTER_TONUXI8( value ) MASTER_B2NUXI8(value)
#		define MASTER_TOPDPE( value ) MASTER_B2PDPE(value)
#		define MASTER_TOPDPE2( value ) MASTER_B2PDPE2(value)
#		define MASTER_TOPDPE4( value ) MASTER_B2PDPE4(value)
#		define MASTER_TOPDPE8( value ) MASTER_B2PDPE8(value)
#		define MASTER_FROMLE( value ) MASTER_L2BE(value)
#		define MASTER_FROMLE2( value ) MASTER_L2BE2(value)
#		define MASTER_FROMLE4( value ) MASTER_L2BE4(value)
#		define MASTER_FROMLE8( value ) MASTER_L2BE8(value)
#		define MASTER_FROMBE( value ) (value)
#		define MASTER_FROMBE2( value ) (value)
#		define MASTER_FROMBE4( value ) (value)
#		define MASTER_FROMBE8( value ) (value)
#		define MASTER_FROMNUXI( value ) MASTER_NUXI2BE(value)
#		define MASTER_FROMNUXI2( value ) MASTER_NUXI2BE2(value)
#		define MASTER_FROMNUXI4( value ) MASTER_NUXI2BE4(value)
#		define MASTER_FROMNUXI8( value ) MASTER_NUXI2BE8(value)
#		define MASTER_FROMPDPE( value ) MASTER_PDP2BE(value)
#		define MASTER_FROMPDPE2( value ) MASTER_PDP2BE2(value)
#		define MASTER_FROMPDPE4( value ) MASTER_PDP2BE4(value)
#		define MASTER_FROMPDPE8( value ) MASTER_PDP2BE8(value)
#		define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_BE(value)
#		define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_BE(value)
#		define MASTER_GLIBE( minValue, maxValue ) MASTER_BELOW( minValue, maxValue )
#		define MASTER_GHIBE( minValue, maxValue ) MASTER_BEHIGH( minValue, maxValue )
#	elif MASTER_ENDIANNESS == MASTER_NUXI_ENDIAN
#		define MASTER_TOLE( value ) MASTER_NUXI2LE(value)
#		define MASTER_TOLE2( value ) MASTER_NUXI2LE2(value)
#		define MASTER_TOLE4( value ) MASTER_NUXI2LE4(value)
#		define MASTER_TOLE8( value ) MASTER_NUXI2LE8(value)
#		define MASTER_TOBE( value ) MASTER_NUXI2BE(value)
#		define MASTER_TOBE2( value ) MASTER_NUXI2BE2(value)
#		define MASTER_TOBE4( value ) MASTER_NUXI2BE4(value)
#		define MASTER_TOBE8( value ) MASTER_NUXI2BE8(value)
#		define MASTER_TONUXI( value ) (value)
#		define MASTER_TONUXI2( value ) (value)
#		define MASTER_TONUXI4( value ) (value)
#		define MASTER_TONUXI8( value ) (value)
#		define MASTER_TOPDPE( value ) MASTER_NUXI2PDPE(value)
#		define MASTER_TOPDPE2( value ) MASTER_NUXI2PDPE2(value)
#		define MASTER_TOPDPE4( value ) MASTER_NUXI2PDPE4(value)
#		define MASTER_TOPDPE8( value ) MASTER_NUXI2PDPE8(value)
#		define MASTER_FROMLE( value ) MASTER_L2PDPE(value)
#		define MASTER_FROMLE2( value ) MASTER_L2PDPE2(value)
#		define MASTER_FROMLE4( value ) MASTER_L2PDPE4(value)
#		define MASTER_FROMLE8( value ) MASTER_L2PDPE8(value)
#		define MASTER_FROMBE( value ) MASTER_B2NUXI(value)
#		define MASTER_FROMBE2( value ) MASTER_B2NUXI2(value)
#		define MASTER_FROMBE4( value ) MASTER_B2NUXI4(value)
#		define MASTER_FROMBE8( value ) MASTER_B2NUXI8(value)
#		define MASTER_FROMNUXI( value ) (value)
#		define MASTER_FROMNUXI2( value ) (value)
#		define MASTER_FROMNUXI4( value ) (value)
#		define MASTER_FROMNUXI8( value ) (value)
#		define MASTER_FROMPDPE( value ) MASTER_PDP2NUXI(value)
#		define MASTER_FROMPDPE2( value ) MASTER_PDP2NUXI2(value)
#		define MASTER_FROMPDPE4( value ) MASTER_PDP2NUXI4(value)
#		define MASTER_FROMPDPE8( value ) MASTER_PDP2NUXI8(value)
#		define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_PDPE(value)
#		define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_PDPE(value)
#		define MASTER_GLIBE( minValue, maxValue ) MASTER_PDPELOW( minValue, maxValue )
#		define MASTER_GHIBE( minValue, maxValue ) MASTER_PDPEHIGH( minValue, maxValue )
#	elif MASTER_ENDIANNESS == MASTER_PDP_ENDIAN
		/* #! PDP have maximum 32 bits. But in 64 bit endian will be 78563412 !# */
#		define MASTER_TOLE( value ) MASTER_PDP2LE(value)
#		define MASTER_TOLE2( value ) MASTER_PDP2LE2(value)
#		define MASTER_TOLE4( value ) MASTER_PDP2LE4(value)
#		define MASTER_TOLE8( value ) MASTER_PDP2LE8(value)
#		define MASTER_TOBE( value ) MASTER_PDP2BE(value)
#		define MASTER_TOBE2( value ) MASTER_PDP2BE2(value)
#		define MASTER_TOBE4( value ) MASTER_PDP2BE4(value)
#		define MASTER_TOBE8( value ) MASTER_PDP2BE8(value)
#		define MASTER_TONUXI( value ) MASTER_PDP2NUXI(value)
#		define MASTER_TONUXI2( value ) MASTER_PDP2NUXI2(value)
#		define MASTER_TONUXI4( value ) MASTER_PDP2NUXI4(value)
#		define MASTER_TONUXI8( value ) MASTER_PDP2NUXI8(value)
#		define MASTER_TOPDPE( value ) (value)
#		define MASTER_TOPDPE2( value ) (value)
#		define MASTER_TOPDPE4( value ) (value)
#		define MASTER_TOPDPE8( value ) (value)
#		define MASTER_FROMLE( value ) MASTER_L2PDPE(value)
#		define MASTER_FROMLE2( value ) MASTER_L2PDPE2(value)
#		define MASTER_FROMLE4( value ) MASTER_L2PDPE4(value)
#		define MASTER_FROMLE8( value ) MASTER_L2PDPE8(value)
#		define MASTER_FROMBE( value ) MASTER_B2PDPE(value)
#		define MASTER_FROMBE2( value ) MASTER_B2PDPE2(value)
#		define MASTER_FROMBE4( value ) MASTER_B2PDPE4(value)
#		define MASTER_FROMBE8( value ) MASTER_B2PDPE8(value)
#		define MASTER_FROMNUXI( value ) MASTER_NUXI2PDPE(value)
#		define MASTER_FROMNUXI2( value ) MASTER_NUXI2PDPE2(value)
#		define MASTER_FROMNUXI4( value ) MASTER_NUXI2PDPE4(value)
#		define MASTER_FROMNUXI8( value ) MASTER_NUXI2PDPE8(value)
#		define MASTER_FROMPDPE( value ) (value)
#		define MASTER_FROMPDPE2( value ) (value)
#		define MASTER_FROMPDPE4( value ) (value)
#		define MASTER_FROMPDPE8( value ) (value)
#		define MASTER_ITERATE_L2H( value ) MASTER_ITERATE_L2H_PDPE(value)
#		define MASTER_ITERATE_H2L( value ) MASTER_ITERATE_H2L_PDPE(value)
#		define MASTER_GLIBE( minValue, maxValue ) MASTER_PDPELOW( minValue, maxValue )
#		define MASTER_GHIBE( minValue, maxValue ) MASTER_PDPEHIGH( minValue, maxValue )
#	endif /* #! Endianness !# */
#else /* #! MASTER_UNKNOWN_ENDIAN - runtime check !# */
/* #! TODO !# */
#	define MASTER_TOLE( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE(value), MASTER_B2LE(value), MASTER_NUXI2LE(value), MASTER_PDP2LE(value))
#	define MASTER_TOLE2( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE2(value), MASTER_B2LE2(value), MASTER_NUXI2LE2(value), MASTER_PDP2LE2(value))
#	define MASTER_TOLE4( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE4(value), MASTER_B2LE4(value), MASTER_NUXI2LE4(value), MASTER_PDP2LE4(value))
#	define MASTER_TOLE8( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE8(value), MASTER_B2LE8(value), MASTER_NUXI2LE8(value), MASTER_PDP2LE8(value))
#	define MASTER_TOBE( value ) MASTER_FUNC_ENDIAN(MASTER_L2BE(value), MASTER_B2BE(value), MASTER_NUXI2BE(value), MASTER_PDP2BE(value))
#	define MASTER_TOBE2( value ) MASTER_FUNC_ENDIAN(MASTER_L2BE2(value), MASTER_B2BE2(value), MASTER_NUXI2BE2(value), MASTER_PDP2BE2(value))
#	define MASTER_TOBE4( value ) MASTER_FUNC_ENDIAN(MASTER_L2BE4(value), MASTER_B2BE4(value), MASTER_NUXI2BE4(value), MASTER_PDP2BE4(value))
#	define MASTER_TOBE8( value ) MASTER_FUNC_ENDIAN(MASTER_L2BE8(value), MASTER_B2BE8(value), MASTER_NUXI2BE8(value), MASTER_PDP2BE8(value))
#	define MASTER_TONUXI( value ) MASTER_FUNC_ENDIAN(MASTER_L2NUXI(value), MASTER_B2NUXI(value), MASTER_NUXI2NUXI(value), MASTER_PDP2NUXI(value))
#	define MASTER_TONUXI2( value ) MASTER_FUNC_ENDIAN(MASTER_L2NUXI2(value), MASTER_B2NUXI2(value), MASTER_NUXI2NUXI2(value), MASTER_PDP2NUXI2(value))
#	define MASTER_TONUXI4( value ) MASTER_FUNC_ENDIAN(MASTER_L2NUXI4(value), MASTER_B2NUXI4(value), MASTER_NUXI2NUXI4(value), MASTER_PDP2NUXI4(value))
#	define MASTER_TONUXI8( value ) MASTER_FUNC_ENDIAN(MASTER_L2NUXI8(value), MASTER_B2NUXI8(value), MASTER_NUXI2NUXI8(value), MASTER_PDP2NUXI8(value))
#	define MASTER_TOPDPE( value ) MASTER_FUNC_ENDIAN(MASTER_L2PDPE(value), MASTER_B2PDPE(value), MASTER_NUXI2PDPE(value), MASTER_PDP2PDPE(value))
#	define MASTER_TOPDPE2( value ) MASTER_FUNC_ENDIAN(MASTER_L2PDPE2(value), MASTER_B2PDPE2(value), MASTER_NUXI2PDPE2(value), MASTER_PDP2PDPE2(value))
#	define MASTER_TOPDPE4( value ) MASTER_FUNC_ENDIAN(MASTER_L2PDPE4(value), MASTER_B2PDPE4(value), MASTER_NUXI2PDPE4(value), MASTER_PDP2PDPE4(value))
#	define MASTER_TOPDPE8( value ) MASTER_FUNC_ENDIAN(MASTER_L2PDPE8(value), MASTER_B2PDPE8(value), MASTER_NUXI2PDPE8(value), MASTER_PDP2PDPE8(value))
#	define MASTER_FROMLE( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE(value), MASTER_L2BE(value), MASTER_L2NUXI(value), MASTER_L2PDPE(value))
#	define MASTER_FROMLE2( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE2(value), MASTER_L2BE2(value), MASTER_L2NUXI2(value), MASTER_L2PDPE2(value))
#	define MASTER_FROMLE4( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE4(value), MASTER_L2BE4(value), MASTER_L2NUXI4(value), MASTER_L2PDPE4(value))
#	define MASTER_FROMLE8( value ) MASTER_FUNC_ENDIAN(MASTER_L2LE8(value), MASTER_L2BE8(value), MASTER_L2NUXI8(value), MASTER_L2PDPE8(value))
#	define MASTER_FROMBE( value ) MASTER_FUNC_ENDIAN(MASTER_B2LE(value), MASTER_B2BE(value), MASTER_B2NUXI(value), MASTER_B2PDPE(value))
#	define MASTER_FROMBE2( value ) MASTER_FUNC_ENDIAN(MASTER_B2LE2(value), MASTER_B2BE2(value), MASTER_B2NUXI2(value), MASTER_B2PDPE2(value))
#	define MASTER_FROMBE4( value ) MASTER_FUNC_ENDIAN(MASTER_B2LE4(value), MASTER_B2BE4(value), MASTER_B2NUXI4(value), MASTER_B2PDPE4(value))
#	define MASTER_FROMBE8( value ) MASTER_FUNC_ENDIAN(MASTER_B2LE8(value), MASTER_B2BE8(value), MASTER_B2NUXI8(value), MASTER_B2PDPE8(value))
#	define MASTER_FROMNUXI( value ) MASTER_FUNC_ENDIAN(MASTER_NUXI2LE(value), MASTER_NUXI2BE(value), MASTER_NUXI2NUXI(value), MASTER_NUXI2PDPE(value))
#	define MASTER_FROMNUXI2( value ) MASTER_FUNC_ENDIAN(MASTER_NUXI2LE2(value), MASTER_NUXI2BE2(value), MASTER_NUXI2NUXI2(value), MASTER_NUXI2PDPE2(value))
#	define MASTER_FROMNUXI4( value ) MASTER_FUNC_ENDIAN(MASTER_NUXI2LE4(value), MASTER_NUXI2BE4(value), MASTER_NUXI2NUXI4(value), MASTER_NUXI2PDPE4(value))
#	define MASTER_FROMNUXI8( value ) MASTER_FUNC_ENDIAN(MASTER_NUXI2LE8(value), MASTER_NUXI2BE8(value), MASTER_NUXI2NUXI8(value), MASTER_NUXI2PDPE8(value))
#	define MASTER_FROMPDPE( value ) MASTER_FUNC_ENDIAN(MASTER_PDP2LE(value), MASTER_PDP2BE(value), MASTER_PDP2NUXI(value), MASTER_PDP2PDPE(value))
#	define MASTER_FROMPDPE2( value ) MASTER_FUNC_ENDIAN(MASTER_PDP2LE2(value), MASTER_PDP2BE2(value), MASTER_PDP2NUXI2(value), MASTER_PDP2PDPE2(value))
#	define MASTER_FROMPDPE4( value ) MASTER_FUNC_ENDIAN(MASTER_PDP2LE4(value), MASTER_PDP2BE4(value), MASTER_PDP2NUXI4(value), MASTER_PDP2PDPE4(value))
#	define MASTER_FROMPDPE8( value ) MASTER_FUNC_ENDIAN(MASTER_PDP2LE8(value), MASTER_PDP2BE8(value), MASTER_PDP2NUXI8(value), MASTER_PDP2PDPE8(value))
/* #! TODO !# */
#	define MASTER_ITERATE_L2H( value )
#	define MASTER_ITERATE_H2L( value )
#	define MASTER_GLIBE( minValue, maxValue )
#	define MASTER_GHIBE( minValue, maxValue )
#endif /* #! Endianness !# */

#define MASTER_UNPACK_LE2( pointer ) (UI2)((UI2)(pointer)[0] | ((UI2)(pointer)[1] << 8))
#define MASTER_UNPACK_LE3( pointer ) (UI4)((UI4)(pointer)[0] | ((UI4)(pointer)[1] << 8) | ((UI4)(pointer)[2] << 16))
#define MASTER_UNPACK_LE3_SE( pointer ) (SI4)((UI4)(pointer)[0] | ((UI4)(pointer)[1] << 8) | ((UI4)(pointer)[2] << 16) | (0xFF000000 & ((UI4)!!(UI4)pointer)[2] - 1)))
#define MASTER_UNPACK_LE4( pointer ) (UI4)((UI4)(pointer)[0] | ((UI4)(pointer)[1] << 8) | ((UI4)(pointer)[2] << 16) | ((UI4)(pointer)[3] << 24))
#define MASTER_UNPACK_LE8( pointer ) (UI8)((UI8)(pointer)[0] | ((UI8)(pointer)[1] << 8) | ((UI8)(pointer)[2] << 16) | ((UI8)(pointer)[3] << 24) | ((UI8)(pointer)[4] << 32) | ((UI8)(pointer)[5] << 40) | ((UI8)(pointer)[6] << 48) | ((UI8)(pointer)[7] << 56))

#define MASTER_UNPACK_BE2( pointer ) (UI2)((UI2)(pointer)[1] | ((UI2)(pointer)[0] << 8))
#define MASTER_UNPACK_BE3( pointer ) (UI4)((UI4)(pointer)[2] | ((UI4)(pointer)[1] << 8) | ((UI4)(pointer)[0] << 16))
#define MASTER_UNPACK_BE3_SE( pointer ) (SI4)((UI4)(pointer)[2] | ((UI4)(pointer)[1] << 8) | ((UI4)(pointer)[0] << 16) | (0xFF000000 & ((UI4)!!(UI4)(pointer)[0] - 1)))
#define MASTER_UNPACK_BE4( pointer ) (UI4)((UI4)(pointer)[3] | ((UI4)(pointer)[2] << 8) | ((UI4)(pointer)[1] << 16) | ((UI4)(pointer)[0] << 24))
#define MASTER_UNPACK_BE8( pointer ) (UI8)((UI8)(pointer)[7] | ((UI8)(pointer)[6] << 8) | ((UI8)(pointer)[5] << 16) | ((UI8)(pointer)[4] << 24) | ((UI8)(pointer)[3] << 32) | ((UI8)(pointer)[2] << 40) | ((UI8)(pointer)[1] << 48) | ((UI8)(pointer)[0] << 56))

#define MASTER_UNPACK_NUXI4( pointer ) (UI4)((UI4)(pointer)[1] | ((UI4)(pointer)[0] << 8) | ((UI4)(pointer)[3] << 16) | ((UI4)(pointer)[2] << 24))
#define MASTER_UNPACK_PDPE4( pointer ) (UI4)((UI4)(pointer)[2] | ((UI4)(pointer)[3] << 8) | ((UI4)(pointer)[0] << 16) | ((UI4)(pointer)[1] << 24))

#define MASTER_IS_ZERO_BUFFER2( pointer ) (!((pointer)[0] | (pointer)[1]))
#define MASTER_IS_ZERO_BUFFER4( pointer ) (!((pointer)[0] | (pointer)[1] | (pointer)[2] | (pointer)[3]))

#define MASTER_PACK_LE2( pointer, value ) do { \
		(pointer)[0] = (UI1)(value); \
		(pointer)[1] = (UI1)((value) >> 8); \
	} while (0)

#define MASTER_PACK_LE3( pointer, value ) do { \
		(pointer)[0] = (UI1)(value); \
		(pointer)[1] = (UI1)((value) >> 8); \
		(pointer)[2] = (UI1)((value) >> 16); \
	} while (0)

#define MASTER_PACK_LE4( pointer, value ) do { \
		(pointer)[0] = (UI1)value; \
		(pointer)[1] = (UI1)((value) >> 8); \
		(pointer)[2] = (UI1)((value) >> 16); \
		(pointer)[3] = (UI1)((value) >> 24); \
	} while (0)

#define MASTER_PACK_LE8( pointer, value ) do { \
		(pointer)[0] = (UI1)(value); \
		(pointer)[1] = (UI1)((value) >> 8); \
		(pointer)[2] = (UI1)((value) >> 16); \
		(pointer)[3] = (UI1)((value) >> 24); \
		(pointer)[4] = (UI1)((value) >> 32); \
		(pointer)[5] = (UI1)((value) >> 40); \
		(pointer)[6] = (UI1)((value) >> 48); \
		(pointer)[7] = (UI1)((value) >> 56); \
	} while (0)

#define MASTER_PACK_BE2( pointer, value ) do { \
		(pointer)[1] = (UI1)(value); \
		(pointer)[0] = (UI1)((value) >> 8); \
	} while (0)

#define MASTER_PACK_BE3( pointer, value ) do { \
		(pointer)[2] = (UI1)(value); \
		(pointer)[1] = (UI1)((value) >> 8); \
		(pointer)[0] = (UI1)((value) >> 16); \
	} while (0)

#define MASTER_PACK_BE4( pointer, value ) do { \
		(pointer)[3] = (UI1)(value); \
		(pointer)[2] = (UI1)((value) >> 8); \
		(pointer)[1] = (UI1)((value) >> 16); \
		(pointer)[0] = (UI1)((value) >> 24); \
	} while (0)

#define MASTER_PACK_BE8( pointer, value ) do { \
		(pointer)[7] = (UI1)(value); \
		(pointer)[6] = (UI1)((value) >> 8); \
		(pointer)[5] = (UI1)((value) >> 16); \
		(pointer)[4] = (UI1)((value) >> 24); \
		(pointer)[3] = (UI1)((value) >> 32); \
		(pointer)[2] = (UI1)((value) >> 40); \
		(pointer)[1] = (UI1)((value) >> 48); \
		(pointer)[0] = (UI1)((value) >> 56); \
	} while (0)

#define MASTER_PACK_NUXI4( pointer, value ) do { \
		(pointer)[1] = (UI1)(value); \
		(pointer)[0] = (UI1)((value) >> 8); \
		(pointer)[3] = (UI1)((value) >> 16); \
		(pointer)[2] = (UI1)((value) >> 24); \
	} while (0)

#define MASTER_PACK_PDPE4( pointer, value ) do { \
		(pointer)[2] = (UI1)(value); \
		(pointer)[3] = (UI1)((value) >> 8); \
		(pointer)[0] = (UI1)((value) >> 16); \
		(pointer)[1] = (UI1)((value) >> 24); \
	} while (0)

#define MASTER_ENDIAN_ACTION_2( funcLE, funcBE, argList, endian ) do { \
		if ((endian) == MASTER_LITTLE_ENDIAN) { funcLE argList; } \
		else { funcBE argList; } \
	} while (0)

#define MASTER_ENDIAN_ACTION( funcLE, funcBE, funcNUXI, funcPDPE, argList, endian ) do { \
		if ((endian) == MASTER_LITTLE_ENDIAN) { funcLE argList; } \
		otherwise ((endian) == MASTER_BIG_ENDIAN) { funcBE argList; } \
		otherwise ((endian) == MASTER_NUXI_ENDIAN) { funcNUXI argList; } \
		else { funcPDPE argList; } \
	} while (0)

/* #! MASTER Saturation Functions !# */

#define MASTER_SaturateSI1( value ) (SI1)MASTER_CLAMP(value, MASTER_SI1_MIN, MASTER_SI1_MAX)
#define MASTER_SaturateSI2( value ) (SI2)MASTER_CLAMP(value, MASTER_SI2_MIN, MASTER_SI2_MAX)
#define MASTER_SaturateSI4( value ) (SI4)MASTER_CLAMP(value, MASTER_SI4_MIN, MASTER_SI4_MAX)
#define MASTER_SaturateUI1( value ) (UI1)MASTER_CLAMP(value, MASTER_UI1_MIN, MASTER_UI1_MAX)
#define MASTER_SaturateUI2( value ) (UI2)MASTER_CLAMP(value, MASTER_UI2_MIN, MASTER_UI2_MAX)
#define MASTER_SaturateUI4( value ) (UI4)MASTER_CLAMP(value, MASTER_UI4_MIN, MASTER_UI4_MAX)

MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI1, MASTER_AddSaturateSI1, ( const SI1, const SI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI2, MASTER_AddSaturateSI2, ( const SI2, const SI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_AddSaturateSI4, ( const SI4, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI1, MASTER_SubSaturateSI1, ( const SI1, const SI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI2, MASTER_SubSaturateSI2, ( const SI2, const SI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_SubSaturateSI4, ( const SI4, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI1, MASTER_MulSaturateSI1, ( const SI1, const SI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI2, MASTER_MulSaturateSI2, ( const SI2, const SI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI4, MASTER_MulSaturateSI4, ( const SI4, const SI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_AddSaturateUI1, ( const UI1, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_AddSaturateUI2, ( const UI2, const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_AddSaturateUI4, ( const UI4, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_SubSaturateUI1, ( const UI1, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_SubSaturateUI2, ( const UI2, const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_SubSaturateUI4, ( const UI4, const UI4 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI1, MASTER_MulSaturateUI1, ( const UI1, const UI1 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI2, MASTER_MulSaturateUI2, ( const UI2, const UI2 ) );
MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI4, MASTER_MulSaturateUI4, ( const UI4, const UI4 ) );
#if MASTER_64_AVAILABLE == 1
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI8, MASTER_AddSaturateSI8, ( const SI8, const SI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI8, MASTER_SubSaturateSI8, ( const SI8, const SI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, SI8, MASTER_MulSaturateSI8, ( const SI8, const SI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_AddSaturateUI8, ( const UI8, const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_SubSaturateUI8, ( const UI8, const UI8 ) );
	MASTER_EXTERN_FUNCTION( MASTER_NO_FLAGS, UI8, MASTER_MulSaturateUI8, ( const UI8, const UI8 ) );
#endif /* #! 64 Bits !# */

#define MASTER_zzz_MACDEF_AddSaturateSIx( variableType ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_AddSaturate ## variableType /* ! */, \
		variableType, \
		( const variableType, value1 ), \
		( const variableType, value2 ) \
	) { \
		const variableType value3 = value1 + value2; \
		if (value1 > 0 && value2 > 0 && value3 < 0) return MASTER_TYPE_MAX_VALUE(variableType); \
		if (value1 < 0 && value2 < 0 && value3 > 0) return MASTER_TYPE_MIN_VALUE(variableType); \
		return value3; \
	}

#define MASTER_zzz_MACDEF_AddSaturateUIx( variableType ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_AddSaturate ## variableType /* ! */, \
		variableType, \
		( const variableType, value1 ), \
		( const variableType, value2 ) \
	) { \
		const variableType value3 = value1 + value2; \
		if (value3 < value1) return MASTER_TYPE_MAX_VALUE(variableType); \
		return value3; \
	}

#define MASTER_zzz_MACDEF_SubSaturateSIx( variableType ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_SubSaturate ## variableType /* ! */, \
		variableType, \
		( const variableType, value1 ), \
		( const variableType, value2 ) \
	) { \
		const variableType value3 = value1 - value2; \
		if (value1 >= 0 && value2 < 0 && value3 < 0) return MASTER_TYPE_MAX_VALUE(variableType); \
		if (value1 < 0 && value2 > 0 && value3 > 0) return MASTER_TYPE_MIN_VALUE(variableType); \
		return value3; \
	}

#define MASTER_zzz_MACDEF_SubSaturateUIx( variableType ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_SubSaturate ## variableType /* ! */, \
		variableType, \
		( const variableType, value1 ), \
		( const variableType, value2 ) \
	) { \
		const variableType value3 = value1 - value2; \
		if (value3 > value1) return MASTER_TYPE_MIN_VALUE(variableType); \
		return value3; \
	}

#define MASTER_zzz_MACDEF_MulSaturateSIx( variableType ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_MulSaturate ## variableType /* ! */, \
		variableType, \
		( const variableType, value1 ), \
		( const variableType, value2 ) \
	) { \
		const variableType value3 = value1 * value2; \
		return (value2 != 0 && value3 / value2 != value1) ? ( ((value1 > 0) == (value2 > 0)) ? (MASTER_TYPE_MAX_VALUE(variableType)) : (MASTER_TYPE_MIN_VALUE(variableType)) ) : (value3); \
	}

#define MASTER_zzz_MACDEF_MulSaturateUIx( variableType ) \
	MASTER_DEFINE_FUNCTION2( \
		MASTER_NO_FLAGS, \
		MASTER_EMPTY_DESCRIPTION, \
		/* ! */ MASTER_MulSaturate ## variableType /* ! */, \
		variableType, \
		( const variableType, value1 ), \
		( const variableType, value2 ) \
	) { \
		const variableType value3 = value1 * value2; \
		if (value2 != 0 && value3 / value2 != value1) return MASTER_TYPE_MAX_VALUE(variableType); \
		return value3; \
	}

MASTER_zzz_MACDEF_AddSaturateSIx( SI1 )
MASTER_zzz_MACDEF_SubSaturateSIx( SI1 )
MASTER_zzz_MACDEF_MulSaturateSIx( SI1 )
MASTER_zzz_MACDEF_AddSaturateSIx( SI2 )
MASTER_zzz_MACDEF_SubSaturateSIx( SI2 )
MASTER_zzz_MACDEF_MulSaturateSIx( SI2 )
MASTER_zzz_MACDEF_AddSaturateSIx( SI4 )
MASTER_zzz_MACDEF_SubSaturateSIx( SI4 )
MASTER_zzz_MACDEF_MulSaturateSIx( SI4 )
MASTER_zzz_MACDEF_AddSaturateUIx( UI1 )
MASTER_zzz_MACDEF_SubSaturateUIx( UI1 )
MASTER_zzz_MACDEF_MulSaturateUIx( UI1 )
MASTER_zzz_MACDEF_AddSaturateUIx( UI2 )
MASTER_zzz_MACDEF_SubSaturateUIx( UI2 )
MASTER_zzz_MACDEF_MulSaturateUIx( UI2 )
MASTER_zzz_MACDEF_AddSaturateUIx( UI4 )
MASTER_zzz_MACDEF_SubSaturateUIx( UI4 )
MASTER_zzz_MACDEF_MulSaturateUIx( UI4 )
#if MASTER_64_AVAILABLE == 1
	MASTER_zzz_MACDEF_AddSaturateSIx( SI8 )
	MASTER_zzz_MACDEF_SubSaturateSIx( SI8 )
	MASTER_zzz_MACDEF_MulSaturateSIx( SI8 )
	MASTER_zzz_MACDEF_AddSaturateUIx( UI8 )
	MASTER_zzz_MACDEF_SubSaturateUIx( UI8 )
	MASTER_zzz_MACDEF_MulSaturateUIx( UI8 )
#endif /* #! 64 Bits !# */

#undef MASTER_zzz_MACDEF_AddSaturateUIx
#undef MASTER_zzz_MACDEF_AddSaturateSIx
#undef MASTER_zzz_MACDEF_SubSaturateUIx
#undef MASTER_zzz_MACDEF_SubSaturateSIx
#undef MASTER_zzz_MACDEF_MulSaturateUIx
#undef MASTER_zzz_MACDEF_MulSaturateSIx

/* #! MASTER Comment !# */

#define MASTER_COMMENT( comment )
#define MASTER_UNUSED( variable ) (void)variable

/* #! MASTER Libraries States !# */

#define MASTER_LIBRARY_STATE_MASK 0x7
#define MASTER_LIBRARY_INCREMENT_MASK 0x8
#define MASTER_LIBRARY_CHARNAME_MASK 0x30
#define MASTER_LIBRARY_ARGS_MASK 0xC0
#define MASTER_LIBRARY_GRAPHS_MASK 0x100
#define MASTER_LIBRARY_DEPENDENCY_MASK 0x200

#define MASTER_LIBRARY_STATE_SHIFT 0
#define MASTER_LIBRARY_INCREMENT_SHIFT 3
#define MASTER_LIBRARY_CHARNAME_SHIFT 4
#define MASTER_LIBRARY_ARGS_SHIFT 6
#define MASTER_LIBRARY_GRAPHS_SHIFT 8
#define MASTER_LIBRARY_DEPENDENCY_SHIFT 9

/* #!! States !!# */
#define MASTER_LIBRARY_UNAVAILABLE (0 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_INDEV (1 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_TESTING (2 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_AVAILABLE (3 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_COMPLETED (4 << MASTER_LIBRARY_STATE_SHIFT)
#define MASTER_LIBRARY_DEPRECATED (5 << MASTER_LIBRARY_STATE_SHIFT)

/* #!! Increment / Decrement !!# */
#define MASTER_LIBRARY_INCREMENTHATE (1 << MASTER_LIBRARY_INCREMENT_MASK)
#define MASTER_LIBRARY_INCREMENT (0 << MASTER_LIBRARY_INCREMENT_MASK)

/* #!! Character Name !!# */
#define MASTER_LIBRARY_FiCViN (2 << MASTER_LIBRARY_CHARNAME_SHIFT)
#define MASTER_LIBRARY_OCViNHATE (1 << MASTER_LIBRARY_CHARNAME_SHIFT)
#define MASTER_LIBRARY_OCViN (0 << MASTER_LIBRARY_CHARNAME_SHIFT)

/* #!! Arguments !!# */
#define MASTER_LIBRARY_MASTERARGS (2 << MASTER_LIBRARY_ARGS_SHIFT)
#define MASTER_LIBRARY_KAIRARGS (1 << MASTER_LIBRARY_ARGS_SHIFT)
#define MASTER_LIBRARY_STDARGS (0 << MASTER_LIBRARY_ARGS_SHIFT)
#define MASTER_LIBRARY_NO_FUNCTIONS (1 << MASTER_LIBRARY_ARGS_SHIFT)

/* #!! Graphs !!# */
#define MASTER_LIBRARY_GRAPHSHATE (1 << MASTER_LIBRARY_GRAPHS_SHIFT)
#define MASTER_LIBRARY_TRIODUOGRAPHS (0 << MASTER_LIBRARY_GRAPHS_SHIFT)

/* #!! Dependency !!# */
#define MASTER_LIBRARY_FREESTANDING (1 << MASTER_LIBRARY_DEPENDENCY_SHIFT)
#define MASTER_LIBRARY_LIBC (0 << MASTER_LIBRARY_DEPENDENCY_SHIFT)

#define MASTER_LIBRARY_RANK( libval ) \
	((((libval) & MASTER_LIBRARY_STATE_MASK) >> MASTER_LIBRARY_STATE_SHIFT) + \
	(((libval) & MASTER_LIBRARY_INCREMENT_MASK) >> MASTER_LIBRARY_INCREMENT_SHIFT) + \
	(((libval) & MASTER_LIBRARY_CHARNAME_MASK) >> MASTER_LIBRARY_CHARNAME_SHIFT) + \
	(((libval) & MASTER_LIBRARY_ARGS_MASK) >> MASTER_LIBRARY_ARGS_SHIFT) + \
	(((libval) & MASTER_LIBRARY_GRAPHS_MASK) >> MASTER_LIBRARY_GRAPHS_SHIFT) + \
	(((libval) & MASTER_LIBRARY_DEPENDENCY_MASK) >> MASTER_LIBRARY_DEPENDENCY_SHIFT))

/* #! MASTER Function Markers !# */

#define MASTER_MARKER_COMPRESSION
#define MASTER_MARKER_CRYPTOGRAPHY
#define MASTER_MARKER_MATH
#define MASTER_MARKER_PARSER
#define MASTER_MARKER_SORTER
#define MASTER_MARKER_SOLVER

#define MASTER_MARKER_CONSTANT_TIME
#define MASTER_MARKER_DOUBTFUL_CT
#define MASTER_MARKER_NO_CT

#define MASTER_MARKER_ONESHOT
#define MASTER_MARKER_FSM
#define MASTER_MARKER_CREATE
#define MASTER_MARKER_INIT
#define MASTER_MARKER_FLUSH
#define MASTER_MARKER_END
#define MASTER_MARKER_FREE
#define MASTER_MARKER_EXTRA_INFO

#define MASTER_MARKER_GENERATOR
#define MASTER_MARKER_GENERABLE( funcname )

#define MASTER_MARKER_ONLY_FOR( comment )

#define MASTER_MARKER_NOT_DOCUMENTED
#define MASTER_MARKER_DOCUMENTED( docpath )
#define MASTER_MARKER_NIH( docpath )

/* #! Next macros i will use only when at least someone asked !# */
#define MASTER_MARKER_WIKIPEDIA_SOURCE( wikipath )

#define MASTER_MARKER_AGENT
#define MASTER_MARKER_DISPATCHER
#define MASTER_MARKER_EMPLOYEE
#define MASTER_MARKER_PSYHOPATH
#define MASTER_MARKER_PATENTED
#define MASTER_MARKER_COPY( copy )
#define MASTER_MARKER_DEEPREADER
#define MASTER_MARKER_DEEPWRITER
#define MASTER_MARKER_ULP( value )
#define MASTER_MARKER_NAIVE
#define MASTER_MARKER_THREADHATE
#define MASTER_MARKER_FOREIGNER

MASTER_END_DECLARATIONS

#ifdef MASTER_LAST_LINE_LIBRARY_NUMBERS
	const UI4 MASTER_zzz_CODE_STYLE_H_LLINE = MASTER_LINE + 6;
#endif /* #! MASTER_LAST_LINE_LIBRARY_NUMBERS !# */

#ifdef __COCCINELLE__
#	if MASTER_PREFER_C89_SUPPORTED
 #		error "Hey, no cocaine here!"
#	else
		MASTER_ERRORRISE "Hey, no cocaine here!"
#	endif /* #! C89+ !# */
#endif /* #! cocine... conine... conice... keccak... cocaine !# */

#endif /* #! MASTER_zzz_CODE_STYLE_H !# */

/* #! be master~ !# */
