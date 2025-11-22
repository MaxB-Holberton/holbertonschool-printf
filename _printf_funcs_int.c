#include "main.h"
#include <stdarg.h>
#include <limits.h>
/**
 * int_print_rec - prints int chars recursively
 * @n: the number
 *
 * Return: 1 - one char per recursion
 */
unsigned int int_print_rec(unsigned int n, char *conv)
{
	int i = 0;
	
	if (n / 10 != 0)
	{
		i += int_print_rec((n / 10), conv);
	}
	conv[i] = (n % 10 + '0');
	i++;
	return (i);
}
/**
 * print_int - prints an integer
 * @arg: the int to print
 *
 * Return: the number of chars in the int
 */
int print_int(va_list arg)
{
	char *conv;
	unsigned int i = 0;
	int n;
	conv = createbuffer();

	n = va_arg(arg, int);
	if (n < 0)
	{
		_putchar('-');
		i += int_print_rec((unsigned int)n * -1, conv);
		return (printbuffer(conv, i) + 1);
	}
	i += int_print_rec(n, conv);
	return (printbuffer(conv, i));
}
/**
 * print_unsigned - prints unsigned integer
 * @arg: the int to print
 *
 * Return: the number of chars in the int
 */
int print_unsigned(va_list arg)
{
	char *conv;
	int i = 0;
	
	conv = createbuffer();
	i += int_print_rec(va_arg(arg, unsigned int), conv);
	return(printbuffer(conv, i));

}
