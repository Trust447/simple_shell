#include "main.h"

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
