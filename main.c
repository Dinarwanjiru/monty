#include "monty.h"
/**
* main - main function
* @argc: number of command line arguments
* @argv: list of command line arguments
* Return: EXIT_SUCCESS if no errors or EXIT_FAILURE
**/

int main(__attribute__((unused)) int argc, char const *argv[])
{
	FILE *file;
	char *buffe = NULL, *opcode, *n;
	size_t lol = 0;
	int line_number = 0;
	stack_t *stack = NULL, *present;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(1);
	}
	while ((getline(&buffe, &lol, file)) != -1)
	{
		line_number++;
		opcode = strtok(buffe, DELIMITER);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (!strcmp(opcode, "nop"))
			continue;
		else if (!strcmp(opcode, "push"))
		{
			n = strtok(NULL, DELIMITER);
			_push(&stack, n, line_number);
		}
		else
			_opcode(&stack, opcode, line_number);
	}
	fclose(file);
	free(buffe);
	while (stack != NULL)
	{
		present = stack;
		stack = stack->next;
		free(present);
	}
	return (0);
}
