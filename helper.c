#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * handle_char - prints a character to stdout (specifier: 'c')
 * @args: the va_list containing the character to print
 *
 * Return: number of characters printed
 */
int handle_char(va_list args)
{
	char c = (char)va_arg(args, int); // Get char argument (promoted to int)
	return _putchar(c);
}

/**
 * handle_string - prints a string to stdout (specifier: 's')
 * @args: the va_list containing the string to print
 *
 * Return: number of characters printed
 */
int handle_string(va_list args)
{
	char *p = va_arg(args, char *); // Get string argument 
	int count;

	if (p == NULL)
		p = "(null)"; // Mimic printf behavior for NULL strings

	count = 0;
	while (*p)
	{
		_putchar(*p);
		p++;
		count++;
	}
	return (count);
}

/**
 * handle_int - prints an integer to stdout (specifier: 'd' | 'i')
 * @args: the va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int handle_int(va_list args)
{
	int i = va_arg(args, int); // Get int argument
	return put_int(i);
}

/**
 * put_int - prints an integer to stdout
 * @i: the integer to print
 *
 * Return: number of characters printed
 */
int put_int(int i)
{
	int count;
	unsigned int num;

	count = 0;
	
	if (i < 0)
	{
		count += _putchar('-'); // Print negative sign for negative numbers
		num = (unsigned int)(i * -1);
	}
	else
		num = (unsigned int)i;
	if (num >= 10)
		count += put_int(num / 10); // Print recursively for digits before the last one
	count += _putchar((num % 10) + '0');
	return (count);
}

