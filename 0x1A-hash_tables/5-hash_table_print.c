#include "hash_tables.h"
#include <stdio.h>
/**
 * hash_table_print - prints the entire table
 * @ht: pointer to hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned int i = 0;
	int check = 0;
	hash_node_t *tmp = NULL;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	while (i < ht->size)
	{
		if (ht->array[i] != NULL)
		{
			tmp = ht->array[i];
			while (tmp != NULL)
			{
				check++;
				if (check % 2 != 0)
				{
					if (check != 1)
						printf(", ");
					printf("'%s': '%s'", tmp->key, tmp->value);
				}
				else
				{
					printf(", ");
					printf("'%s': '%s'", tmp->key, tmp->value);
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	printf("}\n");
}
