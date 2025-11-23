#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
/*
 *
 *
 *
 */
unsigned int write_octal(unsigned int n, char *buffer, unsigned int *iptr)
{
	unsigned int count = 0;

	if ((n / 8) != 0)
	{
		count = write_octal((n / 8), buffer, iptr);
		count++;
	}
	buffer[(*iptr)++] = ((n % 8) + '0');
	return (count);
}
/*
 *
 *
 *
 */
int print_octal(va_list arg, char *buffer, unsigned int *iptr)
{
	return(write_octal(va_arg(arg, unsigned int), buffer, iptr));
}
/*
 *
 *
 *
 */
unsigned int hex_lower(unsigned int n, char *buffer, unsigned int *iptr)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
	{
			count = hex_lower((n / 16), buffer, iptr);
			count++;
	}
	if ((n % 16) > 9)
		buffer[(*iptr)++] = (((n % 16) - 10) + 'a');

	else
		buffer[(*iptr)++] =((n % 16) + '0');

	return (count);
}
/*
 *
 *
 *
 */
unsigned int hex_upper(unsigned int n, char *buffer, unsigned int *iptr)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
	{
		count = hex_upper((n / 16), buffer, iptr);
		count++;
	}
	if ((n % 16) > 9)
		buffer[(*iptr)++] = (((n % 16) - 10) + 'A');

	else
		buffer[(*iptr)++] =((n % 16) + '0');

	return (count);
}
/*
 *
 *
 *
 */
int print_hex_l(va_list arg, char *buffer, unsigned int *iptr)
{
	return(hex_lower(va_arg(arg, unsigned int), buffer, iptr));
}
/*
 *
 *
 *
 */
int print_hex_u(va_list arg, char *buffer, unsigned int *iptr)
{
	return(hex_upper(va_arg(arg, unsigned int), buffer, iptr));
}
/*
 *
 *
 *
 */
unsigned int write_binary(unsigned int n, char *buffer, unsigned int *iptr)
{
	unsigned int count = 0;

	if ((n / 2) != 0)
	{
		count = write_binary((n / 2), buffer, iptr);
		count++;
	}
	buffer[(*iptr)++] = ((n % 2) + '0');
	return (count);
}
/*
 *
 *
 *
 */
int print_binary(va_list arg, char *buffer, unsigned int *iptr)
{
	return(write_binary(va_arg(arg, unsigned int), buffer, iptr));
}


