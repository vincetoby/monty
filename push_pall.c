#include "monty.h"

/**
 * m_pall - prints the stack
 * @h: stack head
 * @c: count but unused
 * Return: void
*/

void m_pall(stack_t **h, unsigned int c)
{
	stack_t *h2;
	(void)c;

	h2 = *h;
	if (h2 == NULL)
		return;
	while (h2)
	{
		printf("%d\n", h2->n);
		h2 = h2->next;
	}
}

/**
 * m_push - func that inserts node to the stack
 * @h: head of stack
 * @count: line_number
 * Return: void
*/

void m_push(stack_t **h, unsigned int count)
{
	int num, j = 0, fg = 0;

	if (container.c_arg)
	{
		if (container.c_arg[0] == '-')
			j++;
		for (; container.c_arg[j] != '\0'; j++)
		{
			if (container.c_arg[j] < 48 || container.c_arg[j] > 57)
				fg = 1;
		}
		if (fg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(container.c_file);
			free(container.c_content);
			free_stack(*h);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(container.c_file);
		free(container.c_content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	num = atoi(container.c_arg);
	if (container.c_flag == 0)
		node_adder(h, num);
	else
		queue_adder(h, num);
}
