#include <stdlib.h>
#include "shell.h"
/**
 * shell_loop - run shell
 * description: run shell in an infinite loop
 * Return: executable command
 */
void shell_loop(void)
{
	char *input = read_user_input();
	char *command = parse_command(input);
	char *path = "/usr/bin:/bin";
	char *executable_path = search_executable(command, path);

	while (1)
	{
		display_prompt();

		if (input == NULL)
		{
			break;
		}

		free(input);
		if (command == NULL)
		{
			continue;
		}

		if (executable_path == NULL)
		{
			handle_error("shell", "command not found");
			continue;
		}

		execute_command(executable_path);
	}
}
