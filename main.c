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
	const char *ascii_filename = "ascii-art.txt";
	char *user = getenv("USER");
	char *pwd = getenv("PWD");
	char *user_input = NULL;
	size_t len = 0;
	ssize_t read;
	char *executable_path;

	terminal_check(user, pwd);
	while ((read = getline(&user_input, &len, stdin)) != -1)
	{
		user_input[strcspn(user_input, "\n")] = 0;

		if (strcmp(user_input, "exit") == 0)
			break;
		else if (strcmp(user_input, "clear") == 0)
			system("clear");
		else if (strcmp(user_input, "sohi") == 0)
		{
			print_ascii_art(ascii_filename);
			printf("\n");
		}
		else
		{
			executable_path = find_executable(user_input);
			if (executable_path)
		{
				execute_command(user_input);
				free(executable_path);
		}
			else
			{
				if (strlen(user_input) != 0)
				printf("%s: command not found\n", user_input);
			}
		}
		terminal_check(user, pwd);
	}
	putchar('\n');
	free(user_input);
	return (0);
}
