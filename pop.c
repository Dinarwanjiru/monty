#include "monty.h"
/**
 * _pop - removes the last inserted element
 * @line_number: number of lines  in the file
 * @stack: pointer to the pointer to the head
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *end;

	if (stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = *end;
		*stack = (*stack)->next;
		free(end);
	}
}
