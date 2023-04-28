#ifndef MAINSHELL_H
#define MAINSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


extern char **environ;



typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} inform_shell;


typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sept_lst;


typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} link_list;


typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} rx_var;


typedef struct builtin_s
{
	char *name;
	int (*f)(inform_shell *datash);
} builtin_t;


sept_lst *add_sep_node_end(sept_lst **head, char sep);
void free_sep_list(sept_lst **head);
link_list *add_line_node_end(link_list **head, char *line);
void free_line_list(link_list **head);


rx_var *add_rvar_node(rx_var **head, int lvar, char *var, int lval);
void free_rvar_list(rx_var **head);


char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);


void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);


char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);


void rev_string(char *s);


int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(inform_shell *datash, char *input, int i, int bool);
int check_syntax_error(inform_shell *datash, char *input);


char *without_comment(char *in);
void shell_loop(inform_shell *datash);


char *read_line(int *i_eof);

char *swap_char(char *input, int bool);
void add_nodes(sept_lst **head_s, link_list **head_l, char *input);
void go_next(sept_lst **list_s, link_list **list_l, inform_shell *datash);
int split_commands(inform_shell *datash, char *input);
char **split_line(char *input);


void check_env(rx_var **h, char *in, inform_shell *data);
int check_vars(rx_var **h, char *in, char *st, inform_shell *data);
char *replaced_input(rx_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, inform_shell *datash);


void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);


int exec_line(inform_shell *datash);


int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(inform_shell *datash);
int check_error_cmd(char *dir, inform_shell *datash);
int cmd_exec(inform_shell *datash);


char *_getenv(const char *name, char **_environ);
int _env(inform_shell *datash);


char *copy_info(char *name, char *value);
void set_env(char *name, char *value, inform_shell *datash);
int _setenv(inform_shell *datash);
int _unsetenv(inform_shell *datash);


void cd_dot(inform_shell *datash);
void cd_to(inform_shell *datash);
void cd_previous(inform_shell *datash);
void cd_to_home(inform_shell *datash);


int cd_shell(inform_shell *datash);


int (*get_builtin(char *cmd))(inform_shell *datash);


int exit_shell(inform_shell *datash);

int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);


char *strcat_cd(inform_shell *, char *, char *, char *);
char *error_get_cd(inform_shell *datash);
char *error_not_found(inform_shell *datash);
char *error_exit_shell(inform_shell *datash);


char *error_get_alias(char **args);
char *error_env(inform_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(inform_shell *datash);



int get_error(inform_shell *datash, int eval);


void get_sigint(int sig);


void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);


void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);


int get_help(inform_shell *datash);

#endif

