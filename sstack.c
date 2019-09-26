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
