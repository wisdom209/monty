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

/* check_data_structure.c */
void set_stack_or_queue(char *arg_1, int *isStack);

/* check_error.c */
int is_string_printable(char *str);
void check_args(int argc);
FILE *get_file(const char *path);
void check_op_code(char *str, int line_number);
int check_arg2(char *arg_2);

/* continue_checks.c */
int check_comment(char *arg_1);
int check_empty_line(char *arg_1, char *string);

/* freelist.c */
void free_dlistint(stack_t *head);

/* linkedlist.c */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *del_dnodeint(stack_t **head);
stack_t *delend_dnodeint(stack_t **head);
size_t print_dlistintrev(stack_t *h);

/* linkedlist2.c */
size_t peek(stack_t *h, int ln);
size_t swap(stack_t *h, int ln);
size_t add(stack_t *h, int ln);
size_t sub(stack_t *h, int ln);
size_t _div(stack_t *h, int ln);

/* linkedlist3.c */
size_t mul(stack_t *h, int ln);
size_t mod(stack_t *h, int ln);
size_t peek_char(stack_t *h, int ln);
size_t printstr_dlistintrev(stack_t *h);
void rotate_left(stack_t *h);

/* linkedlist4.c */
void rotate_right(stack_t *h);

/* op_funcs.c */
void call_opfunc(char *op_code, stack_t *stack, int op_num, int ln, int isStack);
stack_t *push_stack(char *op_code, stack_t *stack, const int op_num, int ln);
void print_stack(char *op_code, stack_t *stack);
void print_top_stack(char *op_code, stack_t *stack, int ln);
void swap_top_stack(char *op_code, stack_t *stack, int ln);

/* op_funcs_two.c */
void pop_top_of_stack(char *op_code, stack_t *stack, int ln);
void add_top_stack(char *op_code, stack_t *stack, int ln);
void sub_top_stack(char *op_code, stack_t *stack, int ln);
void div_top_stack(char *op_code, stack_t *stack, int ln);
void nop(char *op_code);

/* op_funcs_three.c */
void mul_top_stack(char *op_code, stack_t *stack, int ln);
void mod_top_stack(char *op_code, stack_t *stack, int ln);
void print_char_top_stack(char *op_code, stack_t *stack, int ln);
void rotate_stack_left(char *opcode, stack_t *stack);
void printstr_stack(char *op_code, stack_t *stack);

/* op_funcs_four.c */
void rotate_stack_right(char *opcode, stack_t *stack);
stack_t *enqueue_stack(char *op_code, stack_t *stack, const int op_num, int ln);
void dequeue_stack(char *op_code, stack_t *stack, int ln);

#endif
