#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * wait_for_child_process - wait for child process
 * @pid: process identification
 * @status: status
 * Return: Void
 */
void wait_for_child_process(pid_t pid, int *status)
{
	do {
		if (waitpid(pid, status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	} while (!WIFEXITED(*status) && !WIFSIGNALED(*status));
}
