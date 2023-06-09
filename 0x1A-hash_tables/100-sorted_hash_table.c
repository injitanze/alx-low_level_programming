#include "hash_tables.h"

/**
 * sorted_list - function for insert new node in sorted
 * @ht: pointer to sorted hash table
 * @new_node: pew node to insert
 *
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *sbrook = ht->shead;

	if (sbrook == NULL)
	{
		ht->shead = ht->stail = new_node;
		new_node->snext = new_node->sprev = NULL;
		return;
	}
	do {
		if (strcmp(new_node->key, sbrook->key) < 0)
		{
			new_node->snext = sbrook;
			new_node->sprev = sbrook->sprev;

			if (!sbrook->sprev)
				ht->shead = new_node;
			else
				sbrook->sprev->snext = new_node;
			sbrook->sprev = new_node;
			return;
		}
		sbrook = sbrook->snext;
	} while (sbrook);
	new_node->sprev = ht->stail;
	new_node->snext = ht->stail->snext;
	ht->stail->snext = new_node;
	ht->stail = new_node;
}

/**
 * shash_table_create - creates a sorted hash tables
 * @size: size of the hash table
 *
 * Return: pointer to hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;

	if (size == 0)
		return (NULL);

	table = calloc(1, sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = calloc(size, sizeof(shash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	return (table);
}

/**
 * shash_table_set - function that adds an element to the sorted hash table
 * @ht: pointer to sorted hash table
 * @key: key to add the element
 * @value: value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *valuecpy, *keycpy;
	shash_node_t  *brook, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);
	valuecpy = strdup(value);
	if (!valuecpy)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	brook = ht->array[index];

	while (brook)
	{
		if (!strcmp(key, brook->key))
		{
			free(brook->value);
			brook->value = valuecpy;
			return (1);
		}
		brook = brook->next;
	}
	new_node = calloc(1, sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(valuecpy);
		return (0);
	}
	keycpy = strdup(key);
	if (!keycpy)
		return (0);
	new_node->key = keycpy;
	new_node->value = valuecpy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	sorted_list(ht, new_node);
	return (1);
}
/**
 * shash_table_get - function to retrieve value associeted with key
 * @ht: pointer to hash table
 * @key: key to retrive value
 *
 * Return: value or NULL if key does not exit.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t  *brook;

	if (!ht || !key || !*key)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	brook = ht->array[index];
	while (brook)
	{
		if (!strcmp(key, brook->key))
			return (brook->value);
		brook = brook->next;
	}
	return (NULL);
}

/**
 * shash_table_print - function to print the key:value from ht
 * @ht: pointer to hash table
 *
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *brook;
	int key-value = 0;

	if (!ht)
		return;
	brook = ht->shead;
	printf("{");
	while (brook)
	{
		if (key-value)
			printf(", ");
		printf("'%s': '%s'", brook->key, brook->value);
		key-value = 1;
		brook = brook->snext;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - function to print the key:value from ht in reverse
 * @ht: pointer to hash table
 *
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *brook;
	int key-value = 0;

	if (!ht)
		return;
	brook = ht->stail;
	printf("{");
	while (brook)
	{
		if (key-value)
			printf(", ");
		printf("'%s': '%s'", brook->key, brook->value);
		key-value = 1;
		brook = brook->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - free hash table and all nodes
 * @ht: pointer to hash table
 *
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *brook, *brook_free;
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
