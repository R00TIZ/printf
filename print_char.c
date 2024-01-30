#include "main.h"
/**
 * print_char - prints a character to stdout
 * @arg: argument
 * Return: returns 1 on success
 */
int print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	_putchar(c);
	return (1);
}
