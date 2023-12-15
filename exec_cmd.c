#include "main.h"

/**
 * execute_command - executes a command
 * @command: the command to execute
 */

void execute_command(char *command)
{
	char *argv[10];
	int argc = 0;
	char *token = strtok(command, " ");
	pid_t pid;
	char *envp[] = { NULL };
	char *executable_path;

	while (token != NULL && argc < 9)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
    argv[argc] = NULL;

	if (argv[0][0] == '/' || (argv[0][0] == '.' && argv[0][1] == '/'))
	{
		executable_path = argv[0];
	}
	else
	{
		executable_path = find_executable(argv[0]);
		if (executable_path == NULL)
		{
			printf("%s: command not found\n", argv[0]);
			return;
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(executable_path, argv, envp) == -1)
		{
			perror("./simple_shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		if (executable_path != argv[0]) free(executable_path);
	}
}
