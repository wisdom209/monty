#include "monty.h"

/**
 * mul_top_stack - divs
 * @op_code: op code
 * @stack: stack
 * @ln: length
 *
 * Return: void
 */
void mul_top_stack(char *op_code, stack_t *stack, int ln)
{
	if (strcmp(op_code, "mul\n") == 0 || strcmp(op_code, "mul") == 0)
	{
		mul(stack, ln);
	}
}

/**
 * mod_top_stack - divs
 * @op_code: op code
 * @stack: stack
 * @ln: length
 *
 * Return: void
 */
void mod_top_stack(char *op_code, stack_t *stack, int ln)
{
	if (strcmp(op_code, "mod\n") == 0 || strcmp(op_code, "mod") == 0)
	{
		mod(stack, ln);
	}
}

/**
 * print_char_top_stack - peek char value
 * @op_code: op code
 * @stack: stack head
 * @ln: line number
 *
 * Return: void
 */
void print_char_top_stack(char *op_code, stack_t *stack, int ln)
{
	if (strcmp(op_code, "pchar\n") == 0 || strcmp(op_code, "pchar") == 0)
	{
		if (stack && stack->next == NULL)
		{
			if (stack->n >= 0 && stack->n <= 127)
				printf("%c\n", stack->n);
			else
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
				exit(EXIT_FAILURE);
			}
		}
		else
			peek_char(stack, ln);
	}
}
