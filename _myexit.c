#include "shell.h"

/**
 * _myexit - function to exit the shell
 * @info: structure containing potential arguments
 *
 * Return: (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* if there is an exit argument */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Number not allowed: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - function to change the current directory of the process
 * @info: structure containing potential arguments
 *
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failed<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir = chdir(info->argv[1]);
	if (chdir == -1)
	{
		print_error(info, "failed to cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
}
