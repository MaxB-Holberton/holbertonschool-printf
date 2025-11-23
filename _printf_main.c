#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * _putchar - writes the character to stdout
 * @c: character to write
 *
 * Return: 1 - the number of chars written to stdout
 */
int _putchar(const char c)
{
	return (write(1, &c, 1));
}

/**
 * printbuffer - Print the buffer and buffer pointer iptr to zero
 * @bufer: the buffer to write to
 * @size: the number of characters to write
 * @iptr: the buffer pointer
 *
 * Return: the number of characters that have been written
 */
int writetostdout(char *buffer, unsigned int *iptr)
{
	unsigned int size = *iptr;
	*iptr = 0;
	return(write(1, buffer, size));
}

/**
 * flush_buffer - print the buffer and free the memory
 * @bufer: the buffer to write to
 * @size: the number of characters to write
 *
 * Return: the number of characters that have been written
 */
int write_buffer(char *buffer, unsigned int size)
{
	return(write(1, buffer, size));
}

/**
 * _printf - the copy of printf
 * @format: character formatting
 * @...: args to handle
 *
 * Return: # of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int rtn = 0;
	unsigned int struct_size;

	const char *ptr = format;

	print printer[] = {
		{"c", print_char},
		{"s", print_str},
		{"S", print_ascii},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex_l},
		{"X", print_hex_u},
		{"b", print_binary},
		{"p", print_memory}
	};

	struct_size = (sizeof(printer) / sizeof(printer[0]));
	va_start(args, format);

	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] == '%')
		{
			i++;
			if (ptr[i] == '\0')
				return (-1);

			if (ptr[i] == '%')
			{
				rtn += _putchar('%');
				continue;
			}
			j = 0;
			while (j < struct_size)
			{
				if (*(printer[j].conversion) == ptr[i])
				{
					rtn += printer[j].function(args);
					break;
				}
				j++;
			}
			if (j != struct_size)
				continue;
			rtn += _putchar('%');
		}
		rtn += _putchar(ptr[i]);
	}
	va_end(args);
	return (rtn);
}
