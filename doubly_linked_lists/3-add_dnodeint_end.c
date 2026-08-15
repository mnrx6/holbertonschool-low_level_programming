#include <stdlib.h>
#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: pointer to the head of the list
 * @n: integer to add
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	new->prev = temp;
	temp->next = new;

	return (new);
}
