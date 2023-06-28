#include "main.h"

/**
 * _strrev - reverses a string
 *
 * @str: the string to be reversed
 */

void _strrev(char *str)
{
	int x = 0;
	int y = _strlen(str) - 1;
	char t;

	while (x < y)
	{
		t = str[x];

		str[x] = str[y];


		str[y] = t;

		x++;

		y--;
	}
}
