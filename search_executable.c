#include "shell.h"
/**
 * search_executable - searching executable path of a given command
 * @command: command
 * description - search executable path
 * Return: Null
 */
char *search_executable(char *command)
{
	char *paths = getenv("PATH");
	char *path = strtok(paths, ":");
	char *executable_path = (char *)malloc(strlen(path) + strlen(command) + 2);

	if (paths == NULL)
	{
		return (NULL);
	}

	while (path != NULL)
	{
		if (executable_path == NULL)
		{
			return (NULL);
		}

		sprintf(executable_path, "%s/%s", path, command);

		if (access(executable_path, X_OK) == 0)
		{
			return (executable_path);
		}

		free(executable_path);
		path = strtok(NULL, ":");
	}

	return (NULL);
}
