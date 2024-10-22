#include "blockchain.h"

/**
 * block_destroy - Destroys provided block
 * @block: block to destroy
 */
void block_destroy(block_t *block)
{
	if (!block)
		return;
	llist_for_each(block->transactions, tx_free, NULL);
	free(block);
}

/**
 * tx_free - Frees a list of transactions
 * @tx: transaction to free
 * @iter: unused
 * @args: unused
 * Return: 1 on fail
 */
int tx_free(llist_node_t tx, unsigned int iter, void *args)
{
	(void)iter;
	(void)args;
	transaction_destroy((transaction_t *)tx);
}
