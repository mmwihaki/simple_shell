#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>

#ifdef __unix__
extern char **environ;
#endif
void execute_external_command(char *command, char *command_path);
void wait_for_child_process(pid_t pid, int *status);
void prompt_loop(void);
char **split_arguments(char *line);
char *search_path(char *command);
void print_environment(void);
void execute_command(char *command);

#endif
