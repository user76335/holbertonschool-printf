#include "main.h"

int print_octal(unsigned int n, flags_t flags)
{
    int count = 0;

    if (flags.hash && n != 0)
        count += _putchar('0');

    count += print_base(n, 8, 0);
    return count;
}

