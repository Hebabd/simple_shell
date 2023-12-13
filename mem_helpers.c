#include "main.h"

/**
 * _memcpy - copies memory area.
 * @dest: The first pointer.
 * @src: The second char.
 * @n: The number.
 *
 * Return: a pointer to the result.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * *_realloc - reallocates a memory block using malloc and free.
 * @ptr: The given pointer.
 * @old_size: The old size.
 * @new_size: The new size.
 *
 * Return: Void.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (old_size == new_size)
		return (ptr);

	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}

/**
 * free_arr - frees a given array.
 * @arr: The given array.
 *
 * Return: Void.
 */

void free_arr(char **arr)
{
	if (arr)
	{
		int i;

		for (i = 0; arr[i]; i++)
			free(arr[i]);
		free(arr);
	}
	else
		return;
}

/**
 * free_str - frees a given string.
 * @str: The given string.
 *
 * Return: Void.
 */

void free_str(char *str)
{
	if (str)
		free(str);
}
