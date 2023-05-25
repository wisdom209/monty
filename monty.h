#ifndef _MAIN_H_
#define _MAIN_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *head;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

FILE *getfile(char *path);
void push(char *first, int second, int line_number);
void pall(stack_t *head, char *opcode);
void check_code(char *first, int second, int line_number);
void checkArgs(char *opcode, int line_number);
int check_only_figures(char *first, char *second);
void pint(char *opcode, int line_number);
void pop(char *opcode, int line_number);
void swap(char *opcode, int line_number);
void add(char *opcode, int line_number);
void sub(char *opcode, int line_number);
void divs(char *opcode, int line_number);
void mul(char *opcode, int line_number);
void mod(char *opcode, int line_number);
void pchar(char *opcode, int line_number);
void rotl(char *opcode, int line_number);
void rotr(char *opcode, int line_number);
void pstr(stack_t *head, char *opcode);
#endif
