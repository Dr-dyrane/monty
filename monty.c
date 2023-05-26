#include "monty.h"

data_t variable;

/**
 * free_variable - Frees the global variable and associated resources
 *
 * Description: Frees the doubly linked list, buffer, & closes the file stream
 *             associated with the global variable 'variable' of type 'data_t'.
 *             This function should be called before exiting the program.
 */
void free_variable(void)
{
	free_dlistint(variable.stack);
	free(variable.buffer);
	fclose(variable.stream);
}

/**
 * initialize_variable - Initializes the global variable
 *
 * @stream: File descriptor
 * Return: No return
 */
void initialize_variable(FILE *stream)
{
	variable.is_stack = 1;
	variable.line_number = 1;
	variable.optokens = NULL;
	variable.stack = NULL;
	variable.stream = stream;
	variable.buffer = NULL;
}

/**
 * run_monty - Read and execute Monty bytecode instructions
 * @stream: Pointer to the file stream
 *
 * Return: void
 */
void run_monty(FILE *stream)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *optokens[2] = {NULL, NULL}, *delim = " \t\n";
	size_t buffer_size = 256;
	ssize_t line_read = 0;

	initialize_variable(stream);
	line_read = getline(&variable.buffer, &buffer_size, stream);

	while (line_read != -1)
	{
		optokens[0] = split_string(variable.buffer, delim);
		if (optokens[0] && optokens[0][0] != '#')
		{
			f = do_operation(optokens[0]);
			if (f == NULL)
			{
				dprintf(2, "L%u: ", variable.line_number);
				dprintf(2, "unknown instruction %s\n", optokens[0]);
				free_variable();
				exit(EXIT_FAILURE);
			}
			variable.optokens = split_string(NULL, delim);
			f(&variable.stack, variable.line_number);
		}
		line_read = getline(&variable.buffer, &buffer_size, stream);
	}

	free_variable();
}

/**
 * main - Interprets Monty ByteCodes files
 * @argc: Number of arguments
 * @argv: Pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *stream;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (!stream)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	run_monty(stream);

	return (0);
}
