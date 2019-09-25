#include "monty.h"

int main(int argc, char **argv, char **env)
{
	int ret = 0, fd = 0, i = 0, ret2 = 0;
	char **buffer = NULL, *head = NULL;
	char buf[SIZE];
	_sstack_t *node = malloc(sizeof(stack_t));
	int data = 0;

	(void)ret;
	(void)env;
	(void)head;
	init(node);
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
	i = 0;
	while (buffer[i] != NULL)
	{
		data = *buffer[i];
		stack(node, data);
		++i;
	}
	printlist(node->front);
	close(fd);
	return (ret2);
}
