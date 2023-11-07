/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay<marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:16:01 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/07 14:16:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	char	*infile;
	char	*outfile;
	char	**command1;
	char	**command2;
	int		pid1;
	int		pid2;
	char	*path;

	if (argc != 5)
	{
		ft_printf("Wrong number of arguments. Please try again.\n");
		return (1);
	}

	infile = argv[1];
	command1 = ft_split(argv[2], ' ');
	command2 = ft_split(argv[3], ' ');
	outfile = argv[4];

	int fd[2];
	if (pipe(fd) == -1)
	{
		perror("Error in main");
		return (1);
	}

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("Error in main");
		return (1);
	}
	char	*ls[] = {"-l", NULL};
	if (pid1 == 0)
	{
		// Child 1: cmd1
		ft_printf("Child process 1\n");
		path = ft_strjoin("/bin/", command1[0]);
		// ft_putendl_fd(path, 1);
		if (execve(path, command1, envp) == -1)
			perror("Child 1");
		// bin or sbin ?
	}

	// Main process here
	waitpid(pid1, NULL, 0);
	pid2 = fork();

	if (pid2 == -1)
	{
		perror("Error in main");
		return (1);
	}

	if (pid2 == 0)
	{
		// Child 2: cmd2
		ft_printf("Child process 2\n");
		return (0);
	}

	// Main process
	waitpid(pid2, NULL, 0);
	ft_printf("Main process waited for children\n");
	return (0);
}
