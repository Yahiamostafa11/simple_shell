#include "shell.h"

extern char **environ;

void shell_loop(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		printf("shell> ");
		fgets(input, MAX_INPUT_SIZE, stdin);

		/* Remove trailing newline */
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			/* Exit the shell if the user enters "exit" */
			exit(EXIT_SUCCESS);
		}

		handle_input(input);
	}
}

void execute_command(char *tokens[])
{
	if (tokens[0] == NULL)
	{
		/* Empty command */
		return;
	}

	if (strcmp(tokens[0], "exit") == 0)
	{
		/* Exit the shell */
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(tokens[0], "cd") == 0)
	{
		/* Change directory */
		if (tokens[1] != NULL)
		{
			if (chdir(tokens[1]) != 0)
			{
				perror("chdir");
			}
		}
		else
		{
			fprintf(stderr, "cd: Missing argument\n");
		}
	}
	else if (strcmp(tokens[0], "env") == 0)
	{
		/* Print environment variables */
		char **env = environ;
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else
	{
		/* For other commands, fork and execute */
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
		}
		else if (pid == 0)
		{ /* Child process */
			if (execvp(tokens[0], tokens) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{ /* Parent process */
			int status;
			waitpid(pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("Child process exited with status %d\n", WEXITSTATUS(status));
			}
			else
			{
				printf("Child process did not exit normally\n");
			}
		}
	}
}

void handle_input(char *input)
{
	/* Tokenize input */
	char *tokens[MAX_TOKENS];
	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL && i < MAX_TOKENS - 1)
	{
		tokens[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	tokens[i] = NULL; /* Null-terminate the tokens array */

	/* Execute the command */
	execute_command(tokens);
}
