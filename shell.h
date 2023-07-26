#ifndef SHELL_H
#define SHELL_H

void set_program_name(char *argO);
void display_prompt(void);
char *read_user_input();
char *parse_command(char *input);
char *search_executable(char *command, const char *path);
void execute_command(char *command);
void handle_error(const char *program_name, const char *error_messsage);
void shell_loop(void);

#endif
