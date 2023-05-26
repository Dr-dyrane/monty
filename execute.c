#include "monty.h"

/**
 * do_operation - Executes the operation associated with the opcode
 * @op_code: opcode passed in file stream
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void (*do_operation(char *op_code))(stack_t **stack, unsigned int line_number)
{
	int ai = 0;

	instruction_t opcodes[] = {
		{"push", do_push},
		{"pall", do_pall},
		{"pint", do_pint},
		{"pop", do_pop},
		{"swap", do_swap},
		{"queue", do_queue},
		{"stack", do_stack},
		{"add", do_add},
		{"nop", do_nop},
		{"sub", do_sub},
		{"div", do_div},
		{"mul", do_mul},
		{"mod", do_mod},
		{"pchar", do_pchar},
		{"pstr", do_pstr},
		{"rotl", do_rotl},
		{"rotr", do_rotr},
		{NULL, NULL}};

	while (opcodes[ai].opcode)
	{
		if (_strcmp(opcodes[ai].opcode, op_code) == 0)
			break;
		ai++;
	}

	return (opcodes[ai].f);
}

/**
 * do_stack - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the head of the linked list
 * @line_number: Line number being processed
 * Return: No return
 *
 * Description: Updates the `is_stack` field in the global `data_t` struct
 *             to indicate that the interpreter operates as a stack (LIFO).
 */
void do_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	variable.is_stack = 1;
}

/**
 * do_queue - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the linked list
 * @line_number: Line number being processed
 * Return: No return
 *
 * Description: Updates the `is_stack` field in the global `data_t` struct
 *             to indicate that the interpreter operates as a queue (FIFO).
 */
void do_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	variable.is_stack = 0;
}
