#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * containing a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int len;
	unsigned int i;

	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}

	return (copy);
}
