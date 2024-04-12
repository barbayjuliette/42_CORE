/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:33:11 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/12 16:43:00 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int	ft_cd(char **argv, int i)
{
	if (i != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return (0);
	}
	if (chdir(argv[1]) == -1)
		return (ft_error("error: cd cannot change directory to "), ft_error(argv[1]), ft_error("\n"));
	return (0);
}

int	execute(char **argv, char **envp, int i)
{
	int	has_pipe;
	int	fd[2];
	int	pid;
	int	status;

	// Create pipe
	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (has_pipe && pipe(fd) == -1)
		 write(2, "error: fatal\n", 13);

	// Fork to create child
	pid = fork();
	if (pid == 0) // Child
	{
		argv[i] = 0; // set i to 0, so execve stops the execution there
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			write(2, "error: fatal\n", 13);
		execve(*argv, argv, envp);
		return (ft_error("cannot execute"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (ft_error("error: fatal\n"));
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int	get_n_args(char **argv)
{
	int	i = 0;

	while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
		i++;
	return (i);
}

int main(int argc, char *argv[], char *envp[])
{
	int	status = 0;
	int	i = 0;

	if (argc == 1)
		return (1);

	while (argv[i] && argv[i + 1])
	{
		i++;
		argv += i;
		i = 0;
		i = get_n_args(argv);

		if (strcmp(*argv, "cd") == 0)
			status = ft_cd(argv, i);
		else if (i)
			status = execute(argv, envp, i);
	}
	return (status);
}
