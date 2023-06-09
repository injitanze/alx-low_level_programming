#include "hash_tables.h"

/**
 * hash_table_print - function to print the key:value from ht
 * @ht: pointer to hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int x = 0;
	hash_node_t  *brook;
	int key_value = 0;

	if (!ht)
		return;

	printf("{");
	for (x = 0; x < ht->size; x++)
	{
		brook = ht->array[x];
		while (brook)
		{
			if (key_value)
				printf(", ");
			printf("'%s': '%s'", brook->key, brook->value);
			key_value = 1;
			brook = brook->next;
		}
	}
	printf("}\n");
}
