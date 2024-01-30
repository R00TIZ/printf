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
    int buff_ind = 0;
    char buffer[BUFF_SIZE];

    while (*format != '\0')
    {
        if (*format != '%')
        {
            buffer[buff_ind++] = *format;
            if (buff_ind == BUFF_SIZE - 1)
            {
                print_buffer(buffer, &buff_ind);
                printed_chars += buff_ind;
            }
            else
            {
                printed_chars++;
            }
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                    buffer[buff_ind++] = va_arg(args, int);
                    break;
                case 's':
                    printed_chars += print_string(args, buffer, &buff_ind);
                    break;
                case '%':
                    buffer[buff_ind++] = '%';
                    break;
                default:
                    buffer[buff_ind++] = '%';
                    buffer[buff_ind++] = *format;
            }
        }
        format++;
    }

    print_buffer(buffer, &buff_ind);
    va_end(args);

    return (printed_chars);
}

/**
 * print_string - Prints a string
 * @args: va_list for variable arguments
 * @buffer: Character buffer
 * @buff_ind: Index at which to add the next char
 * Return: Number of characters printed
 */
int print_string(va_list args, char buffer[], int *buff_ind)
{
    char *s = va_arg(args, char *);
    if (s == NULL)
        s = "(null)";

    int len = 0;
    while (*s)
    {
        buffer[*buff_ind] = *s;
        (*buff_ind)++;
        if (*buff_ind == BUFF_SIZE - 1)
        {
            print_buffer(buffer, buff_ind);
            len += *buff_ind;
        }
        else
        {
            len++;
        }
        s++;
    }
    return len;
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Character buffer
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}
