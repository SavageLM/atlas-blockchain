#include "blockchain.h"

#define BDL block->data.len

/**
 * block_hash - hashes a block using sha256
 * @block: block to hash
 * @hash_buf: buffer to store computed hash
 * Return: hash buffer or NULL
 */
uint8_t *block_hash(block_t const *block,
					uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	size_t num_tx = 0, buff_len = 0;
	uint8_t *buffer;

	if (!block || !hash_buf)
		return (NULL);

	if (block->transactions)
		num_tx = llist_size(block->transactions);

	buff_len = sizeof(block->info) + BDL + (num_tx *SHA256_DIGEST_LENGTH);
	buffer = calloc(0, buff_len);

	memcpy(buffer, block, sizeof(block->info) + BDL);
	llist_for_each(block->transactions, tx_id_cpy, buffer);
	SHA256(buffer, buff_len, hash_buf);

	return (hash_buf);
}

/**
 * tx_id_cpy - function to copy tx_id into a buffer
 * @tx: Transaction to store to buffer
 * @iter: index of transaction
 * @buffer: Buffer to copy into
 * Return: 1 on Fail, otherwise 0
 */
int tx_id_cpy(llist_node_t tx, int iter, void *buffer)
{
	memcpy(
		(uint8_t *)buffer + iter * SHA224_DIGEST_LENGTH,
		((transaction_t *)tx)->id, SHA224_DIGEST_LENGTH);
	return (0);
}
