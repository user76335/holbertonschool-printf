#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @n: the unsigned int to print
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
    int i, count = 0;
    int started = 0;
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
