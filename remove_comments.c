#include "main.h"

/**
 * remove_comments - removes any parts of string that starts with a hashtag.
 * @str: The input line string.
 *
 * Return: Void.
 */

ssize_t remove_comments(char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			str[i] = '\0';
			break;
		}

		i++;
	}

	return (i + 1);
}
