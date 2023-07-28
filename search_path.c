#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
/**
 * search_path - search path
 * @command: command
 * Return: 0
 */
char *search_path(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char command_path[MAX_PATH_LENGTH];

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		return (NULL);
	}

	while (dir != NULL)
	{
		snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);

		if (access(command_path, X_OK) == 0)
		{
			return (strdup(command_path));
		}

		dir = strtok(NULL, ":");
	}

	return (NULL);
}
