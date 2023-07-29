#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * execute_external_command - execute external command
 * @command: command
 * @command_path: command path
 * Return: void
 */
void execute_external_command(char *command, char *command_path)
{
	pid_t pid;
	int status;
	char **args = split_arguments(command);

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(args);
		return;
	}

	if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror(command_path);
			free(args);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait_for_child_process(pid, &status);
	}

	free(args);
}
