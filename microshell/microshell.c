/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:33:11 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/11 23:27:00 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_cd(char **argv, int i)
{
	if (i != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return ;
	}
	if (chdir(argv[1]) == -1)
	{
		printf("ERROR\n");
		write(2,  "error: cd: cannot change directory to ", 38);
		write(2, argv[1], ft_strlen(argv[1] + 1));
		write(2, "\n", 1);
	}
}

void	execute(char **argv, char **envp, int i)
{
	int	has_pipe;
	int	fd[2];
	int	pid;
	int	status;

	// Create pipe
	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (has_pipe && pipe(fd) == -1)
		 write(2, "error: fatal\n", 13);

	// Fork to create child if there is a child
	pid = fork();
	if (pid == 0) // Child
	{
		argv[i] = 0; // set i to 0, so execve stops the execution there
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			write(2, "error: fatal\n", 13);
		execve(*argv, argv, envp);
		write(2, "error: cannot execute\n", 22);
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		write(2, "error: fatal\n", 13);
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
	// int	status;
	int	i;
	// int	n = 0;

	i = 0;
	if (argc == 1)
		return (0);

	while (argv[i] && argv[i + 1])
	{
		i++;
		argv += i;
		i = 0;
		i = get_n_args(argv);

		if (strcmp(*argv, "cd") == 0)
			ft_cd(argv, i);
		else if (i)
			execute(argv, envp, i);
	}
	return (0);
}
