#include "main.h"

/**
 * handle_sigint - handles SIGINT (CTRL-C)
 * @sig: the signal number
 */

void handle_sigint(int sig)
{
	(void)sig;

	if (child_pid != 0)
	{
		kill(child_pid, SIGINT);
	}
	putchar('\n');
}
