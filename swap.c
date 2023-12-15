#include "monty.h"

/**
* _swap - swaps the value of the top two elements to the stack
* @stack: pointer that point to stack
* @line_number: line number of instruction
* Return: void, exit with -1 on failure
**/
void _swap(stack_t **stack, unsigned int line_number)
{
	int current;

	if (len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = current;
}
