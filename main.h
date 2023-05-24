#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


#ifndef MAIN_H
#define MAIN_H

int arguments(int ac, char **argv) __attribute__((unused));

int unsetenv_op(int ac, char **argv);
int env_pro(int ac, char **argv);
char* readline();


#endif
