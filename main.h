#ifndef __MAIN__H__
#define __MAIN__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

extern pid_t child_pid;
extern char **environ;

int main(void);
void terminal_check(char *user, char *pwd);

void print_ascii_art(const char *filename);
char *shell_executable_name(void);
void print_env(void);

void execute_command(char *command);
char *find_executable(const char *command);
char **parse_command(char *command);

void handle_sigint(int sig);
void run_calculator(void);
int calculate(int num1, char *operator, int num2);

#endif
