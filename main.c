#include "monty.h"

int main(int argc, char **argv, char **env)
{
	int ret = 0, fd = 0, i = 0, ret2 = 0;
	char **buffer = NULL, *head = NULL;
	char buf[SIZE];
	stack_t **stackH = NULL;
	int data = 0;

	(void)ret;
	(void)env;
	(void)head;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		printf("Error: Can't open file ");
		printf("<%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ret = read(fd, buf, SIZE);
	buffer = parse(buf);
	while (buffer[i] != NULL)
	{
		data = *buffer[i];
		addnode(stackH, data);
		printf("%d\n", data);
		++i;
	}
	print_dlistint(stackH);
	close(fd);
	return (ret2);
}
