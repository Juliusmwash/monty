#include "monty.h"

/**
 * pop - removes the top element from the stack
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void pop(stack_tt **stack, unsigned int line_num)
{
	stack_tt *tmp;

	tmp = *stack;
	if (tmp != NULL)
	{
		if ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			free(tmp);
		}
		else
		{
			free(*stack);
			*stack = NULL;
		}
	}
	else
		pop_error(line_num);
}
