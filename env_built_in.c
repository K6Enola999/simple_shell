#include "main.h"

/**
 * changeDirectory - changes directories within the program (Shell) session
 * @_argv: a pointer to the program (Shell) name
 * @argv: a pointer to array of string
 * Return: 0 (Success), or 2 (Misuse of Shell Builtins)
 */
int changeDirectory(char *_argv, char *argv[])
{
	char *home_dir = NULL, *prev_dir = NULL;
	char *buf = getcwd(NULL, 0);

	if (argv[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			free(buf);
			return (2);
		}
		else
			chdir(home_dir);
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		prev_dir = getenv("OLDPWD");
		if (prev_dir == NULL)
			printf("%s\n", buf);
		else
		{
			chdir(prev_dir);
			printf("%s\n", prev_dir);
		}
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			fprintf(stderr, "%s: 1: cd: can't cd to %s\n", _argv, argv[1]);
			free(buf);
			return (2);
		}
	}
	if (buf != NULL)
		setenv("OLDPWD", buf, 1);
	free(buf);
	return (0);
}

/**
 * print_env - prints the current enviroment
 * Return: 0 and exit
 */
int print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * set_env - sets or unsets a new enviroment variable
 * @_argv: a pointer to the prpgram (Shell) name
 * @argv: a pointer to array of strings
 * Return: 0 (Success) or 2 (failure)
 */
int set_env(char *_argv, char *argv[])
{
	if (setenv(argv[1], argv[2], 1) != 0)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", _argv, argv[0]);
		return (2);
	}
	return (0);
}

/**
 * unset_env - unsets an existing enviroment variable
 * @_argv: a pointer to the program (Shell) name
 * @argv: a pointer to array of strings
 * Return: 0 (Success) or 2 (failure)
 */
int unset_env(char *_argv, char *argv[])
{
	if (unsetenv(argv[1]) != 0)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", _argv, argv[0]);
		return (2);
	}
	return (0);
}
