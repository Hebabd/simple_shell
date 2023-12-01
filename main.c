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
	char *input_ptr;
	size_t num = 0;
	ssize_t chars_num = 1;
	char **arr;

	while (chars_num >= 0)
	{
		printf("$ ");

		chars_num = getline(&input_ptr, &num, stdin);

		printf("%s", input_ptr);

		arr = get_args(chars_num, input_ptr);
	}

	free(input_ptr);

	return (0);
}
