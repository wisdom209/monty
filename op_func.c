#include "monty.h"

/**
 * pint - print top of stack
 * @opcode: op code
 * @line_number: line number
 */
void pint(char *opcode, int line_number)
{
	if (strcmp(opcode, "pint") == 0)
	{
		stack_t *temp = head;

		if (head == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			exit(EXIT_FAILURE);
		}

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		printf("%d\n", temp->n);
	}
}

/**
 * pop - pop top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void pop(char *opcode, int line_number)
{
	stack_t *tmp = head;

	if (strcmp(opcode, "pop") == 0)
	{
		if (head == NULL)
		{
			fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
			exit(EXIT_FAILURE);
		}

		if (tmp->next == NULL)
		{
			free(tmp);
			head = NULL;
		}
		else
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->prev->next = NULL;
			free(tmp);
		}
	}
}

/**
 * swap - swap top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void swap(char *opcode, int line_number)
{
	stack_t *tmp = head;
	int tmp_val;

	if (strcmp(opcode, "swap") == 0)
	{
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}

		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp_val = tmp->n;
		tmp->n = tmp->next->n;
		tmp->next->n = tmp_val;
	}
}

/**
 * add - add top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void add(char *opcode, int line_number)
{
	stack_t *tmp = head;
	int sum;

	if (strcmp(opcode, "add") == 0)
	{
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L<%d>: can't add, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}

		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		sum = tmp->n + tmp->next->n;
		free(tmp->next);
		tmp->next = NULL;
		tmp->n = (sum);
	}
}

/**
 * sub - sub top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void sub(char *opcode, int line_number)
{
	stack_t *tmp = head;
	int result;

	if (strcmp(opcode, "sub") == 0)
	{
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L<%d>: can't sub, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}

		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		result = tmp->n - tmp->next->n;
		free(tmp->next);
		tmp->next = NULL;
		tmp->n = (result);
	}
}
