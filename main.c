#include "monty.h"
/**
 * main - starting point for the monty bytecode interpreter program
 * @argc: argument count
 * @argv: argument vector
 * Return: exit success
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	char *buf = NULL, *nstr = NULL;
	stack_t *node = malloc(sizeof(char *));
	unsigned int lc = 0;
	size_t len;
	ssize_t get;
	FILE *_file;

	init(&node);
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_file = fopen(argv[1], "r+");
	if (_file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((get = getline(&buf, &len, _file) != -1))
	{
		lc++;
		buffer = strtok(buf, DELIM);
		if (strcmp(buffer, "push") == 0)
		{
			nstr = strtok(NULL, DELIM);
			push(&node, lc, nstr);
		}
		else
			getops(buffer, &node, lc);
	}
	fclose(_file);
	free(node);
	free(buf);
	return (EXIT_SUCCESS);
}
