#include <stdio.h>
#include "shell.h"
/**
 * handle_error - handle erros
 * @program_name: program name
 * @error_message: error message
 * description - handle error
 * Return: void
 */
void handle_error(const char *program_name, const char *error_message)
{
	fprintf(stderr, "%s: %s\n", program_name, error_message);
}
