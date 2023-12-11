#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: The given string.
 *
 * Return: Void.
 */

void rev_string(char *s)
{
	int i = 0, j, length;
	char tmp;

	while (s[i] != '\0')
	{
		i++;
	}

	length = i;
	j = 0;

	while (j < length / 2)
	{
		tmp = s[j];
		s[j] = s[length - j - 1];
		s[length - j - 1] = tmp;
		j++;
	}

}

/**
 * _itoa - converts an integer into string.
 * @n: The number to be printed.
 *
 * Return: Char.
 */

char *_itoa(int n)
{
	unsigned int tmp;
	int i = 0, negative = 0, len;
	char *str;

	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	len = (n == 0) ? 1 : 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	str = malloc(1 + len + negative);
	if (str)
	{
		do {
			tmp = n % 10;
			str[i++] = '0' + tmp;
			n /= 10;
		} while (n > 0);
		if (negative)
			str[i++] = '-';
		str[i] = '\0';
		rev_string(str);

		return (str);
	}
	else
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

}

/**
 * handle_vars - handles commands with $ vars.
 * @new_env: The given array of env vars.
 * @arr: The given array of args.
 * @ex_status: The given exit status.
 *
 * Return: Void.
 */

void handle_vars(char ***new_env, char **arr, int ex_status)
{
	int i, j, len;
	char *str = NULL;

	for (i = 0; arr[i]; i++)
	{
		if (_strcmp(arr[i], "$?") == 0)
		{
			str = _itoa(ex_status);
			arr[i] = _strdup(str);
		}
		else if (_strcmp(arr[i], "$$") == 0)
		{
			str = _itoa(getpid());
			arr[i] = _strdup(str);
		}
		else if (arr[i][0] == '$')
		{
			if (arr[i][1] != '\0')
			{
				len = _strlen(arr[i]);
				if (len > 0)
				{
					for (j = 0; j < len - 1; j++)
						arr[i][j] = arr[i][j + 1];
				}
				arr[i][len - 1] = '\0';

				str = get_env(*new_env, arr[i]);
				arr[i] = _strdup(str);
			}
		}
	}

	free(str);
}
