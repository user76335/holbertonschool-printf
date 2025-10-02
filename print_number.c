#include "main.h"

/**
 * print_number - Prints an unsigned integer recursively
 * @n: Number to print
 * Return: Number of characters printed
 */
int print_number(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_number(n / 10);

    count += _putchar((n % 10) + '0');
    return (count);
}
