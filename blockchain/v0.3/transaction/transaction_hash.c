#include "transaction.h"

int hash_in(llist_node_t input, unsigned int iter, void *buff);
int hash_out(llist_node_t output, unsigned int iter, void *buff);


/**
 * transaction_hash - Calculates the hash of a transaction
 * @transaction: transaction to hash
 * @hash_buf: buffer to hold the hash
 * Return: pointer to hash_buff or NULL
 */
uint8_t *transaction_hash(
	transaction_t const *transaction, uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	int ins = 0, outs = 0;
	uint8_t *buff = NULL;

	if (!transaction || !hash_buf)
		return (NULL);
	ins = llist_size(transaction->inputs);
	outs = llist_size(transaction->outputs);
	buff = calloc(1, ((32 * 3 * ins) + (32 * outs)));
	llist_for_each(transaction->inputs, hash_in, buff);
	llist_for_each(transaction->outputs, hash_out, &buff[32 * 3 * ins]);
	SHA256(buff, (ins + outs), hash_buf);
	return (hash_buf);
}

/**
 * hash_in - reads inputs into a buffer for hashing
 * @input: node in list
 * @iter: Iteration index in list
 * @buff: Buffer to read into
 * Return: returns 0 on success, 1 on fail
 */
int hash_in(llist_node_t input, unsigned int iter, void *buff)
{
	unsigned int pos = iter * (32 * 3);

	if (!input)
		return (1);
	memcpy(&((uint8_t *)buff)[pos], input, 96);
	return (0);
}

/**
 * hash_out - reads inputs into a buffer for hashing
 * @output: node in list
 * @iter: Iteration index in list
 * @buff: Buffer to read into
 * Return: returns 0 on success, 1 on fail
 */
int hash_out(llist_node_t output, unsigned int iter, void *buff)
{
	unsigned int pos = iter * 32;

	if (!output)
		return (1);
	memcpy(&((uint8_t *)buff)[pos], (uint8_t *)output + 69, 32);
	return (0);
}
