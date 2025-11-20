#include "main.h"
#include <stdarg.h>
#include <stddef.h>
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
	unsigned int i = 0;
	unsigned int rtn = 0;
	char *buffer;

	buffer = createbuffer();
	str = va_arg(arg, char *);
	
	if (str == NULL || buffer == NULL)
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
		if (i == 1024)
		{
			rtn += printbuffer(buffer, i);
			buffer = createbuffer();
			i = 0;
		}
		buffer[i] = *str;
		str++;
		i++;
	}
	rtn += printbuffer(buffer, i);
	return (rtn); 
}

int print_ascii(va_list arg)
{
	char *str;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int rtn = 0;

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
	while (*str != '\0')
        {
                if (i == 1024)
                {
                        rtn += printbuffer(buffer, i);
                        buffer = createbuffer();
			if (buffer == NULL)
				return (NULL);
                        i = 0;
                }
		if (*str >= 32 && *str < 127)
		{
                	buffer[i] = *str;
			str++;
			i++;
			continue;
		}
		if ((i + 3) == 1024)
		{

		}
		buffer[i] = '\\';
                i++;
		buffer[i] = 'x';
		i++
		if (*str < 16)
		{
			buffer[i] = '0';
			i++;
		}
        }
        rtn += printbuffer(buffer, i);


        /*for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] >= 32 && str[j] < 127)
		{
			i += _putchar(str[j]);
			continue;
		}
		i += _putchar('\\');
		i += _putchar('x');
		if (str[j] < 16)
			i += _putchar('0');
		i += hex_u_rec(str[j]);
	}*/
        return (rtn);
}
