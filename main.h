#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct opt - Struct option
 * @opt: format option/specifier
 * @op: list fuctions
 */
typedef struct opt
{
	char *opt;
	int (*op)();
} print_f;

int _putchar(char c);
int _printf(const char *format, ...);
int parser(const char *option, print_f f[], va_list arg);
int _strlen(char *s);
int strlen_const(const char *s);

/* Functions to print characters and Strings */
int print_rev(va_list arg);
int print_char(va_list arg);
int print_string(va_list arg);
int print_S(va_list arg);

/* Functions to print decimal numbers */
int print_unsigned(va_list arg);
int print_int(va_list arg);
int print_decimal(va_list arg);

/* Function to print octal numbers */
int print_oct(va_list arg);

/* Functions to print hexadecimal numbers*/
int print_hex(va_list arg);
int print_HEX(va_list arg);

/* Functions to print memory addresses */
int print_address(unsigned long int arg);
int print_pointer(va_list arg);
int print_ADDRESS(unsigned int arg);

/* Function to print % */
int print_percent(void);

/* Function to print binary numbers */
int print_binary(va_list arg);

/* Function to print a string in rot 13 */
int print_rot13(va_list arg);

/* Flags */

#endif
