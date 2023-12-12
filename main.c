#include "main.h"

void terminal_check(char *user, char *pwd)
{
	if (isatty(STDIN_FILENO))
	{
		printf("%s:/%s$ ", user, pwd);
		fflush(stdout);
	}
}

int main(void)
{
	char *user = getenv("USER");
	char *pwd = getenv("PWD");
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	terminal_check(user, pwd);
	while ((read = getline(&input, &len, stdin)) != -1)
	{
		if (strcmp(input, "exit\n") == 0)
			break;
		else if (strcmp(input, "clear\n") == 0)
			system("clear");
		else if (strcmp(input, "help\n") == 0)
			printf("help\n");
		else
			printf("%s", input);
		terminal_check(user, pwd);
	}
	free(input);
	return (0);
}