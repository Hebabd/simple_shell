#include "main.h"

/**
 * get_separator - checks the given string for a predefined separator.
 * @str: The given string.
 *
 * Return: String or NULL.
 */

char *get_separator(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ';')
			return (";");
		else if (str[i] == '|' && str[i + 1] == '|')
			return ("||");
		else if (str[i] == '&' && str[i + 1] == '&')
			return ("&&");
	}

	return (NULL);
}
