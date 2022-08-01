#include "hash_tables.h"
#include <string.h>
#include <stdio.h>
/**
 * hash_table_set - adds/updates the value of a key
 * @ht: pointer to the hash table
 * @key: the key in the form of a string
 * @value: the value to be assigned to the key in the form of a string
 * Return: 1(on sucess) and 0(on failure)
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	char *v = (char *)strdup(value);
	char *k = (char *)strdup(key);
	unsigned long int index = key_index((unsigned const char *)k, ht->size);
	hash_node_t *new_node = (hash_node_t *) malloc(sizeof(hash_node_t));
	hash_node_t *tmp = NULL;

	if (new_node == NULL || ht == NULL ||
			key == NULL || k[0] == '\0')
	{
		free(new_node);
		free(k);
		free(v);
		return (0);
	}
	if (ht->array[index] == NULL)
	{
		ht->array[index] = new_node;
		ht->array[index]->key = (char *)k;
		ht->array[index]->value = (char *)v;
		ht->array[index]->next = NULL;
		return (1);
	}
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, k) == 0)
		{
			free(tmp->value);
			tmp->value = v;
			free(k);
			free(new_node);
			return (1);
		}
		tmp = tmp->next;
	}
	col_resolute(ht, k, v, new_node);
	return (1);
}
/**
 * col_resolute - resolves collisions using chain handling
 * @ht: pointer to the hash table
 * @key: the key in the form of a string
 * @value: the value to be assigned to the key in the form of a string
 * @new_node: pointer to a new node
 * Return: nothing(void)
 */
void col_resolute(hash_table_t *ht,
		const char *key, const char *value, hash_node_t *new_node)
{
	hash_node_t *tmp;
	unsigned int index = key_index((unsigned const char *)key, ht->size);

	tmp = ht->array[index];
	tmp->next = NULL;
	ht->array[index] = new_node;
	ht->array[index]->key = (char *)key;
	ht->array[index]->value = (char *)value;
	ht->array[index]->next = tmp;
}
