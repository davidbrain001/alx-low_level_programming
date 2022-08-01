#include "hash_tables.h"
/**
 * key_index - returns the index for a particular key
 * @size: size of the hash table
 * @key: a key in the form of a string whose index is to
 * be determined then returned
 * Return: index for the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
  return (hash_djb2(key) % size);
}
