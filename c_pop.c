#include "monty.h"

/**
 * m_pop - deletes top of stack
 * @h: head
 * @count: line count
 * Return: void
 */

void m_pop(stack_t **h, unsigned int count)
{
	stack_t *h2;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	h2 = *h;
	*h = h2->next;
	free(h2);
}
