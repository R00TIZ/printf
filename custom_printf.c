#include "main.h"

/**
 * _printf - custom printf function
 *
 * @format: first variadic argument
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	match specifier[] = {
		{"%c", print_c}, {"%s", print_s}, {"%%", print_pct}, {"%d", print_d},
		{"%i", print_i}, {"%b", print_b}, {"%u", print_u}, {"%o", print_o},
		{"%x", print_x}, {"%X", print_X}, {"%S", print_S}, {"%r", print_r},
		{"%R", print_R}, {"%p", print_p}
	};

	va_list args;
	int i = 0;
	int j;
	int len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (specifier[j].id[0] == format[i] && specifier[j].id[1] == format[i + 1])
			{
				len = len + specifier[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		len++;
	}
	va_end(args);
	return (len);
}
