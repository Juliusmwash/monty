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
