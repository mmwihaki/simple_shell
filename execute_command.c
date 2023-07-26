#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
#include <string.h>
/**
 * execute_command - executes commands
 * @command: command character
 * Return: 0 (Success)
 */
void execute_command(char *command)
{
	pid_t process_id;
	int status;

	process_id = fork();

	if (process_id < 0)
	{
		perror("fork");

		exit(EXIT_FAILURE);
	}
	else if (process_id == 0)
	{
		char *argv[3] = {command, NULL, NULL};

		execvp(command, argv);

		perror("execvp");

		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(process_id, &status, 0);

		if (WIFEXITED(status))
		{
			int status_exit = WEXITSTATUS(status);

			printf("Command status exited: %d\n", status_exit);
		}
		else if (WIFSIGNALED(status))
		{
			int final_signal = WTERMSIG(status);

			printf("Command signal termination: %d\n", final_signal);
		}
	}
}
