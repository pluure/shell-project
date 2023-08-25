#include "shell.h"
/**
 * main- the shell entry page
 * Return: nothing
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	FILE *cmd_output;
	char cmd_output_line[MAX_INPUT_SIZE];

	while (1)
	{
		printf("MyShell> ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("Exiting\n");
			break;
		}
		input[strlen(input) - 1] = '\0';

		if (strlen(input) == 0)
		{
			continue;
		}
		cmd_output = popen(input, "r");
		if (cmd_output == NULL)
		{
			perror(" ");
			continue;
		}
		while (fgets(cmd_output_line, sizeof(cmd_output_line), cmd_output) != NULL)
		{
			printf("%s", cmd_output_line);
		}
		pclose(cmd_output);
	}
	return (0);
}
