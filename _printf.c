#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				printed += print_char(args);
			else if (format[i] == 's')
				printed += print_string(args);
			else if (format[i] == '%')
				printed += write(1, "%", 1);
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				printed += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed++;
		}
		i++;
	}

	va_end(args);
	return (printed);
}
