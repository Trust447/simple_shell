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
	char *cmd = NULL;
	char *tok = NULL;
	char *path = NULL;
	char *fmt = NULL;
	char *cmd_cpy = NULL;
	char *deli = " \n";
	char **arr = NULL;
	int status = 0;
	size_t len = 0;
	pid_t  pid = 0;
	pid_t wait_pid = 0;
	(void) ac;
	(void) av;

	while (1)
	{
		prompt();

		cmd = get_cmd();
		if (_strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}

		tok = strtok(cmd, deli);
		len = toklen(tok, deli);

		/* Allocate memory for av using malloc*/
		arr = malloc(sizeof(char *) * (len + 1));
		if (arr == NULL)
		{
			perror("Error");
			free(cmd);
			break;
		}

		cmd_cpy = _strdup(cmd);
		tok = strtok(cmd_cpy, deli);
		tokcpy(tok, arr, deli);
		

		fmt = han_slash(arr[0]);
		if (_strcmp("exit", fmt) == 0)
		{
			free(cmd);
			free(cmd_cpy);
			free_av(arr);
			exit(0);
		}

		path = cmd_path(fmt);
		if (path == NULL)
		{
			dis_err(av[0], arr[0]);
			free_av(arr);
			free(cmd);
			free(cmd_cpy);
			continue;
		}

		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			free_av(arr);
			free(cmd);
			free(cmd_cpy);
			free (path);
			break;
		}
		else if (pid == 0)
		{

			execve(path, arr, environ);
			perror(arr[0]);
			free(path);
			free_av(arr);
			free(cmd_cpy);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait_pid = wait(&status);
			if (wait_pid == -1)
			{
				perror("wait failed");
				free_av(arr);
				free(cmd);
				free(path);
				break;
			}

		}
		/* Free the memory for av_array*/
		free_av(arr);
		free(cmd);
		free(cmd_cpy);

	}
	return (0);
}
