#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * handle_unsigned - prints an unsigned integer to stdout (specifier: 'u')
 * @args: the va_list containing the unsigned integer to print
 *
 * Return: number of characters printed
 */
int handle_unsigned(va_list args) 
{
    unsigned int n = va_arg(args, unsigned int); /* Get unsigned int */
    return put_unsigned(n);
}

/**
 * put_unsigned - prints an unsigned integer to stdout
 * @num: the unsigned integer to print
 *
 * Return: number of characters printed
 */
int put_unsigned(unsigned int num)
{
	int count = 0;

	if (num >= 10)
		count += put_unsigned(num / 10);

	count += _putchar((num % 10) + '0');
	return count;
}

/**
 * handle_octal - prints an octal number to stdout (specifier: 'o')
 * @args: the va_list containing the octal number to print
 *
 * Return: number of characters printed
 */
int handle_octal(va_list args) 
{
    unsigned int n = va_arg(args, unsigned int); /* Get unsigned int for octal */
    return put_octal(n);
}

/**
 * put_octal - prints an octal number to stdout
 * @num: the octal number to print
 *
 * Return: number of characters printed
 */
int put_octal(unsigned int num)
{
    int count = 0;

    if (num >= 8)
        count += put_octal(num / 8);

    count += _putchar((num % 8) + '0');
    return count;
}

