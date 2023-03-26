#include "monty.h"

/**
 * push_queue - adds element to stack
 * @stack: doubly linked list representing stack
 * @line_num: line number
 * Return: Nothing
 */

void push_queue(stack_tt **stack, unsigned int line_num)
{
	stack_tt *tmp, *temp;

	if (str_int->element == NULL)
	{
		free_stack(stack);
		none_integer_error(line_num);
	}
	push_helper(line_num, stack);
	tmp = malloc(sizeof(stack_tt));
	if (tmp == NULL)
	{
		free_stack(stack);
		free(str_int);
		malloc_error();
	}
	tmp->next = NULL;
	tmp->n = atoi(str_int->element);
	if (*stack == NULL)
	{
		tmp->prev = NULL;
		*stack = tmp;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		tmp->prev = temp;
		temp->next = tmp;
	}
}
