#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/prctl.h>

/**
 * set_program_name - sets program name
 * @argO: argument
 * Return: 0 (Success)
 */

void set_program_name(char *arg0)
{
	size_t get_len = strlen(arg0);

	if (get_len > 15)
	{
		argO[15] = '\0';
	}

	prctl(PR_SET_MM, PR_SET_MM_ARG_START, arg0, 0, 0);
}
