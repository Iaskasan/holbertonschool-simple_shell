#include "main.h"

char *find_executable(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token;
	char exec_path[1024];

	if (!path_copy)
	{
		perror("$PATH not found");
		return NULL;
	}

	for (token = strtok(path_copy, ":"); token != NULL; token = strtok(NULL, ":"))
	{
		sprintf(exec_path, "%s/%s", token, command);
		if (access(exec_path, X_OK) == 0)
		{
			free(path_copy);
			return strdup(exec_path);
		}
	}

	free(path_copy);
	return NULL;
}
