#include "monty.h"

/**
 * mul - adds the top two elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void mul(stack_tt **stack, unsigned int line_num)
{
	int _mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		if (*stack != NULL)
			free_stack(stack);
		add_error(line_num);
	}
	else
	{
		_mul = (*stack)->n * (*stack)->next->n;
		pop(stack, line_num);
		(*stack)->n = _mul;
	}
}
