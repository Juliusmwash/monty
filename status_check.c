#include "monty.h"

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
