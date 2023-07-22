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
    char *cmd, *tok, *cmd_cpy;
		char **arr;
    int i = 0;
    char *deli = " \n";
    size_t len;

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

        execve(arr[0], (const char * const *)arr, NULL);

        perror("./shell ");

        // Free the memory for av_array
        free_av(arr);

        free(cmd);
        free(cmd_cpy);
    }

