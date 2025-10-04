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

/* print_char: print a single character */
int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return write(1, &c, 1);
}

/* print_string: print a string */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (!str)
        str = "(null)";

    while (str[len])
        len++;

    return write(1, str, len);
}

/* print_int: print a signed integer */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    char buffer[12];
    int i = 0, count = 0;
    unsigned int num;

    if (n == 0)
        return write(1, "0", 1);

    if (n < 0)
    {
        count += write(1, "-", 1);
        num = -n;
    }
    else
        num = n;

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i--)
        count += write(1, &buffer[i], 1);

    return count;
}

/* handle_format: dispatch to correct print function */
int handle_format(char format_char, va_list args)
{
    if (format_char == 'c')
        return print_char(args);
    if (format_char == 's')
        return print_string(args);
    if (format_char == 'd' || format_char == 'i')
        return print_int(args);
    if (format_char == 'b')
    {
        unsigned int num = va_arg(args, unsigned int);
        return print_binary(num);
    }
    if (format_char == '%')
        return write(1, "%", 1);

    /* Unknown specifier: print '%' and the char */
    write(1, "%", 1);
    return write(1, &format_char, 1) + 1;
}

/* _printf: simplified printf supporting %b */
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

/* main: test the _printf with %b */
int main(void)
{
    _printf("%b\n", 98);  /* Should print: 1100010 */
    _printf("Char: %c\n", 'A');  /* Char: A */
    _printf("String: %s\n", "Hello, world!");
    _printf("Decimal: %d\n", 1234);
    _printf("Percent sign: %%\n");

    return 0;
}
