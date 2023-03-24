#include "monty.h"

/**
 * push_helper - helps push achieve its purpose
 * @line_num: file line number
 * Return: 1 or 0
 */

void push_helper(unsigned int line_num, stack_tt **stack)
{
	int i = 0;

	while (element[i] != '\0')
	{
		if (element[i] < '0' || element[i] > '9')
		{
			if (element[i] != '-')
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_num);
				free_stack(stack);
				exit(EXIT_FAILURE);
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

	if (element == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push_helper(line_num, stack);
	num = atoi(element);
	tmp = malloc(sizeof(stack_tt));
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
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
