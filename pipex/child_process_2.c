/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:38:29 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/08 12:38:32 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_2(char *file, int fd[2], char *cmd, char *envp[])
{
	int		outfile;
	char	**command2;
	char	*path;

	outfile = open(file, O_WRONLY | O_CREAT, 00777);
	if (outfile == -1)
	{
		perror("Child 2, trying to open file2");
		exit(1);
	}
	dup2(outfile, 1);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	command2 = ft_split(cmd, ' ');
	path = ft_strjoin("/usr/bin/", command2[0]);
	if (execve(path, command2, envp) == -1)
		exit(5);
	return ;
}
