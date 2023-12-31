#include "main.h"

/**
 * update_env - updates a new env var.
 * @env: The given pointer to env vars array.
 * @current_env: The current env vars array.
 * @var: The given variable.
 * @val: The desired value.
 *
 * Return: Void.
 */

void update_env(char ***env, char **current_env, char *var, char *val)
{
	int index;
	int len = 2 + _strlen(var) + _strlen(val);
	char *new = malloc(sizeof(char) * len);

	index = get_index(current_env, var);

	if (!new)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	_strcpy(new, var);
	_strcat(new, "=");
	_strcat(new, val);

	current_env[index] = _strdup(new);
	free(new);
	*env = current_env;
}

/**
 * add_env - creates a new env var.
 * @env: The given pointer to env vars array.
 * @current_env: The current env vars array.
 * @var: The given variable.
 * @val: The desired value.
 *
 * Return: Void.
 */

void add_env(char ***env, char **current_env, char *var, char *val)
{
	int i, env_c = 0, len;
	char *new;
	char **new_env;

	while (*current_env)
	{
		env_c++;
		current_env++;
	}

	new_env = malloc(sizeof(char *) * (2 + env_c));

	current_env = *env;

	for (i = 0; i < env_c; i++, current_env++)
	{
		new_env[i] = *current_env;
	}

	len = 2 + _strlen(var) + _strlen(val);
	new = malloc(sizeof(char) * len);
	_strcpy(new, var);
	_strcat(new, "=");
	_strcat(new, val);
	new_env[env_c] = new;
	new_env[1 + env_c] = NULL;
	free(*env);
	*env = new_env;
}

/**
 * set_env - creates or modifies a given environment variable.
 * @env: The given environment variables pointer to array.
 * @var: The given variable.
 * @val: The desired value.
 *
 * Return: Void.
 */

void set_env(char ***env, char *var, char *val)
{
	char **current_env = *env;
	char *key, *eq, *curkey;
	size_t len;
	int i;

	for (i = 0; current_env[i]; i++)
	{
		key = current_env[i];
		eq = _strchr(key, '=');
		len = eq - key;
		curkey = malloc(len + 1);
		_strncpy(curkey, key, len);
		curkey[len] = '\0';
		if (eq && _strcmp(curkey, var) == 0)
		{
			update_env(env, current_env, var, val);
			return;
		}
	}

	add_env(env, current_env, var, val);
}
