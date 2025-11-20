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
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

int print_ascii(va_list arg)
{
	char *str;
	unsigned int i = 0;
	unsigned int j = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
        {
                _putchar('(');
                _putchar('n');
                _putchar('u');
                _putchar('l');
                _putchar('l');
                _putchar(')');
                return (6);
        }
        for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] >= 32 && str[j] < 127)
		{
			i += _putchar(str[j]);
			continue;
		}
		i += _putchar('\\');
		i += _putchar('x');
		if (str[j] < 16)
			i += _putchar('0');
		i += hex_u_rec(str[j]);
	}
        return (i);
}
