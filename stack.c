#include "monty.h"

void init(_sstack_t *node)
{
	node->count = 0;
	node->front = NULL;
	node->rear = NULL;
}

int empty(_sstack_t *node)
{
	return (node->rear == NULL);
}


void stack(_sstack_t *node, int num)
{
	stack_t *temp = NULL;

	if (node->count < FULL)
	{
		temp = malloc(sizeof(node));
		temp->n = num;
		temp->next = NULL;
		if (!empty(node))
		{
			node->rear->next = temp;
			node->rear = temp;
		}
		else
		{
			node->front = node->rear = temp;
		}
		node->count++;
	}
}
int removenode(_sstack_t *node)
{
	stack_t *temp;
	int i = 0;

	i = node->front->n;
	temp = node->front;
	node->front = node->front->next;
	node->count--;
	free(temp);
	return(i);
}
void printlist(stack_t *head)
{
	if (!head)
	{
		printf("NULL\n");
		exit(1);
	}
	else
	{
		printf("%d\n", head->n);
		printlist(head->next);
	}
}
