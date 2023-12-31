#include "main.h"

/**
 * _printf - prints different datatypes on the screen according to input.
 * @format: string determining printed string and data types
 *
 * Return: count of args printed in string and -1 on failure.
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j, len = 0;
	form_spec fs[] = {
		{'c', print_char}, {'s', print_str}, {'i', print_int}, {'d', print_int}
		, {'r', print_rev}, {'R', print_rot13}, {'S', print_S}, {'\0', NULL}
	};

	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')/*normal char case*/
		{
			_putchar(format[i]);
			len++;
		}
		else
		{
			i++;/*skip % to get to core*/
			if (format[i] == '%')
			{
				_putchar('%');
				len++;
				i++;
				continue;
			}
			for (j = 0; fs[j].ch != '\0'; j++)/*calling suitable function*/
			{
				if (fs[j].ch == format[i])
					len += fs[j].f(ap);
			}
		}
		i++;
	}
	va_end(ap);
	return (len);
}
