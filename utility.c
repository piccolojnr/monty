#include "monty.h"
/**
 * is_number - Check if a string is a number.
 * @str: The string to check.
 * Return: 1 if it's a number, 0 otherwise.
 */
int is_number(char *str)
{
	char *tmp = str;

	if (!tmp)
		return (0);

	if (*tmp == '-' || *tmp == '+')
		tmp++;

	if (!*tmp)
		return (0);

	while (*tmp)
	{
		if (*tmp < '0' || *tmp > '9')
			return (0);
		tmp++;
	}
	return (1);
}
