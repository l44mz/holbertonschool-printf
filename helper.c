#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to stdout using a buffer
 * @ch: the character to write
 *
 * Return: 1 on success, 0 on flush or reset
 */
int _putchar(char ch)
{
	static int count;
	static char buffer[1024];

	if (ch == -1)
	{
		count = 0;
		return (0);
	}
	if (ch == -2 || count == 1024)
	{
		write(1, buffer, count);
		count = 0;
	}
	if (ch != -1 && ch != -2)
	{
		buffer[count] = ch;
		count++;
		return (1);
	}
	return (0);
}

/**
 * print_string - prints a string to stdout
 * @p: pointer to the string to print
 *
 * Return: number of characters printed
 */
int print_string(char *p)
{
	int count;

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
 * print_int - prints an integer to stdout
 * @i: the integer to print
 *
 * Return: number of characters printed
 */
int print_int(int i)
{
	int count;
	unsigned int num;

	count = 0;
	if (i < 0)
	{
		count += _putchar('-');
		num = (unsigned int)(i * -1);
	}
	else
		num = (unsigned int)i;
	if (num >= 10)
		count += print_int(num / 10);
	count += _putchar((num % 10) + '0');
	return (count);
}
