#include "main.h"

/**
 * terminal_check - checks if the terminal is interactive
 * @user: the user
 * @pwd: the current working directory
 */

void terminal_check(char *user, char *pwd)
{
	if (isatty(STDIN_FILENO))
	{
		printf("%s:/%s$ ", user, pwd);
		fflush(stdout);
	}
}

/**
 * main - main fucntion of the shell
 *
 * Return: 0 on success
 */

int main(void)
{
	const char *filename = "ascii-art.txt";
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
		else if (strcmp(input, "sohi\n") == 0)
		{
			print_ascii_art(filename);
			printf("\n");
		}
		else
			printf("%s", input);
		terminal_check(user, pwd);
	}
	free(input);
	return (0);
}
