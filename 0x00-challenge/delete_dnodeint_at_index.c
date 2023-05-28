#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	dlistint_t *tmp;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	current = *head;
	i = 0;

	while (i < index)
	{
		if (current == NULL)
			return (-1);

		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;

		if (*head != NULL)
			(*head)->prev = NULL;

		free(tmp);
	}
	else
	{
		current->prev->next = current->next;

		if (current->next != NULL)
			current->next->prev = current->prev;

		free(current);
	}

	return (1);
}
