#ifndef _HBLK_CRYPTO_H_
#define _HBLK_CRYPTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include <openssl/ssl.h>
#include <openssl/sha.h>
#include <openssl/obj_mac.h>
#include <openssl/ec.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/ecdsa.h>
#include <openssl/bio.h>
#include <openssl/ecdh.h>

/* MACROS */

/* Structs */

/* Prototypes */
uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);
int ec_save(EC_KEY *key, char const *folder);
EC_KEY *ec_load(char const *folder);
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t *sig);
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t const *sig);

#endif
