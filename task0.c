#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include "_putchar.h"
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
            _putchar(*format);
            chara_str++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;
            if (*format == '%')
            {
                _putchar(*format);
		chara_str++;
            }
            else if (*format == 'c')
            {
                char C = (char)va_arg(arg_list, int);
                _putchar(C);
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

<<<<<<< HEAD
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
=======
				write(1, &C, 1);
				chara_str++;
			}
			else if (*format == 's')
			{
				char *ptr = va_arg(arg_list, char*);
				int str_len = 0;
>>>>>>> da8444d48481677892f0e8b750c53a0a60e5282f

        format++;
    }

    va_end(arg_list);

    return (chara_str);
}

