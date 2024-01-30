#include "main.h"
/**
 * print_address - prints memory address in hexadecimal form
 * i.e. 'a' to 'f'
 * @arg: argument
 * Return: number of characters
 */
int print_address(unsigned long int arg)
{
	int i, *hex, count = 0;
	unsigned long int temp = arg;

	while (arg / 16 != 0)
	{
		arg /= 16;
		count++;
	}
	count++;
	hex = malloc(count * sizeof(long int) + 1);
	if (hex == NULL)
		return (-1);

	for (i = 0; i < count; i++)
	{
		hex[i] = temp % 16;
		temp /= 16;
	}

	for (i = count - 1; i >= 0; i--)
	{
		if (hex[i] > 9)
			hex[i] += 39;
		_putchar(hex[i] + 48);
	}
	if (hex != NULL)
		free(hex);
	return (count);
}

/**
 * print_pointer - prints String in hexadecimal format
 * @arg: argument
 * Return: number of characters
 */
int print_pointer(va_list arg)
{
	void *ptr;
	char *str = "(nil)";
	long int count;
	int i, byte;

	ptr = va_arg(arg, void*);
	while (ptr == NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
			_putchar(str[i]);
		return (i);
	}
	count = (unsigned long int)ptr;
	_putchar(48);
	_putchar('x');
	byte = print_address(count);
	return (byte + 2);
}
