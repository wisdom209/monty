#include "monty.h"

/**
 * push - push to the top of stack
 * @first: first opcode
 * @second: value to add
 * @line_number: line number of operation
 */
void push(char *first, int second, int line_number)
{
	if (second == -9999)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (strcmp(first, "push") == 0)
	{
		stack_t *tmp = malloc(sizeof(instruction_t));

		if (tmp == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		tmp->n = second;
		tmp->next = NULL;
		tmp->prev = NULL;
		if (head == NULL)
			head = tmp;
		else
		{
			stack_t *thd = head;

			while (thd->next != NULL)
			{
				thd = thd->next;
			}
			thd->next = tmp;
			tmp->prev = thd;
		}
	}
}

/**
 * pall - print all
 * @head: head of stack
 * @opcode: op code
 */
void pall(stack_t *head, char *opcode)
{
	if (strcmp(opcode, "pall") == 0)
	{
		stack_t *temp = head;

		while (temp && temp->next != NULL)
			temp = temp->next;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
}

/**
 * check_code - checking codes
 * @first: first arg
 * @second: second arg
 * @line_number: line number
 */
void check_code(char *first, int second, int line_number)
{
	checkArgs(first, line_number);

	push(first, second, line_number);
	pall(head, first);
	pint(first, line_number);
	pop(first, line_number);
	swap(first, line_number);
	add(first, line_number);
	sub(first, line_number);
	divs(first, line_number);
	mul(first, line_number);
	mod(first, line_number);
	pchar(first, line_number);
	pstr(head, first);
	rotl(first, line_number);
	rotr(first, line_number);
}

/**
 * checkArgs - check the opcode
 * @opcode: opcode
 * @line_number: line number
 */
void checkArgs(char *opcode, int line_number)
{
	char *arr[] = {"pall", "push", "pint", "pop", "swap", "add",
				   "nop", "div", "sub", "mul", "mod", "pchar",
				   "pstr", "rotl", "rotr"};
	size_t i;

	for (i = 0; i < (sizeof(arr) / sizeof(arr[i])); i++)
	{
		if (strcmp(arr[i], opcode) == 0)
			return;
	}
	if (opcode[0] == '\0' || opcode[0] == '#')
		return;
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
