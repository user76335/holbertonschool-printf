#include "main.h"
#include <unistd.h>

/* Print a single character */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* Print a string */
int _puts(char *str)
{
    int len = 0;

    if (!str)
        str = "(null)";
    while (*str)
    {
        len += _putchar(*str);
        str++;
    }
    return len;
}

/* Print signed integer */
int print_number(int n)
{
    int len = 0;
    unsigned int num;

    if (n < 0)
    {
        len += _putchar('-');
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        len += print_number(num / 10);
    len += _putchar(num % 10 + '0');

    return len;
}

/* Print unsigned int in given base */
int print_unsigned(unsigned int n, int base, int uppercase)
{
    char buffer[32];
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int i = 0, len = 0;

    if (n == 0)
        return _putchar('0');

    while (n)
    {
        buffer[i++] = digits[n % base];
        n /= base;
    }

    while (i--)
        len += _putchar(buffer[i]);

    return len;
}

/* Print unsigned int in binary */
int print_binary(unsigned int n)
{
    return print_unsigned(n, 2, 0);
}

/* The main _printf function */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, len = 0;

    if (!format)
        return -1;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                len += _putchar(va_arg(args, int));
            else if (format[i] == 's')
                len += _puts(va_arg(args, char *));
            else if (format[i] == '%')
                len += _putchar('%');
            else if (format[i] == 'd' || format[i] == 'i')
                len += print_number(va_arg(args, int));
            else if (format[i] == 'b')
                len += print_binary(va_arg(args, unsigned int));
            else if (format[i] == 'u')
                len += print_unsigned(va_arg(args, unsigned int), 10, 0);
            else if (format[i] == 'o')
                len += print_unsigned(va_arg(args, unsigned int), 8, 0);
            else if (format[i] == 'x')
                len += print_unsigned(va_arg(args, unsigned int), 16, 0);
            else if (format[i] == 'X')
                len += print_unsigned(va_arg(args, unsigned int), 16, 1);
            else
            {
                len += _putchar('%');
                if (format[i])
                    len += _putchar(format[i]);
                else
                    i--;
            }
        }
        else
            len += _putchar(format[i]);
        i++;
    }
    va_end(args);
    return len;
}

