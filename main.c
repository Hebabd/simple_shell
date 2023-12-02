#include "main.h"

/**
 * main - entry point.
 *
 * Return: 0 always.
 */

int main(void)
{
	char *input_ptr = NULL;
	size_t num = 0;
	ssize_t chars_num = 1;
	char **arr = NULL;

	while (chars_num >= 0)
	{
		_puts("$ ");
		fflush(stdout);
		chars_num = _getline(&input_ptr, &num, stdin);

		if (chars_num > 1)
		{
			if (arr)
			{
				free_arr(arr);
			}
			arr = get_args(chars_num, input_ptr);
			print_env(arr[0]);
		}
		else if (chars_num < 1)
			break;
	}

	free(input_ptr);

	if (arr)
	{
		free_arr(arr);
	}

	return (0);
}
