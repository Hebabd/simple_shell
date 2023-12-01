#include "main.h"

/**
 * main - entry point.
 * @argc: The number of arguments.
 * @argv: The pointer to the array of arguments.
 *
 * Return: 0 always.
 */

int main(int argc, char **argv)
{
	char *input_ptr;
	size_t num = 0;
	ssize_t shell_exit = 1;

	(void)argc;
	(void)argv;

	while (shell_exit >= 0)
	{
		printf("$ ");

		shell_exit = getline(&input_ptr, &num, stdin);

		printf("%s", input_ptr);
	}

	free(input_ptr);

	return (0);
}
