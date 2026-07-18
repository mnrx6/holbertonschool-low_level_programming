#include "main.h"
/**
 * cap_string - capitalizes all words of a string
 * @str: string to capitalize
 *
 * Return: pointer to the string
 */
char *cap_string(char *str)
{
	int i = 0;
	int j;
	char separators[] = " \t\n,;.!?\"(){}";

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;

	while (str[i] != '\0')
	{
		j = 0;
		while (separators[j] != '\0')
		{
			if (str[i] == separators[j] &&
			    str[i + 1] >= 'a' &&
			    str[i + 1] <= 'z')
			{
				str[i + 1] -= 32;
			}
			j++;
		}
		i++;
	}

	return (str);
}
