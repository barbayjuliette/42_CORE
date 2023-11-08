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
	char	*file1;
	char	*file2;
	char	**command1;
	char	**command2;
	int		pid1;
	int		pid2;
	char	*path;
	char	*path2;
	int		infile;
	int		outfile;

	if (argc != 5)
	{
		ft_printf("Wrong number of arguments. Please try again.\n");
		return (1);
	}

	file1 = argv[1];
	command1 = ft_split(argv[2], ' ');
	command2 = ft_split(argv[3], ' ');
	file2 = argv[4];

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

	if (pid1 == 0)
	{
		// CHILD 1: cmd1
		ft_printf("Child process 1\n");
		infile = open(file1, O_RDONLY | O_CREAT);
		dup2(infile, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		path = ft_strjoin("/usr/bin/", command1[0]);
		if (execve(path, command1, envp) == -1)
			perror("Child 1");
		return (0);
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
		// CHILD 2: cmd2
		ft_printf("Child process 2\n");
		outfile = open(file2, O_WRONLY | O_CREAT, 00777);
		if (outfile == -1)
			perror("Child 2, trying to open file2");
		dup2(outfile, 1);
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		path2 = ft_strjoin("/usr/bin/", command2[0]);
		if (execve(path2, command2, envp) == -1)
			perror("Child 2");
		return (0);
	}

	// Main process
	close(fd[0]);
	close(fd[1]);
	waitpid(pid2, NULL, 0);
	ft_printf("Main process waited for children\n");
	return (0);
}
