#include "monty.h"
/**
 * free_dlistint - free double linked list
 * @head: head of list
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}
