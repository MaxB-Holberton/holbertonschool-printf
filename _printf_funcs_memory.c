#include "main.h"
#include <stdarg.h>
#include <stddef.h>

int print_nil(char *buffer, unsigned int *iptr)
{
	buffer[(*iptr)++] = '(';
	buffer[(*iptr)++] = 'n';
	buffer[(*iptr)++] = 'i';
	buffer[(*iptr)++] = 'l';
	buffer[(*iptr)++] = ')';
	return (5);
}

unsigned int hex(unsigned int n, char *buffer, unsigned int *iptr)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
	{
		count = hex((n / 16), buffer, iptr);
		count++;
	}
	if ((n % 16) > 9)
		buffer[(*iptr)++] = (((n % 16) - 10) + 'a');

	else
		buffer[(*iptr)++] = ((n % 16) + '0');

	return (count);
}

int print_memory(va_list arg, char *buffer, unsigned int *iptr)
{
	unsigned long n;

	n = va_arg(arg, unsigned long);
	if (n == 0)
		return(print_nil(buffer, iptr));

	buffer[(*iptr)++] = '0';
	buffer[(*iptr)++] = 'x';
	return(hex(n, buffer, iptr) + 2);
}

