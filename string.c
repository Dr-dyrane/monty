#include "monty.h"

/**
 * split_string - Function that splits a string into tokens based on delimiters
 * @line: String to be split
 * @delim: Delimiters
 * Return: Pointer to the first token
 */
char *split_string(char *line, char *delim)
{
	static char *last_token;
	int ai = 0, ja = 0;

	if (!line)
		line = last_token;
	while (line[ai] != '\0')
	{
		if (!my_strchr(delim, line[ai]) && line[ai + 1] == '\0')
		{
			last_token = line + ai + 1;
			*last_token = '\0';
			line = line + ja;
			return (line);
		}
		else if (!my_strchr(delim, line[ai]) && my_strchr(delim, line[ai + 1]))
		{
			last_token = line + ai + 1;
			*last_token = '\0';
			last_token++;
			line = line + ja;
			return (line);
		}
		else if (my_strchr(delim, line[ai]))
		{
			ja++;
			ai++;
		}
		else
		{
			ai++;
		}
	}

	return (NULL);
}

/**
 * my_strchr - Function that searches for a character in a string
 * @str: String to search in
 * @c: Character to find
 * Return: 1 if the character is found, 0 otherwise
 */
int my_strchr(char *str, char c)
{
	int ai = 0;

	while (str[ai] != '\0')
	{
		if (str[ai] == c)
			return (1);
		ai++;
	}

	return (0);
}

/**
 * my_strcmp - Function that compares two strings
 * @s1: String to compare
 * @s2: String to compare
 * Return: 0 if the strings are equal, a positive value if s1 > s2,
 *        a negative value if s1 < s2
 */
int my_strcmp(char *s1, char *s2)
{
	int ai = 0;

	while (s1[ai] == s2[ai] && s1[ai] != '\0')
		ai++;

	if (s1[ai] > s2[ai])
		return (1);
	else if (s1[ai] < s2[ai])
		return (-1);
	else
		return (0);
}
