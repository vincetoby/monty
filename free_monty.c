#include "monty.h"

/**
* free_stacked - Function that frees a doubly linked list
* @h: head of list (stack)
* Return: void
*/

void free_stacked(stack_t *h)
{
	stack_t *temp;

	temp = h;
	while (h)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}
