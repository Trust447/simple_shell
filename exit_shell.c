#include "main.h"
/**
 * exit_shell - fuction that exits shell
 *
 * @arr[0] : first command to be compared
 * Returns void
 */

void exit_shell(char **arr)
{
	if (_strcmp(arr[0], "exit") == 0)
	{
		exit (0);
	}
}
