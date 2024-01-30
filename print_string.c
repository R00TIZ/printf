#include "main.h"
/**
 * _strlen - returns the length of a String
 * @s: String to be checked
 * Return: length of the String
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * strlen_const - strlen for constant char pointer s
 * @s: String to be checked
 * Return: length of the String
 */
int strlen_const(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * print_string - writes a String to stdout
 * @arg: argument
 * Return: returns 1 on success
 */
int print_string(va_list arg)
{
	char *s;
	int i = 0, length;

	s = va_arg(arg, char *);
	if (s == NULL)
	{
		s = "(null)";
		length = _strlen(s);
		while (i < length)
		{
			_putchar(s[i]);
			i++;
		} return (length);
	}
	length = _strlen(s);
	for (; i < length; i++)
		_putchar(s[i]);
	return (length);
}
