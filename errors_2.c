#include "monty.h"

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
