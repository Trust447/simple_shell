#include "main.h"

/**
 * get_cmd - reds line from the standard input
 *
 * Returns: buf
 */
char *get_cmd(void)
{
	char *buf = NULL;
	size_t size = 0;
	ssize_t n = 0;

	n = getline(&buf, &size, stdin);
	if (n == -1)
	{
		exit(0);
	}
	if (n > 0 && buf[n - 1] == '\n')
		buf[n - 1] = '\0';
	return (buf);
}

/**
 * _getenv - get the environmental variable value for the provided arg.
 * @c: the environ name (const char *)
 *
 * Return: returns the value of the env variable
 */
char *_getenv(const char *c)
{
	char **envir = environ;
	size_t i = 0;
	size_t len_c = _strlen(c);

	i = 0;
	while (envir[i] != NULL)
	{
		if (_strncmp(envir[i], c, len_c) == 0 && envir[i][len_c] == '=')
			return (envir[i] + len_c + 1);
		i++;
	}
	free(envir);
	return (NULL);
}
