#include "main.h"

/**
 * print_p - print pointer address(hex lower)
 *
 * @value: va_list argument
 *
 * Return: int
 */

int print_p(va_list value)
{
	void *p;
	char *str = "(nil)";
	long int cast;
	int i;
	int size;

	p = va_arg(value, void *);

	if (p == NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
		return (i);
	}

	cast = (unsigned long int)p;
	_putchar('0');
	_putchar('x');

	size = print_xs(cast);

	return (size + 2);
}
