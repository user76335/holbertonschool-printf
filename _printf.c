#include "main.h"

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
