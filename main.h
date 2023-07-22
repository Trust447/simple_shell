#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// functions declaration
void prompt (void);
char *get_cmd (void);
size_t _strlen(const char *str);
void _strcpy(char *copy, const char *main);
int _strcmp(char *s1, char *s2);
size_t toklen(char *tok, const char *deli);
void tokcpy(char *tok, char **av, const char *deli);
char *_strdup(const char *data);
void free_av(char **arr);

#endif /*_MAIN_H_*/
