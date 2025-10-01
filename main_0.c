#include <stdio.h>
#include "main.h"

int main(void)
{
	int count;

	count = _printf("Hello %s. Your grade is %c%%\n", "Alice", 'A');
	printf("Printed %d characters.\n", count);

	return (0);
}
