#include "main.h"

/**
 * executecmd - handles command execute
 * @argv: pointer
 *
 * Return: 0 on success
 */

void executecmd(char **argv)
{
char *command = NULL;
int val;

if (argv)
{
command = argv[0]; /*getting the buffer value from the terminal*/
/* running execve  */

val = execve(command, argv, NULL);

if (val == -1)
{
perror("Error:");
exit(EXIT_FAILURE); /*Exit the shell on fail*/
}
}
}
