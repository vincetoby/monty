#include "monty.h"

/**
 * exec - executes opcode
 * @stack: head linked list - stack
 * @count: line count
 * @file: Pointer to monty file
 * @c_info: line content
 * Return: void
 */

int exec(char *c_info, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opc[] = {
				{"push", m_push}, {"pall", m_pall},
				{"pint", m_pint}, {"pop", m_pop},
				{"swap", m_swap}, {"add", m_add},
				{"nop", m_nop}, {"sub", m_sub},
				{"div", m_div}, {"mul", m_mul},
				{"mod", m_mod}, {"pchar", m_pchar},
				{"pstr", m_pstr}, {"rotl", m_rot2},
				{"rotr", m_rot1}, {"queue", m_queue},
				{"stack", m_stack}, {NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(c_info, " \n\t");
	if (op && op[0] == '#')
		return (0);
	container.c_arg = strtok(NULL, " \n\t");
	while (opc[i].opcode && op)
	{
		if (strcmp(op, opc[i].opcode) == 0)
		{	opc[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opc[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(c_info);
		free_stacked(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
