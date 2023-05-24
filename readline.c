#include "main.h"
#include "mine.h"

/**
 *
 * readline - is  Custom getline function to read a line from standard input
 *
 *  This function stores chunks of characters
 *
 *  Return: line read will be returned if sucessful, NULL will be returned if failed
 */



char *readline(void)
{


	static char storage[1500];
	int storage_index = 0;
	int storage_count = 0;
	char *full_line  = NULL;
	size_t storage_size = sizeof(storage);

	/*refill storage if empty*/
	if (storage_index >= storage_count)
	{
		/* read more characters into storage if it is empty*/
		storage_count = fread(storage, sizeof(char), storage_size, stdin);

		/* check if there are no more characters coming in*/
		if (storage_count == 0)
		{
			return (NULL);
		}

		storage_index = 0;

	size_t line_index = storage_index;

	while (line_index < storage_size && storage[line_index] != '\n')
	{
		 line_index++;
	}

	size_t line_length = line_index - storage_index;
	full_line = (char*)malloc((line_length + 1) * sizeof(char));

	size_t i = 0;

	while (i < line_length)
	{
		full_line[i] = storage[storage_index + i];
		i++;
	}

	full_line[line_length] = '\0';

	 storage_index = line_index + 1;


	}



	return (full_line);

}
