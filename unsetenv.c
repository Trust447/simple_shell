#include "main.h"
#include <mine.h>

/**
 * unsetenv_op - checks for env commands an unset the variables
 *
 * @ac: keeps cthe count of commands or arguments
 * @argv: holds the the actual commands or arguments
 *
 * Return 0 when succesful
 */

int unsetenv_op(int ac, char **argv)
{
	int unset_status;
	char *var = argv[1];

	 /* check for environmental variables and values */
	if (ac < 2)
	{
		my_fprintf(stderr, "syntax error");
		return (-1);
	}


	unset_status = unsetenv(var);
	/* if setenv is not successful, print error message */
	if (unset_status != 0)
	{
		my_fprintf(stderr, "AN ERROR OCCURRED");
		return (-1);

	}


	return (0);
}
