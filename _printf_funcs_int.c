#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * write_int - prints int chars recursively
 * @n: the number
 *
 * Return: number of chars to print
 */
unsigned int write_int(unsigned int n, char *buffer, unsigned int i)
{
	unsigned int count = 0;
	if (n / 10 != 0)
	{
		count += write_int((n / 10), buffer, i);
		count++;
	}
	buffer[count + i] = (n % 10 + '0');
	return (count);
}
/**
 * print_int - prints an integer
 * @arg: the int to print
 *
 * Return: the number of chars in the int
 */
int print_int(va_list arg, char *buffer, unsigned int *iptr)
{
	unsigned int i;
	int n;
	unsigned int count = 0;

	n = va_arg(arg, int);

	i = checkbuffer(buffer, iptr, (sizeof(n) * sizeof(unsigned int)) + (sizeof(char) * 1));
	if (n < 0)
	{
		buffer[count + i] = '-';
		count++;
		count += write_int((unsigned int)n * -1, buffer, count + i);
		(*iptr) = count + i;
		return (count);
	}
	count += write_int(n, buffer, i);
	(*iptr) = count + i;
	return (count);
}
/**
 * print_unsigned - prints unsigned integer
 * @arg: the int to print
 *
 * Return: the number of chars in the int
 */
int print_unsigned(va_list arg, char *buffer, unsigned int *iptr)
{
	unsigned int i;
	unsigned int n;
	unsigned int count = 0;

	n = va_arg(arg, unsigned int);

	i = checkbuffer(buffer, iptr, (sizeof(n) * sizeof(unsigned int)) + (sizeof(char) * 1));
	count += write_int(n, buffer, i);
	(*iptr) = count + i;
	return (count);
}
