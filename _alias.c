#include "main.h"

/**
 * initiate_aliases - creates an array of aliases.
 *
 * Return: Void.
 */

char **initiate_aliases()
{

	char **aliases = NULL;

	aliases = malloc(sizeof(char *) * 2/** (1 + MAX_NO)*/);

	if (!aliases)
		return (NULL);

	aliases[0] = _strdup("alias_name='value'");
	aliases[1] = NULL;

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
	int index;
	char **current_aliases = *aliases;

	if (arr[0] && !arr[1])
		print_env(current_aliases);
	else if (arr[1])
	{
		index = get_index(current_aliases, arr[1]);

		if (index != -1)
		{
			if (arr[2])
				update_env(aliases, current_aliases, arr[1], arr[2]);
			else
			{
				_puts("alias ");
				_puts(current_aliases[index]);
				_putchar('\n');
			}
		}
		else if (index == -1)
			add_env(aliases, current_aliases, arr[1], arr[2]);
		else
		{
			perror("hsh");
		}
	}
}
