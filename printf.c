#include "main.h"
#include <stdio.h>
#include <strings.h>
#include <stdarg.h>

void print_buffer(char buffer[], int *buff_ind);

/*
 * description printf: output results
 *get_flags:obtain flags
 *get_size
 * get_width:obtain width
 * handle_print:print output
 * _printf :  display funtion
 * @format: output format.
 *print_buffer: print arrays
 * Return: Printed number of characters.
 */
int _printf(const char *format, ...)
{
	int x, printed = 0, printed_chars = 0;
	int flags, size, precision, width, buff_ind = 0;
	va_list list;
	char buffer[BUFSIZ];

	if (format == NULL)
		return (-1);
	va_start(list, format);
		for (x = 0; format && format[x] != '\0'; x++)
		{
			if (format[x] != '%')
			{
				buffer[buff_ind++] = format[x];
				if (buff_ind == BUFSIZ)
					print_buffer(buffer, &buff_ind);
				printed_chars++;
				}
				else
				{
					print_buffer(buffer, &buff_ind);
					flags = get_flags(format, &x);
					width = get_width(format, &x, list);
					precision = get_precision(format, &x, list);
					size = get_size(format, &x);
					++x;
					printed = handle_print(format, &x, list, buffer,
							flags, width, precision, size);
					if (printed == -1)
						return (-1);
					printed_chars += printed;
				}
		}
		
		print_buffer(buffer, &buff_ind);
		
		va_end(list);
		
		return (chars);
}
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

