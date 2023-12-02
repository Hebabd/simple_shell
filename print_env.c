#include "main.h"

/**
 * print_env - prints the current environment.
 * @cmnd: The given command.
 *
 * Return: Void.
 */

void print_env(char *cmnd)
{
	char **env;

	if (strcmp(cmnd, "env") == 0)
	{
		for (env = environ; *env; env++)
		{
			_puts(*env);
			_putchar('\n');
		}
	}
	else
	{
		_puts("Command ");
		_putchar('\'');
		_puts(cmnd);
		_putchar('\'');
		_puts(" not found!\n");
	}
}
