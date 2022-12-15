#include "monty.h"

/**
 * mul - sutracts top of stack
 * @h: head node
 * @ln: line number
 *
 * Return: number of nodes
 */
size_t mul(stack_t *h, int ln)
{
	size_t number_of_nodes = 0;
	stack_t *temp = h;
	int temp_num = 0;

	if (h == NULL || h->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}

	while (temp != NULL)
	{
		temp_num = abs(temp->prev->n * temp->n);
		delend_dnodeint(&head);
		if (head && head->next == NULL)
		{
			free(head);
			head = NULL;
		}
		else
			delend_dnodeint(&head);
		add_dnodeint_end(&head, temp_num);
		break;
	}
	return (number_of_nodes);
}

/**
 * mod - sutracts top of stack
 * @h: head node
 * @ln: line number
 *
 * Return: number of nodes
 */
size_t mod(stack_t *h, int ln)
{
	size_t number_of_nodes = 0;
	stack_t *temp = head;
	int temp_num = 0;

	if (h == NULL || h->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}

	while (temp != NULL)
	{
		if (temp->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", ln);
			exit(EXIT_FAILURE);
		}

		temp_num = abs(temp->prev->n % temp->n);
		delend_dnodeint(&head);
		if (head && head->next == NULL)
		{
			free(head);
			head = NULL;
		}
		else
			delend_dnodeint(&head);
		add_dnodeint_end(&head, temp_num);
		break;
	}
	return (number_of_nodes);
}

/**
 * peek_char - print top of stack
 * @h: head node
 * @ln: line number
 *
 * Return: number of nodes
 */
size_t peek_char(stack_t *h, int ln)
{
	size_t number_of_nodes = 0;
	stack_t *temp = h;

	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}
	while (temp != NULL)
	{
		if (temp->n >= 0 && temp->n <= 127)
			printf("%c\n", temp->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
			exit(EXIT_FAILURE);
		}
		break;
	}
	return (number_of_nodes);
}

/**
 * printstr_dlistintrev - print chars
 * @h: head node
 *
 * Return: number of nodes
 */
size_t printstr_dlistintrev(stack_t *h)
{
	size_t number_of_nodes = 0;
	stack_t *temp = h;

	if (h == NULL)
	{
		printf("\n");
		return (number_of_nodes);
	}

	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}

	while (temp != NULL)
	{
		if (temp->n >= 1 && temp->n <= 127)
			printf("%c", temp->n);
		else
		{
			printf("\n");
			return (number_of_nodes);
		}
		temp = temp->prev;
	}
	printf("\n");
	return (number_of_nodes);
}
