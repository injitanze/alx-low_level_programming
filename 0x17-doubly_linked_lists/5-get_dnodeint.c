#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 *
 * @head: Head of list.
 * @index: Index of the nth node.
 * Return: nth node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int y;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	y = 0;

	while (head != NULL)
	{
		if (y == index)
			break;
		head = head->next;
		y++;
	}

	return (head);
}
