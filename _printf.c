#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * specifiers - Array of format specifiers
 *  and their corresponding handlers
 */
struct specifier specifiers[] = {
        {'c', handle_char},
        {'s', handle_string},
        {'d', handle_int},
        {'i', handle_int},
        {'u', handle_unsigned},
        {'o', handle_octal},
        {'x', handle_hex_lower},
        {'X', handle_hex_upper},
        {'\0', NULL} /* null terminator to mark end of array */
    };

/**
    * specifier_handler - Handles the format 
    * specifier and calls the corresponding function
    * @specifier: The format specifier character (example: 'c')
    * @args: The va_list containing the arguments passed to _printf
    *
    * Return: The number of characters printed by the handler
    */
int specifier_handler(char specifier, va_list args)
{
    int i;
    for (i = 0; specifiers[i].character != '\0'; i++)
    {
        if (specifiers[i].character == specifier)
        {
            return specifiers[i].fptr(args);
        }
    }
    return (-1); /* No valid specifier */
}

/**
 * _printf - produces output according to a format.
 * @format: A string that contains the text to be written to stdout.
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    const char *ptr = format;
    int count = 0, printed = 0;
    va_list args;

    if (!format)
        return (-1); /* Case: handle NULL format string */

    va_start(args, format);
    _putchar(-1); /* Reset buffer */

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == '\0') /* Case: _printf("%") */
            {
                va_end(args);
                return (-1); 
            }
            if (*ptr == '%') /* Case: _printf("%%") */
            {
                count += _putchar('%');
            }
            else 
            {
                printed = specifier_handler(*ptr, args);
                if (printed != -1) /* Valid specifier found */
                {
                    count += printed;
                }
                else /* Unknown specifier: _printf("%[unknown character]") */
                {
                    count += _putchar('%');
                    count += _putchar(*ptr);
                }
            }
        }
        else
        {
            count += _putchar(*ptr);
        }
        ptr++;
    }
    _putchar(-2); /* Final Flush */
    va_end(args);
    return (count);
}

