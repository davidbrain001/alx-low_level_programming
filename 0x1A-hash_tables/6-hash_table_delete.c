#include "hash_tables.h"
/**
 * hash_table_delete - deletes an hash table
 * @ht: the table to be deleted
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *node = NULL;
	hash_node_t *tmp = NULL;

	if (ht == NULL)
	{
		return;
	}

	while (i < ht->size)
	{
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->value);
				free(node->key);
				free(node);
				node = tmp;
			}
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
