#include "main.h"

/**
 * _putchar - Prints the given character.
 * @c: The given character.
 *
 * Return: Always 0 (Success)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line, to stdout.
 * @str: The given string.
 *
 * Return: Void.
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strlen - returns the length of a string.
 * @s: The given string.
 *
 * Return: The length of the string.
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strchr - locates a character in a string.
 * @s: The first pointer.
 * @c: The second char.
 *
 * Return: a pointer to the result.
 */

char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}

	if (s[i] == c)
		return (s + i);
	return (0);
}

/**
 * _strcmp - appends the src string to the dest string.
 * @s1: The first pointer.
 * @s2: The second pointer.
 *
 * Return: a pointer to the resulting string dest.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s1[i] - s2[i] == 0)
	{
		i++;
	}

	return (s1[i] - s2[i]);
}

