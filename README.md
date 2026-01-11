# MASTER Library
This library was created with the goal of replicating most of the algorithms and collecting them in simple C89 style compatible files.

Current available algorithms:
 * File with some useful abstract structures ([abstract.h](./source/abstract.h)) ;
 * File with some interesting and useful algorithms (Dancing Links) ([algolib.h](./source/algolib.h)) ;
 * Bit useful functions ([bitlib.h](./source/bitlib.h)) ;
 * Enumerating tables for some encodings (cp437/737) ([charmaplib.h](./source/charmaplib.h)) ;
 * Some checksum-functions (Adler32, unoptimized) ([checksum.h](./source/checksum.h)) ;
 * Text & symbol distances ([distances.h](./source/distances.h)) ;
 * Some hash-functions (MD2, MD4, MD5, SHA1, RIPEMD128/160/256/320) ([hashlib,h](./source/hashlib.h)) ;
 * Some random generate algorithms (xorshift32/64/128) ([randomlib.h](./source/randomlib.h)) ;

Also available:
 * Listing some useful macros & main header file ([master_enum.h](,/source/master_enum.h)) ;
 * File for architecture detect and define his properties ([architecture_detect.h](./source/architecture_detect.h)) ;
 * File for operating system detect and define his properties ([operating_system_detect.h](./source/operating_system_detect.h)) ;
 * File for compiler detect and define his properties ([compiler_detect.h](./source/compiler_detect.h)) ;
 * File for detecting available SIMD instructions on compile time ([simd_detect.h](./source/simd_detect.h)) ;
 * File that just includes all files in this library ([includeall.h](./source/includeall.h)).

/* #! be master~ !# */
