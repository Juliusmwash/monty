#include "monty.h"
#define MAX_LINE_LENGTH 100
element_t *str_int;

/**
 * main_helper_helper - function helping main_helper accomplish its task
 * @op: linked list containing opcode and function pointer
 * @sk: doubly linked list representing stack
 * @l: line number
 * Return: Nothing
 */

int main_helper_helper(instruction_t **op, stack_tt **sk, unsigned int *l)
{
	int check;

	check = 0;
	if (strcmp((*op)->opcode, "sub") == 0)
	{
		(*op)->f = &sub;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "pint") == 0)
	{
		(*op)->f = &pint;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "pop") == 0)
	{
		(*op)->f = &pop;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "swap") == 0)
	{
		(*op)->f = &swap;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "add") == 0)
	{
		(*op)->f = &add;
		(*op)->f(sk, *l);
	}
	else
		if (strcmp((*op)->opcode, "nop") != 0)
			check = 1;
	return (check);
}

/**
 * main_hlper - function helping main function do its assigned task
 * @op: linked list containing opcode and function pointer
 * @sk: doubly linked list representation of stack
 * @l: line number
 * @li: array receiving every character in the line
 * Return: Nothing
 */

void main_hlper(instruction_t **op, char li[], stack_tt **sk, unsigned int *l)
{
	int check;

	(*op)->opcode = strtok(li, " \n\t\a\b");
	if ((*op)->opcode != NULL)
		str_int->element = strtok(NULL, " \n\t\a\b");
	/* Handle some operation. Others handled on another function */
	check = 0;
	if (*op != NULL)
	{
		if (strcmp((*op)->opcode, "push") == 0)
		{
			(*op)->f = &push;
			(*op)->f(sk, *l);
			check = 1;
		}
		if (strcmp((*op)->opcode, "pall") == 0)
		{
			(*op)->f = &pall;
			(*op)->f(sk, *l);
			check = 1;
		}
	}
	if (check == 0 && *op != NULL)
		check = main_helper_helper(op, sk, l);
	else
		check = 0;
	if ((*op)->opcode != NULL && check)
	{
		free_stack(sk);
		free(*op);
		unknown_instruction_error(op, *l);
	}
	free(*op);
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

	str_int = malloc(sizeof(element_t));
	if (str_int == NULL)
		malloc_error();
	if (argc < 2)
		no_file_error();
	textfile = fopen(argv[1], "r");
	if (textfile == NULL)
		file_open_error(argv[1]);
	while (result = fgets(line, MAX_LINE_LENGTH, textfile), result != NULL)
	{
		l++;
		oppexec = malloc(sizeof(instruction_t));
		if (oppexec == NULL)
			malloc_error();
		main_hlper(&oppexec, line, &stack_data, &l);
	}
	fclose(textfile);
	free_stack(&stack_data);
	free(str_int);
	exit(0);
}
