##**Project**'Blockchain - Data structures'

## Introduction
> This README is for the Blockchain - Data structures project at Atlas.

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
|blockchain.h| (v0.1/v0.2/v0.3)Header file for Programs|
|block_create.c| (v0.1/v0.2/v0.3)Function for creating a new block|
|block_destroy.c| (v0.1/v0.2/v0.3)Function for destroying a block|
|block_hash.c| (v0.1/v0.2/v0.3)Function for hashing a block|
|block_is_valid.c| (v0.1/v0.2/v0.3)Function for validating a block|
|blockchain_create.c| (v0.1/v0.2/v0.3)Function for creating a new blockchain|
|blockchain_deserialize.c| (v0.1/v0.2/v0.3)Function for deserializing a blockchain from a file|
|blockchain_serialize.c| (v0.1/v0.2/v0.3)Function for serializing a blockchain to a file|
|hash_matches_difficulty.c| (v0.2/v0.3)Function for checking if hash matches difficulty of a block|
|block_mine.c| (v0.2/v0.3)Function for mining and adding a block to the chain|
|blockchain_difficulty.c| (v0.2/v0.3)Function for assigning difficulty of next block|
|tx_out_create.c| (transaction)Function for creating a transaction out structure|
|unspent_tx_out_create.c| Function for creating an unspent data structure|
|tx_in_create.c| (transaction)Function for creating a transaction input data structure|
|transaction_hash.c| (transaction)Function for calculating the id of a transaction|
|tx_in_sign.c| (transaction)Function for signing a transaction|
|transaction_create.c| (transaction)Function for creating a transaction|
|transaction_is_valid.c| (transaction)Function for checking if a transaction is valid|
|coinbase_create.c| (transaction)Function for creating a coinbase transaction|
|coinbase_is_valid.c| (transaction)Function  for checking if a coinbase transaction is valid|
|transaction_destroy.c| (transaction)Function for removing a transaction|
|update_unspent.c| (transaction)Function for updating all unspent transaction outputs|
|test| Directory containing test files for functions|
|provided| Directory containing provided for testing|

#### Authors
Logan Savage