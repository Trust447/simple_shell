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
	ssize_t cmd_len;
	char *cmd_cpy;
	char *d = " ";
	char *tok_val;
	int tok_count = 0;

	if (ac > 1)
	{

		cmd_line_args(ac, av);
	}

	while (1)
	{
		prompt();
		cmd = get_cmd();
		cmd_len = cmd
		cmd_cpy = malloc(sizeof(char) * cmd_len);
		if (cmd_cpy == NULL)
		{
			perror("error");
			return (-1)
		}
		_strcpy(cmd_cpy, cmd);

		for (tok_val = strtok(cmd, d); tok_val != NULL; tok_val = (NULL, d)
		{
			tok_count++;
		
		}
		tok_count++

		free(cmd);

		
	}
	return (0);
}
