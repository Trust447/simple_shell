#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

size_t reader(void *ptr, size_t size, size_t count, FILE *stream);
char *my_strncpy(char *dest, const char *src, size_t n);
int my_fprintf(FILE *stream, const char *format, ...);
ssize_t readline(char **buf, size_t *number);

#endif
