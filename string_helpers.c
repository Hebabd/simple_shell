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
 * _strcpy - copies the string pointed to by src, including the
 * terminating null byte (\0), to the buffer pointed to by dest.
 * @dest: The given destination.
 * @src: The given source.
 *
 * Return: The pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0, length = _strlen(src);

	while (i <= length)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
