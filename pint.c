#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: doubly linked list stack representation
 * @line_num: file's line number
 * Return: nothing
 */

void pint(stack_tt **stack, unsigned int line_num)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		free_stack(stack);
		pint_error(line_num);
	}
}
