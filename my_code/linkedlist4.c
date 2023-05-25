#include "monty.h"

/**
 * rotate_right - first of stack becomes last
 * @h: head
 *
 * Return: void
 */
void rotate_right(stack_t *h)
{
	int hold_first = 0;

	if (h == NULL || (h && h->next == NULL))
		return;

	hold_first = h->n;

	del_dnodeint(&head);
	add_dnodeint_end(&head, hold_first);
}
