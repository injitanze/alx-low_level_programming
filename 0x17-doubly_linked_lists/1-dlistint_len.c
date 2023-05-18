#include "lists.h"

/**
 * dlistint_len - Returns number of elements in a double linked list
 *
 * @h: Head of list
 * Return: The number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int rturn;

	rturn = 0;

	if (h == NULL)
		return (rturn);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		rturn++;
		h = h->next;
	}

	return (rturn);
}
