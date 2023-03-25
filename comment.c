#include "monty.h"

/**
 * cmnt - check for comment validity
 * @arr: array containing characters
 * Return: 0 if no comment or 1 if a valid comment
 */

int cmnt(char arr[])
{
	int len, i;

	len = strlen(arr);
	for (i = 0; i < len; i++)
	{
		if (arr[i] == '#')
			return (1);
		else if (arr[i] != ' ')
			return (0);
	}
	return (0);
}
