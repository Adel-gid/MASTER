# MASTER Library
This library was created with the goal of replicating most of the algorithms and collecting them in simple C89 style compatible files.

Current available algorithms:
* File with some useful abstract structures ("./source/abstract.h") ;
* File with some interesting and useful algorithms (Dancing Links) ("./source/algolib.h") ;
* Bit useful functions ("./source/bitlib.h") ;
* Enumerating tables for some encodings (cp437/737) ("./source/charmaplib.h") ;
* Some checksum-functions (Adler32, unoptimized) ("./source/checksum.h") ;
* Text & symbol distances ("./source/distances.h") ;
* Some hash-functions (MD2, MD4, MD5, SHA1, RIPEMD128/160/256/320) ("./source/hashlib.h") ;
* Some random generate algorithms (xorshift32/64/128) ("./source/randomlib.h") ;

Also available:
* Listing some useful macros & main header file ("./source/master_enum.h") ;
* File for architecture detect and define his properties ("./source/architecture_detect.h") ;
* File for operating system detect and define his properties ("./source/operating_system_detect.h") ;
* File for compiler detect and define his properties ("./source/compiler_detect.h") ;
* File for detecting available SIMD instructions on compile time ("./source/simd_detect.h") ;
* File that just includes all files in this library ("./source/includeall.h").

/* #! be master~ !# */
