#include "monty.h"

/**
 * sub - subtracts the top element from the second top elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void sub(stack_tt **stack, unsigned int line_num)
{
	int _sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		if (*stack != NULL)
			free_stack(stack);
		sub_error(line_num);
	}
	else
	{
		_sub = (*stack)->next->n - (*stack)->n;
		pop(stack, line_num);
		(*stack)->n = _sub;
	}
}
