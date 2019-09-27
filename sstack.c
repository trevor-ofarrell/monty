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
		fprintf(stderr, "L%d: can't pint, stack empty\n", lc);
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
/**
 * add - add the two elements on the TOS
 * @node: pointer to linked list
 * @lc: line count
 *
 * Return - void
 */
void add(stack_t **node, unsigned int lc)
{
	stack_t *temp = NULL;

	if (*node && (*node)->next != NULL)
	{
		(*node)->next->n += (*node)->n;
		temp = *node;
		*node = (*node)->next;
		(*node)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", lc);
		freestack(node);
		exit(EXIT_FAILURE);
	}
}
/**
 * sub - subtract the two elements on the TOS
 * @node: pointer to linked list
 * @lc: line count
 *
 * Return - void
 */
void sub(stack_t **node, unsigned int lc)
{
	stack_t *temp = NULL;

	if (*node && (*node)->next != NULL)
	{
		(*node)->next->n -= (*node)->n;
		temp = *node;
		*node = (*node)->next;
		(*node)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lc);
		freestack(node);
		exit(EXIT_FAILURE);
	}
}
