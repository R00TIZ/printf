#include "main.h"
/**
 * print_binary - prints binary numbers
 * @arg: argument
 * Return: returns number of characters
 */
int print_binary(va_list arg)
{
	int in = 0, count = 0, i, start = 1, neg;
	unsigned int bnr = va_arg(arg, unsigned int);
	unsigned int temp;

	for (i = 0; i < 32; i++)
	{
		temp = ((start << (31 - i)) & bnr);
		if (temp >> (31 - i))
			in = 1;
		if (in)
		{
			neg = temp >> (31 - i);
			_putchar(neg + 48);
			count++;
		}
	}
	if (count == 0)
	{
		count++;
		_putchar(48);
	} return (count);
}
