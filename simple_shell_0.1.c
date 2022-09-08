#include "main.h"


/**
 * main - super simple unix shell. Version 1.0.
 * Return: 0 on success.
 */

int main(void)
{
	char *buffer, *prompt = "$ ";
	char **args = NULL;
	int status = 1;
       

	while(status)
	{
		if (isatty(STDIN_FILENO))
			write(1, prompt, 2); 
		
		buffer = read_line();
		
		if (buffer != NULL)
			args = tokenize(buffer);

		if (args != NULL)
			status = execute(args);

		free(buffer);
		if (buffer != NULL)
			free(args);


	}


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
	if (nread == -1)
	{
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
				write(1, newline, 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		else
		{
			perror("readline");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		return (NULL);
	}


	if (buffer != NULL)
		buffer[nread - 1] = '\0';

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

	if (buffer == NULL || *buffer == '\0')
	{
		free(args);
		return (NULL);
	}

	token = strtok(buffer, " ");

	while (token != NULL)
	{
		args[index] = token;
		index++;
		token = strtok(NULL, " ");
	}

	args[index] = NULL;

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
	pid_t child_pid = 1;

	if (args == NULL || *args == NULL)
		return (1);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");
			free(*args);
			free(args);
			exit (EXIT_FAILURE);
		}
	}

	wait(NULL);

	return (1);
}

