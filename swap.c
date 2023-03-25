#include "monty.h"

/**
 * swap - swaps two elements from the top of the stack
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void swap(stack_tt **stack, unsigned int line_num)
{
	stack_tt *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		if (*stack != NULL)
			free(*stack);
		swap_error(line_num);
	}
	else
	{
		tmp = (*stack)->next;
		n = (*stack)->n;
		(*stack)->n = tmp->n;
		tmp->n = n;
	}
}
