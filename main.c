int main(void)
{
    _printf("%b\n", 98);
    _printf("Char: %c\n", 'A');
    _printf("String: %s\n", "Hello, world!");
    _printf("Decimal: %d\n", 1234);
    _printf("Percent sign: %%\n");

    _printf("Hex lowercase: %#x\n", 255);
    _printf("Binary: %b\n", 5);
    _printf("Address: %p\n", main);

    return 0;
}
