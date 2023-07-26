#include "main.h"

/**
 * _strcmp - compare string
 * @s1: param
 * @s2: param
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' || s2[a] != '\0'; a++)
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);


	return (0);
}

/**
 * _strncmp - compare string with the given lenth
 * @s1: source param const char
 * @s2: target param const char
 * @n: len of string to compare (size_t)
 *
 * Return: returns 0 if true
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strdup - create a duplicate for the data.
 * @data: the string to duplicate
 *
 * Return: the new duplicated string
 */
char *_strdup(const char *data) {
	size_t leng;
	char *dup;

	leng = _strlen(data);

	dup = malloc(sizeof(char *) * (leng + 1) );
	if (dup == NULL)
		return NULL;

	_strcpy(dup, data);
	return dup;
}

/**
 * free_av - this is used to free the memory allocated to av
 * @av: the pointer to the arrays.
 * 
 * Return: None
 */
void free_av(char **arr)
{
	int i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
