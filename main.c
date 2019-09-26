#include "monty.h"
/**
 * main - starting point for the monty bytecode interpreter program
 * @argc: argument count
 * @argv: argument vector
 * Return: exit success
 */
int main(int argc, char **argv)
{
	char *buf = NULL;
	stack_t *node = malloc(sizeof(char *));
	size_t len = 0;
	FILE *_file;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_file = fopen(argv[1], "r");
	if (_file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
		do_ops(node, buf, len, _file);
	return (EXIT_SUCCESS);
}
