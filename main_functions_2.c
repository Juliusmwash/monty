#include "monty.h"

/**
 * pall - prints all the elements in the stack from the top
 * @stack: doubly linked list representation of the stack
 * @line: number of the line in the file
 * Return: Nothing
 */

void pall(stack_tt **stack, __attribute__((unused)) unsigned int line)
{
	stack_tt *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pchar - prints ascii characters
 * @stack: doubly linked list representation of stack
 * @line_num: file's line number
 * Return: nothing
 */

void pchar(stack_tt **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n < 128)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: doubly linked list stack representation
 * @line_num: file's line number
 * Return: nothing
 */

void pint(stack_tt **stack, unsigned int line_num)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		free_stack(stack);
		pint_error(line_num);
	}
}

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
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints ascii characters
 * @stack: doubly linked list representation of stack
 * @line_num: file's line number
 * Return: nothing
 */

void pstr(stack_tt **stack, unsigned int line_num)
{
	stack_tt *tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		putchar(10);
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->n >= 0 && tmp->n < 128)
		{
			if (tmp->n != 0)
				printf("%c", tmp->n);
			else
				break;
		}
		else
			break;
		tmp = tmp->next;
	}
	putchar(10);
	(void) line_num;
}
