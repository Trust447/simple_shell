#include "main.h"

/**
 * tokenizeInput - handles agrument tokenzation
 * @input: cmd entered
 * @argv: agruement vector
 * @argc: argument counter
 * Return: 0 on success
 */


void tokenizeInput(char *input, char ***argv, int *argc)
{
	char *ctoken;
	int tok_count;
	int counting;
	const char *delim;

tok_count = 0;
counting = 0;
delim = " \n";

	ctoken = strtok(input, " \n");

	while (ctoken != NULL)
	{
	tok_count++;
	ctoken = strtok(NULL, " \n");
	}
	tok_count++;
	*argv = malloc(sizeof(char *) * tok_count); /* allocating mem */

	if (*argv == NULL)
	{
	perror("Error creating memory location");
	exit(EXIT_FAILURE);
	}

	ctoken = strtok(input, delim); /* splitting string */

	for (counting = 0; ctoken != NULL; counting++)
	{
	(*argv)[counting] = malloc(sizeof(char) * (strlen(ctoken) + 1));
	if ((*argv)[counting] == NULL)
	{
	perror("Error creating memory location");
	exit(EXIT_FAILURE);
	}
	strcpy((*argv)[counting], ctoken);
	ctoken = strtok(NULL, delim);
	}
	(*argv)[counting] = NULL;
*argc = tok_count - 1;
}



/**
 * managetheExitCmd - this exit the shell
 *
 * @argc: argument counter
 * @argv: argument vector
 * Return: exit status on success
 */

void managetheExitCmd(int argc, char **argv)
{
	if (argc >= 2)
	{
		int exit_status = atoi(argv[1]);

		exit(exit_status);

	}
	else
	{
		exit(0);
	}
}


/**
 * manageEnvVariable - this writeout env value
 *
 * @sysenvp: pointer to evn
 */



void manageEnvVariable(char **sysenvp)
{
int i = 0;
	for (i = 0; sysenvp[i] != NULL; i++)
	{
		write(STDOUT_FILENO, sysenvp[i], strlen(sysenvp[i]));
	}

}
