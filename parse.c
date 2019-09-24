#include "monty.h"

char **parse(char *buf)
{
	char *token = NULL, **lines = malloc(SIZE);
	int i = 0;

	if (!buf)
		exit(1);
	else
		while ((token = strtok(buf, "\n")))
		{
			if (buf)
				buf = NULL;

			lines[i] = _strdup(token);
			if (lines[i] == NULL)
			{
				free(lines);
				return (NULL);
			}
			i++;
		}
	lines[i] = 0x00;
	return (lines);
}
