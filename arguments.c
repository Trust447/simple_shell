#include "main.h"

/**
 * arguments - handles arguments given to the program
 *
 * @argc: holds the actual arguments counter
 *
 * Return: 0 on success
 */


int arguments(int argc)
{
	/*declear an index to access individual arguments*/
	int arg_counter = 0;

	/*check and print out each arguments*/
	while (arg_counter < argc)
	{
		arg_counter++;
	}
	return (arg_counter);
}

/**
 * getlinefunc - this handles getline command
 *
 * @buf: pointer to the buffer memory
 * @number: lenght of the string
 * Return: 0 on success
 */

ssize_t getlinefunc(char **buf, size_t number)
{
	/*this get string for the terminal*/
	ssize_t linelen;

	linelen = getline(buf, &number, stdin); /*get the length of the buffer*/

	if (linelen == -1)
	{
		perror("Existing from the shell");
		exit(EXIT_FAILURE);
	}

	return (linelen);
}
/**
 * creatingmemory - this create memory using malloc
 *
 * @linelen: get the lenth of pointer
 * Return: 0 on success
 */

char *creatingmemory(ssize_t linelen)
{
	char *str = NULL;

	if (linelen != -1)
	{
		str = malloc(sizeof(char) * linelen);
		if (str == NULL)
		{
			perror("Error creating memory"); /*if null print error */
			exit(EXIT_FAILURE);
		}
	}
	return (str);
}
