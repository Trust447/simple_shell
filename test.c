#include "main.h"
#include <stdlib.h>
/**
 * main - where the simple shell program begins
 *
 * @ac: Holds the number of command line arguments
 * @av: Array that holds the values of the command line arguments
 * Return: Always 0
 */
int main(int ac, char **av)
{
	char *cmd;

	if (ac > 1)
	{

		cmd_line_args(ac, av);
	}

	while (1)
	{
		prompt();
		cmd = get_cmd();
		free(cmd);
	}
	return (0);
}
