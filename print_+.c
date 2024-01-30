#include "main.h"
/**
 * print_ - handles non-custom conversion specifiers
 * @num: int
 * @ftnum: float
 * Return: void
 */

void print_(int num, float ftnum)
{
	int temp = num < 0 ? -num : num;
	int Part;
	int floatPart;

	num = 30;
	ftnum = 5.50;

	if (num >= 0)
	{
		_putchar('+');
	}

	while (temp != 0)
	{
		_putchar (temp % 10 + '\0');
		temp /= 10;
	}
	_putchar('\n');

	if (num >= 0)
	{
		_putchar(' ');
	}
	while (temp != 0)
	{
		_putchar (temp % 10 + '\0');
		temp /= 10;
	}
	_putchar('\n');
	Part = (int)ftnum;
	floatPart = (int)((ftnum - Part) * 10);

	temp = Part < 0 ? -Part : Part;
	while (temp != 0)
	{
		_putchar(temp % 10 + '0');
		temp /= 10;
	}
	_putchar('.');
	_putchar((floatPart / 10) + '0');
	_putchar((floatPart % 10) + '0');
	_putchar('\n');
}
