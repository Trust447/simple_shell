#include "main.h"

/**
 * managingFilesPath - this checks for filepath
 * @argv: pointer to argv
 *
 * Return: 0 on success
 */

void managingFilesPath(char **argv)
{
int processidstatus;

if (filestat(argv[0]) == 2)
{
char *fp = getfileinpath(argv[0]);
if (fp != NULL)
{
pid_t processid = fork();
if (processid == -1)
{
perror("Error creating fork");
exit(EXIT_FAILURE);
}
if (processid == 0)
{
argv[0] = fp;
executecmd(&argv[0]);
}
if (waitpid(processid, &processidstatus, 0) == -1)
{
perror("Error wait for child");
exit(EXIT_FAILURE);
}
}
else
{
perror("Error File Path Not found");
exit(EXIT_FAILURE);
}
}
else
{
forkprocess(argv);
}
}


/**
 * forkprocess - this calls the child process
 * @argv: pointer to argv
 *
 * Return: 0 on success
 */

void forkprocess(char **argv)
{
int processidstatus;

pid_t processid = fork();
if (processid == -1)
{
perror("Error creating fork");
exit(EXIT_FAILURE);
}
if (processid == 0)
{
executecmd(argv);
}
if (waitpid(processid, &processidstatus, 0) == -1)
{
perror("Error wait for child");
exit(EXIT_FAILURE);
}
}
