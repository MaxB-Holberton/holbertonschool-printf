#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("Length (_printf): [%d, %i]\n", len2, len2);
	printf("Length (printf): [%d, %i]\n", len, len);

	_printf("String (_printf): [%s]\n", "I am a string !");
    	printf("String (printf): [%s]\n", "I am a string !");
	
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	return (0);
}
