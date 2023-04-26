#include "main.h"

/**
 * main - boiler pointer code
 * bufAdd - ADDRESS OF BUFFER HOLDING WHATEVER WE TYPE
 * ac - void parameter
 * argv - argument
 * env = environment
 * Return: 0 always for success -1 for failure
 */

int main(int ac, char **argv, char **env)
{
char *instant = "PJshell:";
char *bufAdd = NULL, *bufAdd_cpy = NULL;
size_t siz = 0;
pid_t  fpid;
int fstat;
const char *bound = " \n";
ssize_t sizchar;
char *index;
/*
 *size_t argzN = 0;
 * char **argz;
 */
int num_index = 0;
int y;
bool pipee = false;
(void) ac;
(void) env;
while (1 && !pipee)
{
	if (isatty(STDIN_FILENO) == 0)
		pipee = true;
printf("%s", instant);
sizchar = getline(&bufAdd, &siz, stdin);

if (sizchar == -1)
{
	printf("Exit Shell\n");
	return (-1);
}
bufAdd_cpy = malloc(sizeof(char) * sizchar);
if (bufAdd_cpy == NULL)
{
perror(" ERROR in memory allo");
return (-1);
}
strcpy(bufAdd_cpy, bufAdd);

index = strtok(bufAdd, bound);

while (index != NULL)
{
	num_index++;
	index = strtok(NULL, bound);
}
num_index++;

argv = malloc(sizeof(char *) * num_index);
index = strtok(bufAdd_cpy, bound);

for (y = 0; index != NULL; y++)
{
	argv[y] = malloc(sizeof(char) * strlen(index));
	strcpy(argv[y], index);

	index = strtok(NULL, bound);
}
argv[y] = NULL;
cmdexe(argv);

/*if (bultin(argz, argzN))
*	continue;
*/	
fpid = fork();
if (fpid == -1)
{
perror("Error (fork)");
exit(EXIT_FAILURE);
}
if (waitpid(fpid, &fstat, 0) == -1)
{
perror("Error (wait)");
exit(EXIT_FAILURE);
}
}
free(bufAdd_cpy);
free(bufAdd);
return (0);
}
