#include "main.h"

/* Print signed integer */
int print_number(int n)
{
    int len = 0;
    unsigned int num;

    if (n < 0)
    {
        len += _putchar('-');
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        len += print_number(num / 10);
    len += _putchar(num % 10 + '0');

    return len;
}

