#include "main.h"

/**
 * free_cmds - Frees the memory allocated for an array of strings.
 * @cmds: Array of strings to be freed
 */

void free_cmds(char **cmds)
{
	size_t i;

	for (i = 0; cmds[i] != NULL; i++)
	{
		free(cmds[i]);
		cmds[i] = NULL;
	}

	free(cmds);
}
