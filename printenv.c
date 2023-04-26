#include "main.h"
/*
 * _print - prints the env
 * Return: none
 */

void _print(void)
{
int p;

for (p = 0; __environ[p]; p++)
        printf("%s\n", __environ[p]);
}
