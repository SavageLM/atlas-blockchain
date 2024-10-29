CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -Wno-deprecated-declarations -g -I.
LLIBS = -lhblk_crypto -lllist -lssl -lcrypto

libhblk_blockchain.a:
	$(CC) -c $(CFLAGS) *.c; ar -rc libhblk_blockchain.a *.o