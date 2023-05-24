#include "main.h"

/**
 * arguments - handles arguments given to the program
 *
 * @ac: takes count of argument passed to the program
 *
 * @argv: holds the actual arguments
 *
 * Return: 0 on success
 */


int arguments(int ac, char **argv)
{
	/*declear an index to access individual arguments*/
	int arg_counter = 0;

	/*check and print out each arguments*/
	while (arg_counter < ac)
	{
		write(STDOUT_FILENO, argv[arg_counter], strlen(argv[arg_counter]));
		write(STDOUT_FILENO, "\n", 1);
		arg_counter++;
	}
	return (0);
}
