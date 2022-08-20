#include "main.h"

<<<<<<< HEAD
/**
 * int execute(char **args);
 * main - super simple unix shell. Version 1.0.
 *
 * Return: 0 on success.
 */
=======
int execute(char **args);
/**
 * main - super simple unix shell. Version 1.0.
 * Return: 0 on success.
 */

>>>>>>> 9d906f9a279d9bd4109c53c999be0aaa6439d00e
int main(void)
{
	char *buffer = NULL, *prompt = "$ ", *newline = "\n";
	size_t len = 0, ret;
	ssize_t nread;
	char *args[] = {NULL, NULL};

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, prompt, 2);

<<<<<<< HEAD

=======
>>>>>>> 9d906f9a279d9bd4109c53c999be0aaa6439d00e
		nread = getline(&buffer, &len, stdin);
		buffer[nread - 1] = '\0';
		args[0] = buffer;

		if (nread == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(1, newline, 2);
			free(buffer);
			return (0);
		}

		ret = execute(args);
		if (ret == 1)
			return (1);
<<<<<<< HEAD
	}

	free(buffer);

	return (0);
=======

	}


	free(buffer);
	return (0);

>>>>>>> 9d906f9a279d9bd4109c53c999be0aaa6439d00e
}

/**
 * execute - execute commands
 * @args: array of commands
<<<<<<< HEAD
 *
 * Return: 0 on success
 */
=======
 * Return: 0 on success
 */

>>>>>>> 9d906f9a279d9bd4109c53c999be0aaa6439d00e
int execute(char **args)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");
			return (1);
		}
	}

	wait(NULL);

	return (0);
}
