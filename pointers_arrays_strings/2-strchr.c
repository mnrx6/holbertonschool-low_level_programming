#include "main.h"
/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: character to locate
 *
 * Return: pointer to the first occurrence of c, or NULL
 */
char *_strchr(char *s, char c)
{
	unsigned int i;

	for (i = 0;; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}

		if (s[i] == '\0')
		{
			break;
		}
	}

	return (NULL);
}
