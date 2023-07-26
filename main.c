#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * description - check code
 * Return: Void
 */
int main(void)
{
	char *user_input = NULL;
	char **command = NULL;

	while (1)
	{
		display_prompt();

		user_input = read_user_input();

		if (user_input == NULL)
		{
			break;
		}

		command = parse_command(user_input);

		if (command != NULL)
		{
			execute_command(command);
			free(command);

		}
		else
		{
			free(user_input);
			continue;
		}

		free(user_input);
	}

	return (0);
}
