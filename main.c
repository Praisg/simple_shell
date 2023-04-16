#include "main.h"

/**
 * main - boiler pointer code 
 * bufAdd - ADDRESS OF BUFFER HOLDING WHATEVER WE TYPE
 * Return: 0 always for success -1 for failure
 */
 
int main(int ac, char **argv)
{
(void) ac;
(void) argv;
char *instant = "(PJshell)$:";
char *bufAdd = NULL;// *bufAdd_cpy = NULL;
size_t siz = 0;
//const char *bound = " \n";
//ssize_t sizchar;

while (1){
printf("%s", instant);
//sizchar = 
getline(&bufAdd, &siz, stdin);//check for getline failure
/*
if (sizchar == -1){
	return (-1);
}
 exit shell
 */
printf("%s\n", bufAdd);

free(bufAdd);//free up allocated memory
}
return (0);
}
