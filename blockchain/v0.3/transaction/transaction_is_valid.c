#include "transaction.h"

#define OUT_HASH (((ti_t *)in)->tx_out_hash)
#define TX_ID (((tc_t *)context)->tx->id)
#define LUNSPENT (((tc_t *)context)->all_unspent)
#define IN_SIG (((ti_t *)in)->sig)
#define MATCH ((uto_t *)match)

int check_hash_match(llist_node_t unspent, void *hash);
int valid_ins(llist_node_t in, unsigned int iter, void *unspent);

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
	int in = 0, out = 0;
	tc_t *context;

	context = calloc(1, sizeof(tc_t));
	context->tx = (void *)transaction, context->all_unspent = all_unspent;

	transaction_hash(transaction, v_hash);
	if (memcmp(v_hash, transaction->id, SHA256_DIGEST_LENGTH))
		return (0);

	in = llist_size(transaction->inputs);
	out = llist_size(transaction->outputs);
	if (in != out)
		return (0);

	if (llist_for_each(transaction->inputs, valid_ins, context))
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
	match = llist_find_node(LUNSPENT, check_hash_match, OUT_HASH);
	if (!match)
		return (1);
	key = ec_from_pub(MATCH->out.pub);
	if (!key)
		return (1);
	if (!ec_verify(key, TX_ID, SHA256_DIGEST_LENGTH, &IN_SIG))
		return (1);
	return (0);
}

/**
 * check_hash_match - checks the unspent nodes for a matching hash
 * @unspent: unspent tx_out node
 * @hash: hash to compare
 * Return: 1 on match, else 0
 */
int check_hash_match(llist_node_t unspent, void *hash)
{
	if (!unspent)
		return (0);
	if (!memcmp(UNSPENT->out.hash, hash, SHA256_DIGEST_LENGTH))
		return (1);
	return (0);
}
