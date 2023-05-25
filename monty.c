#include "monty.h"

/**
 * variable - Global variable used to store the tokenized opcode lines
 */
data_t variable;

/**
 * run_monty - Read and execute Monty bytecode instructions
 * @stream: Pointer to the file stream
 *
 * Return: void
 */
void run_monty(FILE *stream)
{
	unsigned int line_number = 0;
	char *buffer = NULL, *delim = " \n";
	size_t buffer_size;
	stack_t *stack = NULL, *temp;

	while (getline(&buffer, &buffer_size, stream) != -1)
	{
		line_number++;
		variable.optokens = split_string(buffer, delim);
		if (variable.optokens[0])
		{
			if (variable.optokens[0][0] == '#')
			{
				free(variable.optokens);
				continue;
			}
			else
				do_operation(&stack, line_number);
			free(variable.optokens);
		}
		else
		{
			free(variable.optokens);
			continue;
		}
	}
	free(buffer);
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
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

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	run_monty(stream);

	fclose(stream);
	return (0);
}
