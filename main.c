#include "monty.h"

int main(int argc, char **argv, char **env)
{
	int ret = 0, fd = 0;
	char **buffer = NULL, *head = NULL;
	char buf[SIZE];

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
	if (!buffer)
	{
		printf("F");
		return (0);
	}
	printf("%s\n", buffer[0]);
	printf("%s\n", buffer[1]);
	printf("%s\n", buffer[2]);
	printf("%s\n", buffer[3]);
	close(fd);
	return (ret);
}
