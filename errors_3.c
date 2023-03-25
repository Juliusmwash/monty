#include "monty.h"

/**
 * mul_error - subtracts two elements
 * @line_num: file's line number
 * Return: nothing
 */

void mul_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}
