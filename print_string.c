#include "main.h"

/* Print a string */
int _puts(char *str)
{
    int len = 0;

    if (!str)
        str = "(null)";
    while (*str)
    {
        len += _putchar(*str);
        str++;
    }
    return len;
}
