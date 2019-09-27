#include "monty.h"
/**
 * getops - struct to compare input to a list of cmds and then execute if valid
 * @buf: user input
 * @stack: our linked list
 * @lc: line count of instruction
 *
 * Return: 0 for success, 1 otherwise
 */
int getops(char *buf, stack_t **stack, unsigned int lc)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pop", pop},
		{"nop", nop},
		{"pint", pint},
		{NULL, NULL},
	};

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(buf, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, lc);
			return (EXIT_SUCCESS);
		}
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", lc, buf);
	freestack(stack);
	return (EXIT_FAILURE);
}