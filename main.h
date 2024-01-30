#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int width, int precision, int size);

/* Functions to print chars and strings */
int print_char(va_list types, char buffer[], int width, int precision, int size);
int print_string(va_list types, char buffer[], int width, int precision, int size);
int print_percent(va_list types, char buffer[], int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[], int width, int precision, int size);

/* Util functions */
int is_printable(char c);
void print_buffer(char buffer[], int *buff_ind);

#endif /* MAIN_H */
