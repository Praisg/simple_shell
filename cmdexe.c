#include "main.h"

void cmdexe(char **argv){
char *command = NULL, *actu_command = NULL;

if (argv){
	command = argv[0];
actu_command = location(command);

	if (execve(actu_command, argv, NULL) == -1){
		perror("Error: ");
	};
}
}
