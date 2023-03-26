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

/**
 * status_check - checks for stack or queue mode
 * @op: linked list pointer to opcode
 * @status: mode switching variable
 * Return: nothing
 */

int status_check(instruction_t **op, int *status)
{
	if ((*op)->opcode != NULL)
	{
		if (strcmp((*op)->opcode, "queue") == 0)
		{
			*status = 1;
			return (1);
		}
		else if (strcmp((*op)->opcode, "stack") == 0)
		{
			*status = 0;
			return (1);
		}
	}
	return (0);
}
