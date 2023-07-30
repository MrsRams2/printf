#ifndef MAIN_H
#define MAIN_H

/** header files **/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

typedef void (*print_handler)(va_list args);

/** functions */
int _putchar(char c);
int _puts(char *s);
int _printf(const char *format, ...);
void print_percent(va_list args);
void print_char(va_list args);
int v_printf(const char *format, va_list args);

/** updated functions */
int format_parser(const char *format, va_list args);
int format_handler(char format_specifier, va_list args);
int print_string(char *str);
int print_number(int num);
int print_unsigned(unsigned int num);
int print_octal(unsigned int num);
int print_hexadecimal(unsigned int num, char format);
int print_pointer(void *ptr);


#endif
