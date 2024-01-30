#include "main.h"
/**
 * print_int - prints an integer
 * @arg: arguments
 * Return: number of characters printed
 */
int print_int(va_list arg)
{
	int i, div = 1, len = 0;
	int num;

	i = va_arg(arg, int);
	if (i < 0)
	{
		len += _putchar(45);
		num = i * -1;
	}
	if (i == 0)
	{
		len += _putchar(48);
		return (1);
	}
	if (i > 0)
		num = i;
	for (; num / div > 9;)
		div *= 10;
	for (; div != 0;)
	{
		len += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	} return (len);
}
