#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 256

/**
 * read_user_input - reads user inputs from stdin
 *
 * Return: 0 (Success)
 */
char *read_user_input(void)
{
	char user_input[MAX_INPUT_LENGTH];
	char *result;

	if (fgets(user_input, sizeof(user_input), stdin) != NULL)
	{
		char *new_line = strchr(user_input, '\n');

		if (new_line != NULL)
		{
			*new_line = '\0';
		}
		result = strdup(user_input);
		return (result);
	}
	else
	{
		return (NULL);
	}
}
