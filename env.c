#include "main.h"
/**
 * env_handlin - self
 * arg_env - argument
 * Return : none
 */

void env_handlin(char **arg_env, size_t args)
{
if (!arg_env[1])
	_print();
free(arg_env, args);
}

/*
 * _print - prints the env
 * Return: none
 */

void _print(void)
{
int p;

for (p = 0; environ[p]; p++)
	printf("%s\n", environ[p]);
}
