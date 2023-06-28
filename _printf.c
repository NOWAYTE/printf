#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 *
 * @format: is a character string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	int chars = 0;

	va_start(args, format);


	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);

			chars++;
		}
		else
		{
			format++;
			switch (*format) {
			case 'c': {
				char x = (char) va_arg(args, int);

				_putchar(x);

				chars++;
				break;
			}
			case 's': {
				char *s = va_arg(args, char *);

				chars += _writestr(s);

				break;
			}
			case 'd':
			case 'i': {
				int y = va_arg(args, int);
				chars += _writeint(y);

				break;
			}
			case 'x': {

				unsigned int w = va_arg(args, unsigned int);

				char hex_d[] = "0123456789abcdef";
				char hex[9] = {'\0'};
				int i = 0;
				while (w) {
					hex[i++] = hex_d[w % 16];

					w /= 16;
				}
				_writestr("0x");


				_writestr(hex);
				chars += 10;

				break;
			}
			case 'p': {

				void *p = va_arg(args, void *);
				unsigned long int add = (unsigned long int) p;
				char hex_d[] = "0123456789abcdef";
				char hex[17] = {'\0'};
				int i = 0;
				while (add) {

					hex[i++] = hex_d[add % 16];

					add /= 16;
				}
				_writestr("0x");

				_writestr(hex);

				chars += 18;
				break;
			}
			default:
				_putchar('%');
				_putchar(*format);

				chars += 2;

				break;
			}
		}

		format++;
	}

	va_end(args);
	return (chars);
}

