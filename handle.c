#include "main.h"

/**
 * han_slash - handles cmd with slash
 * @first: the command
 *
 * Return: return the formatted command
 */
char *han_slash(char *first)
{
    char *token[] = {"", NULL}; /* Array to store the tokens (assuming a maximum of 10 tokens)*/
    int i = 0;
    int count = 0;
    char *temp = NULL; 
    char *dup = NULL;

    /* Using strtok to count the number of tokens*/
    dup = _strdup(first);
    temp = strtok(dup, "/");
    while (temp != NULL) {
        token[i++] = temp;
        count++;
        temp = strtok(NULL, "/");
    }

    if (count <= 1)
    {
	free(dup);
	return first;
    }

    /* Printing the individual parts saved in the array*/
    if (_strcmp(token[0], "bin") == 0 && first[0] == '/')
    {
	return token[1];
    }

    free(dup);
    return first;
}
