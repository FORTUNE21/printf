#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int loop_format(const char *format, va_list args);
int check_percent(int *flag, char charac);
int func_service(char charac, va_list args);
int _switch(char c, va_list arg);
int print_character(va_list arg);
int print_signInt(va_list arg, int base);
int print_unsignedInt(va_list arg, int base);
int print_base16_upper_lower(va_list arg, char *rep);
int print_addr(va_list arg);
int print_string(va_list arg);
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *convert_to_format(char *rep, unsigned int number, int base);

#endif /*MAIN_H*/
