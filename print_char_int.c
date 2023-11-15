#include "monty.h"

/**
 * m_pchar - Prints char at the top of stack,
 * @h: head
 * @count: line count
 * Return: void
 */

void m_pchar(stack_t **h, unsigned int count)
{
	stack_t *h2;

	h2 = *h;
	if (!h2)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	if (h2->n > 127 || h2->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h2->n);
}

/**
 * m_pint - prints int on the top of stack
 * @h: stack's head
 * @count: line count
 * Return: void
 */

void m_pint(stack_t **h, unsigned int count)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
