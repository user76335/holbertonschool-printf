#include "main.h"

/**
 * print_octal - prints an unsigned integer in octal
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_octal(unsigned int n)
{
    int count = 0;
    char c;

    if (n / 8)
        count += print_octal(n / 8);

    c = (n % 8) + '0';
    count += _putchar(c);

    return (count);
}
