#include "blockchain.h"

/**
 * block_destroy - Destroys provided block
 * @block: block to destroy
 */
void block_destroy(block_t *block)
{
	if (!block)
		return;
	llist_destroy(block->transactions, 1, NULL);
	free(block);
}
