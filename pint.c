#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: doubly linked list stack representation
 * Return: nothing
 */

void pint(stack_tt **stack, unsigned int line_num)
{
	if (stack != NULL)
		printf("%d\n", (*stack)->n);
	(void)line_num;
}
