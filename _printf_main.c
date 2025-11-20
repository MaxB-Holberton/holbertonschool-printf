#include "main.h"
#include <unistd.h>
#include <stdarg.h>

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
		{"X", print_hex_u}
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
