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
void push(stack_tt **, unsigned int);
void pall(stack_tt **, unsigned int);
void main_helper_helper(instruction_t **op, stack_tt **sk, unsigned int *l);
void main_helper(instruction_t **op, char li[], stack_tt **sk, unsigned int *l);
void push_helper(unsigned int line_num, stack_tt **stack);
extern char *element;
void free_stack(stack_tt **stack);

#endif /* MONTY_H */
