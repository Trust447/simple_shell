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
	(void) ac, av;
	char *cmd, *tok, *path, *fmt, *cmd_cpy, *deli = " \n";
	char **arr;
	int status, i = 0;
	size_t len;
	pid_t  pid, wait_pid;

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

        // Allocate memory for av using malloc
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

	if (exit_shell(arr))
	{
		free(cmd);
		free(cmd_cpy);
		free_av(arr);
		break;
	}

	fmt = han_slash(arr[0]);

        path = cmd_path(fmt);
        if (path == NULL)
        {
            perror(arr[0]);
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

            execve(path, (char* const*)arr, (char* const*)environ);
            perror(arr[0]);
	    free(path);
	    free_av(arr);
	    free(cmd_cpy);
	    free(cmd);
            exit(1);
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
        // Free the memory for av_array
        free_av(arr);
        free(cmd);
	free(cmd_cpy);
   
    }
    return (0);
}
