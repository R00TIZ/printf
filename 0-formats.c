#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: input String
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int a = 0;
	va_list arg;

	print_f f[] = {
		{"u", print_unsigned},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_pointer},
		{"r", print_rev},
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_decimal},
		{"i", print_int},
		{"b", print_binary},
		{"S", print_S},
		{"R", print_rot13},
		{NULL, NULL}
	};

	if (!format)
		return (-1);
	va_start(arg, format);
	a = parser(format, f, arg);
	va_end(arg);
	return (a);
}
