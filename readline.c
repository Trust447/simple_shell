#include "main.h"
#include "functions.h"
/**
 * readline - is  Custom getline function to read a line from standard input
 * This function stores chunks of characters
 * Return: line read will be returned if sucessful, NULL will be returned if failed
 *
 */
ssize_t readline(char **buf, size_t *number)
{
	static char storage[1500];
	int storage_index = 0;
	int storage_count = 0;
	size_t storage_size = sizeof(storage);
	int line_index;
	ssize_t line_length;
	size_t i;
	
	if (storage_index >= storage_count)
	{
		storage_count = reader(storage, sizeof(char), storage_size, stdin);
		if (storage_count == 0)
		return (-1);
	}
		storage_index = 0;
	
	line_index = storage_index;
	while (line_index < storage_count && storage[line_index] != '\n')
	{
		line_index++;
	}
	line_length = line_index - storage_index;
	*buf = (char *)malloc(line_length + 1);
	i = 0;
	while (i < (size_t)line_length)
	{
		(*buf)[i] = storage[storage_index + i];
		i++;
	}
	(*buf)[line_length] = '\0';
	storage_index = line_index + 1;

	*number = line_length;

	return line_length;
}
