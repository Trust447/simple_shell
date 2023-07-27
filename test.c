#include "main.h"

/**
 * main - where the simple shell program begins
 *
 * @ac: Holds the number of command line arguments
 * @av: Array that holds the values of the command line arguments
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[], char *envp[])
{
	char *cmd_line = NULL, *path = NULL;
	char **arr = NULL;
	int loop = 1;

	while (loop != 0)
	{
		if (isatty(0))  /* print prompt */
			prompt();

		cmd_line = get_cmd();
		if (_strcmp(cmd_line, "\n") == 0)
		{
			free(cmd_line);
			continue;
		}

		arr = han_token(cmd_line);  /* handle tokenization */
		loop = han_bulltin(arr, argv[0], envp);
		if (loop == 5)
		{
			path = cmd_path(arr[0], envp);
			if (path != NULL)
			{
				arr[0] = path; /* make the first arg the path feteched */
				loop = run(arr, argv[0], envp);
			}
			else
			{
				dis_err(argv[0], arr[0]);
				if(!isatty(0))
				{
					free(cmd_line);
					free(arr);
					_exit(45);
				}
			}
		}

		free(cmd_line);
		free(arr);
	}
	return (0);
}
