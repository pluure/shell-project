#include "shell.h"
/**
 * shell_pmt - interface for shell prompt
 * @av: argument vector
 * @env: environment viriable
 */
void shell_pmt(char **av, char **env)
{
	char *strg = NULL;
	int i, wstatus, index;
	ssize_t no_char;
	size_t a = 0;
	char *argv[MAX_COMMAND];
	pid_t mini_process;

	while (1)
	{
		printf("ALX_simple_shell$: ");

		no_char = getline(&strg, &a, stdin);
		if (no_char == -1)
		{
			free(strg);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (strg[i])
		{
			if (strg[i] == '\n')
				strg[i] = 0;
			i++;
		}
		index = 0;
		argv[index] = strtok(strg, " ");
		while (argv[index])
		{
			index++;
			argv[index] = strtok(NULL, " ");
				}
		mini_process = fork();
		if (mini_process == -1)
		{
			free(strg);
			exit(EXIT_FAILURE);
		}
		if (mini_process == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or Directory\n", av[0]);
		}
		else
			wait(&wstatus);
	}
}
