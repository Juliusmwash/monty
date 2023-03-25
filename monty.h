#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_tt;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_tt **stack, unsigned int line_number);
} instruction_t;

/**
 * struct element_s - global variable
 * @element: string
 *
 * Description: string to be converted to integer
 */

typedef struct element_s
{
	char *element;
} element_t;

/* GLOBAL VARIABLE */
extern element_t *str_int;

/* MAIN FUNCTIONS */
void push(stack_tt **, unsigned int);
void pall(stack_tt **, unsigned int);
void pint(stack_tt **, unsigned int);
void pop(stack_tt **, unsigned int);
void swap(stack_tt **, unsigned int);
void add(stack_tt **, unsigned int);
void sub(stack_tt **, unsigned int);
void stack_div(stack_tt **, unsigned int);

/* HELPER FUNCTIONS */
int main_helper_helper(instruction_t **op, stack_tt **sk, unsigned int *l);
void main_hlper(instruction_t **op, char li[], stack_tt **sk, unsigned int *l);
void push_helper(unsigned int line_num, stack_tt **stack);

/* FREE MEMORY FUNCTIONS */
void free_stack(stack_tt **stack);

/* ERRORS */
void malloc_error(void);
void file_open_error(char *);
void no_file_error(void);
void none_integer_error(unsigned int);
void pint_error(unsigned int);
void pop_error(unsigned int);
void swap_error(unsigned int);
void add_error(unsigned int);
void unknown_instruction_error(instruction_t **, unsigned int);
void sub_error(unsigned int);

#endif /* MONTY_H */
