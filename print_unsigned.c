#include "main.h"

/**
 * print_unsigned - prints unsigned int
 * @n: number
 *
 * Return: number of characters printed
 */
int print_unsigned(unsigned int n)
{
    int count = 0;
    char c;

    if (n / 10)
        count += print_unsigned(n / 10);

    c = (n % 10) + '0';
    count += _putchar(c);

    return (count);
}

