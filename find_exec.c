#include "main.h"

/**
 * find_executable - Search for an executable file in the directories
 * listed in PATH.
 * @command: The command for which to find the executable.
 *
 * Return: A dynamically allocated string containing the full path to the
 * executable, or NULL if the executable is not found or if an error occurs.
 */


char *find_executable(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token;
	char exec_path[1024];

	if (command == NULL || *command == '\0' || strspn(command, " ") == strlen(command))
	{
		free(path_copy);
		return (NULL);
	}
	if (!path_copy)
	{
		perror("$PATH not found");
		free(path_copy);
		return (NULL);
	}

	if (access(command, X_OK) == 0)
	{
		free(path_copy);
		return (strdup(command));
	}
	for (token = strtok(path_copy, ":"); token != NULL; token = strtok(NULL, ":"))
	{
		sprintf(exec_path, "%s/%s", token, command);
		if (access(exec_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(exec_path));
		}
	}

	free(path_copy);
	return (NULL);
}
