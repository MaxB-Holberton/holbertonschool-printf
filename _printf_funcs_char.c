#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * print_char - print a char
 * @arg: the char to print
 *
 * Return: 1 - since only a single char was printed
 */
int print_char(va_list arg, char *buffer, unsigned int *iptr)
{
	buffer[*iptr] = va_arg(arg, int);
	return(1);
}
/**
 * print_str - print a string
 * @arg: the string to print
 *
 * Return: number of characters printed
 */
int print_str(va_list arg, char *buffer, unsigned int *iptr)
{
	char *str;
	unsigned int i;
	unsigned int count = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		buffer[0 + *iptr] = '(';
		buffer[1 + *iptr] = 'n';
		buffer[2 + *iptr] = 'u';
		buffer[3 + *iptr] = 'l';
		buffer[4 + *iptr] = 'l';
		buffer[5 + *iptr] = ')';
		*iptr = 5 + *iptr;
		return (6);
	}
	i = checkbuffer(buffer, iptr, sizeof(str) * sizeof(char));
	while (*str != '\0')
	{
		buffer[count + i] = *str;
		str++;
		count++;
	}
	*iptr = (count - 1) + i;
	return (count);
}

int print_ascii(va_list arg, char *buffer, unsigned int *iptr)
{
	char *str;
	unsigned int i;
	unsigned int count = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		buffer[0 + *iptr] = '(';
		buffer[1 + *iptr] = 'n';
		buffer[2 + *iptr] = 'u';
		buffer[3 + *iptr] = 'l';
		buffer[4 + *iptr] = 'l';
		buffer[5 + *iptr] = ')';
		*iptr = 5 + *iptr;
		return (6);
	}
	i = checkbuffer(buffer, iptr, sizeof(str) * sizeof(char));

	while (*str != '\0')
	{
		if (*str >= 32 && *str < 127)
		{
			buffer[count + i] = *str;
			str++;
			count++;
			continue;
		}
		buffer[count + i]  = '\\';
		count++;
		buffer[count + i]  = 'x';
		if (*str < 16)
		{
			count++;
			buffer[count + i]  = '0';
		}
		str++;
		count++;
	}
	*iptr = (count - 1) + i;
	return (count);
}
