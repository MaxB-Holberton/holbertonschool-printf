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
char *createbuffer(void)
{
	int buffersize = 1024;
	int i;
	char *buffer;

	buffer = malloc(buffersize * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	for (i = 0; i < buffersize; i++)
	{
		buffer[i] = '0';
	}
	return (buffer);
}

unsigned int checkbuffer(char *buffer, unsigned int *iptr, unsigned int write_size)
{
	unsigned int i = *iptr;
	if ((i + write_size) > 1024)
	{
		printbuffer(buffer, i);
		return(0);
	}
	return (i);
}

int printbuffer(char *buffer, unsigned int size)
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
	char *buffer;

	print printer[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex_l},
		{"X", print_hex_u},
		{"b", print_binary},
		{"S", print_ascii},
		{"p", print_memory},
	};

	struct_size = (sizeof(printer) / sizeof(printer[0]));
	va_start(args, format);

	buffer = createbuffer();
	if (buffer == NULL)
		return (-1);

	while (*ptr != '\0')
	{
		if (*ptr != '%')
		{
			buffer[i] = *ptr;
			ptr++;
			i++;
			rtn++;
			continue;
		}
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
			return (-1);

			if (*ptr == '%')
			{
				buffer[i] = *ptr;
				i++;
				ptr++;
				rtn++;
				continue;
			}
			j = 0;
			while (j < struct_size)
			{
				if (*(printer[j].conversion) == *ptr)
				{
					rtn += printer[j].function(args, buffer, &i);
					break;
				}
				j++;
			}
			if (j == struct_size)
			{
				buffer[i] = '%';
				i++;
				rtn++;
				buffer[i] = *ptr;
			}
			ptr++;
			i++;
			rtn++;
		}
	}
	va_end(args);
	printbuffer(buffer, i);
	free(buffer);
	return (rtn);
}
