#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array and initializes it with a character
 * @size: size of the array
 * @c: character used to initialize the array
 *
 * Return: pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	array = malloc(size * sizeof(char));

	if (array == NULL)
	{
		return (NULL);
	}

	i = 0;

	while (i < size)
	{
		array[i] = c;
		i++;
	}

	return (array);
}
