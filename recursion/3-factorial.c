#include "main.h"
/**
 * factorial - returns the factorial of a number
 * @n: number
 *
 * Return: factorial of n, or -1 if n is negative
 */
c
{
	if (n < 0)
	{
		return (-1);
	}

	if (n == 0)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}
