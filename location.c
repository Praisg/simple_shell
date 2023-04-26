#include "main.h"

/**
 * location - gives path
 * command - commnads in func
 * Return: none for success
 */

char *location(char *command)
{
char *locat, *locat_cpy, *locat_index, *file_locat;
int command_len, directry_len;
struct stat buffer;
locat = getenv("PATH");

if (locat)
{
	locat_cpy = strdup(locat);
	command_len = strlen(command);
	locat_index = strtok(locat_cpy, ":");

	while (locat_index != NULL)
	{
		directry_len = strlen(locat_index);
		file_locat = malloc(command_len + directry_len + 2);
		strcpy(file_locat, locat_index);
		strcat(file_locat, "/");
		strcat(file_locat, command);
		strcat(file_locat, "\0");

		if (stat(file_locat, &buffer) == 0)
		{
			free(locat_cpy);
			return (file_locat);
		}
		else
		{
			free(file_locat);
			locat_index = strtok(NULL, ":");
		}
	}
	free(locat_cpy);
	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	return (NULL);
}
return (NULL);
}
