#include "main.h"

/**
 * _strcat - appends the src string to the dest
 * @dest: The first pointer.
 * @src: The second pointer.
 *
 * Return: a pointer to the resulting
 * string dest.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	dest[i + j] = '\0';
	return (dest);
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

/**
 * *_strncpy - appends the src string to the dest string.
 * @dest: The first pointer.
 * @src: The second pointer.
 * @n: The number.
 *
 * Return: a pointer to the resulting string dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

/**
 * *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: The string.
 *
 * Return: Char.
 */

char *_strdup(char *str)
{
	int i, length;
	char *dup;

	if (str == NULL)
		return (NULL);

	length = _strlen(str);

	dup = malloc((length + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		dup[i] = str[i];
	}

	return (dup);


}

/**
 *  _isalpha - checks whether the parameter is a letter or not.
 * @c: The parameter or character to be checked.
 *
 * Return: 1 if c is a letter whether it's lowercase or uppercase, 0 otherwise.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
