#include "monty.h"

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
		putchar(10);
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
