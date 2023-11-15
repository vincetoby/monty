#include "monty.h"

/**
 * m_pstr - Prints string starting from stacks top
 * @h: Stack's head
 * @count: line count
 * Return: void
 */

void m_pstr(stack_t **h, unsigned int count)
{
	stack_t *h2;
	(void)count;

	h2 = *h;
	while (h2)
	{
		if (h2->n > 127 || h2->n <= 0)
		{
			break;
		}
		printf("%c", h2->n);
		h2 = h2->next;
	}
	printf("\n");
}
