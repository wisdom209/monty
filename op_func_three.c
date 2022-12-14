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
