#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
/**
 * prompt_loop - prompts user input commands
 *
 * Return: 0 (Success)
 */

void prompt_loop(void)
{
	char *line;
	char buffer[BUFFER_SIZE];
	size_t bufsize = BUFFER_SIZE;
	int output_mode = 0;

	while (1)
	{
		if (output_mode == 0)
		{
			printf("($) ");
		}

		line = fgets(buffer, bufsize, stdin);

		if (line == NULL)
		{
			printf("\n");
			break;
		}

		if (line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}

		execute_command(line);

		output_mode = 1;

		printf("\n");
	}
}
