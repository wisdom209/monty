#ifndef _main_h_
#define _main_h_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INT_NULL -9999999

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

extern stack_t *head;

void free_dlistint(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *del_dnodeint(stack_t **head);
stack_t *delend_dnodeint(stack_t **head);
size_t print_dlistintrev(stack_t *h);
size_t peek(stack_t *h, int ln);
size_t swap(stack_t *h, int ln);
size_t add(stack_t *h, int ln);
size_t sub(stack_t *h, int ln);

void check_args(int argc);
FILE *get_file(const char *path);
void call_opfunc(char *op_code, stack_t *stack, int op_num, int ln);
stack_t *push_stack(char *op_code, stack_t *stack, const int op_num, int ln);
void print_stack(char *op_code, stack_t *stack);
int is_string_printable(char *str);
void check_op_code(char *str, int line_number);
int check_arg2(char *arg_2);

void print_top_stack(char *op_code, stack_t *stack, int ln);
void pop_top_of_stack(char *op_code, stack_t *stack, int ln);
void swap_top_stack(char *op_code, stack_t *stack, int ln);
void add_top_stack(char *op_code, stack_t *stack, int ln);
void nop(char *op_code);
void sub_top_stack(char *op_code, stack_t *stack, int ln);

#endif
