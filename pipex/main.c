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

int	main(int argc, char *argv[], char *envp[])
{
	int		pid1;
	int		pid2;
	int		fd[2];

	if (argc != 5)
	{
		ft_printf("Wrong number of arguments. Please try again.\n");
		return (1);
	}

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
		child_process_1(argv[1], fd, argv[2], envp);
	}

	pid2 = fork();

	if (pid2 == -1)
	{
		perror("Error in main");
		return (1);
	}

	if (pid2 == 0)
	{
		child_process_2(argv[4], fd, argv[3], envp);
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
