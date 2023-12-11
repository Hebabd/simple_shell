#include "main.h"

/**
 * exec_cmnds - handles and executes non-builtin commands.
 * @arr: The given array of args.
 * @new_env: The given env vars array.
 *
 * Return: Int.
 */

int exec_cmnds(char ***new_env, char **arr)
{
	int value;
	char *cmnd;
	pid_t pid = fork();

	cmnd = malloc(sizeof(char) * (_strlen(arr[0]) + _strlen("/usr/bin/")));
	if (!cmnd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(cmnd, "/usr/bin/");
	_strcat(cmnd, arr[0]);
	if (pid == 0)
	{
		if (access(cmnd, X_OK) == 0)
		{
			execve(cmnd, arr, *new_env);
			perror("Command execution failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			perror("hsh");
			value = 0;
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		/*wait(NULL);*/
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
