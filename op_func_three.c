#include "monty.h"

/**
 * rotl - rotate left the top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void rotl(char *opcode, int line_number __attribute__((unused)))
{
	stack_t *tmp = head;
	stack_t *tmptop;

	if (strcmp(opcode, "rotl") == 0)
	{
		if (head != NULL || (head != NULL && head->next != NULL))
		{
			while (tmp && tmp->next->next != NULL)
			{
				tmp = tmp->next;
			}
			tmptop = tmp->next;
			tmp->next = NULL;
			tmptop->next = head;
			head->prev = tmptop;
			head = tmptop;
		}
	}
}

/**
 * rotr - rotate right the top of stack
 * @opcode: opcode
 * @line_number: line number
 */
void rotr(char *opcode, int line_number __attribute__((unused)))
{
	stack_t *tmp = head;

	if (strcmp(opcode, "rotr") == 0)
	{
		if (head != NULL || (head != NULL && head->next != NULL))
		{
			while (tmp && tmp->next != NULL)
			{
				tmp = tmp->next;
			}

			tmp->next = head;
			head = head->next;
			tmp->next->next = NULL;
			tmp->next->prev = tmp;
		}
	}
}
