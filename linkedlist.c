#include "monty.h"

/**
 * add_dnodeint - add node at beginning of list
 * @head: list head
 * @n: new value at head
 *
 * Return: address of new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;

		return (new_node);
	}

	new_node->next = *head;
	new_node->prev = NULL;
	(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * add_dnodeint_end - add node at end of doubly linked list
 * @head: head node
 * @n: value at end
 *
 * Return: address of newnode
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *head;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*head = new_node;

		return (new_node);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = NULL;
	return (new_node);
}

/**
 * del_dnodeint - del node at beginning of list
 * @head: list head
 *
 * Return: address of del element
 */
stack_t *del_dnodeint(stack_t **head)
{
	stack_t *temp = *head;

	if (*head == NULL)
		return (*head);

	*head = temp->next;
	free(temp);
	(*head)->prev = NULL;

	return (*head);
}

/**
 * delend_dnodeint - del node at end of list
 * @head: list head
 *
 * Return: address of del element
 */
stack_t *delend_dnodeint(stack_t **head)
{
	stack_t *temp = *head;

	if (*head == NULL)
		return (*head);
	while (temp && temp->next->next != NULL)
		temp = temp->next;

	free(temp->next);
	temp->next = NULL;

	return (*head);
}

/**
 * print_dlistintrev - print double linked list
 * @h: head node
 *
 * Return: number of nodes
 */
size_t print_dlistintrev(stack_t *h)
{
	size_t number_of_nodes = 0;
	stack_t *temp = h;

	while (temp && temp->next != NULL)
	{
		number_of_nodes++;
		temp = temp->next;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}

	return (number_of_nodes);
}
