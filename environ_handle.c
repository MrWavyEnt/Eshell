#include "main.h"

/**
 * envi_val - Creates an array of Enviroment Variables
 * @enviromt: Array to store Enviroment Variables
 */

void envi_val(char **enviromt)
{
	int abc;

	for (abc = 0; environ[abc]; abc++)
		enviromt[abc] = _strdup(environ[abc]);
	enviromt[abc] = NULL;
}

/**
 * free_env - Frees the memory of the created Enviroment Variables array
 * @env:  Array of Environment variables
 */
void free_env(char **env)
{
	int abc;

	for (abc = 0; env[abc]; abc++)
	{
		free(env[abc]);
	}
}

