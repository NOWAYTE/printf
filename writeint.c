#include "main.h"
/**
 * _putint - writes an integer to the standard output
 *
 * @n: the integer to be written
 *
 * Return: the number of characters written
 */

int _writeint(int n)
{

	int i = 0;

	if (n < 0)
	{

		_putchar('-');
		i++;
		n = -n;
	}
	if (n / 10)
	{
		i += _writeint(n / 10);
	}

	_putchar('0' + n % 10);

	return (i);
}
