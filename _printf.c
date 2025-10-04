#include "main.h"

/**
 * handle_format - Handle a format specifier and print accordingly
 * @format_char: The format specifier character
 * @args: va_list of arguments
 * Return: Number of characters printed
 */
int handle_format(char format_char, va_list args)
{
	if (format_char == 'c')
		return (print_char(args));
	if (format_char == 's')
		return (print_string(args));
	/*-placed-*/
	if (format_char == 'd' || format_char == 'i')
        return (print_int(args));
	/*-placed-*/
	if (format_char == 'b')
		return (print_binary(args));
	if (format_char == '%')
		return (write(1, "%", 1));

	/* Unknown specifier: print '%' and the character */
	write(1, "%", 1);
	return (write(1, &format_char, 1) + 1);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed = 0, res;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			res = handle_format(format[i], args);
			printed += res;
		}
		else
		{
			printed += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (printed);
}


/**
 * print_binary - Prints the binary representation of an unsigned int
 * @args: va_list containing the unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int started = 0;

	if (num == 0)
		return (write(1, "0", 1));

	while (mask > 0)
	{
		if (num & mask)
		{
			started = 1;
			count += write(1, "1", 1);
		}
		else if (started)
		{
			count += write(1, "0", 1);
		}
		mask >>= 1;
	}
	return (count);
}
