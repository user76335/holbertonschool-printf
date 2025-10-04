#include "main.h"

/**
 * print_octal_number - Recursively prints an unsigned int in octal
 * @n: The number to print
 *
 * Return: Number of characters printed
 */
int print_octal_number(unsigned int n)
{
    int count = 0;

    if (n / 8)
        count += print_octal_number(n / 8);

    count += _putchar((n % 8) + '0');

    return count;
}

/**
 * print_octal - Prints an unsigned int in octal with '#' flag support
 * @n: The number to print
 * @flags: Flags struct containing the hash flag
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int n, flags_t flags)
{
    int count = 0;

    if (flags.hash && n != 0)
        count += _putchar('0');

    count += print_octal_number(n);

    return count;
}
