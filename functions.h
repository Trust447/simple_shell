#ifndef FUNCTIONS_H
#define FUNCTIONS_H

size_t reader(void *ptr, size_t size, size_t count, FILE *stream);
char *my_strncpy(char *dest, const char *src, size_t n);
int my_fprintf(FILE *stream, const char *format, ...);

#endif /* FUNCTIONS_H */
