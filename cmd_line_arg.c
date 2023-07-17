#include <stdio.h>
#include <unistd.h>
/*
 * cmd_line_args - Handles command line arguements
 *
 * @ac: Argument count
 * @av: Argument vector
 * Return: void
 */
void cmd_line_args(int ac, char **av)
{
	int index;
	int len = 0;
	char *str;

	for (index = 0; index < ac; index++)
	{
		str = av[index];
		while(*str != '\0')
		{
			len++;
			str++;
		}	
		write(1, av[index], len);
		write(1, "\n", 1);
	}
}
