#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...) {
  int i, written;
  char buffer[BUFFER_SIZE];
  va_list args;

  va_start(args, format);

  for (i = 0; format[i]; i++) {
    if (format[i] == '%') {
      i++;

      switch (format[i]) {
        case 'c': {
          char c = va_arg(args, int);
          written = snprintf(buffer, BUFFER_SIZE, "%c", c);
          break;
        }
        case 's': {
          char *s = va_arg(args, char *);
          written = snprintf(buffer, BUFFER_SIZE, "%s", s);
          break;
        }
        case '%': {
          written = snprintf(buffer, BUFFER_SIZE, "%%");
          break;
        }
        case 'b': {
          unsigned int n = va_arg(args, unsigned int);
          written = snprintf(buffer, BUFFER_SIZE, "%u", n);
          break;
        }
        case 'd':
        case 'i': {
          int n = va_arg(args, int);
          written = snprintf(buffer, BUFFER_SIZE, "%d", n);
          break;
        }
        case 'u': {
          unsigned int n = va_arg(args, unsigned int);
          written = snprintf(buffer, BUFFER_SIZE, "%u", n);
          break;
        }
        case 'o': {
          unsigned int n = va_arg(args, unsigned int);
          written = snprintf(buffer, BUFFER_SIZE, "%o", n);
          break;
        }
        case 'x': {
          unsigned int n = va_arg(args, unsigned int);
          written = snprintf(buffer, BUFFER_SIZE, "%x", n);
          break;
        }
        case 'X': {
          unsigned int n = va_arg(args, unsigned int);
          written = snprintf(buffer, BUFFER_SIZE, "%X", n);
          break;
        }
        case 'S': {
          char *s = va_arg(args, char *);
          int len = strlen(s);
          for (int j = 0; j < len; j++) {
            if (s[j] < 32 || s[j] >= 127) {
              buffer[written++] = '\\';
              buffer[written++] = 'x';
              buffer[written++] = (s[j] >> 4) & 0xf;
              buffer[written++] = s[j] & 0xf;
            } else {
              buffer[written++] = s[j];
            }
          }
          break;
        }
        default: {
          written = 1;
          break;
        }
      }

      printf(buffer);
    } else {
      printf("%c", format[i]);
      written = 1;
    }
  }

  va_end(args);

  return written;
}

