#include "main.h"

/**
 * print_string - Prints a string
 * @args: va_list containing the string
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int len = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}

	return (len);
}
