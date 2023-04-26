#include "main.h"

/*
 *cmdexe - handles commands
 *Return - 1 for success
 */

void cmdexe(char **argv)
{
char *command = NULL, *actu_command = NULL;

if (argv)
{
	command = argv[0];
actu_command = location(command);

	if (execve(actu_command, argv, NULL) == -1)
	{
		perror("Error: ");
	};
}
}
