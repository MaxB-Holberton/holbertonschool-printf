#include "main.h"
#include <stdarg.h>

unsigned int octal_rec(unsigned int n)
{
        unsigned int i = 0;

        if ((n / 8) != 0)
                i += octal_rec(n / 8);
        i += _putchar(n % 8 + '0');
        return (i);
}

unsigned int hex_l_rec(unsigned int n)
{
        unsigned int i = 0;

        if ((n / 16) != 0)
                i += hex_l_rec(n / 16);
	if ((n % 16) > 9)
		i += _putchar (((n % 16) - 10) + 'a');
	else
        	i += _putchar(n % 16 + '0');
        return (i);
}

int print_hex_l(va_list arg)
{
        unsigned int n;
        unsigned int i = 0;

        n = va_arg(arg, unsigned int);
        return (i += hex_l_rec(n));
}

unsigned int hex_u_rec(unsigned int n)
{
	unsigned int i = 0;

        if ((n / 16) != 0)
		i += hex_u_rec(n / 16);
	if ((n % 16) > 9)
		i += _putchar (((n % 16) - 10) + 'A');
	else
		i += _putchar(n % 16 + '0');
        return (i);
}
int print_hex_u(va_list arg)
{
	unsigned int n;
	unsigned int i = 0;

	n = va_arg(arg, unsigned int);
	return (i += hex_u_rec(n));

}
int print_octal(va_list arg)
{
        unsigned int n;
        unsigned int i = 0;

        n = va_arg(arg, unsigned int);
        return (i += octal_rec(n));
}

