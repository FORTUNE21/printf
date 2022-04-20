#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function that produces output according to a format
 * @format: pointer to array of constant characters
 * ...: elpsis of a variadic function
 *
 * Return: (int);
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char *buffer, *str;

	if (!format)
		return (-1);
	buffer = malloc(sizeof(char) * 1024);

	if (!buffer)
		return (-1);
	va_start(args, format);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c': {
					buffer[j] = (char)va_arg(args, int);
					j++;
					break;
				}
				case 's': {
					str = va_arg(args, char *);
					strcpy(&buffer[j], str);
					j += strlen(str);
					break;
				}
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
		i++;
	}
		fwrite(buffer, j, 1, stdout);
			va_end(args);
			return (j);
}
