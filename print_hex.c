#include "main.h"

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @n: number
 * @uppercase: 1 for uppercase, 0 for lowercase
 *
 * Return: number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
    int count = 0;
    char c;
    char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        count += print_hex(n / 16, uppercase);

    c = hex[n % 16];
    count += _putchar(c);

    return (count);
}

