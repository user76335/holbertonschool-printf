#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer recursively
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned(n / 10);

    count += _putchar((n % 10) + '0');

    return count;
}

/**
 * print_number - Prints a signed integer with flags + and space
 * @n: The signed integer to print
 * @flags: Flags struct with plus and space flags set
 *
 * Return: Number of characters printed
 */
int print_number(int n, flags_t flags)
{
    int count = 0;
    unsigned int num;

    if (n >= 0)
    {
        if (flags.plus)
            count += _putchar('+');
        else if (flags.space)
            count += _putchar(' ');
        num = n;
    }
    else
    {
        count += _putchar('-');
        num = -n;
    }

    count += print_unsigned(num);

    return count;
}
