#include "main.h"

/**
 * print_S - prints 0-->32 or >=127 of the ascii
 * otherwise, it prints '\x'
 * @ap: pointer to the string to be printed
 *
 * Return: the length of the string
 */

int print_S(va_list ap)
{
	int len = 0, i;
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (0);
	len = _strlen(str);
	for (i = 0; i < len; i++)
	{
		if ((str[i] >= 0 && str[i] <= 32) || str[i] >= 127)
			_putchar(str[i]);
		else
		{
			_putchar('\\');
			_putchar('x');

		}	
	}


	return (len);
}
