#include "main.h"

/**
 * run - excute the command
 *
 * @arr[0] : first command to be compared
 * Returns void
 */
int run(char **params, char *hsh, char *envp[])
{
	pid_t  pid = 0;
	int wait_stat;

	pid = fork();
	if (pid < 0)
		dis_err(hsh, " ");
	else if (pid == 0)
	{
		if (execve(params[0], params, envp) == -1)
		{
			dis_err(hsh, params[0]);
			exit(1);
		}
	}
	else
	{
		wait(&wait_stat);
		if (wait_stat != 0)
			if (!isatty(0))
			{
				_exit(2);
			}
	}
	return (1);
}
