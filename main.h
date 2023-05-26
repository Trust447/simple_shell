#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>

int arguments(int argc);
ssize_t getlinefunc(char **buf, size_t number);
char *creatingmemory(ssize_t linelen);
char *cpstrcpy(char *finaldes, const char *strsource);
void tokenizeInput(char *input, char ***argv, int *argc);
void managetheExitCmd(int argc, char **argv);
void managingFilesPath(char **argv);
void manageEnvVariable(char **sysenvp);
void forkprocess(char **argv);
void executecmd(char **argv);
void free_memory(char *buf, char *str, char **argv, int tok_count);
int filestat(const char *filepath);
char *getfileinpath(const char *filename);
char *cust_evn(const char *cenvname);
char *cstrconcat(char *filepath, const char *additionpath);
int setenv_op(int ac, char **argv);
int unsetenv_op(int ac, char **argv);


#endif
