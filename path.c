#include "main.h"

/**
 * cmd_path - get the command full path.
 * @cmd: the command
 *
 * Return: return the full path
*/
//char *cmd_path(const char *cmd)
//{
//	char *path, *dir, *get_cmd_path;
  //   	char* path_copy;
//
//
  //  	path = _getenv("PATH");
    //	if (path == NULL)
//	{
//		printf("Error: PATH environment variable not set.\n");
  //      	return NULL;
//	}
//
  //   	path_copy = strdup(path);
    // 	if (path_copy == NULL) 
     //	{
//	     	perror("Error");
//	     	return NULL;
  //   	}	
//
  //  	dir = strtok(path, ":");
    //	while (dir != NULL)
    //	{
      //  	get_cmd_path = get_path(dir, cmd);
	//	printf("Searching in directory: %s\n", dir);
        //	if (get_cmd_path != NULL)
	//	{
	//		free(path_copy);
	//		printf("Found command path: %s\n", get_cmd_path);
          //  		return get_cmd_path;
	//		
	//	}
        //	dir = strtok(NULL, ":");
    //	}
    //	free(path_copy);
   //	return NULL;
//}

char *cmd_path(char *cmd)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_len, dir_len;
	struct stat buf;

	path = _getenv("PATH"); 

	if (path)
	{
		path_copy = strdup(path);
		command_len = _strlen(cmd);
		path_token = strtok(path_copy, ":");
		while(path_token != NULL)
		{
			dir_len = _strlen(path_token);
			file_path = malloc(command_len + dir_len + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");
			if (stat(file_path, &buf) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(cmd, &buf) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	 return (NULL);
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
	{
		return NULL;
	}	

    _strcpy(new_path, dir);
    _strcat(new_path, "/");
    _strcat(new_path, cmd);

    // Check if the command path exists and is executable
    printf("Executing command: %s\n", new_path);
    if (access((const char*)new_path, X_OK) == 0)
        return (char *)new_path;
    else
    {
        free(new_path);
	 printf("Command not found or not executable.\n");
        return NULL;
    }
}
