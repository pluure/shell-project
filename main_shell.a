#include "shell.h"
/**
 * main - this is the main shell access 
 * @ac: argument counts
 * @av: argument vector for recieving commands
 * @env: environtment variable
 * Return: zero error
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		int sum = add(50, 67, 12);

		printf("Results of addition is: %d\n", sum);
		shell_pmt(av, env);
	}
	return (0);
}
