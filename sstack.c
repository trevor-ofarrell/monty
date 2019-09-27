#include "monty.h"
/**
 * pint - prints value at TOS
 * @node: linked list
 * @lc: line count
 * Return: void
 */
void pint(stack_t **node, unsigned int lc)
{
	int data = 0;

	if (!node || !*node)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", lc);
		exit(EXIT_FAILURE);
	}
	data = (*node)->n;
	printf("%d\n", data);
}
/**
 * freestack - free the stack
 * @node: linked list
 *
 *
 * Return - void
 */
void freestack(stack_t **node)
{
	stack_t *temp = NULL;

	while (*node)
	{
		temp = *node;
		*node = (*node)->next;
		free(temp);
	}
}
