#include "main.h"
#include <stdarg.h>
/**
 * int_print_rec - prints int chars recursively
 * @n: the number
 *
 * Return: 1 - one char per recursion
 */
int int_print_rec(int n)
{
	int i = 0;

	if (n / 10 != 0)
		i += int_print_rec(n / 10);
	i += _putchar(n % 10 + '0');
	return (i);
}
/**
 * unsigned_print_rec - prints unsigned recursively
 * @n: the number to print
 *
 * Return: the number of chars printed
 */
unsigned int unsigned_print_rec(unsigned int n)
{
	unsigned int i = 0;

	if ((n / 10) != 0)
		i += unsigned_print_rec(n / 10);
	i += _putchar(n % 10 + '0');
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
	int n;
	unsigned int i = 0;

	n = va_arg(arg, int);
	if (n < 0)
	{
		i+= _putchar('-');
		n *= -1;
	}
	return (i+= int_print_rec(n));
}
/**
 * print_unsigned - prints unsigned integer
 * @arg: the int to print
 *
 * Return: the number of chars in the int
 */
int print_unsigned(va_list arg)
{
	unsigned int n;
	unsigned int i = 0;

	n = va_arg(arg, unsigned int);
	return (i += unsigned_print_rec(n));
}
