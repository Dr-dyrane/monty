#include "monty.h"

/**
 * do_pall - prints each stack element on a new line
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}

/**
 * do_pint - prints the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!*stack || !stack)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}

	printf("%i\n", current->n);
}

/**
 * do_pchar - prints the character at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!stack || !current)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}

	if (current->n < 32 || current->n > 126)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current->n);
}

/**
 * do_pstr - prints the string starting at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		if (current->n < 32 || current->n > 126)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

/**
 * do_nop - does nothing
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
