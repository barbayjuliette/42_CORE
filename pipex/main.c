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

void	nb_args(int argc)
{
	if (argc != 5)
	{
		ft_printf("Execute as follow: ./pipex file1 cmd1 cmd2 file2.\n");
		exit(1);
	}
	return ;
}

void	wait_child(int pid)
{
	int		status;

	waitpid(pid, &status, 0);
	if ((WIFEXITED(status)))
	{
		if (WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int		pid1;
	int		pid2;
	int		fd[2];

	nb_args(argc);
	if (pipe(fd) == -1)
		handle_errors(errno, "pipe");
	pid1 = fork();
	if (pid1 == -1)
		handle_errors(errno, "fork");
	if (pid1 == 0)
		child_process_1(argv[1], fd, argv[2], envp);
	pid2 = fork();
	if (pid2 == -1)
		handle_errors(errno, "pipex");
	if (pid2 == 0)
		child_process_2(argv[4], fd, argv[3], envp);
	close(fd[0]);
	close(fd[1]);
	wait_child(pid1);
	wait_child(pid2);
	return (0);
}
