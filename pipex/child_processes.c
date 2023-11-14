/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:47:19 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/14 11:47:23 by jbarbay          ###   ########.fr       */
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
		handle_file_errors(errno, file);
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
	if (!path)
		no_path(path, command1[0]);
	free(command1);
	free(path);
	handle_errors(errno, "pipex");
	return ;
}

void	child_process_2(char *file, int fd[2], char *cmd, char **envp)
{
	int		outfile;
	char	**command2;
	char	*path;

	outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 00777);
	if (outfile == -1)
		handle_file_errors(errno, file);
	if (dup2(outfile, 1) == -1)
		handle_errors(errno, "pipex");
	if (dup2(fd[0], 0) == -1)
		handle_errors(errno, "pipex");
	close(fd[0]);
	close(fd[1]);
	command2 = ft_split(cmd, ' ');
	path = get_path(envp, command2[0]);
	if (path)
		execve(path, command2, envp);
	if (!path)
		no_path(path, command2[0]);
	free(command2);
	free(path);
	handle_errors(errno, "pipex");
	return ;
}
