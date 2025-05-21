#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list
 * @head: Double pointer to head of the list
 * @index: Index of node to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	/* Traverse to the node at the index */
	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	if (current == NULL)
		return (-1);

	if (current->prev != NULL)
		current->prev->next = current->next;
	else
		*head = current->next;  /* Deleting the head */

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
