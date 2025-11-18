#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(const char c);
int print_char(va_list arg);
int print_str(va_list arg);
int print_int(va_list arg);

typedef struct _printf_struct
{
	char *conversion;
	int (*function)(va_list argument);
} print;

#endif
