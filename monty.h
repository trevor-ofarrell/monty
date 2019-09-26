#ifndef MONTY_H
#define MONTY_H
#define SIZE 1024
#define TRUE 1
#define FALSE 0
#define DELIM "\n\t\r "
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;
extern char *gbuffer;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct _sstack_s
{
	int count;
	stack_t *front;
	stack_t *rear;
} _sstack_t;

int getops(char *buf, stack_t **stack, unsigned int lc);
char *_strstr(char *haystack, char *needle);
int _strcmp(char *s1, char *s2);
char **postparse(char **line);
size_t print_dlistint(stack_t **h);
char *_strdup(char *str);
char *parse(char *buf);
void pint(stack_t **node, unsigned int lc);
void pop(stack_t **node, unsigned int lc);
void pall(stack_t **node, unsigned int lc);
void push(stack_t **node, unsigned int lc, char *nstr);
void nop(stack_t **node, unsigned int lc);
void init(stack_t **node);
stack_t *addnode(stack_t **head, const int n);

#endif
