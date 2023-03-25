#include "monty.h"

/**
 * pop_error - displays pop error and exits with an error code
 * @line_num: file's line number
 * Return: nothing
 */

void pop_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * swap_error - swaps two elements of the stack from the top
 * @line_num: file's line number
 * Return: nothing
 */

void swap_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}
