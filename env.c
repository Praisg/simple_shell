#include "main.h"
/**
 * env_handlin - self
 * arg_env - argument
 * Return : none
 */

void env_handlin(char **arg_env, size_t args)
{
	(void) args;
if (!arg_env[1])
	_print();
free(arg_env);
}
