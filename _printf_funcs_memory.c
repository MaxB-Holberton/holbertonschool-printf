#include "main.h"
#include <stdarg.h>
#include <stddef.h>

int print_nil(void)
{
	unsigned int i = 0;

	i += _putchar('(');
	i += _putchar('n');
	i += _putchar('i');
	i += _putchar('l');
	i += _putchar(')');
	return (i);
}

unsigned int hex(unsigned int n)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
		count += hex((n / 16));

	if ((n % 16) > 9)
		count += _putchar(((n % 16) - 10) + 'a');

	else
		count += _putchar((n % 16) + '0');

	return (count);
}
int print_memory(va_list arg)
{
	unsigned long n;

	n = va_arg(arg, unsigned long);
	if (n == 0)
		return(print_nil());

	_putchar('0');
	_putchar('x');
	return(hex(n) + 2);
}

