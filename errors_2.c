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

/**
 * add_error - prints an error and exits with an error code
 * @line_num: file's line number
 * Return: nothing
 */

void add_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * unknown_instruction_error - prints the error message and exits
 * @op: linked list containing opcode and function pointer
 * @l: file's line number
 * Return: nothing
 */

void unknown_instruction_error(instruction_t **op, unsigned int l)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", l, (*op)->opcode);
	free(*op);
	exit(EXIT_FAILURE);
}

/**
 * sub - subtracts two elements
 * @stack: doubly linked list representation of stack
 * @line_num: file's line number
 * Return: nothing
 */

void sub_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}
