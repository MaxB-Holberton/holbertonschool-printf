#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * write_int - prints int chars recursively
 * @n: the number
 *
 * Return: number of chars to print
 */
unsigned int write_int(unsigned int n)
{
	unsigned int count = 0;

	if ((n / 10) != 0)
		count = write_int((n / 10));

	count += _putchar((n % 10) + '0');
	return (count);
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

	n = va_arg(arg, int);
	if (n < 0)
	{
		_putchar('-');
		return (write_int((unsigned int)n * -1) + 1);
	}
	return (write_int(n));
}
/**
 * print_unsigned - prints unsigned integer
 * @arg: the int to print
 *
 * Return: the number of chars in the int
 */
int print_unsigned(va_list arg)
{
	return (write_int(va_arg(arg, int)));
}
