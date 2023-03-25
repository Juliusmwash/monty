#include "monty.h"

/**
 * free_stack - frees the allocated memory
 * @stack: doubly linked list
 * Return: Nothing
 */

void free_stack(stack_tt **stack)
{
	stack_tt *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		*stack = (*stack)->next;
		free(tmp);
		tmp = *stack;
	}
}
