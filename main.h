#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<limits.h>

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct format - structure to be used in custom printf
 * @id: fomat specifier
 * @f: function to call
 */

typedef struct format
{
	char *id;
	int (*f)();
} match;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list value);
int print_s(va_list value);
int print_pct(void);
int print_i(va_list value);
int print_d(va_list value);
int print_b(va_list value);
int print_u(va_list value);
int print_o(va_list value);
int print_x(va_list value);
int print_X(va_list value);
int print_XS(unsigned int num);
int print_S(va_list value);
int print_xs(unsigned long int num);
int print_p(va_list value);
int print_r(va_list value);
int print_R(va_list value);
int print_flags(const char *format, int *i);
int print_width(const char *format, int *i, va_list value);
int print_prec(const char *format, int *i, va_list value);
int print_size(const char *format, int *i);

#endif
