#include "monty.h"

container_t container = {NULL, NULL, NULL, 0};

/**
* main - interpreter for the monty code
* @argc: argument count
* @argv: arg vector
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *c_info;
	FILE *opened_file;
	size_t sz = 0;
	ssize_t readline = 1;
	stack_t *stacked = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	opened_file = fopen(argv[1], "r");
	container.c_file = opened_file;
	if (!opened_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (readline > 0)
	{
		c_info = NULL;
		readline = getline(&c_info, &sz, opened_file);
		container.c_content = c_info;
		count++;
		if (readline > 0)
		{
			exec(c_info, &stacked, count, opened_file);
		}
		free(c_info);
	}
	free_stacked(stacked);
	fclose(opened_file);
return (0);
}
