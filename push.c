#include "monty.h"

/**
 * push_helper - helps push achieve its purpose
 * @stack: doubly linked list stack representation
 * @line_num: file line number
 * Return: 1 or 0
 */

void push_helper(unsigned int line_num, stack_tt **stack)
{
	int i = 0;

	while (str_int->element[i] != '\0')
	{
		if (str_int->element[i] < '0' || str_int->element[i] > '9')
		{
			if (str_int->element[i] != '-')
			{
				free_stack(stack);
				none_integer_error(line_num);
			}
		}

		i++;
	}
}

/**
 * push - adds element to stack
 * @stack: doubly linked list representing stack
 * @line_num: line number
 * Return: Nothing
 */

void push(stack_tt **stack, unsigned int line_num)
{
	stack_tt *tmp;
	int num;

	if (str_int->element == NULL)
	{
		free_stack(stack);
		none_integer_error(line_num);
	}
	push_helper(line_num, stack);
	num = atoi(str_int->element);
	tmp = malloc(sizeof(stack_tt));
	if (tmp == NULL)
	{
		free_stack(stack);
		malloc_error();
	}
	tmp->n = num;
	tmp->prev = NULL;
	if (*stack == NULL)
	{
		*stack = tmp;
		(*stack)->next = NULL;
	}
	else
	{
		(*stack)->prev = tmp;
		tmp->next = *stack;
		*stack = tmp;
	}
}
