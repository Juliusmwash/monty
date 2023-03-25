#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void rotl(stack_tt **stack, unsigned int line_num)
{
	stack_tt *tmp, *temp;

	temp = malloc(sizeof(stack_tt));
	if (temp == NULL)
	{
		free_stack(stack);
		free(str_int);
		malloc_error();
	}
	tmp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	temp->n = (*stack)->n;
	temp->next = NULL;
	temp->prev = tmp;
	tmp->next = temp;
	pop(stack, line_num);
	(void) line_num;
}
