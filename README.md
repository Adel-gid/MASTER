# MASTER Library
This library was created with the goal of replicating most of the algorithms and collecting them in simple C89 style compatible files.

Current available algorithms:
* Bit useful functions and structures, good for FSM ("./source/bitlib.h");
* Text & symbol distances ("./source/distance.h");
* Some hash-functions (MD2, MD4, MD5, SHA1, RIPEMD128/160 (/256/320 soon)) ("./source/hashlib.h");
* Some checksum-functions (Adler32, unoptimized) ("./source/checksum.h");
* Some random generate algorithms (soon) ("./source/randomlib.h");
* Enumerating tables for some encodings (cp437) ("./source/charmaplib.h");

Also available:
* Listing some useful macros & main header file ("./source/master_enum.h");
* File for architecture detect and define his properties ("./source/architecture_detect.h");
* File for detecting available SIMD instructions ("./source/simd_detect.h");
* File that just includes all files in this library ("./source/includeall.h").

/* #! be master~ !# */
