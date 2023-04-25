#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void cmdexe(char **argv);
char *location(char *command);
int boiler_pt(int ac, char **argv);
ssize_t get_line(char **bufAdd, size_t *siz, FILE *stream);
char *str_tok(char *str, const char *bound);
#endif
