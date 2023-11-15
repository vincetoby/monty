#include "monty.h"

/**
  *m_sub- sustracts top element from 2nd element in stack
  *@h: head of stack
  *@count: line count
  *Return: void
  */

void m_sub(stack_t **h, unsigned int count)
{
	stack_t *temp;
	int s, nd;

	temp = *h;
	for (nd = 0; temp != NULL; nd++)
		temp = temp->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stacked(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	s = temp->next->n - temp->n;
	temp->next->n = s;
	*h = temp->next;
	free(temp);
}
