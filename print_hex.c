#include "main.h"
/**
 * print_hex - prints a hexadecimal number (%x)
 * @arg: argument
 * Return: number of characters
 */
int print_hex(va_list arg)
{
	int i, *arr, count = 0;
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] += 39;
		_putchar(arr[i] + 48);
	}
	free(arr);
	return (count);
}

/**
 * print_HEX - prints a hexadecimal number (%X)
 * @arg: argument
 * Return: number of characters
 */
int print_HEX(va_list arg)
{
	int i, *arr, count = 0;
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] += 7;
		_putchar(arr[i] + 48);
	}
	free(arr);
	return (count);
}
