#include "main.h"

/**
 * get_args - return the split arguments passed.
 * @chars_num: The number of passed chars.
 * @input_ptr: The str pointer.
 *
 * Return: The split arguments.
 */

char **get_args(ssize_t chars_num, char *input_ptr)
{
	int i, str_num = 0;
	char *str, *cloned_ptr = NULL;
	const char *delimiter = " =\n";
	char **argv;

	cloned_ptr = malloc(sizeof(char) * chars_num);
	if (cloned_ptr == NULL)
	{
		perror("hsh: memory allocation error");
		return (NULL);
	}
	_strcpy(cloned_ptr, input_ptr);
	str = _strtok(input_ptr, delimiter);
	while (str)
	{
		str_num++;
		str = _strtok(NULL, delimiter);
	}
	str_num++;
	argv = malloc(sizeof(char *) * str_num);
	str = _strtok(cloned_ptr, delimiter);
	for (i = 0; str; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(str) + 1));
		if (argv[i] == NULL)
		{
			perror("hsh: memory allocation error");
			free_arr(argv);
			free(cloned_ptr);
			return (NULL);
		}
		_strcpy(argv[i], str);
		str = _strtok(NULL, delimiter);
	}
	argv[i] = NULL;
	free(cloned_ptr);

	return (argv);
}
