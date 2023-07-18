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
	ssize_t n;
	char *str_buf;
	size_t buf_len;

	n = getline(&buf, &size, stdin);
	if (n == -1)
	{
		perror("exiting...");
		exit(EXIT_FAILURE);
	}
	str_buf = buf;
	buf_len = _strlen(str_buf);
	write(1, buf, buf_len);
	return (buf);
}