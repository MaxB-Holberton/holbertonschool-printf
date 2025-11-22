#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
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
int writetobuffer(char *str)
{
	char *buffer;
	int rtn = 0;
	int i = 0;

	buffer = createbuffer();
	if (buffer == NULL)
		return (-1);
	while (*str != '\0')
	{
		if (i == 1024)
		{
			rtn += printbuffer(buffer, i);
			buffer = createbuffer();
			if (buffer == NULL)
				return (-1);
			i = 0;
		}
		buffer[i] = *str;
		str++;
		i++;
	}
	rtn += printbuffer(buffer, i);
	return (rtn);
}
void freebuffer(char *createdbuffer)
{
	free(createdbuffer);
}
int printbuffer(char *buffer, unsigned int size)
{
	unsigned int i = 0;

	i = write(1, buffer, size);
	free(buffer);
	return (i);
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
	unsigned int s_size;
	const char *ptr = format;

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
		{"p", print_memory}
	};
	
	s_size = (sizeof(printer) / sizeof(printer[0]));
	va_start(args, format);

	while (*ptr != '\0')
	{
		if (*ptr != '%')
			i += _putchar(*ptr);
		else
		{
			ptr++;
			if (*ptr == '\0')
				return (-1);
			if (*ptr == '%')
				i += _putchar('%');
			else
			{
				j = 0;
				while (j < s_size)
				{
					if (*(printer[j].conversion) == *ptr)
					{
						i += printer[j].function(args);
						break;
					}
					j++;
				}
				if (j == s_size)
				{
					i += _putchar('%');
					i += _putchar(*ptr);
				}
			}
		}
		ptr++;
	}
	va_end(args);
	return (i);
}
