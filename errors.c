#include "monty.h"

/**
 * malloc_error - prints an error message and exits with an error code
 * Return: nothing
 */

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * file_open_error - prints an error when file opening is not successful
 * @str: file which had to be opened
 * Return: nothing
 */

void file_open_error(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}

/**
 * no_file_error - prints an error message and exits with an error code
 * Return: nothing
 */

void no_file_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * none_integer_error - prints an error message and exits with an error code
 * @line_num: line number of the file
 * Return: nothing
 */

void none_integer_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * pint_error - prints an error message and exits with an error code
 * @line_num: file's line number
 * Return: nothing;
 */

void pint_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
	exit(EXIT_FAILURE);
}
