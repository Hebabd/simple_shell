#include "main.h"

/**
 * handle_builtin - handles builtin commands.
 * @new_env: The given array of env vars.
 * @new_aliases: The given array of aliases.
 * @arr: The given array of args.
 *
 * Return: Void.
 */

int handle_builtin(char ***new_env, char ***new_aliases, char **arr)
{
	if (_strcmp(arr[0], "env") == 0)
	{
		print_env(*new_env);
		return (0);
	}
	else if (_strcmp(arr[0], "setenv") == 0)
	{
		set_env(new_env, arr[1], arr[2]);
		return (0);
	}
	else if (_strcmp(arr[0], "unsetenv") == 0)
	{
		unset_env(new_env, arr[1]);
		return (0);
	}
	else if (_strcmp(arr[0], "cd") == 0)
	{
		_cd(new_env, arr);
		return (0);
	}
	else if (_strcmp(arr[0], "alias") == 0)
	{
		_alias(new_aliases, arr);
		return (0);
	}
	else if (_strcmp(arr[0], "exit") == 0)
		/* Built-in Exit Fn Goes Here... */
		exit(0);
	else
		return (-1);
}
