#include "monty.h"
/**
 * freestack - free the stack
 * @node: linked list
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
