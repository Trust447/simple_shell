#include "main.h"

/**
 * cmd_path - get the command full path.
 * @cmd: the command
 *
 * Return: return the full path
*/
char *cmd_path(const char *cmd)
{
    char *path, *dir, *get_cmd_path;

    path = _getenv("PATH");
    if (path == NULL)
        return NULL;

    dir = strtok(path, ":");
    while (dir != NULL)
    {
        get_cmd_path = get_path(dir, cmd);
        if (get_cmd_path != NULL)
            return get_cmd_path;
        dir = strtok(NULL, ":");
    }
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
    size_t dir_len, cmd_len;
    char *new_path;
    
    cmd_len = _strlen(cmd);
    dir_len = _strlen(dir);

    /* Added 2 for the '/' and end of line character */
    new_path = malloc(dir_len + cmd_len + 2);
    if (new_path == NULL)
        return NULL;

    _strcpy(new_path, dir);
    _strcat(new_path, "/");
    _strcat(new_path, cmd);

    // Check if the command path exists and is executable
    if (access((const char*)new_path, X_OK) == 0)
        return (char *)new_path;
    else
    {
        free(new_path);
        return NULL;
    }
}
