#include "main.h"

/* Print unsigned integer in a given base */
int print_unsigned(unsigned int n, int base, int uppercase)
{
    char buffer[32];
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int i = 0, len = 0;

    if (n == 0)
        return _putchar('0');

    while (n)
    {
        buffer[i++] = digits[n % base];
        n /= base;
    }

    while (i--)
        len += _putchar(buffer[i]);

    return len;
}
