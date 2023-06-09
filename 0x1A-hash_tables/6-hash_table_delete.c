#include "hash_tables.h"

/**
 * hash_table_delete - free hash table and all nodes
 * @ht: pointer to hash table
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *brook, *brook_free;
	unsigned long int x = 0;

	if (!ht)
		return;

	for (x = 0; x < ht->size; x++)
	{
		brook = ht->array[x];
		while (brook)
		{
			brook_free = brook;
			brook = brook->next;
			if (brook_free->key)
				free(brook_free->key);
			if (brook_free->value)
				free(brook_free->value);
			free(brook_free);
		}
	}
	free(ht->array);
	free(ht);
}
