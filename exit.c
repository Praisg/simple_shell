#include "main.h"

/**
 * exit_handlin - self explanatory
 * arg_ex: argument for exit
 *args: argumemnts passed
 *Return: none
 */

void exit_handlin(char **arg_ex, size_t args)
{
int stats = EXIT_SUCCESS;
(void) args;

if (arg_ex[1])
stats = atoi(arg_ex[1]);
free(arg_ex);
exit(stats);
}
