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
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}
