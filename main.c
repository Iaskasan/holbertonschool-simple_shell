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
 * Return: EXIT_SUCCESS
 */

int main(void)
{
	const char *ascii_filename = "ascii-art.txt";
	char *user_input = NULL;
	char *user = getenv("USER");
	char *pwd = getenv("PWD");
	size_t len = 0;
	ssize_t bytes_read;

	signal(SIGINT, handle_sigint);

	while (1)
	{
		terminal_check(user, pwd);

		bytes_read = getline(&user_input, &len, stdin);
		if (bytes_read == -1)
		{
			break;
		}

		user_input[strcspn(user_input, "\n")] = 0;

		if (strlen(user_input) == 0)
			continue;
		else if (strcmp(user_input, "exit") == 0)
			break;
		else if (strcmp(user_input, "clear") == 0)
			system("clear");
		else if (strcmp(user_input, "sohi") == 0)
			print_ascii_art(ascii_filename);
		else if (strcmp(user_input, "env") == 0)
			print_env();
		else if (strcmp(user_input, "calc") == 0)
			run_calculator();
		else
			execute_command(user_input);
	}
	free(user_input);
	return (EXIT_SUCCESS);
}
