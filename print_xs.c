#include "main.h"

/**
 * print_xs - prints hexadecimal(lower)
 *
 * @num: unsigned long int
 *
 * Return: int
 */

int print_xs(unsigned long int num)
{
	long int i;
	long int counter = 0;
	long int *hex;
	unsigned long int holder;

	holder = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		counter++;
	}
	counter++;
	hex = malloc(sizeof(long int) * counter);
	if (hex == NULL)
		return (0);
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
