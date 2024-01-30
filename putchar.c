#include <unistd.h>

/**
 * _putchar - used to write char c to stdout
 *
 * @c: char
 *
 * Return: 1 or -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
