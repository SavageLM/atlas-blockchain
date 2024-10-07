#include "blockchain.h"

/**
 * blockchain_difficulty - calculates difficulty to give next block
 * @blockchain: Blockchain to use
 * Return:Block Difficulty of next block
 */
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
	block_t *block, *adj_block;
	/* uint32_t exp_time = 0;
	uint64_t act_time = 0; */
	int idx = 0;

	if (!blockchain)
		return (0);
	block = llist_get_tail(blockchain->chain);
	if ((block->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL == 0) &&
		block->info.index != 0)
	{
		idx = (llist_size(blockchain->chain) - DIFFICULTY_ADJUSTMENT_INTERVAL);
		adj_block = llist_get_node_at(blockchain->chain, idx);
		if (ACTUAL(block, adj_block) > 2 * EXPECTED(block,adj_block))
			return (block->info.difficulty + DIFFICULTY_ADJUSTMENT_INTERVAL);
		else if (ACTUAL(block, adj_block) < EXPECTED(block,adj_block) >> 1)
			return (block->info.difficulty - DIFFICULTY_ADJUSTMENT_INTERVAL);
		else
			return (block->info.difficulty);
	}
	else
		return (block->info.difficulty);
}
