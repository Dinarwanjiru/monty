#include "monty.h"


/**
* _opcode - find operation code
* @stack: stack pointer
* @opcode: user input opcode
* @line_number: line numbef
* Return: Always 1 (Success) or stderr
**/
int _opcode(stack_t **stack, char *opcode, int line_number)
{
	instruction_t opcodes[] = {
		{"pall", _pall},
		{"pop", _pop},
		{"swap", _swap},
		{"pint", _pint},
		{NULL, NULL}
	};
	int s;

	for (s = 0; opcod[s].opcode; s++)
	{
		if (strcmp(opcode, opcod[s].opcode) == 0)
		{
			(opcod[s].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
