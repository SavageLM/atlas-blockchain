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
|Dockerfile| File for spinning up a docker container with all needed libraries|
|crypto/Makefile| Makefile for building and compiling libraries and functions|
|cyrpto/hblk_crypto.h| Header file for Programs|
|crypto/sha256.c| Function for hashing a series of bytes|
|crypto/ec_create.c| Function for creating a new EC_KEY pair|
|crypto/ec_to_pub.c| Function for extracting a public key from an EC_KEY opaque structure|
|crypto/ec_from_pub.c| Function for creating an EC_KEY structure from a public key|
|crypto/ec_save.c| Function for saving an EC_KEY pair to disk|
|crypto/ec_load.c| Function for loading an EC_KEY pair from disk|
|crypto/ec_sign.c| Function for signing a set of bytes, using an EC_KEY private key|
|crypto/ec_verify.c| Function for verifing the signature of a set of bytes, using an EC_KEY public key|

#### Authors
Logan Savage