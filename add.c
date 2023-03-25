#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void add(stack_tt **stack, unsigned int line_num)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		if (*stack != NULL)
			free_stack(stack);
		add_error(line_num);
	}
	else
	{
		sum = (*stack)->n + (*stack)->next->n;
		pop(stack, line_num);
		(*stack)->n = sum;
	}
}
