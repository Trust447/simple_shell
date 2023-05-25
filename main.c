#include "main.h"

/**
 * main - the entry point
 * @argv: agruement vector
 * @argc: argument counter
 * @sysenvp: env path variable
 * Return: 0 on success
 */

int main(int argc, char **argv, char **sysenvp)
{
/*declaring variale for the program*/
char *prompt = "Group(shell)$ ";
int from_pipe = 1;
ssize_t linelen;
char *buf = NULL;
char *str = NULL;
int tok_count = 0;
size_t number = 0;
int agccount = 0;
while (from_pipe == 1)
{
if (isatty(STDIN_FILENO) == 0) /*this code section check if file is piped */
from_pipe = 2;

write(STDOUT_FILENO, prompt, strlen(prompt));  /*writing out to command promt*/

linelen = getlinefunc(&buf, number);
str = creatingmemory(linelen);
cpstrcpy(str, buf); /*using custom string copy*/
tokenizeInput(buf, &argv, &argc);

while (agccount < argc)
agccount++;

if (strcmp(argv[0], "exit") == 0)
managetheExitCmd(argc, argv);
else if (strcmp(argv[0], "env") == 0)
manageEnvVariable(sysenvp);
else
managingFilesPath(argv);


}

free_memory(buf, str, argv, tok_count);
return (0);
}

