#include "mainshell.h"

int (*get_builtin(char *cmd))(inform_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}
	return (builtin[i].f);
}

int get_error(inform_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(datash);
		break;
	case 126:
		error = error_path_126(datash);
		break;
	case 127:
		error = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = error_get_cd(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}

int get_help(inform_shell *datash)
{

	if (datash->args[1] == 0)
		aux_help_general();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		aux_help_setenv();
	else if (_strcmp(datash->args[1], "env") == 0)
		aux_help_env();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (_strcmp(datash->args[1], "help") == 0)
		aux_help();
	else if (_strcmp(datash->args[1], "exit") == 0)
		aux_help_exit();
	else if (_strcmp(datash->args[1], "cd") == 0)
		aux_help_cd();
	else if (_strcmp(datash->args[1], "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, datash->args[0],
		      _strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}

