#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                int len = 0;
                while (s[len])
                    len++;
                write(1, s, len);
                count += len;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);

    return (count);
}

