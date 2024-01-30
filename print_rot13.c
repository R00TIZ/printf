#include "main.h"
/**
 * print_rot13 - encodes a string in rot13
 * @arg: string to be encoded
 * Return: returns encoded String
 */
int print_rot13(va_list arg)
{
	int i = 0, j, count = 0, in = 0;
	char *str = va_arg(arg, char*);
	char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		in = 0;
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j])
			{
				_putchar(rot13[j]);
				count++;
				in = 1;
				break;
			}
		}
		if (!in)
		{
			_putchar(str[i]);
			count++;
		}
		i++;
	} return (count);
}
