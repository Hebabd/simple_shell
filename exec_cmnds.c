#include "main.h"

/**
 * _strstr - locates a substring.
 * @haystack: The first pointer.
 * @needle: The second pointer.
 *
 * Return: a pointer to the result.
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0;

	if (needle[0] == '\0')
		return (haystack);

	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			int j;

			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] == needle[j])
					continue;
				else
					break;
			}

			if (needle[j] == '\0')
				return (haystack + i);
		}

		i++;
	}

	return ('\0');
}

/**
 * check_path - handles and executes non-builtin commands.
 * @arr: The given array of args.
 *
 * Return: Char.
 */

char *check_path(char **arr)
{
	char *cmnd = NULL;

	if (_strchr(arr[0], '/') == NULL)
	{
		cmnd = malloc(sizeof(char) * (_strlen("/usr/bin/") + _strlen(arr[0])));
		if (!cmnd)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy(cmnd, "/usr/bin/");
		_strcat(cmnd, arr[0]);
	}
	else
	{
		cmnd = malloc(sizeof(char) * _strlen(arr[0]));
		if (!cmnd)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy(cmnd, arr[0]);
	}

	return (cmnd);
}

/**
 * exec_cmnds - handles and executes non-builtin commands.
 * @arr: The given array of args.
 * @new_env: The given env vars array.
 *
 * Return: Int.
 */

int exec_cmnds(char ***new_env, char **arr)
{
	int value = 0;
	char *cmnd;
	pid_t pid = fork();

	if (pid == 0)
	{
		cmnd = check_path(arr);
		if (access(cmnd, X_OK) == 0)
		{
			execve(cmnd, arr, *new_env);
			perror("Command execution failed");
			free(cmnd);
			exit(EXIT_FAILURE);
		}
		else
		{
			perror("hsh");
			free(cmnd);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &value, 0);
		return (WEXITSTATUS(value));
	}
	else
	{
		perror("Fork failed");
		return (-1);
	}
	free(cmnd);
	return (value);
}
