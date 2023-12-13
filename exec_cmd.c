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
	pid_t pid = fork();

    while (token != NULL && argc < 9)
    {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    if (pid == -1)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execvp(argv[0], argv);
        perror("execvp error");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}
