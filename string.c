#include "monty.h"

/**
 * is_integer - checks if a string can be converted to an integer
 * @s: string to be checked
 * Return: 0 if string can be converted to integer, or 1 if not.
 */
int is_integer(char *s)
{
	int ai = 0;

	if (s[0] == '-')
		ai++;
	while (s[ai] != '\0')
	{
		if (isdigit(s[ai]) == 0)
			return (1);
		ai++;
	}
	return (0);
}

/**
 * split_string - splits a string
 * @line: string to be splitted
 * @delim: delimiter
 * Return: pointer to array of arrays.
 */
char **split_string(char *line, char *delim)
{
	char **tokens, *token;
	int ai = 0;

	tokens = malloc(sizeof(char) * 1024);
	if (!tokens)
		return (NULL);
	token = strtok(line, delim);
	while (token)
	{
		tokens[ai] = token;
		token = strtok(NULL, delim);
		ai++;
	}
	tokens[ai] = NULL;
	return (tokens);
}
