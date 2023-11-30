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

	(void)argc;
	(void)argv;

	printf("$ ");

	getline(&input_ptr, &num, stdin);

	printf("%s", input_ptr);

	free(input_ptr);

	return (0);
}
