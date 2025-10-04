#include "main.h"

int print_hex(unsigned int n, int uppercase, flags_t flags)
{
    int count = 0;

    if (flags.hash && n != 0)
    {
        count += _putchar('0');
        count += _putchar(uppercase ? 'X' : 'x');
    }

    count += print_base(n, 16, uppercase); /* You must have this utility function */
    return count;
}


