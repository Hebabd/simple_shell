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
	char **arr = NULL, **new_env;

	new_env = initiate_env();

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
			chars_num = remove_comments(input_ptr);
			arr = get_args(chars_num, input_ptr);
			print_env(new_env, arr[0]);
			if (_strcmp(arr[0], "setenv") == 0)
			{
				unset_env(&new_env, "PWD");
				set_env(&new_env, "PWD", "Bitches!");
			}
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
