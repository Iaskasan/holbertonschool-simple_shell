#ifndef __MAIN__H__
#define __MAIN__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void);
void terminal_check(char *user, char *pwd);

void print_ascii_art(const char *filename);

void execute_command(const char *command);
char *find_executable(const char *command);

#endif
