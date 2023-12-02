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
	int i;

	while (chars_num >= 0)
	{
		printf("$ ");
		fflush(stdout);
		chars_num = _getline(&input_ptr, &num, stdin);

		if (chars_num > 1)
		{
			if (arr)
			{
				for (i = 0; arr[i]; i++)
					free(arr[i]);
				free(arr);
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
		for (i = 0; arr[i]; i++)
			free(arr[i]);
		free(arr);
	}

	return (0);
}
