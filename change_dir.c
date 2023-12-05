#include "main.h"

/**
 * get_env - gets env var.
 * @env: The given env.
 * @var: The given env var.
 *
 * Return: Char.
 */

char *get_env(char **env, char *var)
{
	int index, i, len = 0;
	char *val = NULL, *str = NULL;

	index = get_index(env, var);

	val = _strchr(env[index], '=');

	for (i = 0; val[i]; i++)
	{
		len++;
	}

	str = malloc(sizeof(char) * len);

	for (i = 0; val[i]; i++)
	{
		str[i] = val[i + 1];
	}

	return (str);
}

/**
 * _cd - changes the current working directory..
 * @env: The given env vars.
 * @arr: The arguments array.
 *
 * Return: Int.
 */

int _cd(char ***env, char **arr)
{
	int result;
	char curcwd[PATH_MAX];

	if (!arr[1])
		result = chdir(get_env(*env, "HOME"));
	else if (_strcmp(arr[1], "-") == 0)
		result = chdir(get_env(*env, "OLDPWD"));
	else
		result = chdir(arr[1]);

	if (result == -1)
	{
		perror("hsh");
		return (-1);
	}
	else
	{
		getcwd(curcwd, sizeof(curcwd));
		/*unset_env(env, "OLDPWD");*/
		set_env(env, "OLDPWD", get_env(*env, "PWD"));
		/*unset_env(env, "PWD");*/
		set_env(env, "PWD", curcwd);
	}

	return (0);
}
