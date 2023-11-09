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

void	child_process_1(char *file, int fd[2], char *cmd, char **envp)
{
	int		infile;
	char	**command1;
	char	*path;

	infile = open(file, O_RDONLY);
	if (infile == -1)
		handle_errors(errno, "pipex");
	if (dup2(infile, 0) == -1)
		handle_errors(errno, "pipex");
	if (dup2(fd[1], 1) == -1)
		handle_errors(errno, "pipex");
	close(fd[0]);
	close(fd[1]);
	command1 = ft_split(cmd, ' ');
	path = get_path(envp, command1[0]);
	if (path)
		execve(path, command1, envp);
	free(command1);
	if (!path)
		no_path(path, command1[0]);
	free(path);
	handle_errors(errno, "pipex");
	return ;
}
