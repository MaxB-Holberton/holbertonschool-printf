#include "main.h"
#include <stdarg.h>
#include <stddef.h>

unsigned int memory_hex(unsigned long n, char *buffer, unsigned int i)
{
	unsigned int count = 0;

	if ((n / 16) != 0)
	{
		count += memory_hex((n / 16), buffer, i);
		count++;
	}
	if((n % 16) > 9)
		buffer[count + i] = (((n % 16) - 10) + 'a');
	else
		buffer[count + i] = (n % 16 + '0');
	return (count);
}
int print_memory(va_list arg, char *buffer, unsigned int *iptr)
{
	unsigned int i;
	unsigned long n;
	unsigned int count = 0;

	n = va_arg(arg, unsigned long);
	if (n == 0)
	{
	       buffer[0 + *iptr] = '(';
	       buffer[1 + *iptr] = 'n';
	       buffer[2 + *iptr] = 'i';
	       buffer[3 + *iptr] = 'l';
	       buffer[4 + *iptr] = ')';
	       *iptr += 4;
	       return (4);
	}
	i = checkbuffer(buffer, iptr, (sizeof(n) * sizeof(unsigned long)) + (sizeof(char) * 2));
	buffer[count + i] = '0';
	count++;
	buffer[count + i] = 'x';
	count++;
	count += memory_hex(n, buffer, count + i);
	*iptr = count + i;
	return(count);
}
