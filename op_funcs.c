#include "monty.h"

/**
 * call_opfunc - call op_func
 * @stack: stack
 * @op_code: op string code
 * @op_num: op num
 * @ln: line number
 * @isStack: stack or queue flag
 *
 * Return: void
 */
void call_opfunc(char *op_code, stack_t *stack,
				 const int op_num, int ln, int isStack)
{
	check_op_code(op_code, ln);

	if (isStack)
	{
		head = push_stack(op_code, stack, op_num, ln);
		pop_top_of_stack(op_code, stack, ln);
	}
	else
	{
		head = enqueue_stack(op_code, stack, op_num, ln);
		dequeue_stack(op_code, stack, ln);
	}
	print_top_stack(op_code, stack, ln);
	swap_top_stack(op_code, stack, ln);
	add_top_stack(op_code, stack, ln);
	sub_top_stack(op_code, stack, ln);
	div_top_stack(op_code, stack, ln);
	mul_top_stack(op_code, stack, ln);
	mod_top_stack(op_code, stack, ln);
	print_char_top_stack(op_code, stack, ln);
	print_stack(op_code, stack);
	rotate_stack_left(op_code, stack);
	rotate_stack_right(op_code, stack);
	printstr_stack(op_code, stack);
}

/**
 * push_stack - push to stack
 * @stack: stack
 * @op_code: op code string
 * @op_num: op num
 * @ln: line number
 *
 * Return: stack pushed
 */
stack_t *push_stack(char *op_code, stack_t *stack, const int op_num, int ln)
{

	if (strcmp(op_code, "push") == 0)
	{
		if (op_num == INT_NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}

		add_dnodeint_end(&stack, op_num);
	}

	return (stack);
}

/**
 * print_stack - print stack
 * @stack: stack
 * @op_code: op code string
 *
 * Return: void
 */
void print_stack(char *op_code, stack_t *stack)
{

	if (strcmp(op_code, "pall\n") == 0 || strcmp(op_code, "pall") == 0)
	{
		print_dlistintrev(stack);
	}
}

/**
 * print_top_stack - peek
 * @op_code: op code
 * @stack: stack head
 * @ln: line number
 *
 * Return: void
 */
void print_top_stack(char *op_code, stack_t *stack, int ln)
{
	if (strcmp(op_code, "pint\n") == 0 || strcmp(op_code, "pint") == 0)
	{
		if (stack && stack->next == NULL)
			printf("%d\n", stack->n);
		else
			peek(stack, ln);
	}
}

/**
 * swap_top_stack - swaps
 * @op_code: op code
 * @stack: stack
 * @ln: length
 *
 * Return: void
 */
void swap_top_stack(char *op_code, stack_t *stack, int ln)
{
	if (strcmp(op_code, "swap\n") == 0 || strcmp(op_code, "swap") == 0)
	{
		swap(stack, ln);
	}
}
