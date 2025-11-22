#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(const char c);
int print_char(va_list arg, char *buffer, unsigned int *iptr);
int print_str(va_list arg, char *buffer, unsigned int *iptr);
int print_int(va_list arg, char *buffer, unsigned int *iptr);
int print_unsigned(va_list arg, char *buffer, unsigned int *iptr);
int print_hex_l(va_list arg, char *buffer, unsigned int *iptr);
int print_hex_u(va_list arg, char *buffer, unsigned int *iptr);
int print_octal(va_list arg, char *buffer, unsigned int *iptr);
int print_binary(va_list arg, char *buffer, unsigned int *iptr);
int print_ascii(va_list arg, char *buffer, unsigned int *iptr);
int print_memory(va_list arg, char *buffer, unsigned int *iptr);
int printbuffer(char *buffer, unsigned int buffersize);
unsigned int checkbuffer(char *buffer, unsigned int *iptr, unsigned int write_size);

typedef struct _printf_struct
{
	char *conversion;
	int (*function)(va_list argument, char *buffer, unsigned int *iptr);
} print;

#endif
