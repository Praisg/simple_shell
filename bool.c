#include "main.h"
/**
 * bultin - handles builtin commands
 * Return: true if buit in is detected
 */
bool bultin(char **argz, size_t argzN)
{
if (strncmp(argz[0], "exit", 4) == 0)
exit_handlin(argz, argzN);

else if ((strncmp(argz[0], "env", 3) == 0) || (strncmp(argz[0], "printenv", 8 == 0)))
{
env_handlin(argz, argzN);
return (true);
}
return (false);
}
