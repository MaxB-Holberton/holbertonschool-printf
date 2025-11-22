#include "main.h"
#include <stdarg.h>
#include <stdio.h>

unsigned int octal_rec(unsigned int n, char *conv)
{
        unsigned int i = 0;

        if ((n / 8) != 0)
                i += octal_rec((n / 8), conv);
        conv[i] = (n % 8 + '0');
	i++;
        return (i);
}

unsigned int hex_l_rec(unsigned int n, char *conv)
{
        unsigned int i = 0;

        if ((n / 16) != 0)
                i += hex_l_rec((n / 16), conv);
	if ((n % 16) > 9)
		conv[i] =(((n % 16) - 10) + 'a');
	else
        	conv[i] = (n % 16 + '0');
        i++;
	return (i);
}

unsigned int hex_u_rec(unsigned int n, char *conv)
{
	unsigned int i = 0;

        if ((n / 16) != 0)
		i += hex_u_rec((n / 16), conv);
	if ((n % 16) > 9)
		conv[i] = (((n % 16) - 10) + 'A');
	else
		conv[i] = (n % 16 + '0');
	i++;
        return (i);
}
unsigned int binary_rec(unsigned int n, char *conv)
{
	unsigned int i = 0;

	if ((n / 2) != 0)
		i+= binary_rec((n / 2), conv);
	conv[i] = (n % 2 + '0');
	i++;
	return (i);
}
int print_hex_l(va_list arg)
{
	char *conv;
	int i = 0;
	conv = createbuffer();

	i += hex_l_rec(va_arg(arg, unsigned int), conv);
	return (printbuffer(conv, i));
}
int print_hex_u(va_list arg)
{
	char *conv;
	int i = 0;
	conv = createbuffer();

	i += hex_u_rec(va_arg(arg, unsigned int), conv);
	return (printbuffer(conv, i));
}
int print_octal(va_list arg)
{
	char *conv;
	int i = 0;
	conv = createbuffer();

        i += octal_rec(va_arg(arg, unsigned int), conv);
        return (printbuffer(conv, i));
}
int print_binary(va_list arg)
{
	char *conv;
	int i = 0;
	conv = createbuffer();

	i += binary_rec(va_arg(arg, unsigned int), conv);
	return(printbuffer(conv, i));
}
