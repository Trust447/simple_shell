#include "main.h"

/**
 * _strcpy - fuction that copies strings from one variable to another
 *
 * @copy : Destination
 * @main : Source
 * Return: copy on success
 */
char *_strcpy(char *copy, const char *main)
{
	while (*main != '\0')
	{
		*copy = *main;
		copy++;
		main++;
	}
	*copy = '\0';
	return (copy);
}

/**
 * _strlen - Returns the length of a string.
 * @str: string.
 *
 * Return: Lenght
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * _strcat - concat string
 * @dest: param
 * @src: param
 * Return: the pointer
 */
char *_strcat(char *dest, const char *src)
{
	int a, b;

	a = 0;

	while (dest[a])
		a++;

	for (b = 0; src[b]; b++)
	{
		dest[a] = src[b];
		a++;
	}
	return (dest);
}
