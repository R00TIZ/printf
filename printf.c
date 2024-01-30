#include "main.h"
/**
 * _printf - printf function
 * @format: array of strings to print
 * @...: variable arguments
 * Return: -1 on error
 */
int _printf(const char *format, ...)
{
	int num_char, str_len = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num_char++;
		} else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
				write(1, format, 1);
				num_char++;
			} else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				numchar++;
			} else if (*format == 's')
			{
				char *str = va_arg(args, char*);

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				num_char += str_len;
			}
		}
		format++;
	}
	va_end(args);
	return (num_char);
}
