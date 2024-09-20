##**Project**'Blockchain - Crypto'

## Introduction
> This README is for the Blockchain - Crypto project at Atlas.

### Requirements
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS
- OpenSSL Library needs to be installed
- Your C programs and functions will be compiled with gcc 9.* using the flags -Wall -Werror -Wextra, -pedantic -Wno-deprecated-declarations and the linker flags -lssl and -lcrypto
- A README.md file, at the root of the folder of the project, is mandatory
- All your header files should be include guarded
- Your code should use the Betty style
- Allowed to use STD Library
- Allowed to use static functions and variables

### Repo Files
| **File** | *__Description__* |
|----------|----------------:|
|Makefile| Makefile for building and compiling libraries and functions|
|hblk_crypto.h| Header file for Programs|
|sha256.c| Function for hashing a series of bytes|
|ec_create.c| Function for creating a new EC_KEY pair|
|ec_to_pub.c| Function for extracting a public key from an EC_KEY opaque structure|
|ec_from_pub.c| Function for creating an EC_KEY structure from a public key|
|ec_save.c| Function for saving an EC_KEY pair to disk|
|ec_load.c| Function for loading an EC_KEY pair from disk|
|ec_sign.c| Function for signing a set of bytes, using an EC_KEY private key|
|ec_verify.c| Function for verifing the signature of a set of bytes, using an EC_KEY public key|
|test| Directory containing test files for functions|
|provided| Directory containing provided functions for testing|

#### Authors
Logan Savage