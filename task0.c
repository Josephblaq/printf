#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

int _printf(const char *format, ...);
{
	int chara_str = 0;
	va_list arg_list;

	if (format = NULL)
	{
		return (-1);
	}
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
		}
		if (*format == '\0')
			break;
		if (*format == '%')
		{
			write(1, format, 1);
			chara_str++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(arg_list, int);
			write(1, &c, 1);
			chara_str++;
		}
		else if (*format == 's')
		{
			char *ptr = va_arg(arg_list, char*);
			int str_len = 0;

			while (ptr[str_len] != '\0')
				str_len++;

			write(1, ptr, str_len);
			chara_str += str_len;
		}
	}
	format++;
}
va_end(arg_list);
return(chara_str);
