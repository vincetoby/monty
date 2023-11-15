#include "monty.h"

/**
 * m_swap - swaps the top two elements of the stack.
 * @h: head of stack
 * @count: line count
 * Return: void
 */

void m_swap(stack_t **h, unsigned int count)
{
	stack_t *h2;
	int len = 0, temp;

	h2 = *h;
	while (h2)
	{
		h2 = h2->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	h2 = *h;
	temp = h2->n;
	h2->n = h2->next->n;
	h2->next->n = temp;
}
