#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
* Struct specifier - Struct to map format specifiers
* to their corresponding functions
* @character: The format specifier character (example: 'c')
* @fptr: Pointer to the function that handles corresponding specifier
*
*/
struct specifier 
{
    char character;
    int (*fptr)(va_list args);
};

/** Function prototypes */
int _printf(const char *format, ...);
int specifier_handler(char specifier, va_list args);
int _putchar(char ch);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_int(va_list args);
int put_int(int i);
int handle_unsigned(va_list args);
int put_unsigned(unsigned int num);
int handle_octal(va_list args);
int put_octal(unsigned int num);
int handle_hex_lower(va_list args);
int put_hex_lower(unsigned int num);
int handle_hex_upper(va_list args);
int put_hex_upper(unsigned int num);
int handle_binary(va_list args);
int put_binary(unsigned int num);

#endif

