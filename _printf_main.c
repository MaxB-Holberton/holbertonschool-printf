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
	const char *ptr = format;
	char *buffer;

	buffer = malloc(2048 * sizeof(char));
	if (buffer == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] != '%')
		{
			buffer[j++] = ptr[i];
			rtn++;
			continue;
		}
		switch (ptr[++i]) {
			case 'c':
				rtn += print_char(args, buffer, &j);
				break;
			case 's':
				rtn += print_str(args, buffer, &j);
				break;
			case 'S':
				rtn += print_ascii(args, buffer, &j);
				break;
			case 'd':
				rtn += print_int(args, buffer, &j);
				break;
			case 'i':
				rtn += print_int(args, buffer, &j);
				break;
			case 'u':
				rtn += print_unsigned(args, buffer, &j);
				break;
			case 'o':
				rtn += print_octal(args, buffer, &j);
				break;
			case 'x':
				rtn += print_hex_l(args, buffer, &j);
				break;
			case 'X':
				rtn += print_hex_u(args, buffer, &j);
				break;
			case 'b':
				rtn += print_binary(args, buffer, &j);
				break;
			case 'p':
				rtn += print_memory(args, buffer, &j);
				break;
			case '%':
				buffer[j++] = '%';
				rtn++;
				break;
			case '\0':
				return (-1);
			default:
				buffer[j++] = '%';
				buffer[j++] = ptr[i];
				rtn += 2;
		}
	}
	va_end(args);
	write_buffer(buffer, j);
	free(buffer);
	return (j);
}
