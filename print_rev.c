#include "main.h"
/**
 * print_rev - prints a String in reverse
 * @arg: argument
 * Return: returns number of characters
 */
int print_rev(va_list arg)
{
	char *str = va_arg(arg, char*);
	int i = 0, j;

	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
		i++;
	for (j = i - 1; j >= 0; j--)
		_putchar(str[j]);
	return (i);
}
