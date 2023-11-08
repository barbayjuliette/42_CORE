/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:38:16 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/08 12:38:22 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_1(char *file, int fd[2], char *cmd, char *envp[])
{
	int		infile;
	char	**command1;
	char	*path;

	infile = open(file, O_RDONLY);
	if (infile == -1)
	{
		perror("Child 1, trying to open file1");
		exit(1);
	}
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	command1 = ft_split(cmd, ' ');
	path = ft_strjoin("/usr/bin/", command1[0]);
	if (execve(path, command1, envp) == -1)
		perror("Child 1");
	return ;
}
