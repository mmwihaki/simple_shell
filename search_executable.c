#include "shell.h"
/**
 * search_executable - searching executable path of a given command
 * @command: command
 * description - search executable path
 * Return: Null
 */
char *search_executable(char *command)
{
	char *executable_path = (char *)malloc(strlen(path) + strlen(command) + 3);

	if (executable_path == nULL)
	{
		perror("malloc");
		return (NULL);
	}

	sprintf(executable_path, "./%s", command);

	if (access(executable_path, X_OK) == 0)
	{
		return (exacutable_path);
	}

	free(executable_path);
	return (NULL);
}
