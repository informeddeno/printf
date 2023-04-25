#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/*
* print_unsigned - Prints an unsigned number
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: obtain width
* @precision: Precision
* @size: obtain Size
* Return: Number of chars printed.
*/
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int n = BUFSIZ - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[n--] = '0';
buffer[BUFSIZ - 1] = '\0';
while (num > 0)
{
buffer[n--] = (num % 10) + '0';
num /= 10;
}
n++;
return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}

/*
* print_octal - Prints an unsigned number in octal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: obtain width
* @precision: Precision
* @size: obtain Size
* Return: Number of chars printed
*/
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int d = BUFSIZ - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[d--] = '0';
buffer[BUFSIZ - 1] = '\0';
while (num > 0)
{
buffer[d--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[d--] = '0';
d++;
return (write_unsgnd(0, d, buffer, flags, width, precision, size));
}

/*
* print_hexadecimal - Prints an unsigned number in hexadecimal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: obtain width
* @precision: Precision
* @size: obtain Size
* Return: Number of chars printed
*/
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/*
* print_hexa_upper - Prints an unsigned number hexadecimal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: obtain width
* @precision: Precision
* @size: obtain Size
* Return: Number of chars printed
*/
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/*
* print_hexa - Prints a hexadecimal number in lower or upper
* @types: Lista of arguments
* @map_to: Array of values to map the number to
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @flag_ch: Calculates active flags
* @width: obtain width
* @precision: Precision
*

* @size: obtain Size
* Return: Number of chars printed
*/
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int v = BUFSIZ - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[v--] = '0';
buffer[BUFSIZ - 1] = '\0';
while (num > 0)
{
buffer[v--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[v--] = flag_ch;
buffer[v--] = '0';
}
v++;
return (write_unsgnd(0, v, buffer, flags, width, precision, size));
}
