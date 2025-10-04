#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
