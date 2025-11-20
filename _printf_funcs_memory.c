#include "main.h"
#include <stdarg.h>

int print_memory(va_list arg)
{
	unsigned int i = 0;
	unsigned int n;

	n = va_arg(arg, unsigned int);
	
	i += _putchar('0');
	i += _putchar('x');
	i += hex_l_rec(n);
	
	return (i);
}


