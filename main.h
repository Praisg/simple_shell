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
#include <stdbool.h>
#include <stddef.h>

void cmdexe(char **argv);
void exit_handlin(char **arg_ex, size_t args);
bool bultin(char **argz, size_t argzN);
void env_handlin(char **arg_env, size_t args);
void _print(void);
char *location(char *command);
int boiler_pt(int ac, char **argv);
ssize_t get_line(char **bufAdd, size_t *siz, FILE *stream);
char *str_tok(char *str, const char *bound);
#endif
