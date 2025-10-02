#include "main.h"

/**
 * print_int - Prints a decimal integer
 * @args: va_list of arguments
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
        num = n;

    count += print_number(num);
    return (count);
}

