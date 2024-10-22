#include "transaction.h"

#define IN_HASH (((ti_t *)in)->tx_out_hash)
#define IN_BLOCK (((ti_t *)in)->block_hash)
#define IN_ID (((ti_t *)in)->tx_id)
#define TX_ID (((tc_t *)context)->tx->id)
#define LUNSPENT (((tc_t *)context)->all_unspent)
#define IN_SIG (((ti_t *)in)->sig)
#define MATCH ((uto_t *)match)

int check_hash_match(llist_node_t unspent, void *hash);
int valid_ins(llist_node_t in, unsigned int iter, void *unspent);
int get_out_amount(llist_node_t out, unsigned int iter, void *context);

/**
 * transaction_is_valid - Checks if a transaction is valid
 * @transaction: Transaction to check
 * @all_unspent: list of unspent transactions
 * Return: 1 if valid, 0 if not
 */
int transaction_is_valid(
	transaction_t const *transaction, llist_t *all_unspent)
{
	uint8_t v_hash[SHA256_DIGEST_LENGTH];
	tc_t *context;

	if (!transaction || !all_unspent)
		return (0);
	context = calloc(1, sizeof(tc_t));
	context->tx = (void *)transaction, context->all_unspent = all_unspent;

	transaction_hash(transaction, v_hash);
	if (memcmp(v_hash, transaction->id, SHA256_DIGEST_LENGTH))
		return (0);

	if (llist_for_each(transaction->inputs, valid_ins, context))
		return (0);

	llist_for_each(transaction->outputs, get_out_amount, context);
	if (context->balance != context->needed)
		return (0);

	return (1);
}

/**
 * valid_ins - function for checking tx inputs sig and unspent out
 * @in: input to check
 * @iter: index for list
 * @context: struct holding tx and unspent list
 * Return: 0 on match, 1 on fail
 */
int valid_ins(llist_node_t in, unsigned int iter, void *context)
{
	(void)iter;
	llist_node_t *match;
	EC_KEY *key;

	if (!in)
		return (1);
	match = llist_find_node(LUNSPENT, check_hash_match, in);
	if (!match)
		return (1);
	key = ec_from_pub(MATCH->out.pub);
	if (!key)
		return (1);
	if (!ec_verify(key, TX_ID, SHA256_DIGEST_LENGTH, &IN_SIG))
		return (1);
	((tc_t *)context)->balance += ((uto_t *)match)->out.amount;
	return (0);
}

/**
 * check_hash_match - checks the unspent nodes for a matching hash
 * @unspent: unspent tx_out node
 * @in: input tx
 * Return: 1 on match, else 0
 */
int check_hash_match(llist_node_t unspent, void *in)
{
	if (!memcmp(UNSPENT->out.hash, IN_HASH, SHA256_DIGEST_LENGTH) &&
		!memcmp(UNSPENT->block_hash, IN_BLOCK, SHA256_DIGEST_LENGTH) &&
		!memcmp(UNSPENT->tx_id, IN_ID, SHA256_DIGEST_LENGTH))
		return (1);
	return (0);
}

/**
 * get_out_amount - calculates output amounts
 * @out: input to check
 * @iter: index for list
 * @context: struct holding tx and unspent list
 * Return: 0 on match, 1 on fail
 */
int get_out_amount(llist_node_t out, unsigned int iter, void *context)
{
	(void)iter;

	if (!out)
		return (1);

	((tc_t *)context)->needed += ((to_t *)out)->amount;
	return (0);
}
