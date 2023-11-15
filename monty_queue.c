#include "monty.h"

/**
 * m_stack - sets flag to 0
 * @h: head
 * @count: line count
 * Return: void
*/

void m_stack(stack_t **h, unsigned int count)
{
	(void)h;
	(void)count;
	container.c_flag = 0;
}

/**
 * m_queue - sets flag to 1
 * @h: head of stack
 * @count: line count
 * Return: void
 */

void m_queue(stack_t **h, unsigned int count)
{
	(void)h;
	(void)count;
	container.c_flag = 1;
}

/**
 * queue_adder - add node to the end of stack
 * @n_val: value of new node
 * @h: head of stack
 * Return: void
 */

void queue_adder(stack_t **h, int n_val)
{
	stack_t *new, *temp;

	temp = *h;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n_val;
	new->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*h = new;
		new->prev = NULL;
	}
	else
	{
		temp->next = new;
		new->prev = temp;
	}
}
