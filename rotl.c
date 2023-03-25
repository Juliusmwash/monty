#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void rotl(stack_tt **stack, unsigned int line_num)
{
	stack_tt *tmp;
	int n;

	tmp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	n = (*stack)->n;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*stack)->n = tmp->n;
	tmp->n = n;
	(void) line_num;
}
