#include "monty.h"

/**
 * pop_top_of_stack - pop top
 * @stack: stack
 * @op_code: op_code
 * @ln: line number
 *
 * Return: void
 */
void pop_top_of_stack(char *op_code, stack_t *stack, int ln)
{

	if (strcmp(op_code, "pop\n") == 0 || strcmp(op_code, "pop") == 0)
	{
		if (stack == NULL)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (stack->next == NULL)
			{
				free(stack);
				stack = NULL;
				head = NULL;
			}
			else
				delend_dnodeint(&stack);
		}
	}
}

/**
 * add_top_stack - swaps
 * @op_code: op code
 * @stack: stack
 * @ln: length
 *
 * Return: void
 */
void add_top_stack(char *op_code, stack_t *stack, int ln)
{
	if (strcmp(op_code, "add\n") == 0 || strcmp(op_code, "add") == 0)
	{
		add(stack, ln);
	}
}
/**
 * sub_top_stack - swaps
 * @op_code: op code
 * @stack: stack
 * @ln: length
 *
 * Return: void
 */
void sub_top_stack(char *op_code, stack_t *stack, int ln)
{
	if (strcmp(op_code, "sub\n") == 0 || strcmp(op_code, "sub") == 0)
	{
		sub(stack, ln);
	}
}

/**
 * nop - does nothing
 * @op_code: op code
 *
 * Return: nothing
 */
void nop(char *op_code)
{
	if (strcmp(op_code, "nop\n") == 0 || strcmp(op_code, "nop") == 0)
	{
		return;
	}
}
