#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void rotr(stack_tt **stack, unsigned int line_num)
{
	stack_tt *tmp, *temp;

	tmp = *stack;
	temp = malloc(sizeof(stack_tt));
	if (temp == NULL)
	{
		free_stack(stack);
		free(str_int);
		malloc_error();
	}
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free(temp);
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	temp->n = tmp->n;
	temp->prev = NULL;
	(*stack)->prev = temp;
	temp->next = *stack;
	tmp->prev->next = NULL;
	free(tmp);
	*stack = temp;
	(void) line_num;
}
