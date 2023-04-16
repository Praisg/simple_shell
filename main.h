#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int boiler_pt (int ac, char **argv);
ssize_t getline(char **bufAdd, size_t *siz, FILE *stream);
char *strtok(char *str, const char *bound);

#endif
