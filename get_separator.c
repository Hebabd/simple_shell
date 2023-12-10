#include "main.h"

/**
 * get_separator - checks the given string for a predefined separator.
 * @str: The given string.
 *
 * Return: String or NULL.
 */

char *get_separator(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ';')
			return (";");
		else if (str[i] == '|' && str[i + 1] == '|')
			return ("||");
		else if (str[i] == '&' && str[i + 1] == '&')
			return ("&&");
	}

	return (NULL);
}

/**
 * handle_semicolon - handles the execution of ; separated commands.
 * @new_env: The given env vars array.
 * @new_aliases: Teh given aliases array.
 * @args: The given array of separated commands.
 * @arr: The given array of individual commands.
 * @separator: The given separator.
 *
 * Return: Void.
 */

void handle_semicolon(char ***new_env, char ***new_aliases,
		char **args, char **arr)
{
	int result = 0;
	ssize_t chars_num;

	while (*args)
	{
		chars_num = remove_comments(*args);
		arr = get_args(chars_num, *args, " =\n");
		result = handle_builtin(new_env, new_aliases, arr);

		if (result == 0)
			exec_cmnds(new_env, arr);
		args++;
	}
}

/**
 * handle_AND - handles the execution of && separated commands.
 * @new_env: The given env vars array.
 * @new_aliases: Teh given aliases array.
 * @args: The given array of separated commands.
 * @arr: The given array of individual commands.
 * @separator: The given separator.
 *
 * Return: Void.
 */

void handle_AND(char ***new_env, char ***new_aliases,
		char **args, char **arr)
{
	int result = 0;
	ssize_t chars_num;

	while (*args)
	{
		chars_num = remove_comments(*args);
		arr = get_args(chars_num, *args, " =\n");
		result = handle_builtin(new_env, new_aliases, arr);

		if (result == 0)
			result = exec_cmnds(new_env, arr);

		if (result == 1)
			args++;
		else
			break;
	}
}

/**
 * handle_OR - handles the execution of || separated commands.
 * @new_env: The given env vars array.
 * @new_aliases: Teh given aliases array.
 * @args: The given array of separated commands.
 * @arr: The given array of individual commands.
 * @separator: The given separator.
 *
 * Return: Void.
 */

void handle_OR(char ***new_env, char ***new_aliases,
		char **args, char **arr)
{
	int result = 0;
	ssize_t chars_num;

	while (*args)
	{
		chars_num = remove_comments(*args);
		arr = get_args(chars_num, *args, " =\n");
		result = handle_builtin(new_env, new_aliases, arr);

		if (result == 0)
			result = exec_cmnds(new_env, arr);

		if (result == 0)
			args++;
		else
			break;
	}
}

/**
 * handle_separator - handles the execution of separated commands.
 * @new_env: The given env vars array.
 * @new_aliases: Teh given aliases array.
 * @args: The given array of separated commands.
 * @arr: The given array of individual commands.
 * @separator: The given separator.
 *
 * Return: Void.
 */
void handle_separator(char ***new_env, char ***new_aliases,
	       char **args, char **arr, char *separator)
{
	if (_strcmp(separator, ";") == 0)
		handle_semicolon(new_env, new_aliases, args, arr);

	else if (_strcmp(separator, "&&") == 0)
		handle_AND(new_env, new_aliases, args, arr);

	else if (_strcmp(separator, "||") == 0)
		handle_OR(new_env, new_aliases, args, arr);
}
