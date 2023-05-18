#include "lists.h"

/**
 * Print_dlistint - Prints all elements of a dlistint_t list.
 *
 * @h: Head of the list
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int print;

	print = 0;

	if (h == NULL)
		return (print);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		print++;
		h = h->next;
	}

	return (print);
}
