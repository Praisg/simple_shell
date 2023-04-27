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
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>

void cmdexe(char **argv);
void exit_handlin(char **arg_ex, size_t args);
bool bultin(char **argz, size_t argzN);
void env_handlin(char **arg_env, size_t args);
void _print(void);
char *location(char *command);
ssize_t get_line(char **bufAdd, size_t *siz, FILE *stream);
char *str_tok(char *str, const char *bound);


#define command_norm	0
#define or_command	1
#define and_command	2
#define chain_command 3
#define to_lower	1
#define CONV_unsign	2
#define read_buffer 1024
#define write_buffer 1024
#define flush_buffer -1
#define _getline0
#define _strtok 0

#define file_histry	".pj_HIST"
#define max_histry	4096

extern char **environ;


typedef struct linklst
{
	int num;
	char *str;
	struct linklst *next;
} link_lst


typedef struct info
{
char file_nam
	char *argz;
	int counter_flag
	char **argzv;
	char *path;
	int argc;
	unsigned int count;
	int number_error;
	
	link_lst *env;
	link_lst *history;
	link_lst *alias;
	char **environ;
	int env_shift;
	int status;

	char **buff_cmd; 
	int cmd_type; 
	int read_fd;
	int hist_count;
} inform_t;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}


typedef struct bultin
{
	char *typ;
	int (*func)(inform_t *);
} builtin

int cmd_is(inform_t *, char *);
char *dup_charz(char *, int, int);
char *find_rout(inform_t *, char *, char *);
int hsh(inform_t *, char **);
int find_bultin(inform_t *);
void cmd_find(inform_t *);
void cmd_fork(inform_t *);
void _eputts(char *);
int _eputtchar(char);
int _puttfd(char c, int fd);
int _putzfd(char *str, int fd);
int hshloop(char **);
int _strrlen(char *);
int _strrcmp(char *, char *);
char *begin_wth(const char *, const char *);
char *_strrcat(char *, char *);

char *_strrcpy(char *, char *);
char *_strrdup(const char *);
void _putts(char *);
int _puttchar(char);
char *_setmem(char *, char, unsigned int);
void freee(char **);
void *_readlloc(void *, unsigned int, unsigned int);
char *_strrncpy(char *, char *, int);
char *_strrncat(char *, char *, int);
char *_strrchr(char *, char);
char **strrtow(char *, char *);
char **strrtow2(char *, char);


int freeb(void **);
int interactive(inform_t *);
int is_delim(char, char *);
int _isalpha(int);
int _otoi(char *);

int _errotoi(char *);
void print_eror(inform_t *, char *);
int print_x(int, int);
char *conv_num(long int, int, int);
void clear_comments(char *);

int _exit(inform_t *);
int _cd(inform_t *);
int _help(inform_t *);
int _histry(inform_t *);
int _alias(inform_t *);
ssize_t _input(inform_t *);
int _getline(inform_t *, char **, size_t *);
void handlesign(int)
void remove_info(inform_t *);
void set_inf(inform_t *, char **);
void free_inf(inform_t *, int);


char *_getenv(inform_t *, const char *);
int _envme(inform_t *);
int _setenvme(inform_t *);
int _unsetenvme(inform_t *);
int fill_env_list(inform_t *);

char **get_environ(inform_t *);
int _unsetenv(inform_t *, char *);
int _setenv(inform_t *, char *, char *);

char *get_history_file(inform_t *info);
int write_history(inform_t *info);
int read_history(inform_t *info);
int build_history_list(inform_t *info, char *buf, int linecount);
int renumber_history(inform_t *info);
list_t *add_node(link_lst **, const char *, int);
list_t *add_node_end(link_lst **, const char *, int);
size_t print_list_str(const link_lst *);
int delete_node_at_index(link_lst **, unsigned int);
void free_list(link_lst **);

size_t list_len(const link_lst *);
char **list_to_strings(link_lst *);
size_t print_list(const link_lst *);
link_lst *node_starts_with(link_lst *, char *, char);
ssize_t get_node_index(link_lst *, link_lst *);

int is_chain(inform_t *, char *, size_t *);
void check_chain(inform_t *, char *, size_t *, size_t, size_t);
int replace_alias(inform_t *);
int replace_vars(inform_t *);
int replace_string(char **, char *);

#endif

#endif
