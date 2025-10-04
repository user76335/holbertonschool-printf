#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Flag structure */
typedef struct flags_s
{
    int plus;
    int space;
    int hash;
} flags_t;


/* _printf function */
int _printf(const char *format, ...);

/* Helper functions */
int _putchar(char c);
int print_char(char c);
int print_string(char *s);
int print_number(int n, flags_t flags);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n, flags_t flags);
int print_binary(unsigned int n);
int print_hex(unsigned int n, int uppercase, flags_t flags);
int print_address(void *p);

#endif /* MAIN_H */

