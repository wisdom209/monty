#include "monty.h"

/**
 * set_stack_or_queue - set data structure
 * @arg_1: op code
 * @isStack: data structure flag
 *
 * Return: void
 */
void set_stack_or_queue(char *arg_1, int *isStack)
{
	if (strcmp(arg_1, "queue") == 0 || strcmp(arg_1, "queue\n") == 0)
		*isStack = 0;

	if (strcmp(arg_1, "stack") == 0 || strcmp(arg_1, "stack\n") == 0)
		*isStack = 1;
}
