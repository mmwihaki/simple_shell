#include "shell.h"
#include <stdio.h>
/**
 * print_environment - print environment
 * description - print environment
 * Return: void
 */
void print_environment(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
