#include "monty.h"

/**
 * my_calloc - Allocates memory for an array of elements and initializes to 0
 * @elements: Number of elements
 * @size: Size of each element
 *
 * Return: Pointer to the allocated memory, or NULL on failure
 */
void *my_calloc(unsigned int elements, unsigned int size)
{
	void *pointer = NULL;
	unsigned int total_size = elements * size;
	unsigned int ai;
	unsigned char *byte_ptr;

	if (elements == 0 || size == 0)
		return (NULL);

	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);

	byte_ptr = (unsigned char *) pointer;
	ai = 0;
	while (ai < total_size)
	{
		byte_ptr[ai] = 0;
		ai++;
	}

	return (pointer);
}

/**
 * my_realloc - Reallocates a block of memory with a new size
 * @pointer: Pointer to the previously allocated memory
 * @old_size: Old size of the memory block
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure
 */
void *my_realloc(void *pointer, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;
	unsigned int ai;
	unsigned char *src;
	unsigned char *dest;

	if (new_size == old_size)
		return (pointer);

	if (!pointer)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
	}
	else if (new_size == 0)
	{
		free(pointer);
		return (NULL);
	}
	else
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);

		src = (unsigned char *) pointer;
		dest = (unsigned char *) new_ptr;
		ai = 0;
		while (ai < new_size && ai < old_size)
		{
			dest[ai] = src[ai];
			ai++;
		}

		free(pointer);
	}

	return (new_ptr);
}
