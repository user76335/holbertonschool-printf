#include "main.h"
#include <stdarg.h>

/**
 * parse_flags - Parses flag characters and sets the flags struct
 * @format: Pointer to the format string
 * @flags: Pointer to flags struct to fill
 * Return: Number of flag characters parsed
 */
int parse_flags(const char *format, flags_t *flags)
{
    int i = 0;

    while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
    {
        if (format[i] == '+')
            flags->plus = 1;
        else if (format[i] == ' ')
            flags->space = 1;
        else if (format[i] == '#')
            flags->hash = 1;
        i++;
    }

    return i;
}

/**
 * _printf - Custom printf implementation with +, space, and # flags
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    flags_t flags;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (!*format)
                break;

            /* Reset and parse flags */
            flags.plus = 0;
            flags.space = 0;
            flags.hash = 0;
            format += parse_flags(format, &flags);

            /* Handle format specifier */
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
                    count += print_number(va_arg(args, int), flags);
                    break;
                case 'u':
                    count += print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'o':
                    count += print_octal(va_arg(args, unsigned int), flags);
                    break;
                case 'x':
                    count += print_hex(va_arg(args, unsigned int), 0, flags);
                    break;
                case 'X':
                    count += print_hex(va_arg(args, unsigned int), 1, flags);
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
