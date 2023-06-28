#include "main.h"

/**
 * _putstr - writes a string to the standard output
 *
 * @str: the string to be written
 *
 * Return: the number of characters written
 */

int _writestr(const char *str)
{

	int l = _strlen(str);

	int j;

	for (j = 0; j < l; j++)
	{

		_putchar(str[j]);

	}

	return (l);
}
