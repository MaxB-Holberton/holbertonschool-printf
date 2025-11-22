#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
unsigned int memory_hex(unsigned long n, char *conv)
{
	unsigned int i = 0;

	if ((n / 16) != 0)
		i += memory_hex((n / 16), conv);
	if((n % 16) > 9)
		conv[i] = (((n % 16) - 10) + 'a');
	else
		conv[i] = (n % 16 + '0');
	i++;
	return (i);
}
int print_memory(va_list arg)
{
	char *conv;
	int i = 0;
	unsigned long n;

	n = va_arg(arg, unsigned long);

	conv = createbuffer();
	if (conv == NULL)
		return (-1);
	_putchar('0');
	_putchar('x');
	i += memory_hex(n, conv);
	return(printbuffer(conv, i));
}
