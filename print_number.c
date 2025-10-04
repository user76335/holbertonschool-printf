int print_number(int n, flags_t flags)
{
    int count = 0;
    unsigned int num;

    if (n >= 0)
    {
        if (flags.plus)
            count += _putchar('+');
        else if (flags.space)
            count += _putchar(' ');
        num = n;
    }
    else
    {
        count += _putchar('-');
        num = -n;
    }

    count += print_unsigned(num);
    return count;
}
