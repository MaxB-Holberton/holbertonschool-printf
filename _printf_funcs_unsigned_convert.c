#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

unsigned int write_octal(unsigned int n, char *buffer, unsigned int i)
{
	unsigned int count = 0;

	if ((n / 8) != 0)
	{
		count += write_octal((n / 8), buffer, i);
		count++;
	}
	buffer[count + i] = ((n % 8) + '0');
	return (count);
}
int print_octal(va_list arg, char *buffer, unsigned int *iptr)
{
	unsigned int i;
	unsigned int n;

	n = va_arg(arg, unsigned int);

	i = checkbuffer(buffer, iptr, (sizeof(n) * sizeof(unsigned int)));
	i += write_octal(n, buffer, i);
	*iptr = i;
	return(i);
}

unsigned int hex_lower(unsigned int n, char *buffer, unsigned int i)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
	{
			count += hex_lower((n / 16), buffer, i);
			count++;
	}
	if ((n % 16) > 9)
		buffer[count + i] =(((n % 16) - 10) + 'a');
	else
		buffer[count + i] = (n % 16 + '0');
	return (count);
}
unsigned int hex_upper(unsigned int n, char *buffer, unsigned int i)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
	{
		count += hex_upper((n / 16), buffer, i);
		count++;
	}
	if ((n % 16) > 9)
		buffer[count + i] = (((n % 16) - 10) + 'A');
	else
		buffer[count + i] = (n % 16 + '0');
	return (count);
}
int print_hex_l(va_list arg, char *buffer, unsigned int *iptr)
{
	unsigned int i;
	unsigned int n;
	unsigned int count = 0;

	n = va_arg(arg, unsigned int);

	i = checkbuffer(buffer, iptr, (sizeof(n) * sizeof(unsigned int)));
	count += hex_lower(n, buffer, i);
	(*iptr) = count + i;
	return(count);
}

int print_hex_u(va_list arg, char *buffer, unsigned int *iptr)
{
	unsigned int i;
	unsigned int n;
	unsigned int count = 0;

	n = va_arg(arg, unsigned int);

	i = checkbuffer(buffer, iptr, (sizeof(n) * sizeof(unsigned int)));
	count += hex_upper(n, buffer, i);
	(*iptr) = count + i;
	return(count);
}
unsigned int write_binary(unsigned int n, char *buffer, unsigned int i)
{
	unsigned int count = 0;

	if ((n / 2) != 0)
	{
		count += write_binary((n / 2), buffer, i);
		count++;
	}
	buffer[count + i] = ((n % 2) + '0');
	return (count);
}
int print_binary(va_list arg, char *buffer, unsigned int *iptr)
{
	unsigned int i;
	unsigned int n;
	unsigned int count = 0;

	n = va_arg(arg, unsigned int);

	i = checkbuffer(buffer, iptr, (sizeof(n) * sizeof(unsigned int)));
	count += write_binary(n, buffer, i);
	(*iptr) = count + i;
	return(count);
}
