#include "main.h"

/**
 * print_int - Prints a signed integer (%d or %i)
 * @args: va_list containing the integer
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	count += print_number(num);
	return (count);
}
