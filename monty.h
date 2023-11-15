#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct container_s - contains arg, file, content and flag
 * @c_arg: the arg value
 * @c_file: pointer to monty file
 * @c_content: line content
 * @c_flag: Flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct container_s
{
	char *c_arg;
	FILE *c_file;
	char *c_content;
	int c_flag;
}  container_t;

extern container_t container;

void m_pall(stack_t **h, unsigned int c);
void m_stack(stack_t **h, unsigned int count);
void m_queue(stack_t **h, unsigned int count);
void queue_adder(stack_t **h, int n_val);
void free_stacked(stack_t *h);
void m_push(stack_t **h, unsigned int count);
void m_sub(stack_t **h, unsigned int count);
void m_add(stack_t **h, unsigned int count);
void m_swap(stack_t **h, unsigned int count);
void m_pstr(stack_t **h, unsigned int count);
void m_nop(stack_t **h, unsigned int count);
void m_div(stack_t **h, unsigned int count);
void m_mod(stack_t **h, unsigned int count);
void m_mul(stack_t **h, unsigned int count);
void m_pint(stack_t **h, unsigned int count);
void m_pop(stack_t **h, unsigned int count);
void m_pchar(stack_t **h, unsigned int count);
void node_adder(stack_t **h, int n_val);
void m_rot1(stack_t **h, __attribute__((unused)) unsigned int count);
void m_rot2(stack_t **h,  __attribute__((unused)) unsigned int count);
int exec(char *c_info, stack_t **stack, unsigned int count, FILE *file);

#endif
