#include "main.h"

/**
 * execute_command - executes a command
 * @command: the command to execute
 */

pid_t child_pid;

void execute_command(char *command)
{
	char *argv[32];
	int argc = 0;
	char *token = strtok(command, " ");
	char *envp[] = { NULL };
	char *executable_path;
	int status;

	child_pid = 0;

	while (token != NULL && argc < 31)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
    argv[argc] = NULL;

	if (argv[0][0] == '/' || (argv[0][0] == '.' && argv[0][1] == '/'))
	{
		executable_path = argv[0];
	}
	
	executable_path = find_executable(argv[0]);

	if (executable_path == NULL)
	{
		printf("%s: command not found\n", argv[0]);
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(executable_path, argv, envp) == -1)
		{
			perror("./simple_shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (executable_path != argv[0]) free(executable_path);
	}
}
