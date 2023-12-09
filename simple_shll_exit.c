#include "main.h"

/**
 * _atoi : takes a string str and converts it to an nteger.
 *sign : check for minus sign.
 *Return : 0 if an invalid character is encounterered.
 * *str : pointer of the input char array .
 *
 */

int _atoi(const  char *str)
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
 * he_exit : Exit the command with specified code.
 *By default, it  sets the exit code to 0
 *and checks if ana exit code is provid as an argument
 *
 * _atoi : convert an argument exit code to an integer
 *
 */

void he_exit(char **arr)
{
	int _exit = 0;

	if (arr[1] != NULL)
	{
	_exit = _atoi(arr[1]);
	}
	exit(_exit);
}
