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
	_putchar(va_arg(arg, int));
	return (1);
}
/**
 * print_str - print a string 
 * @arg: the argument to print 
 *
 * Return: number of characters printed
 */
int print_str(va_list arg)
{
	char *str;
	unsigned int i;	

	str = va_arg(arg, char *);
	if (str == NULL)
		return (0);
	
	for  (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
