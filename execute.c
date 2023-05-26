#include "monty.h"

/**
 * do_operation - Executes the operation associated with the opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_operation(stack_t **stack, unsigned int line_number)
{
	int ai = 0;

	instruction_t ops[] = {
		{"push", do_push},
		{"pall", do_pall},
		{"pint", do_pint},
		{"pop", do_pop},
		{"swap", do_swap},
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

	while (ops[ai].opcode)
	{
		if (strcmp(variable.optokens[0], ops[ai].opcode) == 0)
		{
			ops[ai].f(stack, line_number);
			return;
		}
		ai++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
			variable.optokens[0]);
	exit(EXIT_FAILURE);
}
