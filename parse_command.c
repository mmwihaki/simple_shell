#include <stdio.h>
#include <string.h>
#include "shell.h"
/**
 * parse_command - parse user input
 * @input: user input
 * description: parse user input
 * Return: Command
 */
char *parse_command(char *input)
{
	char *command = strtok(input, "\n");

	return (command);
}
