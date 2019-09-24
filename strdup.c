#include "monty.h"

/**
 * _strdup - copy a given string to an allocated memory
 *
 * @str: string to copy
 *
 * Return: string
 */

char *_strdup(char *str)
{
	int i;
	int n = 0;
	char *string = NULL;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		n++;

	string = malloc((n + 1) * sizeof(char));

	if (string == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		string[i] = str[i];

	string[i] = '\0';

	return (string);
}
