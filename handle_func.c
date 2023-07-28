#include "main.h"

/**
 * han_spec - handles cmd with slash or . (special characters)
 * @first: the command
 *
 * Return: return the command if there is special or NULL if there isn't
 */
char *han_spec(char *first)
{
	if ((stat(first, &find) == 0) && (*first == '/' || *first == '.'))
		return (first);
	return (NULL);
}

/**
 * han_token - Tokenizes a string into an array of strings
 *
 * @cmd : The input string to be tokenized
 *
 * Return : char pointers
 */

char **han_token(char *cmd)
{
	char **arr = NULL;
	size_t len = 0;
	char *tok = NULL;
	int i = 0;

	len = _strlen(cmd);
	arr = malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		exit(0);

	tok = strtok(cmd, " \n");
	while (tok != NULL)
	{
		arr[i] = tok;
		tok = strtok(NULL, " \n");
		i++;
	}
	arr[i] = NULL;
	return (arr);
}


/**
 * han_builtin - Execute built-in shell commands.
 *
 * @param : An array of strings representing the command and its arguments.
 * @hsh : The name of the shell.
 * @envp : An array of strings containing the environment variables.
 *
 * Return : an integer value based on the command execution
 */
int han_bulltin(char **param, char *hsh, char **envp)
{
	int i = 0;
	size_t len = 0;

	if (_strcmp(param[0], "exit") == 0)
		return (0);
	if (_strcmp(param[0], "env") == 0)
	{
		if (envp == NULL)
		{
			dis_err(hsh, param[0]);
			return (-1);
		}

		while (envp[i] != NULL)
		{
			len = _strlen(envp[i]);
			write(1, envp[i], len);
			write(1, "\n", 2);
			i++;
		}
		return (1);
	}
	return (5);
}
