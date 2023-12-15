#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: the stack
 * Return: void
**/
void rel_stack(stack_t *stack)
{
	stack_t *follow;

	while (stack != NULL)
	{
		follow = stack->next;
		free(stack);
		stack = follow;
	}
}

/**
* length - length of stack
* @stack: pointer that point to stack
* Return: unsigned int
**/
unsigned int length(stack_t **stack)
{
	stack_t *present;
	unsigned int m = 0;

	present = *stack;
	while (present)
	{
		present = present->next;
		m++;
	}
	return (m);
}
