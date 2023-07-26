#include <stdio.h>
#include <string.h>
#include "shell.h"
#include <stdlib.h>

#define MAX_ARGUMENTS 64
/**
 * parse_command - parse user input
 * @input: user input
 * description: parse user input
 * Return: Command
 */
char **parse_command(char *input)
{
	int i, t_count = 0;
	char *token;
	char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
	char *input_copy = strdup(input);

	if (tokens == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(input, " ");
	while (token != NULL && t_count < MAX_ARGUMENTS - 1)
	{
		tokens[t_count] = strdup(token);

		if (tokens[t_count] == NULL)
		{
			perror("malloc");
			for (i = 0; i < t_count; i++)
			{
				free(tokens[i]);
			}

			free(tokens);
			free(input_copy);
			return (NULL);
		}

		t_count++;
		token = strtok(NULL, " ");
	}

	tokens[t_count] = NULL;
	free(input_copy);

	return (tokens);
}
