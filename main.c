#include "monty.h"

int main(int argc, char **argv, extern char **environ)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FALIURE);
	}
	check = open(fd, argv[1], NULL);
	if (check == -1)
	{
		printf("Error: Can't open file <file>\n");
		exit(EXIT_FALIURE);
	}
