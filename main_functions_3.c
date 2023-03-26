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
	{
		free(temp);
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	temp->n = (*stack)->n;
	temp->next = NULL;
	temp->prev = tmp;
	tmp->next = temp;
	pop(stack, line_num);
	(void) line_num;
}

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
