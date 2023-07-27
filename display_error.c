#include "main.h"

/**
 * dis_err - Display an error message for unrecognized commands.
 * @prog: The name of the shell program (argv[0]).
 * @cmd: The command that caused the error.
 */

void dis_err(char *prog, char *cmd)
{
	write(2, prog, _strlen(prog));
	write(2, ": 1: ", 5);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}
