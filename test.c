#include "main.h"

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
	char *tokenize;
	int i = 0;
	size_t len;
	char *deli = " ";
	char *cmd_cpy;
	char *argv[] = {"", NULL};

	if (ac > 1)
		cmd_line_args(ac, av);

	while (1)
	{
		prompt();
		cmd = get_cmd();
		cmd_cpy = malloc(sizeof(char) * (_strlen(cmd) + 1));
		if (cmd_cpy == NULL)
			return (-1);

		_strcpy(cmd_cpy, cmd);

		tokenize = strtok(cmd_cpy, deli);
		while(tokenize != NULL)
		{
			argv[i] = tokenize;
			i++;
			tokenize = strtok(NULL, deli);
		}
		free(cmd);
		free(cmd_cpy);
	}
	return (0);
}

