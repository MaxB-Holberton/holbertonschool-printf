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
 * Args_check - check # of args to 
 *
 */

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
	const char *ptr = format;

	print printer[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int}
	};

	va_start(args, format);

	while (*ptr != '\0')
	{
		if (*ptr != '%')
			i+= _putchar(*ptr);
		else
		{
			ptr++;
			j = 0;
			while (j < (sizeof(printer) / sizeof(printer[0])))
			{
				if (*(printer[j].conversion) == *ptr)
					i += printer[j].function(args);
				j++;
			}
		}
		ptr++;
	}
	va_end(args);
	return (i);
}
