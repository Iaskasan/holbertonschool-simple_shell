#include "main.h"

/**
 * execute_command - executes a command
 * @command: the command to execute
 */

void execute_command(const char *command)
{
	char *executable_path = find_executable(command);
	char *argv[2];
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		free(executable_path);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		extern char **environ;
		argv[0] = executable_path;
		argv[1] = NULL;
		execve(executable_path, argv, environ);
		perror("execcve error");
		free(executable_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		free(executable_path);
	}
}
