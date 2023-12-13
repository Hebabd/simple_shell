#include "main.h"

#define BUFFER_SIZE 1024



int main (void)
{
	char cmond[BUFFER_SIZE];

	while(1) {
		puts ("cisfun$ ");

		if (fgets(cmond, BUFFER_SIZE, stdin) == NULL)
		{
			puts("\n");
			break;
		}
		cmond[strcspn(cmond, "\n")] = '\0';
		
		pid_t pid = fork ();
		 
		if (pid == -1){
			perror ("fork");
			exit(FAILURE);
		}
		else if (pid == 0)
		{
			if (execne(cmond, cmond, NULL) == -1) {
				perror("execve");
				exit(FAILURE);
			}
		} else {

			int status;
			if (waitpid(pid, &status, 0) == -1) {
				perror ("waitpid");
				exit (EXIT_FAILURE);
			}
		}
	}
	return (0);
}
