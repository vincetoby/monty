#include "monty.h"

/**
 * m_rot1- Rotates the stack (to the bottom)
 * @h: Stack's head
 * @count: line count
 * Return: void
 */

void m_rot1(stack_t **h, __attribute__((unused)) unsigned int count)
{
	stack_t *temp;

	temp = *h;
	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *h;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*h)->prev = temp;
	(*h) = temp;
}

/**
  *m_rot2- Rotates the stack (to the top)
  *@h: stack head
  *@count: line count
  *Return: void
 */

void m_rot2(stack_t **h,  __attribute__((unused)) unsigned int count)
{
	stack_t *temp = *h, *temp2;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	temp2 = (*h)->next;
	temp2->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = temp;
	(*h) = temp2;
}
