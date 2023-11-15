#include "monty.h"

/**
 * m_div - divides the 2nd  by  top element of stack.
 * @h: head
 * @count: line count
 * Return: void
 */

void m_div(stack_t **h, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	h2 = *h;
	if (h2->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	temp = h2->next->n / h2->n;
	h2->next->n = temp;
	*h = h2->next;
	free(h2);
}

/**
 * m_mod - gets the remainder of the division of 2nd nd top element
 * @h: Stack's head
 * @count: line count
 * Return: void
 */

void m_mod(stack_t **h, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	h2 = *h;
	if (h2->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	temp = h2->next->n % h2->n;
	h2->next->n = temp;
	*h = h2->next;
	free(h2);
}

/**
 * m_mul - Multiplies the 2nd and top element of stack.
 * @h: head
 * @count: line count
 * Return: void
 */

void m_mul(stack_t **h, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	h2 = *h;
	temp = h2->next->n * h2->n;
	h2->next->n = temp;
	*h = h2->next;
	free(h2);
}
