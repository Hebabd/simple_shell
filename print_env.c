#include "main.h"

/**
 * initiate_env - creates new env vars.
 *
 * Return: Array.
 */

char **initiate_env()
{
	int i = 0, env_c = 0;
	char **env, **temp_env = NULL;

	for (env = environ; *env; env++)
		env_c++;
	temp_env = malloc(sizeof(char *) * (1 + env_c));

	if (!temp_env)
		return (NULL);

	for (env = environ; *env; env++)
	{
		temp_env[i++] = _strdup(*env);

		if (!temp_env[i - 1])
		{
			while (--i >= 0)
				free(temp_env[i]);
			free(temp_env);

			return (NULL);
		}
	}

	temp_env[i] = NULL;

	return (temp_env);
}

/**
 * print_env - prints the current environment.
 * @temp_env: The new env vars copied.
 *
 * Return: Void.
 */

void print_env(char **temp_env)
{
	char **env;

	for (env = temp_env; *env; env++)
	{
		_puts(*env);
		_putchar('\n');
	}
}
