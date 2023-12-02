#include "main.h"

/**
 * _strtok - splits a string by a given delimiter.
 * @str: The given string.
 * @delimiter: The given delimiter.
 *
 * Return: String or NULL.
 */

char *_strtok(char *str, const char *delimiter)
{
	static char *str_ptr;
	char *temp;
	int i = 0, ltr = 0, done = 0;

	if (str != NULL)
		str_ptr = str;
	temp = str_ptr;

	while (*str_ptr && str_ptr)
	{
		while (delimiter[i])
		{
			if (ltr == 0 && *str_ptr == delimiter[i])
			{
				i = 0;
				++str_ptr;
				++temp;
				continue;
			}
			if (ltr == 1 && *str_ptr == delimiter[i])
			{
				i = 0;
				*str_ptr++ = '\0';
				done = 1;
				break;
			}
			++i;
		}

		if (!*str_ptr || done)
			break;
		i = 0;
		++str_ptr;
		ltr = 1;
	}

	if (*temp == '\0' || !temp)
		return (NULL);

	return (temp);
}
