#include "main.h"
/**
 * print_unsigned - prints unsigned integers
 * @arg: argument
 * Return: number of characters printed
 */
int print_unsigned(va_list arg)
{
	int i, div = 1, len = 0;
	unsigned int num;

	i = va_arg(arg, int);
	if (i < 0)
	{
		num = i * -1;
	}
	num = i;
	for (; num / div > 9;)
		div *= 10;
	for (; div != 0;)
	{
		len += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (len);
}
