#include "main.h"

/**
 * main - entry point.
 *
 * Return: 0 always.
 */

int main(void)
{
	char *input_ptr = NULL, *separator;
	char **arr = NULL, **args, **new_env, **new_aliases;
	size_t num = 0;
	ssize_t chars_num = 1;
	int result = 0;

	new_env = initiate_env();
	new_aliases = initiate_aliases();
	while (chars_num >= 0)
	{
		_puts("$ ");
		fflush(stdout);
		chars_num = _getline(&input_ptr, &num, stdin);
		if (chars_num > 1)
		{
			/*if (arr)*/
				/*free_arr(arr);*/
			separator = get_separator(input_ptr);
			if (separator)
			{
				args = get_args(chars_num, input_ptr, separator);
				handle_separator(&new_env, &new_aliases, args, arr, separator);
			}
			else
			{
				chars_num = remove_comments(input_ptr);
				arr = get_args(chars_num, input_ptr, " =\n");
				handle_vars(&new_env, arr, result);
				result = handle_builtin(&new_env, &new_aliases, arr);
				if (result != 0)
					result = exec_cmnds(&new_env, arr);
			}
		}
		else if (chars_num < 1)
			break;
	}
	free(input_ptr);
	if (arr)
		free_arr(arr);
	return (0);
}
