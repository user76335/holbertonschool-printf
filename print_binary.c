#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @n: number
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
    int count = 0;
    char c;

    if (n / 2)
        count += print_binary(n / 2);

    c = (n % 2) + '0';
    count += _putchar(c);

    return (count);
}
