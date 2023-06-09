#include "monty.h"
#define MAX_LINE_LENGTH 100
element_t *str_int;

/**
 * main_hp_hp_hp_helper - function helping main_helper accomplish its task
 * @op: linked list containing opcode and function pointer
 * @sk: doubly linked list representing stack
 * @l: line number
 * Return: Nothing
 */

int main_hp_hp_hp_helper(instruction_t **op, stack_tt **sk, unsigned int *l)
{
	int check;

	check = 0;
	if (strcmp((*op)->opcode, "rotr") == 0)
	{
		(*op)->f = &rotr;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "sub") == 0)
	{
		(*op)->f = &sub;
		(*op)->f(sk, *l);
	}
	else
		if (strcmp((*op)->opcode, "nop") != 0)
			check = 1;
	return (check);
}

/**
 * main_hlp_hlp_helper - function helping main_helper accomplish its task
 * @op: linked list containing opcode and function pointer
 * @sk: doubly linked list representing stack
 * @l: line number
 * Return: Nothing
 */

int main_hlp_hlp_helper(instruction_t **op, stack_tt **sk, unsigned int *l)
{
	int check;

	check = 0;
	if (strcmp((*op)->opcode, "mul") == 0)
	{
		(*op)->f = &mul;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "mod") == 0)
	{
		(*op)->f = &stack_mod;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "pchar") == 0)
	{
		(*op)->f = &pchar;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "pstr") == 0)
	{
		(*op)->f = &pstr;
		(*op)->f(sk, *l);
	}
	else if (strcmp((*op)->opcode, "rotl") == 0)
	{
		(*op)->f = &rotl;
		(*op)->f(sk, *l);
	}
	else
		check = main_hp_hp_hp_helper(op, sk, l);
	return (check);
}

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
	if (strcmp((*op)->opcode, "pall") == 0)
	{
		(*op)->f = &pall;
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
	else if (strcmp((*op)->opcode, "div") == 0)
	{
		(*op)->f = &stack_div;
		(*op)->f(sk, *l);
	}
	else
		check = main_hlp_hlp_helper(op, sk, l);
	return (check);
}

/**
 * _h - function helping main function do its assigned task
 * @op: linked list containing opcode and function pointer
 * @sk: doubly linked list representation of stack
 * @l: line number
 * @t: file pointer
 * @li: array receiving every character in the line
 * Return: Nothing
 */

/* Forced to change 'main-helper' to '_h' due to line length */
void _h(instruction_t **op, char li[], stack_tt **sk, unsigned int *l, FILE *t)
{
	int check;
	static int status;

	(*op)->opcode = strtok(li, " \n\t\a\b");
	if ((*op)->opcode != NULL)
		str_int->element = strtok(NULL, " \n\t\a\b");
	check = status_check(op, &status);
	if (check)
	{
		free(*op);
		return;
	}
	check = 0;
	if ((*op)->opcode != NULL)
	{
		if (strcmp((*op)->opcode, "push") == 0)
		{
			if (status)
			{
				(*op)->f = &push_queue;
				(*op)->f(sk, *l);
			}
			else
			{
				(*op)->f = &push;
				(*op)->f(sk, *l);
			}
			check = 1;
		}
	}
	if (check == 0 && (*op)->opcode != NULL)
		check = main_helper_helper(op, sk, l);
	else
		check = 0;
	if ((*op)->opcode != NULL && check)
		f(op, sk, t, l);
	free(*op);
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
	int check;

	str_int = malloc(sizeof(element_t));
	if (str_int == NULL)
		malloc_error();
	if (argc < 2 || argc > 2)
	{
		free(str_int);
		no_file_error();
	}
	textfile = fopen(argv[1], "r");
	if (textfile == NULL)
		file_open_error(argv[1]);
	while (result = fgets(line, MAX_LINE_LENGTH, textfile), result != NULL)
	{
		l++;
		check = cmnt(line);
		if (!check)
		{
			oppexec = malloc(sizeof(instruction_t));
			if (oppexec == NULL)
			{
				free_stack(&stack_data);
				free(str_int);
				fclose(textfile);
				malloc_error();
			}
			_h(&oppexec, line, &stack_data, &l, textfile);
		}
	}
	fclose(textfile);
	free_stack(&stack_data);
	free(str_int);
	exit(0);
}
