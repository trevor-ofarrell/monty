#include "monty.h"
/**
 * do_ops - called by main to exec ops specifed in the opcode struct
 *
 * @node: pointer to linked list
 * @buf: buffer of user input
 * @len: len of buffer
 * @_file: pointer to file to read from
 *
 * Return: void
 */
void do_ops(stack_t *node, char *buf, size_t len, FILE *_file)
{
	unsigned int lc = 0;
	char *buffer = NULL, *nstr = NULL;

	while ((getline(&buf, &len, _file) != -1))
	{
		lc++;
		buffer = strtok(buf, DELIM);
		if (buffer == NULL || strncmp(buffer, "#", TRUE) == 0)
			continue;
		if (strcmp(buffer, "push") == 0)
		{
			nstr = strtok(NULL, DELIM);
			push(&node, lc, nstr);
		}
		else
			getops(buffer, &node, lc);
	}
}
