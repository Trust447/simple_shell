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
    char *cmd, *tok, *path, *cmd_cpy, *deli = " \n";;
	char **arr;
    int status, i = 0;
    size_t len;
    pid_t pid;

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
            return (1);
        }

        cmd_cpy = _strdup(cmd);
        tok = strtok(cmd_cpy, deli);
        tokcpy(tok, arr, deli);

        path = cmd_path(arr[0]);
        if (path == NULL)
        {
            perror("./shell ");
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
            break;
        }
        else if (pid == 0)
        {
            execve(path, (char* const*)arr, (char* const*)environ);
	    free(path);
            perror("./shell ");
            exit(1);
        }
        else
            wait(&status);

        // Free the memory for av_array
        free_av(arr);
        free(cmd);
        free(cmd_cpy);
    }
    return (0);
}
