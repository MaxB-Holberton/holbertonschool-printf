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
	return (_putchar(va_arg(arg, int)));
}
/**
 * print_null - print (null) to the buffer
 * @buffer: the buffer
 * @iptr: the current position in the buffer
 *
 * Return: 6 - as 6 chars were printed
 */
int print_null(void)
{
	unsigned int i = 0;

	i += _putchar('(');
	i += _putchar('n');
	i += _putchar('u');
	i += _putchar('l');
	i += _putchar('l');
	i += _putchar(')');
	return (i);
}
/**
 * print_str - print a string
 * @arg: the arg to print
 * @buffer: the buffer to write the char into
 * @iptr: the current position in the buffer
 *
 * Return: number of characters printed
 */
int print_str(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (print_null());
/*
 * *buffer;
 * unsigned int i = 0;
	buffer = malloc(sizeof(str) * sizeof(char));
	if (buffer == NULL)
		return (print_null());

	for (i = 0; str[i] != '\0'; i++)
		buffer[i] = str[i];
	write_buffer(str, sizeof(str));
	free(buffer);*/

	return (write_buffer(str, sizeof(str)));
}
/**
 * print_str - print only ascii chars, other chars are \xFF (hex) vals
 * @arg: the arg to print
 * @buffer: the buffer to write the char into
 * @iptr: the current position in the buffer
 *
 * Return: number of characters printed
 */
int print_ascii(va_list arg)
{
	char *str, *buffer;
	unsigned int i = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (print_null());

	/*
	 * as the hex is 4 chars long, making it n *5
	 * ensures that the full size of the string can be safely covered
	 */
	buffer = malloc(sizeof(str) * 5);
	if (buffer == NULL)
		return (print_null());

	for (i = 0; str[i] != '\0'; i++)
	{
		if (*str >= 32 && *str < 127)
		{
			buffer[i] = str[i];
			continue;
		}
		buffer[i++]  = '\\';
		buffer[i++]  = 'x';
		if (*str < 16)
			buffer[i++]  = '0';
	}
	write_buffer(buffer, i);
	free(buffer);
	return (i);
}
