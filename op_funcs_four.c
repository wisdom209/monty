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

/**
 * dequeue_stack - dequeue
 * @op_code: op code
 * @stack: stack
 * @ln: line number
 *
 * Return: dequeued
 */
void dequeue_stack(char *op_code, stack_t *stack, int ln)
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
				del_dnodeint(&stack);
		}
	}
}

/**
 * enqueue_stack - enqueue
 * @stack: stack
 * @op_code: op code string
 * @op_num: op num
 * @ln: line number
 *
 * Return: stack queued
 */
stack_t *enqueue_stack(char *op_code, stack_t *stack, const int op_num, int ln)
{
	if (strcmp(op_code, "push") == 0)
	{
		if (op_num == INT_NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		add_dnodeint(&stack, op_num);
	}

	return (stack);
}
