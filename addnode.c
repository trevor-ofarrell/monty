#include "monty.h"
/**
 * add_dnodeint - add node to start of doubly linked list.
 * @head: head node
 * @n: data
 *
 * Return: Always EXIT_SUCCESS.
 */
stack_t *addnode(stack_t **head, const int n)
{
	stack_t *newnode = (stack_t *)malloc(sizeof(stack_t));

	if (head == NULL || !newnode)
		return (NULL);
	newnode->n = n;
	newnode->next = (*head);
	newnode->prev = NULL;
	if (*head)
		(*head)->prev = newnode;
	(*head) = newnode;
	return (newnode);
}
