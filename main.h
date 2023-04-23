#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>

/*
 *print_info: gives information about format specification
 *
 *
 */

struct printf_info
{
int prec;
int width;
wchar_t spec;
unsigned int is_long_double:1;
unsigned int is_short:1;
unsigned int is_long:1;
unsigned int alt:1;
unsigned int space:1;
unsigned int left:1;
unsigned int showsign:1;
unsigned int group:1;
unsigned int extra:1;
unsigned int is_char:1;
unsigned int wide:1;
unsigned int i18n:1;
unsigned int __pad:4;
unsigned short int user;
wchar_t pad;
};

typedef int _printf(const char *format, ...);

#endif
