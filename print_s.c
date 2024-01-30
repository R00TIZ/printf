#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * print_s - prints strings using putchar
 *
 * @value: va_list type
 *
 * Return: char count in string
 */

int print_s(va_list value)
{
	int i;
	int n;
	char *str;

	str = va_arg(value, char *);
	if (str == NULL)
	{
		str = "(null)";
		n = strlen(str);
		for (i = 0; i < n; i++)
		{
			_putchar(str[i]);
		}
		return (n);
	}
	else
	{
		n = strlen(str);
		for (i = 0; i < n; i++)
		{
			_putchar(str[i]);
		}
		return (n);
	}
}
