#ifndef MINE_H
#define MINE_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

size_t reader(void *ptr, size_t size, size_t count, FILE *stream)
{
	size_t read;
	read = fread(ptr, size, count, stream);
	return (read);
}	


char *my_strncpy(char *dest, const char *src, size_t n)
{
	 strncpy(dest, src, n);
	 return (dest);

}


int stderror(const char *format, ...)
{
	int error;
	va_list args;
	va_start(args, format);
	error = fprintf(stderr, format, args);
	va_end(args);
	return (error);

}


int my_fprintf(FILE *stream, const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int result = vfprintf(stream, format, args);
	va_end(args);
	return result;
}


size_t my_fread(void *ptr, size_t size, size_t count, FILE *stream)
{

	size_t bytes_read = fread(ptr, size, count, stream);
	return bytes_read;

}



#endif
