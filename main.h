#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Declare global struct */
struct stat find;

/* functions declaration*/
void prompt (void);
void dis_err(char *prog, char *cmd);
char *get_cmd (void);
char **han_token(char *cmd);
int han_bulltin(char**param, char *hsh, char **envp);
char *_getenv(const char *c, char **envp);
size_t _strlen(const char *str);
char *cmd_path(char *cmd, char **envp);
char *_strcpy(char *copy, const char *main);
char *han_spec(char *first);
void free_arr(char **arr);
int run(char **params, char *hsh, char **envp);
char *_strcat(char *dest, const char *src);
char *get_path(const char *dir, const char *cmd);
char *_strdup(const char *data);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif /*_MAIN_H_*/
