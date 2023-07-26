#include "main.h"

/**
 * cmd_path - get the command full path.
 * @cmd: the command
 *
 * Return: return the full path
 */
char *cmd_path(const char *cmd)
{
	char *path = NULL;
	char *dir = NULL;
	char *get_cmd_path = NULL;
	char *path_copy = NULL;

	path = _getenv("PATH");
	if (path == NULL)
		return NULL;

	path_copy = strdup(path);
	if (path_copy == NULL) 
	{
		perror("Error");
		return NULL;
	}

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		get_cmd_path = get_path(dir, cmd);
		if (get_cmd_path != NULL)
		{
			free(path_copy);
			return get_cmd_path;

		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}

/**
 * get_path - check if the path is okay
 * @dir: the directory
 * @cmd: command
 *
 * Return: returns command path
 */
char *get_path(const char *dir, const char *cmd)
{
	size_t dir_len = 0; 
	size_t cmd_len = 0;
	char *new_path = NULL;

	cmd_len = _strlen(cmd);
	dir_len = _strlen(dir);

	/* Added 2 for the '/' and end of line character */
	new_path = malloc(dir_len + cmd_len + 2);
	if (new_path == NULL)
	{
		return NULL;
	}

	_strcpy(new_path, dir);
	_strcat(new_path, "/");
	_strcat(new_path, cmd);

	/* Check if the command path exists and is executable*/
	if (access((const char*)new_path, X_OK) == 0)
		return (char *)new_path;
	else
	{
		free(new_path);
		return NULL;
	}
}
