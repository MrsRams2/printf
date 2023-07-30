#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * my_printf - function that produces output
 * @format: The format string
 * Return: On success, returns the number of characters printed
 */

int my_printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int printed_chars = 0;

while (*format != '\0')
{
if (*format == '%')
{
format++;

if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
printed_chars += printf("%d", num);
}
else
{

putchar('%');
printed_chars++;
}
}
else
{
putchar(*format);
printed_chars++;
}

format++;
}
va_end(args);
return (printed_chars);
}

