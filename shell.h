#ifndef SHELL_H
#define SHELL_H

void set_program_name(char *argO);
void display_prompt();
char *read_user_input();
char *parse_command(char *input);
char *search_executable(char *command);
void execute_command(char *command);
void handle_error(const char *error_messsage);
void shell_loop();

#endif
