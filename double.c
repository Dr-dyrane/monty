#include "monty.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 * @stack: Double pointer to the head of the list
 * @n: Value to be stored in the new node
 *
 * Return: Address of the newly added node, or NULL on failure
 */
stack_t *add_dnodeint_end(stack_t **stack, const int n)
{
	stack_t *new_node = NULL;
	stack_t *temp;

	if (!stack)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_variable();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (!*stack)
	{
		new_node->prev = NULL;
		*stack = new_node;
		return (new_node);
	}

	temp = *stack;
	while (temp->next)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list
 * @stack: Double pointer to the head of the list
 * @n: Value to be stored in the new node
 *
 * Return: Address of the newly added node, or NULL on failure
 */
stack_t *add_dnodeint(stack_t **stack, const int n)
{
	stack_t *new_node = NULL;

	if (!stack)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_variable();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (!*stack)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
	return (new_node);
}

/**
 * free_dlistint - Frees a doubly linked list
 * @stack: Pointer to the head of the list
 */
void free_dlistint(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next = NULL;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
