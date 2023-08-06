#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * execute_command - execute command
 * @command: command
 * Return: Void
 */
void execute_command(char *command)
{
	char *command_path = search_path(command);

	if (strcmp(command, "exit") == 0)
	{
		printf("Exiting the shell...\n");
		exit(0);
	}
	else if (strcmp(command, "env") == 0)
	{
		print_environment();
		free(command_path);
		return;
	}

	if (command_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", command);
		return;
	}

	execute_external_command(command, command_path);

	free(command_path);
}
