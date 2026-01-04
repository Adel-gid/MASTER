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