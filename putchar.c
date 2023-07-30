#include "main.h"
#include <unistd.h>
/**
 * _putchar - Custom putchar function to print a single character
 * @c: The character to be printed
 * Return: On success, returns 1; on failure, -1 is returned
 */
int _putchar(char c)
{
	write(1, &c, 1);

	return (1);
}
