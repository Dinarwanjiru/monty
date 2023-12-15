#include "monty.h"

/**
 * _push - add element on top of stack
 * @stack: pointer to a pointer to the doubly linked list
 * @line_number: line where there is an error
 * @n: op_code
 * Return: void
*/
void _push(stack_t **stack, char *n, unsigned int line_number)
{
	stack_t *insert_t = NULL;
	int k;

	insert_t = malloc(sizeof(stack_t));
	if (insert_t == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (k = 0; n[k]; k++)
	{
		if (n[0] == '-' && k == 0)
			continue;
		if (n[k] < 48 || n[k] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	insert_t->n = atoi(n);
	insert_t->prev = NULL;
	insert_t->next = NULL;
	if (*stack != NULL)
	{
		insert_t->next = *stack;
		(*stack)->prev = insert_t;
	}
	*stack = insert_t;
}
/**
 * _pall - print stack's elements
 * @line_number: will not be used , we usse attribute not void
 * @stack: pointer to the head of the doubly linked list
 * Return: void
*/

void _pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *present = *stack;

	if (stack == NULL || *stack == NULL)
		return;
	while (present != NULL)
	{
		printf("%d\n", present->n);
		present = present->next;
	}
}

