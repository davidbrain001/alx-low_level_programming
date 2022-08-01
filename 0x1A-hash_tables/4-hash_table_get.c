#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_get - uses the key to return a value
 * @ht: pointer to the hash table
 * @key: the key whose value is to be returned
 * Return: value(on success) and NULL(on failure)
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int index = key_index((const unsigned char *)key, ht->size);
	char *k = strdup(key);
	hash_node_t *tmp;

	if (ht == NULL || key == NULL || *k == '\0')
		return (NULL);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strncmp(tmp->key, k, strlen(k)) == 0)
		{
			free(k);
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
