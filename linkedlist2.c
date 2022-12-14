#include "monty.h"

/**
 * peek - print top of stack
 * @h: head node
 * @ln: line number
 *
 * Return: number of nodes
 */
size_t peek(stack_t *h, int ln)
{
	size_t number_of_nodes = 0;
	stack_t *temp = h;

	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		break;
	}

	return (number_of_nodes);
}

/**
 * swap - print top of stack
 * @h: head node
 * @ln: line number
 *
 * Return: number of nodes
 */
size_t swap(stack_t *h, int ln)
{
	size_t number_of_nodes = 0;
	stack_t *temp = h;
	int temp_num = 0;

	if (h == NULL || h->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}

	while (temp != NULL)
	{
		temp_num = temp->n;
		temp->n = temp->prev->n;
		temp->prev->n = temp_num;
		break;
	}

	return (number_of_nodes);
}

/**
 * add - adds top of stack
 * @h: head node
 * @ln: line number
 *
 * Return: number of nodes
 */
size_t add(stack_t *h, int ln)
{
	size_t number_of_nodes = 0;
	stack_t *temp = h;
	int temp_num = 0;

	if (h == NULL || h->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}

	while (temp != NULL)
	{
		temp_num = temp->n + temp->prev->n;
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
 * sub - sutracts top of stack
 * @h: head node
 * @ln: line number
 *
 * Return: number of nodes
 */
size_t sub(stack_t *h, int ln)
{
	size_t number_of_nodes = 0;
	stack_t *temp = h;
	int temp_num = 0;

	if (h == NULL || h->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}

	while (temp != NULL)
	{
		temp_num = abs(temp->n - temp->prev->n);
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
