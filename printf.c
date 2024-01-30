#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char buffer[1024];  // Adjust the buffer size as needed

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            buffer[count++] = *format;
            if (count == sizeof(buffer) - 1)  // Check if buffer is full
            {
                write(1, buffer, count);
                count = 0;
            }
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += _print_char(va_arg(args, int), buffer, count);
                    break;
                case 's':
                    count += _print_str(va_arg(args, char *), buffer, count);
                    break;
                case '%':
                    buffer[count++] = '%';
                    if (count == sizeof(buffer) - 1)
                    {
                        write(1, buffer, count);
                        count = 0;
                    }
                    break;
                default:
                    buffer[count++] = '%';
                    buffer[count++] = *format;
                    if (count == sizeof(buffer) - 1)
                    {
                        write(1, buffer, count);
                        count = 0;
                    }
            }
        }
        format++;
    }

    write(1, buffer, count);  // Write any remaining characters in the buffer

    va_end(args);

    return count;
}

int _print_char(int c, char buffer[], int count)
{
    buffer[count++] = c;
    if (count == sizeof(buffer) - 1)
    {
        write(1, buffer, count);
        count = 0;
    }
    return 1;
}

int _print_str(char *str, char buffer[], int count)
{
    if (!str)
        str = "(null)";

    while (*str)
    {
        buffer[count++] = *str;
        if (count == sizeof(buffer) - 1)
        {
            write(1, buffer, count);
            count = 0;
        }
        str++;
    }

    return count;
}
