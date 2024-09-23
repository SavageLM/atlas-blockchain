#include "blockchain.h"

/**
 * blockchain_destroy - destroys a blockchain
 * @blockchain: chain to destroy
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;
	llist_destroy(blockchain->chain, 1, NULL);
	free(blockchain);
}
