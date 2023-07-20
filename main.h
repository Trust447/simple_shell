#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void prompt (void);
void _strcpy(char *copy, char *main);
char *get_cmd (void);
size_t _strlen(const char *str);
void cmd_line_args (int ac, char **av);
void _strcpy(char *copy, char *main);
int count_tok(char* cmd_cpy, char* deli);

#endif /*_MAIN_H_*/
