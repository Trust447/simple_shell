#include "main.h"

/**
* _strcpy - fuction that copies strings from one variable to another
*
* @copy : Destination
* @main : Source
* Returns void
*/
void _strcpy(char *copy, const char *main)
{
	while (*main != '\0')
	{
		*copy = *main;
		copy++;
		main++;
	}
	*copy = '\0';
}

/**
 * _strlen - Returns the length of a string.
 * @str: string.
 *
 * Return: Length.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * toklen - returns the length of tokens generated
 * @tok: string.
 * @deli: the delimeter
 * 
 * Return: length
 */
size_t toklen(char *tok, const char *deli)
{
	size_t c;

	for (c = 0; tok != NULL; c++)
	{
		tok = strtok(NULL, deli);
	}
	return c;
}

/**
 * tokcpy - stores token into pointer of arrays.
 * @tok: string
 * @av: the memory alloated
 * @deli: delimeter
 * 
 * Return: NULL
 */
void tokcpy(char *tok, char **av, const char *deli)
{
	int i = 0;

	while(tok != NULL)
	{
		av[i] = malloc(sizeof(char) * (_strlen(tok) + 1));
		if (av[i] == NULL)
		{
			perror("Error allocating memory");
		}

		_strcpy(av[i], tok);
		tok = strtok(NULL, deli);
		i++;
	}
	av[i] = NULL;
}
