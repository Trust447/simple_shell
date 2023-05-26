#include "main.h"
#include "funcs.h"

/**
 * Reads data from a stream into a buffer.
 * @ptr -  Points to the buffer where inputs stored
 * @size: Size of each input read
 * @count: Number of inputs to be read
 * @ stream: Poits to input source
 * Return: number of commands read
 */


size_t reader(void *ptr, size_t size, size_t count, FILE *stream)
{	
	size_t read;
	read = fread(ptr, size, count, stream);
	return (read);
}


/**
 * reader - copies strings from one variablele to another
 * @dest: destination string buffer
 * @src: Source
 * @n: stores numer of characters to be copied
 * Return: keeps destination string
 */

char *my_strncpy(char *dest, const char *src, size_t n)
{
	strncpy(dest, src, n);
	return (dest);
}

/**
 * my_fprintf - Prints to stderr
 * @stream: Output stream
 * @format: format string
 * @Return: number of characters printed or a negative value if an error occurred
 */

int my_fprintf(FILE *stream, const char *format, ...)
{
	va_list args;
	int result;
	va_start(args, format);
	result = vfprintf(stream, format, args);
	va_end(args);
	return (result);
}

