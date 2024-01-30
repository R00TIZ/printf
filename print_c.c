#include "main.h"
#include <stdarg.h>

/**
 * print_c - this prints type char using putchar
 *
 * @value: va_list type
 *
 * Return: 1
 */

int print_c(va_list value)
{
	char str;

	str = va_arg(value, int);

	_putchar(str);
	return (1);
}
