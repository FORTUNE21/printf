#include "main.h"
#include <stdarg.h>

/**
 * _printf - function produces output according to a format.
 * @format: is a pointer to string
 * Return: is the count of printed characters
 */
int _printf(const char *format, ...)
{
	const char *string;

	int count = 0;

	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	string = format;

	count = loop_format(string, args);

	va_end(args);

	return (count);
}

/**
 * loop_format - function is to print format
 * @format: is a pointer to string
 * @args: is a va_list args
 * Return: is an integer.
 */
int loop_format(const char *format, va_list args)
{
	int i = 0, counter = 0, flag = 0, check_flag = 0, f_counter = 0;

	while (i < _strlen((char *)format) && *(format + i) != '\0')
	{
		char charac = format[i];

		if (charac == '%')
		{
			flag++, i++;
			charac = format[i];
			if (charac == '\0' && _strlen((char *)format) == 1)
				return (-1);
			if (charac == '\0')
				return (counter);
			if (charac == '%')
				flag++;
			else
			{
				f_counter = func_service(charac, args);
				if (f_counter >= 0 && f_counter != -1)
				{
					i++;
					charac = format[i];
					if (charac == '%')
						flag--;
					counter += f_counter;
				}
				else if (f_counter == -1 && charac != '\n' && flag == 1)
					counter += _putchar('%');
			}

		}
		check_flag = check_percent(&flag, charac);
		counter += check_flag;
		if (check_flag == 0 && charac != '%' && charac != '\0')
			counter += _putchar(charac), i++;
		check_flag = 0;
	}
	return (counter);
}


/**
 * check_percent - print a percentage
 * @flag: is address of an int
 * @charac: is a char
 * Return: is 1 if % was printed, 0 otherwise.
 */
int check_percent(int *flag, char charac)
{
	int count = 0;

	int tmp;

	tmp = *flag;

	if (tmp == 2 && charac == '%')
	{
		count = _putchar('%');
		tmp = 0;
	}
	return (count);
}


/**
 * func_service - takes arguments and prints it accordingly
 * @charac: is a char or type determinant
 * @args: is a va_list
 * Return: is the number of characters printed
 */
int func_service(char charac, va_list args)
{
	int count = 0;

	count = _switch(charac, args);

	return (count);
}


/**
 * _switch - switch character to find arg
 * @arg: is a va_list argument
 * @c: is a char
 * Return: count of printed characters
 */
int _switch(char c, va_list arg)
{
	int count = 0;

	switch (c)
	{
		case 'c':
			count += print_character(arg);
			break;
		case 'd':
		case 'i':
			count += print_signInt(arg, 10);
			break;
		case 's':
			count += print_string(arg);
			break;
		case 'x':
			count += print_base16_upper_lower(arg, "0123456789abcdef");
			break;
		case 'X':
			count += print_base16_upper_lower(arg, "0123456789ABCDEF");
			break;
		case 'p':
			count += print_addr(arg);
			break;
		case 'o':
			count += print_unsignedInt(arg, 8);
			break;
		case 'u':
			count += print_unsignedInt(arg, 10);
			break;
		default:
			count = -1;
	}
	return (count);
}
