#include "main.h"

/**
 * exit_handlin - self explanatory
 * arg_ex: argument for exit
 *args: argumemnts passed
 *Return: none
 */

void exit_handlin(char **arg_ex)
{
int stats = EXIT_SUCCESS;
size_t args = 0;

if (arg_ex[1])
stats = atoi(arg_ex[1]);
free(arg_ex);
free(void *args);
exit(stats);
}
