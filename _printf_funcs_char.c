#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>
/**
 * print_char - print a char
 * @arg: the char to print
 *
 * Return: 1 - since only a single char was printed
 */
int print_char(va_list arg, char *buffer, unsigned int *iptr)
{
	buffer[(*iptr)++] = va_arg(arg, int);
	return (1);
}
/**
 * print_null - print (null) to the buffer
 * @buffer: the buffer
 * @iptr: the current position in the buffer
 *
 * Return: 6 - as 6 chars were printed
 */
int print_null(char *buffer, unsigned int *iptr)
{
	buffer[(*iptr)++] = '(';
	buffer[(*iptr)++] = 'n';
	buffer[(*iptr)++] = 'u';
	buffer[(*iptr)++] = 'l';
	buffer[(*iptr)++] = 'l';
	buffer[(*iptr)++] = ')';
	return (6);
}
/**
 * print_str - print a string
 * @arg: the arg to print
 * @buffer: the buffer to write the char into
 * @iptr: the current position in the buffer
 *
 * Return: number of characters printed
 */
int print_str(va_list arg, char *buffer, unsigned int *iptr)
{
	char *str;
	unsigned int i = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (print_null(buffer, iptr));

	while (*str != '\0')
	{
		buffer[(*iptr)++] = *str;
		str++;
		i++;
	}
	return (i);
}
/**
 * print_str - print only ascii chars, other chars are \xFF (hex) vals
 * @arg: the arg to print
 * @buffer: the buffer to write the char into
 * @iptr: the current position in the buffer
 *
 * Return: number of characters printed
 */
int print_ascii(va_list arg, char *buffer, unsigned int *iptr)
{
	char *str;
	unsigned int i = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (print_null(buffer, iptr));

	while (*str != '\0')
	{
		if (*str >= 32 && *str < 127)
		{
			buffer[(*iptr)++] = (*str)++;
			i++;
			continue;
		}
		buffer[(*iptr)++]  = '\\';
		buffer[(*iptr)++]  = 'x';
		i += 2;
		if (*str < 16)
		{
			buffer[(*iptr)++] = '0';
			i++;
		}
		buffer[(*iptr)++] = (*str)++;
		i++;
	}
	return (i);
}
