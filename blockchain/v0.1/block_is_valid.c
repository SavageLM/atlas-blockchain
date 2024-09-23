#include "blockchain.h"

int is_genesis(block_t const *block);

/**
 * block_is_valid - function to validate a block
 * @block: block to validate
 * @prev_block: block before block to validate
 * Return: 1 on Success, 0 on fail
 */
int block_is_valid(block_t const *block, block_t const *prev_block)
{
	uint8_t prev_hash[SHA256_DIGEST_LENGTH] = {0};
	uint8_t current_hash[SHA256_DIGEST_LENGTH] = {0};

	if (!block)
		return (0);

	if (!prev_block && block->info.index != 0)
		return (0);

	if (block->info.index == 0)
	{
		if (is_genesis(block))
			return (1);
		else
			return (0);
	}

	if (block->info.index != prev_block->info.index + 1)
		return (0);

	block_hash(prev_block, prev_hash);
	if (memcmp(prev_hash, prev_block->hash, 32))
		return (0);

	if (memcmp(prev_block->hash, block->info.prev_hash, 32))
		return (0);

	block_hash(block, current_hash);
	if (memcmp(current_hash, block->hash, 32))
		return (0);

	if (block->data.len > BLOCKCHAIN_DATA_MAX)
		return (0);
	return (1);
}

/**
 * is_genesis - checks if a block is a genesis block
 * @block: block to check
 * Return: 1 on success, 0 on fail
 */
int is_genesis(block_t const *block)
{
	block_t genesis = {
		{0, 0, 1537578000, 0, {0}},
		{"Holberton School", 16},
		HOLBERTON_HASH};

	return (memcmp(&genesis, block, 108));
}
