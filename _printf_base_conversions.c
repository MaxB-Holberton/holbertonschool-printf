#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

unsigned int write_octal(unsigned int n)
{
	unsigned int count = 0;

	if ((n / 8) != 0)
		count = write_octal((n / 8));

	count += _putchar((n % 8) + '0');
	return (count);
}
int print_octal(va_list arg)
{
	return(write_octal(va_arg(arg, unsigned int)));
}

unsigned int hex_lower(unsigned int n)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
			count = hex_lower((n / 16));

	if ((n % 16) > 9)
		count += _putchar(((n % 16) - 10) + 'a');

	else
		count += _putchar((n % 16) + '0');

	return (count);
}
unsigned int hex_upper(unsigned int n)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
		count = hex_upper((n / 16));

	if ((n % 16) > 9)
		count += _putchar(((n % 16) - 10) + 'A');

	else
		count += _putchar((n % 16) + '0');

	return (count);
}
int print_hex_l(va_list arg)
{
	return(hex_lower(va_arg(arg, unsigned int)));
}

int print_hex_u(va_list arg)
{
	return(hex_upper(va_arg(arg, unsigned int)));
}
unsigned int write_binary(unsigned int n)
{
	unsigned int count = 0;

	if ((n / 2) != 0)
		count = write_binary((n / 2));

	count += _putchar((n % 2) + '0');
	return (count);
}
int print_binary(va_list arg)
{
	return(write_binary(va_arg(arg, unsigned int)));
}


