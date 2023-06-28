#include "main.h"

/**
 * _strlen - returns the length of a string
 *
 * @str: the string
 *
 * Return: the length of the string
 */
int _strlen(const char *str)
{


	int l = 0;

	while (str[l] != '\0')
	{


		l++;
	}


	return (l);
}
