What added and changed on 01.03.2026 ?
 !!! CHANGE "WHATNEW.MD" - MINOR UPDATE (SEE **<{1}>**) ;
 ! API change :
 ! Now using "MASTER_zzz" namespace for all private macroses and function instead of "MASTER_zRIVATE" ;
 ! Now using "MASTER_OS" namespace for all macroses for "operating_system_detect.h" instead of "MASTER_OPERATING_SYSTEM" ;
 ! Now using "MASTER_ARCH" namespace for all macroses for "architecture_detect.h" instead of "MASTER_ARCHITECTURE" ;
 ! Now using "MASTER_LAST_LINE_LIBRARY_NUMBERS" for using library line count instead of "MASTER_ADD_LAST_LINE_LIBRARY_NUMBERS" ;
 ! Now macroses MASTER_[[L / B / NUXI / PDPE]2[LE / BE / NUXI / PDPE]![2 / 4 / 8] / [TO / FROM][LE / BE / NUXI / PDPE]![2 / 4 / 8]] {96} is marked as unsafe - "cast to a larger pointer type and dereference it" now is a fatal error ;
 ! Now using "MASTER_Algolib_DLX_*" namespace for all functions and types that have connection to dancing links algorithm in "algolib.h" instead of "MASTER_Algolib_DancingLinks" ;
 * added file "library.h" that enumerates all libraries possible to include and includes them ;
 * now [S/U]I[1/2/4/8] {8} types can be defined with [s/u]int[8/16/32/64]_t {8} types thankfully to "library.h" and testing, is "stdint.h" can be included ;
 * now for "gcc", "tcc" and "tc" compilers are writed their size of some types ;
 * now [S/U]I[1/2/4/8] {8} types can be defined with hardcoded size of some types thankfully to updated configurations about all supported compilers ;
 * added all libc header files (32) check to include in "library.h" ;
 * added configuration file for TCC - "compilers/tcc_config.h" => "includeall.h" updated also ;
 * fixed "library.h" in processing already defined macroses ;
 * added detection of Bi-Endian architectures in "architecture_detect.h" ;
 * added a count indicator showing how many names are expanded from each grouped expression **<{1}>**;
 * updated variable names to use camelCase instead of snake_case (1339+ modifications) ;
 * added pack and unpack endian macroses in "master_enum.h" that safer than previous TO and FROM macroses ;
 * added support to include C++ libraries in C++ compilers and some C libraries in C++ compilers in "library.h" - total 150 libraries can be included in C++ compilers ;
 * added the ability to specify your own endian using the MASTER_ENDIANNESS macro ;
 * added macro that contains, is warning and error preprocessor commands is available ;
 * changed the style code - now all warning and error preprocessor commands must be checked, is warning or error preprocessor command accordingly is available, and must contain in first symbol line a space " " ;
 * removed all 0x0D symbols from all files ;
 * now the preprocessor commands for concatenating instructions "<var1>##<var2>" and generating a string from the value of the variable "#<var>" are considered unsafe - "it is necessary to ensure compatibility with K&R C standards" ;
 * added check for macroses-functions in "library.h" - if macros-function found, it will be replaced by normal integer macros with True value ;
 * added POSIX, Windows and MSDOS libraries in "library.h" - total 62 POSIX, 37 Windows and 1 MSDOS ;
 * added more operating system in "operating_system_detect.h" ;
 * updated configuration files for all supported compilers ;
 * added support of GNU Autoconf ;
 * added 14 new code page tables in "charmaplib.h" ;
 * all function implementations are now described using the MASTER standard - now, when compiling in traditional mode, there will not be a single warning of the "ISO C Style" type ;
 * when compiling with gcc -Wtraditional, only one unique warning remains, related to #elif.

What added and changed on 19.01.2026 ?
 ! API change :
 ! Now using "MASTER_zRIVATE" namespace for all private macroses and function instead of "__MASTER_...__" ;
 ! __MASTER_FULL_LIBRARY_SUM_OF_LINES__ -> MASTER_FULL_LIBRARY_SUM_OF_LINES ;
 ! __MASTER_<libname>_INCLUDE_H__ -> MASTER_zRIVATE_<libname>_INCLUDE_H ;
 ! __MASTER_<libname>_INCLUDE_H_LAST_LINE__ -> MASTER_zRIVATE_<libname>_INCLUDE_H_LAST_LINE ;
 ! MASTER_<...>[LE / BE / NUXI / PDPE][16 / 32 / 64] {12} -> MASTER_<...>[LE / BE / NUXI / PDPE][2 / 4 / 8] {12} ;
 * added more compiler features available in "master_enum.h" ;
 * added logic to get compiler features for every compiler in "compiler_detect.h" ;
 * added configuration file for GCC - "compilers/gcc_config.h" ;
 * removed possible problems "empty macros in expression" ;
 * added "restrict" macroses to "hashlib.h" and "checksum.h" for more speed ;
 * strongly optimized all functions in "hashlib.h" ;
 * optimized Adler32 checksum in "checksum.h" ;
 * added CP210 encoding table to "charmaplib.h" ;
 * added some macroses to "bitlib.h" ;
 * created file "masmath.h" which contains mathematical function implementation ;
 * added include "masmath.h" to "includeall.h" ;
 * added DCT-I, DCT-II, DCT-III, DCT-IV and DHT to "masmath.h" ;
 * added some functions to "algolib.h" ;
 * added more macroses to best define android and BeOS version in "operating_system_detect.h" ;
 * added more macroses to detect operating system in "operating_system_detect.h" ;
 * updated license comment in every file ;
 * added bimap structure to "abstract.h" ;
 * added middle squares, Lehmer and LCG PRNG algorithms to "randomlib.h" ;
 * added more macroses check to check SSE2 availability in "simd_detect.h" ;
 * added MurmurHash2A algorithm to "hashlib.h" and MurmurHash1/2/3 family OneShot to "algolib.h".

What added and changed on 11.01.2026 ?
 ! API change :
 ! * MASTER_SMEAR[1 / 2 / 4 / 8] {4} -> MASTER_Bit_Smear[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_BITLEN[1 / 2 / 4 / 8] {4} -> MASTER_Bit_Bitlen[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_POW2FLOOR[1 / 2 / 4 / 8] {4} -> MASTER_BIT_POW2FLOOR[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_POW2CEIL[1 / 2 / 4 / 8] {4} -> MASTER_BIT_POW2CEIL[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_POW2ROUND[1 / 2 / 4 / 8] {4} -> MASTER_BIT_POW2ROUND[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_POW2MATHROUND[1 / 2 / 4 / 8] {4} -> MASTER_BIT_POW2MATHROUND[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_LOG2FLOOR[1 / 2 / 4 / 8] {4} -> MASTER_BIT_LOG2FLOOR[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_LOG2CEIL[1 / 2 / 4 / 8] {4} -> MASTER_BIT_LOG2CEIL[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_LOG2ROUND[1 / 2 / 4 / 8] {4} -> MASTER_BIT_LOG2ROUND[1 / 2 / 4 / 8] {4} ;
 ! * MASTER_LOG2MATHROUND[1 / 2 / 4 / 8] {4} -> MASTER_BIT_LOG2MATHROUND[1 / 2 / 4 / 8] {4} ;
 ! * All functions and macroses above moved from "master_enum.h" to "bitlib.h" ;
 * fixed compiling with using tradional compiler ;
 * added macroses to "master_enum.h", especially MASTER_EXTERN_FUNCTION ;
 * added start and end markers for declarations of C functions and variables to all files ;
 * now the links to files in README.MD point to the file and when clicked, you can go to this library file ;
 * now library compiles without warnings with -Wcast-qual, -Wmissing-declarations and -Wmissing-prototypes (gcc/clang) ;
 * added MT19937 and WELL family (512a, 521a/b, 607a/b, 800a/b, 1024a/b, 19937a/b/c, 21701a, 23209a/b, 44497a/b + constructor for custom WELL algorithms) PRNG in "randomlib.h" ;
 * added ".gitattributes" specifying the C language for .h files to avoid confusion with C++ files when analyzed with Linguist.

What added and changed on 05.01.2026 ?
 ! API change :
 ! * MASTER_[RLL / RLR][8 / 16 / 32 / 64] {8} -> MASTER_[RLL / RLR][1 / 2 / 4 / 8] {8} ;
 ! * MASTER_BSWAP[16 / 32 / 64] {3} -> MASTER_BSWAP[2 / 4 / 8] {3} ;
 ! * MASTER_[L / B / NUXI / PDP]2[LE / BE / NUXI / PDPE][16 / 32 / 64] {48} -> MASTER_[L / B / NUXI / PDP]2[LE / BE / NUXI / PDPE][2 / 4 / 8] {48} ;
 ! * Moved "bit stream" from "bitlib.h" to "abstract.h" ;
 * added new abstract structure "monotonic stack" to "abstract.h" ;
 * added new algorithms to "algolib.h" ;
 * added version clarification to the names of some architectures in "architecture_detect.h" ;
 * improved method for obtaining endian in "architecture_detect.h" ;
 * removed several duplicate macros in "architecture_detect.h" ;
 * updated standard compiler flags for variables and functions in "master_enum.h" ;
 * added new file with enumeration of operating systems and defining they properties - "operating_system_detect.h" ;
 * added "operating_system_detect.h" header file to "includeall.h" ;
 * fixed array arguments in "hashlib.h" ;
 * added ripemd256 and ripemd320 algorithm in "hashlib.h" ;
 * added CP737 charmap to "charmap.h".

What added and changed on 01.01.2026 ?
 * updated license year to 2026 ;
 * added some new macroses to "master_enum.h" ;
 * added some new functions to "bitlib.h" ;
 * added new file which stores some algorithms - "algolib.h" ;
 * added "xorshift128" algorithm to "randomlib.h" ;
 * added "check brackets" function to "algolib.h" ;
 * added algorithm "Dancing Links" to "algolib.h" ;
 * added new file which stores some abstract structures - "absract.h" ;
 * added byte stack and ring buffer to "abstract.h" ;
 * added a placeholder if MASTER_NO_STRING_DEPENDENCY is defined ;
 * the standard style for writing macroses has been updated ;
 * reduced the number of errors during traditional compilation from ~1700 to 332.

What added and changed on 25.12.2025 ?
 * added more architectures in "architecture_detect.h" ;
 * added architecture name detection in "architecture_detect.h" ;
 * added NUXI byte order macroses in "master_enum.h" ;
 * some variables in "master_enum.h" was changed to rule "5+ symbols in variable name" ;
 * added xorshift32 and xorshift64 to "randomlib.h" with 64 and 32 bits safety ;
 * renamed "README.md" to "README.MD" ;
 * added changelog named "WHATNEW.MD".
