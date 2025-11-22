#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(const char c);
int print_char(va_list arg);
int print_str(va_list arg);
int print_int(va_list arg);
int print_unsigned(va_list arg);
int print_hex_l(va_list arg);
int print_hex_u(va_list arg);
unsigned int hex_u_rec(unsigned int n, char *conv);
unsigned int hex_l_rec(unsigned int n, char *conv);
int print_octal(va_list arg);
int print_binary(va_list arg);
int print_ascii(va_list arg);
int print_memory(va_list arg);
char *createbuffer(void);
int writetobuffer(char *str);
void freebuffer(char *createdbuffer);
int printbuffer(char *buffer, unsigned int buffersize);

typedef struct _printf_struct
{
	char *conversion;
	int (*function)(va_list argument);
} print;

#endif
