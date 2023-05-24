#include "main.h"

/**
 * filestat - checkes if file is in path
 * @filepath: pointer filepath
 * Return: 0 on success
 */

/*checking if a command exist */
int filestat(const char *filepath)
{

if (access(filepath, F_OK) != -1)
{
return (1);
}
return (2);
}

/**
 * getfileinpath - handles file path
 * @filename: pointer filename
 * Return: 0 on success
 */


char *getfileinpath(const char *filename)
{
const char *delimseparator = ":";
char *tokpath;
char *path = cust_evn("PATH");
char *copypath = strdup(path);
char *filepath = NULL;

tokpath = strtok(copypath, delimseparator);
while (tokpath != NULL)
{
size_t path_length = strlen(tokpath);
size_t filename_length = strlen(filename);
filepath = malloc(path_length + filename_length + 2);
if (filepath == NULL)
{
perror("Error creating memory");
exit(EXIT_FAILURE);
}
strcpy(filepath, tokpath);
strcat(filepath, "/");
strcat(filepath, filename);

if (access(filepath, F_OK) != -1)
{
break;
}

free(filepath);
filepath = NULL;
tokpath = strtok(NULL, delimseparator);
}

free(copypath);
return (filepath);
}


