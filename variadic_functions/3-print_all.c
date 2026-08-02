#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_all - prints anything based on a format string
 * @format: list of argument types
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *separator = "";
	char *str;

	va_start(ap, format);

	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", separator, va_arg(ap, int));
			separator = ", ";
			break;
		case 'i':
			printf("%s%d", separator, va_arg(ap, int));
			separator = ", ";
			break;
		case 'f':
			printf("%s%f", separator, va_arg(ap, double));
			separator = ", ";
			break;
		case 's':
			str = va_arg(ap, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", separator, str);
			separator = ", ";
			break;
		default:
			break;
		}

		i++;
	}

	va_end(ap);
	printf("\n");
}
