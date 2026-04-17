#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * handle_hex_lower - prints a hexadecimal number 
 * in lowercase  to stdout (specifier: 'x')
 * @args: the va_list containing the hexadecimal number to print
 *
 * Return: number of characters printed
 */
int handle_hex_lower(va_list args) 
{
    unsigned int n = va_arg(args, unsigned int); /* Get unsigned int for hexadecimal */
    return put_hex_lower(n);
}

/**
 * put_hex_lower - prints a hexadecimal number in lowercase to stdout
 * @num: the hexadecimal number to print
 *
 * Return: number of characters printed
 */
int put_hex_lower(unsigned int num)
{
    int count = 0;
    char *hex_digits = "0123456789abcdef"; /* Hexadecimal digits for lowercase */

    if (num >= 16)
        count += put_hex_lower(num / 16);

    count += _putchar(hex_digits[num % 16]);
    return count;
}

/**
 * handle_hex_upper - prints a hexadecimal number in 
 * uppercase to stdout (specifier: 'X')
 * @args: the va_list containing the hexadecimal number to print
 *
 * Return: number of characters printed
 */
int handle_hex_upper(va_list args) 
{
    unsigned int n = va_arg(args, unsigned int); 
    return put_hex_upper(n);
}

/**
 * put_hex_upper - prints a hexadecimal number in uppercase to stdout
 * @num: the hexadecimal number to print
 *
 * Return: number of characters printed
 */
int put_hex_upper(unsigned int num)
{
    int count = 0;
    char *hex_digits = "0123456789ABCDEF"; /* Hexadecimal digits for uppercase */

    if (num >= 16)
        count += put_hex_upper(num / 16);

    count += _putchar(hex_digits[num % 16]);
    return count;
}

