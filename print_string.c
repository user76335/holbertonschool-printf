#include "main.h"

int print_string(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;

	return (write(1, str, len));
}
