#ifndef __MAIN__H__
#define __MAIN__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

	extern pid_t child_pid;

int main(void);
void terminal_check(char *user, char *pwd);

void print_ascii_art(const char *filename);

void execute_command(char *command);
char *find_executable(const char *command);

void handle_sigint(int sig);

#endif
