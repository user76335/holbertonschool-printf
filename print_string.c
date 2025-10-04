#include "main.h"

/**
 * print_string - prints a string
 * @s: string
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
    int len = 0;

    if (!s)
        s = "(null)";

    while (*s)
    {
        _putchar(*s);
        len++;
        s++;
    }

    return (len);
}
