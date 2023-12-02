#include "main.h"

/**
 * _getline - reads line input by user.
 * @input_ptr: The first pointer.
 * @num: The second pointer.
 * @buff_type: Buffer stream type.
 *
 * Return: The number of characters read.
 */

ssize_t _getline(char **input_ptr, size_t *num, FILE *buff_type)
{
	static ssize_t bread;
	static char buff[1024];
	static size_t bidx;
	size_t input_len;

	if (bread <= 0)
	{
		bread = read(fileno(buff_type), buff, 1024);

		if (bread == 0)
			return (-1);

		bidx = 0;
	}

	input_len = 0;

	while ((input_len + bidx < (size_t)bread) && buff[input_len + bidx] != '\n')
		input_len++;

	if (*num < input_len + 1 || *input_ptr == NULL)
	{
		*input_ptr = _realloc(*input_ptr, input_len, input_len + 1);

		if (*input_ptr == NULL)
		{
			perror("Cannot realloc");
			exit(EXIT_FAILURE);
		}
		*num = input_len + 1;
	}

	_memcpy(*input_ptr, buff + bidx, input_len);
	(*input_ptr)[input_len] = '\0';

	bidx += input_len + 1;
	bread -= input_len + 1;
	input_len++;

	return (input_len);
}
