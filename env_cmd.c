#include "main.h"
#include "funcs.h"

/**
 * setenv_op - to set enviromental variables
 * @ac: used to check number of commands passed in to the program
 * @argv: holds the actual commands passed into the program
 * Return 0  when succeful
 */

int setenv_op(char *variable, char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		my_fprintf(stderr, "Invalid\n");
		return (-1);
	}
	return (0);
}


/**
 * unsetenv_op - to unset enviromental variables
 * @char: keps variable
 * Return: 0 if successful
 */

int unsetenv_op(const char *variable)
{
	if (variable == NULL)
	{
		my_fprintf(stderr, "Invalid\n");
		return (-1);
	}
	if (unsetenv(variable) != 0)
	{	
		my_fprintf(stderr, "setenv Failed\n");
		return (-1);
	}
	return (0);
}
