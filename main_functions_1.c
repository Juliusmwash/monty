#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void add(stack_tt **stack, unsigned int line_num)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		if (*stack != NULL)
			free_stack(stack);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*stack)->n + (*stack)->next->n;
		pop(stack, line_num);
		(*stack)->n = sum;
	}
}

/**
 * cmnt - check for comment validity
 * @arr: array containing characters
 * Return: 0 if no comment or 1 if a valid comment
 */

int cmnt(char arr[])
{
	int len, i;

	len = strlen(arr);
	for (i = 0; i < len; i++)
	{
		if (arr[i] == '#')
			return (1);
		else if (arr[i] != ' ')
			return (0);
	}
	return (0);
}

/**
 * stack_div - prints division error and exits with an error code
 * @line_num: file's line number
 * @stack: doubly linked list representation of the stack
 * Return: nothing;
 */

void stack_div(stack_tt **stack, unsigned int line_num)
{
	int _div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	_div = (*stack)->next->n / (*stack)->n;
	pop(stack, line_num);
	(*stack)->n = _div;
}

/**
 * stack_mod- prints division error and exits with an error code
 * @line_num: file's line number
 * @stack: doubly linked list representation of the stack
 * Return: nothing;
 */

void stack_mod(stack_tt **stack, unsigned int line_num)
{
	int _mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	_mod = (*stack)->next->n % (*stack)->n;
	pop(stack, line_num);
	(*stack)->n = _mod;
}

/**
 * mul - adds the top two elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_num: file's line number
 * Return: nothing
 */

void mul(stack_tt **stack, unsigned int line_num)
{
	int _mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		if (*stack != NULL)
			free_stack(stack);
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		_mul = (*stack)->n * (*stack)->next->n;
		pop(stack, line_num);
		(*stack)->n = _mul;
	}
}
