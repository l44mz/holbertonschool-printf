#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * put_binary - prints an unsigned integer in binary to stdout
 * @num: the unsigned integer to print in binary
 *
 * Return: number of characters printed
 */
int put_binary(unsigned int num)
{
    int count = 0;

    if (num >= 2)
        count += put_binary(num / 2); /* Recursively print higher bits */

    count += _putchar((num % 2) + '0'); /* Print the least significant bit */
    return count;
}

/**
 * handle_binary - prints an unsigned integer in binary to stdout (specifier: 'b')
 * @args: the va_list containing the unsigned integer to print in binary
 *
 * Return: number of characters printed
 */
int handle_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int); /* Get unsigned int for binary */
    return put_binary(n);
}
