#include "monty.h"
/**
 * opdiv - divide by the two elements on the TOS
 * @node: pointer to linked list
 * @lc: line count
 *
 * Return - void
 */
void opdiv(stack_t **node, unsigned int lc)
{
	stack_t *temp = NULL;

	if ((*node)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lc);
		exit(EXIT_FAILURE);
	}
	else if (!*node || !(*node)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lc);
		exit(EXIT_FAILURE);
	}
	if (*node && (*node)->next != NULL)
	{
		(*node)->next->n /= (*node)->n;
		temp = *node;
		*node = (*node)->next;
		(*node)->prev = NULL;
		free(temp);
	}
}
/**
 * mul - multiply the two elements on the TOS
 * @node: pointer to linked list
 * @lc: line count
 *
 * Return - void
 */
void mul(stack_t **node, unsigned int lc)
{
	stack_t *temp = NULL;

	if (*node && (*node)->next != NULL)
	{
		(*node)->next->n *= (*node)->n;
		temp = *node;
		*node = (*node)->next;
		(*node)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", lc);
		freestack(node);
		exit(EXIT_FAILURE);
	}
}
