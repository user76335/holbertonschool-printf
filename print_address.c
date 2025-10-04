#include "main.h"

/**
 * print_address - prints a pointer address in hexadecimal
 * @p: pointer
 *
 * Return: number of characters printed
 */
int print_address(void *p)
{
    unsigned long int addr = (unsigned long int)p;
    int count = 0;

    count += print_string("0x");
    count += print_hex(addr, 0);

    return (count);
}
