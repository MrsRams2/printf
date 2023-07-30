#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * _putchar - Custom putchar function to print a single character
 * @c: The character to be printed
 * Return: On success, returns the number of characters printed
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _printf - Custom printf function that produces output according to a format
 * @format: The format string
 * Return: On success, returns the number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    if (!format)
        return (-1);

    va_start(args, format);
    printed_chars = format_parser(format, args);
    va_end(args);

    return (printed_chars);
}

/**
 * format_parser - Parses the format string and prints the output accordingly
 * @format: The format string
 * @args: The variable arguments list
 * Return: On success, returns the number of characters printed
 */
int format_parser(const char *format, va_list args)
{
    int i = 0, printed_chars = 0;

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
            {
                printed_chars += _putchar(va_arg(args, int));
            }
            else if (format[i] == 's')
            {
                printed_chars += print_string(va_arg(args, char *));
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                printed_chars += print_number(va_arg(args, int));
            }
            else if (format[i] == 'u')
            {
                printed_chars += print_unsigned(va_arg(args, unsigned int));
            }
            else if (format[i] == 'o')
            {
                printed_chars += print_octal(va_arg(args, unsigned int));
            }
            else if (format[i] == 'x' || format[i] == 'X')
            {
                printed_chars += print_hexadecimal(va_arg(args, unsigned int), format[i]);
            }
            else if (format[i] == 'p')
            {
                printed_chars += print_pointer(va_arg(args, void *));
            }
            else if (format[i] == '%')
            {
                printed_chars += _putchar('%');
            }
            else
            {
                printed_chars += _putchar('%');
                printed_chars += _putchar(format[i]);
            }
        }
        else
        {
            printed_chars += _putchar(format[i]);
        }
        i++;
    }
    return (printed_chars);
}

/**
 * print_string - Prints a string
 * @str: The string to be printed
 * Return: On success, returns the number of characters printed
 */
int print_string(const char *str)
{
    int i = 0;

    if (!str)
        str = "(null)";

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }

    return (i);
}

/**
 * print_number - Prints a signed integer
 * @num: The integer to be printed
 * Return: On success, returns the number of characters printed
 */
int print_number(int num)
{
    int printed_chars = 0;

    if (num < 0)
    {
        _putchar('-');
        printed_chars++;
        num = -num;
    }

    if (num / 10)
        printed_chars += print_number(num / 10);

    _putchar((num % 10) + '0');
    printed_chars++;

    return (printed_chars);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @num: The unsigned integer to be printed
 * Return: On success, returns the number of characters printed
 */
int print_unsigned(unsigned int num)
{
    int printed_chars = 0;

    if (num / 10)
        printed_chars += print_unsigned(num / 10);

    _putchar((num % 10) + '0');
    printed_chars++;

    return (printed_chars);
}

/**
 * print_octal - Prints an unsigned integer as octal
 * @num: The unsigned integer to be printed
 * Return: On success, returns the number of characters printed
 */
int print_octal(unsigned int num)
{
    int printed_chars = 0;

    if (num / 8)
        printed_chars += print_octal(num / 8);

    _putchar((num % 8) + '0');
    printed_chars++;

    return (printed_chars);
}

/**
 * print_hexadecimal - Prints an unsigned integer as hexadecimal
 * @num: The unsigned integer to be printed
 * @format: The format character ('x' or 'X' for lowercase/uppercase)
 * Return: On success, returns the number of characters printed
 */
int print_hexadecimal(unsigned int num, char format)
{
    int printed_chars = 0;
    char hex_digits[] = "0123456789abcdef";
    char hex_digits_upper[] = "0123456789ABCDEF";
    char *hex_ptr = (format == 'x') ? hex_digits : hex_digits_upper;

    if (num / 16)
        printed_chars += print_hexadecimal(num / 16, format);

    _putchar(hex_ptr[num % 16]);
    printed_chars++;

    return (printed_chars);
}

/**
 * print_pointer - Prints a pointer address in hexadecimal
 * @ptr: The pointer to be printed
 * Return: On success, returns the number of characters printed
 */
int print_pointer(void *ptr)
{
    int printed_chars = 0;
    unsigned long int addr = (unsigned long int)ptr;

    _putchar('0');
    _putchar('x');
    printed_chars += 2;

    if (addr == 0)
    {
        _putchar('0');
        printed_chars++;
        return (printed_chars);
    }

    printed_chars += print_hexadecimal(addr, 'x');
    return (printed_chars);
}
