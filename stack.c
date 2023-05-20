#include "monty.h"

/**
 * do_push - adds a value to the top of a stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!variable.optokens[1] || !is_integer(variable.optokens[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(variable.optokens[1]);
	new->prev = NULL;

	if (!*stack)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * do_pop - removes a value from the top of a stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(current);
}

/**
 * do_swap - swaps the first two values in the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node_0, *node_1;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_0 = *stack;
	node_1 = node_0->next;

	node_0->prev = node_1;
	node_0->next = node_1->next;
	node_1->prev = NULL;
	node_1->next = node_0;

	if (node_0->next)
		node_0->next->prev = node_0;

	*stack = node_1;
}

/**
 * do_rotl - rotates the stack to the left
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *tail;

	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	current = *stack;
	tail = current;

	while (current->next)
		current = current->next;

	current->next = tail;
	tail->prev = current;
	*stack = tail->next;
	(*stack)->prev = NULL;
	tail->next = NULL;
}

/**
 * do_rotr - rotates the stack to the right
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number being processed
 */
void do_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *current;

	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	current = *stack;

	while (current->next)
		current = current->next;

	head = current;
	head->prev->next = NULL;
	head->prev = NULL;
	current = *stack;
	head->next = current;
	current->prev = head;
	*stack = head;
}
