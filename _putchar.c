#include "main.h"
#include <unistd.h>
#include <stdarg.h>

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

	if (ch == -1) // Reset buffer for new _printf call
	{
		count = 0;
		return (0);
	}
	if (ch == -2 || count == 1024) // Flush buffer when full or on final flush signal
	{
		write(1, buffer, count);
		count = 0;
	}
	if (ch != -1 && ch != -2) // Add character to buffer
	{
		buffer[count] = ch;
		count++;
		return (1);
	}
	return (0);
}

