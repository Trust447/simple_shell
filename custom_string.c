#include "main.h"

/**
* _strcpy - fuction that copies strings from one variable to another
*
* @copy : Destination
* @main : Source
* Returns void
*/
void _strcpy(char *copy, char *main)
{

	while (*main != '\0')
	{
		*copy = *main;
		copy++;
		main++;
	}
	*copy = '\0';
}

/**
 * _strlen - Returns the length of a string.
 * @str: string.
 *
 * Return: Length.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str++)
		len++;

	return (len);
}
