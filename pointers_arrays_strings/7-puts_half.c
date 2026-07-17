#include "main.h"
/**
 * puts_half - prints the second half of a string
 * @str: string to print
 */
void puts_half(char *str)
{
	int i;
	int start;

	i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	if (i % 2 == 0)
	{
		start = i / 2;
	}
	else
	{
		start = (i + 1) / 2;
	}

	while (str[start] != '\0')
	{
		_putchar(str[start]);
		start++;
	}

	_putchar('\n');
}
