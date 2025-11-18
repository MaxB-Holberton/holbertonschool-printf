#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * print_char - print a char
 * @arg: the char to print
 *
 * Return: 1 - since only a single char was printed
 */
int print_char(va_list arg)
{
	return(_putchar(va_arg(arg, int)));
}
/**
 * print_str - print a string
 * @arg: the string to print
 *
 * Return: number of characters printed
 */
int print_str(va_list arg)
{
	char *str;
	unsigned int i = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (0);

	for  (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
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
		_putchar('-');
		n *= -1;
		i++;
	}
	if (n / 10 != 0)
		i+= int_print_rec(n / 10);
	i += _putchar(n % 10 + '0');
	return (i);
}

