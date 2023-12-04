#include "main.h"

/**
 * get_index - returns the index.
 * @env: The given array.
 * @var: The given variable.
 *
 * Return: Int.
 */

int get_index(char **env, char *var)
{
	int i;
	char *key, *eq, *curkey;
	size_t len;

	for (i = 0; env[i]; i++)
	{
		key = env[i];
		eq = _strchr(key, '=');

		if (eq)
		{
			len = eq - key;
			curkey = malloc(1 + len);

			if (!curkey)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			_strncpy(curkey, key, len);
			curkey[len] = '\0';

			if (_strcmp(curkey, var) == 0)
			{
				free(curkey);
				return (i);
			}

			free(curkey);
		}
	}

	return (-1);
}

/**
 * remove_index - removes the env var at the given index.
 * @env: The given env.
 * @index: The given index.
 *
 * Return: Array.
 */

char **remove_index(char **env, int index)
{
	int i, len = 0;
	char **new_env;

	while (env[len])
	{
		len++;
	}

	new_env = malloc(sizeof(char *) * len);

	if (!new_env)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < index; i++)
		new_env[i] = env[i];

	for (i = index; i < len - 1; i++)
		new_env[i] = env[1 + i];

	new_env[len - 1] = NULL;
	free(env);

	return (new_env);
}

/**
 * unset_env - removes the env var at the given index.
 * @env: The given env.
 * @var: The given env var.
 *
 * Return: Int.
 */

int unset_env(char ***env, char *var)
{
	int index;

	index = get_index(*env, var);

	if (index != -1)
	{
		*env = remove_index(*env, index);

		return (1);
	}

	return (0);
}
