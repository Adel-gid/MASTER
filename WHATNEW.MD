What added and changed on 11.01.2026 ?
 ! API change :
 ! * MASTER_SMEAR[1 / 2 / 4 / 8] -> MASTER_Bit_Smear[1 / 2 / 4 / 8] ;
 ! * MASTER_BITLEN[1 / 2 / 4 / 8] -> MASTER_Bit_Bitlen[1 / 2 / 4 / 8] ;
 ! * MASTER_POW2FLOOR[1 / 2 / 4 / 8] -> MASTER_BIT_POW2FLOOR[1 / 2 / 4 / 8] ;
 ! * MASTER_POW2CEIL[1 / 2 / 4 / 8] -> MASTER_BIT_POW2CEIL[1 / 2 / 4 / 8] ;
 ! * MASTER_POW2ROUND[1 / 2 / 4 / 8] -> MASTER_BIT_POW2ROUND[1 / 2 / 4 / 8] ;
 ! * MASTER_POW2MATHROUND[1 / 2 / 4 / 8] -> MASTER_BIT_POW2MATHROUND[1 / 2 / 4 / 8] ;
 ! * MASTER_LOG2FLOOR[1 / 2 / 4 / 8] -> MASTER_BIT_LOG2FLOOR[1 / 2 / 4 / 8] ;
 ! * MASTER_LOG2CEIL[1 / 2 / 4 / 8] -> MASTER_BIT_LOG2CEIL[1 / 2 / 4 / 8] ;
 ! * MASTER_LOG2ROUND[1 / 2 / 4 / 8] -> MASTER_BIT_LOG2ROUND[1 / 2 / 4 / 8] ;
 ! * MASTER_LOG2MATHROUND[1 / 2 / 4 / 8] -> MASTER_BIT_LOG2MATHROUND[1 / 2 / 4 / 8] ;
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
 ! * MASTER_[RLL / RLR][8 / 16 / 32 / 64] -> MASTER_[RLL / RLR][1 / 2 / 4 / 8] ;
 ! * MASTER_BSWAP[16 / 32 / 64] -> MASTER_BSWAP[2 / 4 / 8] ;
 ! * MASTER_[L / B / NUXI / PDP]2[LE / BE / NUXI / PDPE][16 / 32 / 64] -> MASTER_[L / B / NUXI / PDP]2[LE / BE / NUXI / PDPE][2 / 4 / 8] ;
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