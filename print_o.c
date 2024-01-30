#include "main.h"

/**
 * print_o - print octal value
 *
 * @value: va_List argument
 *
 * Return: int
 */

int print_o(va_list value)
{
	unsigned int num;
	int i;
	int counter = 0;
	int *octal;
	int holder;

	num = va_arg(value, unsigned int);
	holder = num;

	while (num / 8 != 0)
	{
		num = num / 8;
		counter++;
	}
	counter++;
	octal = malloc(sizeof(int) * counter);
	if (octal == NULL)
		return (0);
	for (i = 0; i < counter; i++)
	{
		octal[i] = holder % 8;
		holder = holder / 8;
	}
	for (i = counter - 1; i >= 0 ; i--)
	{
		_putchar(octal[i] + '0');
	}
	free(octal);
	return (counter);
}
