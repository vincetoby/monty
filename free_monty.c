#include "monty.h"

/**
* free_stack - Function that frees a doubly linked list
* @h: head of list (stack)
* Return: void
*/

void free_stack(stack_t *h)
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
