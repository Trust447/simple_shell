#include "main.h"
#include "functions.h"

/**
 * env_pro - to set enviromental variables
 * @ac: used to check number of commands passed in to the program
 * @argv: holds the actual commands passed into the program
 * Return 0  when succeful
 */

int env_pro(int ac, char **argv)
{
	char *var = argv[1];
	char *val;
	int status;
	/* checking if the commands entered are correct*/
	if (ac < 3)
	{
		my_fprintf(stderr, "syntax error");
		return (-1);
	}
	/* set enviromental variables*/
	val = argv[2];
	status = setenv(var, val, 1);
	/* if it was not successful send error to stderr*/
	if (status != 0)
	{
		my_fprintf(stderr, "AN ERROR OCCURRED");
		return (-1);
	}
	return (0);
}
