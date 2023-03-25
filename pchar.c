#include "monty.h"

/**
 * pchar - prints ascii characters
 * @stack: doubly linked list representation of stack
 * @line_num: file's line number
 * Return: nothing
 */

void pchar(stack_tt **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n < 128)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
