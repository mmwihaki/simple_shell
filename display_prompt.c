#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * display_prompt - prompts user input commands
 *
 * Return: 0 (Success)
 */

void display_prompt(void)
{
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s$ ", cwd);
	}
	else
	{
		perror("getcwd");
		printf("shell_error$ ");
	}
}
