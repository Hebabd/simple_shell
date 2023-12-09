#include "main.h"

/**
 * _atoi : take a string str and converts it to integer.
 *sign : check for minus sign
 *Return : 0 it return 0 if an invalid character is encounterered
 */

int _atoi(const  char *str)
{
	int re = 0;
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





	return (re * sign);
}

/**
 * _exit : to exit ommand with specified code.
 * by set the exit code to 0 by default
 * and check ifan exit code is provied as an argument.
 *_atoi : convert an argument exit code to an integer
 *
 */

void _exit(char **arr)
{
	int _exit = 0;
	if (arr[1] != NULL)
	{
	_exit = _atoi(arr[1]);
	}
	exit(_exit);
}
