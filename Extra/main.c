#include "monty.h"
#define MAX_LINE_LENGTH 100
char *element = NULL;

/**
 * main_helper_helper - function helping main_helper accomplish its task
 * @op: linked list containing opcode and function pointer
 * @sk: doubly linked list representing stack
 * @l: line number
 * Return: Nothing
 */

void main_helper_helper(instruction_t **op, stack_tt **sk, unsigned int *l)
{
	if (strcmp((*op)->opcode, "push") == 0)
	{
		(*op)->f = &push;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "pall") == 0)
	{
		(*op)->f = &pall;
		(*op)->f(sk, *l);
	}
}

/**
 * main_helper - function helping main function do its assigned task
 * @op: linked list containing opcode and function pointer
 * @sk: doubly linked list representation of stack
 * @l: line number
 * @li: array receiving every character in the line
 * Return: Nothing
 */

void main_helper(instruction_t **op, char li[], stack_tt **sk, unsigned int *l)
{
	char *array[5] = {"push", "pall"};
	int i, check;

	(*op)->opcode = strtok(li, " \n");
	if ((*op)->opcode != NULL)
		element = strtok(NULL, " \n");
	check = 0;
	for (i = 0; i < 2; i++)
	{
		if ((*op)->opcode != NULL)
		{
			if (strcmp((*op)->opcode, array[i]) == 0)
			{
			check = 1;
			main_helper_helper(op, sk, l);
			break;
			}
			else
			check = 0;
		}
	}
	if ((*op)->opcode != NULL && check == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", *l, (*op)->opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - frees the allocated memory
 * @stack: doubly linked list
 * Return: Nothing
 */

void free_stack(stack_tt **stack)
{
	stack_tt *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		*stack = (*stack)->next;
		free(tmp);
		tmp = *stack;
	}
}
/**
 * main - driver program
 * @argc: count of arguments in the argv array
 * @argv: array of arguments
 * Return: Nothing
 */

int main(int argc, char *argv[])
{
	instruction_t *oppexec;
	stack_tt *stack_data = NULL;
	FILE *textfile;
	char line[MAX_LINE_LENGTH], *result;
	unsigned int l = 0;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	textfile = fopen(argv[1], "r");
	if (textfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (result = fgets(line, MAX_LINE_LENGTH, textfile), result != NULL)
	{
		l++;
		main_helper(&oppexec, line, &stack_data, &l);
	}
	free_stack(&stack_data);
	return (0);
}
