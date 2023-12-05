#include "main.h"

/**
 * initiate_aliases - creates an array of aliases.
 *
 * Return: Void.
 */

char **initiate_aliases()
{

	char *ex = "#alias='value/command'", **aliases = NULL;

	aliases[0] = _strdup(ex);
	aliases[1] = NULL;

	free(ex);

	return (aliases);
}

/**
 * _alias - aliases a given command.
 * @aliases: The given aliases env.
 * @arr: The given array of commands.
 *
 * Return: Void.
 */

void _alias(char ***aliases, char **arr)
{
	int exists1, exists2;
	char **current_aliases = *aliases;

	if (arr[0] && !arr[1])
		print_env(current_aliases);
	else if (arr[1] && arr[2])
	{
		exists1 = get_index(current_aliases, arr[1]);
		exists2 = get_index(current_aliases, arr[2]);

		if (exists1 != -1 && exists2 != -1)
		{
			_puts(get_env(current_aliases, arr[1]));
			_putchar('\n');
			_puts(get_env(current_aliases, arr[2]));
			_putchar('\n');
		}
		else if (exists1 == -1 && exists2 == -1)
			add_env(aliases, current_aliases, arr[1], arr[2]);
		else if (exists1 != -1)
			update_env(aliases, current_aliases, arr[1], arr[2]);
		else
			perror("hsh");
	}
}
