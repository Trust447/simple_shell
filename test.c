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
	char *tok;
	int i = 0;
//	size_t len;
	char *deli = " \n";
	char *cmd_cpy;
	int exec_val;
	int f;


	//if (ac > 1)
	//	cmd_line_args(ac, av);

	while (1)
	{
		prompt();

		cmd = get_cmd();
		cmd_cpy = malloc(sizeof(char) * (_strlen(cmd) + 1));
		if (cmd_cpy == NULL)
			perror("Error");

		_strcpy(cmd_cpy, cmd);

		tok = strtok(cmd_cpy, deli);

		size_t len = toklen(tok, deli);

		av = malloc(sizeof(char*) * (len + 1));
		if (av == NULL)
		{
			perror("Error");
			free(cmd_cpy);
		}

		tok = strtok(cmd, deli);
		tokcpy(tok, av, deli);
		//for (size_t i = 0; av[i] != NULL; i++) {
			//printf("%s\n", av[i]);
		//}
		av[0] = tok;

		exec_val = execve(av[0], av, NULL);
		if (exec_val == -1)
		{
			
			perror("./shell");
		}
		/*for (f = 0; av[i] != NULL; i++)
		{
			free(av[i]);
		*
		}
		*/
		free(cmd);
		free(cmd_cpy);
	}
	return (0);
}
