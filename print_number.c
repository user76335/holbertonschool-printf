#include "main.h"

/**
 * print_number - prints an integer
 * @n: number
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
    int count = 0;
    char c;

    if (n < 0)
    {
        count += _putchar('-');
        if (n == -2147483648)
        {
            count += print_string("2147483648");
            return (count);
        }
        n = -n;
    }

    if (n / 10)
        count += print_number(n / 10);

    c = (n % 10) + '0';
    count += _putchar(c);

    return (count);
}
