#include "blockchain.h"

/**
 * blockchain_deserialize - Loads a blockchain from file
 * @path: file to read from
 * Return: Pointer to chain or NULL
 */
blockchain_t *blockchain_deserialize(char const *path)
{
	FILE *fptr = NULL;
	char block_buf[1116] = {0}, header_buf[12] = {0};

	if (!path)
		return (NULL);
	fptr = fopen(path, "r");
	if (!fptr)
		return (NULL);
	fread(header_buf, 1, 7, fptr)
}
