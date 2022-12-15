#include "monty.h"

/**
 * rotate_stack_right - first becomes last
 * @opcode: opcode
 * @stack: head
 *
 * Return: void
 */
void rotate_stack_right(char *opcode, stack_t *stack)
{
	if (strcmp(opcode, "rotr\n") == 0 || strcmp(opcode, "rotr") == 0)
	{
		rotate_right(stack);
	}
}
