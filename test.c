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
	int c;
//	size_t len;
	char *deli = " \n";
	char *cmd_cpy;
	int exec_val;
	int num_tokens;

//	if (ac > 1)
//		cmd_line_args(ac, av);

	while (1)
	{
		prompt();

		cmd = get_cmd();
		cmd_cpy = malloc(sizeof(char) * (_strlen(cmd) + 1));
		if (cmd_cpy == NULL)
		{
			return (-1);
		}

		_strcpy(cmd_cpy, cmd);

		tok = strtok(cmd_cpy, deli);
		num_tokens = count_tok(cmd_cpy, deli);
		printf("number of tokens %d\n", num_tokens);
//		for (c = 0; tok != NULL; c++)
//		{
//		
//			tok = strtok(NULL, deli);
//		} 
//		av = malloc(sizeof (char*) * (c + 1));
//
//		tok = strtok(cmd, deli);
//		printf("number of token = %d\n", c);
//
//		while(tok != NULL)
//		{
//			av[i] = malloc(sizeof (char) * _strlen(tok));
//			if (av[i] == NULL)
//			{
//				perror("Error");
//				free(cmd);
//			}
//			 _strcpy(av[i], tok);
//			 i++;
//			 tok = strtok(NULL, deli);
//		}
//		_strcpy(av[i], tok);
//
//		exec_val = execve(av[0], av, NULL);
//		if (exec_val == -1)
//		{
//			perror("Error");
//		}
//
//		free(cmd);
//		free(cmd_cpy);
	}
	return (0);
}

