#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - program that prints formatted strings to stdout
 * @format: char pointer to the arguments to be printed
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int chara_str = 0;
    va_list arg_list;

    if (format == NULL)
        return (-1);

    va_start(arg_list, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            chara_str++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;
            if (*format == '%')
            {
                write(1, format, 1);
                chara_str++;
            }
            else if (*format == 'c')
            {
                char C = (char)va_arg(arg_list, int);

                write(1, &C, 1);
                chara_str++;
            }
            else if (*format == 's')
            {
                char *ptr = va_arg(arg_list, char *);
                if (ptr != NULL)
                {
                    int str_len = 0;
                    while (ptr[str_len] != '\0')
                        str_len++;

                    write(1, ptr, str_len);
                    chara_str += str_len;
                }
                else
                {
                    write(1, "(null)", 6);
                    chara_str += 6;
                }
            }
        }

        format++;
    }

    va_end(arg_list);

    return (chara_str);
}

