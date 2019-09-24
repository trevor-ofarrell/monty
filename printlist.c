#include "monty.h"
/**
 * print_dlistint - print all elements of doubly linked list
 * @h: head node
 *
 * Return: Always EXIT_SUCCESS.
 */
size_t print_dlistint(stack_t **h)
{
	int i = 0;

	while (h != NULL)
	{
		printf("%i\n", (*h)->n);
		(*h) = (*h)->next;
		i++;
	}
	return (i);
}
