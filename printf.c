#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>  /* forgot it :p */

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    count += _print_str(va_arg(args, char *));
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    write(1, "%", 1);
                    write(1, format, 1);
                    count += 2;
            }
        }
        format++;
    }

    va_end(args);

    return count;
}

/**
 * _print_str - Print a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int _print_str(char *str)
{
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str != '\0')
    {
        write(1, str, 1);
        str++;
        count++;
    }

    return count;
}
