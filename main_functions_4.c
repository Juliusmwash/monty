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
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		_sub = (*stack)->next->n - (*stack)->n;
		pop(stack, line_num);
		(*stack)->n = _sub;
	}
}

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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = (*stack)->next;
		n = (*stack)->n;
		(*stack)->n = tmp->n;
		tmp->n = n;
	}
}
