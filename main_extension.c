#include "monty.h"

/**
 * f - function used by main to free all memory
 * @p: linked list containing opcode
 * @sk: doubly linked list stack representation
 * @t: file pointer for reading file
 * @l: file's line number
 * Return: nothing
 */

void f(instruction_t **p, stack_tt **sk, FILE *t, unsigned int *l)
{
	free_stack(sk);
	free(str_int);
	fclose(t);
	unknown_instruction_error(p, *l);
}
