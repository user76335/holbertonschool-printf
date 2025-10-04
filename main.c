#include <stdarg.h>
#include <unistd.h>

/* _putchar writes a single character */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* print_binary: prints an unsigned int in binary */
int print_binary(unsigned int n)
{
    int i, count = 0, started = 0;
    unsigned int mask = 1 << 31;

    for (i = 0; i < 32; i++)
    {
        if (n & mask)
        {
            _putchar('1');
            count++;
            started = 1;
        }
        else if (started)
        {
            _putchar('0');
            count++;
        }
        mask >>= 1;
    }

    if (!started)
    {
        _putchar('0');
        count++;
    }

    return count;
}

/* handle_format: dispatch to correct print function */
int handle_format(char format_char, va_list args)
{
    if (format_char == 'b')
    {
        unsigned int num = va_arg(args, unsigned int);
        return print_binary(num);
    }
    /* For unsupported formats, just print them literally */
    write(1, "%", 1);
    return write(1, &format_char, 1) + 1;
}

/* _printf: simplified printf supporting only %b */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed = 0, res;

    if (format == NULL)
        return -1;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
            {
                va_end(args);
                return -1;
            }
            res = handle_format(format[i], args);
            if (res == -1)
            {
                va_end(args);
                return -1;
            }
            printed += res;
        }
        else
            printed += write(1, &format[i], 1);
        i++;
    }

    va_end(args);
    return printed;
}

/* main: print binary of 98 only */
int main(void)
{
    _printf("%b\n", 98);
    return 0;
}
