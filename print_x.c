#include "main.h"

/**
 * print_x - prints hexadecimal
 *
 * @value: va_list rgument
 *
 * Return: int
 */

int print_x(va_list value)
{
	unsigned int num;
	int i;
	int counter = 0;
	int *hex;
	int holder;

	num = va_arg(value, unsigned int);
	holder = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		counter++;
	}
	counter++;
	hex = malloc(sizeof(int) * counter);
	for (i = 0; i < counter; i++)
	{
		hex[i] = holder % 16;
		holder = holder / 16;
	}

	for (i = counter - 1; i >= 0; i--)
	{
		if (hex[i] < 10)
		{
			_putchar(hex[i] + '0');
		}
		else
		{
			_putchar(hex[i] - 10 + 'a');
		}
	}
	free(hex);
	return (counter);
}
