
# _printf - Custom C printf Implementation

A custom implementation of the C standard library printf function,
built as part of the Holberton School curriculum. This project replicates
core formatting behavior of printf using only a limited set of authorized
system calls and functions.

---

## Description

_printf is a variadic function that formats and prints output to stdout.
It processes a format string containing zero or more conversion specifiers
and outputs the formatted result, returning the total number of characters
printed (excluding the null terminator).

### Supported Conversion Specifiers

| Specifier | Description |
|-----------|-------------|
| %c | Prints a single character |
| %s | Prints a string |
| %d | Prints a signed decimal integer |
| %i | Prints a signed integer |
| %% | Prints a literal % character |

---

## Requirements

- OS: Ubuntu 20.04 LTS
- Compiler: gcc with flags -Wall -Werror -Wextra -pedantic -std=gnu89
- Coding style: Betty style
- No global variables allowed
- No more than 5 functions per file
- Authorized functions: write, malloc, free, va_start, va_end, va_copy, va_arg

---

## Files

| File | Description |
|------|-------------|
| _printf.c | Main _printf function |
| handlers.c | Conversion specifier handler functions |
| main.h | Header file with prototypes and include guards |
| man_3_printf | Manual page for _printf |
| README.md | Project documentation |

---

## Installation

1. Clone the repository:

git clone https://github.com/l44mz/holbertonschool-printf.git
cd holbertonschool-printf

2. Compile the project:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf

---

## Usage

Include the header in your source file:

#include "main.h"

Then call _printf exactly as you would the standard printf:

_printf("Hello, %s! You are %d years old.\n", "Alice", 30);

Function prototype:

int _printf(const char *format, ...);

Return value: Number of characters printed, excluding the null byte.

---

## Examples

_printf("Character: [%c]\n", 'Z');
_printf("String:    [%s]\n", "Holberton");
_printf("Decimal:   [%d]\n", 42);
_printf("Integer:   [%i]\n", -7);
_printf("Negative:  [%d]\n", -762534);
_printf("Percent:   [%%]\n");

Expected output:

Character: [Z]
String:    [Holberton]
Decimal:   [42]
Integer:   [-7]
Negative:  [-762534]
Percent:   [%]

---

## Testing

gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format test/main.c *.c -o test_printf
./test_printf

---

## Man Page

To view the manual page for _printf:

man ./man_3_printf

---

## Authors

- Ghaida Alsabti - GitHub: https://github.com/Ghaaidda
- Lama Almazroa - GitHub: https://github.com/l44mz

