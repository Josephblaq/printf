#define MAIN_H
#include<stdarg.h>
#include<stdio.h>

int _printf(const char *format, ...);
int _write(char *str);
void *_malloc(size_t size);
void _free(void *ptr);
void _variadicFunction(int num, ...);
void _print_char(va_list args);
void _print_string(va_list args);
void _print_percent(va_list args);

#endif
