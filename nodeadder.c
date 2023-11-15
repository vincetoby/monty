#include "monty.h"

/**
 * node_adder - adds new node to stack
 * @h: head of stack
 * @n_val: new node value
 * Return: void
 */

void node_adder(stack_t **h, int n_val)
{

	stack_t *new, *temp;

	temp = *h;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n"); /*rechck here*/
		exit(0);
	}
	if (temp)
		temp->prev = new;
	new->n = n_val;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}

/**
 * m_add - Adds the top two elements of stack.
 * @h: head of stack
 * @count: line count
 * Return: void
 */

void m_add(stack_t **h, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	h2 = *h;
	temp = h2->n + h2->next->n;
	h2->next->n = temp;
	*h = h2->next;
	free(h2);
}
