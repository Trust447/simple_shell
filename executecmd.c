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

	if (argv == NULL || argv[0] == NULL)
	{
		return;
	}
	command = argv[0];

	val = execve(command, argv, NULL);

	perror("Error:");
	exit(EXIT_FAILURE); /*Exit the shell on fail*/
}
