#include "main.h"

/**
 * print_env - prints the current environment.
 * @cmnd: The given command.
 *
 * Return: Void.
 */

void print_env(const char *cmnd)
{
	extern char **environ;
	char **env;

	if (strcmp(cmnd, "env") == 0)
	{
		for (env = environ; *env; env++)
			printf("%s\n", *env);
	}
	else
		fprintf(stderr, "Command '%s' not found!\n", cmnd);
}
