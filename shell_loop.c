#include <stdlib.h>
#include "shell.h"

void shell_loop()
{
	char *input = read_user_input();
	char *command = parse_command(input);
	char *executable_path = search_executable(command);

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
			handle_error("command not found");
			continue;
		}

		execute_command(executable_path);
	}
}
