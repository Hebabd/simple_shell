#include "main.h"

/**
 * _atoi - takes a string str and converts it to an integer.
 * @str: pointer of the input char array.
 *
 * Return: Int.
 */

int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			return (0);
		}
	}

	return (result * sign);
}

/**
 * he_exit - Exit the command with specified code
 * @arr: The given array.
 *
 * Return: Void.
 */

int he_exit(char **arr)
{
	int ex_status = 0, i;

	if (arr[1] != NULL)
	{
		for (i = 0; arr[1]; i++)
		{
			if (_isalpha(arr[1][i]) != 0)
			{
				_puts("-hsh: exit: ");
				_puts(arr[1]);
				_puts(": numeric argument required\n");
				return (EXIT_FAILURE);
			}
			else
			{
				ex_status = _atoi(arr[1]);
				return (ex_status);
			}
		}
	}

	return(EXIT_SUCCESS);
}
