#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated concatenated string,
 * or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *str;
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	len1 = 0;
	while (s1[len1] != '\0')
	{
		len1++;
	}

	len2 = 0;
	while (s2[len2] != '\0')
	{
		len2++;
	}

	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}

	j = 0;
	while (j < len2)
	{
		str[i] = s2[j];
		i++;
		j++;
	}

	str[i] = '\0';

	return (str);
}
