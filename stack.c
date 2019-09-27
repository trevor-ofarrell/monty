 #include "monty.h"
/**
 * init - initialize stack
 * @node: linkedlist
 *
 * Return: 0 for success, 1 otherwise
 */
void init(stack_t **node)
{
	(*node)->n = 0;
	(*node)->next = NULL;
	(*node)->prev = NULL;
}
/**
 * nop - does nothing
 * @node: linkedlist
 * @lc: line count
 * Return: void
 */
void nop(stack_t **node, unsigned int lc)
{
	(void)node;
	(void)lc;
}
/**
 * push - add new item to TOS
 * @node: linked list
 * @lc: line count
 * @nstr: string containing values stack items
 * Return: void or failure
 */
void push(stack_t **node, unsigned int lc, char *nstr)
{
	stack_t *temp = NULL;
	int i;

	if (nstr == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lc);
		exit(EXIT_FAILURE);
	}
	for (i = 0; nstr[i]; i++)
	{
		if (nstr[0] == '-' && i == 0)
			continue;
		if (isdigit(nstr[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lc);
			exit(EXIT_FAILURE);
		}
	}
	temp = malloc(sizeof(node));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(nstr);
	temp->next = NULL;
	temp->prev = NULL;
	if (*node)
	{
		temp->next = *node;
		(*node)->prev = temp;
	}
	*node = temp;
}
/**
 * pop - removes top value of stack
 * @node: linked list
 * @lc: line count
 * Return: void
 */
void pop(stack_t **node, unsigned int lc)
{
	stack_t *next;

	if (!node || !*node)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lc);
		exit(EXIT_FAILURE);
	}
	next = (*node)->next;
	free(*node);
	*node = next;
}
/**
 * pall - prints the value of the items on the stack
 * @node: linked list
 * @lc: line count
 * Return: void
 */
void pall(stack_t **node, unsigned int lc)
{
	stack_t *temp = *node;

	(void)lc;
	if (node == NULL || *node == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
