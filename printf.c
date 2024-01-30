#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
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
                    count += _print_char(va_arg(args, int));
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
 * _print_char - Print a character
 * @c: Character to print
 *
 * Return: Number of characters printed
 */
int _print_char(int c)
{
    write(1, &c, 1);
    return 1;
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

    if (!str)
        str = "(null)";

    while (*str)
    {
        write(1, str, 1);
        str++;
        count++;
    }

    return count;
}
