#include "main.h"
/**
 * print_ADDRESS - prints an hexadecimal number
 * @arg: argument
 * Return: number of characters
 */
int print_ADDRESS(unsigned int arg)
{
	int i, *arr, count = 0;
	unsigned int temp = arg;

	while (arg / 16 != 0)
	{
		arg /= 16;
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

/**
 * print_S - handles custom conversion specifier
 * @arg: argument
 * Return: retruns number characters
 */
int print_S(va_list arg)
{
	char *s = va_arg(arg, char *);
	unsigned int i = 0, num, a = 0;

	if (s == NULL)
		s = "(NULL)";
	while (s[i])
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar(120);
			a += 2;
			num = s[i];
			if (num < 16)
			{
				_putchar(48);
				a++;
			}
			a += print_ADDRESS(num);
		} else
		{
			_putchar(s[i]);
			a++;
		}
		i++;
	} return (a);
}
