#include "main.h"

/**
 * main - entry point.
 * @argc: The number of arguments.
 * @argv: The pointer to the array of arguments.
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

		chars_num = getline(&input_ptr, &num, stdin);

		printf("%s, %ld", input_ptr, chars_num);

		if (chars_num > 1)
		{
			if (arr)
			{
				for (i = 0; arr[i]; i++)
					free(arr[i]);
				free(arr);
			}
			arr = get_args(chars_num, input_ptr);
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
