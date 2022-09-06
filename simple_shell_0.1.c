#include "main.h"

int execute(char **args);
char *read_line(void);
char **tokenize(char *buffer);

/**
 * main - super simple unix shell. Version 1.0.
 * Return: 0 on success.
 */

int main(/*int argc , char **argv*/void)
{
	char *buffer, *prompt = "$ ";
	char **args;
	int status;


	do {
		if (isatty(STDIN_FILENO))
			write(1, prompt, 2); 
		buffer = read_line();
		args = tokenize(buffer);
		status = execute(args);

		free(buffer);
		free(args);

	} while (status);

	return (EXIT_SUCCESS);

}


/**
 * read_line - gets input from the terminal. 
 * Return: the arrray of characters read.
 */

char *read_line(void)
{
	char *buffer = NULL, *newline = "\n";
	size_t len = 0;
	ssize_t nread;

	nread = getline(&buffer, &len, stdin);
	buffer[nread - 1] = '\0';
	if (nread == -1)
	{
		if (nread == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(1, newline, 2);
			exit(EXIT_SUCCESS);
		}

		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}

	
	return (buffer);
}

/**
 * tokenize - tokenize arguments
 */
 
char **tokenize(char *buffer)
{
	int index = 0;
	char **args, *token;

	args = malloc(sizeof(char *) * strlen(buffer));
	if (args == NULL)
		return (NULL);

	token = strtok(buffer, " ");

	while (token != NULL)
	{
		args[index] = strdup(token);
		index++;
		token = strtok(NULL, " ");
	}

	return (args);
}




/**
 * execute - execute commands
 * @args: array of commands
 *
 * Return: 0 on success
 */
int execute(char **args)
{
	pid_t child_pid;


	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");
			exit (EXIT_FAILURE);
		}
	}

	wait(NULL);

	return (1);
}
