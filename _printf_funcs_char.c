#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
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

	return (writetobuffer(str));
}

int print_ascii(va_list arg)
{
	char *str;
	char *ascii;
	
	str = va_arg(arg, char *);
	ascii = malloc(sizeof(str) * sizeof(char));

	if (str == NULL || ascii == NULL)
        {
                _putchar('(');
                _putchar('n');
                _putchar('u');
                _putchar('l');
                _putchar('l');
                _putchar(')');
                return (6);
        }
	while (*str != '\0')
        {
		if (*str >= 32 && *str < 127)
		{
			*ascii = *str;
			continue;
		}
		*ascii = '\\';
                ascii++;
		*ascii = 'x';
		if (*str < 16)
		{
			ascii++;
			*ascii = '0';
		}
		str++;
		ascii++;
	}
	return (writetobuffer(ascii));
}
