#include "hash_tables.h"
#include <stdlib.h>
/**
 * hash_table_create - creates an array for a hash table and returns
 * the pointer pointer to its first node
 * @size: the number of elements in the array
 * Return: pointer to the first node of the array
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new = (hash_table_t *) malloc(sizeof(hash_table_t));
	unsigned int i = 0;

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->size = size;
	new->array = (hash_node_t **) malloc(size * sizeof(hash_node_t *));
	if (new->array == NULL)
	{
		free(new->array);
		return (NULL);
	}
	/* initializing each node of the hashtable to NULL */
	while (i < size)
	{
		new->array[i] = (NULL);
		i++;
	}
	return (new);
}
