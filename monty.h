#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO in the Monty project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Structure for storing opcode and its corresponding function
 * for stack, queues, LIFO, FIFO in the Monty project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data - Stores Monty bytecode data
 * @optokens: Array of opcode lines
 *
 * Description: Structure for storing Monty bytecode data, specifically the
 *              lines of opcode, to be used in multiple functions.
 */
typedef struct data_s
{
	char **optokens;
} data_t;

/* Global variable used to store the tokenized opcode lines */
extern data_t variable;

/**
 * do_operation - Executes the operation associated with the opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_operation(stack_t **stack, unsigned int line_number);

/* Stack manipulation */
void do_push(stack_t **stack, unsigned int line_number);
void do_pop(stack_t **stack, unsigned int line_number);
void do_swap(stack_t **stack, unsigned int line_number);
void do_rotl(stack_t **stack, unsigned int line_number);
void do_rotr(stack_t **stack, unsigned int line_number);

/* Printing functions */
void do_pall(stack_t **stack, unsigned int line_number);
void do_pint(stack_t **stack, unsigned int line_number);
void do_pchar(stack_t **stack, unsigned int line_number);
void do_pstr(stack_t **stack, unsigned int line_number);
void do_nop(stack_t **stack, unsigned int line_number);

/* Arithmetic operations */
void do_add(stack_t **stack, unsigned int line_number);
void do_sub(stack_t **stack, unsigned int line_number);
void do_div(stack_t **stack, unsigned int line_number);
void do_mul(stack_t **stack, unsigned int line_number);
void do_mod(stack_t **stack, unsigned int line_number);

/* String functions */
int is_integer(char *s);
char **split_string(char *line, char *delim);

/* Monty interpreter */
void run_monty(FILE *stream);

#endif /* MONTY_H */
