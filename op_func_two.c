#include "monty.h"

/**
 * divs - divides top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void divs(char *opcode, int line_number)
{
	stack_t *tmp = head;
	int result;

	if (strcmp(opcode, "div") == 0)
	{
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L<%d>: can't div, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		if (tmp->next->n == 0)
		{
			fprintf(stderr, "L<%d>: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		result = tmp->n / tmp->next->n;
		free(tmp->next);
		tmp->next = NULL;
		tmp->n = (result);
	}
}

/**
 * mod - mods top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void mod(char *opcode, int line_number)
{
	stack_t *tmp = head;
	int result;

	if (strcmp(opcode, "mod") == 0)
	{
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L<%d>: can't mod, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		if (tmp->next->n == 0)
		{
			fprintf(stderr, "L<%d>: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		result = tmp->n % tmp->next->n;
		free(tmp->next);
		tmp->next = NULL;
		tmp->n = (result);
	}
}

/**
 * mul - multiplies top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void mul(char *opcode, int line_number)
{
	stack_t *tmp = head;
	int result;

	if (strcmp(opcode, "mul") == 0)
	{
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L<%d>: can't mul, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		result = tmp->n * tmp->next->n;
		free(tmp->next);
		tmp->next = NULL;
		tmp->n = (result);
	}
}

/**
 * pchar - print ascii at top of stack
 * @opcode: op code
 * @line_number: line number
 */
void pchar(char *opcode, int line_number)
{
	if (strcmp(opcode, "pchar") == 0)
	{
		stack_t *temp = head;

		if (head == NULL)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			exit(EXIT_FAILURE);
		}

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		if (temp->n > 127 || temp->n < 0)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
		printf("%c\n", temp->n);
	}
}

/**
 * pstr - print ascii string from stacktop
 * @head: head of stack
 * @opcode: op code
 */
void pstr(stack_t *head, char *opcode)
{
	if (strcmp(opcode, "pstr") == 0)
	{
		stack_t *temp = head;
		int arr[4096];
		int count = 0, i = 0;

		if (temp == NULL)
		{
			printf("\n");
			return;
		}
		while (temp != NULL)
		{
			arr[count] = temp->n;
			count++;
			temp = temp->next;
		}
		for (i = count - 1; i >= 0; i--)
		{
			if (arr[i] > 127 || arr[i] <= 0)
				break;
			printf("%c", arr[i]);
		}
		printf("\n");
	}
}
