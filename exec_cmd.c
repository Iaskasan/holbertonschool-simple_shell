#include "main.h"

pid_t child_pid;

/**
 * parse_command - Parse a command string into an array of arguments.
 * @command: The command string to be parsed.
 *
 * Return: An array of pointers to strings (arguments), or NULL on failure.
 */

char **parse_command(char *command)
{
	int argc = 0;
	char *token = strtok(command, " ");
	char **argv = malloc(32 * sizeof(char *));

	if (argv == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	while (token != NULL && argc < 31)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;

	return (argv);
}

/**
 * execute_command - executes a command
 * @command: the command to execute
 */

void execute_command(char *command)
{
	char **argv;
	char *envp[] = { NULL };
	char *executable_path;
	int status;

	child_pid = 0;
	argv = parse_command(command);
		if (argv == NULL)
		return;

	executable_path = find_executable(argv[0]);

	if (executable_path == NULL)
	{
		printf("%s: command not found\n", argv[0]);
		free(argv);
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
		if (executable_path != argv[0])
			free(executable_path);
		free(argv);
	}
}
