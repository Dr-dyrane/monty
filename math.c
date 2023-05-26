#include "monty.h"

/**
 * do_add - adds the first two values in the stack,
 * stores the result in the second node of the stack, and then pops the first.
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_add(stack_t **stack, unsigned int line_number)
{
	stack_t *node_0 = *stack, *node_1;

	if (!stack || !node_0)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1 = node_0->next;
	if (!node_1)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1->n += node_0->n;
	*stack = node_1;
	node_1->prev = NULL;
	do_pop(stack, line_number);
}

/**
 * do_sub - subtracts the top node of the stack from the second node
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node_0 = *stack, *node_1;

	if (!stack || !node_0)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1 = node_0->next;
	if (!node_1)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1->n -= node_0->n;
	*stack = node_1;
	node_1->prev = NULL;
	do_pop(stack, line_number);
}

/**
 * do_div - divides the second node of the stack by the first node of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_div(stack_t **stack, unsigned int line_number)
{
	stack_t *node_0 = *stack, *node_1;

	if (!stack || !node_0)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1 = node_0->next;
	if (!node_1)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	if (node_0->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1->n /= node_0->n;
	*stack = node_1;
	node_1->prev = NULL;
	do_pop(stack, line_number);
}

/**
 * do_mul - multiplies the second and first nodes of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node_0 = *stack, *node_1;

	if (!stack || !node_0)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1 = node_0->next;
	if (!node_1)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1->n *= node_0->n;
	*stack = node_1;
	node_1->prev = NULL;
	do_pop(stack, line_number);
}

/**
 * do_mod - the remainder of the division of the second node by the first
 * element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node_0 = *stack, *node_1;

	if (!stack || !node_0)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1 = node_0->next;
	if (!node_1)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	if (node_0->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_variable();
		exit(EXIT_FAILURE);
	}
	node_1->n %= node_0->n;
	*stack = node_1;
	node_1->prev = NULL;
	do_pop(stack, line_number);
}
