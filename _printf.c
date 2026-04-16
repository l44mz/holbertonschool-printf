#include "main.h"
#include <stdarg.h>
/**
 * _printf - produces output according to a format.
 * @format: A string that contains the text to be written to stdout.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings).
 */

int _printf(const char *format, ...)
{
    int count = 0;
    const char *ptr = format;
    va_list args;
    va_start(args, format);
    _putchar(-1);
    while (*ptr)
    {
        if (*ptr == '%' && *(ptr + 1) != '\0')
        {
            ptr++;
            if (*ptr == 'c')
            {
                int c = va_arg(args, int);
                count += _putchar(c);
            }
            else if (*ptr == 's')
            {
                char *str = va_arg(args, char *);
                count += print_string(str);
            }
            else if (*ptr == 'd' || *ptr == 'i')
            {
                int num = va_arg(args, int);
                count += print_int(num);
            }
            else if (*ptr == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_unsigned(num);
            }
            else if (*ptr == '%')
            {
                count += _putchar('%');
            }
            else
            {
		count += _putchar('%');
                count += _putchar(*ptr);
            }
        }
        else if (*ptr == '%' && *(ptr + 1) == '\0')
        {
            return (-1);
        }
        else
        {
            count += _putchar(*ptr);
        }
        ptr++;
    }
    _putchar(-2);
    va_end(args);
    return (count);
}
