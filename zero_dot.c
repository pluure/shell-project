#include "shell.h"
/**
 * main- the shell entry page
 * Return: nothing
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	pid_t child_process;

	while (1)
	{
		printf("Luure&: ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strlen(input) - 1] = '\0';

		if (strlen(input) == 0)
		{
			continue;
		}
		child_process = fork();

		if (child_process == -1)
		{
			perror("forking");
			exit(0);
		}
		else if (child_process == 0)
		{
			if (execlp(input, input, (char *)NULL) == -1)
			{
				perror("Exec. not found: ");
				exit(0);
			}
		}
		else
		{
			int status;

			waitpid(child_process, &status, 0);
		}
	}
	return (0);

}
