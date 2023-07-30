#include "main.h"

/**
 *  print_char - prints characters
 *  @args: the character argument
 *
 *  Return: void
 */

void print_char(va_list args)
{
	char ch = va_arg(args, int);

	_putchar(ch);
}

/**
 *  print_percent - prints the %
 *  @args: the argument to printt
 *
 *  Return: void
 */

void print_percent(va_list args)

{
	(void)args;
	_putchar('%');
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
		if (format[i] == '%' && format[++i] != '%')
		{
			if (format[i] == 'c')
				_putchar(va_arg(args, int));
			else if (format[i] == 's')
				printed_chars += print_string(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				printed_chars += print_number(va_arg(args, int));
			else
			{
				_putchar('%');
				_putchar(format[i]);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
		printed_chars++;
	}


	return (printed_chars);
}
/**
 * print_string - Prints a string
 * @str: The string to be printed
 * Return: On success, returns the number of characters printed
 */
int print_string(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i] != '\0')
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
