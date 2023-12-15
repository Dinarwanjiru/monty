#include "monty.h"

/**
 * _add -  adds the first two integers in the stack
 * stack: stack
 * @line_count: number of lines
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_count)
{
	int fin;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	fin = ((*stack)->next->n) + ((*stack)->n);
	_pop(stack, line_count);
	(*stack)->n = fin;
}
