#include "main.h"

/**
 * main - boiler pointer code 
 * bufAdd - ADDRESS OF BUFFER HOLDING WHATEVER WE TYPE
 * Return: 0 always for success -1 for failure
 */

int main(int ac, char **argv, char **env)
{
char *instant = "PJshell:";
char *bufAdd = NULL, *bufAdd_cpy = NULL;
size_t siz = 0;
const char *bound = " \n";
ssize_t sizchar;
char *index;
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

if (sizchar == -1){
	printf("Exit Shell\n");
	return (-1);
}
bufAdd_cpy = malloc(sizeof(char) * sizchar);
if (bufAdd_cpy == NULL){
perror(" ERROR in memory allo");
return (-1);
} 
strcpy(bufAdd_cpy, bufAdd);

index = strtok(bufAdd, bound);

while (index != NULL){
	num_index++;
	index = strtok(NULL, bound);
}
num_index++;

argv = malloc(sizeof(char *)* num_index);
index = strtok(bufAdd_cpy, bound);

for (y = 0; index != NULL; y++){
	argv[y] = malloc(sizeof(char) * strlen(index));
	strcpy(argv[y],index);

	index = strtok(NULL, bound);
}
argv[y] = NULL;
cmdexe(argv);
}
free(bufAdd_cpy);
free(bufAdd);
return (0);
}
