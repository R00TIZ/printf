#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    while (*format != '\0')
    {
        if (*format != '%')
        {
            write(1, format, 1);
            printed_chars++;
        }
        else
        {
            format++; /* Move past '%' */
            switch (*format)
            {
                case 'c':
                    printed_chars += print_char(va_arg(args, int));
                    break;
                case 's':
                    printed_chars += print_string(va_arg(args, char *));
                    break;
                case '%':
                    write(1, "%", 1);
                    printed_chars++;
                    break;
                default:
                    write(1, "%", 1);
                    write(1, format, 1);
                    printed_chars += 2;
                    break;
            }
        }
        format++;
    }

    va_end(args);

    return (printed_chars);
}

/**
 * print_char - Prints a character
 * @c: Character to print
 * Return: Number of characters printed
 */
int print_char(char c)
{
    write(1, &c, 1);
    return 1;
}

/**
 * print_string - Prints a string
 * @s: String to print
 * Return: Number of characters printed
 */
int print_string(char *s)
{
    if (s == NULL)
        s = "(null)";

    int len = 0;
    while (*s)
    {
        write(1, s, 1);
        s++;
        len++;
    }
    return len;
}
