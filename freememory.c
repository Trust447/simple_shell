#include "main.h"

/**
 * free_memory - this fuction release memory
 * @buf: pointer to memory allocated
 * @str: pointer to string copy
 * @argv: pointer to agument vector
 * @tok_count: get length og argv
 * Return: 0 on success
 */

void free_memory(char *buf, char *str, char **argv, int tok_count)
{
int i;
free(buf);
free(str);
for (i = 0; i < tok_count; i++)
{
free(argv[i]);
}
free(argv);
}
