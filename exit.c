#include "main.h"

/**
 * exitShell - exits the shell
 * @_arg: a pointer to the program (Shell) name
 * @argv: a pointer to array of strings
 * @lineptr: a pointer to the input on the CLI
 * @re: return value
 * Return: 2 in case of failure.
 */
int exitShell(char *_arg, char *argv[], char *lineptr, int re)
{
	char *endptr;
	long int exitStatus;
	int i;

	if (argv[1] != NULL)
	{
		exitStatus = strtol(argv[1], &endptr, 10);
		if (*endptr == '\0' || *endptr == '\n')
		{
			if (exitStatus >= 0)
			{
				for (i = 0; argv[i] != NULL; i++)
					free(argv[i]);
				free(argv);
				free(lineptr);
				exit((int)exitStatus);
			}
			else
			{
				fprintf(stderr, "%s: 1: %s: Illegal number: %s\n", _arg, argv[0], argv[1]);
			}
		}
		else
		{
			fprintf(stderr, "%s: 1: %s: Illegal number: %s\n", _arg, argv[0], argv[1]);
		}
	}
	else
	{
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);
		free(lineptr);
		exit(re);
	}
	return (2);
}
