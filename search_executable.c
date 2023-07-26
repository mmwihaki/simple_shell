#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
/**
 * search_executable - searching executable path of a given command
 * @command: command
 * description - search executable path
 * Return: Null
 */
char *search_executable(char *command)
{
	char *executable_path = (char *)malloc(strlen(path) + strlen(command) + 3);

	if (executable_path == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	sprintf(executable_path, "./%s", command);

	if (access(executable_path, X_OK) == 0)
	{
		return (executable_path);
	}

	free(executable_path);
	return (NULL);
}
