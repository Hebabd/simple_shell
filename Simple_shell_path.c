#include "main.h"

/**
 * path_com - responsible for executing non_builtin commands
 * by creating a hild process,constructing the full path of the command.
 *@arr : the given array of args(command argument)
 *@new_env : the given env vars array(enviroment variables).
 * execve : check the function executability and executing it .
 */

void path_com(char ***new_env, char **arr)
{
	char *path;
	pid_t pid = fork();

	path = malloc(sizeof(char) * (_strlen(arr[0]) + _strlen("/user/bin/"));
			if (!path)
			{
			perror("malloc");
			exit(EXIT_FAILURE));
			}
	_strcpy(path, "/user/bin/");
	_strcat(pah, arr[0]);

	if (pid == 0)
	{
		/*
		*the current process is the child process
		*if command (path) is executable(x-ok)using the access()function
		*/
	if (access(path, x_ok) == 0)
	{
		execve(access(path, arr, *new_env);
				perror("Command execution failed");
				exit9EXit_FAILURE);
		/*if execve ()fail ,an error message is printed and the cild process exit */
	}
	else
	}
	perror("hsh");
	exit(EXIT_FAAILURE);
	}
}
/*the parent process ,it waits for the child process by using wit funtion*/
	else if (pid > 0)
	wait(NULL);
	else
	perror("fork failed");
	free(path);
	}
