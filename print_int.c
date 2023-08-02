#include "main.h"

/**
 * print_int - prints integers
 * @ap: pointer to the data entered by user
 *
 * Return: lenght of the number printed
 */

int print_int(va_list ap)
{
	int num, len = 0;

	num = va_arg(ap, int);
	_putchar(num);
	return (len);
}
