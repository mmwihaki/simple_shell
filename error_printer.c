#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
    unsigned long int result = 0;

    if (*s == '+')
        s++;  /* TODO: why does this make main return 255? */
    while (*s != '\0')
    {
        if (*s >= '0' && *s <= '9')
        {
            result *= 10;
            result += (*s - '0');
            if (result > INT_MAX)
                return (-1);
        }
        else
            return (-1);

        s++;
    }
    return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
}

/**
 * print_d_recursive - recursive helper to print a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 * @count: pointer to the count of characters printed
 * @__putchar: pointer to the character output function
 *
 * Return: void
 */
void print_d_recursive(int input, int *count, int (*__putchar)(char))
{
    unsigned int _abs_, current;
    int i;

    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        (*count)++;
    }
    else
        _abs_ = input;
    current = _abs_;

    for (i = 1000000000; i > 1; i /= 10)
    {
        if (_abs_ / i)
        {
            __putchar('0' + current / i);
            (*count)++;
        }
        current %= i;
    }

    __putchar('0' + current);
    (*count)++;
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
    int (*__putchar)(char) = _putchar;
    int count = 0;

    if (fd == STDERR_FILENO)
        __putchar = _eputchar;

    print_d_recursive(input, &count, __putchar);

    return count;
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }

    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;
    return ptr;
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
    while (*buf != '\0')
    {
        if (*buf == '#' && *(buf - 1) == ' ')
        {
            *buf = '\0';
            break;
        }
        buf++;
    }
}
