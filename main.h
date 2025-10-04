#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* _printf prototype */
int _printf(const char *format, ...);

/* Helper function prototypes */
int _putchar(char c);
int _puts(char *str);
int print_number(int n);
int print_unsigned(unsigned int n, int base, int uppercase);
int print_binary(unsigned int n);

#endif /* MAIN_H */

