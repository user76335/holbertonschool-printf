#include "main.h"
#include <stdarg.h>

/**
 * _printf - custom printf implementation
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += print_char(va_arg(args, int));
                    break;
                case 's':
                    count += print_string(va_arg(args, char *));
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    count += print_number(va_arg(args, int));
                    break;
                case 'u':
                    count += print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'o':
                    count += print_octal(va_arg(args, unsigned int));
                    break;
                case 'x':
                    count += print_hex(va_arg(args, unsigned int), 0);
                    break;
                case 'X':
                    count += print_hex(va_arg(args, unsigned int), 1);
                    break;
                case 'b':
                    count += print_binary(va_arg(args, unsigned int));
                    break;
                case 'p':
                    count += print_address(va_arg(args, void *));
                    break;
                default:
                    count += _putchar('%');
                    count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}
