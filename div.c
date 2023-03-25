#include "monty.h"

/**
 * stack_div - prints division error and exits with an error code
 * @line_num: file's line number
 * @stack: doubly linked list representation of the stack
 * Return: nothing;
 */

void stack_div(stack_tt **stack, unsigned int line_num)
{
	int _div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	_div = (*stack)->next->n / (*stack)->n;
	pop(stack, line_num);
	(*stack)->n = _div;
}