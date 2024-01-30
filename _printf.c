#include "main.h"
/**
 * _printf - Custom printf function with limited functionality
 * @format: Format string containing conversion specifiers
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count, i;
	va_list args;

	count = 0;
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					handle_char(args, &count);
					break;
				case 's':
					handle_string(args, &count);
					break;
				case '%':
					_putchar(format[i]);
					count++;
					break;
				default:
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count += 2;
					break;
			}
			i++;
		}
	}
	va_end(args);
	return (count);
}