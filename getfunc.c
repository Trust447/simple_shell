#include "main.h"

/**
 * get_cmd - reds line from the standard input
 *
 * Return: buf which holds command
 */
char *get_cmd(void)
{
	char *buf = NULL;
	size_t size = 0;
	ssize_t n = getline(&buf, &size, stdin);

	if (n == -1)
	{
		free(buf);
		if (isatty(STDIN_FILENO))
			write(1, "\n", 2);
		exit(0);
	}
	if (n > 0 && buf[n - 1] == '\n')
		buf[n - 1] = '\0';
	return (buf);
}

/**
 * _getenv - get the environmental variable value for the provided arg.
 * @c: the environ name (const char *)
 * @envp : array that will hold the env
 *
 * Return: returns the value of the env variable
 */
char *_getenv(const char *c, char *envp[])
{
	size_t i = 0;
	size_t len_c = _strlen(c);

	i = 0;
	while (envp[i] != NULL)
	{
		if (_strncmp(envp[i], c, len_c) == 0 && envp[i][len_c] == '=')
			return (envp[i] + len_c + 1);
		i++;
	}
	return (NULL);
}
